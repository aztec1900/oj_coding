#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//#define DEBUG

using namespace std;

struct TrieNode{
	char c;
	vector<TrieNode*> next;
	int freq;
	bool isWord;
	TrieNode(char chr) : c(chr), next({}), freq(1), isWord(false) {}
};

int main() {

#ifdef DEBUG
	ifstream fin;
	fin.open("data_in.txt");
	cin.rdbuf(fin.rdbuf());
#endif
	int nDict;
	cin >> nDict;
	TrieNode* root = new TrieNode(0);
	for (int i = 0; i < nDict; ++i) {
		string word;
		cin >> word;
		TrieNode* node = root;
		for (char chr : word) {
			int iNode;
			for (iNode = 0; iNode < node->next.size(); ++iNode) {
				if (node->next[iNode]->c == chr)
					break;
			}
			if (iNode == node->next.size()) {
				TrieNode* newNode = new TrieNode(chr);
				node->next.push_back(newNode);
			}
			else {
				node->next[iNode]->freq++;
			}
			node = node->next[iNode];
		}
		node->isWord = true;
	}
	int nWord;
	cin >> nWord;
	for (int i = 0; i < nWord; ++i) {
		string word;
		cin >> word;
		TrieNode* node = root;
		bool found = true;
		for (char chr : word) {
			int iNode;
			for (iNode = 0; iNode < node->next.size(); ++iNode) {
				if (node->next[iNode]->c == chr)
					break;
			}
			if (iNode == node->next.size()) {
				found = false;
				break;
			}
			else {
				node = node->next[iNode];
			}
		}
		if (found)
			cout << node->freq << endl;
		else
			cout << 0 << endl;
	}
#ifdef DEBUG
	system("pause");
#endif
	return 0;
}