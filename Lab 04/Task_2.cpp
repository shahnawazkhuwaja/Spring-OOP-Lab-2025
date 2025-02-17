#include "iostream"
#include <cstring>
using namespace std;

class Book {
private:
    string title;
    double price;
    int stock;

public:
    Book(string t, double p, int s) {
        title = t;
        price = p;
        stock = s;
    }

    void applyDiscount(int quantity) {
        if (quantity > 10) {
            price *= 0.90;
        } else if (quantity > 5) {
            price *= 0.95;
        }
    }

    void purchase(int quantity) {
        if (quantity > stock) {
            cout << "Error: Only " << stock << " copies available.\n";
        } else {
            applyDiscount(quantity);
            stock -= quantity;
            cout << "Purchase successful! Remaining stock: " << stock << endl;
            if (stock < 5) {
                cout << "Warning: Low stock!\n";
            }
        }
    }
    void display() const {
        cout << "Title: " << title << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

int main() {
    Book book2("ABCDE", 40.0, 12);
    book2.display();

    book2.purchase(4);
    book2.display();
    book2.purchase(11);
    book2.display();
}
