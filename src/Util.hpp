#include <vector>
#include <algorithm>

namespace util
{
    template<typename T>
    void remove(std::vector<T> &vec,const T &item)
    {
        vec.erase(std::remove(vec.begin(),vec.end(),item),vec.end() );
    }
}