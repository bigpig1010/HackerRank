#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int lines = 0;
    cin >> lines;
    cin.ignore();
    int result[lines];
    
    for (int i = 0; i < lines; i++) {
        string inputString;
        getline(cin, inputString);
        int count = 0;
        int length = inputString.length();
        for (int j = 0; j < length; j++) {
            if (inputString[j] == inputString[j+1] && j != length - 1) {
                cout << inputString[j] << " " << inputString[j+1] << endl;
                count++;
            }
        }
        result[i] = count;
    }
    
    for (int k = 0; k < lines; k++) {
        cout << result[k] << endl;
    }
    
    return 0;
}