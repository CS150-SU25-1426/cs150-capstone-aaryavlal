#include <iostream>
#include "DonatedItem.h"

int main() {
    DonatedItem item1("Blankets", 10, "Red Cross");
    DonatedItem item2("Blankets", 10, "Red Cross");
    DonatedItem item3("Canned Food", 20, "John Doe");

    std::cout << item1 << std::endl;
    std::cout << item3 << std::endl;

    if (item1 == item2)
        std::cout << "Item 1 and Item 2 are the same." << std::endl;
    else
        std::cout << "Item 1 and Item 2 are different." << std::endl;

    if (item1 == item3)
        std::cout << "Item 1 and Item 3 are the same." << std::endl;
    else
        std::cout << "Item 1 and Item 3 are different." << std::endl;

    return 0;
}
