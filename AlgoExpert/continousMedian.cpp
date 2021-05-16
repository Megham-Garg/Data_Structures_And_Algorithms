#include<bits/stdc++.h>
using namespace std;

class contMean{
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    float median;
public:
    contMean(){
        median = 0;
    }
    void newNum(int num){
        if(maxH.size() == minH.size()){
            if(maxH.size() == 0) maxH.push(num);
            else if((num >= maxH.top() && num <= minH.top()) || (num <= maxH.top())){
                maxH.push(num);
            }
            else{
                minH.push(num);
            }
        }
        else if(maxH.size() > minH.size()){
            if(maxH.top() <= num) minH.push(num);
            else{
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(num);
            }            
        }
        else{
            if(minH.top() >= num) maxH.push(num);
            else{
                maxH.push(minH.top());
                minH.pop();
                minH.push(num);
            }            
        }
    }
    float getMedian(){
        if(maxH.size() == 0 && minH.size() == 0) cout << "no number in stream\n";
        else if(maxH.size() == minH.size()) {
            median = float((minH.top() + maxH.top())) / 2;
        }
        else if(maxH.size() > minH.size()){
            median = maxH.top();
        }
        else{
            median = minH.top();
        }
        return median;
    }
};

int main(){
    contMean cm;
    cm.newNum(5);
    cout << cm.getMedian() << "\n";
    cm.newNum(10);
    cout << cm.getMedian() << "\n";
    cm.newNum(100);
    cout << cm.getMedian() << "\n";
    cm.newNum(200);
    cout << cm.getMedian() << "\n";
    cm.newNum(6);
    cout << cm.getMedian() << "\n";
    cm.newNum(13);
    cout << cm.getMedian() << "\n";
    cm.newNum(14);
    cout << cm.getMedian() << "\n";
    return 0;
}