#include <string>
#include <vector>
#include <iostream>

/********************************************************************\
- store and retrieve data based on prefix-searching

Complexity of inserting and searching
- Time Complexity: O(number of words * maxLengthOfWord)
- Auxiliary Space: O(number of words * maxLengthOfWord)

\********************************************************************/

class TrieNode {
private:
    bool wordEnd;
    std::vector<TrieNode*> children;
public:
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            children.push_back(nullptr);
        }
    }
    void insert(TrieNode *root, std::string key) {
        TrieNode *current = root;
        for (size_t i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->wordEnd = true;
    }
    void getAllWords(TrieNode *node, std::string prefix, std::vector<std::string> &suggestions) {
        if (node->wordEnd)
            suggestions.push_back(prefix);
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char c = 'a' + i;
                getAllWords(node->children[i], prefix + c, suggestions);
            }
        }
    }
    bool search(TrieNode *root, std::string key) {
        TrieNode *current = root;
        for (char c : key) {
            int index = c - 'a';
            if (!current->children[index])
                return false;
            current = current->children[index];
        }
        return current->wordEnd;
    }

    std::vector<std::string> getSuggestions(TrieNode *root, std::string partialWord) {
        std::vector<std::string> suggestions;
        TrieNode *current = root;
        for (char c : partialWord) {
            int index = c - 'a';
            if (!current->children[index])
                return suggestions;
            current = current->children[index];
        }
        current->getAllWords(current, partialWord, suggestions);
        return suggestions;
    }
};


int main() {
    TrieNode *root = new TrieNode();
    root->insert(root, "mira");
    root->insert(root, "mirror");
    root->insert(root, "mic");
    root->insert(root, "minh");
    root->insert(root, "michael");
    root->insert(root, "mike");
    root->insert(root, "laluot");
    root->insert(root, "lalala");
    root->insert(root, "app");
    root->insert(root, "apple");

    std::vector<std::string> autoComplete;
    root->getAllWords(root, "", autoComplete);
    for (std::string s : autoComplete) std::cout << s << " ";
    std::cout << std::endl;

    autoComplete = root->getSuggestions(root, "mir");
    for (std::string s : autoComplete) std::cout << s << " ";
    std::cout << std::endl;

    std::cout << root->search(root, "lalala") << std::endl;

    return 0;
}

