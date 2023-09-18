#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

int offset(char chara)
{
    if (isupper(chara)) { return static_cast<int>(chara) - 38; }
    else                { return static_cast<int>(chara) - 96; }
}

void e1(vector<string> input)
{
    char repeating;
    int sum = 0;

    for (string line : input)
    {
        vector<string> halves = split(line, (int) line.length()/2);

        for (char c : halves[0])
            if (halves[1].find(c) != string::npos)      // if halves[1].contains(c)
                repeating = c;

        sum = sum + offset(repeating);
        cout << sum << "\t" << repeating << " -> " << halves[0] << " | "<< halves[1] << endl;
    }
}

void e2(vector<string> input)
{
    char repeating;
    int sum = 0;

    int group = 0;
    string line_0 = "";
    string line_1 = "";

    for (string line : input)
        switch (group)
        {
            case 0:
                line_0 = line;
                group = group + 1;
                break;

            case 1:
                line_1 = line;
                group = group + 1;
                break;

            case 2:
                for (char c : line)
                    if (line_0.find(c) != string::npos)     // if line_0.contains(c)
                        if (line_1.find(c) != string::npos) // if line_1.contains(c)
                            repeating = c;
                sum = sum + offset(repeating);
                cout << sum << "\t" << repeating << " -> " << line_0 << " & " << line_1 << " & " << line << endl;
                group = 0;
                break;
            default:
                group = 0;
                break;
        }
}

int main() {
    // INPUT
    ifstream input_file("../../input/03");
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
    e2(input);

    return 0;
}
