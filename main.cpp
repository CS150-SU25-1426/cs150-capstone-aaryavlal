#include <iostream>
#include <string>
#include "DonatedItem.h"
#include "InventoryList.h"

void displayMenu() {
    std::cout << "\n--- Donation Inventory Menu ---\n";
    std::cout << "1. Add Donated Item\n";
    std::cout << "2. Edit Donated Item\n";
    std::cout << "3. Delete Donated Item\n";
    std::cout << "4. Show All Items\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    InventoryList inventory;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

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

            inventory.addItem(DonatedItem(name, quantity, donor));

        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter name of item to edit: ";
            std::getline(std::cin, name);

            std::string newName, newDonor;
            int newQty;
            std::cout << "Enter new name: ";
            std::getline(std::cin, newName);
            std::cout << "Enter new quantity: ";
            std::cin >> newQty;
            std::cin.ignore();
            std::cout << "Enter new donor: ";
            std::getline(std::cin, newDonor);

            inventory.editItem(name, DonatedItem(newName, newQty, newDonor));

        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter name of item to delete: ";
            std::getline(std::cin, name);

            inventory.deleteItem(name);

        } else if (choice == 4) {
            inventory.displayItems();

        } else if (choice == 5) {
            std::cout << "Exiting program.\n";
            break;

        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
