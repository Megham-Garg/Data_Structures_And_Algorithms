// #include<bits/stdc++.h>
// using namespace std;

// struct Node{
//     char data;
//     unordered_map<char, Node*> hash;
// };

// // O(b^2 + ns)
// // O(b^2 + n)
// class SuffixTree{
//     Node* root;
// public:
//     SuffixTree(string str){
//         root = new Node;
//         root->data = '-';
//         for(int i = 0; i < str.size(); i++){
//             insert(str.substr(i, str.size()-i));
//         }
//     }
//     void insert(string str){
//         Node* cur = root;
//         int ind = 0;
//         while(cur->hash.find(str[ind]) != cur->hash.end() && ind < str.size()){
//             cur = cur->hash[str[ind]];
//             ind++;
//         }
//         for(int i = ind; i < str.size(); i++){
//             Node* node = new Node;
//             node->data = str[i];
//             cur->hash[str[i]] = node;
//             cur = node;
//         }
//         cur->hash['*'] = NULL;
//     }
//     bool search(string str){
//         bool res = false;
//         Node* cur = root;
//         int ind = 0;
//         while(cur->hash.find(str[ind]) != cur->hash.end() && ind < str.size()){
//             cur = cur->hash[str[ind]];
//             ind++;
//         }
//         if(ind == str.size()) res = true;
//         return res;
//     }
// };

// int main(){
//     string bigString = "This is a big string";
//     SuffixTree st(bigString);
//     vector<string> smallStrings = {"This", "yo", "is", "a", "bigger", "string", "kappa"};
//     vector<bool> isPresent;
//     for(auto str : smallStrings){
//         isPresent.push_back(st.search(str));
//     }
//     for(auto stat: isPresent) cout << stat << " ";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    unordered_map<char, Node*> hash;
};

// O(bs + ns)
// O(sn)
class SuffixTree{
    Node* root;
public:
    SuffixTree(vector<string> arr){
        root = new Node;
        root->data = '-';
        for(auto str: arr){
            insert(str);
        }
    }
    void insert(string str){
        Node* cur = root;
        int ind = 0;
        while(cur->hash.find(str[ind]) != cur->hash.end() && ind < str.size()){
            cur = cur->hash[str[ind]];
            ind++;
        }
        for(int i = ind; i < str.size(); i++){
            Node* node = new Node;
            node->data = str[i];
            cur->hash[str[i]] = node;
            cur = node;
        }
        cur->hash['*'] = NULL;
    }
    pair<string, bool> search(string str){
        bool res = false;
        Node* cur = root;
        int ind = 0;
        string keyString = "";
        while(cur->hash.find(str[ind]) != cur->hash.end() && ind < str.size()){
            cur = cur->hash[str[ind]];
            keyString.append(str, ind, 1);
            ind++;
        }
        if(ind != 0 && cur->hash.find('*') != cur->hash.end()) res = true;
        return make_pair(keyString, res);
    }
};

int main(){
    string bigString = "This is a big string";
    vector<string> smallStrings = {"This", "yo", "is", "a", "bigger", "string", "kappa"};
    SuffixTree st(smallStrings);
    unordered_map<string, bool> isPresent;
    for(int i = 0; i < bigString.size(); i++){
        pair<string, bool> pr = st.search(bigString.substr(i));
        isPresent[pr.first] = pr.second;
    }
    for(auto ele : smallStrings){
        if(isPresent.find(ele) != isPresent.end()) cout << ele << " : " << isPresent[ele] << "\n";
        else cout << ele << " : " << false << "\n";
    }
    return 0;
}