#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
template<typename T>
struct AVLTree
{
	AVLTree():root_(nullptr),size_(0){}
	~AVLTree()
	{
		queue<Node*> q;
		if (root_ != nullptr)q.push(root_);
		while (!q.empty())
		{
			if (q.front()->left_ != nullptr)q.push(q.front()->left_);
			if (q.front()->right_ != nullptr)q.push(q.front()->right_);
			delete q.front();
			q.pop();
		}
	}
	size_t size()const { return size_; }
	void Insert(const T value)
	{
		root_= Insert(root_, value);
	}
	struct Node
	{
		T data_;
		int height_;
		Node* left_;
		Node* right_;
		explicit  Node(T value = 0) : data_(value), height_(1), left_(nullptr), right_(nullptr)
		{
		}

		Node* LeftRotate()
		{
			if (left_ == nullptr)return this;
			auto parent = left_;
			left_ = parent->right_;
			parent->right_ = this;
			return parent;
		}
		Node* RightRotate()
		{
			if (right_ == nullptr)return this;
			auto parent = right_;
			right_ = parent->left_;
			parent->left_ = this;
			return parent;
		}
		Node* LeftRightRotate()
		{
			left_ = left_->RightRotate();
			return LeftRotate();
		}
		Node* RightLeftRotate()
		{
			right_ = right_->LeftRotate();
			return RightRotate();
		}
	};
	Node* root_;
	size_t size_;
	Node* Insert(Node* n, const T value)
	{
		if(n==nullptr)
		{
			size_++;
			return new Node(value);
		}
		if (n->data_ > value) n->left_= Insert(n->left_, value);
		else if (n->data_ < value) n->right_ = Insert(n->right_, value);
		return Balance(n,value);
	}
	int Height(Node* n)const
	{
		if (n == nullptr)return 0;
		return n->height_;
	}
	Node* Balance(Node*n, const T value)
	{
		const auto balanceFactor = Height(n->left_)-Height(n->right_);
		if(balanceFactor>1)
		{
			if (value< n->left_->data_){ n = n->LeftRotate(); }
			else{ n = n->LeftRightRotate(); }
			UpdateHeight(n);
		}
		else if(balanceFactor<-1)
		{
			if (value<n->right_->data_){ n = n->RightLeftRotate(); }
			else { n = n->RightRotate(); }
			UpdateHeight(n);
		}
		n->height_ = max(Height(n->left_), Height(n->right_)) + 1;
		return n;
	}
	int UpdateHeight(Node* n)const
	{
		if (n == nullptr)return 0;
		return n->height_= max(UpdateHeight(n->left_), UpdateHeight(n->right_)) + 1;
	}
};
int main(int argc, char* argv[])
{
	AVLTree<int> avlTree;
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int num;
		cin >> num;
		avlTree.Insert(num);
	}
	cout << avlTree.root_->data_;
}
