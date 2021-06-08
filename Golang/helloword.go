//编译 go build helloword.go
//运行 ./helloword
package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	fmt.Printf("Hello world\n")

	fmt.Printf("/*有名函数*/\n")
	fmt.Printf("%T\n", add)
	a := do(add, 1, 2) //函数名可当作相同参数函数类型形参
	fmt.Println(a)
	s := do(sub, 1, 2)
	fmt.Println(s)
	add(1, 2)
	//有名的函数可直接赋值给变量
	f := add
	f(1, 2)

	fmt.Printf("/*匿名函数*/\n")
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()
	sum(1, 2)
	doinput(func(x, y int) int {
		return x + y
	}, 1, 2)
	opFunc := wrap("add")
	re := opFunc(2, 3)
	fmt.Printf("%d\n", re)

	fmt.Printf("/*defer*/\n")
	deferMethod()
	deferMethod2()
}

//函数签名与匿名函数

/*有名函数*/
func add(a, b int) int {
	return a + b
}

func sub(a, b int) int {
	return a - b
}

type Op func(int, int) int //定义一个函数类型，输入两个int 输出一个int

func do(f Op, a, b int) int { //第一个参数是函数类型
	return f(a, b)
}

/*匿名函数*/
var sum = func(a, b int) int {
	return a + b
}

func doinput(f func(int, int) int, a, b int) int {
	return f(a, b)
}

func wrap(op string) func(int, int) int {
	switch op {
	case "add":
		return func(a, b int) int {
			return a + b
		}
	case "sub":
		return func(a, b int) int {
			return a + b
		}
	default:
		return nil
	}
}

/*
defer 关键字 注册多个延迟调用 先进后出顺序 在函数返回前被执行
类似 finaly
用于保证一些资源最终一定能得到回收和释放
defer 后面必须是函数或方法
*/
func deferMethod() {
	defer func() {
		fmt.Println("first") //第三个
	}()
	defer func() {
		fmt.Println("second") //第二个
	}()
	fmt.Println("function body") //第一个输出
}
func deferMethod2() {
	i := 10
	defer func(i int) {
		fmt.Println("defer i=", i) //此处输出10
	}(i)
	i++
	fmt.Println(i) //此处为11
}
func deferMethod3() {
	i := 10
	defer func(i int) {
		fmt.Println("defer i=", i) //此处输出10
	}(i)
	i++
	fmt.Println("主动调用os.Exit时defer不执行")
	os.Exit(1)
}

//defer的实际应用
//defer 可用来注册资源释放函数，防止忘记资源释放
func CopyFile(dst, src string) (w int64, err error) {
	newSrc, err := os.Open(src)
	if err != nil {
		return
	}
	defer newSrc.Close()
	newDst, err := os.Open(dst)
	if err != nil {
		return
	}
	defer newDst.Close()
	w, err = io.Copy(newDst, newSrc)
	return
}
