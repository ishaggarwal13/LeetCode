struct TrieNode {
	int next[10];
	TrieNode() {
		fill(next, next + 10, -1);
	}
};
TrieNode trie[65'000]; int trieSize;
void insert(const string& s) {
	int v = 0;
	for(char c : s) {
		if(trie[v].next[c-'0'] == -1) {
			trie[v].next[c-'0'] = trieSize;
			fill(trie[trieSize].next, trie[trieSize].next + 26, -1);
            trieSize++;
		}
		v = trie[v].next[c-'0'];
	}
}

int go(const string& s) {
	int v = 0; int len = 0;
	for(char c : s) {
		if(trie[v].next[c-'0'] == -1) {
			return len;
		}
		v = trie[v].next[c-'0'];
        len++;
	}
	return len;
}
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieSize = 1;
        fill(trie[0].next, trie[0].next + 26, -1);
        for(int n : arr1) {
            insert(to_string(n));
        }
        int ans = 0;
        for(int n : arr2) {
            ans = max(ans, go(to_string(n)));
        }
        return ans;
    }
};