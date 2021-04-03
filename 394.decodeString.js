/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    let numStack = [];
    let strStack = [];
    let res = '';
    let num = 0;
    for(const char of s){
        if(!isNaN(char)){
            num = num * 10 + Number(char);
        }else if(char == '['){
            strStack.push(res);
            numStack.push(num);
            num = 0;
            res = '';
        }else if(char == ']'){
            let num = numStack.pop();
            res = strStack.pop() + res.repeat(num);
        }else{
            res += char;
        }
    }
    return res;
};