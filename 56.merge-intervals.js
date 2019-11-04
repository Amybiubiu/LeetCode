/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if(intervals.length == 0)
        return intervals;
    intervals.sort((a,b)=> a[0]-b[0]);
    var res = [];
    res.push(intervals.reduce((acc,cur)=>{
        if(acc[1]>=cur[0]){         //相同的临界值也需要合并啊
            if(acc[1]<cur[1]){
                acc[1] = cur[1];
            }
                return acc;
            
        }else{
            res.push(acc);
            return cur;
        }
    }))
    return res;
};