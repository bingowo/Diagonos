#include <stdio.h>
#include <stdlib.h>
int length[52]={0};
int sign[52]={0};

int cmp(int a[],int b[],int pa,int pb)
{
    if (sign[pa]>sign[pb]) return 1;
    else if(sign[pa]<sign[pb]) return 0;
    int flag;
    if (length[pa]>length[pb]) flag=1;
    else if (length[pa]<length[pb]) flag=0;
    else
    {
        for(int i=120-length[pa]+1;i<=120;i++)
        {
            if(a[i]>b[i]){flag=1;break;}
            else if(a[i]<b[i]){flag=0;break;}
        }
    }
    if(sign[pa]==1)
        return flag;
    else return 1-flag;
}
int main()
{
    int num[51][122]={0};
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        char c;
        c=getchar();
        if(c=='-')
            sign[i]=-1;
        else ungetc(c,stdin);
        c=getchar();
        int j=120;
        while(c!=10)
        {
            num[i][j]=c-'0';
            j=j-1;
            c=getchar();
        }
        length[i]=120-j;
    }
    int min=0;
    int max=0;
    for(int i=1;i<N;i++)
    {
        if(cmp(num[i],num[min],i,min)==0) min=i;
        if(cmp(num[i],num[max],i,max)==1) max=i;
    }
    int res[122]={0};
    if(sign[max]==0&&sign[min]==0)
    {
        for(int i=0;i<=120;i++)
            res[i]=num[max][i]-num[min][i];
        for(int i=120;i>=0;i=i-1)
        {
            if(res[i]<0)
            {
                res[i]=res[i]+10;
                res[i-1]=res[i-1]-1;
            }
        }
    }
    else if(sign[max]==0&&sign[min]==-1)
    {
        for(int i=0;i<=120;i++)
            res[i]=num[max][i]+num[min][i];
        for(int i=120;i>=0;i=i-1)
        {
            if(res[i]>=10)
            {
                res[i]=res[i]-10;
                res[i-1]=res[i-1]+1;
            }
        }
    }
    if(sign[max]==-1&&sign[min]==-1)
    {
        for(int i=0;i<=120;i++)
            res[i]=num[min][i]-num[max][i];
        for(int i=120;i>=0;i=i-1)
        {
            if(res[i]<0)
            {
                res[i]=res[i]+10;
                res[i-1]=res[i-1]-1;
            }
        }
    }
    int v=0;
    while(res[v]==0)
        v++;
    for(int i=v;i<=120;i++)
        printf("%d",res[i]);
    return 0;
}
