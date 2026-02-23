#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "POTOTYPE"
#include <fstream>
#include <iomanip>
#include <sstream>

void saveData() {
    std::ofstream outFile("database.txt");
    if (outFile.is_open()) {
        outFile << std::fixed << std::setprecision(2);
        outFile << totalProfit << std::endl;
        outFile << totalShippingExpense << std::endl;
        for (const auto& p : inventory) {
            outFile << p.name << " " << p.condition << " " 
                    << p.quantity << " " << p.cost << " " << p.price << std::endl;
        }
        outFile.close();
    }
}

void loadData() {
    std::ifstream inFile("database.txt");
    if (!inFile) return;
    std::string line;
    if (std::getline(inFile, line) && !line.empty()) totalProfit = std::stod(line);
    if (std::getline(inFile, line) && !line.empty()) totalShippingExpense = std::stod(line);
    inventory.clear();
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        Product p;
        if (ss >> p.name >> p.condition >> p.quantity >> p.cost >> p.price) {
            inventory.push_back(p);
        }
    }
    inFile.close();
}
#endif