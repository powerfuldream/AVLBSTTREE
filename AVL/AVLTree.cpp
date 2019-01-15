#include "stdafx.h"
#include "AVLTree.h"

int GetAVLtreeHeight(AVLtreePtr T)
{
	if (!T)
		return 0;
	else
	return T->height;
}


void ViewAVLtree(AVLtreePtr T)
{
	if (T)
	{
		ViewAVLtree(T->lchild);
		cout << "val: "<<T->data << " height: "<<T->height<<" Blance VAL:"<<GetAVLtreeHeight(T->lchild)-GetAVLtreeHeight(T->rchild)<<"\n";
		ViewAVLtree(T->rchild);
	}
}

bool InsertAVLtree(AVLtreePtr &T, string val)
{
	if (!T)
	{
		T = new AVLtree(val);
		return true;
	}
	else
	{
		if (T->data == val)
			return false;
		else if (val < (T->data))
		{
			if (!InsertAVLtree(T->lchild, val))
				return false;
			if (GetAVLtreeHeight(T->lchild) - GetAVLtreeHeight(T->rchild) == 2)
			{
				if (val < (T->lchild->data))
					RightRotate(T);
				else
				{
					LeftRotate(T->lchild);
					RightRotate(T);
				}
				

			}
		}
		else if (val > T->data)
		{
			if (!InsertAVLtree(T->rchild, val))
				return false;
			if (GetAVLtreeHeight(T->rchild) - GetAVLtreeHeight(T->lchild) == 2)
			{
				if (val > (T->rchild->data))
					LeftRotate(T);
				else
				{
					RightRotate(T->rchild);
					LeftRotate(T);
				}


			}
		}

		T->height = MaxHeight(GetAVLtreeHeight(T->lchild), GetAVLtreeHeight(T->rchild)) + 1;
		return true;
	}
		
}

bool DeleteAVLtree(AVLtreePtr & T, string val)
{
	if(!T)
	return false;
	
	if (val == T->data)
	{
		if (!T->rchild)
		{
			AVLtreePtr temp = T;
			T = T->lchild;
			delete temp;
			return true;
		}
		if (!T->lchild)
		{
			AVLtreePtr temp = T;
			T = T->rchild;
			delete temp;
			return true;
		}
		if(T->lchild&&T->rchild)
		{
			string NextMin = FindNext(T->rchild);
			T->data = NextMin;
			DeleteAVLtree(T->rchild, NextMin);
			
			if (GetAVLtreeHeight(T->lchild) - GetAVLtreeHeight(T->rchild) == 2)
			{
				if (GetAVLtreeHeight(T->lchild->lchild) - GetAVLtreeHeight(T->lchild->rchild) >= 0)
					RightRotate(T);
				else
				{
					LeftRotate(T->lchild);
					RightRotate(T);
				}
			}

		}
	}
	else if (val < T->data)
	{
		if (!DeleteAVLtree(T->lchild, val))
			return false;
		if (GetAVLtreeHeight(T->rchild) - GetAVLtreeHeight(T->lchild) == 2)
		{
			if (GetAVLtreeHeight(T->rchild->rchild) - GetAVLtreeHeight(T->rchild->lchild) >= 0)
				LeftRotate(T);
			else
			{
				RightRotate(T->rchild);
				LeftRotate(T);
			}
		}
		
	}
	else if (val > T->data)
	{
		if (!DeleteAVLtree(T->rchild, val))
			return false;
		if (GetAVLtreeHeight(T->lchild) - GetAVLtreeHeight(T->rchild) == 2)
		{
			if (GetAVLtreeHeight(T->lchild->lchild) - GetAVLtreeHeight(T->lchild->rchild) >= 0)
				RightRotate(T);
			else
			{
				LeftRotate(T->lchild);
				RightRotate(T);
			}
		}
	}

	T->height= MaxHeight(GetAVLtreeHeight(T->lchild), GetAVLtreeHeight(T->rchild)) + 1;
	return true;

}

AVLtreePtr InitAVLtree()
{
	AVLtreePtr root = nullptr;
	string val;

	cout << "input tree value,'q' end:\n";
	while (cin >> val&&val != "q")
	{
		InsertAVLtree(root, val);
	}

	return root;
}

void FreeAVLtree(AVLtreePtr& root)
{
	if (root)
	{
		FreeAVLtree(root->lchild);
		FreeAVLtree(root->rchild);
		delete root;
	}
}

void LeftRotate(AVLtreePtr & T)
{
	AVLtreePtr R = T->rchild;
	AVLtreePtr P = T;
	T->rchild = R->lchild;
	R->lchild = T;
	T = R;
	P->height= MaxHeight(GetAVLtreeHeight(P->lchild),GetAVLtreeHeight(P->rchild)) + 1;
	T->height = MaxHeight(GetAVLtreeHeight(T->lchild), GetAVLtreeHeight(T->rchild)) + 1;
}

void RightRotate(AVLtreePtr & T)
{
	AVLtreePtr L = T->lchild;
	AVLtreePtr P = T;
	T->lchild = L->rchild;
	L->rchild = T;
	T = L;
	P->height = MaxHeight(GetAVLtreeHeight(P->lchild), GetAVLtreeHeight(P->rchild)) + 1;
	T->height = MaxHeight(GetAVLtreeHeight(T->lchild), GetAVLtreeHeight(T->rchild)) + 1;
}

string FindNext(AVLtreePtr sn)
{
	if (!sn)
		return NULL;
	
	while (sn->lchild)
	{
		sn = sn->lchild;
	}
	return sn->data;
	
}

void inverse(AVLtreePtr T)
{
	if (!T)
		return;
	else
	{
		queue<AVLtreePtr> q;
		q.push(T);
		while (!q.empty())
		{
			auto tr = q.front();
			q.pop();
			auto node = tr->lchild;
			tr->lchild = tr->rchild;
			tr->rchild = node;
			if (tr->lchild)
				q.push(tr->lchild);
			if (tr->rchild)
				q.push(tr->rchild);
		}
	}
}
