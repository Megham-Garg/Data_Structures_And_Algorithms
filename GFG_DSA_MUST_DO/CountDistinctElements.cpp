vector <int> countDistinct (int A[], int n, int k){
    map<int,int> dist;
    vector<int> res;
    int count=0;
    for(int i=0; i<n; i++){
        if(i > k-1){
            int preSt = i - k;
            if(preSt >= 0 && dist[A[preSt]] > 0){
                dist[A[preSt]]-=1;
                if(dist[A[preSt]]<=0) count--;
            } 
        }
        if(!dist[A[i]]) count++;
        dist[A[i]]++;
        if(i > k-2) res.push_back(count);
    }
    return res;
}
