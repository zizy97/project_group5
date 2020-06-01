#include <stdio.h>
#include <stdlib.h>
typedef enum{True=1, False=0}boolean;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

node *root;

void insert(int);
void inorder(node *n);
void postorder(node *n);
void preorder(node *n);
boolean search(int x);
int findMin();
int findMax();
int countNodes(node *n,int i);
void printLeaf(node *p);
void deleteNode(int x);

int main(){
	int i,x;
	root=NULL;
	for(i=0;i<8;i++)
	{
		printf("Enter Number:");
		scanf("%d",&x);
		insert(x);
	}
	printf("\ndisplay tree inOder\n=============\n");
	inorder(root);
	printf("\ndisplay tree in post order\n=============\n");
	postorder(root);
	printf("\ndisplay tree in pre order\n=============\n");
	preorder(root);
	printf("\nEnter Value to search:");
	scanf("%d",&x);
	if(search(x))
		printf("\n%d Exist on the tree",x);
	else
		printf("\n%d Not Exist on the tree",x);
	printf("\nMinimum value of the tree=%d",findMin());
	printf("\nMaximum value of the tree=%d",findMax());
	i=0;
	printf("\nNo of nodes in the tree=%d",countNodes(root,i));
	printLeaf(root);
	printf("\nEnter Value to delete:");
	scanf("%d",&x);
     	deleteNode(x);
	printf("\ndisplay tree inOder\n=============\n");
	inorder(root);
} 

void insert(int x){
	node *parent,*current;
	node *nw=(node*)malloc(sizeof(node));
	nw->data=x;
	nw->left=NULL;
	nw->right=NULL;
	if(search(x))
		printf("\nAlready exist cann't insert");
	else{
		if(root==NULL){
			root=nw;
		}else{
			current=root;
			while(current!=NULL)
			{
				parent=current;
				if(current->data>x){
					current=current->left;
				}else{
					current=current->right;
				}
			}
			if(x>parent->data)
				parent->right=nw;
			else
				parent->left=nw;
		}
	}
}

void inorder(node *n){
	if(n!=NULL)
	{
		inorder(n->left);
		printf("%d\t",n->data);
		inorder(n->right);
	}
}

void postorder(node *n){
	if(n!=NULL)
	{
		postorder(n->left);
		postorder(n->right);
		printf("%d\t",n->data);
	}
}
void preorder(node *n){
	if(n!=NULL)
	{
		printf("%d\t",n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

boolean search(int x)
{
	node *n=root;
	boolean check=False;
	while(n!=NULL)
	{
		if(n->data==x)
		{
			check=True;
			break;
		}else if(n->data>x)
			n=n->left;
		else
			n=n->right;
	}
	return check;
}

int findMin(){
	node *n=root;
	while(n->left!=NULL)
		n=n->left;
	return n->data;
}

int findMax(){
	node *n=root;
	while(n->right!=NULL)
		n=n->right;
	return n->data;
}

int countNodes(node *n,int i)
{
	if(n!=NULL)
	{
		i=countNodes(n->left,i);
		i++;
		i=countNodes(n->right,i);
	}
	return i;

}
void printLeaf(node *p)
{
 	if(p->left)
       		printLeaf(p->left);
	   
	if(p->right) 
		printLeaf(p->right);
	
	if((p->left==NULL)&&(p->right==NULL)) 
	       printf("\nLeaf Node value=%d",p->data);
}

void deleteNode(int x)
{
	node *cur=root,*parent;
	if(!search(x))
		printf("\nNo element to delete");
	else{
		while(cur->data!=x)
		{
			parent=cur;
			if(cur->data>x)
				cur=cur->left;
			else
				cur=cur->right;
		}

		if((cur->left==NULL)&&(cur->right==NULL))
		{
			if(parent->left==cur)
				parent->left=NULL;
			else
				parent->right=NULL;
			free(cur);
		}else if((cur->left==NULL)&&(cur->right!=NULL)){
			 if(parent->left==cur)
				parent->left=cur->right;
			else
				parent->right=cur->right;
			free(cur);
		}else if((cur->left!=NULL)&&(cur->right==NULL)){
			 if(parent->left==cur)
				parent->left=cur->left;
			else
				parent->right=cur->left;
			free(cur);
		}else{
			node *n=cur->right,*p;
			while(n->left!=NULL){
				p=n;
				n=n->left;
			}
			cur->data=n->data;
			p->left=n->right;
			free(n);
		}
	}
}
