#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum status {END_UNMATCH, MATCH, UNMATCH};

status isMatch(string& s, int indS, string& p, int indP) {
	int m = s.length();
	int n = p.length();
	if (indS == m && indP == n)
		return MATCH;
	else if (indS == m && p[indP] != '*')
		return END_UNMATCH;
	if (p[indP] == '*') {
		while (indP != n - 1 && p[indP + 1] == '*')
			indP++;
		if (indP == n - 1)
			return MATCH;
		for (int i = indS; i <= m; ++i) {
			status sts = isMatch(s, i, p, indP + 1);
			if (sts == END_UNMATCH || sts == MATCH) // 剪枝：当一种匹配模式达到s的末尾还没有匹配的话，就不可能匹配了
				return sts;
		}
		return UNMATCH;
	}
	else if (p[indP] == '?' || p[indP] == s[indS])
		return isMatch(s, indS + 1, p, indP + 1);
	else
		return UNMATCH;
}
bool isMatch(string s, string p) {
	return isMatch(s, 0, p, 0) == MATCH;
}

int main() {	
	string s("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb");
	string p("**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	cout << isMatch(s, p);
	return 0;
}