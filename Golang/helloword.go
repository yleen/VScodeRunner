//编译 go build helloword.go
//运行 ./helloword
package main

import "fmt"

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

// todo:defer
