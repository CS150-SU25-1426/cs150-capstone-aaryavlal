#include "DonatedItem.h"

DonatedItem::DonatedItem() : name("Unknown"), quantity(0), donor("Anonymous") {}

DonatedItem::DonatedItem(const std::string& name, int quantity, const std::string& donor)
    : name(name), quantity(quantity), donor(donor) {}

std::string DonatedItem::getName() const { return name; }
int DonatedItem::getQuantity() const { return quantity; }
std::string DonatedItem::getDonor() const { return donor; }

void DonatedItem::setName(const std::string& name) { this->name = name; }
void DonatedItem::setQuantity(int quantity) { this->quantity = quantity; }
void DonatedItem::setDonor(const std::string& donor) { this->donor = donor; }

bool DonatedItem::operator==(const DonatedItem& other) const {
    return name == other.name && donor == other.donor;
}

std::ostream& operator<<(std::ostream& os, const DonatedItem& item) {
    os << "Item: " << item.name << ", Quantity: " << item.quantity << ", Donor: " << item.donor;
    return os;
}
