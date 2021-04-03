let arr = readline().split(' ').map(x => +x);
let n = arr[0];
let m = arr[1];
let sum = -1;
let isPostive = false;
for(let i = 1; i < n; i++){
    if(i%m == 0){
        isPostive = !isPostive;
    }
    let num = isPostive ? i+1 : 0 - (i+1);
    sum += num;
}
console.log(sum);
console.log(m*m*(n/2*m));