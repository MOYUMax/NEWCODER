#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <string>
#include <vector>

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
#endif