# 基本语法
## 基本的源程序框架
```golang
package xxxx

import {
    "xxx"
    "xxx"
}

func xxx(){

}
```

## 变量 与常量
### 变量声明
**变量类型**

```golang
空值：nil

整型类型： int(取决于操作系统), int8, int16, int32, int64, uint8, uint16, …

浮点数类型：float32, float64

字节类型：byte (等价于uint8)

字符串类型：string

布尔值类型：boolean，(true 或 false)
```
```golang
// 完整声明
var vaName dataType = value
//FE (for example)
var a int
var a int = 10
var b byte ='g'
var c int8 = 2
var d float32 = 12.1
var e bool = true
//简写
var varName = value
varName :=value//此种声明只可以用于函数内，方法内
//FE
var b=1//自动确定类型
c:=3
d:="this is go"//简写方式 
a,b := 1,"this is b"
```

### 常量

预声明标识符iota，初始值为0。一组常量同时声明时其值逐行增加，iota可以看作自增的枚举变量。

```go
//类似枚举的iota
const {
	c0 = iota //=0
	c1 = iota //=1
	c2 = iota //=2
}
//简写模式
const {
  c0 = iota //=0
  c1        //=1 
  c2        //=2
}

//注意iota逐行增加
const {
  a=1 << iota //a=1 iota=0
  b=1 << iota //b=2 iota=1
  c=3         //c=3 iota=2
  d=1 << iota //d=8 iota=3
}

const {
  u = iota * 42 //u=0
  v float64 = iota * 42 //v=42.0
  w = iota *42 //w=84
}

//分开的onst语句，iota每次都从0开始
const x = iota //x=0
const y = iota //y=0
```

### 字符串

go中字符串string是以byte形式存储的

```GO
	str1 := "abcd"
	str2 := "go笔记"

	fmt.Println(reflect.TypeOf(str2[2]).Kind()) //uint8
	fmt.Println(str1[2], string(str1[2]))       //第一个输出 ascii码的值  第二个输出字符
	fmt.Printf("%d %c\n", str2[2], 97)          //%d 为将 %c 为将ascii码转换为字符
	fmt.Println(len(str2))                      //输出8 说明中文占三个字符
```

- 因为字符串是以 byte 数组的形式存储的，所以，`str2[2]` 的值并不等于`笔`。str2 的长度 `len(str2)` 也不是 4，而是 8（ Go 占 2 byte，笔记占 6 byte）。

  因此，若想像其他语言一样对string进行操作，则需将string转成rune数组

**解决方法**
  
  将 string 转为 rune 数组
```GO
	runeArr1 := []rune(str1)
	runeArr2 := []rune(str2)
	fmt.Println(reflect.TypeOf(runeArr1[1]).Kind()) //int32 此时runeArr存储的是str1字符的ascii值
	fmt.Println(runeArr1[1], string(runeArr1[1]))   //98 b
	fmt.Println(len(str2), len(runeArr2))           //8 4
```
转换成 `[]rune` 类型后，字符串中的每个字符，无论占多少个字节都用 int32 来表示，因而可以正确处理中文。

#### Println 与 Printf的区别

```GO
	a, b := 10, "go"
	fmt.Println(a, b)

	fmt.Printf(a)  //会报错  因为Printf只能输出字符串不能输出变量 数字等
	fmt.Println(a) //换成Println就没问题了
	fmt.Printf(b + "\n")
	fmt.Printf("%v\n", a)        //这样写是正确的
	fmt.Println("Println:%v", b) //输出Println:%v go
	fmt.Printf("Println:%v", b)  //输出Println:go
```



#### golang fmt格式“占位符”

