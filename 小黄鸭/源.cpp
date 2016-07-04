#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class AVLNode
{
private:
	int val;
	int h;
	AVLNode * parent;
	AVLNode * lc;
	AVLNode * rc;
	int factor(){return (lc == nullptr ? -1 : lc->h) - (rc == nullptr ? -1 : rc->h);}
	void update()
	{
		h = max((lc == nullptr ? -1 : lc->h), (rc == nullptr ? -1 : rc->h)) + 1;
	}
	AVLNode * left_rot(AVLNode * t)
	{
		AVLNode * tmp = t->rc;
		if (t->parent != nullptr)
		{
			if (t->parent->lc == t)
			{
				t->parent->lc = tmp;
			}
			else
			{
				t->parent->rc = tmp;
			}
		}
		tmp->parent = t->parent;
		t->rc = tmp->lc;
		if(t->rc!=nullptr)
		    t->rc->parent = t;
		tmp->lc = t;
		t->parent = tmp;
		t->update();
		tmp->update();
		return tmp;
	}
	AVLNode * right_rot(AVLNode * t)
	{
		AVLNode * temp = t->lc;
		if (t->parent != nullptr)
		{
			if (t->parent->lc == t)
			{
				t->parent->lc = temp;
			}
			else
			{
				t->parent->rc = temp;
			}
		}
		temp->parent = t->parent;
		t->parent = temp;
		t->lc = temp->rc;
		if(t->lc !=nullptr)
		    t->lc->parent = t;
		temp->rc = t;
		t->update();
		temp->update();
		return temp;
	}
	AVLNode * rebalance(AVLNode * root)
	{
		int fac = root->factor();
		if ( fac > 1)
		{
			if (root->lc->factor() < 0)
			{
				root->lc = left_rot(root->lc);
			}
			root = right_rot(root);
		}
		else if (fac < -1)
		{
			if (root->rc->factor()>0)
			{
				root->rc = right_rot(root->rc);
			}
			root = left_rot(root);
		}
		if (root->parent != nullptr)
		{
			return rebalance(root->parent);
		}
		else
		{
			return root;
		}
	}
public:
	AVLNode(int _val, AVLNode* _p = nullptr) :val(_val), parent(_p),h(0),lc(nullptr),rc(nullptr) {}
	~AVLNode()
	{
		delete lc;
		delete rc;
	}
	AVLNode * insert(int v)
	{
		if (v == val)
		{
			return nullptr;
		}
		if (v > val)
		{
			if (rc != nullptr)
			{
				return rc->insert(v);
			}
			else
			{
				rc = new AVLNode(v, this);
				update();
				return rebalance(this);
			}
		}
		else
		{
			if (lc != nullptr)
			{
				return lc->insert(v);
			}
			else
			{
				lc = new AVLNode(v, this);
				update();
				
				return rebalance(this);
			}
		}
	}
	AVLNode * preceeder(AVLNode * tr)
	{
		if (tr->lc == nullptr)
		{
			return nullptr;
		}
		AVLNode * pt = tr->lc;
		while (pt->rc != nullptr)
		{
			pt = pt->rc;
		}
		return pt;
	}
	AVLNode * successor(AVLNode * rt)
	{
		if (rt->rc == nullptr)
		{
			return nullptr;
		}
		AVLNode * pt = rt->rc;
		while (pt->lc != nullptr)
		{
			pt = pt->lc;
		}
		return pt;
	}
	AVLNode * del(int v,AVLNode * rt)
	{
		AVLNode * ret;
		if (v == rt->val)
		{
			AVLNode * fake = preceeder(rt);
			if (fake == nullptr)
			{
				if (rt->rc != nullptr)
				{
					if (rt->parent != nullptr)
					{
						if (rt->parent->lc = rt)
						{
							rt->parent->lc = rt->rc;
						}
						else
						{
							rt->parent->rc = rt->rc;
						}
						
					}
					rt->rc->parent = rt->parent;
					rt->parent->update();
					ret = rebalance(rt->parent);
					rt->lc = nullptr;
					rt->rc = nullptr;
					delete rt;
				}
				else
				{
					if (rt->parent != nullptr)
					{
						if (rt->parent->lc = rt)
						{
							rt->parent->lc = nullptr;
						}
						else
						{
							rt->parent->rc = nullptr;
						}
						ret = rebalance(rt->parent);

					}
					else
					{
						delete rt;
						return nullptr;
					}

				}
			}
			else
			{
				swap(fake->val, rt->val);
				ret = del(v, fake);
			}
			return ret;
		}
		if (v > rt->val)
		{
			return del(v, rt->rc);
		}
		else
		{
			return del(v, rc->lc);
		}
	}
	int query(int k)
	{
		stack<AVLNode *> s;
		AVLNode * cur = this;
		while (!s.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->rc;
			}
			else
			{
				cur = s.top();
				s.pop();
				//output
				k--;
				if (k == 0)
				{
					return cur->val;
				}
				cur = cur->lc;
			}
		}
		return 0;
	}
	
};

int main_2()
{
	AVLNode* root;
	int n, m, temp;
	string cmd;
	cin >> n >> m;
	cin >> temp;
	root = new AVLNode(temp);
	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		root = root->insert(temp);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> cmd >> temp;
		if (cmd == "insert")
		{
			root = root->insert(temp);
		}
		else if (cmd == "delete")
		{
			root = root->del(temp, root);
		}
		else if(cmd == "query")
		{
			cout << root->query(temp) << endl;
		}
	}
	
	return 0;
}