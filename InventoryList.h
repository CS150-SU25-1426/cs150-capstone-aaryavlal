#ifndef INVENTORY_LIST_H
#define INVENTORY_LIST_H

#include <vector>
#include <string>
#include "DonatedItem.h"

class InventoryList {
private:
    std::vector<DonatedItem> items;
    int findItemIndex(const std::string& name) const;

public:
    void addItem(const DonatedItem& item);
    void editItem(const std::string& name, const DonatedItem& updatedItem);
    void deleteItem(const std::string& name);
    void displayItems() const;
};

#endif
