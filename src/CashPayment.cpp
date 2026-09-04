#include <iostream>
#include <string>
using namespace std;

class CashPayment : public Payment {
private:
    double cashTendered;
    double changeAmount;

public:
    CashPayment(int pId, int bId, double amt, double cash)
        : Payment(pId, bId, amt, "Cash") {
        cashTendered = cash;
        changeAmount = 0;
    }

    bool processPayment() override {
        cout << "Processing Cash payment..." << endl;
        cout << "Amount Due: Rs. " << amount << endl;
        cout << "Cash Tendered: Rs. " << cashTendered << endl;

        if (cashTendered >= amount) {
            changeAmount = cashTendered - amount;
            status = "Completed";
            transactionId = "CASH-" + to_string(paymentId) + "-" + to_string(time(nullptr));
            cout << "Cash payment successful!" << endl;
            cout << "Change Amount: Rs. " << changeAmount << endl;
            cout << "Transaction ID: " << transactionId << endl;
            return true;
        } else {
            status = "Failed";
            cout << "Cash payment failed: Insufficient cash" << endl;
            cout << "Please provide Rs. " << (amount - cashTendered) << " more." << endl;
            return false;
        }
    }

    double calculateChange() {
        if (cashTendered >= amount) {
            return cashTendered - amount;
        }
        return 0;
    }
};