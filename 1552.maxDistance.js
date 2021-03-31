/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
const check = (p, mid, m) => {
    let count = 1;
    let pre = p[0];
    for(let i = 1; i < p.length; i++){
        if(p[i] - pre >= mid){
            pre = p[i];
            count++;
        }
    }
    return count >= m;
}


var maxDistance = function(position, m) {
    position.sort((x, y) => x-y);
    let n = position.length;
    let min_length = 1;
    let max_length = Math.floor((position[n-1] - position[0])/(m-1));
    
    let res = -1;
    while(min_length <= max_length){
        const mid = Math.floor((min_length + max_length)/2);
        if(check(position, mid, m)){
            res = mid;
            min_length = mid+1;
        }else{
            max_length = mid-1;
        }
    }
    return res;
};