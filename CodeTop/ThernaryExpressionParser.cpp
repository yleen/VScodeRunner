/*
给定一个以字符串表示的任意嵌套的三元表达式，计算表达式的值。你可以假定给定的表达式始终都是有效的并且只包含数字 0-9, ?, :, T 和 F (T 和 F 分别表示真和假）。

注意：

给定的字符串长度 ≤ 10000。
所包含的数字都只有一位数。
条件表达式从右至左结合（和大多数程序设计语言类似）。
条件是 T 和 F其一，即条件永远不会是数字。
表达式的结果是数字 0-9, T 或者 F。
 

示例 1：

输入： "T?2:3"

输出： "2"

解释： 如果条件为真，结果为 2；否则，结果为 3。
 

示例 2：

输入： "F?1:T?4:5"

输出： "4"

解释： 条件表达式自右向左结合。使用括号的话，相当于：

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 或者     -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
 

示例 3：

输入： "T?T?F:5:3"

输出： "F"

解释： 条件表达式自右向左结合。使用括号的话，相当于：

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 或者       -> "(T ? F : 5)"
          -> "F"                                     -> "F"
*/
#include <stack>
#include <string>
using namespace std;
class Solution{
public:
   char ThernaryExpressionParser(string expression){
      stack<char> sk;
      stack<char> k;
      for(int i = 0; i < expression.length(); i++){
         sk.push(expression[i]);
      }
      while (!sk.empty())
      {
         char c = sk.top();
         sk.pop();
         if(c == '?'){
            if(sk.top() == 'F'){
               k.pop();
            }else{
               char tmp = k.top();
               k.pop();
               k.pop();
               k.push(tmp);
            }
            sk.pop();
         }else if(c != ':'){
            k.push(c);
         }
      }
      return k.top();
   }
};
#include <iostream>
int main(){
   Solution s;
   char res = s.ThernaryExpressionParser("T?T?F:5:3");
   cout<<res<<endl;
}