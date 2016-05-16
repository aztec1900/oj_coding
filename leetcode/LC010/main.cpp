#include <iostream>
#include <string>

using namespace std;

bool isMatch(string& s, int indS, string& p, int indP) {
	if (indS == s.length() && indP == p.length())
		return true;
	else if (indP == p.length())
		return false;
	if (indP + 1 == p.length() || (indP + 1<p.length() && p[indP + 1] != '*')) {
		if (p[indP] == '.')
			return isMatch(s, indS + 1, p, indP + 1);
		else {
			if (p[indP] == s[indS])
				return isMatch(s, indS + 1, p, indP + 1);
			else
				return false;
		}
	}
	else {
		if (p[indP] == '.') {
			while (indS <= s.length()) {
				if (isMatch(s, indS, p, indP + 2))
					return true;
				indS++;
			}
			return false;
		}
		else {
			if (isMatch(s, indS, p, indP + 2))
				return true;
			while (indS < s.length() && s[indS] == p[indP]) {
				indS++;
				if (isMatch(s, indS, p, indP + 2))
					return true;
			}
			return false;
		}
	}
}
bool isMatch(string s, string p) {
	return isMatch(s, 0, p, 0);
}

int main() {
	string s("aab");
	string p("aa");
	cout << isMatch(s, p) << endl;
	system("pause");
	return 0;
}