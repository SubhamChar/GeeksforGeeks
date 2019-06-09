Given a Binary Search Tree of size N, that may be unbalanced. Your task is to complete the function buildBalancedTree(), that convert the given BST into a balanced BST that has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
The function takes a single argument as input, the reference pointer to the root of the Binary Search Tree.
There are T, test cases and for each test case the function will be called separately.

Output:
For each test case output will be the new height of the BST.

Constraints:
1<=T<=100
1<=N<=200

Example:
Input:
2
3
30 20 10
5
10 8 7 6 5
Output:
2
3

-------------------------------------------------------CODE--------------------------------------------------------------------

{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left, *right;
};
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
Node* insert(struct Node* node, int key){
	if (node == NULL) return newNode(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}
void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
int height(struct Node* node) 
{
   if (node==NULL) return 0;
   else
   {
       int lDepth = height(node->left);
       int rDepth = height(node->right);
       if (lDepth > rDepth) return(lDepth+1);
       else return(rDepth+1);
   }
} 
Node* buildBalancedTree(Node* root);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void storeBSTNodes(Node* root, vector<Node*> &nodes) 
{ 
    // Base case 
    if (root==NULL) 
        return; 
  
    // Store nodes in Inorder (which is sorted 
    // order for BST) 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
} 
  
/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start, 
                   int end) 
{ 
    // base case 
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node *root = nodes[mid]; 
  
    /* Using index in Inorder traversal, construct 
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end); 
  
    return root; 
} 
  
// This functions converts an unbalanced BST to 
// a balanced BST 
Node* buildBalancedTree(Node* root) 
{ 
    // Store nodes of given BST in sorted order 
    vector<Node *> nodes; 
    storeBSTNodes(root, nodes); 
  
    // Constucts BST from nodes[] 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1); 
} 
