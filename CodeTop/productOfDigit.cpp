/*
现给定任意正整数 n，请寻找并输出最小的正整数 m（m>9），使得 m 的各位（个位、十位、百位 ... ...）之乘积等于n，若不存在则输出 -1。

示例1
输入 36
输出 49

示例2
输入100
输出455

*/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int produce(int n) {
        if(n < 10 ){
            return 10 + n;
        }
        int num = 9;
        int m = 0;
        int base = 0;
        while (n > 1 && num != 1)
        {
            // if(n % num == 0){ 易错点 while可以把两次整除筛出来
            while(n % num == 0){
                m = m + num * pow(10, base);
                n = n / num;
                base++;
            }
            num--;
        }
        return m == 0 ? 1 : m;
    }
//牛客网
public:
    int solution(int n) {
        if (n < 10) return 10 + n;
        int res = 0, base = 1;
        for (int i = 9; i > 1; i--) {
            while (n % i == 0) {
                res += i * base;
                base*=10;
                n /= i;
            }
        }
        if (n > 1) return -1;
        else return res;
    }
};

int main(){
    Solution s;
    int res = s.produce(100);
    int res2 = s.solution(100);
    cout<<res<<"--"<<res2<<endl;
}