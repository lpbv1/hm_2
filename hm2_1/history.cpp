
#include "history.h"
#include "stock.h"
#include <string>


void history::load(std::vector<std::string> fileContents) {
    days = std::stoi(fileContents[2]);
    money = std::stoi(fileContents[3]);
    stockCount = std::stoi(fileContents[4]);
    stockList.resize(stockCount);
    for (int x = 0; x < stockCount; x++){
        stockList[x].load(fileContents[x + 5]);
    }
}

void history::sort(std::vector<stock>& sortStock){
    for (int x = 0; x < sortStock.size(); x++){
        for (int y = 0; y < sortStock.size() - 1; y++){
            if (sortStock[x].getName() < sortStock[x + 1].getName()){
                stock* temp = new stock;
                *temp = sortStock[x];
                sortStock[x] = sortStock[x + 1];
                sortStock[x + 1] = *temp;
                delete[]temp;
            }
        }
    }
}

int history::getDays() {
    return days;
}

int history::getMoney() {
    return money;
}

int history::getTotalProfitloss() {
    int totalProfitLoss;
    for (int x = 0; x < stockCount; x++){
        totalProfitLoss += stockList[x].getProfitloss();
    }
    return totalProfitLoss;
}

int history::getProfitlossPerday() {
    return getTotalProfitloss()/days;
}

std::vector<stock> history::getStock(){
    return stockList;
}