#include <iostream>
#include <vector>
#include <string>
#include "DonatedItem.h"

void displayMenu() {
    std::cout << "\n--- Donation Inventory Menu ---\n";
    std::cout << "1. Add Donated Item\n";
    std::cout << "2. Edit Donated Item\n";
    std::cout << "3. Delete Donated Item\n";
    std::cout << "4. Show All Items\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int findItemIndex(const std::vector<DonatedItem>& items, const std::string& name) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    std::vector<DonatedItem> items;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        if (choice == 1) {
            std::string name, donor;
            int quantity;

            std::cout << "Enter item name: ";
            std::getline(std::cin, name);
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cin.ignore();
            std::cout << "Enter donor name: ";
            std::getline(std::cin, donor);

            items.emplace_back(name, quantity, donor);
            std::cout << "Item added.\n";

        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter name of item to edit: ";
            std::getline(std::cin, name);

            int index = findItemIndex(items, name);
            if (index != -1) {
                std::string newName, newDonor;
                int newQty;
                std::cout << "Enter new name: ";
                std::getline(std::cin, newName);
                std::cout << "Enter new quantity: ";
                std::cin >> newQty;
                std::cin.ignore();
                std::cout << "Enter new donor: ";
                std::getline(std::cin, newDonor);

                items[index].setName(newName);
                items[index].setQuantity(newQty);
                items[index].setDonor(newDonor);
                std::cout << "Item updated.\n";
            } else {
                std::cout << "Item not found.\n";
            }

        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter name of item to delete: ";
            std::getline(std::cin, name);

            int index = findItemIndex(items, name);
            if (index != -1) {
                items.erase(items.begin() + index);
                std::cout << "Item deleted.\n";
            } else {
                std::cout << "Item not found.\n";
            }

        } else if (choice == 4) {
            if (items.empty()) {
                std::cout << "No items to display.\n";
            } else {
                for (const auto& item : items) {
                    std::cout << item << std::endl;
                }
            }

        } else if (choice == 5) {
            std::cout << "Exiting program.\n";
            break;

        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
