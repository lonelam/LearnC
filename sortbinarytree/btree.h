#pragma once
#include<iostream>
using namespace std;
class Node
{
private:
	int data;
	Node * father, *lchild, *rchild;
public:
	Node() :data(0), father(nullptr), lchild(nullptr), rchild(nullptr) {}
	Node(Node * fa ,int dd) :data(dd), father(fa), lchild(nullptr), rchild(nullptr) {}
	Node(int dd) :Node(nullptr, dd) {}
	~Node()
	{
		if (rchild != nullptr)
		{
			delete rchild;
		}
		if (lchild != nullptr)
		{
			delete lchild;
		}
	}
	void insert(int value)
	{
		if (data == value)
		{
			return;
		}
		else if (value > data)
		{
			if (rchild == nullptr)
			{
				rchild = new Node(this,value);
			}
			else
			{
				rchild->insert(value);
			}
		}
		else if (value < data)
		{
			if (lchild == nullptr)
			{
				lchild = new Node(this, value);
			}
			else
			{
				lchild->insert(value);
			}
		}
	}
	Node * search(int value)
	{
		if (data == value)
		{
			return this;
		}
		else if (value > data)
		{
			if (rchild == nullptr)
			{
				return nullptr;
			}
			else
			{
				rchild->search(value);
			}
		}
		else
		{
			if (lchild == nullptr)
			{
				return nullptr;
			}
			else
			{
				lchild->search(value);
			}
		}
	}
	void output()
	{
		cout << data << "(";
		if (lchild == nullptr)
		{
			cout << "#";
		}
		else
		{
			cout << lchild->data;
		}
		cout << ",";
		if (rchild == nullptr)
		{
			cout << "#";

		}
		else
		{
			cout << rchild->data;
		}
		cout << ")" << endl;
	}
	void inorderout()
	{
		if (lchild != nullptr)
		{
			lchild->inorderout();
		}
		output();
		if (rchild != nullptr)
		{
			rchild->inorderout();
		}
	}
};
class binarytree
{
private:
	Node* root;
public:
	binarytree():root(nullptr) {}
	~binarytree()
	{
		if (root != nullptr)
		{
			delete root;
		}
	}
	void insert(int value)
	{
		if (root == nullptr)
		{
			root = new Node(value);
		}
		else
		{
			root->insert(value);
		}
	}
	void printout()
	{
		if (root == nullptr)
		{
			cout << "No any data!" << endl;
		}
		else
		{
			root->inorderout();
		}
	}
};