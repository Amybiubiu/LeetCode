class Solution {
public:
    double unsignedPow(double x, unsigned int exponent){
        if(exponent == 0){
            return 1;
        }
        if(exponent == 1){
            return x;
        }
        // 如果 exponent 的不为 unsigned int 的话，右处问题？？
        double res = unsignedPow(x, exponent>>1);
        res *= res;
        if((exponent & 0x1) == 1){
            res *= x;
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        // long absExponent = n > 0 ? (long)(n) : -(long)(n);
        unsigned int absExponent = n > 0 ? (unsigned int)(n) : -(unsigned int)(n);
        // runtime error: negation of -2147483648 cannot be represented in type 'int'; 
        // cast to an unsigned type to negate this value to itself (solution.cpp
        double res = unsignedPow(x, absExponent);
        return n > 0 ? res : 1.0/res;
    }
};