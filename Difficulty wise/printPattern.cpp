void printPattern(int n){
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