#include <iostream>
#include <string>
using namespace std;

class UPIPayment : public Payment {
private:
    string upiId;
    string provider;

public:
    UPIPayment(int pId, int bId, double amt, string uId, string prov)
        : Payment(pId, bId, amt, "UPI") {
        upiId = uId;
        provider = prov;
    }

    bool processPayment() override {
        cout << "Processing UPI payment..." << endl;
        cout << "UPI ID: " << upiId << endl;
        cout << "Provider: " << provider << endl;
        cout << "Amount: Rs. " << amount << endl;

        // Simulate UPI validation
        if (upiId.find("@") != string::npos && upiId.length() > 5) {
            status = "Completed";
            transactionId = "UPI-" + to_string(paymentId) + "-" + to_string(time(nullptr));
            cout << "UPI payment successful!" << endl;
            cout << "Transaction ID: " << transactionId << endl;
            return true;
        } else {
            status = "Failed";
            cout << "UPI payment failed: Invalid UPI ID" << endl;
            return false;
        }
    }

    bool validateUPIId() {
        return upiId.find("@") != string::npos && upiId.length() > 5;
    }
};