>```GO
>普通占位符
>占位符     说明                           举例                   输出
>%v      相应值的默认格式。            Printf("%v", people)   {zhangsan}，
>%+v     打印结构体时，会添加字段名     Printf("%+v", people)  {Name:zhangsan}
>%#v     相应值的Go语法表示            Printf("#v", people)   main.Human{Name:"zhangsan"}
>%T      相应值的类型的Go语法表示       Printf("%T", people)   main.Human
>%%      字面上的百分号，并非值的占位符  Printf("%%")            %
>Integer:
>%b	base 2
>%c	the character represented by the corresponding Unicode code point
>%d	base 10
>%o	base 8
>%O	base 8 with 0o prefix
>%q	a single-quoted character literal safely escaped with Go syntax.
>%x	base 16, with lower-case letters for a-f
>%X	base 16, with upper-case letters for A-F
>%U	Unicode format: U+1234; same as "U+%04X"
>String and slice of bytes (treated equivalently with these verbs):
>%s	the uninterpreted bytes of the string or slice
>```

reference:https://golang.org/pkg/fmt/

### 数组

#### 声明数组

```GO
	var arr1 [5]int    //一维[0 0 0 0 0]
	var arr2 [3][5]int //二维[[0 0 0 0 0] [0 0 0 0 0] [0 0 0 0 0]]
	var arr3 = [5]int{1, 2, 3, 4, 5}// [1 2 3 4 5]
	arr4 := [3]int{1, 2, 3}// [1 2 3]
	//遍历
	for i := 0; i < len(arr3); i++ {
		arr3[i] += 10
	}//arr3=[11 12 13 14 15]
```

数组长度不能改变，若要拼接数组，或获取子数组，需要使用切片。切片是数组的抽象。 切片使用数组作为底层结构。切片包含三个组件：容量，长度和指向底层数组的指针,切片可以随时进行扩。

- 声明切片时可以为切片设置容量大小，为切片预分配空间。在实际使用的过程中，如果容量不够，切片容量会自动扩展。
- `sub2...` 是切片解构的写法，将切片解构为 N 个独立的元素。
- 切片范围 `[start:end)`

```go
	slice1 := make([]float32, 0)    //长度为0的切片 []
	slice2 := make([]float32, 3, 5) //长度为3容量为5的切片 [0 0 0]
	fmt.Println(slice1, slice2)
	fmt.Println(len(slice2), cap(slice2)) //3 5
	//扩展
	slice2 = append(slice2, 1, 2, 3, 4)
	fmt.Println(slice2)                   //[0 0 0 1 2 3 4]
	fmt.Println(len(slice2), cap(slice2)) //7 12
	//切片 [start:end)
	sub1 := slice2[3:]  //[1 2 3 4]
	sub2 := slice2[:3]  //[0 0 0]
	sub3 := slice2[1:4] //[0 0 1]
	//合并切片
	combined := append(sub1, sub2...) //[1 2 3 4 0 0 0]
	fmt.Println(sub3, combined)
```

### 字典key-value

map 类似于 java 的 HashMap，Python的字典(dict)，是一种存储键值对(Key-Value)的数据解构。使用方式和其他语言几乎没有区别。

```go
	//仅声明
	map1 := make(map[string]int)
	//声明时初始化
	map2 := map[string]int{
		"Tom":   1,
		"Jarry": 2,
	}
	println(map1["Jarry"], map2["Jarry"]) //0 2
	map2["Jarry"] = 3
	println(map2["Jarry"]) //3
```

### 指针

```GO
	str := "golang"
	var p *string = &str
	fmt.Println(*p, str) //p指向str的地址
	*p = "helloworld"
	fmt.Println(*p, str, p) //*p更改 str也会更改 输出 helloworld helloworld 0xc00008a040
```

Go 语言中，参数是按值传递的，如果不使用指针，函数内部将会拷贝一份参数的副本，对参数的修改并不会影响到外部变量的值。如果参数使用指针，对参数的传递将会影响到外部变量。(类比C)

```GO
func main() {
	num := 10
	fun1(num)
	fmt.Println(num) //10 原数未更改
	fun2(&num)
	fmt.Println(num) //110 原数已更改

}

func fun1(num int) {
	num += 100
}
func fun2(num *int) {
	*num += 100
}
```



