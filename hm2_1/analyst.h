
#ifndef HM2_1_ANALYST_H
#define HM2_1_ANALYST_H
#include <string>
#include <fstream>
#include "history.h"
class analyst {
private:
    std::string name;
    std::string initials;
    history History;
    std::vector<std::string> fileContents;
public:
    std::string getName() const;
    std::string getInitials() const;
    history getHistory();
    void load (std::ifstream& inFile);
    float getStockPerformence(std::string stockName);
};


#endif //HM2_1_ANALYST_H
