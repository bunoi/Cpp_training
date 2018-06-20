#include <map>

template<typename Key, typename T, int N>
class LRACache
{
public:
    LRACache() {}
    ~LRACache() {}

    void add(Key k, T v)
    {
        typename std::map<Key, T> :: iterator it = M.find(k);
        if ( it == M.end() )
        {
            if ( M.size() < N)
                M[k] = v; 
        }
        else
        {
            it->second = v;
        }
    }
    T get(Key k)
    {
        typename std::map<Key, T> :: iterator it = M.find(k);
        if ( it == M.end() )
        {
            throw "This key not found in cache!";
        }
        else
        {
            return it->second;
        }
    }

protected:
    std::map<Key, T> M;
};
