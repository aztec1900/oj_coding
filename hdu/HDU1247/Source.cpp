#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

struct TrieNode {
	char c;
	TrieNode* next[26];
	bool leaf, hat;
	TrieNode(int chr) : c(chr) {
		memset(next, 0, sizeof(next));
		leaf = false;
		hat = false;
	}
};

void insert(TrieNode* root, char* word) {
	while (*word) {
		if (!root->next[*word - 'a'])
			root->next[*word - 'a'] = new TrieNode(*word);
		root = root->next[*word - 'a'];
		word++;
	}
	root->leaf = true;
}

bool search(TrieNode* root, char* word) {
	while (*word) {
		if (root->next[*word - 'a']) {
			root = root->next[*word - 'a'];
			word++;
		}
		return root->leaf;
	}
}

void dfs(TrieNode* root) {
	stack<TrieNode*> s;
	s.push(root);
	TrieNode* node;
	while (!s.empty()) {
		node = s.top();
		s.pop();
		if (node->leaf)
			dfs2(node, root);
		for (int i = 25; i >= 0; --i) {
			if (node->next[i]) {
				s.push(node->next[i]);
			}
		}
	}
}

void dfs2(TrieNode* node1, TrieNode* node2) {
	if (node1->leaf && node2->leaf)
		node1->hat = true;
	for (int i = 0; i < 26; ++i) {
		if (node1->next[i] && node2->next[i])
			dfs2(node1->next[i], node2->next[i]);
	}
}

char word[255];

int main() {
	TrieNode *root = new TrieNode('#');
	while (scanf("%s", word) != EOF) {
		insert(root, word);
	}

}