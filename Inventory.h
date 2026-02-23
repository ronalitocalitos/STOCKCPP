#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include "FileHandler.h"
#include <iostream>
#include <iomanip>

using namespace std;

inline void addProduct() {
    Product p;
    int type;
    cout << "\n[+ Add Product]\nName: ";
    getline(cin,p.name);
    cout << "Condition (1:New , 2:Used): ";
    cin >> type;
    if ( type == 1 ){
        p.condition = "New";
    } else {
        p.condition = "Used";
    }
    cout << "Qty: ";
    cin >> p.quantity;
    cout << "Cost: ";
    cin >> p.cost;
    cout << "Price: ";
    cin >> p.price;
    inventory.push_back(p);
    saveData();
    cout << "Added Successfully!" << endl;
}

inline void showStock() {
    cout << "\n" << setfill('=') << setw(65) << "" << setfill(' ') << endl;
    cout << left << setw(15) << "Name" << setw(12) << "Condition" 
              << setw(10) << "Quantity" << setw(12) << "Cost" << setw(12) << "Price" << endl;
    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;
    cout << fixed << setprecision(2);
    for (const Product& p : inventory) {
        cout << left << setw(15) << p.name << setw(12) << p.condition
                  << setw(10) << p.quantity << setw(12) << p.cost << setw(12) << p.price << endl;
    }
    double net = totalProfit - totalShippingExpense;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Gross Profit: " << totalProfit << " | Shipping: " << totalShippingExpense << endl;
    cout << "NET PROFIT: " << net << endl;
    cout << "=================================================================" << endl;
}
#endif