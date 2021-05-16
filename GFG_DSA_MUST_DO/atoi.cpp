int atoi(string str){
    int num=0; int n = str.size(); bool f;
    f=(str[0]=='-');
    if(!isdigit(str[0]) && str[0]!='-')return -1;
    for(int i = 1; i < n; i++){
        if(!isdigit(str[i])) return -1;
    }
    for(int i = 1; i < n && f; i++){
        num+=(str[i]-48)*pow(10,n-i-1);
    }if(f) return num*-1;
    for(int i = 0; i < n && !f; i++){
        num+=(str[i]-48)*pow(10,n-i-1);
    }return num;
}
