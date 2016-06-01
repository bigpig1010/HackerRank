#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string firstString;
    string secondString;
    cin >> firstString;
    cin >> secondString;

    int character[26];
    for (int i = 0; i < 26; ++i)
    {
    	character[i] = 0;
    }
    int firstLength = firstString.length();
    int secondLength = secondString.length();

    for (int j = 0; j < firstLength; ++j)
    {
    	int index = (int)(firstString[j] - 'a');
    	int count = character[index];
    	character[index] = ++count;
    }

    for (int k = 0; k < secondLength; ++k)
    {
    	int index = (int)(secondString[k] - 'a');
    	int count = character[index];
    	character[index] = count - 1;

    }

    int sumDeleteCount = 0;

    for (int m = 0; m < 26; ++m)
    {
    	int count = character[m];
    	sumDeleteCount += abs(count);
    }

    cout << sumDeleteCount << endl;

    return 0;
}
