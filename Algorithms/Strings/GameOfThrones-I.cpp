#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
   
    string s;
    cin>>s;
    int character[26];
    for (int j = 0; j < 26; ++j)
    {
    	character[j] = 0;
    }
    int length = s.length();
    int flag = 0;
    bool odd = false;

    for (int i = 0; i < length; ++i)
    {
    	int index = int(s[i] - 'a');
    	int count = character[index];
    	character[index] = ++count;
    }

    for (int m = 0; m < 26; ++m)
    {
    	int count = character[m];
    	if (count % 2 != 0 && !odd)
    	{
    		flag = 1;
    		odd = true;
    	}
    	else if (count % 2 == 0)
    	{
    		flag = 1;
    	}
    	else if (count % 2 != 0 && odd)
    	{
    		flag = 0;
    		break;
    	}
    }

    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
