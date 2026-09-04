#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TicketPrinter {
private:
    string ticketFormat;

public:
    TicketPrinter(string format = "PDF") {
        ticketFormat = format;
    }

    void printTicket(int bookingId, string customerName, string movieTitle, 
                     string showTime, string seatInfo, double amount) {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════════╗\n";
        cout << "║                  MOVIE TICKET                       ║\n";
        cout << "╠══════════════════════════════════════════════════════╣\n";
        cout << "║  Booking ID   : " << bookingId << "\n";
        cout << "║  Customer     : " << customerName << "\n";
        cout << "║  Movie        : " << movieTitle << "\n";
        cout << "║  Show Time    : " << showTime << "\n";
        cout << "║  Seats        : " << seatInfo << "\n";
        cout << "║  Total Amount : Rs. " << amount << "\n";
        cout << "║  Format       : " << ticketFormat << "\n";
        cout << "║  Status       : CONFIRMED\n";
        cout << "╚══════════════════════════════════════════════════════╝\n";
        cout << "\n";
    }

    void generatePDF(int bookingId) {
        // Simulate PDF generation
        string filename = "Ticket_" + to_string(bookingId) + ".pdf";
        cout << "Generating PDF ticket: " << filename << endl;
        // In real implementation, this would create a PDF file
    }

    void setTicketFormat(string format) {
        ticketFormat = format;
    }
};