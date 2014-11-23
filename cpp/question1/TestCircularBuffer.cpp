#include "CircularBuffer.hpp"
#include "TestHarness.hpp"
#include <string>
#include <vector>

namespace
{

struct CircularBufferFixture
{
    CircularBufferFixture() : buffer_(5) {}
    evernote::CircularBuffer<std::string> buffer_;
};

struct TestVisitor : public std::vector<std::string>
{
    void list(const std::string& s)
    {
        push_back(s);
    }
};

} // namespace

TEST(CircularBuffer, challenge_input_gives_correct_output)
{
    evernote::CircularBuffer<std::string> buffer(10);
    buffer.append("Fee");
    buffer.append("Fi");
    buffer.append("Fo");
    buffer.append("Fum");
    buffer.remove();
    buffer.remove();
    TestVisitor v;
    buffer.list(v);
    ASSERT_EQ(2, v.size());
    ASSERT_STREQ("Fo", v[0]);
    ASSERT_STREQ("Fum", v[1]);
}

TEST_F(CircularBufferFixture, append_more_than_max_elements_gives_size_max)
{
    buffer_.append("foo1");
    buffer_.append("foo2");
    buffer_.append("foo3");
    buffer_.append("foo4");
    buffer_.append("foo5");
    buffer_.append("foo6");
    ASSERT_EQ(5, buffer_.size());
    ASSERT_FALSE(buffer_.empty());
}

TEST_F(CircularBufferFixture, append_max_elements_gives_size_max)
{
    buffer_.append("foo1");
    buffer_.append("foo2");
    buffer_.append("foo3");
    buffer_.append("foo4");
    buffer_.append("foo5");
    ASSERT_EQ(5, buffer_.size());
    ASSERT_FALSE(buffer_.empty());
}

TEST_F(CircularBufferFixture, appended_and_remove_element_keeps_size_zero)
{
    buffer_.append("foo");
    buffer_.remove();
    ASSERT_EQ(0, buffer_.size());
    ASSERT_TRUE(buffer_.empty());
}

TEST_F(CircularBufferFixture, appended_element_increases_size)
{
    buffer_.append("foo");
    ASSERT_EQ(1, buffer_.size());
    ASSERT_FALSE(buffer_.empty());
}

TEST_F(CircularBufferFixture, newley_constructed_buffer_has_size_zero)
{
    ASSERT_EQ(0, buffer_.size());
    ASSERT_TRUE(buffer_.empty());
}

CPPUT_TEST_MAIN;
