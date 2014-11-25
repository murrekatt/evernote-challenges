// Evernote Coding Challenge - Question 2

package main

import(
	"fmt"
	"io"
	"os"
	"bufio"
)

func read_number() int {
	var number int
	_, err := fmt.Fscan(os.Stdin, &number)
	if err == io.EOF {
		os.Exit(1)
	}
	return number
}

func main() {
	count := read_number()
	freq := CreateFrequency()

	// read terms from stdin line by line
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	for count > 0 {
		scanner.Scan()
		line := scanner.Text()
		freq.Add(line)
		count--
	}

	// display top k terms in decending order
	k := read_number()
	freq.Top(k)

	os.Exit(0)
}
