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

vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) 
{
	// write code here

	vector<vector<int>> ret;
	stack<int> mystack;
	for (auto vv_elem : ope){
		cout << "ope*[0]: " << vv_elem[0] << "\t ope*[1]: " << vv_elem[1] << endl;
		if (vv_elem[0] == 1)
			mystack.push(vv_elem[1]);
		else
			mystack.pop();
	}
	int length = mystack.size();
	int left = length % size;
	int nsize = length - left;
	vector<int> temp;
	vector<int>::iterator head = temp.begin();
	for (int i = 0; i < left; ++i)
	{
		int top = mystack.top();
		head  = temp.insert(head, top);
		mystack.pop();
	}
	auto it = ret.begin();
	if (!temp.empty())
		it = ret.insert(it, temp);
	if (nsize > 0){
		int cir = nsize / size;
		for (int i = 0; i < cir; ++i){
			temp.clear();
			head = temp.begin();
			for (int j = 0; j < size && !mystack.empty(); ++j){
				int top = mystack.top();
				head = temp.insert(head, top);
				mystack.pop();				
			}
			it = ret.insert(it, temp);
		}
	}
	return ret;
}
void testsetOfStacks()
{
	vector<vector<int>> vvint = {
		{ 1, 1 },
		{ 2, 1 },
		{ 1, 2 },
		{ 1, 3 },
		{ 1, 4 },
		{ 2, 4 },
		{ 1, 4 },
		{ 2, 4 },
		{ 1, 4 },
		{ 1, 5 },
		{ 2, 5 },
		{ 1, 5 },
		{ 1, 6 },
		{ 1, 7 },
		{ 2, 7 },
		{ 1, 8 },
		{ 1, 9 },
		{ 1, 10 },
		{ 1, 11 },
		{ 1, 12 },
		{ 1, 13 },
		{ 1, 14 },
		{ 1, 15 },
		{ 1, 16 },
	};
	int size = 4;
	vector < vector<int> > ret = setOfStacks(vvint, size);
	cout << "set of stacks:\n";
	for (auto vv : ret){
		for (auto vv_elem : vv){
			cout << vv_elem << " ";
		}
		cout << endl;
	}
}

/*//a queue build with two stack1 and stack2
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty()){
			int top = stack1.top();
			stack2.push(top);
			stack1.pop();
		}
		int ret;
		if (!stack2.empty()){
			ret = stack2.top();
			stack2.pop();
		}
		while (!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
*/
//vector<int> twoStacksSort(vector<int> numbers) 
//{
//	// write code here
//	vector<int> ret = numbers;
//	//struct cmp{
//	//	bool operator()(const int & x, const int & y){
//	//		return x > y;
//	//	}
//	//};
//	//sort(ret.begin(), ret.end(),cmp());
//	sort(ret.begin(), ret.end(), greater<int>());
//	return ret;
//}
//vector<int> twoStacksSort(vector<int> numbers)
//{
//	stack<int> stack1;
//	stack<int> stack2;
//	for (auto vi : numbers)
//		stack1.push(vi);
//	int length = stack1.size();
//	int top1, top2;
//	top2 = stack1.top();
//	stack2.push(top2);
//	stack1.pop();
//	while (!stack1.empty()){
//		top1 = stack1.top();
//		while (!stack2.empty() && stack2.top() > top1){
//			stack1.push(stack2.top());
//			stack2.pop();
//		}
//		stack2.push(top1);
//		while (!stack1.empty() && top1 != stack1.top()){
//			stack2.push(stack1.top());
//			stack1.pop();
//		}
//		stack1.pop();
//	}
//	vector<int> ret;
//	while (!stack2.empty()){
//		ret.push_back(stack2.top());
//		stack2.pop();
//	}
//	return ret;
//}
vector<int> twoStacksSort(vector<int> numbers)
{
	vector<int> ret;
	ret.push_back(numbers.back());
	numbers.pop_back();
	while (!numbers.empty()){
		int back = numbers.back();
		while (!ret.empty() && back > ret.back()){
			numbers.push_back(ret.back());
			ret.pop_back();
		}
		ret.push_back(back);
		while (!numbers.empty() && back != numbers.back()){
			ret.push_back(numbers.back());
			numbers.pop_back();
		}
		numbers.pop_back();
	}
	return ret;
}
void testtwoStacksSort()
{
	vector<int> num = { 1, 5, 4, 6, 8, 7, 9, 1, 6, 4, 4, 5, 8, 420, 130256, 63 };
	cout << "Befor sort:";
	for (auto vi : num)
		cout << vi << " ";
	num = twoStacksSort(num);
	cout << "\nAfter sort:";
	for (auto vi : num)
		cout << vi << " ";
}
vector<int> asylum(vector<vector<int> > ope) {
	// write code here
	vector<int> ret;
	deque<int> myqueue;
	stack<int> temp;
	for (auto vv_elem : ope){
		if (vv_elem[0] == 1)
			myqueue.push_back(vv_elem[1]);
		else if (vv_elem[1] == 0 && !myqueue.empty()){
			ret.push_back(myqueue.front());
			myqueue.pop_front();
		}
		else{
			while (!myqueue.empty() && myqueue.front()*vv_elem[1] < 0){
				temp.push(myqueue.front());
				myqueue.pop_front();
			}
			if (!myqueue.empty()){
				ret.push_back(myqueue.front());
				myqueue.pop_front();
			}
			while (!temp.empty()){
				myqueue.push_front(temp.top());
				temp.pop();
			}
		}
	}
	return ret;
}
void testasylum()
{
	vector<vector<int>> vvint = {
		{ 1, 1 },
		{ 1, -1 },
		{ 2, 0 },
		{ 1, 1 },
		{ 1, -1 },
		{ 2, -1 },
		{ 2, -1 },
		{ 2, 1 },
		{ 2, 1 },
	};
	vector<int> ret = asylum(vvint);
	for (auto vi : ret)
		cout << vi << " ";
	cout << endl;
}

bool isBalance(TreeNode* root) {
	// write code here
	if (root == nullptr)
		return true;
	int m = Depth(root->left);
	int n = Depth(root->right);
	int l = m > n ? m - n : n - m;
	if (l > 1)
		return false;
	else
		return true;
	
}
int Depth(TreeNode * root)
{
	if (root == nullptr)
		return 0;
	else{
		int m = Depth(root->left);
		int n = Depth(root->right);
		return m > n ? m + 1 : n + 1;
	}
}
void CreateTree(TreeNode * & root, int a[],int i, int n)
{
	if (i < n){
		root = new TreeNode(a[i]);
		CreateTree(root->left, a, 2 * i, n);
		CreateTree(root->right, a, 2 * i + 1, n);
	}
	else
		root = nullptr;
}
void testisBalance()
{
	TreeNode * root;
	int a[10] = {0, 1 , 2, 3, 4, 5, 6, 7, 8, 9 };	
	CreateTree(root, a, 1, 9);
	cout << "isBalance:" << isBalance(root) << endl;
}

void L_Rotate(AVLTrNode * & p)
{
	AVLTrNode * R;
	R = p->right;
	p->right = R->left;
	R->left = p;
	p = R;
}
void R_Rotate(AVLTrNode * & p)
{
	AVLTrNode * L;
	L = p->left;
	p->left = L->right;
	L->right = p;
	p = L;
}

void LeftBalance(AVLTrNode * & T)
{
	AVLTrNode * L, * Lr;
	L = T->left;
	Lr = L->right;
	switch (L->bf)
	{
	case LH:
		T->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		switch (Lr->bf)
		{
		case LH:
			T->bf = RH;
			L->bf = EH;
			break;
		case EH:
			T->bf = L->bf = EH;
			break;
		case RH:
			T->bf = EH;
			L->bf = LH;
			break;
		default:
			break;
		}		
	default:
		Lr->bf = EH;
		L_Rotate(T->left);
		R_Rotate(T);
		break;
	}
}
void RightBalance(AVLTrNode * & T)
{
	AVLTrNode * R, *Rl;
	R = T->right;
	Rl = R->left;
	switch (R->bf)
	{
	case RH:
		T->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		switch (Rl->bf)
		{
		case LH:
			T->bf = EH;
			R->bf = RH;
			break;
		case RH:
			T->bf = LH;
			R->bf = EH;
			break;
		case EH:
			T->bf = R->bf = EH;
			break;
		default:
			break;
		}

	default:
		Rl->bf = EH;
		R_Rotate(T->right);
		L_Rotate(T);
		break;
	}
}
int buildMinimalBST(vector<int> vals) {
	// write code here
	AVLTrNode  * root = nullptr;
	bool  taller ;
	for (auto vi_elem : vals){
		InsertAVL(root, vi_elem, taller);
	}
	int depth = Depth(root);
	return depth;
}
bool InsertAVL(AVLTrNode * & root, int s,bool & taller)
{
	if (root == nullptr)
	{
		root = new AVLTrNode(s);
		taller = true;
	}
	else{
		if (s == root->val){
			taller = false;
			return false;
		}
		if (s < root->val){
			if (!InsertAVL(root->left, s, taller))
				return false;
			if (taller){
				switch (root->bf)
				{
				case LH:
					LeftBalance(root);
					taller = false;
					break;
				case EH:
					root->bf = LH;
					taller = true;
					break;
				case RH:
					root->bf = EH;
					taller = false;
					break;
				default:
					break;
				}
			}
		}
		else{
			if (!InsertAVL(root->right, s, taller)){
				return false;
			}
			if (taller){
				switch (root->bf)
				{
				case LH:
					root->bf = EH;
					taller = false;
					break;
				case EH:
					root->bf = RH;
					taller = true;
					break;
				case RH:
					RightBalance(root);
					taller = false;
					break;
				default:
					break;
				}
			}
		}
	}
	return true;
}
int Depth(AVLTrNode * root)
{
	if (root == nullptr)
		return 0;
	else{
		int m = Depth(root->left);
		int n = Depth(root->right);
		return m > n ? m + 1 : n + 1;
	}
}
void testbuildMinimalBST()
{
	vector<int> va = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int depth = buildMinimalBST(va);
	cout << "Depth:" << depth << endl;
}
/*路径检测，有向图顶点a,b是否是连通
 */
bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
	// write code here
	return check(a, b) || check(b, a);	
}
bool check(UndirectedGraphNode* a, UndirectedGraphNode* b)
{
	if (a == nullptr || b == nullptr)
		return false;
	if (a == b)
		return true;
	queue<UndirectedGraphNode * > pQueue;
	pQueue.push(a);
	map<UndirectedGraphNode *, bool> arrived_map;
	while (!pQueue.empty()){
		UndirectedGraphNode * front = pQueue.front();
		arrived_map[front] = true;
		for (unsigned i = 0; i < front->neighbors.size(); ++i){
			if (front->neighbors[i] == b)
				return true;
			if (front->neighbors[i] && arrived_map[front->neighbors[i]] != true)
				pQueue.push(front->neighbors[i]);
		}
		pQueue.pop();
	}
	return false;
}
void testcheckpath()
{
	int mmap[4] = { 0, 1, 2, 3 };
	UndirectedGraphNode * pmap[4];
	for (int i = 0; i < 4; ++i){
		pmap[i] = new UndirectedGraphNode(i);
	}
	for (int i = 0; i < 3; ++i){
		pmap[i]->neighbors.push_back(pmap[(i + 1) % 4]);
	}
	cout << "map[0] to map[3]" << checkPath(pmap[1], pmap[0]);
}
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

ListNode* getTreeLevel(TreeNode* root, int dep) {
	// write code here
	if (root == nullptr)
		return nullptr;
	if (dep <= 0)
		return nullptr;
	queue<TreeNode *> t_Queue;
	t_Queue.push(root);
	int i = 1;
	int branch = (int)pow(2, dep-1) - 1;
	ListNode * list_dep = new ListNode(-1);
	ListNode * p = list_dep;
	while (!t_Queue.empty()){
		TreeNode * tnp = t_Queue.front();
		if (i <= branch){
			//if (tnp->left != nullptr)
				t_Queue.push(tnp->left);
			//if (tnp->right != nullptr)
				t_Queue.push(tnp->right);
			++i;
		}
		else if (i == branch+1){
			ListNode * q = new ListNode(tnp->val);
			p->next = q;
			p = q;
		}
		t_Queue.pop();
	}
	return list_dep->next;
}
void create(TreeNode * root, int i)
{
	if (i < 0 || i>63)
		return;
	TreeNode * lc = new TreeNode(2 * i);
	TreeNode * rc = new TreeNode(2 * i + 1);
	root->left = lc;
	root->right = rc;
	create(lc, 2 * i);
	create(rc, 2 * i + 1);
}
void testgetTreeLevel()
{
	TreeNode * root = new TreeNode(1); 
	create(root, 1);
	ListNode * p = getTreeLevel(root, 6);
	while (p){
		cout << p->val << "->";
		p = p->next;
	}
}
bool checkBST(TreeNode* root) {
	// write code here
	if (nullptr != root){
		TreeNode * p = root->left;
		TreeNode * q = root->right;
		return leftcheck(p, root) && rightcheck(q, root);
	}
	return true;
}
bool leftcheck(TreeNode * L, TreeNode * F)
{
	if (nullptr != L){
		TreeNode * p = L->left;
		TreeNode * q = L->right;
		if (nullptr != p &&L->val < p->val)
			return false;
		else
			return leftcheck(p, L);
		if (nullptr != q && L->val > q->val && q->val > F->val)
			return false;
		else
			return rightcheck(q, L);
	}
	return true;
}
bool rightcheck(TreeNode * R, TreeNode * F)
{
	if (nullptr != R){
		TreeNode * p = R->left;
		TreeNode * q = R->right;
		if (nullptr != p && R->val > p->val && p->val < F->val)
			return false;
		else
			return leftcheck(p, R);
		if (nullptr != q && R->val < q->val)
			return false;
		else
			return rightcheck(q, R);
	}
	return true;
}
TreeNode * searchBST(TreeNode * root, int key)
{
	if (root == nullptr)
		return nullptr;
	if (key = root->val)
		return root;
	else if (key < root->val)
		return searchBST(root->left, key);
	else
		return searchBST(root->right, key);
}
void insertBST(TreeNode * & root, TreeNode * s)
{
	if (root == nullptr)
		root = s;
	else if (root->val > s->val)
		insertBST( root->left, s);
	else
		insertBST( root->right, s);
}
void testcheckBST()
{
	int arr[10] = { 5, 6, 4, 3, 7, 2, 8, 1, 9, 0 };
	TreeNode * root = nullptr;
	for (int i = 0; i < 10; ++i){
		TreeNode * p = new TreeNode(arr[i]);
		insertBST(root, p);
	}
	cout << "CheckBST:" << checkBST(root) << endl;
}
/* 请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
 * 给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
 * 保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
 */
int findSucc(TreeNode* root, int p) {
	// write code here
	vector<int> vi;
	InOrder(root, vi);
	for (unsigned i = 0; i < vi.size(); ++i){
		if (p == vi[i])
			return vi[i + 1];
	}
	return -1;
}
void InOrder(TreeNode * R,vector<int> & vi)
{
	if (R == nullptr)
		return;
	else{
		InOrder(R->left,vi);
		cout << R->val << " ";
		vi.push_back(R->val);
		InOrder(R->right, vi);
	}
}
void testfindSucc()
{
	int arr[10] = { 5, 6, 4, 3, 7, 2, 8, 1, 9, 0 };
	TreeNode * root = nullptr;
	for (int i = 0; i < 10; ++i){
		TreeNode * p = new TreeNode(arr[i]);
		insertBST(root, p);
	}
	cout<<findSucc(root, 5);
}
/* 有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。
 * 现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。给定两个int a,b。
 * 为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
 * 测试样例：2，3  返回：1
*/
int getLCA(int a, int b) {
	// write code here
	if (a == b)
		return a;
	vector<int> fa;
	vector<int> fb;
	for (int i = a; i >= 1; i /= 2)
		fa.push_back(i);
	for (int i = b; i >= 1; i /= 2)
		fb.push_back(i);
	for (unsigned j = 0; j < fa.size(); ++j){
		vector<int>::iterator it = find(fb.begin(), fb.end(), fa[j]);
		if ( it != fb.end())
			return fa[j];
	}
	return 1;
}
void testgetLCA()
{
	cout << "2 and 3 'father :" << getLCA(12, 13);
}
/* 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 */
vector<vector<int> > FindPath(TreeNode * root, int expectNumber) {
	vector<int> Path;
	vector<vector<int>> AllPath;
	if (root != nullptr){
		DFSFindPath(root, expectNumber, AllPath, Path);
	}
	return AllPath;
}
void DFSFindPath(TreeNode * root, int rest, vector<vector<int>> & path, vector<int> & ret)
{
	rest -= root->val;	//减去当前节点的值
	ret.push_back(root->val);	//更新路径
	//达到预期数值时，判断是否是叶子节点，如果是，则保存在 path中
	if (rest == 0 && root->left == nullptr && root->right == nullptr){
		path.push_back(ret);
	}
	if (rest != 0 && root->left != nullptr)
		DFSFindPath(root->left, rest, path, ret);
	if (rest != 0 && root->right != nullptr)
		DFSFindPath(root->right, rest, path, ret);
	ret.pop_back();//关键点，每次到达叶子后返回时逐一的删除原来的路径
}
void testFindPath()
{
	int a[14] = { 0,1, 2, 3, 4, 5, 6, 7, 2, 1, 0, 1, 5, 0 };
	TreeNode * root;
	CreateTree(root, a, 1 , 13);
	vector<vector<int>> vv_i = FindPath(root, 9);
	cin.get();
}
/*题目描述
 *有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,
 *其中二进制的位数从低位数到高位且以0开始。给定两个数int n和int m，同时给定int j和int i，
 *意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
 *测试样例：1024，19，2，6  返回：1100
 *思路：相当于将 m 左移 j 位，然后加上 n 即可
 */
