#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <limits>

class Grocery {
    public:
        Grocery();
        void printMap();
        void printStar();
        void addItem(std::string item); 
        const std::map<std::string, int>& getMap() const;
    private:
        std::map<std::string, int>freq;
};


#endif 