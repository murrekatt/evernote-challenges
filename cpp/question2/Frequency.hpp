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
        typedef std::pair<T, int> Term;
        typedef std::vector<Term> Terms;
        // copy pairs into vector
        Terms terms;
        std::copy(terms_.begin(), terms_.end(), std::back_inserter<Terms>(terms));
        // sort decending values
        std::sort(terms.begin(), terms.end(),
            [=](Term& a, Term& b) {
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
