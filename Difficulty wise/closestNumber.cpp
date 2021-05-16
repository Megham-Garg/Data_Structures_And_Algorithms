int closestNumber(int N , int M) {
    M = abs(M);
    if(! N%M) return N;
    int x = abs(N/M);
    if(abs(abs(N) - x*M) > abs(abs(N) - (x+1)*M)) return (N/abs(N))*M*(x+1);
    else if(abs(abs(N) - x*M) < abs(abs(N) - (x+1)*M)) return (N/abs(N))*M*(x);
    return (N/abs(N))*M*(1+x);
}