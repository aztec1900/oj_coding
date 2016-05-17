#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool hasOverlap(const Interval& a, const Interval& b) {
	if (a.start <= b.start)
		if (b.start <= a.end)
			return true;
		else
			return false;
	else
		if (a.start <= b.end)
			return true;
		else
			return false;
}
Interval mergeIntervals(const Interval& a, const Interval& b) {
	return Interval(min(a.start, b.start), max(a.end, b.end));
}
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	//sort(intervals.begin(), intervals.end());
	int n = intervals.size();
	if (n == 0)
		return{ newInterval };
	if (intervals[0].start >= newInterval.start)
		intervals.insert(intervals.begin(), newInterval);
	else {
		int i;
		for (i = 0; i<intervals.size() - 1; ++i)
			if (intervals[i].start < newInterval.start && intervals[i + 1].start >= newInterval.start) {
				intervals.insert(intervals.begin() + i+1, newInterval);
				break;
			}
		if (i == intervals.size() - 1)
			intervals.insert(intervals.end(), newInterval);
	}
	int i = 0;
	while (i < intervals.size() - 1) {
		if (hasOverlap(intervals[i], intervals[i + 1])) {
			intervals[i] = mergeIntervals(intervals[i], intervals[i + 1]);
			intervals.erase(intervals.begin() + i + 1);
		}
		else
			i++;
	}
	return intervals;
}

int main() {
	vector<Interval> intervals = { Interval(0, 5), Interval(9, 12) };
	Interval newInterval(7, 16);
	auto ret = insert(intervals, newInterval);
	return 0;
}