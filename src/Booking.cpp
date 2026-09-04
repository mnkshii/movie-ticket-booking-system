#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Booking {
private:
    int bookingId;
    int customerId;
    vector<int> showSeatIds;
    double totalAmount;
    string bookingStatus; // Pending, Confirmed, Cancelled
    time_t bookingTime;

public:
    Booking(int id, int custId) {
        bookingId = id;
        customerId = custId;
        totalAmount = 0;
        bookingStatus = "Pending";
        bookingTime = time(nullptr);
    }

    double calculateTotal(double basePrice, double taxRate = 0.18) {
        double tax = basePrice * taxRate;
        totalAmount = basePrice + tax;
        return totalAmount;
    }

    void confirm() {
        bookingStatus = "Confirmed";
        cout << "Booking #" << bookingId << " confirmed!" << endl;
    }

    void cancel() {
        bookingStatus = "Cancelled";
        cout << "Booking #" << bookingId << " cancelled." << endl;
    }

    void generateTicket() {
        cout << "========================================" << endl;
        cout << "          MOVIE TICKET                  " << endl;
        cout << "========================================" << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Status: " << bookingStatus << endl;
        cout << "Total Amount: Rs. " << totalAmount << endl;
        cout << "Booking Time: " << ctime(&bookingTime);
        cout << "========================================" << endl;
    }

    void addSeat(int showSeatId) {
        showSeatIds.push_back(showSeatId);
    }

    int getBookingId() { return bookingId; }
    string getBookingStatus() { return bookingStatus; }
    double getTotalAmount() { return totalAmount; }
};