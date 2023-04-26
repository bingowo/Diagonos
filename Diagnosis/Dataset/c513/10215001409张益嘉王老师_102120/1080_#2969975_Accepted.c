#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int re[],int wei)
{
    int i;
    for(i=0;i<wei/2;i++)
    {
        int m;
        m=re[i];
        re[i]=re[wei-1-i];
        re[wei-1-i]=m;
    }
}

int zhuanint(char *s,int*a)
{
    int len=strlen(s),i;
    for(i=0;i<len;i++)
    {
        a[i]=s[i]-'0';
    }
    return len;
}

int chu2(int *a,int la)
{

    int i,j,jie=0,xin;
    for(i=la-1;i>=0;i--)
    {
        xin=jie*10+a[i];
        a[i]=xin/2;
        jie=xin%2;
    }
    reverse(a,la);
    int st=-1;
    for(i=0;i<la;i++)
    {
        if(a[i]!=0) break;
    }
    st=i;
    for(i=0;i<la-st;i++)
    {
        a[i]=a[i+st];
    }
    for(i=la-st;i<120;i++)
    {
        a[i]=0;
    }
    return la-st;

}

int erjinzhi(int *a,int la,int *b)
{

    int co=0;
    while(la>0)
    {
        reverse(a,la);
        b[co++]=a[0]%2;
        la=chu2(a,la);
    }
    return co;
}

int cheng(int re[],int n)
{
    //printf("test:");
    int i,j,jin=0;
    for(i=0;(jin!=0)||(re[i]!=-1);i++)
    {
        if(re[i]==-1) re[i]=0;
        int mid=re[i]*n+jin;
        jin=mid/10;
        re[i]=mid%10;
        //printf("%d",re[i]);
    }
    //printf("\n");
    return i;
}

int jia(int*re,int jin,int wei)
{
    int i;
    for(i=0;(jin!=0)||(i<wei);i++)
        {
            if(re[i]==-1) re[i]=0;
            int mid=re[i]+jin;
            jin=mid/10;
            re[i]=mid%10;
            //printf("%d",z[i]);
        }
        return i;
}

int zhuan10(int *b,int lb,int *c)
{
    int i,lc,mid=0;
    c[mid++]=b[0];
    for(i=0;i<lb-1;i++)
    {
       mid=cheng(c,2);
       mid=jia(c,b[i+1],mid);
    }
    return mid;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[120];
        int a[120],co,b[400],len,c[400],wei,j;
        memset(a,0,sizeof(int)*120);
        memset(b,0,sizeof(int)*400);
        memset(c,-1,sizeof(int)*400);
        scanf("%s",s);

        len=zhuanint(s,a);

        /*printf("\ntest:a=");
        for(j=0;j<len;j++)
        {
            printf("%d ",a[j]);
        }*/

        co=erjinzhi(a,len,b);

        /*printf("\ntest:b=");
        for(j=0;j<co;j++)
        {
            printf("%d ",b[j]);
        }*/
        wei=zhuan10(b,co,c);

        /*printf("\ntest:c=");
        for(j=0;j<wei;j++)
        {
            printf("%d ",c[j]);
        }*/
        reverse(c,wei);
        printf("case #%d:\n",i);
        for(j=0;j<wei;j++)
        {
            if(c[j]==-1) break;
            printf("%d",c[j]);
        }
        printf("\n");
    }
    return 0;

}
