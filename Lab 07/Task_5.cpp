#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, publisher;
    int uniqueID;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string pub, int id)
        : title(t), publicationDate(pubDate), publisher(pub), uniqueID(id), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nPublisher: " << publisher << "\nUnique ID: " << uniqueID << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    bool search(string searchTitle) { return title == searchTitle; }
    bool search(int searchYear) { return stoi(publicationDate) == searchYear; }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string pub, int id, string auth, string isbn, int pages)
        : Media(t, pubDate, pub, id), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN
             << "\nNumber of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    double rating;

public:
    DVD(string t, string pubDate, string pub, int id, string dir, int dur, double rate)
        : Media(t, pubDate, pub, id), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration
             << " minutes\nRating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string pub, int id, string art, int tracks, string gen)
        : Media(t, pubDate, pub, id), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks
             << "\nGenre: " << genre << endl;
    }
};

int main() {
    Book book("idk", "2024", "abc Press", 123, "xyz", "032152348", 350);
    DVD dvd("abc", "2013", "xyz", 234, "lmn", 158, 7.8);
    CD cd("xyz", "2022", "abc", 432, "opq", 8, "efg");

    cout << "\nDisplaying Media Information:\n";
    book.displayInfo();
    cout << endl;
    dvd.displayInfo();
    cout << endl;
    cd.displayInfo();
    cout << endl;
    cout << "\nChecking out items:\n";
    book.checkOut();
    dvd.checkOut();
    cout << endl;

    cout << "\nReturning items:\n";
    book.returnItem();
    dvd.returnItem();
    cout << endl;

    cout << "Searching for 'abc': ";
    if (dvd.search("abc"))
        cout << "Found!\n";
    else
        cout << "Not found.\n";

    cout << "Searching for items from 2024: ";
    if (book.search(2024))
        cout << "Found!\n";
    else
        cout << "Not found.\n";
 return 0;
}
