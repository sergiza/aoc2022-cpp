#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void e1(vector<string> input)
{
}

void e2(vector<string> input)
{
}

int main() {
    // INPUT
    ifstream input_file("../../input/02");
    if (!input_file.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }
    vector<string> input;
    string line;
    while (getline(input_file, line)) {
        input.push_back(line);
    }
    /* input.push_back("");    // append empty line */

    // SOLVE
    /* e1(input); */
    /* e2(input); */

    return 0;
}
