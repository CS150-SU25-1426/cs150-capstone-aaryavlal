#include "InventoryList.h"
#include <iostream>

int InventoryList::findItemIndex(const std::string& name) const {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void InventoryList::addItem(const DonatedItem& item) {
    items.push_back(item);
    std::cout << "Item added.\n";
}

void InventoryList::editItem(const std::string& name, const DonatedItem& updatedItem) {
    int index = findItemIndex(name);
    if (index != -1) {
        items[index] = updatedItem;
        std::cout << "Item updated.\n";
    } else {
        std::cout << "Item not found.\n";
    }
}

void InventoryList::deleteItem(const std::string& name) {
    int index = findItemIndex(name);
    if (index != -1) {
        items.erase(items.begin() + index);
        std::cout << "Item deleted.\n";
    } else {
        std::cout << "Item not found.\n";
    }
}

void InventoryList::displayItems() const {
    if (items.empty()) {
        std::cout << "No items to display.\n";
    } else {
        for (const auto& item : items) {
            std::cout << item << std::endl;
        }
    }
}
