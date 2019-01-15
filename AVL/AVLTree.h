#pragma once

#include <iostream>
#include <string>
#include <queue>
using namespace std;
class AVLtree
{
public:
	string data;
	int height;
	AVLtree * lchild;
	AVLtree * rchild;
	AVLtree(string val):data(val),height(1),lchild(nullptr),rchild(nullptr){}
};

typedef AVLtree * AVLtreePtr;

inline int MaxHeight(int a, int b)
{
	return a >= b ? a : b;
}

int GetAVLtreeHeight(AVLtreePtr T);

void ViewAVLtree(AVLtreePtr T);

bool InsertAVLtree(AVLtreePtr &T, string val);

bool DeleteAVLtree(AVLtreePtr &T, string val);

AVLtreePtr InitAVLtree();

void FreeAVLtree(AVLtreePtr &root);

void LeftRotate(AVLtreePtr &T);

void RightRotate(AVLtreePtr &T);

string FindNext(AVLtreePtr T);

void inverse(AVLtreePtr T);