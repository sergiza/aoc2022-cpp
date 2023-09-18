#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string line)
{
            // con lo facil que era en Rust...      let round = line.split(" ");
            vector<std::string> round;
            size_t start = 0;
            size_t end = line.find(' ');

            while (end != std::string::npos) {
                round.push_back(line.substr(start, end - start));
                start = end + 1;
                end = line.find(' ', start);
            }
            round.push_back(line.substr(start, end));

            return round;
}

int rock_paper_scissors(int elf, int me)
{
    if (elf == 1)
    {
        if (me == 2) { return 6; }
        if (me == 3) { return 0; }
    }
    if (elf == 2)
    {
        if (me == 3) { return 6; }
        if (me == 1) { return 0; }
    }
    if (elf == 3)
    {
        if (me == 1) { return 6; }
        if (me == 2) { return 0; }
    }
    return 3;
}

int rock_paper_scissors_inverse(int elf, int result)
{
    if (elf == 1)
    {
        if (result == 6)  { return 2;  }
        if (result == 3)  { return 1;  }
        if (result == 0)  { return 3;  }
    }
    if (elf == 2)
    {
        if (result == 6)  { return 3;  }
        if (result == 3)  { return 2;  }
        if (result == 0)  { return 1;  }
    }
    if (elf == 3)
    {
        if (result == 6)  { return 1;  }
        if (result == 3)  { return 3;  }
        if (result == 0)  { return 2;  }
    }

    return -1;
}


void e1(vector<string> input)
{
    int score = 0;
    int elf = 0;
    int me = 0;

    for(string line : input)
    {
        if (line != "")
        {
            vector<string> round = split(line);
            for (string hand : round)
            {
                if (hand[0] == 'A') { elf = 1; }
                if (hand[0] == 'B') { elf = 2; }
                if (hand[0] == 'C') { elf = 3; }
                if (hand[0] == 'X') { me = 1; }
                if (hand[0] == 'Y') { me = 2; }
                if (hand[0] == 'Z') { me = 3; }
            }
            score = score + me + rock_paper_scissors(elf, me);
            cout << "SCORE = " << score << "\t<-\t" << line << endl;
        }
    }
}

void e2(vector<string> input)
{
    int score = 0;
    int elf = 0;
    int result = 0;

    for (string line : input)
    {
        if (line != "")
        {
            vector<string> round = split(line);
            for (string hand : round)
            {
                if (hand[0] == 'A') { elf = 1; }
                if (hand[0] == 'B') { elf = 2; }
                if (hand[0] == 'C') { elf = 3; }
                if (hand[0] == 'X') { result = 0; }
                if (hand[0] == 'Y') { result = 3; }
                if (hand[0] == 'Z') { result = 6; }
            }
            int me = rock_paper_scissors_inverse(elf, result);
            score = score + me + result;
            cout << "SCORE = " << score << "\t<-\t" << line << endl;
        }
    }
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
    e2(input);

    return 0;
}
