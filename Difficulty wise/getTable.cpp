vector<int> getTable(int N)
{
    vector<int> ans;
    for(auto i = 1; i <= 10; i++) ans.push_back(N*i);
    return ans;
}