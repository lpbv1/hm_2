
#ifndef HM2_1_HISTORY_H
#define HM2_1_HISTORY_H
#include "stock.h"
#include <string>
#include <vector>

class history {
private:
    std::vector<stock> stockList;
    int days;
    int money;
    int stockCount;
public:
    void load(std::vector<std::string> fileContents);
    void sort(std::vector<stock>& sortStock);
    int getDays();
    int getMoney();
    int getTotalProfitloss();
    int getProfitlossPerday();
    std::vector<stock> getStock();
};


#endif //HM2_1_HISTORY_H
