long long int reverse_digit(long long int n)
{
    long long int rev = n%10;
    n/=10;

    while(n){
        rev = n%10 + rev*10;
        n/=10;
    }
    return rev;
}