int binInsert(int n, int m, int j, int i) {
	// write code here
	//return (n + (m*pow(2, j)));
	return (n + (m << j));
}
void testbinInsert()
{
	while (true){
		cout << "请输入 n m j i:";
		int n, m, j, i;
		cin >> n >> m >> j >> i;
		cout << " m 二进制插入 n 的结果：" << binInsert(n, m, j, i) << endl;
	}
}
/*题目描述
 *有一个介于0和1之间的实数，类型为double，返回它的二进制表示。
 *如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
 *给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
 *测试样例：0.625   返回：0.101
 *思路：乘 2 取整数部分，重复直到小数部分为 0，当超过32次仍有小数，则返回 Error。
 */
string printBin(double num) {
	// write code here
	string s = "0.";
	double twice = num * 2.0;
	int zenhlen = int(2 * num);
	double fraction = twice - zenhlen;
	int count = 32;
	s.push_back( '0' + zenhlen );
	while (fraction != 0 && --count > 0){
		twice = fraction * 2.0;
		zenhlen =int(2 * fraction);
		fraction = twice - zenhlen;
		s.push_back('0' + zenhlen);
	}
	if (fraction == 0)
		return s;
	else
		return "Error";
}
void testprintBin()
{
	double num;
	while (true){
		cout << "请输入介于0 和 1之间的纯小数（double):";
		cin >> num;
		cout << "它的32位二进制:" << printBin(num) << endl;
	}
}
/*题目描述
 *有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
 *给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
 *测试样例：2  返回：[1,4]
 *思路：位操作法 http://blog.csdn.net/wangfengfan1/article/details/47957299
 
 */
vector<int> getCloseNumber(int x) {
	// write code here
	vector<int> ret;
	int next = getNext(x);
	int prev = getPrev(x);
	
	ret.push_back(prev);
	ret.push_back(next);
	return ret;
}
int getNext(int n)
{
	// p : 最右边但是不拖尾的 0 的位置（低位从 0 开始记）
	//步骤 1 ：计算 c0, c1, p
	int c = n;
	int c0 = 0;// p 的右边 0 的个数
	int c1 = 0;// p 的右边 1 的个数
	while (((c & 1) == 0) && (c != 0)){
		++c0;
		c >>= 1;//
	}
	while ((c & 1) == 1)
	{
		++c1;
		c >>= 1;
	}
	//错误：若 x == 11..1100..00,那么没有比它更大的数字
	if (c0 + c1 == 31 || c0 + c1 == 0){
		return -1;
	}
	//步骤 2  ： 将 n 的第 p 位置 1， p 右边的全部清零，
	int p = c0 + c1;	//p : 最右边但是不拖尾的 0 的位置（低位从 0 开始记）
	n |= (1 << p);	//翻转第 p 位上的 0 成为 1
	int a = 1 << p;	// a : p 位为 1，其余位为 0 
	int b = a - 1;	// b : 前面全为 0， 后面跟 p 个 1
	int mask = ~b;	// 掩码 mask : 前面全为 1 ，后面跟 p 个 0
	n = n& mask;	// 将 n 右边 p 位清零
	//步骤 3 ：将 n 右边的 p 位回填最大的 （c1 - 1） 个 1
	a = 1 << (c1 - 1);// a : 位（c1 - 1)为 1，其余位均为 0
	b = a - 1;	//位 0 到位（c1 - 1)均为 1，其余位为 0
	n = n | b;	//在位 0 到位（c1 - 1)插入1
	return n;
}
int getPrev(int n)
{
	// p : 最右边但是不拖尾的 1 的位置（低位从 0 开始记）
	//步骤 1 ：计算 c1, c0, p ( 与getNext中的定义有区别）
	int temp = n;
	int c0 = 0;
	int c1 = 0;
	//计算
	while ((temp & 1) == 1){
		++c1;
		temp >>= 1;
	}
	//错误，形如 00..0011..11的数，没有比他更小的（1个数相同）的数
	if (temp == 0)
		return -1;
	while (((temp & 1) == 0) && (temp != 0)){
		++c0;
		temp >>= 1;
	}
	//步骤 2、3 ：将位 0 到位 p 清零
	int p = c0 + c1;//p : 最右边但是不拖尾的 1 的位置（低位从 0 开始记）
	int a = ~0; //全1
	int b = a << (p + 1); //位 p 左方全为 1，后跟 p+1 个0
	n &= b;	//将 n 位 0 到位 p 清零
	//步骤 4 ：将 n 位 p 的右方，插入最大 c1 + 1 个1
	//注意：p = c0 + c1,因此（c1 + 1) 个1 的后面会跟（c0 - 1)个 0
	a = 1 << (c1 + 1); //a : 位（c1 + 1) 为1，其余位均为0
	b = a - 1;			//b : 前面为 0 ，后面跟 （c1 + 1） 个1
	int c = b << (c0 - 1);//c : (c1 + 1)个1，后面跟 (c0 - 1)个0
	n |= c;		// 把 n 的后面替换为 c, 相当于 n = n + c ;
	return  n;
}
void testgetCloseNumber()
{
	int x;
	vector<int> closeNum;
	while (true){
		cout << "请输入一个正整数：";
		cin >> x;
		closeNum = getCloseNumber(x);
		cout << "最接近 " << x << "的两个数：";
		for (auto vi_elem : closeNum){
			cout << vi_elem << " ";
		}
		cout << endl;
	}
}
/*题目描述
编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
给定两个整数int A，int B。请返回需要改变的数位个数。
测试样例：10,5  返回：4
思路：从低位求两个数的二进制值，对比该位二进制是否相同；一个数完成后，查看另一个数剩下的位为 1 的个数
 */
int calcCost(int A, int B) {
	// write code here
	int a = A;
	int b = B;
	int count = 0;
	while (a != 0 && b != 0){
		int bitA = a % 2;
		int bitB = b % 2;
		if (bitA != bitB)
			++count;
		a /= 2;
		b /= 2;
	}
	while (a != 0){
		if (a % 2 == 1)
			++count;
		a /= 2;
	}
	while (b != 0){
		if (b % 2 == 1)
			++count;
		b /= 2;
	}
	return count;
}
void testcalcCost()
{
	while (true){
		int A, B;
		cout << "请输入整数 A B：";
		cin >> A >> B;
		cout << "需要改变的数位个数：" << calcCost(A, B) << endl;
	}
}
/*题目描述
请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
给定一个int x，请返回交换后的数int。
测试样例： 10   返回：5
思路：  设待操作的数为N，用N&0xaaaaaaaa（也就是10101010....）取出偶数位，
		用N&0x55555555（也就是01010101...）取出奇数位。
		第二步：偶数位应该右移一位，奇数位则应该左移一位。
		第三步：采用与操作把它们拼起来。
 */
int exchangeOddEven(int x) {
	// write code here
	return (((x)& 0xaaaaaaaa) >> 1) | (((x)& 0x55555555) << 1);
}
void testexchangeOddEven()
{
	while (true){
		int x;
		cout << "请输入整数：";
		cin >> x;
		cout << "交换它的二进制奇数位和偶数位后：" << exchangeOddEven(x) << endl;
	}
}
int findMissing(vector<vector<int> > numbers, int n) {
	// write code here
	if (numbers[0][0] != 0)
		return 0;
	for (int i = 0; i < n - 1; ++i){
		if (numbers[i + 1][0] != (numbers[i][0] + 1) % 2)
			return i + 1;
	}
	return n;
}
void testfindMissing()
{
	vector<vector<int>> numbers = { { 0 }, { 1, 0 }, { 0, 1 }, { 0, 1 }, { 0, 0, 1 } };
	cout << "缺失的数是：" << findMissing(numbers, 5) << endl;
}
/*题目描述
有一个单色屏幕储存在一维数组中，其中数组的每个元素代表连续的8位的像素的值，
请实现一个函数，将第x到第y个像素涂上颜色(像素标号从零开始)，并尝试尽量使用最快的办法。
给定表示屏幕的数组screen(数组中的每个元素代表连续的8个像素，且从左至右的像素分别对应元素的二进制
的从低到高位)，以及int x,int y，意义如题意所述，保证输入数据合法。请返回涂色后的新的屏幕数组。
测试样例：[0,0,0,0,0,0],0,47          返回：[255,255,255,255,255,255]
思路：基本上大意就是从第x 到第y位 ，其中的像素全部变为1，如此两种情况 ：
        0-->1, 1-->1 ，所以这时候就很清楚的用 位操作中的 ' | '
 */
