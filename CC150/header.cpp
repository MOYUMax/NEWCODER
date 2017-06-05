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
	int sum = 0;
	vector<int> Path;
	vector<vector<int>> AllPath;
	if (root != nullptr){
		LeftPath(root, sum, expectNumber, Path, AllPath);
		RightPath(root, sum, expectNumber, Path, AllPath);
	}
	return AllPath;
}
void LeftPath(TreeNode * L,int sum ,const int expectNumber,vector<int> path,vector<vector<int>> & Allpath)
{
	if (L == nullptr)
		return;
	sum += L->val;
	if (sum > expectNumber)
		return;
	path.push_back(L->val);
	TreeNode * lc = L->left;
	TreeNode * rc = L->right;
	if (lc == nullptr && rc == nullptr){
		if (sum == expectNumber){
			Allpath.push_back(path);
		}
	}
	LeftPath(lc, sum, expectNumber, path, Allpath);
	RightPath(rc, sum, expectNumber, path, Allpath);
}
void RightPath(TreeNode * R, int & sum, const int expectNumber, vector<int> & path, vector<vector<int>> & Allpath)
{
	if (R == nullptr)
		return;
	sum += R->val;
	if (sum > expectNumber)
		return;
	path.push_back(R->val);
	TreeNode * lc = R->left;
	TreeNode * rc = R->right;
	if (lc == nullptr && rc == nullptr){
		if (sum == expectNumber){
			Allpath.push_back(path);
		}
	}
	LeftPath(lc, sum, expectNumber, path, Allpath);
	RightPath(rc, sum, expectNumber, path, Allpath);
}
void testFindPath()
{
	int a[14] = { 0,1, 2, 3, 4, 5, 6, 7, 2, 1, 0, 1, 5, 0 };
	TreeNode * root;
	CreateTree(root, a, 1 , 13);
	vector<vector<int>> vv_i = FindPath(root, 10);
	cin.get();
}