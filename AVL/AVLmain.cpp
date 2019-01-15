// AVL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AVLTree.h"

int main()
{
	AVLtreePtr root = InitAVLtree();
	cout << "output AVLtree\n";
	ViewAVLtree(root);
	cout << "\ndelete val\n";
	string val;
	cin >> val;
	DeleteAVLtree(root,val);
	cout << "after delete\n";
	ViewAVLtree(root);
	cout << "reverse Tree\n";
	inverse(root);
	ViewAVLtree(root);
	FreeAVLtree(root);
	return 0;
}

