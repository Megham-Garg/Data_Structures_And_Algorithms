#include<bits/stdc++.h>
using namespace std;

// hashset with a doubly linked list

struct Node{
    Node* next;
    Node* prev;
    int value;
    char key;
};

class DLL{
    Node* head;
    Node* tail;
public:
    void shiftToEnd(Node* target){
        if(target == tail) return;
        Node node;
        node.key = target->key;
        node.value = target->value;
        node.next = NULL;
        node.prev = tail;
        tail = &node;
        if(target->next){
            target->key = target->next->key;
            target->value = target->next->value;
            if(target->next->next) target->next->prev = target;
            target->next = target->next->next;
        }
    }
    char remove_front(){
        char key;
        if(head){
            key = head->key;
            head = head->next;
            head->prev = NULL;
        }
        return key;
    }
    Node* append(char key, int val){
        Node node;
        node.key = key;
        node.value = val;
        node.prev = tail;
        node.next = NULL;
        tail = &node;
    }
    Node* get_head() {return head;}
};

// O(1) space
// O(1) time

class LRU_Cache{
    DLL cache;
    unordered_map<char, Node*> hash;
public:
    void insert(char key, int value){
        if(hash.size() >= 3){
            if(hash.find(key) != hash.end()){
                cache.shiftToEnd(hash[key]);
            }
            else{
                char key = cache.remove_front();
                hash.erase(key);
            }
        }
        hash[key] = cache.append(key, value);
    }

    unordered_map<char, int> get_LRUData(){
        unordered_map<char, int> res;
        if(hash.size() > 0){
            Node* front = cache.get_head();
            res[front->key] = front->value;
        }
        return res;
    }

    int get_value(char key){
        Node* target;
        if(hash.size() > 0){
            if(hash.find(key) != hash.end()) target = hash[key];
            else return INT_MIN;
            cache.shiftToEnd(target);
        }
        else{
            return INT_MIN;
        }
        return target->value;
    }
};