#ifndef EVERNOTE_CIRCULARBUFFER_HPP
#define EVERNOTE_CIRCULARBUFFER_HPP

#include <vector>

namespace evernote
{

template <typename T>
class CircularBuffer
{
public:
    explicit CircularBuffer(size_t capacity)
        : buffer_(capacity)
        , capacity_(capacity)
        , head_(0)
        , tail_(0)
        , lastWasAppend_(false)
    {
    }

    void append(const T& t)
    {
        buffer_[head_] = t;
        if (head_ == tail_ && lastWasAppend_) {
            tail_ = (tail_ + 1) % capacity_;
            head_ = tail_;
        }
        else
            head_ = (head_ + 1) % capacity_;
        lastWasAppend_ = true;
    }

    void remove()
    {
        tail_ = (tail_ + 1) % capacity_;
        lastWasAppend_ = false;
    }

    template <typename V>
    void list(V& v) const
    {
        if (empty())
            return;

        int pos = tail_;
        do {
            v.list(buffer_[pos]);
            pos = (pos + 1) % capacity_;
        } while (pos != head_);
    }

    size_t size() const
    {
        // if head and tail same, buffer can be either full or empty
        if (head_ == tail_) {
            if (lastWasAppend_)
                return capacity_;
            else
                return 0;
        }
        if (head_ > tail_)
            return head_ - tail_;
        return capacity_ - tail_ + head_;
    }

    bool empty() const
    {
        return head_ == tail_ && !lastWasAppend_;
    }

private:
    std::vector<T> buffer_;
    size_t capacity_;
    size_t head_;
    size_t tail_;
    bool lastWasAppend_;
};

} // namespace evernote

#endif // EVERNOTE_CIRCULARBUFFER_HPP
