#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*lchild;
    int data;
    int height;
    struct node*rchild;
}*root;

int nodeheight(struct node *p);
int balancefactor(struct node *p);



struct node*rinsert(struct node*p,int key);
struct node *llrotation(struct node*p);
struct node *rrrotation(struct node*p);
struct node *lrrotation(struct node*p);
struct node *rlrotation(struct node*p);




void preorder(struct node*p);

int main()
{
root=rinsert(root,1);
   rinsert(root,2);
   rinsert(root,3);
   rinsert(root,4);
   rinsert(root,5);
   rinsert(root,6);
   printf("\nheight of(avl not binary) after rotation tree \n");
printf("%d",nodeheight(root));
printf("\n\npreorder after rotation\n");
preorder(root);
}

int nodeheight(struct node*p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int balancefactor(struct node*p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl-hr;
}



    struct node *rinsert(struct node*p,int key)
    {
        struct node*t;
        if(p==NULL)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=key;
            t->height=1;
            t->lchild=t->rchild=NULL;
            return t;
        }
        if(key==p->data)
            return 0;
        else if(key<p->data)
            p->lchild=rinsert(p->lchild,key);
        else
            p->rchild=rinsert(p->rchild,key);

            p->height=nodeheight(p);

            if(balancefactor(p)==2&&balancefactor(p->lchild)==1)
            {
                printf("\nll rotation is required\n");
                return llrotation(p);
            }
           else   if(balancefactor(p)==-2&&balancefactor(p->rchild)==-1)
            {
                printf("\nrr rotation is required\n");
                return rrrotation(p);
            }
            else if(balancefactor(p)==2&&balancefactor(p->lchild)==-1)
            {
                printf("\nlr rotation is required\n");
                return lrrotation(p);
            }
            else if(balancefactor(p)==-2&&balancefactor(p->rchild)==1)
            {
                printf("\nrl rotation is required\n");
                return rlrotation(p);
            }
            return p;
    };
    struct node*llrotation(struct node*p)
    {
        struct node*pl=p->lchild;
        struct node*plr=pl->rchild;

        p->lchild=plr;
        pl->rchild=p;
        p->height=nodeheight(p);
        pl->height=nodeheight(pl);

        if(root==p)
            root=pl;
        return pl;
    };
 struct node*rrrotation(struct node*p)
    {
        struct node*pr=p->rchild;
        struct node*prl=pr->lchild;

        p->rchild=prl;
        pr->lchild=p;
        p->height=nodeheight(p);
        pr->height=nodeheight(pr);

        if(root==p)
            root=pr;
        return pr;
    };

    struct node*lrrotation(struct node*p)
    {
        struct node*pl=p->lchild;
        struct node*plr=pl->rchild;
        p->lchild=plr->rchild;
        pl->rchild=plr->lchild;
        plr->lchild=pl;
        plr->rchild=p;

        p->height=nodeheight(p);
        pl->height=nodeheight(pl);
        plr->height=nodeheight(plr);
        if(root=p)
            root=plr;
        return plr;

    };
    struct node*rlrotation(struct node*p)
    {
        struct node*pr=p->rchild;
        struct node*prl=pr->lchild;
        p->rchild=prl->lchild;
        pr->lchild=prl->rchild;
        prl->lchild=p;
        prl->rchild=pr;
          p->height=nodeheight(p);
        pr->height=nodeheight(pr);
        prl->height=nodeheight(prl);
        if(root=p)
            root=prl;
        return prl;
    };



void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
