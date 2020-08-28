class Trie{
    Trie *children[26];
    bool endOfWord;
public:
    Trie():endOfWord(false){
        for(int i = 0; i < 26; ++i) children[i] = NULL;
    }
    
    void insert(string word){
        Trie *curr = this;
        for(char ch: word){
            if(curr->children[ch-'a'] == NULL)
                curr->children[ch-'a'] = new Trie();
            curr = curr->children[ch-'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(deque<char>& word){
        Trie *curr = this;
        for(char ch: word){
            if(curr->children[ch-'a'] == NULL) return false;
            curr = curr->children[ch-'a'];
            if(curr->endOfWord) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie trie;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        for(string& word: words){
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        return trie.search(stream);
    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */