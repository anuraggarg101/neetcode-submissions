class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict{};
        for(auto &word:wordList) {
            dict.insert(word);
        }
        
        if(dict.find(endWord) == dict.end()) return 0;
        if(beginWord == endWord) return 1;

        /*
        int n = dict.size();

        unordered_map<string, vector<string>> graph{};
        for(auto &word:dict) {
            int len = word.length();
            for(int i=0;i<len;i++) {
                char c = word[i];
                for(int j=0;j<26;j++) {
                    char new_c = 'a' + j;
                    if(new_c != c) {
                        string temp_word = word;
                        temp_word[i] = new_c;
                        if(dict.find(temp_word)!=dict.end()) {
                            graph[word].push_back(temp_word);
                        }
                    }
                }
            }
        }
        */
        
        queue<pair<string, int>> q{};
        q.push({beginWord, 1});
        
        if(dict.count(beginWord) > 0)
            dict.erase(beginWord);

        while(!q.empty()) {
            string curr_word = q.front().first;
            int curr_steps = q.front().second;
            q.pop();
            if(curr_word == endWord) {
                return curr_steps;
            }

            for(int i=0; i<curr_word.length(); i++) {
                char original = curr_word[i];
                for(char c='a'; c<= 'z'; c++) {
                    if(c == original) continue;
                    curr_word[i] = c;
                    if(dict.find(curr_word) != dict.end()) {
                        q.push({curr_word, curr_steps + 1});
                        dict.erase(curr_word);
                    }
                }
                curr_word[i] = original;
            }
            /*
            for(auto &word:graph[curr_word]) {
                if(dict.find(word) != dict.end()) {
                    q.push({word, curr_steps + 1});
                }
            }
            dict.erase(curr_word);
            */
        }
        return 0;

    }
};
