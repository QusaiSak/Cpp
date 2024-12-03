#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> main;
    stack<int> minS;
public:
    MinStack() {

    }
    
    void push(int val) {
        main.push(val);
        if (!minS.empty()){
            minS.push(min(val,minS.top()));
        }else{
            minS.push(val);
        }
    }
    
    void pop() {
        if(!main.empty()){
            if(main.top()==minS.top()){
                minS.pop();
            }
            main.pop();
        }
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minS.top();
    }
};