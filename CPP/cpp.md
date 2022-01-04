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

# struct和class的区别
在C++中struct得到了很大的扩充：

1. struct可以包括成员函数
2. struct可以实现继承
3. struct可以实现多态

## 区别

1. 默认的继承访问权。class默认的是private,strcut默认的是public。

```c++
struct A
{
	char name;
};  
struct B:A
{
	int age;
	int score;
};
int main(){
	B b;
	int core=b.age;//可以直接访问
	return 0;
}
```
```c++
class A
{
	char name;
};  
class B:A
{
	int age;
	int score;
};
int main(){
	B b;
	int core=b.age;//会报错
	return 0;
}
```
2. 默认访问权限：struct作为数据结构的实现体，它默认的数据访问控制是public的，而class作为对象的实现体，它默认的成员变量访问控制是private的。
   struct可以添加private/public修饰符，但是如果没有显式添加，则默认的访问权限为public，class默认为private。

```c++
struct A
{
	int age;
	int score;
};


int main(){
	A a;
	int core=a.age;//默认为public 不用添加修饰符
	return 0;
}
```
```c++
class A
{
public://默认为private 若不添加修饰符则报错
	int age;
	int score;
};


int main(){
	A a;
	int core=a.age;
	return 0;
}
```
3. 使用大括号赋值。struct如果没有定义构造函数(是的，在C++中，struct也可以定义构造函数)，可以使用大括号对struct的数据成员进行赋值,但是如果struct中定义了一个构造函数，则不能使用大括号进行赋值了。class只有在成员变量全部是public的情况下，才能使用大括号进行赋值。
```c++
struct A
{
	char name;
};
struct A2
{
	A2():name('A'){}
	char name;
};
class B
{
public:
	int age;
};

class B2
{
   public:
      void setAge( int age );
      int getAge( void );
      B2();   // 这是构造函数声明
      ~B2();  // 这是析构函数声明
 
   private:
      int age;
};

int main(){
	A a={'a'};
	A2 a2={'a'};
	B b={1};
	B2 b2={1};
	return 0;
}
```
4. "class"这个关键字还用于定义模板参数，就像"typename"。但关建字"struct"不用于定义模板参数

**总结：**
  1) 对类及对象进行建模时，使用class。
  2) 对数据结构进行建模时，使用struct。
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
# 关于指针的使用规范
```cpp
int *p
int* p
```
在C语言中，我们这样把p声明为一个int类型的指针 int *p，而在C++中我们使用int* p     https://www.zhihu.com/question/52305847?rf=21136956
```

# map 与 count 的区别
https://stackoverflow.com/questions/25490357/checking-for-existence-in-stdmap-count-vs-find