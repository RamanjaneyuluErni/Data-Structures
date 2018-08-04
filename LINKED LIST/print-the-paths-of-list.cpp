#include<iostream>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
void printPathsRecur(struct node* node, int path[], int pathLen);
void printArray(int ints[], int len);

void printPaths(struct node* node)
{
  int path[100];
  printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen)
{
  if (node==NULL)
    return;


  path[pathLen] = node->data;
  pathLen++;

  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++)
  {
  cout<<ints[i]<<endl;
  }
cout<<endl;
}

struct node* newnode(int data)
{
  struct node* newnode = new node;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}


int main()
{

  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  root->right->right=newnode(7);
  root->left->right->right=newnode(11);
  root->left->right->left=newnode(17);
  root->left->right->left->right=newnode(9);
root->left->right->left->right->left=newnode(54);
root->left->right->left->right->right=newnode(23);
  printPaths(root);
  return 0;
}
