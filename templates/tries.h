#include <unordered_map>
#include <memory>
#include <vector>

template<typename Key, typename Value>
class Trie {
private:
    struct TrieNode {
        std::unordered_map<Key, std::shared_ptr<TrieNode>> children;
        bool is_end_of_word = false;
        Value value;
    };

    std::shared_ptr<TrieNode> root;

public:
    Trie() : root(std::make_shared<TrieNode>()) {}

    void insert(const std::vector<Key>& key, const Value& value) {
        auto current = root;
        for (const Key& k : key) {
            if (current->children.find(k) == current->children.end()) {
                current->children[k] = std::make_shared<TrieNode>();
            }
            current = current->children[k];
        }
        current->is_end_of_word = true;
        current->value = value;
    }

    bool search(const std::vector<Key>& key, Value& value) const {
        auto current = root;
        for (const Key& k : key) {
            if (current->children.find(k) == current->children.end()) {
                return false;
            }
            current = current->children[k];
        }
        if (!current->is_end_of_word) {
            return false;
        }
        value = current->value;
        return true;
    }

    bool remove(const std::vector<Key>& key) {
        return removeHelper(root, key, 0);
    }

private:
    bool removeHelper(std::shared_ptr<TrieNode>& current, const std::vector<Key>& key, size_t depth) {
        if (depth == key.size()) {
            if (!current->is_end_of_word) {
                return false;
            }
            current->is_end_of_word = false;
            return current->children.empty();
        }

        const Key& k = key[depth];
        auto it = current->children.find(k);
        if (it == current->children.end() || removeHelper(it->second, key, depth + 1)) {
            current->children.erase(k);
            return !current->is_end_of_word && current->children.empty();
        }
        return false;
    }
};


