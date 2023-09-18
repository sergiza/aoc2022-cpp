#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void e1(vector<string> input)
{
    int c_current = 0;
    int c_max = 0;
    
    for(string line: input)
    {
        if (line != "")
            c_current = c_current + stoi(line);
        else
            c_current = 0;

        if (c_current > c_max)
            c_max = c_current;

        cout << c_current << "(+" << line << ")" << "\tMAX=" << c_max << endl;
    }
}

void e2(vector<string> input)
{
    int c_current = 0;
    int c_max_1 = 0;
    int c_max_2 = 0;
    int c_max_3 = 0;
    
    for(string line: input)
    {
        if (line != "")
            c_current = c_current + stoi(line);
        else
        {
            if (c_current > c_max_1)
            {
                c_max_3 = c_max_2;
                c_max_2 = c_max_1;
                c_max_1 = c_current;
            }
            else if (c_current > c_max_2)
            {
                c_max_3 = c_max_2;
                c_max_2 = c_current;
            } 
            else if (c_current > c_max_3)
            {
                c_max_3 = c_current;
            }
            cout << c_max_1 << ">" << c_max_2 << ">" << c_max_3 << "\t(Current:" << c_current << ")" << endl;
            c_current = 0;
        }
    }

    cout <<  "Total calories carried by the top 3 elves: " << c_max_3 + c_max_2 + c_max_1 << endl;
}

int main() {
    // INPUT
    ifstream input_file("../../input/01mini");
    if (!input_file.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }
    vector<string> input;
    string line;
    while (getline(input_file, line)) {
        input.push_back(line);
    }
    input.push_back("");    // append empty line

    // SOLVE
    /* e1(input); */
    e2(input);

    return 0;
}
