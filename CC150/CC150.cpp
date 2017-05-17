// CC150.cpp : 定义控制台应用程序的入口点。
//本套编程题为CC150（《Cracking the Coding Interview程序员面试金典》）一书配套在线练习，
//共84题，未包含原书150题中8.1-8.10、10.1-10.7、12.1-12.6、13.1-13.10、14.1-14.6、15.1-15.
//7、16.1-16.5等题目（因用在线编程方式不易判定）。官方参考代码链接：https://github.com/gaylemcd/ctci。
//Author MaxWang 2017.05.11
#include "stdafx.h"
#include "header.h"

int _tmain(int argc, _TCHAR* argv[])
{
//	testcheckDifferent();	//1.1
//	testveverseString();	//1.2
//	testcheckSam();			//1.3
//	testreplaceSpace();		//1.4
//	testzipString();		//1.5
//	testtrans();			//1.6
//	testclearZero();		//1.7
//	testcheckReverseEqual();//1.8
//	testFindKthToTail();	//2.2
//	testPartition();		//2.4
//	testplusAB();			//2.5
//	testisPalindrome();		//2.7
	testFindLoopEntry();	//test fast and slow pointer to find Loop Entry
	system("PAUSE");
	return 0;
}

