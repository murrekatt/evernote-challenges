// Evernote Coding Challenge - Question 3

package main

import(
	"fmt"
	"io"
	"os"
)

func main() {
	product := 1
	// dynamic array
	numbers := make([]int, 0)
	var number int

	for {
		// read numbers from stdin line by line until EOF
		_, err := fmt.Fscan(os.Stdin, &number)
		if err == io.EOF {
			break
		}
		// total a prduct for all
		product = product * number
		// store numbers in dynamic array
		numbers = append(numbers, number)
	}
	// iterate numbers and print product divided by current number
	for _, value := range numbers {
		fmt.Printf("%d\n", product / value)
	}
}
