#include "TestHarness.hpp"
#include "CircularBuffer.hpp"

using namespace evernote;

struct CircularBufferFixture
{
    CircularBufferFixture() : buffer_(5) {}
    CircularBuffer<std::string> buffer_;
};

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
