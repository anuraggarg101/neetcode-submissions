class Solution {
private:    
    vector<string> getNeighbours(string &word, unordered_set<string> &words) {
        vector<string> res{};

        for(int i=0;i<word.length(); i++) {
            char orig = word[i];
            for(char c='a'; c<='z';c++) {
                if(c == orig ) continue;
                word[i] = c;
                if(words.count(word) > 0) {
                    res.push_back(word);
                }
            }
            word[i] = orig;
        }
        return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.count(endWord)==0) return 0;

        queue<string> q{};
        q.push(beginWord);
        
        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 1;
        while(!q.empty()) {

            int n = q.size();
            while(n--) {
                auto word = q.front();
                q.pop();
                if(word == endWord) {
                    return level;
                }

                vector<string> neighbors = getNeighbours(word, words);
                for(auto &next:neighbors) {
                    if(words.erase(next))
                        q.push(next);
                }        
            }
            level++;
        }
        return 0;
    }
};
