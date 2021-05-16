// O(1) space
// O(n) time
bool isPalindrome(string str){
    int start = 0;
    int end = str.size()-1;
    while(start < end){
        if(str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}