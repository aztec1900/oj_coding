#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> ret;
	int n = words.size();
	if (n == 0) 
		return{ string(maxWidth, ' ') };
	int len = 0;
	int lineStart, lineEnd;
	for (int i = 0; i<n; ++i) {
		if (len == 0) {
			len += words[i].length();
			lineStart = i;
		}
		else
			len += words[i].length() + 1;
		if (i == n - 1) {
			string line;
			line.append(words[lineStart]);
			for (int j = lineStart + 1; j <= n - 1; ++j) {
				line.append(" " + words[j]);
			}
			line.append(string(maxWidth - len, ' '));
			ret.push_back(line);
		}
		else if (len + words[i + 1].size() + 1 > maxWidth) {
			lineEnd = i;
			int nWords = lineEnd - lineStart + 1;
			int space, spaceRemain;
			int nTotalSpace = maxWidth - len + nWords - 1;
			if (nWords != 1) {
				space = nTotalSpace / (nWords - 1);
				spaceRemain = nTotalSpace % (nWords - 1);
			}
			else {
				space = nTotalSpace;
				spaceRemain = 0;
			}

			string line;
			for (int j = lineStart; j <= lineEnd; ++j) {
				line.append(words[j]);
				if (j != lineEnd) {
					if (spaceRemain > 0) {
						spaceRemain--;
						line.append(string(space + 1, ' '));
					}
					else
						line.append(string(space, ' '));
				}
				else if (nWords == 1)
					line.append(string(nTotalSpace, ' '));
			}
			len = 0;
			ret.push_back(line);
		}
		
	}
	return ret;
}

int main() {
	//vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> words = { "Imagination", "is", "more", "important", "than", "knowledge." };
	auto ret = fullJustify(words, 18);
	return 0;
}