#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    char s;
    int i=0,j=0;
    int n=0,m=0,L=0,tm=0,tn=0;
    int c=0;
    int f=0,t=0,p=0;
    int A[500]={0},B[500]={0};
    int res[500]={0};
    while((s=getchar())!=EOF)
    {
        if(s=='\n')
        {
            f=0;
            n=0;
            i=0;
            j=0;
            m=0;
            c=0;
            L=0;
            t=0;
            tm=0;
            p=0;
            tn=0;
            for(i=0;i<500;i++)
            {
                A[i]=0;
                B[i]=0;
                res[i]=0;
            }

        }
        else if(s==' ')
        {
            f=1;
        }
        else if(('0'<=s)&&(s<='9'))
        {
            if(f==0)
            {
                A[n]=s-'0';
                n++;
            }
            if(f==1)
            {
                B[m]=s-'0';
                m++;
            }
        }
        if(m>n)
        {
            L=m;
            p=1;
            for(i=0;i<L;i++)
            {
                swap(&A[i],&B[i]);
            }
            swap(&n,&m);
        }
        else if(m==n)
        {
            L=n;
            p=0;
            for(i=0;i<L;i++)
            {
                if(A[i]>B[i])
                {
                    p=0;
                    break;
                }
                if(B[i]>A[i])
                {
                    p=1;
                    break;
                }
            }
            if(p==1)
            {
                for(i=0;i<L;i++)
                {
                    swap(&A[i],&B[i]);
                }
            }
        }
        else
        {
            p=0;
            L=n;
        }
        tn=n;
        tm=m;
        for(i=L-1;i>=0;i--)
        {
            if(tm>=1)
            {
                t=A[tn-1]-B[tm-1]-c;
            }
            else if(tm<1)
            {
                t=A[tn-1]-c;
            }
            if(t<0)
            {
                c=1;
                res[i]=10+t;
            }
            else
            {
                res[i]=t;
                c=0;
            }
            tm--;
            tn--;
        }
        f=0;
        if(p==1)
            printf("-");
        for(i=0;i<L;i++)
        {
            if(res[i]==0)
            {
                if(f==1)
                    printf("%d",res[i]);
            }
            else
            {
                f=1;
                printf("%d",res[i]);
            }
        }
        printf("\n");
    }
    return 0;
    
}