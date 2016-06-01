#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string inputString;
    getline(cin, inputString);
    int result[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char character[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char capital[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int length = inputString.length();
    cout << length;
    if (length > 1 && length <= 1000) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 26; j++) {
                if (inputString[i] == character[j] || inputString[i] == capital[j]) {
                    result[j] = 1;
                    break;
                }
            }
        }
    }
    
    bool isPangram = false;
    for (int k = 0; k < 26; k++) {
        if (result[k] == 1)  {
            isPangram = true;
        } else {
            isPangram = false;
            break;
        }
    }
    
    if (isPangram == true) {
        cout << "pangram" << endl;
    } else {
        cout << "not pangram" << endl;
    }
    return 0;
}