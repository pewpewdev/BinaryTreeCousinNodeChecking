#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

//Defining the node of the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Non-recursive function for post order traversal through the binary search tree.
void postOrdernr(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack[100];
    int top = -1;
    struct Node *cur = root;
    struct Node *prev = NULL;
    while (cur != NULL || top != -1) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top];
        if (cur->right == NULL || cur->right == prev) {
            printf("%d ", cur->data);
            top--;
            prev = cur;
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
}

// Recursive function for pre-order tree traversal
void preOrder(struct Node* root)
{
	if (root == NULL)
    	return;
 
	printf("%d ", root->data);
 
    preOrder(root->left);
 
	preOrder(root->right);
	
}

//Non-recursive function for pre order tree traversal.
void preOrdernr(struct Node *root) {
    if (root == NULL) {
        return;
    }

    struct Node *stack[100];
    int top = -1;

    while (1) {
        while (root) {
            printf("%d ", root->data);
            stack[++top] = root;
            root = root->left;
        }
        if (top < 0) {
            break;
        }
        root = stack[top--];
        root = root->right;
    }
}



//Boolean function that returns 1 if two nodes are siblings and 0 if they are not siblings.
bool areSiblings(struct Node *root, int a, int b)
{
    if (root == NULL)
        return false;
    return ((root->left && root->left->data == a && root->right && root->right->data == b) ||
            (root->left && root->left->data == b && root->right && root->right->data == a) ||
            areSiblings(root->left, a, b) ||
            areSiblings(root->right, a, b));
}   
    


// Finds level of node x in binary tree starting from root as level 0.
int edepth(struct Node* root, int x, int level)
{
    if (root == NULL)
        return 0;
    if (root->data == x)
        return level;
    int downlevel = edepth(root->left, x, level + 1);
    if (downlevel != 0)
        return downlevel;
    downlevel = edepth(root->right, x, level + 1);
    return downlevel;
}

// Returns 1 if x and y are cousins, otherwise 0
int areCousins(struct Node* root, int x, int y)
{
    int xLevel = edepth(root, x, 1);
    int yLevel = edepth(root, y, 1);
    if (xLevel == yLevel && !(areSiblings(root, x, y)))
        return 1;
    return 0;
}

// Returns 1 if x and y are siblings, otherwise 0
int isSibling(struct Node* root, int x, int y)
{
    if (root == NULL)
        return 0;
    return ((root->left && root->left->data == x &&
             root->right && root->right->data == y) ||
            (root->left && root->left->data == y &&
             root->right && root->right->data == x) ||
            isSibling(root->left, x, y) ||
            isSibling(root->right, x, y));
}


//Recursive function for post order tree traversal
void postOrder(struct Node* root) {
  if (root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->data);
  
}

//Recursive function for in order tree traversal.
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


//Non-recursive function for in order tree traversal.
void inOrdernr(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100];
    int top = -1;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}


//new node 
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//function to insert new node in the binary search tree
struct Node* insert(struct Node* node, int data) {
  if (node == NULL) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
  }
  if (data < node->data) node->left = insert(node->left, data);
  else if (data > node->data) node->right = insert(node->right, data);
  return node;
}


//main function
int main() {
    struct Node* root = NULL;
    int data, choice,x,y,a,b,height,n1,n2;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert new node\n");
        printf("2. Recursive In-Order Traversal\n");
        printf("3. Non-Recursive In-Order Traversal\n");
        printf("4. Recursive Pre-Order Traversal\n");
        printf("5. Non-Recursive Pre-Order Traversal\n");
        printf("6. Recursive Post-Order Traversal\n");
        printf("7. Non-Recursive Post-Order Traversal\n");
        printf("8. Check whether two nodes are Cousins\n");
        printf("9. Check whether two nodes are siblings\n");
        printf("10. Check the level of a node\n");
        printf("11. Exit\n");
        scanf("%d", &choice);
        if (choice == 11) break;
//Switch case to allow the user to input their choice as per the instructions given above.
        switch (choice)
        {
            case 1:
            {
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            }
            case 2:
            {
                printf("Recursive In-Order Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Non-Recursive In-Order Traversal:\n");
                inOrdernr(root);
                printf("\n");
                break;
            }
            
            
            case 4:
            {
                printf("Recursive Pre-Order Traversal\n");
                preOrder(root);
                printf("\n");
                break;
                
            }
            
            
            case 5:
            {
                printf("Non-Recursive Pre-Order Traversal\n");
                preOrdernr(root);
                printf("\n");
                break;
            }
            
            case 6:
            {
                printf("Recursive Post-Order Traversal\n");
                postOrder(root);
                printf("\n");
                break;
            }
            case 7:
            {
                printf("Non-Recursive Post-Order Traversal\n");
                postOrdernr(root);
                printf("\n");
                break;
            }
            case 8:
            {
                 
               printf("Enter two nodes to check if they are cousins or not.\n");
			printf("Enter the first node: \n");
            	scanf("%d", &x);
			printf("Enter the second node:\n");
    			scanf("%d", &y);
            if (areCousins(root, x, y))
                printf("The two nodes are cousins \n");
            else
                printf("The two nodes are not cousins\n");
            
                   
            break;
            }
            case 9:
            {
		printf("Enter two nodes to check if they are siblings or not.\n");
            printf("Enter the first node: \n");
            scanf("%d", &a);
            printf("Enter the second node: \n");
            scanf("%d", &b);
            if (areSiblings(root, a, b))
                printf("The two nodes are siblings.\n");
            else 
                printf("The two nodes are not siblings.\n");
             
                
            break;
        default:
            break;
            }
            
            case 10:
            {
                printf("Enter a node from the tree to check its level: ");
                scanf("%d", &a);
                height = edepth(root, a,0);
                printf("Level of %d = %d\n", a,height);
                break;
            }
            
        }
    }

    return 0;
}