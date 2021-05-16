void printPat(int n){
    int x = n;
    for(int i = n; i > 0; i--){
        x = n+1;
        for(int j = 0; j < n*i; j++){
            if(j%i == 0) x--;
            cout << x << " ";
        }
        x = n;
        cout << "$";
    }
}

/* You a given a number N. You need to print the pattern for the given value of N.
for N = 2 the pattern will be 
2 2 1 1
2 1
for N = 3 the pattern will be 
3 3 3 2 2 2 1 1 1
3 3 2 2 1 1
3 2 1 */
