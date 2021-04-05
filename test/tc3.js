// let a = readline().split(' ').map(x => +x);
// let n = a[0];
// let m = a[1];
function isValid(mid, n, m){
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += mid;
        mid = Math.ceil(mid/2);
    }
    return sum <= m;
}
function firstDay(n, m){
    let l = 0;
    let r = m;
    while(l < r){
        console.log(l, r);
        let mid = Math.ceil((l + r)/2);
        if(isValid(mid, n, m)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
console.log(firstDay(58, 80));