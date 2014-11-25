// Evernote Coding Challenge - Question 1

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
	size := read_number()
	buffer := CreateBuffer(size)

	for {
		// read lines from stdin until EOF
		var command string
		_, err := fmt.Fscan(os.Stdin, &command)
		if err == io.EOF {
			break
		}

		switch command[0] {
		case 'A':
			count := read_number()
			scanner := bufio.NewScanner(os.Stdin)
			scanner.Split(bufio.ScanLines)
			for count > 0 {
				scanner.Scan()
				line := scanner.Text()
				buffer.Add(line)
				count--
			}
		case 'R':
			count := read_number()
			for count > 0 {
				buffer.Remove(count)
				count--
			}
		case 'L':
			buffer.List()
		case 'Q':
			os.Exit(0)
		default:
			os.Exit(2)
		}
	}

	os.Exit(1)
}
