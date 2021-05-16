int binary_search(int target, vector<int> array){
    int start = 0, end = array.size()-1;
    int mid = end/2;
    while(start <= end){
        if(array[mid] == target) return mid;
        else if(array[mid] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}
// o(log(n)) time
// o(1) space

// In recursive soln
// space O(log(n)) due to recursion stack