class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int size = 0;
        if(height.size() < 3)
            return 0;
        for(int i = 0; i < height.size(); i++){
            while(!stack.empty() && height[i] > height[stack.top()]){
                int popnum = stack.top();
                stack.pop();
                while(!stack.empty() && height[stack.top()] == height[popnum])
                    stack.pop();
                if(!stack.empty()){
                    int temp = height[stack.top()];
                    int h = min(height[i], temp) - height[popnum];
                    int w = i - stack.top() - 1;
                    size += w*h;
                }
            }
            stack.push(i);
        }
        return size;
    }
};
