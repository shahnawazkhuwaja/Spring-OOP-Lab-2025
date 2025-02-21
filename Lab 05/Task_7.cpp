#include "iostream"
#include <cstring>
using namespace std;

class Product {
    int id;
    char name[50];
    float price;

public:
    Product(int i = 0, const char* n = "", float p = 0.0) {
        id = i;
        strcpy(name, n);
        price = p;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    float getPrice() const { return price; }
    const char* getName() const { return name; }
};

class Inventory {
    Product* products;
    int size;

public:
    Inventory(int s) : size(s) {
        products = new Product[size];
    }

    void inputProducts() {
        int id;
        char name[50];
        float price;
        for (int i = 0; i < size; i++) {
            cout << "Enter details for Product " << i + 1 << " (ID Name Price): ";
            cin >> id >> name >> price;
            products[i] = Product(id, name, price);
        }
    }
    void sortProductsByPrice() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (products[j].getPrice() > products[j + 1].getPrice()) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
    }
    void searchProduct(const char* searchName) const {
        for (int i = 0; i < size; i++) {
            if (strcmp(products[i].getName(), searchName) == 0) {
                cout << "Product Found: ";
                products[i].display();
                return;
            }
        }
        cout << "Product not found!" << endl;
    }
    void displayProducts() const {
        cout << "\nProduct Inventory:\n";
        for (int i = 0; i < size; i++) {
            products[i].display();
        }
    }
    ~Inventory() {
        delete[] products;
    }
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Inventory store(n);
    
    store.inputProducts();
    store.sortProductsByPrice();
    store.displayProducts();
    char searchName[50];
    cout << "\nEnter product name to search: ";
    cin >> searchName;
    store.searchProduct(searchName);
}