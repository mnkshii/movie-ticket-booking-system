#include <iostream>
#include <string>
using namespace std;

class Payment {
protected:
    int paymentId;
    int bookingId;
    double amount;
    string method;
    string status;
    string transactionId;

public:
    Payment(int pId, int bId, double amt, string m) {
        paymentId = pId;
        bookingId = bId;
        amount = amt;
        method = m;
        status = "Pending";
        transactionId = "";
    }

    virtual bool processPayment() = 0; // Pure virtual - abstract class
    
    bool refund() {
        if (status == "Completed") {
            status = "Refunded";
            cout << "Refund processed successfully!" << endl;
            return true;
        }
        cout << "Refund failed: Payment not completed." << endl;
        return false;
    }

    void verifyStatus() {
        cout << "Payment Status: " << status << endl;
    }

    int getPaymentId() { return paymentId; }
    string getStatus() { return status; }
    string getTransactionId() { return transactionId; }
};