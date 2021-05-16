int binary_to_decimal(string str)
{
    int bin = 0;
    int ind = str.length()-1;
    for(auto ch : str) {if(ch == '1') bin += pow(2,ind); ind--;}
    return bin;
}