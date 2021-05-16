void dfs(vector<int> A[], int n, int m, int x, int y, int &count, int stat) {
    if(x<n && x>=0 && y>=0 && y<m && A[x][y]==1){
        A[x][y] = -1;
        dfs(A,n,m,x-1,y,count,1);
        dfs(A,n,m,x,y-1,count,1);
        dfs(A,n,m,x+1,y,count,1);
        dfs(A,n,m,x,y+1,count,1);
        dfs(A,n,m,x+1,y+1,count,1);
        dfs(A,n,m,x-1,y-1,count,1);
        dfs(A,n,m,x+1,y-1,count,1);
        dfs(A,n,m,x-1,y+1,count,1);
        if(stat==0) {count++;}
    }
}

int findIslands(vector<int> A[], int n, int m) {
    int count = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(A[i][j] == 1) {dfs(A,n,m,i,j,count,0);}
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(A[i][j] == -1) A[i][j]=1;
    return count;
}
