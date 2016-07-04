#pragma once
#include<algorithm>
#include<memory>

template<typename E>
class HuffNode
{
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};
template<template E>
class LeafNode :public HuffNode<E>
{
private:
	E it;
	int wgt;
public:
	LeafNode(const E & val, int freq) :it(E), wgt(freq) {}
	int weight() { return wgt; }
	E val() { return it; }
	bool isLeaf() { return true };
};
template <typename E>
class IntlNode :public HuffNode<E>
{
private:
	HuffNode<E> * lc;
	HuffNode<E> * rc;
	int wgt;
public:
	IntlNode(HuffNode<E> * l, HuffNode<E> * r) :wgt(l->weight() + r->weight()), lc(l), rc(r) {}
	int weight() { return wgt; }
	bool isLeaf() { return false; }
	HuffNode<E>* left() const { return lc; }
	void setLeft(HuffNode<E>* b)
	{
		lc = b;
	}
	HuffNode<E>* right() const { return rc; }
	void setRight(HuffNode<E>* b)
	{
		rc = b;
	}
};

template <typename E>
class HuffTree
{
private:
	HuffNode<E>* Root;
public:
	HuffTree(E & val, int freq) :Root(new LeafNode<E>(val, freq)) {}
	HuffTree(HuffTree<E> * l, HuffTree<E>*r) :Root(new IntlNode<E>(l->Root, r->Root)) {}
	~HuffTree() {}
	HuffNode<E> * root() { return Root; }
	int weight() { return Root->weight; }
};

template<typename E>
HuffTree<E> * buildHuff(HuffTree<E> **TreeArray, int count)
{
	heap<HuffTree<E>*, minTreeComp>* forest = new heap<HuffTree<E>*, minTreeComp>(TreeArray, count, count);
	HuffTree<char> *temp1, *temp2, *temp3 = NULL;
	while (forest->size() > 1)
	{
		temp1 = forest->removefirst();
		temp2 = forest->removefirst();
		temp3 = new HuffTree<E>(temp1, temp2);
		forest->insert(temp3);
		delete temp1;
		delete temp2;
	}
	return temp3;
}