/*
输入一个unsigned int的数X，
求X%3的结果，并计算循环次数。
限制：不能用除法。提示：循环次数越少越好
*/
class Solution
{
public:
    int mod(unsigned int x,int count)
    {
        if (x < 4)
        {
            count+=1;
            if (x == 3)
                return 0;
            return x;
        }
        else
        {
            return mod((x >> 2) + (x & 3),count+1);
        }
    }
};
//参考https://www.zhihu.com/question/26627122