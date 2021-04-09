// let str = '{[()]}';
let str = '{{]]()'

const resolution = (s) => {
    let map = new Map();
    map.set('[',']');
    map.set('{', '}');
    map.set('(', ')');
    let stack = [];
    for(let i = 0; i < s.length; i++){
        if(map.get(s[i])){
            stack.push(map.get(s[i]));
        }else{
            if(stack.length){
                if(stack.pop() != s[i]){
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if(stack.length){
        return false;
    }else{
        return true;
    }
}
console.log(resolution(str));