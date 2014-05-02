package main

import (
	"fmt"
)

const (
	min = 100
	max = 999
)

func isPalindrome(n int) bool {
	str := fmt.Sprintf("%d", n)

	i := 0
	j := len(str)-1
	for i < j {
		if str[i] != str[j] {
			return false
		}
		i++
		j--
	}

	return true
}

func main() {
	largest := 0

	for i := min; i < max; i++ {
		for j := min; j < max; j++ {
			prod := i * j
			if isPalindrome(prod) {
				if prod > largest {
					largest = prod
				}
			}
		}
	}

	fmt.Printf("Largest Palindrome: %d\n", largest)
}
