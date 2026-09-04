#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declarations
#include "Movie.cpp"
#include "Screen.cpp"
#include "Seat.cpp"
#include "Show.cpp"
#include "ShowSeat.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UPIPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {
    cout << "========================================" << endl;
    cout << "  MOVIE TICKET BOOKING SYSTEM DEMO      " << endl;
    cout << "========================================" << endl;
    cout << "\n";

    // 1. Create a Movie
    cout << "1. Creating Movie..." << endl;
    Movie movie1(101, "The Avengers: Endgame", "Action/Sci-Fi", 181, "English", 8.4);
    movie1.getDetails();
    cout << "\n";

    // 2. Create a Screen
    cout << "2. Creating Screen..." << endl;
    Screen screen1(1, 1, 501, 100);
    screen1.getSeatMap();
    cout << "\n";

    // 3. Create Seats
    cout << "3. Creating Seats..." << endl;
    Seat seat1(1, 'A', 1, "Platinum");
    Seat seat2(2, 'A', 2, "Gold");
    Seat seat3(3, 'A', 3, "Silver");
    cout << "Seats created: " << seat1.getSeatInfo() << ", " 
         << seat2.getSeatInfo() << ", " << seat3.getSeatInfo() << endl;
    cout << "\n";

    // 4. Create a Customer
    cout << "4. Creating Customer..." << endl;
    Customer customer1(1001, "Rahul Sharma", "9876543210", "rahul@email.com");
    cout << "Customer: " << customer1.getName() << " (ID: " << customer1.getCustomerId() << ")" << endl;
    cout << "\n";

    // 5. Show Selection
    cout << "5. Customer selects a show..." << endl;
    Show show1(1, 101, 1, "18:30", "2026-09-10");
    show1.getAvailableSeats();
    cout << "\n";

    // 6. Price Calculation
    cout << "6. Calculating Ticket Price..." << endl;
    PriceCalculator calculator;
    double seatPrice = calculator.calculatePrice(1, false); // Platinum seat, weekday
    double finalPrice = calculator.getFinalPrice(seatPrice);
    cout << "Base Price: Rs. 200" << endl;
    cout << "Platinum Seat Premium: 80% increase" << endl;
    cout << "Final Price after tax: Rs. " << finalPrice << endl;
    cout << "\n";

    // 7. Booking Creation
    cout << "7. Creating Booking..." << endl;
    BookingService bookingService;
    vector<int> showSeatIds = {1};
    int bookingId = bookingService.createBooking(1001, showSeatIds, finalPrice);
    cout << "\n";

    // 8. Payment Processing (UPI)
    cout << "8. Processing Payment (UPI)..." << endl;
    UPIPayment payment1(5001, bookingId, finalPrice, "rahul@paytm", "Paytm");
    if (payment1.processPayment()) {
        bookingService.confirmBooking(bookingId);
    }
    cout << "\n";

    // 9. Ticket Generation
    cout << "9. Generating Ticket..." << endl;
    TicketPrinter printer;
    printer.printTicket(bookingId, customer1.getName(), movie1.getTitle(), 
                        show1.getShowTime(), seat1.getSeatInfo(), finalPrice);
    cout << "\n";

    // 10. Show Booking Confirmation
    cout << "10. Booking Summary..." << endl;
    bookingService.viewBooking(bookingId);
    cout << "\n";

    // Demo of other payment methods
    cout << "========================================" << endl;
    cout << "  OTHER PAYMENT METHOD DEMOS            " << endl;
    cout << "========================================" << endl;
    cout << "\n";

    // Card Payment Demo
    cout << "Card Payment Demo:" << endl;
    CardPayment cardPayment(5002, 1002, 500.0, "4111111111111111", "John Doe", "12/28", "123");
    cardPayment.processPayment();
    cout << "\n";

    // Cash Payment Demo
    cout << "Cash Payment Demo:" << endl;
    CashPayment cashPayment(5003, 1003, 350.0, 500.0);
    cashPayment.processPayment();
    cout << "\n";

    // Booking Cancellation Demo
    cout << "========================================" << endl;
    cout << "  BOOKING CANCELLATION DEMO             " << endl;
    cout << "========================================" << endl;
    bookingService.cancelBooking(bookingId);
    cout << "\n";

    cout << "========================================" << endl;
    cout << "  DEMO COMPLETED SUCCESSFULLY!         " << endl;
    cout << "========================================" << endl;

    return 0;
}