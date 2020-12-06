﻿#include "days.h"

#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

using namespace std;

inline vector<string> read_lines(string file_name)
{
    ifstream infile(file_name);
    string line;
    vector<string> myLines;
    while (getline(infile, line))
    {
        myLines.push_back(line);
    }
    return myLines;
}

void Day02()
{
    auto lines = read_lines("../input/input02.txt");

    regex rgx("(.+)-(.+) (.+): (.+)");
    smatch matches;
    auto validPasswords1 = 0, validPasswords2 = 0;
    for (const auto & line : lines)
    {
        regex_search(line, matches, rgx);
        size_t min = stoul(matches[1].str());
        size_t max = stoul(matches[2].str());
        auto character = matches[3].str()[0];
        auto password = matches[4].str();
        auto count = 0u;
        for (auto item : password)
        {
            if (item == character)
            {
                ++count;
            }
        }
        if (min <= count && count <= max)
        {
            ++validPasswords1;
        }
        if ((password[min - 1] == character || password[max - 1] == character) &&
            password[min - 1] != password[max - 1])
        {
            ++validPasswords2;
        }
    }

    cout << "Part 1: " << validPasswords1 << endl;
    cout << "Part 2: " << validPasswords2 << endl;

    cout << endl;
}