// 

#include<iostream>
#include<stack>
using namespace std;
int main(){
    

    cout<<"hello world"<<endl;
}

void stackReference(){
    stack<int> sk;//int只是举例，以实际type为准
    sk.empty();//bool 判断是否为空
    sk.size();//int 栈元素个数
    sk.top();//返回栈顶元素 只访问不删除
    sk.push(1);//压栈
    sk.emplace();//Construct and insert element
    sk.pop();//移除栈顶元素 无返回值
    stack<int> sk2;
    sk.swap(sk2);//交换元素
}