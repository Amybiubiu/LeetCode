new Promise((resolve, reject)=>{
    for (var i = 0; i < 5; i++) {
        let a = i;
        setTimeout(function() {
            if(a == 4){
               resolve(i); 
            }
           console.log(a);
        }, 1000);
    }
}).then(i => console.log(i));
// 约定：用箭头表示其前后的两次输出之间有 1 秒的时间间隔，而逗号表示其前后的两次输出之间的时间间隔可以忽略。
// 1)    输出结果？ 
// 2)    期望代码的输出变成：5 -> 0,1,2,3,4 
// 3)    如果期望代码的输出变成 0 -> 1 -> 2 -> 3 -> 4 -> 5 , 用Promise或者await如何实现？