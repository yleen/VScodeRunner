package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var len_str, count_word, line_pge int

func main() {
	len_str, count_word, line_pge = 0, 0, 0
	inputReader := bufio.NewReader(os.Stdin)
	fmt.Println("please enter your input:")
	for {
		input, err := inputReader.ReadString('\n')

		if err != nil {
			fmt.Println("There were errors reading, exiting program.")
			return
		}
		if input == "S\r\n" {

			fmt.Printf("The string length is %d,word is %d,line is %d", len_str, count_word, line_pge)
			os.Exit(0)
		}
		Counters(input)

	}

}

func Counters(input string) {
	len_str += len(input) - 2
	count_word += len(strings.Fields(input))
	line_pge++
}
