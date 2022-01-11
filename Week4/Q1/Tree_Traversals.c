
#include<stdio.h>
#include<stdlib.h>
#define spaceVal 10

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



void Postorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    Postorder_Traverse(root->l_child);
    Postorder_Traverse(root->r_child);
    printf("%d ", root->key);
}
 
 
// Recursive inorder traversal
void Inorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    Inorder_Traverse(root->l_child);
    printf("%d ", root->key);
    Inorder_Traverse(root->r_child);
}

 
// Recursive preorder traversal
void Preorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    printf("%d ", root->key);
    Preorder_Traverse(root->l_child);
    Preorder_Traverse(root->r_child);
}

void displayNode(struct Node *node, int space)
{
    if (node == NULL)
        return;
 
    space += spaceVal;
    displayNode(node->r_child, space);
    printf("\n");
    for (int i = spaceVal; i < space; i++)
        printf(" ");
    printf("%d\n", node->key);
    displayNode(node->l_child , space);
}
 
void displayTree(struct Node *node)
{
   displayNode(node, 0);
}



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




int main()
{
    struct Node *root_node = NULL;
    int no_of_nodes,a[30];
    printf("Enter number of Nodes: ");
    scanf("%d",&no_of_nodes);
    printf("Enter elements ");
    
    for(int i=0;i<no_of_nodes;i++)
    {
        scanf("\n %d",&a[i]);
    }
    
    root_node = insert_node(root_node, a[0]); 
    
    for(int i=1;i<no_of_nodes;i++)
    {
      insert_node(root_node, a[i]);  
    }
    
    //printf("\n Height of tree is %d", treeHeight(root_node));
    
    printf("\n Inorder_Traverse is: ");
    Inorder_Traverse(root_node);
    
    printf("\n Preorder_Traverse is : ");
    Preorder_Traverse(root_node);
    
    printf("\n Postorder_Traverse is : ");
    Postorder_Traverse(root_node);
    
    printf("\n Height of tree is %d \n", treeHeight(root_node));
    
    displayTree(root_node);
    
    
    return 0;
}