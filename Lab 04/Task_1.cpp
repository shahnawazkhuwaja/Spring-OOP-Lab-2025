#include "iostream"
#include <cstring>
using namespace std;

class Book {
private:
    string title;
    double price;
    int stock;

public:
    Book() {
        title = "ABC";
        price = 0.0;
        stock = 30;
    }

    void updateDetails(string newTitle, double newPrice) {
        title = newTitle;
        price = newPrice;
    }

    void purchase(int quantity) {
        if (quantity > stock) {
            cout << "Error: Only " << stock << " copies available.\n";
        } else {
            stock -= quantity;
            cout <<"Purchase successful! Remaining stock: " << stock << endl;
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
    Book book1;
    book1.display();

    book1.updateDetails("ABCDE", 30.0);
    book1.display();
    book1.purchase(17);
    book1.display();
    book1.purchase(4);
}