#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int lines = 0;
    cin >> lines;
    if (lines < 1 || lines > 10)
    {
    	return 0;
    }

    while(lines--)
    {
    	string firstString;
    	cin >> firstString;
    	string secondString;
    	cin >> secondString;
    	int firstLength = firstString.length();
    	for (int i = 0; i < firstLength; ++i)
    	{
    		int pos = secondString.find(firstString[i]);
    		if (pos != -1)
    		{
    			cout << "YES" << endl;
    			break;
    		}
    		if (i == firstLength - 1)
    		{
    			cout << "NO" << endl;	
    		}
    	}
    }



    return 0;
}
