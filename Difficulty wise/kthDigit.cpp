int kthDigit(int A,int B,int K){
    unsigned long long int x = pow(A,B);
    x = x/pow(10, K-1);
    // cout << x << "____";
    return x%10;
}