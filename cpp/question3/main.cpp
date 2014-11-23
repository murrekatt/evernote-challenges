#include "Product.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

namespace
{

struct ProductVisitor
{
    void visit(uint64_t value) const
    {
        std::cout << value << '\n';
    }
};

} // namespace

int main()
{
    evernote::Product product;

    // read numbers from stdin
    std::string line;
    while (std::getline(std::cin, line)) {
        uint64_t number = std::atoll(&line[0]);
        product.add(number);
    }

    ProductVisitor v;
    product.calculate(v);

    return 1;
}
