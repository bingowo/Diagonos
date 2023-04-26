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
        if (m=0) continue;
        struct team t[n];      
        for (int i=1;i<=n;i++)
        {
            t[i-1].num=i;
            t[i-1].score=0;
            t[i-1].win=0;
            t[i-1].loss=0;
        }
            
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
                if (t[j].score>t[j-1].score)
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
        for (int i=0;i<n;i++)
        {
            if (i!=n-1) printf("%d ",t[i].num);
            else printf("%d\n",t[i].num);
        }
    }while(!(m==n&&n==0));
}