#pragma once

#include <iostream>
#include <string>
using namespace std;
class BSTtree
{
public:
	string data;
	BSTtree * lchild;
	BSTtree * rchild;
	BSTtree (string val="#"):data(val),lchild(nullptr),rchild(nullptr){}
};

typedef BSTtree* BSTPtr;

BSTPtr InitBSTtree();


bool SearchBSTtree(BSTPtr T, string val, BSTPtr  Pre, BSTPtr & recordPre);

void ListBSTtree(BSTPtr T);

void DeleteBSTtree(BSTPtr T, string val);

void Deleterecord(BSTPtr &T);

