
#include "stock.h"
#include "Utils.h"
#include <string>

void stock::load(std::string stockStat){
    std::string stats[8];
    split(stockStat, ',', stats, 8);
    name = stats[0];
    quantity = std::stoi(stats[1]);
    purchaseTime = std::stoi(stats[2]);
    purchasePrice = std::stoi(stats[3]);
    purchaseFee = std::stoi(stats[4]);
    saleTime = std::stoi(stats[5]);
    salePrice = std::stoi(stats[6]);
    saleFee = std::stoi(stats[7]);
}

std::string stock::getName() const{
    return name;
}

int stock::getQuantity() const{
    return quantity;
}

int stock::getPurchTime() const{
    return purchaseTime;
}

int stock::getPurchPrice() const{
    return purchasePrice;
}

int stock::getPurchFee() const{
    return purchaseFee;
}

int stock::getSaleTime() const{
    return saleTime;
}

int stock::getSalePrice() const{
    return salePrice;
}

int stock::getSaleFee() const{
    return saleFee;
}

int stock::getInvestment(){
    investment = quantity*purchasePrice+purchaseFee+saleFee;
    return investment;
}

int stock::getProfitloss(){
    return quantity*salePrice-investment;
}

