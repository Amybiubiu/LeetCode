/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
//我自己的版本
var equalSubstring = function(s, t, maxCost) {
    var max = 0;
    var curCost = 0;
    var left = 0;
    var right = 0;
    while(right < s.length-1){
       for(var i = left; curCost <= maxCost && i < s.length; i++){
           curCost += Math.abs(s[i] - t[i]);
           if(curCost <= maxCost){
               right++;
           }
       }
        max = Math.max(right-left+1,max);
        curCost = curCost - Math.abs(s[left]-t[left]) + Math.abs(s[right+1]-t[right+1]);
        left++;
        right++;
    }
    return max;
};
//仿照ac的版本
//魔怔了，都通不过！
//js是有什么鬼？？
// var equalSubstring = function(s, t, maxCost) {
//     var max = 0;
//     var curCost = 0;
//     var left = 0;
//     var right = 0;
//     while(right < s.length){
           
//         curCost += Math.abs(s[right] - t[right]);
//         while(curCost >  maxCost){
//             curCost -= Math.abs(s[left]-t[left]);
//             left++;
//         }
//         max = Math.max(max,right-left+1);
//         right++;
//     }
//     return max;
// };
//ac c++
// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) { 
//         // 初始ans为0
//         int ans = 0, cost = 0;
//         int len = s.size();
//         int left = 0, right=0;
//         while(right < len){
//             //扩大窗口
//             cost += abs(t[right] - s[right]);
//             //如果当前窗口的cost大于maxCost，右移left，缩小窗口，直到窗口的cost不大于maxCost
//             while(cost > maxCost){
//                 cost -= abs(t[left] - s[left]);
//                 left ++;
//             } 
//             //如果当前窗口大小比上一次计算的ans还大，更新ans
//             ans = max(ans, right-left+1);
//             right++;            
//         }
//         return ans;
//     }
// };
