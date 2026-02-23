#ifndef SALES_H
#define SALES_H

#include "Product.h"
#include "FileHandler.h"
#include <iostream>

inline void sellProduct() {
    std::string name;
    int type, qty;
    double ship;
    std::cout << "\n[$ Sell Product]\nName: "; std::cin >> name;
    std::cout << "Condition (1:Hand-1, 2:Hand-2): "; std::cin >> type;
    std::string target = (type == 1) ? "New" : "Used";

    for (auto& p : inventory) {
        if (p.name == name && p.condition == target) {
            std::cout << "Available: " << p.quantity << " | Qty to sell: "; std::cin >> qty;
            if (qty <= p.quantity) {
                std::cout << "Shipping Cost: "; std::cin >> ship;
                p.quantity -= qty;
                totalProfit += (p.price - p.cost) * qty;
                totalShippingExpense += ship;
                std::cout << ">> Success!\n";
                saveData();
            } else { std::cout << "!! Not enough stock.\n"; }
            return;
        }
    }
    std::cout << "!! Product not found.\n";
}
#endif