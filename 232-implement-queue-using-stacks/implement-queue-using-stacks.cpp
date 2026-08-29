class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()){//unless s1 is empty 
            s2.push(s1.top());//insert top value in s2
            s1.pop();//removing inputed value
        }
        s1.push(x);//after that insert that val
        while(s2.size()){
            s1.push(s2.top());//filling again from opp end to get it right 
            s2.pop();
        }

    }
    
    int pop() {
       int val = s1.top(); 
       s1.pop();   
       return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.size()==0)return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */