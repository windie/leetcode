#include "common.h"
#include "lru_cache.h"
#include <gtest/gtest.h>

TEST(A, B){
	LRUCache lruCache(2);
	lruCache.get(2);
	lruCache.set(2,6);
	lruCache.get(1);
	lruCache.set(1,5);
	lruCache.set(1,2);
	lruCache.get(1);
	lruCache.get(2);
}
