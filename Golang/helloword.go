package main //声明了 main.go 所在的包，Go 语言中使用包来组织代码。一般一个文件夹即一个包，包内可以暴露类型或方法供其他包使用。
import (
	"fmt"
	"time"
)

//fmt 是 Go 语言的一个标准库/包，用来处理标准输入输出。

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