## 流程控制语句

### if

```GO
	age := 18
	if age > 14 {
		fmt.Println("yes")
	} else {
		fmt.Println("warning")
	}
	if age := 18; age > 14 {
		fmt.Println("warning")
	} else {
		fmt.Println("yes")
	}
```

### switch

```GO
	type Gender int8
	const (
		MALE   Gender = 1
		FEMALE Gender = 2
	)

	gender := MALE

	switch gender {
	case FEMALE:
		fmt.Println("female")
	case MALE:
		fmt.Println("male")
	default:
		fmt.Println("unknown")
	}//输出male
```

- 在这里，使用了`type` 关键字定义了一个新的类型 Gender。
- 使用 const 定义了 MALE 和 FEMALE 2 个常量，Go 语言中没有枚举(enum)的概念，一般可以用常量的方式来模拟枚举。
- 和其他语言不同的地方在于，**Go 语言的 switch 不需要 break，匹配到某个 case，执行完该 case 定义的行为后，默认不会继续往下执行**。如果需要继续往下执行，需要使用 fallthrough，例如

```GO
	switch gender {
	case FEMALE:
		fmt.Println("female")
		fallthrough
	case MALE:
		fmt.Println("male")
		fallthrough
	default:
		fmt.Println("unknown")
	}//输出male unknown
```

### for

```go
	sum := 1
	for i := 1; i < 10; i++ {
		sum *= i
		if sum > 50 {
			break
		}
	}//输出120
```

**遍历**

```GO
	arr := []int{1, 2, 3, 4, 5}
	for index, item := range arr {
		fmt.Println(index, item)
	}
    //输出
    //0 1
    //1 2
    //2 3
    //3 4
    //4 5
	m1 := map[int]string{
		1: "Tom",
		2: "Jarry",
		3: "Harry",
	}
	for key, value := range m1 {
		fmt.Println(key, value)
	}
    // 输出  
    // 1 Tom
    // 2 Jarry
    // 3 Harry
//TOFIND:在运行时发现map并不是按顺序便利的，好像是随机遍历？
```

## 函数functions

**模板**

### 函数

```GO
func funcName(param1 Type1, param2 Type2, ...) (return1 Type3, ...) {
    // body
}
```

例：实现加法和除法

```GO
func main() { 
	a := add(1, 2)
	quo, rem := div(3, 2)
	fmt.Println(a, quo, rem)//3 1 1
}

func add(num1 int, num2 int) int {
	return num1 + num2
}
func div(num1 int, num2 int) (int, int) {
	return num1 / num2, num1 % num2
}
```

可给**返回值命名**，简化return

```GO
func add(num1 int, num2 int) (ans int) {
	ans = num1 + num2
	return
}
func div(num1 int, num2 int) (quo int, rem int) {
	quo = num1 / num2
	rem = num1 % num2
	return
}
```

### 错误处理

如果函数实现过程中，如果出现不能处理的错误，可以返回给调用者处理。比如我们调用标准库函数`os.Open`读取文件，`os.Open` 有2个返回值，第一个是 `*File`，第二个是 `error`， 如果调用成功，error 的值是 nil，如果调用失败，例如文件不存在，我们可以通过 error 知道具体的错误信息。

```go
func main() { 
	_, err := os.Open("goNode.md")
	if err != nil {
		fmt.Println(err)
	} //open goNode.md: The system cannot find the file specified.
	if err := hello(""); err != nil {
		fmt.Println(err)
	}//error:name is nil
}
//通过 errorw.New 返回自定义的错误
func hello(name string) error {
	if len(name) == 0 {
		return errors.New("error:name is nil")
	}
	fmt.Println("hello", name)
	return nil
}
```

error 往往是能预知的错误，但是也可能出现一些不可预知的错误，例如数组越界，这种错误可能会导致程序非正常退出，在 Go 语言中称之为 panic。

