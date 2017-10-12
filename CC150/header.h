#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
#include <array>
#include <set>

using namespace std;

bool checkDifferent(string iniString);
bool checkDifferent2(string iniStr);
void testcheckDifferent();
string reverseString(string iniString);
void testveverseString();
bool checkSam(string stringA, string stringB);
void testcheckSam();
string replaceSpace(string iniString, int length);
void testreplaceSpace();
string zipString(string iniString);
void testzipString();
vector<vector<int> > transformImage(vector<vector<int> > mat, int n);
void testtrans();
vector<vector<int>> clearZero(vector<vector<int>> mat, int n);
void testclearZero();
bool checkReverseEqual(string s1, string s2);
void testcheckReverseEqual();
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
void testFindKthToTail();
ListNode* partition(ListNode* pHead, int x);
void testPartition();
ListNode* plusAB(ListNode* a, ListNode* b);
void testplusAB();
bool isPalindrome(ListNode* pHead);
void testisPalindrome();
bool IsListLoop(ListNode * pHead);
ListNode * FindLoopEntry(ListNode * pHead);
void testFindLoopEntry();
vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size);
void testsetOfStacks();
vector<int> twoStacksSort(vector<int> numbers);
void testtwoStacksSort();
vector<int> asylum(vector<vector<int> > ope);
void testasylum();
//Binary Tree Node Structure Defination
struct TreeNode{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
bool isBalance(TreeNode* root);
int Depth(TreeNode * root);
void CreateTree(TreeNode * & root, int a[], int i, int n);
void testisBalance();

void InsertBST(TreeNode * & root, TreeNode * s);

void testbuildMinimalBST();
//AVL Tree
#define LH +1
#define EH 0
#define RH -1
struct AVLTrNode{
	int val;
	int bf;
	struct AVLTrNode * left;
	struct AVLTrNode * right;
	AVLTrNode(int x) :val(x), bf(0), left(nullptr), right(nullptr){}
};
void L_Rotate(AVLTrNode * & p);
void R_Rotate(AVLTrNode * & p);
void LeftBalance(AVLTrNode * & T);
void RightBalance(AVLTrNode * & T);
int Depth(AVLTrNode * root);
bool InsertAVL(AVLTrNode * & root, int s, bool & taller);
int buildMinimalBST(vector<int> vals);
struct UndirectedGraphNode {
	int label;
	vector<struct UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};
bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b);
void testcheckpath();
bool check(UndirectedGraphNode* a, UndirectedGraphNode* b);
ListNode* getTreeLevel(TreeNode* root, int dep);
void create(TreeNode * root, int i);
void testgetTreeLevel();
bool checkBST(TreeNode* root);
TreeNode * searchBST(TreeNode * root, int key);
void insertBST(TreeNode * & root, TreeNode * s);
void testcheckBST();
bool leftcheck(TreeNode * L, TreeNode * F);
bool rightcheck(TreeNode * R, TreeNode * F);
int findSucc(TreeNode* root, int p);
void InOrder(TreeNode * R, vector<int> & vi);
void testfindSucc();
int getLCA(int a, int b);
void testgetLCA();
vector<vector<int> > FindPath(TreeNode* root, int expectNumber);
//void PreOrderPath(TreeNode * R, int & sum, const int expectNumber, vector<int> & path, vector<vector<int>> & Allpath);
void testFindPath();
void DFSFindPath(TreeNode * root, int rest, vector<vector<int>> & path, vector<int> & ret);
int binInsert(int n, int m, int j, int i);
void testbinInsert();
string printBin(double num);
void testprintBin();
vector<int> getCloseNumber(int x);
int getNext(int n);
int getPrev(int n);
void testgetCloseNumber();
int calcCost(int A, int B);
void testcalcCost();
int exchangeOddEven(int x);
void testexchangeOddEven();
int findMissing(vector<vector<int> > numbers, int n);
void testfindMissing();
struct Point {
	int x;
	int y;
	Point() :
		x(0), y(0) {
	}
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	}
};
void testgetLine();
int findKth(int k);
void testfindKth();
int countWays(int n);
void testcountWays();

int countWays(int x, int y);
void testcountWays2();
int countWays(vector<vector<int> > map, int x, int y);
void testcountWays3();
bool findMagicIndex(vector<int> A, int n);
void testfindMagicIndex();
bool MagicNumber(vector<int> A, int start, int end);
bool findMagicIndexII(vector<int> A, int n);
vector<vector<int> > getSubsets(vector<int> A, int n);
void testgetSubsets();
vector<string> getPermutation(string A);
void Permutation(vector<string> & vs, string A, int start, int end);
void testgetPermutation();
bool chkParenthesis(string A, int n);
void testchkParenthesis();
int countWaysC(int n);
void testcountWays4();
bool check_place(int row, int col, vector<int> & m, int n);
void print_result(const vector<int> & m, const int count, const int n);
void queen(const int n, int row, vector<int> & m, int & count);
int nQueens(int n);
void testnQueens();
int getHeight(vector<int> w, vector<int> l, vector<int> h, int n);
void testgetHeight();

struct JosephNode{
	int jsp;
	JosephNode * next;
	JosephNode(int j) :jsp(j), next(nullptr){}
};
int getResult(int n, int m);
void testJoseph();
int getResult(int n);
void testJosephUP();
vector<string> sortStrings(vector<string> str, int n);
void testsortStrings();
int findElement(vector<int> A, int n, int x);
void testfindElement();
int findString(vector<string> str, int n, string x);
void testfindString();
vector<int> findElement(vector<vector<int> > mat, int n, int m, int x);
void testfindElementMat();
int getHeight(vector<int> men, int n);
void testgetHeightV2();
int getHeight(vector<vector<int> > actors, int n);
void testgetHeightVII();
vector<int> getRankOfNumber(vector<int> A, int n);
void testgetRankOfNumber();
int count(vector<int> A, int n);
void testcount();
#endif