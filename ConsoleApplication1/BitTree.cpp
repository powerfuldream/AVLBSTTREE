#include "stdafx.h"
#include "BitTree.h"

BSTPtr InitBSTtree()
{
	BSTPtr root=nullptr;
	BSTPtr recordPre;
	string val;

	cout << "input tree value,'q' end:\n";
	while (cin >> val&&val!="q")
	{
		if (!(SearchBSTtree(root, val,nullptr, recordPre)))
		{
			BSTPtr temp = new BSTtree(val);
			if (!recordPre)
			{
				root = temp;
			}
			else
			{
				if (val < recordPre->data)
					recordPre->lchild = temp;
				else
					recordPre->rchild = temp;
			}
		}
	}
	return root;
}

bool SearchBSTtree(BSTPtr  T, string val,BSTPtr  Pre,BSTPtr & recordPre)
{
	if (!T)
	{
		recordPre = Pre;
		return false;
	}
	else if (val == T->data)
	{
		recordPre = Pre;
		return true;
	}
		

	if (val < T->data)
		return SearchBSTtree(T->lchild, val, T, recordPre);
	else
		return SearchBSTtree(T->rchild, val, T, recordPre);
}

void ListBSTtree(BSTPtr T)
{
	if(T)
	{
		ListBSTtree(T->lchild);
		cout << T->data << " ";
		ListBSTtree(T->rchild);
	}
}


void DeleteBSTtree(BSTPtr T, string val)
{
	BSTPtr recordpre;
	if (SearchBSTtree(T, val, nullptr, recordpre) == false) {
		return;
	}

	else
	{
		if (recordpre->lchild->data == val)
		{
			BSTPtr record = recordpre->lchild;
			Deleterecord(record);
			recordpre->lchild = record;
		}
		else
		{
			BSTPtr record = recordpre->rchild;
			Deleterecord(record);
			recordpre->rchild = record;
		}
	}

}

void Deleterecord(BSTPtr &record) {
	if (record->lchild == nullptr)
	{
		BSTPtr del = record;
		record = record->rchild;
		delete del;
		return;
	}
	else if (record->rchild == nullptr)
	{
		BSTPtr del = record;
		record = record->lchild;
		delete del;
		return;
	}
	else
	{
		BSTPtr sn = record->rchild;
		BSTPtr snPre=nullptr;
		while (sn->lchild)
		{
			snPre = sn;
			sn = sn->lchild;
		}
		record->data = sn->data;
		if (sn == record->rchild)
		{
			record->rchild = sn->rchild;
			delete sn;
		}
		else
		{
			snPre->lchild = sn->rchild;
			delete sn;
		}


	}
}

