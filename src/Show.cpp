#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Show {
private:
    int showId;
    int movieId;
    int screenId;
    string showTime;
    string date;

public:
    Show(int id, int mId, int sId, string time, string d) {
        showId = id;
        movieId = mId;
        screenId = sId;
        showTime = time;
        date = d;
    }

    void getAvailableSeats() {
        cout << "Show ID: " << showId << endl;
        cout << "Date: " << date << " Time: " << showTime << endl;
        cout << "Checking seat availability for this show..." << endl;
        // This would normally query Screen for seat info
    }

    int getMovieId() { return movieId; }
    int getScreenId() { return screenId; }
    int getShowId() { return showId; }
    string getShowTime() { return showTime; }
    string getDate() { return date; }
};