#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BookingService {
private:
    vector<Booking> bookings;
    int bookingCounter;

public:
    BookingService() {
        bookingCounter = 1000;
    }

    int createBooking(int customerId, vector<int> showSeatIds, double amount) {
        bookingCounter++;
        Booking newBooking(bookingCounter, customerId);
        
        for (int seatId : showSeatIds) {
            newBooking.addSeat(seatId);
        }
        
        newBooking.calculateTotal(amount);
        bookings.push_back(newBooking);
        
        cout << "Booking created with ID: " << bookingCounter << endl;
        return bookingCounter;
    }

    bool cancelBooking(int bookingId) {
        for (Booking &b : bookings) {
            if (b.getBookingId() == bookingId) {
                if (b.getBookingStatus() == "Confirmed") {
                    b.cancel();
                    return true;
                } else {
                    cout << "Booking cannot be cancelled. Current status: " 
                         << b.getBookingStatus() << endl;
                    return false;
                }
            }
        }
        cout << "Booking ID not found!" << endl;
        return false;
    }

    bool confirmBooking(int bookingId) {
        for (Booking &b : bookings) {
            if (b.getBookingId() == bookingId) {
                if (b.getBookingStatus() == "Pending") {
                    b.confirm();
                    return true;
                }
            }
        }
        return false;
    }

    void viewBooking(int bookingId) {
        for (Booking &b : bookings) {
            if (b.getBookingId() == bookingId) {
                b.generateTicket();
                return;
            }
        }
        cout << "Booking not found!" << endl;
    }
};