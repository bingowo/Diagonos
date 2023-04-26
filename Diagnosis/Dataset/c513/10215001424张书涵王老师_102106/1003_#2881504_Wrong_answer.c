#include <stdio.h>
#include <stdlib.h>

int cmp(const void *ele1,const void *ele2)
{
    char c[2][64];
    int a1,b1;
    int i;
    a1=*(int*)ele1;
    b1=*(int*)ele2;
        if(a1<0)
    {
        a1=(-1)*a1;
        for(i=0;i<64;i++)
        {
            c[0][i]=a1%2+48;
            a1=a1/2;
            if(c[0][i]=='0')
                c[0][i]='1';
            else
                c[0][i]='0';
        }
        c[0][0]=c[0][0]+1;
        for(i=0;c[0][i]=='2';i++)
        {
            c[0][i]='0';
            c[0][i+1]=c[0][i+1]+1;
        }
    }
    else
    {
        for(i=0;i<64;i++)
        {
            c[0][i]=a1%2+48;
            a1=a1/2;
        }
    }
        if(b1<0)
    {
        b1=(-1)*b1;
        for(i=0;i<64;i++)
        {
            c[1][i]=b1%2+48;
            b1=b1/2;
            if(c[1][i]=='0')
                c[1][i]='1';
            else
                c[1][i]='0';
        }
        c[1][0]=c[1][0]+1;
        for(i=0;c[1][i]=='2';i++)
        {
            c[1][i]='0';
            c[1][i+1]=c[1][i+1]+1;
        }
    }
    else
    {
        for(i=0;i<64;i++)
        {
            c[1][i]=b1%2+48;
            b1=b1/2;
        }
    }
    int b[2]={0,0};
    for(i=0;i<64;i++)
    {
        if(c[0][i]=='1')
            b[0]=b[0]+1;
    }
    for(i=0;i<64;i++)
    {
        if(c[1][i]=='1')
            b[1]=b[1]+1;
    }
    if(b[0]==b[1])
        return (a1-b1);
    else
        return (b[1]-b[0]);
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int t,j;
        scanf("%d",&t);
        int a[t];  //b存储的是a数字二进制中的1的个数
        for(j=0;j<t;j++)
        {
            scanf("%d",&a[j]);  //a存储的是数字
        }
        qsort(a,t,sizeof(int),cmp);
        printf("case #%d\n",i);
        int l;
        for(l=0;l<t;l++)
            printf("%d ",a[l]);
        printf("\n");
    }
    return 0;
}

