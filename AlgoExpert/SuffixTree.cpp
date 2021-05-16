#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    unordered_map<char, Node*> hash;
};

// O(m) time where m is len of search string
// O(1) space where m is len of search string

// O(n^2) time where m is len of input string creation
// O(n^2) space where m is len of input string creation
class SuffixTree{
    Node* root;
public:
    SuffixTree(string str){
        root = new Node;
        root->data = '-';
        for(int i = 0; i < str.size(); i++){
            insert(str.substr(i, str.size()-i));
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
    bool search(string str){
        bool res = false;
        Node* cur = root;
        int ind = 0;
        while(cur->hash.find(str[ind]) != cur->hash.end() && ind < str.size()){
            cur = cur->hash[str[ind]];
            ind++;
        }
        if(ind == str.size() && cur->hash.find('*') != cur->hash.end()) res = true;
        return res;
    }
};

int main(){
    string test = "babc";
    SuffixTree st(test);
    cout << "babc status " << st.search("babc") << endl;
    cout << "abc status " << st.search("abc") << endl;
    cout << "bc status " << st.search("bc") << endl;
    cout << "c status " << st.search("c") << endl;
    cout << "bac status " << st.search("bac") << endl;
    cout << "ac status " << st.search("ac") << endl;
    return 0;
}