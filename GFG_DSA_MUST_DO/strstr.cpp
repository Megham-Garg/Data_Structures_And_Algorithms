int strstr(string s, string x)
{
    int i = 0, j = 0;
    while(i < s.size()){
        if(s[i]==x[j]) {if(j==x.size()-1) return i-j; j++;}
        else j = 0;
        i++;
    }
    return -1;
}
