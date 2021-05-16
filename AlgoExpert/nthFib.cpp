// O(2^n) time
// O(n) space
int nthFib(int n){
    if(n<2) return n;
    return nthFib(n-1)+nthFib(n-2);
}

// O(n) time
// O(1) space
int nthFib_v2(int n){
    if(n<2) return n;
    int f = 0, s = 1;
    n-=1;
    int temp;
    while(n--){
        temp = f;
        f = s;
        s = s + temp;
    }
    return s;
}