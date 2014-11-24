#include "Frequency.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

namespace
{

struct Visitor
{
    void visit(const std::string& s) const
    {
        std::cout << s << '\n';
    }
};

} // namespace

int main()
{
    std::string line;

    // find out number of terms
    std::getline(std::cin, line);
    size_t N = std::atoi(&line[0]);

    evernote::Frequency<std::string> freq(N);

    // read terms from stdin
    while (N--) {
        if (!std::getline(std::cin, line))
            return 1;

        freq.add(line);
    }

    // show top k terms
    if (!std::getline(std::cin, line))
        return 2;

    size_t k = std::atoi(&line[0]);
    Visitor v;
    freq.top(v, k);

    return 0;
}