类似于try...catch作用的捕获异常语法，Go 语言也提供了类似的机制 `defer` 和 `recover`。

```go
func get(index int) (res int) {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Some error happened!", r)
			res = -1//此处可不加 默认返回0
		}
	}()
	arr := []int{1, 2, 3}
	return arr[index]
}//Some error happened! runtime error: index out of range [5] with length 3
 //-1
```

- 在 get 函数中，使用 defer 定义了异常处理的函数，在协程退出前，会执行完 defer 挂载的任务。因此如果触发了 panic，控制权就交给了 defer。
- 在 defer 的处理逻辑中，使用 recover，使程序恢复正常，并且将返回值设置为 -1，在这里也可以不处理返回值，如果不处理返回值，返回值将被置为默认值 0。

## 结构体 方法 和接口

### struct 结构体

**结构体类似于其他语言中的 class**，可以在结构体中定义多个字段，为结构体实现方法，实例化等。接下来我们定义一个结构体 Student，并为 Student 添加 name，age 字段，并实现 `hello()` 方法。

```go
func main() {
	stu := &Student{
		name: "Tom",
	}
	stu.hello("Jarry")//hello Jarry,i am Tom
	stu2 := new(Student)//使用 new 实例化
	stu2.name = "Poter"
	stu2.hello("Harry")//hello Harry,i am Poter
}

type Student struct {
	name string
	age  int
}

func (stu *Student) hello(person string) {
	fmt.Printf("hello %v,i am %v", person, stu.name)
}
```

- 使用 `Student{field: value, ...}`的形式创建 Student 的实例，字段不需要每个都赋值，没有显性赋值的变量将被赋予默认值，例如 age 将被赋予默认值 0。
- 实现方法与实现函数的区别在于，`func` 和函数名`hello` 之间，加上该方法对应的实例名 `stu` 及其类型 `*Student`，可以通过实例名访问该实例的字段`name`和其他方法了。
- 调用方法通过 `实例名.方法名(参数)` 的方式。

### interfac 接口

一般而言，接口定义了一组方法的集合，接口不能被实例化，一个类型可以实现多个接口。

举一个简单的例子，定义一个接口 `Person`和对应的方法 `getName()` 和 `getAge()`

```GO
func main() { 
	var p Person = &Student{
		name: "Tom",
	}
	fmt.Println(p.getName())
}

type Person interface {
	getName() string
}

type Student struct {
	name string
	age  int
}

func (stu *Student) getName() string {
	return stu.name
}
```

- o 语言中，并不需要显式地声明实现了哪一个接口，只需要直接实现该接口对应的方法即可。
- 实例化 `Student`后，强制类型转换为接口类型 Person。

在上面的例子中，我们在 main 函数中尝试将 Student 实例类型转换为 Person，如果 Student 没有完全实现 Person 的方法，比如我们修改Person中的方法

```GO
type Person interface {
	getName() string
    getAge()  int
}
```

此时Student并没有完全实现Person中的方法，编译时会出现如下报错信息。

`Golang\helloword.go:7:6: cannot use &Student literal (type *Student) as type Person in assignment:
        *Student does not implement Person (missing getAge method)`

这里有个问题，在go中，没有被调用的接口即使是没有完全实现编译也不会报错，此时需要提前检测确保某个类型实现了某个接口的所有方法。

```
	var _ Person = (*Student)(nil)
	var _ Person = (*Worker)(nil)
```

此时若worker没有实现全部的方法则会报错`*Worker does not implement Person (missing getName method)`

实例可以强制类型转换为接口，接口也可以强制类型转换为实例

```GO
	var p Person = &Student{
		name: "Tom",
	}
	stu := p.(*Student)
	fmt.Println(stu.getName())
```

**空接口**

