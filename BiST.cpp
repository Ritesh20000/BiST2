#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

    Node (int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class BiST
{
public:
  Node * root;
  BiST ()
  {
    root = NULL;
  }
  void insert (int value)
  {
    insertHelper (root, value);
  }

  void insertHelper (Node * curr, int value)
  {
    // Base case if curr is NULL, insert there. 
    //Node * temp = new Node(value);
    if (root == NULL)
      {
	root = new Node (value);
      }
    // Else compare the curr data with value
    else if (value < curr->data)
      {
	// If value < curr data  -> 
	// If left is null, insert it. 
	// else move left and call insertH
	if (curr->left == NULL)
	  curr->left = new Node (value);
	else
	  insertHelper (curr->left, value);
      }
    else
      {
	// Else move right and call insertH
	if (curr->right == NULL)
	  curr->right = new Node (value);
	else
	  insertHelper (curr->right, value);
      }
  }
  void display ()
  {
    display2 (root);
  }

  void display2 (Node * curr)
  {
    // Base condition 
    if (curr == NULL)
      return;
    // Display left.  
    display2 (curr->left);
    // Display current
    cout << curr->data << ",";
    // Display right 
    display2 (curr->right);
  }



  Node *search (Node * curr, int value)
  {
    // If reached end of tree. or value found 
    if (curr == NULL || curr->data == value)
      return curr;
    else if (value < curr->data)
      return search (curr->left, value);
    else
      return search (curr->right, value);
  }



};



int
main ()
{
  BiST u;
  u.insert(2);
  u.insert(4);
  u.insert(3);
  u.insert(7);
  int i = 23;
  while(i < 40){
      u.insert(i);
      i++;
  }
  if (u.search (u.root,23)!=NULL) cout<<"Number is found."<<endl;
else cout<<"ERROR :not found."<<endl;
  
  u.display ();
}

