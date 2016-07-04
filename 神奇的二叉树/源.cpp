#include<iostream>
#include<memory>
#include<string>
using std::string;
class Node
{
private:
	char data;
	Node * left;
	Node * right;
public:
	Node(char d) :data(d), left(nullptr), right(nullptr) {}
	Node(char d, Node * lp, Node * rp) :data(d), left(lp), right(rp) {}
	~Node()
	{
		if (left != nullptr)
		{
			delete left;
		}
		if (right != nullptr)
		{
			delete right;
		}
	}
	char & a_data() { return  data; }
	Node  * &lchild() { return left; }
	Node  * &rchild() { return right; }
	static Node * build(const string & prestr, const string & instr, int len)
	{
		Node *fa=new Node(prestr[0]);
		int pos = instr.find(prestr[0]);
		if (pos != 0)
		{
			fa->lchild() = build(prestr.substr(1, pos + 1), instr.substr(0, pos), pos);
		}
		if (pos != len - 1)
		{
			fa->rchild() = build(prestr.substr(pos + 1, len), instr.substr(pos + 1, len), len - pos - 1);
		}
		return fa;

	}
	void postorder()
	{
		if (left != nullptr)
		{
			left->postorder();
		}
		if (right != nullptr)
		{
			right->postorder();
		}
		std::cout << data;
	}
	void mirrorpost()
	{
		if (right != nullptr)
		{
			right->mirrorpost();
		}
		if (left != nullptr)
		{
			left->mirrorpost();
		}
		std::cout << data;
	}
};
class BTree
{
private:
	Node * root;
public:
	BTree() :root(nullptr) {}
	BTree(const string & prestr, const string & instr, int len) :root(nullptr)
	{
		root = Node::build(prestr,instr,len);
	}
	Node & tree()
	{
		return *root;
	}
	
};
int main()
{
	string pres, ins;
	std::cin >> pres >> ins;
	BTree binaryt(pres, ins, ins.length());
	binaryt.tree().postorder();
	std::cout << std::endl;
	binaryt.tree().mirrorpost();
	std::cout << std::endl;
	return 0;
}