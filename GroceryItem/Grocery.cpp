#include "Grocery.h"
using namespace std;
Grocery::Grocery(){}
// print the map with the frequency next to it
void Grocery::printMap() {
    for(auto itr = freq.begin(); itr != freq.end(); itr++){
        cout << itr -> first << ": " << itr -> second << endl;
    }
}
// print the * instead of the int next to each item
void Grocery::printStar() {
    for(auto itr = freq.begin(); itr != freq.end(); itr++){
        cout << itr -> first << ": ";
        for(int i = 0; i < itr->second ; i++){
            cout <<"*";
        }
        cout << endl;
    }
}
// take in an item which is by default zero if it didn't exist then add one
void Grocery::addItem(string item) {
    freq[item]++;
}
// return the map that was created when needed usually at the end of the creation
const map<string, int>& Grocery::getMap() const{
    return freq;
}