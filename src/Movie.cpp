#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    int movieId;
    string title;
    string genre;
    int duration; // in minutes
    string language;
    float rating;

public:
    Movie(int id, string t, string g, int d, string lang, float r) {
        movieId = id;
        title = t;
        genre = g;
        duration = d;
        language = lang;
        rating = r;
    }

    void getDetails() {
        cout << "Movie ID: " << movieId << endl;
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Language: " << language << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }

    void updateDetails(string newTitle, string newGenre, float newRating) {
        title = newTitle;
        genre = newGenre;
        rating = newRating;
        cout << "Movie details updated successfully!" << endl;
    }

    string getTitle() { return title; }
    int getMovieId() { return movieId; }
};