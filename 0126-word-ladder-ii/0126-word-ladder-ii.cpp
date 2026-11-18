
class Solution {
    void dfs(string beginWord, string currentWord,
             unordered_map<string, int>& word_level,
             vector<string>& temp,
             vector<vector<string>>& ans) {

        // Add current word to path
        temp.push_back(currentWord);

        // Base case
        if (currentWord == beginWord) {
            vector<string> path = temp;
            reverse(path.begin(), path.end());

            ans.push_back(path);

            temp.pop_back();
            return;
        }

        int currentLevel = word_level[currentWord];

        // Explore all possible transformations
        for (int i = 0; i < currentWord.size(); i++) {
            char original = currentWord[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                currentWord[i] = ch;

                if (word_level.find(currentWord) != word_level.end() &&
                    word_level[currentWord] == currentLevel - 1) {

                    dfs(beginWord, currentWord, word_level, temp, ans);
                }
            }

            currentWord[i] = original;
        }

        // Backtrack
        temp.pop_back();
    }

public:
    vector<vector<string>> findLadders(
        string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> remaining(wordList.begin(), wordList.end());

        // End word must exist in wordList
        if (remaining.find(endWord) == remaining.end())
            return {};

        // BFS to calculate shortest distances
        queue<pair<string, int>> q;

        q.push({beginWord, 0});
        remaining.erase(beginWord);

        unordered_map<string, int> level;

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            level[word] = steps;

            // Generate all possible transformations
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (remaining.find(word) != remaining.end()) {
                        q.push({word, steps + 1});
                        remaining.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        // Check whether endWord is reachable
        if (level.find(endWord) == level.end())
            return {};

        // DFS to generate all shortest paths
        vector<vector<string>> ans;
        vector<string> temp;

        dfs(beginWord, endWord, level, temp, ans);

        return ans;
    }
};
