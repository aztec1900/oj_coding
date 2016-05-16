#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(vector<int> nums) {
		if (nums.size() == 0) {
			val = 0;
			next = NULL;
		}
		else {
			val = nums[0];
			ListNode* p = this;
			for (int i = 1; i < nums.size(); ++i) {
				p->next = new ListNode(nums[i]);
				p = p->next;
			}
		}
	}
	void display() {
		ListNode* p = this;
		while (p != NULL) {
			cout << p->val << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
};

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k <= 1)
		return head;
	ListNode* p = head;
	int cnt = 0;
	while (p != NULL && cnt < k) {
		p = p->next;
		cnt++;
	}
	if (cnt < k)
		return head;
	p = head->next;
	ListNode* pre = head;
	for (int i = 0; i<k - 1; ++i) {
		ListNode* foo = p->next;
		p->next = pre;
		pre = p;
		p = foo;
	}
	head->next = reverseKGroup(p, k);
	return pre;
}

int main() {
	vector<int> nums{ 1, 2 };
	ListNode* head = new ListNode(nums);
	head->display();
	ListNode* ret = reverseKGroup(head, 2);
	ret->display();
	system("pause");
	return 0;
}