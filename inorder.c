#include<stdio.h>
#include<stdlib.h>

struct trees
{
	int data;
	struct trees *left;
	struct trees *right;
};

struct trees* create()
{
	struct trees *temp;
	int data;
	temp=(struct trees*)malloc(sizeof(struct trees*));
	printf("\nEnter the data or (-1) for NULL : ");
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	temp->data=data;
	printf("Enter data in left part : ");
	temp->left=create();
	printf("Enter data in right part : ");
	temp->right=create();
return temp;
}

struct trees* inorder(struct trees *temp)
{
	if(temp)
	{
		inorder(temp->left);
		printf("temp->data");
		inorder(temp->right);
	}

}

int main()
{
	struct trees* root=create();
	struct trees* t=root;
	inorder(t);
}
