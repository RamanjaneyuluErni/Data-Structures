// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	int data; //data of the node
	Node *left, *right; //left and right references

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		left = right = NULL;
	}
};

// Method that prints the bottom view.
void bottomView(Node *root)
{
	
    unordered_map<int,int>Un_map;
    Un_map.clear();
    queue< pair<Node*,int> > q;
    Node *current=root;
    q.push(make_pair(current,0));
    while(!q.empty())
    {
        pair<Node*,int> p=q.front();
        q.pop();
        current=p.first;
        int val=p.second;
        Un_map[val]=current->data;
        if(!current->left)
        {
            q.push(make_pair(current->left,val-1));
        }
        if(!current->right)
        {
            q.push(make_pair(current->right,val+1));
        }
    }
    unordered_map<int,int>::iterator it;
    for(it=Un_map.begin();it!=Un_map.end();it++)
    {
        cout<<it->second<<" ";
    }
    cout<<endl;
}

// Driver Code
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	bottomView(root);
	return 0;
}

