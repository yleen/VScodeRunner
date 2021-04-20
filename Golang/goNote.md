# 基本的源程序框架
```golang
package xxxx

import {
    "xxx"
    "xxx"
}

func xxx(){

}
```

# 变量 与常量
## 变量声明
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
varName :=value
//FE
var b=1//自动确定类型
c:=3
d:="this is go"//简写方式 
a,b := 1,"this is b"
```

## 常量

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

## 字符串

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

### Println 与 Printf的区别

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



### golang fmt格式“占位符”

>```GO
>普通占位符
>占位符     说明                           举例                   输出
>%v      相应值的默认格式。            Printf("%v", people)   {zhangsan}，
>%+v     打印结构体时，会添加字段名     Printf("%+v", people)  {Name:zhangsan}
>%#v     相应值的Go语法表示            Printf("#v", people)   main.Human{Name:"zhangsan"}
>%T      相应值的类型的Go语法表示       Printf("%T", people)   main.Human
>%%      字面上的百分号，并非值的占位符  Printf("%%")            %
>
>%b	base 2
>%c	the character represented by the corresponding Unicode code point
>%d	base 10
>%o	base 8
>%O	base 8 with 0o prefix
>%q	a single-quoted character literal safely escaped with Go syntax.
>%x	base 16, with lower-case letters for a-f
>%X	base 16, with upper-case letters for A-F
>%U	Unicode format: U+1234; same as "U+%04X"
>```

reference:https://golang.org/pkg/fmt/

## 数组

### 声明数组

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

## 字典key-value

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

## 指针

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

# 流程控制语句

## if

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

# debug

## VSCode: Could not import Golang package



I had a same sort of issue with a different package (on mac),



Update the go tools - ctrl + shift + p or cmd + shift + p and update/install go tools

Restart VScode

Issue solved