class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '('){
                stack.push(0);
            }else{
                if(stack.top() == 0){
                    stack.pop();
                    stack.push(1);
                }else{
                    int temp = 0;
                    while(!stack.empty() && stack.top() != 0){
                        temp += stack.top();
                        stack.pop();
                    }
                    stack.pop();
                    stack.push(2*temp);
                }
            }
        }
        int res = 0;
        while(!stack.empty()){
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};