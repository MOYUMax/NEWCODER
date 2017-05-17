#include "stdafx.h"
#include "header.h"

bool checkDifferent(string iniString)
{
	if (iniString.size() == 0 || iniString.length() > 256)
		return false;
	for (int i = 1; i < (int)iniString.length(); ++i){
		string sub1 = iniString.substr(0, i-1);
		string sub2 = iniString.substr(i);
		string checkstr = iniString.substr(i - 1, 1);
		if (sub1.find(checkstr) != string::npos || string::npos != sub2.find(checkstr))
			return false;
	}
	return true;
}

bool checkDifferent2(string iniString)
{
	if (iniString.size() == 0 || iniString.length() > 256)
		return false;
	bool appear[256];
	for (int i = 0; i < (int)iniString.length(); ++i){
		int index = iniString.at(i);
		if (appear[index] == true)
			return false;
		appear[index] = true;
	}
	return true;
}

void testcheckDifferent()
{
	string inistring = "ABCDEFGHIJKL";
	string iniStr = R"(D-5H0F6T%Z?QM9,\72:[A8X!;YJ#)";//字符串 \72 会被直接转换为 : 号

	cout << "check Different :" << checkDifferent(iniStr) << endl;

	cout << "check Different2 :" << checkDifferent2(iniStr) << endl;
}

string reverseString(string iniString)
{
	reverse(iniString.begin(), iniString.end());
	return iniString;
}
void testveverseString()
{
	string iniString = R"(This is a string to reversi \72)";
	cout << iniString << "\nafter reverse:" << endl;
	cout << reverseString(iniString) << endl;
}

bool checkSam(string stringA, string stringB)
{
	int sumA[256] = { 0 };
	int sumB[256] = { 0 };
	for (int i = 0; i < (int)stringA.length(); ++i){
		int index = stringA.at(i);
		++sumA[index];
	}
	for (int i = 0; i < (int)stringB.length(); ++i){
		int index = stringB.at(i);
		++sumB[index];
	}
	for (int i = 0; i < 256; ++i)
		if (sumA[i] != sumB[i])
			return false;
	return true;
}

void testcheckSam()
{
	string A = "This is a test strinG";
	string B = "is a string tets This";
	cout << "checkSam:" << checkSam(A, B) << endl;
}

string replaceSpace(string iniString, int length)
{
	string ret = "";
	for (int i = 0; i < length; ++i){
		char c = iniString.at(i);
		if (' ' == c){
			ret.append("%20");
		}
		else{
			ret.append(iniString.substr(i,1));
		}
	}
	return ret;
}

void testreplaceSpace()
{
	string A = "This is a test string";
	cout << replaceSpace(A, A.size());
}

string zipString(string iniString)
{
	string ret = "";
	int i = 0;
	while (i <int(iniString.size())){
		ret.append(iniString.substr(i, 1));
		char c1 = iniString.at(i);
		int count = 1;
		while (iniString[++i] == c1)
			++count;
		ret.append(to_string(count));		
	}
	if (ret.size() >= iniString.size())
		return iniString;
	else
		return ret;
}
void testzipString()
{
	string A = "qwertyuioplkjhgfdsAzxcvbNM";
	cout << A << endl << "after zip:\n" << zipString(A) << endl;
}

