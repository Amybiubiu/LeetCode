let a = readline().split(',').map(x => +x);
let n = a.length;
let res = [];
for(let i = 0; i < n; i += 2){
    res.push(a[i]);
}
for(let i = n%2 ? n-2 : n-1; i > 0; i -= 2){
    res.push(a[i]);
}
console.log(res.join(','));
// let a = readline().split(',').map(x => +x);
let a = [1,2,3,4,5,6,7,8,9,10];
let n = a.length;
let res = Array(n);
let lastnumIndex = n%2 ? Math.floor(n/2): n/2;
for(let i = 0; i < n; i++){
    let index = 0;
    if(i%2){
        index = lastnumIndex + Math.floor((n-i)/2);
    }else{
        index = Math.ceil(i/2);
    }
    res[index] = a[i];
    console.log('index:'+index, 'value:'+a[i]);
}
console.log(res);
// console.log(res.join(','));