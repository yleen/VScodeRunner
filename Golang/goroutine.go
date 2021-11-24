package main

import (
	"runtime"
	"time"
)

func main() {
	chanMethod()
	println("NumGoroutine=", runtime.NumGoroutine())
	println("GOMAXPROCS=", runtime.GOMAXPROCS(0))

	println("GOMAXPROCS=", runtime.GOMAXPROCS(2))

	println("GOMAXPROCS=", runtime.GOMAXPROCS(0))
	time.Sleep(5 * time.Second)
	go sum()

	println("NumGoroutine2=", runtime.NumGoroutine())
	time.Sleep(5 * time.Second)

}

func sum() {

	sum := 0
	for i := 0; i < 10000; i++ {
		sum += i
	}

	println(sum)
	time.Sleep(1 * time.Second)
}

func chanMethod() {
	c := make(chan struct{})
	go func(i chan struct{}) {
		sum := 0
		for i := 0; i < 10000; i++ {
			sum += i
		}
		println(sum)
		c <- struct{}{}
	}(c)
	println("NumGoroutine=", runtime.NumGoroutine())

	<-c
}
