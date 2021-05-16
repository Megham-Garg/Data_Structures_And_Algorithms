void dfs(Node* node, vector<char>& arr, const map<Node*, vector<Node*>> graph){
    arr.push_back(node->data);
    for(auto child : graph[node]) dfs(child, arr, graph);
}//O(v+e) time
//O(v) space call stack frames