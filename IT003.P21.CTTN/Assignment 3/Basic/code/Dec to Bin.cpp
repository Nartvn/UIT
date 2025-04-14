#include <bits/stdc++.h>

using namespace std;

string decimalToBinary(int x) {
    if (x == 0) {
        return "0";
    }
    
    vector<int> binaryDigits;
    while (x > 0) {
        binaryDigits.push_back(x % 2);
        x /= 2;
    }
    
    reverse(binaryDigits.begin(), binaryDigits.end());
    
    string binaryStr;
    for (int digit : binaryDigits) {
        binaryStr += to_string(digit);
    }
    
    return binaryStr;
}

int main() {
    int x;
    cin >> x;
    
    string binary = decimalToBinary(x);
    cout << binary << endl;
    
    return 0;
}