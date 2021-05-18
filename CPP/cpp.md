# 栈Stack
```cpp
    #include<stack>
    using namespace std;
    
    stack<int> sk;//int只是举例，以实际type为准
    sk.empty();//bool 判断是否为空
    sk.size();//int 栈元素个数
    sk.top();//返回栈顶元素 只访问不删除
    sk.push(1);//压栈
    sk.emplace();//Construct and insert element
    sk.pop();//移除栈顶元素 无返回值
    stack<int> sk2;
    sk.swap(sk2);//交换元素
```
# long short int的区别

int	        4bytes	-2147483648 to 2147483647
short int	2bytes	-32768 to 32767
long int	8bytes	-2,147,483,648 to 2,147,483,647

short int 简写为short
long int 简写为long
# 使用cmake编译项目
需要安装 CMake 和mingw
1. 在该项目中创建CmakeLists.txt文件，与将要编译的项目平行。
2. windows中直接执行`cmake . -G "Unix Makefiles"`。 //先执行`cmake .`,若没有生成`Makefile`文件，将CMakeCache.txt删除，并执行`cmake . -G "Unix Makefiles"`。 
3. 确定当前目录中生成了`Makefile`文件，执行`make`命令。
4. 注意 若执行中报错则说明安装的环境有问题。
