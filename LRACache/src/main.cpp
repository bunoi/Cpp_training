#include "LRACache.h"
#include <iostream>

using namespace std;

int main()
{
    
    LRACache<int, string, 2> my_cache; // map from int to string holding at most 2 pairs 
                                    // remove oldest (least recenly added) key-value 
                                    // pair if the size will exceed 2.
    my_cache.add(1, "a");
    my_cache.add(2, "b");
    my_cache.add(3, "c"); 
    try
    {
        cout << my_cache.get(1) << endl;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
    }
    try
    {
        cout << my_cache.get(2) << endl;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
    }
    try
    {
        cout << my_cache.get(3) << endl;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
    }
}