vector<vector<int> > transformImage(vector<vector<int> > mat, int n)
{
	for (int i = 0; i < n/2; ++i)
		for (int j = 0; j < n; ++j){
			int temp = mat[i][j];
			mat[i][j] = mat[n-i-1][j];
			mat[n - i - 1][j] = temp;
		}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j){
			int temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}

	return mat;
}
void testtrans()
{

	vector<vector<int> > vvintmat = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	vector<vector<int> > ret = transformImage(vvintmat, 3);
	return;
}
vector<vector<int>> clearZero(vector<vector<int>> mat, int n)
{
	vector < vector<int>> tempmat = mat;

	for (int i = 0; i < n; ++i){
		int j = 0;
		while (j<n && mat[i][j] != 0){
			++j;
		}
		if (j!=n){
			for (int row = i, column = 0; column < n; ++column)
				tempmat[row][column] = 0;
		}
	}

	for (int j = 0; j < n; ++j){
		int i = 0;
		while (i<n && mat[i][j] != 0){
			++i;
		}
		if (i != n){
			for (int row = 0, column = j; row < n; ++row)
				tempmat[row][column] = 0;
		}
	}

	return tempmat;
}
void testclearZero()
{
	vector<vector<int>> mat = {
		{ 1, 2, 3 },
		{ 0, 5, 6 },
		{ 0, 0, 9 }
	};

	mat = clearZero(mat, 3);
	for (auto x : mat){
		for (auto elem : x){
			cout << elem << " ";
		}
		cout << endl;
	}
}
bool checkReverseEqual(string s1, string s2)
{
	int len1 = s1.length();
	if (len1 == s2.length() && len1 > 0){
		string s1s1 = s1 + s1;
		if (s1s1.find(s2) == string::npos)
			return false;
		else
			return true;
	}
	return false;
}
void testcheckReverseEqual()
{
	string s1 = "Hello World!";
	string s2 = "lo World!Hel";
	cout << checkReverseEqual(s1, s2) << endl;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k < 1)
		return nullptr;
	ListNode * p = pListHead;
	ListNode * q = p;
	unsigned int i = 1;
	while (i<k)
	{
		if (p == nullptr)
			return nullptr;
		else{
			p = p->next;
			i++;
		}
	}
	if (i == k && p == nullptr)
		return nullptr;
	while (p->next != nullptr){
		q = q->next;
		p = p->next;
	}
	cout << q->val;
	return q;
}
void testFindKthToTail()
{

	ListNode * s = new ListNode(1);
	s->next = nullptr;
	for (int i = 10; i > 1; --i){
		ListNode * p = new ListNode(i);
		p->next = s->next;
		s->next = p;
	}
	ListNode * ret = FindKthToTail(s, 11);
	//cout << "4th to tail:" << ret->val << endl;
}
bool removeNode(ListNode * pNode)
{
	if (pNode == nullptr || pNode->next == nullptr)
		return false;
	ListNode * q = pNode->next;
	pNode->val = q->val;
	pNode->next = q->next;
	delete q;
	return true;
}
//ListNode* partition(ListNode* pHead, int x) {
//	// write code here
//	if (pHead == nullptr)
//		return pHead;
//	ListNode * low = new ListNode(0);	
//	ListNode * high = new ListNode(0);
//	ListNode * p = pHead;
//	while (p != nullptr){
//		ListNode * q = p;
//		if (q->val < x)
//		{
//			p = q->next;
//			q->next = low->next;
//			low->next = q;
//			low = q;
//		}
//		else{
//			p = q->next;
//			q->next = high->next;
//			high->next = q;
//			high = q;
//		}
//	}
//	ListNode * ret = nullptr;
//	if (low->next == low){
//		p = high->next;
//		ret = p->next;
//		high->next = nullptr;
//		delete p;
//	}
//	else{
//		p = low->next;
//		ret = p->next;
//		low->next = nullptr;
//		delete p;
//		if (high->next == high)
//			return ret;
//		else{
//			p = high->next;
//			low->next = p->next;
//			high->next = nullptr;
//			delete p;
//			return ret;
//		}
//	}
//	return ret;
//}
ListNode* partition(ListNode* pHead, int x)
{
	if (pHead == nullptr)
		return pHead;
	ListNode * small = new ListNode(0);
	ListNode * big = new ListNode(0);
	ListNode * ps, *pb, *p;
	p = pHead;
	ps = small;
	ps->next = nullptr;
	pb = big;
	pb->next = nullptr;
	while (p != nullptr){
		if (p->val < x){
			ps->next = p;
			ps = ps->next;
			p = p->next;
			ps->next = nullptr;
		}
		else{
			pb->next = p;
			pb = pb->next;
			p = p->next;
			pb->next = nullptr;
		}
	}
	if (small->next == nullptr)
		return big->next;
	if (big->next == nullptr)
		return small->next;
	ps->next = big->next;
	return small->next;
}
void testPartition()
{
	ListNode * s = new ListNode(1);
	s->next = nullptr;
	for (int i = 2; i<5; ++i){
		ListNode * p = new ListNode(i);
		p->next = s->next;
		s->next = p;
	}
	s = partition(s, 10);
	ListNode * p = s;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
}
//ListNode* plusAB(ListNode* a, ListNode* b) {
//	// write code here
//	if (a == nullptr)
//		return b;
//	if (b == nullptr)
//		return a;
//	ListNode *pa, *pb,*p;
//	pa = a;
//	pb = b;
//	ListNode * ret = new ListNode(0);
//	p = ret;
//	while (pa != nullptr && pb != nullptr){	
//		int temp =p->val + pa->val + pb->val;
//		if (temp < 10){
//			p->val = temp;
//			p->next = new ListNode(0);
//			p = p->next;
//		}
//		else{
//			int little = temp % 10;
//			temp = temp / 10;
//			p->next = new ListNode(temp);
//			p->val = little;
//			p = p->next;
//		}
//		pa = pa->next;
//		pb = pb->next;
//	}
//
//	while (pb != nullptr){
//		int temp =p->val + pb->val;
//		if (temp < 10){
//			p->val = temp;
//			p->next = pb->next;
//			break;
//		}
//		else{
//			int little = temp % 10;
//			temp = temp / 10;
//			p->next = new ListNode(temp);
//			p->val = little;
//			p = p->next;
//		}
//		pb = pb->next;
//	}
//	while (pa != nullptr){
//		int temp = p->val + pa->val;
//		if (temp < 10){
//			p->val = temp;
//			p->next = pa->next;
//			break;
//		}
//		else{
//			int little = temp % 10;
//			temp = temp / 10;
//			p->next = new ListNode(temp);
//			p->val = little;
//			p = p->next;
//		}
//		pa = pa->next;
//	}
//	if (p->val == 0){
//		pa = ret;
//		while (pa->next != p)
//			pa = pa->next;
//		pa->next = nullptr;
//	}
//	return ret;
//}
ListNode* plusAB(ListNode* a, ListNode* b)
{
	ListNode * head = new ListNode(0);
	ListNode *p = head;
	ListNode *node = nullptr;
	ListNode * pa = a, *pb = b;
	int c = 0, sum, val1, val2;
	while (pa != nullptr || pb != nullptr || c != 0){
		val1 = (pa == nullptr ? 0 : pa->val);
		val2 = (pb == nullptr ? 0 : pb->val);
		sum = val1 + val2 + c;
		c = sum / 10;
		node = new ListNode(sum % 10);

		p->next = node;
		p = node;
		pa = (pa == nullptr ? nullptr : pa->next);
		pb = (pb == nullptr ? nullptr : pb->next);
	}
	return head->next;
}
void testplusAB()
{
	ListNode * sa = new ListNode(1);
	sa->next = nullptr;
	for (int i = 6; i>1; --i){
		ListNode * p = new ListNode(i);
		p->next = sa->next;
		sa->next = p;
	}
	ListNode * sb = new ListNode(1);
	sb->next = nullptr;
	for (int i = 6; i>1; --i){
		ListNode * p = new ListNode(i);
		p->next = sb->next;
		sb->next = p;
	}
	ListNode * r = plusAB(sa, sb);
	ListNode * p = r;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}	
}

