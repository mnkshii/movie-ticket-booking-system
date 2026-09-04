#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string phone;
    string email;

public:
    Customer(int id, string n, string p, string e) {
        customerId = id;
        name = n;
        phone = p;
        email = e;
    }

    void createBooking() {
        cout << "Booking created for customer: " << name << endl;
    }

    void cancelBooking() {
        cout << "Booking cancelled for customer: " << name << endl;
    }

    void viewHistory() {
        cout << "Viewing booking history for: " << name << endl;
    }

    string getName() { return name; }
    int getCustomerId() { return customerId; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
};