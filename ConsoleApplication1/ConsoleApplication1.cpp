// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "BitTree.h"
using namespace std;
int main()
{
	BSTPtr root = InitBSTtree();
	cout << "output BSTtree\n";
	ListBSTtree(root);
	cout << "\ndelete val\n";
	string val;
	cin >> val;
	DeleteBSTtree(root, val);
	cout << "after delete\n ";
	ListBSTtree(root);
	return 0;
}

