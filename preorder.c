#include<stdio.h>
#include<stdlib.h>
struct queue
{   int size;
    int front;
    int rear;
    struct node**a;};
struct node
{   struct node*lchild;
    int data;
    struct node*rchild;};
struct stack
{   int size;
    int top;
    struct node**a;};

struct node*root=NULL;

void create(struct queue*a,int size);
void enqueue(struct queue*q,struct node*x);
struct node* dequeue(struct queue*q);
int isempty(struct queue q);
void screate(struct stack*s,int size);
void spush(struct stack*s,struct node*x);
struct node* spop(struct stack*s);
int issempty(struct stack s);

void binarytree();
void preorder(struct node*p);
void ipreorder(struct node*p);

int main()
{
 binarytree();
 printf("preorder is\n");
 preorder(root);
 printf("\n iterative preorder  is\n"); ipreorder(root);
}

void create(struct queue*q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->a=(struct node**)malloc(q->size*sizeof(struct node*));
}
void enqueue(struct queue*q,struct node*x)
{
    if((q->rear+1)%q->size==q->front)
        printf("no more space");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=x;
    }
}
struct node*dequeue(struct queue*q)
{
    struct node*x;
    if(q->front==q->rear)
        printf("empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];

    }
    return x;
};
int isempty(struct queue q)
{
    if(q.front==q.rear)
        return 1;
    else return 0;
}


void screate(struct stack*s,int size)
{
    s->size=size;
    s->top=-1;
    s->a=(struct node**)malloc(s->size*sizeof(struct node*));
}
void spush(struct stack*s,struct node*x)
{
    if(s->top==s->size-1)
        printf("no more space");
    else
    {
        s->top++;
        s->a[s->top]=x;
    }
}

struct node*spop(struct stack*s)
{
    struct node*x;
    if(s->top==-1)
        printf("empty");
    else
    {

        x=s->a[s->top--];

    }
    return x;
};
int issempty(struct stack s)
{
    if(s.top==-1)
        return 1;
    else return 0;
}
void binarytree()
{struct queue q;
struct node*p;
struct node*t;
create(&q,20);
    int x=-1;
    printf("enter root element");
    scanf("%d",&x);
    root=(struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {p=dequeue(&q);

        printf("enter lchild of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter rchild of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);}
    }
}
void preorder(struct node*p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);}
}
void ipreorder(struct node*p)
{
    struct stack s;
    screate(&s,20);
    while(p||!issempty(s))
    {if(p){
        printf("%d ",p->data);
        spush(&s,p);
        p=p->lchild;
    }
    else
    {
        p=spop(&s);
        p=p->rchild;
    }
}}
