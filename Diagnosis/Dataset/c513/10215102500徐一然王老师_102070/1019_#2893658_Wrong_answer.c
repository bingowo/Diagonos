#include <stdio.h>
#include <stdlib.h>

typedef struct team{int name;int point;int win;int lose;}Team;

int cmp(const void*a, const void*b)
{
    Team* p1;
    Team* p2;
    p1=(Team*)a;
    p2=(Team*)b;
    if(p1->point<p2->point)
    {
        return 1;
    }
    else if(p1->point>p2->point)
    {
        return -1;
    }
    else if(p1->point==p2->point&&p1->win<p2->win)
    {
        return 1;
    }
    else if(p1->point==p2->point&&p1->win>p2->win)
    {
        return -1;
    }
    else if(p1->lose>p2->lose)
    {
        return 1;
    }
    else if(p1->lose<p2->lose)
    {
        return -1;
    }
    else if(p1->name<p2->name)
    {
        return -1;
    }
    else if(p1->name>p2->name)
    {
        return 1;
    }


}

int main()
{

    int n,m,a,b,c;
    while(1)
    {
        Team A[10];
        Team *p3=A;
        for(int i=0;i<10;i++)
        {
            A[i].name=i+1;
            A[i].point=0;
            A[i].win=0;
            A[i].lose=0;
        }
        scanf("%d %d",&n,&m);
        if(m==0&&n==0)
            break;
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                A[a-1].point=A[a-1].point+3;
                A[b-1].point=A[b-1].point-1;
                A[a-1].win=A[a-1].win+1;
                A[b-1].lose=A[b-1].lose+1;
            }
            else if(c==-1)
            {
                A[a-1].point=A[a-1].point-1;
                A[b-1].point=A[b-1].point+3;
                A[a-1].lose=A[a-1].lose+1;
                A[b-1].win=A[b-1].win+1;
            }
            else
            {
                A[a-1].point=A[a-1].point+1;
                A[b-1].point=A[b-1].point+1;
            }
        }
        qsort(p3,10,sizeof(A[0]),cmp);
        for(int j=0;j<n;j++)
        {
            if(j==n-1)
            {
                printf("%d",A[j].name);
            }
            else
            printf("%d ",A[j].name);
        }


    }

}
