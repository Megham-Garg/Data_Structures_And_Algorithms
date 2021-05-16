void heapify(int arr[], int n, int i)  {
    while(i < n){
        int left = 2*i + 1;
        int right = 2*i + 2;
		int l = i; // largest index
        if(left < n && arr[left] > arr[l]) l = left;
		if(right < n && arr[right] > arr[l]) l = right;
		if(l!=i) swap(arr[l], arr[i]);
		else break;
		i=l;
    }
}
void buildHeap(int arr[], int n)  { 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
}
