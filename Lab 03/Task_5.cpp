#include "iostream"
#include <string>
using namespace std;

class GroceryStore {
private:
    string items[50];
    float prices[50];
    int itemCount;

public:
    GroceryStore() : itemCount(0) {}
    void addItem(const string& item, float price) {
        if (itemCount < 50) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added: " << item << " - Price: $" << price << endl;
        } else {
            cout << "Inventory is full. Cannot add more items.\n";
        }
    }

    void updatePrice(const string& item, float newPrice) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == item) {
                prices[i] = newPrice;
                cout << "Price of " << item << " updated to $" << newPrice << endl;
                return;
            }
        }
        cout << "Item not found in inventory.\n";
    }

    void viewInventory() const {
        if (itemCount == 0) {
            cout << "No items in the inventory.\n";
        } else {
            cout << "Inventory:\n";
            for (int i = 0; i < itemCount; i++) {
                cout << items[i] << " - $" << prices[i] << endl;
            }
        }
    }

    void generateReceipt(const string& item, int quantity) const {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == item) {
                float totalCost = prices[i] * quantity;
                cout << "Receipt:\nItem: " << item 
                     << "\nQuantity: " << quantity 
                     << "\nTotal Cost: $" << totalCost << endl;
                return;
            }
        }
        cout << "Item not found in inventory. Cannot generate receipt.\n";
    }
};

int main() {
    GroceryStore store;

    store.addItem("Milk", 1.50);
    store.addItem("Eggs", 2.99);
    store.addItem("Bread", 1.20);
    store.viewInventory();
    store.updatePrice("Eggs", 3.25);
    store.generateReceipt("Milk", 3);

}
