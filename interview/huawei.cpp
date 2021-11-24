/*
第一道题是括号匹配
第二道题是 1/N 2/Y 3/N 4/Y 找出相同的班级
总共有n个人在机房，每个人有一个标号（1<=标号<=n），他们分成了多个团队，需要你根据收到的m条消息判定指定的两个人是否在一个团队中，具体的：
1、消息构成为a b c，整数a、b分别代表两个人的标号，整数c代表指令
2、c == 0代表a和b在一个团队内
3、c == 1代表需要判定a和b的关系，如果a和b是一个团队，输出一行'we are a team',如果不是，输出一行'we are not a team'
4、c为其他值，或当前行a或b超出1~n的范围，输出‘da pian zi'
输入描述：
1、第一行包含两个整数n，m(1<=n,m<100000),分别表示有n个人和m条消息
2、随后的m行，每行一条消息，消息格式为：a b c(1<=a,b<=n,0<=c<=1)
输出描述:
1、c ==1,根据a和b是否在一个团队中输出一行字符串，在一个团队中输出‘we are a team',不在一个团队中输出'we are not a team’
2、c为其他值，或当前行a或b的标号小于1或者大于n时，输出字符串‘da pian zi'
3、如果第一行n和m的值超出约定的范围时，输出字符串'Null'
输入：
5 7
1 2 0
4 5 0
2 3 0
1 2 1
2 3 1
4 5 1
1 5 1
输出：
We are a team
We are a team
We are a team
We are not a team
输入：
5 6
1 2 0
1 2 1
1 5 0
2 3 1
2 5 1
1 3 2
输出：
we are a team
we are not a team
we are a team
da pian zi
*/

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