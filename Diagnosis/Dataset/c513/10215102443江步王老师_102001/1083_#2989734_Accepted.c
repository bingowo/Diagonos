#include<stdio.h>
#define N1 3000
#define N2 4


void add_1(int *a);
void mul(int *a, int *b);
int main()
{
    int i,j;
    int t;
    int n;
    scanf("%d",&t);

    for (i=0;i<t;++i)
    {
        scanf("%d",&n);
        int res[N1]={1,0};
        int temp[N2]={0};        
        

        for (j=1;j<=n;++j)
        {
            add_1(temp);
            mul(res,temp);
        }

        int pos;
        for (j=N1-1;j>=0;--j)
        {
            if (res[j]!=0)
            {
                pos=j;break;
            }
        }
        printf("case #%d:\n",i);
        
        int cnt=0;
        for(j=0;j<=pos;++j)
        {
            if (!res[j])
            {
                cnt++;
                continue;
            }
            else
            {
                break;
            }
        }
        printf("%d\n",cnt);

    }

    return 0;
}

void add_1(int *a)
{
    int i;
    int c;
    a[0]+=1;
    for (i=0;i<4-1;++i)
    {
        c=a[i]/10;
        a[i+1]+=c;
        a[i]=a[i]%10;
    }
    return ;
}

void mul(int *a, int *b)
{
    int la=0,lb=0;
    //la与lb保存此刻a,b的位数
    int i,j;
    int c=0;
    int res[N1]={0};

    for (i=N1-1;i>=0;--i)
    {
        if (a[i]!=0)
        {
            la=i;break;
        }
    }

    for (i=N2-1;i>=0;--i)
    {
        if (b[i]!=0)
        {
            lb=i;break;
        }
    }

    for (i=0;i<=lb;++i)
    {
        for (j=0;j<=la;++j)
        {
            res[i+j]+=a[j]*b[i];
            res[i+j+1]+=res[i+j]/10;
            res[i+j]=res[i+j]%10;
        }
    }

    for (i=0;i<N1;++i)
    {
        a[i]=res[i];
    }
    return;
}