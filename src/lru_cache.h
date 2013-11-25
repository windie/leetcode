class LRUCache {
	int capacity;
	unordered_map<int, int> table;
	list<int> cachelist;
	unordered_map<int, list<int>::iterator> cachemap;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		auto it = table.find(key);
		if (it != table.end()) {
			auto itmap = cachemap.find(key);
			cachelist.erase(itmap->second);
			cachelist.push_back(key);
			itmap->second = --cachelist.end();
			return it->second;
		} else {
			return -1;
		}
	}

	void set(int key, int value) {
		if (table.find(key) != table.end()) {
			cachelist.erase(cachemap.find(key)->second);
		} else if (table.size() == capacity) {
			auto itlist = cachelist.begin();
			cachemap.erase(*itlist);
			table.erase(*itlist);
			cachelist.erase(itlist);
		}
		table[key] = value;
		cachelist.push_back(key);
		cachemap[key] = --cachelist.end();
	}
};
