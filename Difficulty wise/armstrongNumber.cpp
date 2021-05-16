string armstrongNumber(int n){
    int x = pow(n%10,3) + pow((n/10)%10,3) + pow(n/100,3);
    if(x==n) return "Yes";
    return "No";
}