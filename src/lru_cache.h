class LRUCache{
    struct Cache{
        int key;
        int val;
        Cache(int k, int v) :key(k), val(v) {}
    };
    unordered_map<int, list<Cache>::iterator> m_cache_map;
    list<Cache> m_cache_list;
    int m_capacity;

    void moveTohead(int key){
        auto it = *m_cache_map[key];
        m_cache_list.erase(m_cache_map[key]);
        m_cache_list.push_front(it);
        m_cache_map[key] = m_cache_list.begin();
    }

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto it = m_cache_map.find(key);
        if(it != m_cache_map.end()){
            moveTohead(key);
            return m_cache_map[key]->val;
        }else{
            return -1;
        }
    }

    void set(int key, int value) {
        auto it = m_cache_map.find(key);
        if(it != m_cache_map.end()){
            m_cache_map[key]->val = value;
            moveTohead(key);
        }else{
            Cache c(key, value);
            if(m_cache_map.size()>=m_capacity){
                auto ittail = m_cache_list.back();
                m_cache_map.erase(ittail.key);
                m_cache_list.pop_back();
            }
            m_cache_list.push_front(c);
            m_cache_map[key] = m_cache_list.begin();
        }
    }
};

//class LRUCache {
//	int capacity;
//	unordered_map<int, int> table;
//	list<int> cachelist;
//	unordered_map<int, list<int>::iterator> cachemap;
//public:
//	LRUCache(int capacity) {
//		this->capacity = capacity;
//	}
//
//	int get(int key) {
//		auto it = table.find(key);
//		if (it != table.end()) {
//			auto itmap = cachemap.find(key);
//			cachelist.erase(itmap->second);
//			cachelist.push_back(key);
//			itmap->second = --cachelist.end();
//			return it->second;
//		} else {
//			return -1;
//		}
//	}
//
//	void set(int key, int value) {
//		if (table.find(key) != table.end()) {
//			cachelist.erase(cachemap.find(key)->second);
//		} else if (table.size() == capacity) {
//			auto itlist = cachelist.begin();
//			cachemap.erase(*itlist);
//			table.erase(*itlist);
//			cachelist.erase(itlist);
//		}
//		table[key] = value;
//		cachelist.push_back(key);
//		cachemap[key] = --cachelist.end();
//	}
//};
