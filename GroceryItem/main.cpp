#include "Grocery.h"
using namespace std;
// out put the map into the output file
void intoFile(ofstream& outputFile, map<string, int>& freqMap){
    for(auto itr = freqMap.begin(); itr != freqMap.end(); itr++){
        outputFile << itr -> first << ": " << itr -> second << endl;
    }
    outputFile << endl;
    
    for(auto itr = freqMap.begin(); itr != freqMap.end(); itr++){
        outputFile << itr -> first << ": ";
        for(int i = 0; i < itr->second ; i++){
            outputFile <<"*";
        }
        outputFile << endl;
    }

}


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    Grocery list = Grocery();
    string item;
    string input;
// making sure the files are open
    if (!outputFile.is_open() || !inputFile.is_open()){
        cerr << "Error opening output file." << endl;
        return 1;
    }
// looping through each item in the input.txt file and adding each item one by one.
    while(inputFile >> item){
        list.addItem(item);
    }
    map<string , int> freqMap = list.getMap(); //taking the class map and creating a copy to use.

    //exception handling and loop used to re ask for input 
    while(true) {
        cout << "Enter the item you wish to look for: " ;
        try{
            cin >> input;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input.");
            }
            break;
        } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        }
    }
    intoFile(outputFile, freqMap); // calling the function to output into the output.txt
    cout << freqMap[input] << endl;


}


