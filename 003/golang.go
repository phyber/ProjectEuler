package main

import (
	"fmt"
	"math"
)

const (
	number = 600851475143
)

func isPrime(n uint64) bool {
	if n%2 == 0 {
		return false
	}

	var sqr uint64 = uint64(math.Sqrt(float64(n)))
	var i uint64 = 2
	var skip bool = false

	for i < sqr {
		if n%i == 0 {
			return false
		}

		// Skip even numbers past % 2
		if i >= 5 {
			if !skip {
				i += 2
			} else {
				i += 4
			}
			skip = !skip
		} else {
			i++
		}
	}

	return true
}

func main() {
	var largestPrimeFactor uint64

	max := uint64(math.Sqrt(number))

	for i := uint64(1); i < max; i++ {
		if isPrime(i) {
			if number % i == 0 {
				largestPrimeFactor = i
			}
		}
	}

	fmt.Printf("Largest Prime Factor: %d\n", largestPrimeFactor)
}