vector<int> renderPixel(vector<int> screen, int x, int y) {
	// write code here
	for (int i = x; i <= y; ++i){
		int k = i % 8;//列
		int t = i / 8;//行
		screen[t]  |= (1 << k);// 置第t行位k为1，
	}
	return screen;
}
/*题目描述
在二维平面上，有一些点，请找出经过点数最多的那条线。
给定一个点集vector<point>p和点集的大小n,没有两个点的横坐标相等的情况,
请返回一个vector<double>，代表经过点数最多的那条直线的斜率和截距。</double></point>
思路：统计任意两点构成的直线的个数，返回相同点最大的那条直线。
*/
class DenseLine {
public:
	vector<double> getLine(vector<Point> p, int n) {
		// write code here
		double max = 0, slope = DBL_MAX, intercept = 0;
		map<pair<double, double>, int> map_line;

		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				double k = (p[i].y - p[j].y) / (p[i].x - p[j].x);
				double b = p[j].y - k*p[j].x;
				pair<map<pair<double, double>, int>::iterator, bool> ret = map_line.insert(make_pair(make_pair(k, b), 1));
				if (ret.second == false){
					//插入失败，代表 map_line 中已经存在这条直线了，需要增加该直线的计数
					++(ret.first->second);
					if (max < ret.first->second){
						//更新穿点最多的直线
						slope = ret.first->first.first;
						intercept = ret.first->first.second;
						int count = ret.first->second;
						cout << "穿点更大直线：count = "<<count<<"\t斜率和截距：" << slope << "\t" << intercept << endl;
					}
				}				
			}
		}
		vector<double> result = { slope, intercept };
		return result;
	}
};
void testgetLine()
{
	vector<Point> vp = {
		Point(0, 0), Point(1, 1), Point(2, 0), Point(3, 3)
	};
	DenseLine dsl;
	//vector<double> ret = DenseLine::getLine(vp, vp.capacity());
	vector<double> ret = dsl.getLine(vp, vp.capacity());
	cout << "穿点最多的直线：" << ret.at(0) << "\t" << ret.at(1) << endl;
}
/*题目描述
有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。保证k小于等于100。
测试样例： 3    返回：7
思路：
	3个素数因子3、5、7分为三个队列q3,q5,q7，其中最初存放3，5，7。 之后每次添加找到三个队列头中最小的数，
	起初为3，将3移出队列q3后，	在q3添加3*3，在q5添加3*5,q7中添加3*7。 此时可知q3{3*3},q5{5,3*5},q7{7,3*7}
????下一轮找到最小数为5，重复上述步骤，将5从q5移出，添加5*5到q5，因为5*3已经添加过所以不需要添加到q3中
	将5*7添加到q7，结果q3{3*3},q5{3*5,5*5},q7{7,3*7,5*7} 依次找到第k个数
*/
int findKth(int k) {
	// write code here
	if (k <= 0)
		return 0;
	int result = 0;
	queue<int> q3, q5, q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	for (int i = 1; i <= k; ++i){
		int v3 = q3.size() > 0 ? q3.front() : INT_MAX;
		int v5 = q5.size() > 0 ? q5.front() : INT_MAX;
		int v7 = q7.size() > 0 ? q7.front() : INT_MAX;		
		result = min({ v3, v5, v7 });
		if (result == v3){
			q3.pop();
			q3.push(result * 3);
			q5.push(result * 5);			
		}
		else if (result == v5){
			q5.pop();
			q5.push(result * 5);		
		}
		else{
			q7.pop();			
		}
		q7.push(result * 7);
	}
	return result;
}
void testfindKth()
{
	int k = 0;
	while (true){
		cout << "请输入 K ：";
		cin >> k;
		cout << "第 K 个满足素因子3、5、7的数：" << findKth(k) << endl;
	}
}
/*题目描述
有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。
请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
测试样例：1     返回：1
动态规划：
 */
//int waycount = 0;
int countWays(int n) {
	// write code here
	/*if (n == 0 || n == 1){
		return 1;
	}
	else if (n == 2){
		return 2;
	}
	else if (n == 3){
		return 4;
	}
	else{
		return (countWays(n - 1) % 1000000007 + countWays(n - 2) % 1000000007 + countWays(n - 3) % 1000000007) % 1000000007;
	}*/
	int a[100000];
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;
	/*a[i]=((a[i-1]+a[i-2])%1000000007+a[i-3])%1000000007的解释：
	取模运算有这样一个性质：(a+b)%c = ((a%c)+(b%c))%c
	所以(a[i-1]+a[i-2])%1000000007就相当于(a[i-1]%X+a[i-2]%X)%X?? 用X代替1000000007
	这样就使得a[i-1]、a[i-2]、a[i-1]+a[i-2]都没有溢出，之后再与a[i-3]相加之后取模，使得全部结果没有溢出。
	 */
	for (int i = 3; i < n; ++i){
		a[i] = ((a[i - 1]+ a[i - 2]) % 1000000007 + a[i - 3]) % 1000000007;
	}
	return a[n - 1];
}
void testcountWays()
{
	int n;
	while (true){
		cout << "请输入阶梯数：";
		cin >> n;
		cout << "一共有 " << countWays(n) << " 种方法。\n";
	}
}
/*题目描述
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
测试样例：2,2   返回：2
思路：从终点 e(x,0)往起点 s(0,y)走，每一次有两个选择：横坐标-1 或 纵坐标+1，这个子问题符合“最优子结构”，边界就是 （0，y)
	当到达边界 s(0,y)时，返回 1 。
 */

