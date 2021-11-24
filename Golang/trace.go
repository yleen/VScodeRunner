package main

import (
	"fmt"
	"os"
	"runtime/trace"
)

//trace 的编译过程
//1 创建文件
//2 启动
//3 停止
func main() {
	//创建一个trace文件
	f, err := os.Create("trace.out")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	//启动trace
	err = trace.Start(f)
	if err != nil {
		panic(err)
	}

	//正常要调试的业务
	fmt.Println("Hello GMP")

	//停止trace
	trace.Stop()

}
