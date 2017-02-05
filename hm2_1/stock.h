
#ifndef HM2_1_STOCK_H
#define HM2_1_STOCK_H

#include <string>


class stock {
private:
    std::string name;
    int quantity;
    int purchaseTime;
    int purchasePrice;
    int purchaseFee;
    int saleTime;
    int salePrice;
    int saleFee;
    int investment;
public:
    std::string getName()const;
    int getQuantity()const;
    int getPurchTime()const;
    int getPurchPrice()const;
    int getPurchFee()const;
    int getSaleTime()const;
    int getSalePrice()const;
    int getSaleFee()const;
    int getInvestment();
    int getProfitloss();
    void load (std::string stockStat);
};


#endif //HM2_1_STOCK_H
