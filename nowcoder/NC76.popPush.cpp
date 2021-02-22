class Solution
{
public:
    void push(int node) {
        while(!stack1.empty()){
            int temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        stack1.push(node);
        while(!stack2.empty()){
            int temp = stack2.top();
            stack2.pop();
            stack1.push(temp);
        }
    }

    int pop() {
        int res = stack1.top();
        stack1.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};