function compress( str ) {
    // write code here
    let stack = [];
    let res = '';
    let pre = '';
    for(let i = 0; i < str.length;){
        if(str[i] == '['){
            let num = str[++i];
            let value = '';
            i = i+2;
            while('A'<= str[i] && str[i] <= 'Z'){
                value += str[i];
                i++;
            }
            let pair = {num, value};
            stack.push(pair);
        }else if(str[i] == ']'){
            let tem_pair = stack.pop();
            let {num, value} = tem_pair;
            if(stack.length == 0){
                let s = (value+pre).repeat(num);
                res += s;
                pre = '';
            }else{
                pre = value.repeat(num);
            }
            i++;
        }else{
            res += str[i];
            i++;
        }
    }
    return res;
}
console.log(compress("HG[3|B[2|CA]]F"));