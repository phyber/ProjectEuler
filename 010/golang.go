package main

import (
	"fmt"
)

func generatePrimes(n uint64) []uint64 {
	// Create an array of bools to represent primes
	var p = make([]bool, n)

	// Initialize array to true.
	var i, j uint64
	for i = 0; i < n; i++ {
		p[i] = true
	}

	// Walk array and mark numbers that are not prime.
	// That is numbers that are multiples of numbers earlier in the array
	for i = 2; i < n; i++ {
		if p[i] {
			for j = 2 * i; j < n; j += i {
				p[j] = false
			}
		}
	}

	// Walk the array, picking out primes.
	//primes := make([]uint64)
	primes := []uint64{}
	for i = 0; i < n; i++ {
		if p[i] {
			primes = append(primes, i)
		}
	}

	return primes
}

func main() {
	var maxPrimes uint64 = 2000000
	var total uint64
	primes := generatePrimes(maxPrimes)

	// Sum the numbers that were marked as prime.
	for i := 2; i < len(primes); i++ {
		total += primes[i]
	}

	fmt.Printf("Sum of primes < 2,000,000 = %d\n", total)
}
