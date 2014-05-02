package main

import (
	"fmt"
)

func main() {
	total := 0
	for num := 0; num < 1000; num++ {
		if num%3 == 0 || num%5 == 0 {
			total += num
			continue
		}
	}
	fmt.Printf("Total: %d\n", total)
}
