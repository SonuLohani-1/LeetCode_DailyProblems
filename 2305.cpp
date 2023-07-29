#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<Trie*> links{26, NULL};
    bool isEnd = false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* ptr = links[0];
        for(auto ch : word)
        {
            if (ptr->links[ch - 'a'] == NULL) {
                ptr->links[ch - 'a'] = new Trie();
            }
            ptr = ptr->links[ch - 'a'];
        }
        ptr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* ptr = links[0];
        for(auto ch : word)
        {
            ptr = ptr->links[ch - 'a'];
            if(ptr == NULL)
                return false;
        }
        return ptr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* ptr = links[0];
        for(auto ch : prefix)
        {
            ptr = ptr->links[ch - 'a'];
            if(ptr == NULL)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
