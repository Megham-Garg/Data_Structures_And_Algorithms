#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n) time
string ceaserCipherEncrypter(string str, int k){
    for(int ind = 0; ind < str.size(); ind++){
        str[ind] = char(97 + (str[ind]-97+k) % 26);
    }
    return str;
}

int main(){
    cout << ceaserCipherEncrypter("xyzabjdjop", 2);
    return 0;
}