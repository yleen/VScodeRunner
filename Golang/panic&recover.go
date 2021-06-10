/*
panic 和 recover 用来处理Go的运行时错误  panic用来主动抛出错误，recover用来捕获panic抛出的错误
函数签名如下
panic(i interface{})
recover()interface{}
*/
package main

import (
	"fmt"
	"time"
)

func main() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()

	defer func() { //defer 是延迟调用 遵从先进后出原则  只有最后一个panic才会被recover捕获
		panic("first defer panic")
	}()

	defer func() {
		panic("second defer panic")
	}()
	panic("first defer panic")
	do()
}

func do() {
	defer func() {
		if err := recover(); err != nil { //recover 可以中止 panic 造成的程序崩溃。它是一个只能在 defer 中发挥作用的函数，在其他作用域中调用不会发挥作用；
			fmt.Println(err)
		}
	}()
	go da()
	go db()
	time.Sleep(3 * time.Second)
}

func da() {
	panic("panic da")         //panic 能够改变程序的控制流，调用 panic 后会立刻停止执行当前函数的剩余代码，并在当前 Goroutine 中递归执行调用方的 defer；
	for i := 0; i < 10; i++ { //所以下方不执行了 报警告
		fmt.Println(i)
	}
}

func db() {
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}
}
