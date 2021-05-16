void preOrder(Node* root, map<int, pair<int,int>> &comb, int hd, int vd){
    if(comb.find(hd)==comb.end())
        comb[hd] = make_pair(root->data, vd);
        
    else if(comb[hd].second <= vd){     //  takes care of this test case
                                        //           20
                                        //         /    \
                                        //       8       22
                                        //     /   \     /   \
                                        //   5      3   4     25
                                        //          /    \      
                                        //      10       14
                                        // where 4 overlaps 3
        comb[hd].second = vd;
        comb[hd].first = root->data;
    }
    
    if(root->left) preOrder(root->left, comb, hd-1, vd+1);
    if(root->right) preOrder(root->right, comb, hd+1, vd+1);
}

vector<int> bottomView(Node *root){ 
    map<int, pair<int,int>> comb; // combination container with horizontal and
                                  // vertical distance
    vector<int> result;           // resulting vector
    preOrder(root, comb, 0, 0);
    
    for(auto it=comb.begin(); it!=comb.end(); it++)
        result.push_back((it->second).first);
    return result;
}
