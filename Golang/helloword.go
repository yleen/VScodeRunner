package main//声明了 main.go 所在的包，Go 语言中使用包来组织代码。一般一个文件夹即一个包，包内可以暴露类型或方法供其他包使用。

import "fmt"//fmt 是 Go 语言的一个标准库/包，用来处理标准输入输出。

func main() {//main 函数是整个程序的入口，main 函数所在的包名也必须为 main。

  fmt.Println("Hello go")




	a,b:=10,"=b"
	fmt.Println(a,b)

}