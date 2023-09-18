#include <string>
#include <vector>
using namespace std;

// SPLIT
// con lo facil que era en Rust...      let round = line.split(" ");
vector<string> split(string line, char splitAt)
{
    vector<string> split;
    size_t start = 0;
    size_t end = line.find(splitAt);

    while (end != string::npos) {
        split.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(' ', start);
    }
    split.push_back(line.substr(start, end));

    return split;
}

vector<string> split(string line, int splitAt)
{
    vector<string> split;

    if (splitAt >= 0 && splitAt < line.length()) {
        split.push_back(line.substr(0, splitAt));
        split.push_back(line.substr(splitAt));
    } else {
        split.push_back(line); // Return the whole string if splitAt is out of bounds.
    }

    return split;
}
