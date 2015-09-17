

#include "LRUCache.h"

int main()
{
    LRUCache cache(3);

    cache.set(3,2);
    cache.set(3,1);
    cache.get(2);


    return 0;
}
