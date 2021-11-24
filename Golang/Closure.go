//闭包
package main

func main() {
	f := fa(1)
	g := fa(1)
	println("因为a为局部变量，两者引用的闭包环境中的a不是一个 而是两次调用产生的副本")
	println(f(1))
	println(g(1))

	f1 := fb()
	g1 := fb()
	println("b为全局变量则会改变")
	println(f1(1))
	println(g1(1))

	println("同一个函数返回的多个闭包共享该函数的局部变量")
	f2, g2 := fc(1)
	f3, g3 := fc(2)
	println(f2(1), g2(1))
	println(f3(1), g3(1))
}

func fa(a int) func(i int) int {
	return func(i int) int {
		println(&a, a)
		a = a + i
		return a
	}
}

var b = 1

func fb() func(i int) int {
	return func(i int) int {
		println(&b, b)
		b = b + i
		return b
	}
}

func fc(base int) (func(int) int, func(int) int) {
	println(&base, base)
	add := func(i int) int {
		base += i
		println(&base, base)
		return base
	}
	sub := func(i int) int {
		base -= i
		println(&base, base)
		return base
	}
	return add, sub
}
