#include <unordered_map>
#include <algorithm>
#include <vector>

namespace evernote
{

template <typename T>
class Frequency
{
public:
    explicit Frequency(size_t capacity)
        : terms_(capacity)
    {
    }

    void add(const T& t)
    {
        auto it = terms_.find(t);
        if (it == terms_.end())
            terms_[t] = 1;
        else
            it->second += 1;
    }

    template <typename V>
    void top(V& v, size_t k) const
    {
        // copy pairs into vector
        std::vector<std::pair<T, int>> terms;
        std::copy(terms_.begin(), terms_.end(), std::back_inserter<std::vector<std::pair<T, int>>>(terms));
        // sort decending values
        std::sort(terms.begin(), terms.end(),
            [=](std::pair<T, int>& a, std::pair<T, int>& b) {
                return a.second > b.second;
            }
        );
        // visit top k terms in decending order
        for (auto it = terms.begin(); k-- && it != terms.end(); ++it)
            v.visit(it->first);
    }

private:
    std::unordered_map<T, int> terms_;
};

} // namespace evernote
