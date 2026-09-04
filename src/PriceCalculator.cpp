#include <iostream>
using namespace std;

class PriceCalculator {
private:
    double basePrice;
    double taxRate;
    double discount;

public:
    PriceCalculator(double base = 200.0, double tax = 0.18, double disc = 0.0) {
        basePrice = base;
        taxRate = tax;
        discount = disc;
    }

    double calculatePrice(int seatType, bool isWeekend) {
        double price = basePrice;

        // Adjust price based on seat type
        if (seatType == 1) { // Platinum
            price *= 1.8;
        } else if (seatType == 2) { // Gold
            price *= 1.4;
        } else if (seatType == 3) { // Silver
            // Base price
        }

        // Weekend surcharge
        if (isWeekend) {
            price *= 1.2;
        }

        return price;
    }

    double applyDiscount(double price, double discountPercent) {
        return price * (1 - discountPercent / 100);
    }

    double calculateTax(double price) {
        return price * taxRate;
    }

    double getFinalPrice(double price) {
        double total = price + calculateTax(price);
        return total - (total * discount / 100);
    }

    void setBasePrice(double price) { basePrice = price; }
    void setTaxRate(double rate) { taxRate = rate; }
    void setDiscount(double disc) { discount = disc; }
};