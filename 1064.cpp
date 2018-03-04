#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Tree
{
	struct Node
	{
		int data;
		Node* left = nullptr;
		Node* right = nullptr;
		explicit  Node(int value=0) :data(value) {}
		Node* RightRotate()
		{
			if (right == nullptr)return this;
			auto parent = right;
			right = parent->left;
			parent->left = this;
			return parent;
		}
		Node* LeftRotate()
		{
			if (left == nullptr)return this;
			auto parent = left;
			left = parent->right;
			parent->right = this;
			return parent;
		}
		Node* RightRotateN(int n)
		{
			if (n < 1)return this;
			auto root = RightRotate();
			auto iter = root;
			for (int i = 1; i < n; ++i)
			{
				if (iter->right == nullptr)break;
				iter->right = iter->right->RightRotate();
				iter = iter->right;
			}
			return root;
		}
	};
	Node* root_;
	size_t size_;
	void Insert(Node*& n,int value)
	{
		if (n == nullptr)
		{
			size_++;
			n=new Node(value);
			return;
		}
		if (n->data == value)return;
		if (n->data < value)return Insert(n->right, value);
		return Insert(n->left, value);
	}
	void ToRightList()
	{
		Node node;
		auto iter = &node;
		iter->right = root_;
		while (root_->left != nullptr)
		{
			root_ = root_->left;
		}
		while (iter->right != nullptr)
		{
			if (iter->right->left != nullptr)iter->right = iter->right->LeftRotate();
			else iter = iter->right;
		}
	}

public:
	void Balance()
	{
		ToRightList();
		int difference = pow(2, floor(log2(size() + 1))) - 1;
		root_= root_->RightRotateN(size() - difference);
		while (difference>1)
		{
			difference /= 2;
			root_= root_->RightRotateN(difference);
		}
	}
	void Insert(int value)
	{
		Insert(root_,value);
	}
	size_t size()const { return size_; }
	bool Empty() { return root_ == nullptr; }
	void LevelOrderTraversal()const
	{
		if (root_ == nullptr)return;
		queue<Node*> q;
		q.push(root_);
		cout << root_->data;
		while (!q.empty())
		{
			if (q.front()->left != nullptr)q.push(q.front()->left);
			if (q.front()->right != nullptr)q.push(q.front()->right);
			q.pop();
			if (!q.empty())cout << " " << q.front()->data;
		}
	}
	Tree():root_(nullptr),size_(0){}
	~Tree()
	{
		queue<Node*> queue;
		if(root_!=nullptr)queue.push(root_);
		while (queue.empty())
		{
			if (queue.front()->left != nullptr)queue.push(queue.front()->left);
			if (queue.front()->right != nullptr)queue.push(queue.front()->right);
			delete queue.front();
			queue.pop();
		}
	}
};
int main(int argc, char* argv[])
{
	int nodeSize;
	cin >> nodeSize;
	Tree tree;
	for (int i = 0; i < nodeSize; ++i)
	{
		int value;
		cin >> value;
		tree.Insert(value);
	}
	tree.Balance();
	tree.LevelOrderTraversal();
}
