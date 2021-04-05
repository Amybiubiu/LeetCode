function resolution() {
    let s = readline();
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] == '(') {
            stack.push('(');
        } else {
            if (stack.length) {
                stack.pop();
            } else {
                console.log('no');
                break；
            }
        }
    }
}