class Solution {
public:
    int countCompleteSubstrings(string word, int k) {

        int n = word.size();
        int ans = 0;

        int start = 0;

        while (start < n) {

            int end = start;

            while (end + 1 < n &&
                   abs(word[end] - word[end + 1]) <= 2) {
                end++;
            }

            for (int unique = 1; unique <= 26; unique++) {

                int len = unique * k;

                if (len > end - start + 1)
                    break;

                int freq[26] = {0};

                for (int i = start; i < start + len; i++) {
                    freq[word[i] - 'a']++;
                }

                int valid = 0;

                for (int i = start; i + len - 1 <= end; i++) {

                    bool complete = true;

                    for (int j = 0; j < 26; j++) {

                        if (freq[j] != 0 && freq[j] != k) {
                            complete = false;
                            break;
                        }
                    }

                    if (complete)
                        ans++;

                    if (i + len <= end) {

                        freq[word[i] - 'a']--;

                        freq[word[i + len] - 'a']++;
                    }
                }
            }

            start = end + 1;
        }

        return ans;
    }
};