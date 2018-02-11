#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	Node* left=nullptr;
	Node* right=nullptr;
	int data;
	Node(){}
};
vector<Node> seq;
vector<int> preorder;
vector<int> postorder;
void Travelsal(Node* n)
{
	if(n==nullptr)return;
	preorder.push_back(n->data);
	Travelsal(n->left);
	Travelsal(n->right);
	postorder.push_back(n->data);
}
bool IsSame()
{
	for (int i = 0; i < seq.size(); ++i)
	{
		if (seq[i].data != preorder[i])return false;
	}
	return true;
}
void Yes()
{
	cout << "YES\n";
	cout << postorder[0];
	for (int i = 1; i < postorder.size(); ++i)
	{
		cout << " " << postorder[i];
	}
}
void Swap(Node* n)
{
	if(n==nullptr)return;
	swap(n->left, n->right);
	Swap(n->left);
	Swap(n->right);
}
int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	seq.resize(size);
	for (int i = 0; i < size; ++i)
	{
		cin >>seq[i].data ;
	}
	for (int i = 1; i < size; ++i)
	{
		auto iter = &seq[0];
		while (true)
		{
			if(seq[i].data<iter->data)
			{
				if(iter->left != nullptr)iter = iter->left;
				else
				{
					iter->left = &seq[i];
					break;
				}
			}
			else
			{
				if (iter->right != nullptr)iter = iter->right;
				else
				{
					iter->right = &seq[i];
					break;
				}
			}
		}
	}
	Travelsal(&seq[0]);
	if(IsSame())Yes();
	else
	{
		Swap(&seq[0]);
		postorder.clear();
		preorder.clear();
		Travelsal(&seq[0]);
		if (IsSame())Yes();
		else { cout << "NO"; }
	}
}