/*	//递归实现回文链表
	//采用递归的方式，将p定义成static：
	//每次传入一个新的链表，让p指向链表首节点。
	//通过递归，pHead从后往前，p从前往后，同时比较。
bool isPalindrome(ListNode* pHead) {
	// write code here
	if (pHead == NULL)
		return true;
	static ListNode* p = NULL;
	if (p == NULL) p = pHead;
	if (isPalindrome(pHead->next) && (p->val == pHead->val))
	{
		p = p->next;
		return true;
	}
	p = NULL;
	return false;
}
*/
bool isPalindrome(ListNode* pHead) {
	// write code here
	
	if (pHead == nullptr)
		return false;
	ListNode * p = pHead;
	ListNode * q ;
	ListNode * reverse = new ListNode(0);
	reverse->next = nullptr;
	while (p != nullptr){
		q = new ListNode(p->val);
		q->next = reverse->next;
		reverse->next = q;
		p = p->next;
	}
	p = pHead;
	q = reverse->next;
	while (p != nullptr && q != nullptr){
		if (p->val != q->val)
			return false;
		p = p->next;
		q = q->next;
	}
	return true;
}
void testisPalindrome()
{
	ListNode * sa = new ListNode(1);
	sa->next = nullptr;
	for (int i = 6; i>1; --i){
		ListNode * p = new ListNode(i);
		p->next = sa->next;
		sa->next = p;
	}
	ListNode * sb = new ListNode(1);
	sb->next = nullptr;
	for (int i = 6; i>1; --i){
		ListNode * p = new ListNode(1);
		p->next = sb->next;
		sb->next = p;
	}
	cout << "Is sa Palindrome:" << isPalindrome(sa) << endl;
	cout << "Is sb Palindrome:" << isPalindrome(sb) << endl;
}
bool IsListLoop(ListNode * pHead)
{
	ListNode * fast, *slow;
	if (pHead == nullptr || pHead->next == nullptr)
		return false;
	fast = slow = pHead;
	while (fast->next != nullptr && fast->next->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow){
			cout << "The List is Loop!\n";
			return true;
		}
	}
	cout << "The List isn't Loop!\n";
	return false;
}
ListNode * FindLoopEntry(ListNode * pHead){
	if (pHead == nullptr || pHead->next == nullptr)
		return nullptr;
	ListNode * fast, *slow;
	fast = slow = pHead;
	while (fast->next != nullptr && fast->next->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow){
			cout << "The list is Loop\n";
			break;
		}
	}
	fast = pHead;
	while (fast != slow){
		fast = fast->next;
		slow = slow->next;
	}
	cout << "Find the Loop Entry:" << fast->val << endl;
	return fast;
}
void testFindLoopEntry()
{
	ListNode * sa = new ListNode(1);
	sa->next = nullptr;
	ListNode * p,*q;
	q = new ListNode(100);
	sa->next = q;
	q->next = nullptr;
	for (int i = 5; i>1; --i){
		p = new ListNode(i);
		p->next = sa->next;
		sa->next = p;
	}
	q->next = sa->next->next->next;
	if (IsListLoop(sa))
		p = FindLoopEntry(sa);
	if (p != nullptr)
		cout << "The p->val :" << p->val << endl;
}