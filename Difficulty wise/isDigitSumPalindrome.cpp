int isDigitSumPalindrome(int N) {
    long sum = 0;
    while(N){
        sum+=N%10;
        N/=10;
    }
    int rev = sum%10, temp = sum;
    sum/=10;
    
    while(sum){
        rev = sum%10 + rev*10;
        sum/=10;
    }// cout << rev << "*" << temp << "\n";
    return (rev != temp)?0:1;
}