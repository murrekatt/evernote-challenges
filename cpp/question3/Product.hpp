#ifndef EVERNOTE_PRODUCT_HPP
#define EVERNOTE_PRODUCT_HPP

#include <vector>
#include <cstdlib>

namespace evernote
{

class Product
{
public:
    Product()
        : total_(1)
        , numbers_()
    {
        // never more than 1000 numbers
        numbers_.reserve(1000);
    }

    void add(uint64_t number)
    {
        total_ *= number;
        numbers_.push_back(number);
    }

    template <typename V>
    void calculate(V& v)
    {
        for (size_t i = 0; i < numbers_.size(); ++i) {
            v.visit(total_ / numbers_[i]);
        }
    }

private:
    uint64_t total_;
    std::vector<uint64_t> numbers_;
};

} // namespace evernote

#endif // EVERNOTE_PRODUCT_HPP
