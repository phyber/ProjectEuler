package main

import (
	"fmt"
)

func main() {
	var total uint64
	seq := []uint64{1, 1}

	var i uint64
	for i < 4000000 {
		i = seq[1] + seq[0]
		seq[0] = seq[1]
		seq[1] = i

		if i%2 == 0 {
			total += i
		}
	}
	fmt.Printf("Total: %d\n", total)
}
