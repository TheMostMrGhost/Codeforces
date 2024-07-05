#include <cstdlib>
#include <unordered_set>
class RandomizedSet {
    std::unordered_set<int> set;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (set.find(val) != set.end()) {
            return false;
        }
        set.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (set.find(val) == set.end()) {
            return false;
        }
        set.erase(val);
        return true;
    }
    
    int getRandom() {
        int random = rand() % set.size();
        auto it = set.begin();
        std::advance(it, random);
        return *it;
    }
};

int main (int argc, char *argv[]) {
    RandomizedSet* obj = new RandomizedSet();
    int val = 1;
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
    return 0;
}
