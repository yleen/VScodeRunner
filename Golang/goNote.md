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

