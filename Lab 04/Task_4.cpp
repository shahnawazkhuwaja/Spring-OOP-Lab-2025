#include "iostream"
#include <cstring>

using namespace std;

class Book {
private:
    char* title;
    double price;
    int stock;

public:
    Book(const char* t, double p, int s) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        price = p;
        stock = s;
    }
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        price = other.price;
        stock = other.stock;
    }
    void display() const {
        cout << "Title: " << title << ", Price: $" << price << ", Stock: " << stock << endl;
    }

    ~Book() {
        cout << "Destroying book: " << title << endl;
        delete[] title;
    }
};

int main() {
    Book book1("AAAAA", 45.0, 10);
    Book book2 = book1;

    cout << "Original Book: ";
    book1.display();
    cout << "Copied Book: ";
    book2.display();
}