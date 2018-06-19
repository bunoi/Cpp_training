#include "LRACache.h"

using namespace std;

// template<typename Key, typename T, int N>
// void LRACache<Key, T, N>::add(Key k, T v)
// {
//     typename map<Key, T> :: iterator it = M.find(k);
//     if ( it == M.end() )
//     {
//         if ( M.size() < N)
//             M[k] = v; 
//     }
//     else
//     {
//         it->second = v;
//     }
// }

// template<typename Key, typename T, int N>
// T LRACache<Key, T, N>::get(Key k)
// {
//     typename map<Key, T> :: iterator it = M.find(k);
//     if ( it == M.end() )
//     {
//         throw "This key not found in cache!";
//     }
//     else
//     {
//         return it->second;
//     }
// }