// This is a terrible way to generate the solution, I'm sure.
package main

import (
	"fmt"
)

func main() {
	for i := uint64(1000); i > 0; i-- {
		m := i

		for n := uint64(0); n < 1000; n++ {
			var a, b, c uint64
			a = m*m - n*n
			if a > 1000 {
				continue
			}
			b = 2 * m * n
			if b > 1000 {
				continue
			}
			c = m*m + n*n
			if c > 1000 {
				continue
			}

			x := a + b + c
			if x > 1000 {
				continue
			}

			if x == 1000 {
				fmt.Printf("%d + %d + %d = %d\n", a, b, c, x)
			}
		}
	}
}