//int countWays(int x, int y) {
//	// write code here
//	if (x == 1 || y == 1)
//		return 1;
//	else
//		return countWays(x - 1, y) + countWays(x, y - 1);
//}
int countWays(int x, int y) {
	// write code here
	// 题目要求走的是大格子而不是网格线的交点，所以有两种走法。
	// 二维数组用于计算走到当前格子的走法总数，为其上方格子走法总数与其左侧格子走法总数之和
	int dp[13][13] = { 0 };
	//初始化边界 第1行：dp[0][] 第一列：dp[][0] 
	dp[0][0] = 1;
	for (int i = 1; i < y; i++)
		dp[0][i] = 1;
	for (int i = 1; i < x; i++)
		dp[i][0] = 1;
	//每一个格子都等于它左边格子和上边格子中数字的和
	for (int i = 1; i < x; ++i)
		for (int j = 1; j < y ; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	return dp[x - 1][y - 1];
}
void testcountWays2()
{
	int x, y;
	while (true){
		cout << "请输入 x 和 y :";
		cin >> x >> y;
		cout << "机器人一共有 " << countWays(x, y) << " 种走法。\n";
	}
}
/*题目描述
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，
计算机器人有多少种走法。注意这次的网格中有些障碍点是不能走的。给定一个int[][] map(C++ 中为vector >),
表示网格图，若map[i][j]为1则说明该点不是障碍点，否则则为障碍。另外给定int x,int y，表示网格的大小。
请返回机器人从(0,0)走到(x - 1,y - 1)的走法数，为了防止溢出，请将结果Mod 1000000007。保证x和y均小于等于50
思路：
     同样定义每一个格子都等于它左边格子和上边格子中数字的和，只是分两种情况，格子原来为1，则加上，否者置0
 */
int countWays(vector<vector<int> > map, int x, int y) {
	// write code here
	// * 1.判断右下角的点以及起点自身是否为障碍点，若是返回0；
	if (map[x - 1][y - 1] != 1 || map[0][0] != 1){//最后一个点为障碍点
		return 0;
	}
	const int MOD = 1000000007;
	map[0][0] = 1;
	for (int i = 1; i < x; ++i){
		if (map[i][0] == 1)
			map[i][0] = map[i - 1][0];
		else
			map[i][0] = 0;
	}
	for (int i = 1; i < y; ++i){
		if (map[0][i] == 1)
			map[0][i] = map[0][i-1];
		else
			map[0][i] = 0;
	}
	for (int i = 1; i < x; ++i)
		for (int j = 1; j < y; ++j){
			if (map[i][j] == 1){
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % MOD;
			}
			else
				map[i][j] = 0;
		}
	return map[x - 1][y - 1];
}
void testcountWays3(){
	vector<vector<int>> vmap = {
		{ 1, 1, 0 }, { 0, 1, 1 }, {1,1,1}
	};
	cout << "总的走法：" << countWays(vmap, 3, 3) << endl;
}
/*题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个升序数组，元素值各不相同，
编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：[1,2,3,4,5]		返回：false
思路：
 */
bool findMagicIndex(vector<int> A, int n) {
	// write code here
	/*for (int i = 0; i <= n / 2 ; ++i){
		if (A[i] == i || A[n - 1 - i] == n - 1 - i)
			return true;
	}
	return false;*/
	int start = 0, end = n - 1;
	int mid = 0;
	while (start <= end){
		mid = (start + end) / 2;
		if (A[mid] == mid)
			return true;
		else if (A[mid]<mid){
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return false;
}
void testfindMagicIndex()
{
	vector<int> A = { 1, 2, 3, 4, 5 };
	//cout << "是否有 MagicIndex：" << findMagicIndex(A, A.capacity()) << endl;
	cout << "是否有 MagicIndex：" << findMagicIndexII(A, A.capacity()) << endl;
}
/*题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个不下降序列，元素值可能相同，
编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：[1,1,3,4,5] 返回：true
思路：* 由于A是递增数组，可递归使用二分法，看是否满足魔术索引的条件
     * 如果当前中间值满足，则返回true，如果不满足
     * 由于序列非递减，两边序列都有可能有魔术索引
 */
bool MagicNumber(vector<int> A, int start, int end)
{
	if (start > end)
		return false;
	int mid = (start + end + 1) / 2;
	if (A[mid] == mid)
		return true;
	else
		return MagicNumber(A, start, mid-1) || MagicNumber(A, mid + 1, end);
}
bool findMagicIndexII(vector<int> A, int n) {
	// write code here
	if (A.capacity() != n || n <= 0)
		return false;
	return MagicNumber(A, 0, n - 1);
}
/*题目描述请编写一个方法，返回某集合的所有非空子集。
给定一个int数组A和数组的大小int n，请返回A的所有非空子集。保证A的元素个数小于等于20，且元素互异。
各子集内部从大到小排序,子集之间字典逆序排序，见样例。
测试样例：[123,456,789]
返回：{[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}
*/
vector<vector<int> > getSubsets(vector<int> A, int n) {
	// write code here
	vector<vector<int>> ret;
	sort(A.begin(), A.end());
	int setsize = 1 << n;
	for (int i = setsize - 1; i > 0; --i){
		vector<int> subset;
		for (int j = n - 1; j >= 0; --j){
			if ((i >> j) & 1){//
				subset.push_back(A[j]);
			}
		}
		ret.push_back(subset);
	}	
	return ret;
}
void testgetSubsets()
{
	vector<int> sets = { 123, 456, 789 };
	vector<vector<int> > result = getSubsets(sets, 3);
	for (auto vv_i : result){
		for (auto v_i : vv_i){
			cout << v_i << " ";
		}
		cout << endl;
	}
}
/*题目描述
编写一个方法，确定某字符串的所有排列组合。给定一个string A和一个int n,代表字符串和其长度，
请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，
排列中的字符串按字典序从大到小排序。(不合并重复字符串)
测试样例："ABC"          返回：["CBA","CAB","BCA","BAC","ACB","ABC"]
思路： 先定第一个字符，有n种选择+后续n-1个字符的全排列。
     
*/
vector<string> getPermutation(string A) {
	// write code here
	int len = A.length();
	vector<string> ret;
	Permutation(ret, A, 0, len);
	sort(ret.begin(), ret.end(), std::greater<string>());
	return ret;
}
void Permutation(vector<string> & vs, string A, int start, int end){
	if (start == end - 1){
		vs.push_back(A);
		return;
	}
	for (int i = start; i < end; ++i){
		swap(A[start], A[i]);
		Permutation(vs, A, start + 1, end);
		swap(A[start], A[i]);//为什么又要交换回来呢，因为要返回
	}
}
void testgetPermutation()
{
	string A;
	vector<string> result;
	while (true){
		cout << "请输入一个字符串：";
		cin >> A;
		result = getPermutation(A);
		for (auto vs : result){
			cout << vs << endl;
		}
	}
}
/*题目描述
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
测试样例："(()())",6   返回：true
*/
bool chkParenthesis(string A, int n) {
	// write code here
	if (n <= 1 || A[0] != '(')
		return false;
	stack<char> st;
	for (int i = 0; i < n; ++i){
		if ('(' == A[i])
			st.push(A[i]);
		else if (A[i] == ')'){
			if (st.empty())
				return false;
			else
				st.pop();
		}
		else{
			if (st.empty())
				return false;
		}
	}
	if (st.empty())
		return true;
	else
		return false;
}
void testchkParenthesis(){
	string A;
	while (true){
		cout << "请输入一个括号匹配字符串：";
		cin >> A;
		cout << "字符串括号合法性：" << chkParenthesis(A, A.length()) << endl;
	}
}
/*题目描述
在一个nxm矩阵形状的城市里爆发了洪水，洪水从(0,0)的格子流到这个城市，在这个矩阵中有的格子有一些建筑，
洪水只能在没有建筑的格子流动。请返回洪水流到(n - 1,m - 1)的最早时间(洪水只能从一个格子流到其相邻的格子
且洪水单位时间能从一个格子流到相邻格子)。给定一个矩阵map表示城市，其中map[i][j]表示坐标为(i,j)的格子，
值为1代表该格子有建筑，0代表没有建筑。同时给定矩阵的大小n和m(n和m均小于等于100)，请返回流到(n - 1,m - 1)的最早时间。
保证洪水一定能流到终点。
思路：用广度优先搜索：BFS，把所有可能的路径走出来，

*/
int floodFill(vector<vector<int> > map, int n, int m) {
	// write code here
	if (m == 0 || n == 0 )
		return 0;
	map[0][0] = 1;
	queue<pair<int, int>> Q;
	Q.push(make_pair(0, 0));
	pair<int, int > p;
	while (!Q.empty()){
		p = Q.front();
		Q.pop();
		//上
		if (p.first > 0 && !map[p.first - 1][p.second])
		{
			Q.push(make_pair(p.first - 1, p.second));
			map[p.first - 1][p.second] = map[p.first][p.second] + 1;
		}
		//左
		if (p.second < m - 1 && !map[p.first][p.second + 1])
		{
			Q.push(make_pair(p.first, p.second + 1));
			map[p.first][p.second + 1] = map[p.first][p.second] + 1;
		}
		//下
		if (p.first < n - 1 && !map[p.first + 1][p.second])
		{
			Q.push(make_pair(p.first + 1, p.second));
			map[p.first + 1][p.second] = map[p.first][p.second] + 1;
		}
		//右
		if (p.second > 0 && !map[p.first][p.second + 1])
		{
			Q.push(make_pair(p.first, p.second + 1));
			map[p.first][p.second + 1] = map[p.first][p.second] + 1;
		}
	}
	return map[n - 1][m - 1] - 1;
}
/*题目描述
有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
给定一个int n，请返回n分有几种表示法。保证n小于等于100000，为了防止溢出，请将答案Mod 1000000007。
测试样例：6	返回：2
思路：
 */
int countWaysC(int n) {
	// write code here
	int coins[4] = { 1, 5, 10, 25 };
	int dp[100001] = { 0 };
	dp[0] = 1;
	for (int i = 0; i < 4; ++i){
		for (int j = coins[i]; j <= n; ++j){
			dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
		}
	}
	return dp[n];
}
void testcountWays4()
{
	int n = 0;
	while (true){
		cout << "请输入n:";
		cin >> n;
		cout << "n 分用（25,10,5,1）表示方法有：" << countWaysC(n) << endl;
	}
}
/*题目描述
请设计一种算法，解决著名的n皇后问题。这里的n皇后问题指在一个nxn的棋盘上放置n个棋子，
使得每行每列和每条对角线上都只有一个棋子，求其摆放的方法数。给定一个int n，请返回方法数，保证n小于等于15
测试样例：1		返回：1
思路：按行来分步骤下棋，当前行有 n-(x-1)个选择
 */
bool check_place(int row, int col, vector<int> & m, int n)
{
	/*for (int i = 0; i < row-1; ++i){
		if (m[i] == col || abs(i - row) == abs(m[i] - col))
			return false;
	}
	return true;*/
	int i = 0;
	while (i < row){
		if (m[i] == col || abs(i - row) == abs(m[i] - col))
			return false;
		++i;
	}
	return true;
}
void print_result(const vector<int> & m,const int count,const int n)
{
	cout << "The " << count << " Ways to place " << n << " Queens." << endl;
	for (int i = 0; i < n; ++i){
		cout << "Row " << i + 1 << " place at " << m[i]<<endl;
	}
}
void queen(const int n,int row,vector<int> & m,int & count)
{
	if (n == row)
	{
		++count;
		//print_result(m,count,n);
	}
	else{
		for (int j = 0; j < n; ++j){
			if (check_place(row, j, m, n)){
				m[row] = j;
				queen(n, row + 1, m, count);
			}
		}
	}
}
//int nQueens(int n) {
//	// write code here
//	vector<int> map(n);
//	int count;
//	int row;
//	count = 0;
//	row = 0;
//	queen(n, row, map, count);
//	return count;
//}
void testnQueens()
{
	int n = 0;
	while (true){
		cout << "请输入n:";
		cin >> n;
		cout << "n皇后问题的摆放方法：" << nQueens(n) << endl;
	}
}
//非递归实现 n 皇后问题
#define MAXQUEEN 20
int a[MAXQUEEN];
//判断第 k 行的 a[k]列是否能放皇后 
bool find(int k){
	for (int i = 1; i < k; ++i){
		if (a[i] == a[k] || (a[i] - a[k] == k - i) || (a[i] - a[k] == i - k)){
			return false;
		}
	}
	return true;
}
void show(const int n,const int count){
	cout << "The " << count << " Ways to place " << n << " Queens." << endl;
	for (int i = 1; i <= n; ++i){
		cout << "Row " << i  << " place at " << a[i] << endl;
	}
}
int nQueens(int n){
	int k = 1, count = 0;
	a[k] = 1;//一维数组存储棋盘，第 i 个元素的值代表第 i 行的皇后位置（从 1 开始）
	while (k > 0){
		
		if (k <= n && a[k] <= n){//从第 k 行的第一列开始，为后边行的皇后确定位置
			if (!find(k)){//判断 k 行的 a[k] 列是否能放置皇后
				++a[k];//k 行的 a[k]列不能放皇后，继续下一行 a[k]+1的探测
			}
			else{
				++k;// k 行位置已经确定，继续寻找第 k + 1 行
				a[k] = 1;//从第 k+1 行的第一列开始查找
			}
		}
		else{//已经到达最后一行或者最后一列
			if (k > n){//到达最后一行且满足条件  ？？？这一步有问题？？？
				count++;//解法计数
				//show(n, count);//输出该解法
			}
			//如果k>num会执行下面两行代码，因为虽然找到了N皇后问题的一个解，但是要找的是所有解，需要回溯，从当前放置皇后的下一列继续探测  
			//如果a[k]>num也会执行下面两行代码，就是说在当前行没有找到可以放置皇后的位置，于是回溯，从上一行皇后位置的下一列继续探测  
			--k;//位置不符合要求，回退一步
			++a[k];//继续试探下一列位置
		}
	}
	return count;
}

// sum用来记录皇后放置成功的不同布局数；upperlim用来标记所有列都已经放置好了皇后。  
// long sum = 0, upperlim = 1;
/*
** 目前最快的N皇后递归解决方法
** N Queens Problem
** 试探-回溯算法，递归实现，利用位运算来判断是否能放置皇后

void nQueens_BIT(int row, int ld, int rd)
{
	int pos, p;
	if (row != upperlim)
	{
		pos = upperlim & (~(row | ld | rd));
		while (pos)
		{
			p = pos & (~pos + 1);
			pos = pos - p;
			nQueens_BIT(row | p, (ld | p) << 1, (rd | p) >> 1);
		}
	}
	else
		++Ans;
}*/
/*题目描述
有一堆箱子，每个箱子宽为wi，长为di，高为hi，现在需要将箱子都堆起来，而且为了使堆起来的箱子不到，上面的箱子的宽度和长度必须小于下面的箱子。
请实现一个方法，求出能堆出的最高的高度，这里的高度即堆起来的所有箱子的高度之和。
给定三个int数组w,l,h，分别表示每个箱子宽、长和高，同时给定箱子的数目n。请返回能堆成的最高的高度。保证n小于等于500。
测试样例：[1,1,1],[1,1,1],[1,1,1]     返回：1
 *思路：采用动态规划算法，从最后一个箱子开始选：满足长，宽最短，且高最大的箱子，它下面的箱子长和宽都比它大且高度最大的箱子。
 *

int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
	// write code here
	if (n <= 0)
		return 0;
	int maxh, wi, li, hi;
	maxh = (int)(max_element(h.begin(), h.end()) - h.begin());
	wi = w[maxh];
	li = l[maxh];
	hi = h[maxh];
	cout << "The top box is :" << wi << " " << li << " " << hi << endl;
	vector<int> nw, nl, nh;
	int next_n = 0;
	for (int j = 0; j < n; ++j){
		if (w[j] > wi && l[j] > li){
			nw.push_back(w[j]);
			nl.push_back(l[j]);
			nh.push_back(h[j]);
			++next_n;
		}
	}
	return hi + getHeight(nw, nl, nh, next_n);
}
 */

int f[501] = { 0 };

int getHeight(vector<int> w, vector<int> l, vector<int> h, int n)
{
	//对初始参数按照宽度进行降序排序，冒泡排序
	for (int i = n - 1; i > 0; --i){
		for (int j = n - 1; j > n - 1 - i; --j){
			if (w[j] > w[j - 1]){
				swap(w[j], w[j - 1]);
				swap(l[j], l[j - 1]);
				swap(h[j], h[j - 1]);
			}
		}
	}
	//打印
	for (int i = 0; i < n; ++i){
		cout << w[i] << " " << l[i] << " " << h[i] << endl;
	}
	//从0开始，根据长度求最大严格上升子序列，来求得满足要求的第i个箱子
	//i从0到n ,一次性求出i个箱子堆的最大高度 = 前i-1个箱子堆的最大高度 + 箱子 i 的最大高度
	//动态规划 ，其中 f[n] 表示前 n 个箱子可以堆的最大高度
	f[0] = h[0];//1个箱子堆的最大高度。
	int maxn = f[0]; //当前最大高度
	//加入第i个箱子，求前i个箱子堆最大高度
	for (int i = 1; i < n; ++i){
		f[i] = h[i]; //第 i 个箱子的高度
		int tmax = 0; //临时高度和
		//j 从 i-1到0 ,求满足长度条件的最大严格上升子序列中的前i个箱子中的最大高度。
		for (int j = i - 1; j >= 0; --j){
			//满足条件的箱子堆
			if (w[i] < w[j] && l[i] < l[j]){
				tmax = max(tmax, f[j]);//取增加一个箱子和不增加两种情况的最大高度值。
			}
		}
		f[i] += tmax; //求出前 i 个箱子堆最大高度
		maxn = max(maxn, f[i]); //取前i-1个箱子和 前i个箱子堆二者较大高度
	}
	return maxn;
}

void testgetHeight()
{
	vector<int> w, l, h;
	int n = 4;
	for (int i = 0; i < n; ++i){
		w.push_back(i+1);
		l.push_back(i+1);
		h.push_back(i+1);
	}
	cout << "The hight of the box:" << getHeight(w, l, h, n) << endl;
}
/*题目描述
约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。
然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。
给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
测试样例：5 3   返回：4
思路：方法一：采用无头结点循环链表构造约瑟夫环，进行取到 m 删除即可
 */

int getResult(int n, int m) {
	// write code here
	JosephNode * s = new JosephNode(1);
	JosephNode * tail = new JosephNode(n);
	tail->next = s;
	for (int i = 2; i < n ; ++i){
		JosephNode * jtemp = new JosephNode(i);
		s->next = jtemp;
		s = jtemp;
	}
	s->next = tail;

	JosephNode * p = tail->next;
	int j = 1;
	while (j < n){		
		for (int i = 1; i < m; ++i){
			s = p;
			p = p->next;
		}
		s->next = p->next;		
		tail = p;
		p = s->next;
		cout << j << ":" << tail->jsp << endl;
		free(tail);
		j++;
	}
	int result = p->jsp;
	free(p);
	return result;
}

void testJoseph()
{
	int n, m;
	while (true){
		cout << "Please input n and m(<=1000):";
		cin >> n >> m;
		cout << "The result of JosephCiru:" << getResult(n, m) << endl;
	}
}

/*题目描述
约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。有n个人站成一列。并从头到尾给他们编号，
第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。
接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。
以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。
给定一个int n，代表游戏的人数。请返回最后一个人的编号
测试样例：5   返回：5
思路：首先要建立一个链表，每次报数后值留下编号为 1 的人，每次等间隔删除且删除人数递增 1。

其实这个题用vector<int>来做是非常方便，链表这些太复杂了，下面是思路：
1、数组joseph为[1,n]，每次循环就用一个局部变量tmp来存放保留的元素；
2、将tmp的最后一个元素插入到tmp的头，再将最后一个元素删除；
3、将tmp与joseph交换。
 */

//int getResult(int n) {
//	// write code here
//	JosephNode * head = new JosephNode(1);
//	JosephNode * p = head;
//	for (int i = 2; i <= n; ++i){
//		JosephNode * tail = new JosephNode(i);
//		p->next = tail;
//		p = tail;
//	}
//	p->next = head;
//	//定义头和尾，每次结束后，头是上一次最后一个编号1，尾是倒数第二个编号1.用head 和 tail 保存，利用单链表反复进行删除。
//	JosephNode * s = head;
//	JosephNode * tail = p;
//	int count = 1;
//	int len = n;
//	while (len > 1){
//		//每次遍历删除编号为 1-j的节点。
//		while (s != p)
//		{
//			JosephNode * temp = s->next;
//			for (int i = 0; i < count ; ++i){
//				--len;
//				cout << i << "Delete :" << temp->jsp << endl;
//				if (temp == p){//当删除到尾时，特殊处理尾部并提前结束删除
//					s->next = p->next;
//					p = p->next;
//					free(temp);
//					break;
//				}
//				s->next = temp->next;
//				free(temp);
//				temp = s->next;
//			}
//			tail = head;
//			s = s->next;
//			head = s;
//		}
//		s = head;
//		p = tail;
//		++count;
//	}
//	int result = s->jsp;
//	free(s);
//	return result;
//}

int getResult(int n){
	vector<int> joseph;
	for (int i = 1; i <= n; ++i){
		joseph.push_back(i);	//生成joseph数组
	}
	int m = 2; //起始间隔
	while (joseph.size() != 1){
		vector<int> temp;
		temp.push_back(0); //先放一个元素，避免第2步头插数组整体后移
		for (size_t i = 1; i <= joseph.size(); i += m){
			temp.push_back(joseph[i - 1]);	//把需要保留的元素存入temp
		}
		temp[0] = temp.back(); //将尾放在头
		temp.erase(temp.end() - 1); //删除尾元素
		joseph.swap(temp);//交换数组
		++m;//间隔加1
	}
	return joseph.back();//返回唯一元素
}

void testJosephUP()
{
	int n;
	while (true){
		cout << "Please input the n: ";
		cin >> n;
		cout << "The Joseph Upgrad result is:" << getResult(n) << endl;
	}
}

/*题目描述
请编写一个方法，对一个字符串数组进行排序，将所有变位词合并，保留其字典序最小的一个串。
这里的变位词指变换其字母顺序所构成的新的词或短语。例如"triangle"和"integral"就是变位词。
给定一个string的数组str和数组大小int n，请返回排序合并后的数组。保证字符串串长小于等于20，数组大小小于等于300。
测试样例：["ab","ba","abc","cba"]  返回：["ab","abc"]
思路：
*/

bool IsAnag(string str1, string str2){
	if (str1.length() != str2.length())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	if (str1 == str2)
		return true;
	else
		return false;
}

vector<string> sortStrings(vector<string> str, int n) {
	// write code here
	sort(str.begin(), str.end());
	vector<string> result;
	result.push_back(str[0]);
	for (int i = 1; i < n; ++i){
		string str2 = str[i];
		bool isanag = false;
		/*for each (string var in result)
		{
			if (IsAnag(var, str2)){
				isanag = true;
				break;
			}
		}*/

		for (size_t j = 0; j < result.size(); ++j){
			if (IsAnag(result[j], str2)){
				isanag = true;
				break;
			}
		}
		if (!isanag)
			result.push_back(str2);
	}
	return result;
}

void testsortStrings()
{
	vector<string> str;
	str.push_back("ab");
	str.push_back("ba");
	str.push_back("abc");
	str.push_back("cba");
	str.push_back("Hello");
	str.push_back("olleH");
	int len = str.size();
	vector<string> result = sortStrings(str, len);
	for each (string var in result)
	{
		cout << var << endl;
	}
}

/*题目描述
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],
现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
测试样例：[6,1,2,3,4,5],6,6        返回：0
思路：二分查找，中间有一个突变点，导致left 和 right 是两个相邻的数。
	分两种情况
 */
int findElement(vector<int> A, int n, int x) {
	// write code here
	if (n < 1)
		return -1;
	int left = 0, right = n -1;
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (A[mid] == x)return mid;
		if (x > A[mid]){
			if (x > A[right] && A[mid] < A[left])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else{
			if (x<A[left] && A[mid] > A[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}

void testfindElement()
{
	vector<int> input = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
		30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
		55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int result = findElement(input, 80, 6);
	cout << "Find Element 5 in:" << result << " "<<input[result]<< endl;
}
/*题目描述
有一个排过序的字符串数组，但是其中有插入了一些空字符串，请设计一个算法，找出给定字符串的位置。算法的查找部分的复杂度应该为log级别。
给定一个string数组str,同时给定数组大小n和需要查找的string x，请返回该串的位置(位置从零开始)。
测试样例：["a","b","","c","","d"],6,"c"返回：3
思路：
 */
int findString(vector<string> str, int n, string x) {
	// write code here
	if (n < 1)
		return -1;
	int left = 0, right = n - 1;
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (str[mid] == x)return mid;
		if (str[mid] != ""){
			if (x > str[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else{
			int indexleft = mid - 1;
			while (str[indexleft] == "" && indexleft > left )
				--indexleft;

			int indexright = mid + 1;
			while (str[indexright] == "" && indexright < right )
				++indexright;

			if (x <= str[indexleft])
				right = indexleft;
			else if(x >= str[indexright])
				left = indexright;	
		}
	}
	return -1;
}

void testfindString()
{
	vector<string> str = { "a", "b", "", "", "", "c", "", "", "", "d" };
	int result = findString(str, 10, "c");
	cout << "The string is in: " << result << " " << str[result] << endl;
}

/*有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。请设计一个高效的查找算法，查找矩阵中元素x的位置。
给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，请返回一个二元数组，代表该元素的行号和列号(均从零开始)。保证元素互异。
测试样例：[[1,2,3],[4,5,6]],2,3,6 返回：[1,2]
思路：链接：https://www.nowcoder.com/questionTerminal/3afe6fabdb2c46ed98f06cfd9a20f2ce
来源：牛客网

从右上角开始，每次将搜索值与右上角的值比较，如果大于右上角的值，则直接去除1行，否则，则去掉1列。如下图显示了查找13的轨迹。
首先与右上角15比较，13<15，所以去掉最右1列，然后与11比较，这是13>11，去掉最上面1行…以此类推，最后找到13。算法复杂度O(n)，
最坏情况需要2n步，即从右上角开始查找，而要查找的目标值在左下角的时候。

*/
vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
	// write code here
	vector<int> result;
	result.push_back(-1); 
	result.push_back(-1);
	if (n == 0 || m == 0)
		return result;

	int i = 0, j = m - 1;
	while (i < n && j >= 0){
		if (x < mat[i][j]){
			--j;
		}
		else if (x > mat[i][j]){
			++i;
		}
		else{
			result[0] = i;
			result[1] = j;
			return result;
		}
	}
	return result;
}

void testfindElementMat()
{
	vector<vector<int>> mat = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vector<int> result = findElement(mat, 3, 3, 6);
	cout << "The findElement is in: [" << result[0] << "," << result[1] << "]" << endl;
}
/*叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。同时我们应该让下面的人比上面的人更高一点。
已知参加游戏的每个人的身高，请编写代码计算通过选择参与游戏的人，我们多能叠多少个人。注意这里的人都是先后到的，
意味着参加游戏的人的先后顺序与原序列中的顺序应该一致。
给定一个int数组men，代表依次来的每个人的身高。同时给定总人数n，请返回最多能叠的人数。保证n小于等于500。
测试样例：[1,6,2,5,3,4],6返回：4(即1,2,3,4)
*/
#define DEBUG
int getHeight(vector<int> men, int n) {
	// write code here
	int dp[501] = { 0 };
	int maxn = 0;
	for (int i = 0; i < n; ++i){
		dp[i] = 1;
		for (int j = 0; j < i; ++j){
			if (men[j] < men[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > maxn)
			maxn = dp[i];
	}
#ifdef DEBUG
	for (int i = 0; i < n; ++i){
		cout << dp[i] << " ";
	}
#endif
	return maxn;
}

int getHeightV2(vector<int> men, int n)
{
//	int dp[501] = { 1 };
	int top[501] = { 1 };
	
	top[0] = men[0];
	int len = 0;
	for (int i = 1; i < n; ++i){
		if (men[i] > top[len])
			top[++len] = men[i];
		else{
			int j = std::lower_bound(top, top + len + 1, men[i]) - top;
			top[j] = men[i];
		}
	}
	
#ifdef DEBUG
	for (int i = 0; i <= len; ++i){
		cout << top[i] << " ";
	}
#endif
	return len+1;
}

void testgetHeightV2()
{
	vector<int> men = { 1, 6, 2, 5, 3, 4 };
//	int result = getHeight(men, 6);
	int result = getHeightV2(men, 6);
	cout << "The Longest Increasing Subsequence is:" << result << endl;
	return;
}

/*题目描述
叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。为了使叠成的罗汉更稳固，我们应该让上面的人比下面的人更轻一点。
现在一个马戏团要表演这个节目，为了视觉效果，我们还要求下面的人的身高比上面的人高。请编写一个算法，计算最多能叠多少人，注意这里所有演员都同时出现。
给定一个二维int的数组actors，每个元素有两个值，分别代表一个演员的身高和体重。同时给定演员总数n，请返回最多能叠的人数。保证总人数小于等于500。
测试样例：[[1,2],[3,4],[5,6],[7,8]],4 返回：4
思路：与堆箱子问题同理，按照高度或者宽度进行排序，然后找剩下一个属性的最长上升子序列。
*/
int getHeight(vector<vector<int> > actors, int n) {
	// write code here
	sort(actors.begin(), actors.end());
	int dp[501] = { 1 };
	int maxn = 0;
	for (int i = 0; i < n; ++i){
		dp[i] = 1;
		for (int j = 0; j < i; ++j){
			if (actors[i][1] > actors[j][1] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > maxn)
			maxn = dp[i];
	}
	return maxn;
}

int getHeightII(vector<vector<int>> actors, int n)
{
	sort(actors.begin(), actors.end());
	int top[501] = { 0 };
	int len = 0;
	top[0] = actors[0][1];
	for (int i = 1; i < n; ++i){
		if (actors[i][1] > top[len])
			top[++len] = actors[i][1];
		else{
			int j = lower_bound(top, top + len + 1, actors[i][1]) - top;
			top[j] = actors[i][1];
		}
	}
	return len + 1;
}

void testgetHeightVII()
{
	vector<vector<int>> actor = {
		{ 1, 2 },
		
		{ 5, 6 },
		{ 7, 8 },
		{ 3, 4 },
	};
	//int result = getHeight(actor, 4);
	int result = getHeightII(actor, 4);
	cout << "The result is :" << result << endl;
}

/*题目描述
现在我们要读入一串数，同时要求在读入每个数的时候算出它的秩，即在当前数组中小于等于它的数的个数(不包括它自身)，请设计一个高效的数据结构和算法来实现这个功能。
给定一个int数组A，同时给定它的大小n，请返回一个int数组，元素为每次加入的数的秩。保证数组大小小于等于5000。
测试样例：[1,2,3,4,5,6,7],7  返回：[0,1,2,3,4,5,6]
思路：
*/
vector<int> getRankOfNumber(vector<int> A, int n) {
	// write code here
	vector<int> result(n);
	
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (A[j] <= A[i]){
				++result[i];
			}
		}
	}
	return result;
}

/*
用一个二叉查找树来维护当前已经插入的数组，小于等于该节点插入左子树内，
大于插入右子树内，递归调用。
这样，每次查询小于等于某个节点的节点数，分三种情况讨论，递归调用：
1.当前节点的值等于插入的节点的值，那么返回该节点的左子树数目就等于秩
2.当前节点的值大于插入的节点的值，那么递归调用左子树（因为该节点的本身
及其右子树都对秩没影响)
3.当前节点的值小于插入的节点的值，那么当前节点的所有左子树加上本身都是
该插入节点的秩，
然后加上插入的节点在右子树中的秩之和为改插入节点的秩
 
 注意：1.只用记录当前节点的左子树的个数，2.每次都是先插再找出秩，所以每
 次查找不会出现不在树中的情况。
 */
//就是高票答案的思路，不过用了现成的库，multiset 底层实现就是一颗红黑树，通过封装好的迭代器，可以轻松算出左边有多少节点
vector<int> getRankOfNumberV2(vector<int> A, int n)
{
	vector<int> result;
	multiset<int> set;
	multiset<int>::iterator iter;

	for (int i = 0; i < n; ++i){
		set.insert(A[i]);
		iter = set.upper_bound(A[i]);
		int len = 0;
		multiset<int>::iterator cur = set.begin();
		while(cur != iter){
			len++;
			cur++;
		}
		result.push_back(len - 1);
	}

	return result;
}
void testgetRankOfNumber()
{
	vector<int> A = { 8, 1, 9, 4, 5, 6, 7 };
//	vector<int> result = getRankOfNumber(A, A.size());
	vector<int> result = getRankOfNumberV2(A, A.size());
	for (size_t i = 0; i < result.size(); ++i){
		cout << result[i] << " ";
	}
	return;
}
/*题目描述
有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。请设计一个高效的算法，计算给定数组中的逆序对个数。
给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。
测试样例：[1,2,3,4,5,6,7,0],8  返回：7
*/
int count(vector<int> A, int n) {
	// write code here
	int result = 0;
	for (int i = 0; i < n - 1; ++i){
		for (int j = i+1; j < n; ++j){
			if (A[i] > A[j])
				++result;
		}
	}
	return result;
}
int countV2(vector<int> A, int n)
{
	int result = 0;
	multiset<int> mset;
	multiset<int>::iterator iter,cur;

	for (int i = 0; i < n; ++i){
		mset.insert(A[i]);
		//iter = lower_bound(mset.begin(), mset.end(), A[i]);
		iter = mset.upper_bound(A[i]);
		int len = 0;
		cur = mset.begin();
		while (cur != iter){
			++cur;
			++len;
		}
		int revers_pair = mset.size() - len;
		result += revers_pair;
	}
	return result;
}

void testcount()
{
	vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 0 };
	//int result = count(a, a.size());
	int result = countV2(a, a.size());
	cout << "The result is :" << result << endl;
}
/*题目描述
请编写一个函数，函数内不使用任何临时变量，直接交换两个数的值。
给定一个int数组AB，其第零个元素和第一个元素为待交换的值，请返回交换后的数组。
测试样例：[1,2]  返回：[2,1]
思路：采用加减法，乘除法，按位异或法都可以，但是前两种可能存在溢出，
	首推按位异或
*/
vector<int> exchangeAB(vector<int> AB) {
	// write code here
	//AB[0] = AB[0] + AB[0] + AB[1];
	//AB[1] = (AB[0] - AB[1]);
	//AB[0] = AB[0] - AB[1];
	//AB[1] /= 2;
	AB[0] = AB[0] + AB[1];
	AB[1] = AB[0] - AB[1];
	AB[0] = AB[0] - AB[1];
	return AB;
}
/*
如果采用位运算来交换两个元素，则最可能使用的是位异或运算。
如果是位与，一个数的0就会覆盖掉另一个数的0或者1，信息丢失。
如果是位或，一个数的1就会覆盖掉另一个数的0或者1.
而采用位异或，1表明两个位置不同，0表示相同。*/
vector<int> exchangeABII(vector<int> AB) {
	// write code here
	AB[0] = AB[0] ^ AB[1];
	AB[1] = AB[0] ^ AB[1];
	AB[0] = AB[0] ^ AB[1];

	return AB;
}
void testexchangeAB()
{
	vector<int> a = { 1, 2 };
	vector<int> result = exchangeAB(a);
	//vector<int> result = exchangeABII(a);
	for (size_t i = 0; i < result.size(); ++i)
		cout << result.at(i)<<" ";
	return;
}
/*题目描述
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
测试样例：[[1,0,1],[1,-1,-1],[1,-1,0]]返回：true
思路：数组是否存在任意相连的3个1
*/
bool checkWon(vector<vector<int> > board) {
	// write code here
	for (int i = 0; i < 3; ++i){
		if ((board[i][0] + board[i][1] + board[i][2]) == 3)
			return true;
		if ((board[0][i] + board[1][i] + board[2][i]) == 3)
			return true;
	}
	if ((board[0][0] + board[1][1] + board[2][2]) == 3)
		return true;
	if ((board[0][2] + board[1][1] + board[2][0]) == 3)
		return true;
	return false;
}

void testcheckWon()
{
	vector<vector<int>> jing = {
		{ 1, 0, 1 },
		{ 1, -1, -1 },
		{ 1, -1, 0 }
	};
	bool result = checkWon(jing);
	cout << "The checkWon:" << result << endl;
}
/*题目描述
请编写一个方法，找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：1，2  返回：2
思路：  # (a - b) >> 31 为 0， 说明 a - b 最高位为0，即a >=b
        # (a - b) >> 31 为 -1, 说明 a - b 最高位为1， 即 a < b
*/
int getMax(int a, int b) {
	// write code here
	//return max(a, b);
	b = a - b;
	a -= b&(b >> 31);
	return a;
}
void testgetMax()
{
	int a = 1, b = 2;
	int result = getMax(a, b);
	cout << "The getMax:" << result << endl;
}
/*题目描述
我们现在有四个槽，每个槽放一个球，颜色可能是红色(R)、黄色(Y)、绿色(G)或蓝色(B)。例如，可能的情况为RGGB(槽1为红色，槽2、3为绿色，槽4为蓝色)，
作为玩家，你需要试图猜出颜色的组合。比如，你可能猜YRGB。要是你猜对了某个槽的颜色，则算一次“猜中”。要是只是猜对了颜色但槽位猜错了，则算一次“伪猜中”。注意，“猜中”不能算入“伪猜中”。
给定两个string A和guess。分别表示颜色组合，和一个猜测。请返回一个int数组，第一个元素为猜中的次数，第二个元素为伪猜中的次数。
测试样例："RGBY","GGRR"   返回：[1,1]
思路：按照槽位统计，先删除猜中的，剩下的就是伪猜中和未中的。
*/
vector<int> calcResult(string A, string guess) {
	// write code here
	vector<int> result(2,0);
	int rygb[2][4] = { 0 };
	int cz = 0, wcz = 0;
	for (int i = 0; i < 4; ++i){
		if (A[i] == guess[i])
			++cz;
		switch (A[i])
		{
		case 'R':
			++rygb[0][0];
			break;
		case 'Y':
			++rygb[0][1];
			break;
		case 'G':
			++rygb[0][2];
			break;
		case 'B':
			++rygb[0][3];
			break;
		default:
			break;
		}
		switch (guess[i])
		{
		case 'R':
			++rygb[1][0];
			break;
		case 'Y':
			++rygb[1][1];
			break;
		case 'G':
			++rygb[1][2];
			break;
		case 'B':
			++rygb[1][3];
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < 4; ++i){
		wcz += min(rygb[0][i], rygb[1][i]);
	}
	wcz -= cz;
	result[0] = cz;
	result[1] = wcz;
	return result;
}

void testcalcResult()
{
	string A= "RGBY";
	string Guss = "GGRR";
	vector<int> result = calcResult(A, Guss);
	cout << "The Right Guss is:" << result[0] << " and the Fake Guss is:" << result[1] << endl;
}
/*题目描述
请设计一个算法，计算n的阶乘有多少个尾随零。
给定一个int n，请返回n的阶乘的尾零个数。保证n为正整数。
测试样例：5   返回：1
思路：
*/
int getFactorSuffixZero(int n) {
	// write code here
	long fac = 1;
	for (int i = 2; i <= n; ++i)
		fac *= i;
	int result = 0;
	while (fac % 10 == 0){
		fac /= 10;
		++result;
	}
	return result;
}
/*
 * 思路：刚开始做这道题的时候，我是先求出n！再计算有多少个0
  * 这样的复杂度很大，编译不通过，后来在编程之美中看到了思路，思路如下
   *   n!可以质因数分解，由于2*5=10，所以尾零的个数只与2和5有关
    *   但是能被2整除的频率比被5整除的数高的多，所以尾零的个数其实只和5相关，
	 *   n！能被多少个5解，就有多少个0，
	  *   这事，通过遍历（1到n)只要将能被5整除，就统计+1，最后统计的数，就是尾零的个数
	   *
	    */
int getFactorSuffixZeroV2(int n)
{
	int result = 0;
	for (int i = 1; i <= n; ++i){
		int j = i;
		while (j % 5 == 0){
			++result;
			j /= 5;
		}
	}
	return result;
}
void testgetFact()
{
	int n, result;
	
	do{
		cout << "Please input a num (<0queit):";
		cin >> n;
		//result = getFactorSuffixZero(n);
		result = getFactorSuffixZeroV2(n);
		cout << "The 0 tail is:" << result << endl;
	} while (n > 0);
}