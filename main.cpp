// Conner Tash
// Gets input from the file text.txt and then reads in the dates to 
// put in order. Once the dates are in order output the file to 
// a text file called ouput.txt.
#include <vector>
#include <algorithm>
#include <fstream>
#include "Date.h"

using namespace std;

int main(int argc, char const *argv[]) 
{
    int numberLines, m, d, y;
    vector<Date> allDates;
    string line, dateName;
    stringstream ss;

    // Opens the text file for the input
    ifstream datesInput;
    datesInput.open(argv[1], ios::in);

    // Verfication that the file opened
    if(!datesInput.is_open()) 
    {
        cout << "Unable to open file."; 
        return EXIT_FAILURE;
    }

    // Reads the first line of the text file
    getline(datesInput, line);
    numberLines = stoi(line);

    for(int i = 0; i < numberLines; i++) 
    {      
            getline(datesInput, line);
            
            // If the line has more than one char, add it to the vector
            if(line.length() > 1)
            {
                ss << line;
                ss >> m >> d >> y;
                allDates.push_back(Date(m, d, y)); 
                
                ss.clear();
            }
    }
    // Close input file
    datesInput.close();

    sort(allDates.begin(), allDates.end(), Date::compare);

    // Open the output file 
    ofstream datesOutput;
    datesOutput.open(argv[2]);
    
    // Prints the edited lines to the output file
    for(int i = 0; i < numberLines; i++)
    {
        datesOutput << allDates.at(i).print() << endl;
    }

    return 0;
}