#include "iostream"
using namespace std;

class Movie {
    string title;
    string director;
    int duration;
public:
    Movie (string t, string d, int dur): title(t), director(d), duration(dur) {}

    void display() const {
        cout << "Movie: " << title << ", Director: " << director << ", Duration: " << duration << " mins" << endl;
    }
};

class CinemaHall {
private:
    string hallName;
    Movie** movies;
    int movieCount;

public:
    CinemaHall(string name, Movie movieList[], int count) : hallName(name), movieCount(count) {
        movies = new Movie*[movieCount];
        for (int i =0; i< movieCount; i++) {
            movies[i] =new Movie(movieList[i]);
        }
    }

    void display() const {
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Movies Currently Screening:\n";
        for (int i =0; i<movieCount; i++) {
            movies[i]->display();
        }
    }

    ~CinemaHall() {
        for (int i = 0; i < movieCount; i++) {
            delete movies[i];
        }
        delete[] movies;
    }
};

int main() {
    Movie movieList[] = {
        Movie("ABC", "fff", 111),
        Movie("xyz", "ddd", 123),
        Movie("eee", "dsa", 143)
    };
    CinemaHall hall("abc Cineplex", movieList, 3);
    hall.display();
}