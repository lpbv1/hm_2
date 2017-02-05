
#include "analyst.h"
#include "stock.h"
#include <string>
#include <fstream>
#include <algorithm>
#include "Utils.h"

std::string analyst::getName() const{
    return name;
}
std::string analyst::getInitials() const{
    return initials;
}
history analyst::getHistory(){
    return History;
}
void analyst::load(std::ifstream& inFile){
//    std::ifstream inFile(file);
    while (!inFile.eof()){
        std::string line;
        getline(inFile, line);
        fileContents.push_back(line);
    }
//    std::reverse(fileContents.begin(), fileContents.end()); //method found in https://www.quora.com/Whats-the-easiest-way-to-reverse-a-vector-in-C++
    name = fileContents[0];
    name = fileContents[1];
    History.load(fileContents);
}
float analyst::getStockPerformence(std::string stockName){
    std::vector<stock> performance;
    int stockCount = 0;
    float stockPerformance = 0;
    for (int x = 0; x < History.getStock().size(); x++){
        if (History.getStock()[x].getName() == stockName){
            performance.push_back(History.getStock()[x]);
            stockCount++;
        }
    }
    if (stockCount > 0) {
        for (int x = 0; x < performance.size(); x++) {
            for (int y = 0; y < performance.size() - 1; y++) {
                if (performance[x].getPurchTime() > performance[x + 1].getPurchTime()) {
                    stock* temp = new stock;
                    *temp = performance[x];
                    performance[x] = performance[x + 1];
                    performance[x + 1] = *temp;
                    delete[]temp;
                }
            }
        }
        int minPurchaseTime = performance[0].getPurchTime();
        for (int x = 0; x < performance.size(); x++) {
            for (int y = 0; y < performance.size() - 1; y++) {
                if (performance[x].getSaleTime() < performance[x + 1].getSaleTime()) {
                    stock* temp = new stock;
                    *temp = performance[x];
                    performance[x] = performance[x + 1];
                    performance[x + 1] = *temp;
                    delete[]temp;
                }
            }
        }
        int maxSaleTime = performance[0].getSaleTime();
        int days = (maxSaleTime - minPurchaseTime) / 60 / 24;
        int stockPL;
        for (int x = 0; x < performance.size(); x++) {
            stockPL += performance[x].getProfitloss();
        }
        stockPerformance = stockPL/days;
        return stockPerformance/100;
    }
    else{
        return 0.000;
    }
}