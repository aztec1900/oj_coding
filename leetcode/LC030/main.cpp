#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


/* The first solution: TLE
void findSubstring(string& s, int ind, unordered_map<string, int> dict, int nWord, int wordLen, vector<int>& ret) {
	if (s.length() - ind < nWord * wordLen)
		return;
	//vector<int> check(nWord, 0);
	int start = ind;
	for (int i = 0; i<nWord; ++i) {
		string word = s.substr(ind, wordLen);
		ind += wordLen;
		auto it = dict.find(word);
		if (it != dict.end()) {
			if (dict[word] == 0)
				return;
			else
				dict[word]--;
		}
		else
			return;
	}
	ret.push_back(start);
}
vector<int> findSubstring(string s, vector<string>& words) {
	int nWord = words.size();
	if (nWord == 0)
		return{};
	int wordLen = words[0].length();
	vector<int> ret;
	unordered_map<string, int> dict;
	for (int i = 0; i<nWord; ++i) {
		if (dict.find(words[i]) == dict.end())
			dict[words[i]] = 1;
		else
			dict[words[i]]++;
	}
	for (int i = 0; i<s.length(); ++i)
		findSubstring(s, i, dict, nWord, wordLen, ret);
	return ret;
}*/



int main() {
	string s("wordgoodgoodgoodbestword");
	vector<string> words = { "word", "good", "best", "good" };
	auto ret = findSubstring(s, words);
	return 0;
}