#include <iostream>
#include <string>
using namespace std;

class CardPayment : public Payment {
private:
    string cardNumber;
    string cardHolder;
    string expiry;
    string cvv;

public:
    CardPayment(int pId, int bId, double amt, string cardNo, string holder, string exp, string c)
        : Payment(pId, bId, amt, "Card") {
        cardNumber = cardNo;
        cardHolder = holder;
        expiry = exp;
        cvv = c;
    }

    bool processPayment() override {
        cout << "Processing Card payment..." << endl;
        cout << "Card Type: " << (cardNumber.substr(0, 1) == "4" ? "Visa" : "MasterCard") << endl;
        cout << "Card Holder: " << cardHolder << endl;
        cout << "Amount: Rs. " << amount << endl;

        // Simulate card validation
        if (cardNumber.length() >= 16 && cvv.length() == 3) {
            status = "Completed";
            transactionId = "CARD-" + to_string(paymentId) + "-" + to_string(time(nullptr));
            cout << "Card payment successful!" << endl;
            cout << "Transaction ID: " << transactionId << endl;
            return true;
        } else {
            status = "Failed";
            cout << "Card payment failed: Invalid card details" << endl;
            return false;
        }
    }

    bool validateCard() {
        return cardNumber.length() >= 16 && cvv.length() == 3;
    }
};