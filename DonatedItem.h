#ifndef DONATED_ITEM_H
#define DONATED_ITEM_H

#include <iostream>
#include <string>

class DonatedItem {
private:
    std::string name;
    int quantity;
    std::string donor;

public:
    DonatedItem();
    DonatedItem(const std::string& name, int quantity, const std::string& donor);

    std::string getName() const;
    int getQuantity() const;
    std::string getDonor() const;

    void setName(const std::string& name);
    void setQuantity(int quantity);
    void setDonor(const std::string& donor);

    bool operator==(const DonatedItem& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DonatedItem& item);
};

#endif