```GO
	m := make(map[string]interface{})
	m["name"] = "Tom"
	m["age"] = 18
	m["scores"] = []int{60, 75, 55, 102, 110}
	fmt.Println(m)//map[age:18 name:Tom scores:[60 75 55 102 110]]
```

## 并发编程

Go 语言提供了 sync 和 channel 两种方式支持协程(goroutine)的并发.

### sync

例如我们希望并发下载 N 个资源，多个并发协程之间不需要通信，那么就可以使用 sync.WaitGroup，等待所有并发协程执行结束。

```GO
func main() {
	for i := 0; i < 3; i++ {
		wg.Add(1)
		go download("www.abc.com/" + string(i+'0'))
	}
	wg.Wait()
	fmt.Println("Done!")
}

var wg sync.WaitGroup

func download(url string) {
	fmt.Println("start to download", url)
	time.Sleep(time.Second)
	wg.Done()
}
```

- wg.Add(1)：为 wg 添加一个计数，wg.Done()，减去一个计数。
- go download()：启动新的协程并发执行 download 函数。
- wg.Wait()：等待所有的协程执行结束。

输出

`start to download www.abc.com/2
start to download www.abc.com/1
start to download www.abc.com/0
Done!`

串行需要 3s 的下载操作，并发后，只需要 1s。

### channel

使用 channel 信道，可以在协程之间传递消息。阻塞等待并发协程返回消息。

```go
func main() {
	for i := 0; i < 3; i++ {
		go download("www.abc.com")
	}
	for i := 0; i < 3; i++ {
		msg := <-ch
		fmt.Println("Finish:", msg)
	}
	fmt.Println("Done!")
}

var ch = make(chan string, 10) //创建大小为10的缓冲信道
func download(url string) {
	fmt.Println("start to download", url)
	time.Sleep(time.Second)
	ch <- url
}
```

输出

`start to download www.abc.com
start to download www.abc.com
start to download www.abc.com
Finish: www.abc.com
Finish: www.abc.com
Finish: www.abc.com
Done!`

## 单元测试(unit test)

假设我们希望测试 package main 下 `calc.go` 中的函数，要只需要新建 `calc_test.go` 文件，在`calc_test.go`中新建测试用例即可。

```
// calc.go
package main

func add(num1 int, num2 int) int {
	return num1 + num2
}
// calc_test.go
package main

import "testing"

func TestAdd(t *testing.T) {
	if ans := add(1, 2); ans != 3 {
		t.Error("add(1, 2) should be equal to 3")
	}
}
```

运行 `go test`，将自动运行当前 package 下的所有测试用例，如果需要查看详细的信息，可以添加`-v`参数。

```
$ go test -v
=== RUN   TestAdd
--- PASS: TestAdd (0.00s)
PASS
ok      example 0.040s
```

## 一些技巧

1. 对包名进行重新设置

```GO
package main

import fm "fmt" 

func main() {
   fm.Println("hello, world")
}
```
# 常用关键字
## defer
defer 关键字 注册多个延迟调用 先进后出顺序 在函数返回前被执行
类似 finaly
用于保证一些资源最终一定能得到回收和释放,常被用于关闭文件描述符、关闭数据库连接以及解锁资源
defer 后面必须是函数或方法
defer 实现原理为延迟调用链表 当函数只有一个defer时会将结构体分配到栈上  多于一个时会分配到堆上
## panic 和 recover
panic 和 recover 用来处理Go的运行时错误  panic用来主动抛出错误，recover用来捕获panic抛出的错误
函数签名如下
```go
panic(i interface{})
recover()interface{}
```
panic 能够改变程序的控制流，`调用 panic 后会立刻停止执行当前函数的剩余代码`，并在当前 Goroutine 中递归执行调用方的 defer；
recover 可以中止 panic 造成的程序崩溃。`它是一个只能在 defer 中发挥作用的函数`，在其他作用域中调用不会发挥作用；
panic 只会触发当前 Goroutine 的 defer；
recover 只有在 defer 中调用才会生效；
panic 允许在 defer 中嵌套多次调用；
## goroutine
### 并发与并行
并发：处理多个任务的能力，不一定同时进行
单核 CPU 多任务：并发（不必等上一个任务完成才开始下一个任务）、串行（只有一个实际执行任务的 CPU 核）

