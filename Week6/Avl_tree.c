#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int left_sub_sum = 0;

struct Node
{
    int key;
    struct Node *l_child, *r_child;
    int height;
};


//Creating the Node
struct Node* newNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = value;
    node->l_child = NULL;
    node->r_child = NULL;
    node->height = 1;
    return node;
}



//finding the max
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}


//Computes tree height
int treeHeight(struct Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        return node->height;
        /* compute the depth of each subtree */
        /*int l_height = treeHeight(node->l_child);
        int r_height = treeHeight(node->r_child);*/
 
        /* use the larger one */
        /*if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);*/
    }
}



//Finding the balance
int balance(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
        return treeHeight(node->l_child)-treeHeight(node->r_child);
}




//Recursive post order traversal
void postorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    postorder_Traverse(root->l_child);
    postorder_Traverse(root->r_child);
    printf("%d ", root->key);
}
 
 
// Recursive inorder traversal
void inorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    inorder_Traverse(root->l_child);
    printf("%d ", root->key);
    inorder_Traverse(root->r_child);
}

 
// Recursive preorder traversal
void preorder_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    printf("%d ", root->key);
    preorder_Traverse(root->l_child);
    preorder_Traverse(root->r_child);
}


//Finding the left sub tree sum
void leftSum_Traverse(struct Node* root)
{
    if (root == NULL) 
    {
        return;
    }
 
    left_sub_sum += root->key;
    leftSum_Traverse(root->l_child);
    leftSum_Traverse(root->r_child);
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



//Level order traversal
void levelOrder(struct Node* node)
{
    int h = treeHeight(node);
    int i;
    for (i = 0; i <h; i++)
        presentLevel(node, i);
}
 


struct Node *leftRotate(struct Node *node)
{
    struct Node *node1 = node->r_child;
    struct Node *temp = node1->l_child;
    node1->l_child = node;
    node->r_child = temp;
    node1->height = max(treeHeight(node1->l_child), treeHeight(node1->r_child))+1;
    node->height = max(treeHeight(node->l_child), treeHeight(node->r_child))+1;
 
    return node1;
}

struct Node *rightRotate(struct Node *node)
{
    struct Node *node1 = node->l_child;
    struct Node *temp = node1->r_child;
    node1->r_child = node;
    node->l_child = temp;
    node1->height = max(treeHeight(node1->l_child), treeHeight(node1->r_child))+1;
    node->height = max(treeHeight(node->l_child), treeHeight(node->r_child))+1;
 
    return node1;
}





//Inserting in tree
struct Node* insert_node(struct Node* node, int value)
{
    if (node == NULL)
    {
      return(newNode(value));  
    }
    
    if (value < node->key)
    {
      node->l_child = insert_node(node->l_child, value);
    }
    
    else if (value > node->key)
    {
     node->r_child = insert_node(node->r_child, value);
    }
    
    else
    {
    return node;
    }
    
    //Keeping track of height
    node->height = 1 + max(treeHeight(node->l_child),treeHeight(node->r_child));
    //Check the balance after insertion
    int bal = balance(node);
 
    // Left Left
    if (bal > 1 && value < node->l_child->key)
        return rightRotate(node);
        
    // Left Right
    if (bal > 1 && value > node->l_child->key)
    {
        node->l_child =  leftRotate(node->l_child);
        return rightRotate(node);
    }
 
    // Right Left
    if (bal < -1 && value < node->r_child->key)
    {
        node->r_child = rightRotate(node->r_child);
        return leftRotate(node);
    }
    
    // Right Right Case
    if (bal < -1 && value > node->r_child->key)
        return leftRotate(node);
 
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
 
        else
        {
            //Get the inorder successor i.e., smallest in the right subtree
            struct Node* temp = min_Node(root->r_child);
     
            //Copy the inorder successor's content 
            root->key = temp->key;
     
            //Delete the inorder successor
            root->r_child = delNode(root->r_child, temp->key);
        }
    }
    
    if (root == NULL)
      return root;
    root->height = 1 + max(treeHeight(root->l_child),treeHeight(root->r_child));
    
    int bal = balance(root);

    // Left Left 
    if (bal > 1 && balance(root->l_child) >= 0)
        return rightRotate(root);
 
    // Left Right
    if (bal > 1 && balance(root->l_child) < 0)
    {
        root->l_child =  leftRotate(root->l_child);
        return rightRotate(root);
    }
    
    // Right Left
    if (bal < -1 && balance(root->r_child) > 0)
    {
        root->r_child = rightRotate(root->r_child);
        return leftRotate(root);
    }
 
    // Right Right
    if (bal < -1 && balance(root->r_child) <= 0)
        return leftRotate(root);
 
    return root;
}






int main()
{
    
    struct Node *root_node = NULL;
    int no_of_nodes,a[30], ele,ch;
    
    while(1)
    {
        printf("\n Enter your choice");
        printf("\n 1. Insertion \n 2. Deletion \n 3. Traversal \n 4. Left Sub-tree Sum \n 5. Exit \n");
        
        scanf("%d", &ch);
        
        if(ch == 1)
        {
            printf("\nEnter number of Nodes: ");
            scanf("%d",&no_of_nodes);
            printf("\nEnter elements ");
            
            for(int i=0; i<no_of_nodes; i++)
            {
                scanf("\n %d",&a[i]);
                root_node = insert_node(root_node, a[i]);
            }
            
           
            //Taking first node as root node
           /* root_node = insert_node(root_node, a[0]); 
            
            //Inserting the remaining nodes
            for(int i=1;i<no_of_nodes;i++)
            {
              root_node = insert_node(root_node, a[i]);  
            }*/
        
        }//End of Insertion
        
        
        int h = treeHeight(root_node);
        
        if(ch == 2)
        {
            printf("\nEnter the element to delete: ");
            scanf("%d", &ele);
            delNode(root_node,ele);
        }
        
        if(ch == 3)
        {
            printf("\n Level Order : ");
            levelOrder(root_node);
            printf("\n PreOrder : ");
            preorder_Traverse(root_node);
            printf("\n In Order : ");
            inorder_Traverse(root_node);
            printf("\n Post Order : ");
            postorder_Traverse(root_node);
        }
        
        
        if(ch == 4)
        {
            left_sub_sum = 0;
            leftSum_Traverse(root_node->l_child);
            printf("The left sub tree sum is %d",left_sub_sum);
        }
        
        if(ch ==5)
        {
            exit(1);
        }
    }
    return 0;
}

