#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isNumber(string s) {
	enum status { sStart, sNegStart, sGo, sDot, sBareDot, sFirstE, sEOpt, sE, sLastSpace };
	int n = s.length();
	int i = 0;
	while (i < n && s[i] == ' ') i++;
	if (i == n)
		return false;
	/*else if (i == n - 1)
	return s[i] >= '0' && s[i] <= '9';*/
	status sm = sStart;
	for (; i<n; ++i) {
		switch (sm) {
		case sStart:
			if (s[i] >= '0' && s[i] <= '9')
				sm = sGo;
			else if (s[i] == '.')
				sm = sBareDot;
			else if (s[i] == '-' || s[i] == '+')
				sm = sNegStart;
			else
				return false;
			break;
		case sNegStart:
			if (s[i] >= '0' && s[i] <= '9')
				sm = sGo;
			else if (s[i] == '.')
				sm = sBareDot;
			else
				return false;
			break;
		case sGo:
			if (s[i] >= '0' && s[i] <= '9')
				continue;
			else if (s[i] == '.')
				sm = sDot;
			else if ((s[i] == 'e' || s[i] == 'E') && i != n - 1)
				sm = sFirstE;
			else if (s[i] == ' ')
				sm = sLastSpace;
			else
				return false;
			break;
		case sDot:
			if (s[i] >= '0' && s[i] <= '9')
				continue;
			else if ((s[i] == 'e' || s[i] == 'E') && i != n - 1)
				sm = sFirstE;
			else if (s[i] == ' ')
				sm = sLastSpace;
			else
				return false;
			break;
		case sBareDot:
			if (s[i] >= '0' && s[i] <= '9')
				sm = sDot;
			else
				return false;
			break;
		case sFirstE:
			if (s[i] >= '0' && s[i] <= '9')
				sm = sE;
			else if (s[i] == '+' || s[i] == '-')
				sm = sEOpt;
			else
				return false;
			break;
		case sEOpt:
			if (s[i] >= '0' && s[i] <= '9')
				sm = sE;
			else
				return false;
		case sE:
			if (s[i] >= '0' && s[i] <= '9')
				continue;
			else if (s[i] == ' ')
				sm = sLastSpace;
			else
				return false;
			break;
		case sLastSpace:
			if (s[i] != ' ')
				return false;
		}
	}
	return sm != sBareDot && sm != sNegStart && sm != sEOpt;
}

int main() {
	ifstream fin;
	fin.open("data.txt");
	string s;
	while (getline(fin, s)) {
		auto ret = isNumber(s);
		cout << s << ": ";
		if (ret)
			cout << "true";
		else
			cout << "fales";
		cout << endl;
	}
	system("pause");
	return 0;
}