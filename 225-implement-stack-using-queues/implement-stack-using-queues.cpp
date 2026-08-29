class MyStack {
public:
    queue<int >q;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();//taking before size
        q.push(x);
        for(int i = 1;i<=s;i++){
            q.push(q.front());//taking value pushing it 
            q.pop();//removing from back
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0)return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */