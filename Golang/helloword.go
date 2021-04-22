package main //声明了 main.go 所在的包，Go 语言中使用包来组织代码。一般一个文件夹即一个包，包内可以暴露类型或方法供其他包使用。
import "fmt"

//fmt 是 Go 语言的一个标准库/包，用来处理标准输入输出。

var (
	firstName, lastName, s string
	i                      int
	f                      float32
	input                  = "56.12 / 5212 / Go"
	format                 = "%f / %d /%s"
)

func main() {
	fmt.Println("please enter your full name:")
	fmt.Scanln(&firstName, &lastName)
	fmt.Printf("Hi %s %s!", firstName, lastName)
}
