#include "CircularBuffer.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace evernote;

int main()
{
    std::string line;

    // find out capacity and create buffer
    std::getline(std::cin, line);
    size_t capacity = std::atoi(&line[0]);

    CircularBuffer<std::string> buffer(capacity);

    // read commands from stdin
    while (std::getline(std::cin, line)) {
        if (line.empty())
            return 1;

        // what is the command?
        switch (line[0]) {
            case 'A': // add n subsequent lines
                capacity = std::atoi(&line[2]);
                while (capacity--) {
                    if (!std::getline(std::cin, line))
                        return 100;
                    buffer.append(line);
                }
                break;
            case 'R': // remove n lines
                capacity = std::atoi(&line[2]);
                while (capacity--) buffer.remove();
                break;
            case 'L': // list buffer content
                buffer.list();
                break;
            case 'Q': // quit
                return 0;
            default: // error
                return 2;
        }
    }

    return 3; // unexpected EOF
}
