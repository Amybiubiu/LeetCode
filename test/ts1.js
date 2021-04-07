const getNumber = () => {
    return Math.floor(Math.random()* 10);
}
const getNumber2 = (a) => {
    return Math.floor(Math.random()* a);
}
const wrap = (fn) => {
    let res = {};
    return function(...args){
        if(args.length){
            let num = fn(args[0]);
            res = {[args[0]]: num, ...args};
            return res[args[0]];
        }else{
            let num = fn();
            // res['noArgs'] = num;
            res = {'noArgs': num, ...args};
            return res['noArgs'];
        }
    }
}
const fn = wrap(getNumber);
console.log(fn());
console.log(fn());

const fn2 = wrap(getNumber2);
console.log(fn2(1));
console.log(fn2(1));
console.log(fn2(2));
console.log(fn2(2));