并行：同时处理多个任务的能力
多线程：并发、串行（所有线程都在同一个核上执行）；并发、并行（不同线程在不同的核上执行）

线程（Thread）是程序执行流的最小单元。一个标准的线程由线程ID，当前指令指针(PC），寄存器集合和堆栈组成。另外，线程是进程中的一个实体，是被系统独立调度和分派的基本单位，线程自己不拥有系统资源，只拥有一点儿在运行中必不可少的资源，但它可与同属一个进程的其它线程共享进程所拥有的全部资源。
一个进程可包括多个线程

# debug

## VSCode: Could not import Golang package



I had a same sort of issue with a different package (on mac),



Update the go tools - ctrl + shift + p or cmd + shift + p and update/install go tools

Restart VScode

Issue solved

# 与其他语言不一样的地方

1. 没有while
2. 没有枚举
3. 输出分为Printf与Println两种
4. switch不需break
5. 流程控制语句必须加大括号{}
6. 变量声明方式

## **代码格式**

GO语言要求代码的花括号***{}\***必须采用统一的风格，即左花括号***{\***必须放在行尾而不能另起一行。

GO不需要在语句的最后增加分号***;\***以表示语句结束。

```go
if a == b {      //花括号{必须放在上一行的最后面
    a += 1       //语句后面不需要增加;号
}
```



## **常量和变量**

**常量&变量声明与赋值**

GO在进行变量声明时，需要在变量前加***var\***关键字；但GO中的变量可以不定义直接赋值，此时GO会自己根据***:=\***右侧的表达式计算出变量的类型。

同时，GO还支持多重赋值。

```go
var i int
i = 10
str := "Hello World!"
i1, str1 := 10, "Hello World!"  //多重赋值
```

在定义常量常量时，和C++一样只需要在前面增加***const\***关键字，并同时给常量赋以编译期可确定的值。

```go
const i int = 2 << 5  //=号右侧的表达式必须可以在编译期确定
const {
    i1 int = 15
    str = "Hello World!"
}
```

GO语言中有三个预定义的常量：true、false、itoa。true/false很好理解，itoa是一个很特殊和常量，它在一个const作用范围中，第一次出现时为0，后续每次出现都比上次的值大1，在GO中通常用于“枚举”（GO不支持枚举）定义。

```django
const {
    Monday = itoa       //Monday = 0
    Tuesday = itoa      //Tuesday = 1
    Wednesday = itoa    //Wedesday = 2
}

const x = itoa      //下一个const作用域，x = 0
```



**可见性**

GO语言中没有private/protected/public/friend关键字，可见性是通过成员的首字母是否大写决定的，并且仅支持包间的可见性定义，不支持类的可见性。

包中所有首字母大写开头的成员（对象、函数），表示包间可见，可以被其它包中的代码访问。但对于首字母小写开头的成员，则仅能被本包中的成员所访问（这相当于包内的所有成员间都加了friend声明）



## **条件、选择和循环**

**条件语句**

GO语言的条件语句中，条件不需要加括号***()\***，并且支持初始化语句：

```go
if a := b; a == 1 {
    //......
}
```



**选择语句**

GO的选择语句中，不支持***break\***关键字，因为GO的选择语句中，遇到符合条件的分支会自动跳出；如果想要继续向下执行，需要在**case**分支中增加***fallthrough\***关键字。

```go
switch i {
    case 0, 1:
        fmt.Printf("0")    //i等于0或1时，执行完此打印语句后会退出
    case 2:
        fallthrough        //i等于2时，会继续向下执行
    default:
        fmt.Printf("")
} 
```

在GO的switch后面可以不带表达式，此时在case中需要增加条件：

```go
switch {
    case i == 10:
        return
}
```



**循环语句**

GO不支持***while***和***do...while***形式的循环，仅支持***for***循环。在GO的***for***循环中可以通过多重赋值方式为多个变量赋值。对于多重循环，可以在最外层定义循环标签，并在内层循环中通过***break***关键字直接指定标签名，直接跳出外层循环。

```go
OutLoop:    //定义循环标签
    //死循环
    for {
        //注意，在for循环中只能使用多重赋值
        for a, b := 1, 5; a < b; a, b = a + 2, b + 1 {
            if a == 2 {
                break OutLoop    //直接跳出循环标签所定义的外层循环
            }
        }    
    }
```



## **函数**

**普通函数**

在定义GO函数时，需要在前面增加***func\***关键字，func后面紧随函数名，然后定义参数列表；GO语言是支持多返回值的，因此最后需要定义返回值列表。下面是两个int类型的除法函数示例：

```go
//参数或返回值列表中，多个相同类型的可以通过逗号合并声明
func Divide(a, b int) (ret int, err error) {
    //返回值会自动定义，在函数体内可直接赋值
    err = errors.New("Cannot divide zero!")
    if b == 0 {
        return    //在不指定时返回值时，将返回自动定义的对象（ret, err）
    }

    ret = a / b
    return ret, nil
}
```



**可变参数**

GO和C++一样也支持可变参数，同样需要将可变参数放在所有参数的最后。GO的可变参数可以指定类型，也可以通过***interface{}\***支持任意类型。

```go
func varFunc1(argv ...int)    //只可以接受int类型的可变参数
func varFunc1(argv ...interface{})   //可接受任意类型的可变参数
```



**匿名函数**

GO语言支持匿名函数，这一点是C++所不具备的。下面是一个最简单的匿名函数：

```go
f := func() {
    fmt.Println("Hello World!")
}
```

匿名函数经常会在[闭包](https://link.zhihu.com/?target=https%3A//baike.baidu.com/item/%E9%97%AD%E5%8C%85/10908873%3Ffr%3Daladdin)的场景下使用，GO语言也支持闭包。



## **错误处理**

GO语言通过error类型以及defer、panic、recover三个关键字，相对C++提供了更方便的错误处理。

**error：**

GO的error实际是一个定义了***func Error() string\***函数的接口。所有的error类型都必须实现**Error()**函数。

```go
type error interface {
    Error() string
} 
```

因为GO支持多个返回值，因此可以通过在返回值中增加error类型，更方便开发人员判断调用是否成功，比如前面定义的Devide函数的调用可以按如下方式写：

```text
ret, err := Devide(a, b)
if err != nil {
    fmt.Println(err.Error())
}
```

而在C++中要实现同样的功能，则需要函数抛出一个DevideZero异常，并在调用处捕获异常再处理；或是定义一个返回值并通过输出参数返回结果。而通过error进行处理则简单很多。



**defer**

使用C++的开发人员对C++中的内存、文件句柄等资源的释放的处理一定有很深的映像。在使用C++开发过程中，我们必须保证在函数退出或对象析构时进行正确的资源释放动作，而这在复杂的代码逻辑中往往是非常容易出错的地方。

GO语言通过defer关键字解决了开发人员的这个难题。开发人员只需要在申请了资源后立即通过defer关键字编写资源释放的代码，GO会保证在正确的时机释放资源（有点类似C++的finally）。比如下面的例子中，GO会保证在TestResource函数在退出前，调用到defer后面的代码以保证文件被关闭：

```go
func TestResource() {
    file, err := os.Open(fn)
    if err != nil {
        return
    }
    defer file.Close()
    //.......
}
```

> 注意：如果一个作用域内有多个defer，则在退出时会按先进后出的方式进行调用。因此在使用时应该尽量避免一个作用域内多个defer中的代码存在顺序要求，以避免出错。



**panic&recover**

panic和recover的函数原型如下：

```go
func panic(interface{}) 
func recover() interface{}
```

有点类似于C++中的抛出异常，在函数的执行过程中，如果panic被调用到则当前函数执行中止，此时将调用函数中走到过的defer代码，然后再依次向上级函数返回并调用这些函数的panic函数，直至当前goroutine中所有函数中止。

而recover函数通常用于在defer中用于判断函数是否是panic导致的退出：

```go
defer func() {
    if r := recover(); r != nil {
        //说明是panic的情况，进行相应的处理
    }
} 
```





## **更丰富的内建类型**

C++仅支持布尔、字符、数值内建类型，如果需要使用字符串、列表、字典，必须引入stl或其它库。

GO则将字符串、切片（slice）、字典、复数作为了原子类型支持。下面我们通过示例看一下GO对各种类型的支持：

**字符串（string）**

```text
var s string
str := "Hello World!"
s = str
```



**切片（slice）**

GO语言中的切片类似于stl中的vector，它实际包括了一个指向数组的指针，数组元素的个数，以及对应的内存存储空间。

下面的示例展示了如何通过一个数组创建slice。

```text
myArray := [5]int {1,2,3,4,5}
mySlice := myArray[:3]
//通过len和cap函数，可以获取slice的长度和容量
l, c := len(mySlice), cap(mySlice)
```

也可以通过make函数创建指定类型、长度和容量的slice：

```text
//创建一个int类型的slice，初始长度为3，但容量为5
myArray := make([]int, 3, 5)
```



**字典（map）**

在Go中定义字典类型以map[KeyType]ValueType的形式定义，示例如下：

```text
var dict map[string]int
dict := make(map[string]int, 100)  //构造了下string:int类型的map，容量为100
dict["int_1"] = 1
v, ok := dict["int_1"]  //通过判断第2个返回值是否为true，可以判断数据是否存在
```



**复数（complex64/complex128）**

除了以上常见的数据类型，Go还支持复数类型。

```text
var z complex64
z = 10 + 20i        //即10 + 20i
a = real(z)         //real获取复数的实部
b = imag(z)         //imag获取复数的虚部 
```

除了以上类型，GO还支持管道channel、unicode字符rune、错误类型error、指针pointer。这些类型在本文章中不进行更细致的讲解，请有兴趣的读者通过专业书籍或其它资源进行了解。



## **类型系统**

除了内建类型之后，GO也支持用户自定义类型，比如struct、interface，但在语法上有一些差异，比如下面的示例是GO的struct和interface的定义：

```go
type Rect struct {
    X, Y int
}

type TestItf interface {
    f()
}
```

但GO的struct和interface与C++存在几点显著的不同：

1. 不支持继承，只能通过组合实现继承
2. 可以给任意类型增加方法
3. 类不需要显式指定实现interface
4. 对象可以在多个具有相同接口的interface间转换

通过以下的示例可以更好的理解以上几点差异：

```go
//将内建类型int定义Integer
type Integer int           
//为Integer增加Add方法
func (a Integer)Add(b Integer) Integer{
    return a + b
}

type IReader interface {
    Read() string
}

type Father struct {
    I Integer
}
//Father并没有显式实现IReader接口，但通过实现了Read函数就相当于是IReader的实例了
func (f *Father)Read() string {
    fmt.Println("Father::I = ", f.I)
    return "Father's Read"
}

type Child struct {
    Father    //通过匿名组合了Father，Child自动“继承”了I成员和Func方法
}

type IStream interface {
    Read() string
}

var obj IReader
var is IStream
c := &Child{}
obj = c        //Child是IReader的实例，因为c通过组合继承了Father实现的Read方法
is = obj       //IReader因为和IStream有相同的接口定义，因此可以互相转换
```

references:https://zhuanlan.zhihu.com/p/30543250

# Go Proverbs

## Simple, Poetic, Pithy

https://go-proverbs.github.io/