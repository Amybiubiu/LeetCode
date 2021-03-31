class MaxQueue {
private:
    queue<int> q1;
    deque<int> q2;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(q2.empty()){
            return -1;
        }
        return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        while(!q2.empty() && q2.back() <= value){
            q2.pop_back();
        }
        q2.push_back(value);
    }
    
    int pop_front() {
        if(q1.empty()){
            return -1;
        }
        int res = q1.front();
        q1.pop();
        if(q2.front() == res){
            q2.pop_front();
        }
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */