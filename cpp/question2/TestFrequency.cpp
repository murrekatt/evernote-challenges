#include "Frequency.hpp"
#include "TestHarness.hpp"
#include <string>
#include <vector>

namespace
{

struct FrequencyFixture
{
    FrequencyFixture() : f_(1000) {}
    evernote::Frequency<std::string> f_;
};

struct TestVisitor : public std::vector<std::string>
{
    void visit(const std::string& s)
    {
        push_back(s);
    }
};

} // namespace

TEST_F(FrequencyFixture, challenge_input_gives_correct_output)
{
    f_.add("Fee");
    f_.add("Fi");
    f_.add("Fo");
    f_.add("Fum");
    f_.add("Fee");
    f_.add("Fo");
    f_.add("Fee");
    f_.add("Fee");
    f_.add("Fo");
    f_.add("Fi");
    f_.add("Fi");
    f_.add("Fo");
    f_.add("Fum");
    f_.add("Fee");
    TestVisitor v;
    f_.top(v, 3);
    ASSERT_EQ(3, v.size());
    ASSERT_STREQ("Fee", v[0]);
    ASSERT_STREQ("Fo", v[1]);
    ASSERT_STREQ("Fi", v[2]);
}

CPPUT_TEST_MAIN;
