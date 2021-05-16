string decode_file(struct MinHeapNode* root, string s){
    int i = 0;
    string ans = "";
    while(i < s.size()){
        struct MinHeapNode* temp = root;
        while(temp->left || temp->right){
            if(s[i]=='0') temp = temp->left;
            else temp = temp->right;
            i++;
        }
        ans += temp->data;
    }
    return ans;
}
