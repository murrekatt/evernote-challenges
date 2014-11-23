#include "Product.hpp"
#include "TestHarness.hpp"
#include <vector>

namespace
{

struct ProductFixture
{
    evernote::Product p_;
};

struct TestVisitor : public std::vector<uint64_t>
{
    void visit(uint64_t value)
    {
        push_back(value);
    }
};

} // namespace

TEST_F(ProductFixture, challenge_input_gives_correct_output)
{
    p_.add(1);
    p_.add(2);
    p_.add(3);
    p_.add(4);
    TestVisitor v;
    p_.calculate(v);
    ASSERT_EQ(4, v.size());
    ASSERT_EQ(24, v[0]);
    ASSERT_EQ(12, v[1]);
    ASSERT_EQ(8, v[2]);
    ASSERT_EQ(6, v[3]);
}

CPPUT_TEST_MAIN;
