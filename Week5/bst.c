/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int leaf_arr[30],nleaf_arr[30], leaf_pos = 0, nleaf_pos = 0;

struct Node
{
    int key;
    struct Node *l_child, *r_child;
};



struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
    node->key = value;
    node->l_child = NULL;
    node->r_child = NULL;
    return node;
}


//Computes tree height
int treeHeight(struct Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int l_height = treeHeight(node->l_child);
        int r_height = treeHeight(node->r_child);
 
        /* use the larger one */
        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
}



/* Print nodes at a current level */
void presentLevel(struct Node* node, int level)
{
    if (node == NULL)
        return;
    if (level == 0)
        printf("%d ", node->key);
    else if (level > 0)
    {
        presentLevel(node->l_child, level - 1);
        presentLevel(node->r_child, level - 1);
    }
}




void levelOrder(struct Node* node)
{
    int h = treeHeight(node);
    int i;
    for (i = 0; i <h; i++)
        presentLevel(node, i);
}
 

//Finding the sum of leaf or non leaf nides
int sum_of_arr(int arr[])
{
    
    int siz = 30;
    int res = 0;
    for(int k = 0; k < siz; k++)
    {
        res = res + arr[k];
    }
    return res;
    
}


//Keeping track of leaf and non leaf nodes for summation
void diffNodes(struct Node* node, int level)
{
    if (node == NULL)
        return;
    if(node->l_child == NULL && node->r_child ==NULL)
    {
        leaf_arr[leaf_pos] = node->key;
        leaf_pos = leaf_pos + 1;
    }
    else
    {
        nleaf_arr[nleaf_pos] = node->key;
        nleaf_pos = nleaf_pos + 1 ;
    }
    if(level > 0) 
    {
        diffNodes(node->l_child, level - 1);
        diffNodes(node->r_child, level - 1);
    }
}


//Inserting in bst
struct Node* insert_node(struct Node* node, int value)
{
    if (node == NULL)
    {
      return newNode(value);  
    }
    
    if (value < node->key)
    {
      node->l_child = insert_node(node->l_child, value);
    }
    
    else if (value > node->key)
    {
     node->r_child = insert_node(node->r_child, value);
    }
    
    return node;
}




struct Node* min_Node(struct Node* node)
{
    struct Node* curr = node;
 
    /* loop down to find the leftmost leaf */
    while (curr && curr->l_child != NULL)
        curr = curr->l_child;
 
    return curr;
}
 

//Deletes the key and return the root node
struct Node* delNode(struct Node* root, int key)
{
    
    if (root == NULL)
        return root;
 
    //Finding on left side, if key to delete is smaller than root
    if (key < root->key)
        root->l_child = delNode(root->l_child, key);
        
        
 
    //Finding on right side, if key to delete is greater than root
    else if (key > root->key)
        root->r_child = delNode(root->r_child, key);
        
        
 
    // if key is same as root's key, delete it.
    else if(key == root->key)
    {
        
        // node with only one child or no child
        if (root->l_child == NULL)
        {
            
            struct Node* temp = root->r_child;
            free(root);
            return temp;
            
        }
        else if (root->r_child == NULL)
        {
            struct Node* temp = root->l_child;
            free(root);
            return temp;
        }
 
        
        //Get the inorder successor i.e., smallest in the right subtree
        struct Node* temp = min_Node(root->r_child);
 
        //Copy the inorder successor's content 
        root->key = temp->key;
 
        //Delete the inorder successor
        root->r_child = delNode(root->r_child, temp->key);
    }
    return root;
}






int main()
{
    
    struct Node *root_node = NULL;
    int no_of_nodes,a[30], ele;
    printf("\nEnter number of Nodes: ");
    scanf("%d",&no_of_nodes);
    printf("\nEnter elements ");
    
    for(int i=0;i<no_of_nodes;i++)
    {
        scanf("\n %d",&a[i]);
    }
    
    //Taking first node as root node
    root_node = insert_node(root_node, a[0]); 
    
    //Inserting the remaining nodes
    for(int i=1;i<no_of_nodes;i++)
    {
      insert_node(root_node, a[i]);  
    }
    int h = treeHeight(root_node);
    diffNodes(root_node,h-1);
    int nleaf_sum = sum_of_arr(nleaf_arr);
    int leaf_sum = sum_of_arr(leaf_arr);
    levelOrder(root_node);
    printf("\nNon Leaves Sum:  %d\n", nleaf_sum);
    printf("\nLeaves Sum:  %d\n", leaf_sum);
    
    printf("\nEnter the element to delete: ");
    scanf("%d", &ele);
    
    delNode(root_node,ele);
    
    levelOrder(root_node);
    
    
    
    return 0;
}
