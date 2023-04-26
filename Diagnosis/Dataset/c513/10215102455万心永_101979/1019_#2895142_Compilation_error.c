#include<stdio.h>
#include<stdlib.h>

struct team
{
    int num;
    int score;
    int win;
    int loss;
};

int cmp(const void* a,const void* b);

int main()
{
    int m,n,a,b,c;
    do
    {
        scanf("%d%d",&n,&m);
        struct team t[n];      
        for (int i=1;i<=n;i++)
            t[i-1]={i,0,0,0};
            
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if (c==1)
            {
                t[a-1].score+=3;t[a-1].win++;
                t[b-1].score--;t[b-1].loss++;
            }
            else if(c==-1)
            {
                t[a-1].score--;t[a-1].loss++;
                t[b-1].score+=3;t[b-1].win++;
            }
            else if(c==0)
            {
                t[a-1].score++;t[b-1].score++;
            }
        }
        struct team temp;
        for (int i=0;i<n-1;i++)
        {
            for (int j=n-1;j>i;j--)
            {
                if (t[j].score<t[j-1].score)
                {
                    temp=t[j];t[j]=t[j-1];t[j-1]=temp;
                }
                else if (t[j].score==t[j-1].score)
                {
                    if (t[j].win>t[j-1].win)
                    {
                        temp=t[j];t[j]=t[j-1];t[j-1]=temp;
                    }
                    else if (t[j].win==t[j-1].win)
                    {
                        if (t[j].loss<t[j-1].loss)
                        {
                            temp=t[j];t[j]=t[j-1];t[j-1]=temp;
                        }
                        else if (t[j].loss==t[j-1].loss)
                        {
                            if (t[j].num<t[j-1].num)
                            {
                                temp=t[j];t[j]=t[j-1];t[j-1]=temp;
                            }
                        }
                    }
                }
            }
        }
        //qsort(t,n,sizeof(struct team),cmp);
        for (int i=0;i<n;i++)
        {
            if (i!=n-1) printf("%d ",t[i].num);
            else printf("%d\n",t[i].num);
        }
    }while(m!=0&&n!=0);
}

int cmp(const void* a,const void* b)
{
    struct team *x,*y;
    x=(struct team *)&a;y=(struct team *)&b;
    if (x->score<y->score)  return 1;
    else if (x->score>y->score) return -1;
    else if (x->score==y->score)
    {
        if (x->win<y->win)    return 1;
        else if (x->win>y->win)  return -1;
        else if (x->win==y->win)
        {
            if (x->loss>y->loss)    return 1;
            else if (x->loss<y->loss)  return -1;
            else if (x->loss==y->loss)
            {
                if (x->num>y->num)  return 1;
                else return -1;
            }
        }
    }
    return -1;
}