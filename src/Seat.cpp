#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    int seatId;
    char rowNumber;
    int seatNumber;
    string type; // Gold, Silver, Platinum
    bool isBooked;

public:
    Seat(int id, char row, int num, string t) {
        seatId = id;
        rowNumber = row;
        seatNumber = num;
        type = t;
        isBooked = false;
    }

    void book() {
        isBooked = true;
        cout << "Seat " << rowNumber << seatNumber << " booked successfully!" << endl;
    }

    void unbook() {
        isBooked = false;
        cout << "Seat " << rowNumber << seatNumber << " unbooked." << endl;
    }

    bool isAvailable() {
        return !isBooked;
    }

    string getSeatInfo() {
        return string(1, rowNumber) + to_string(seatNumber) + " (" + type + ")";
    }

    string getType() { return type; }
    int getSeatId() { return seatId; }
};