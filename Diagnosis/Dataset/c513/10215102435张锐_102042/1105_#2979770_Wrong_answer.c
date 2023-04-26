#include <stdio.h>
#include <stdlib.h>
int zhuan(int *s)
{
    int t=1,num=0;
    for(int i=7;i>=0;i--)
    {
        num+=t*s[i];
        t=t*2;
    }
    for(int i=6;i>=0;i--)
    {
        int temp=0;t=1;
        for(int j=0;j<8;j++)
        {
            if((i-j)>=0) temp+=t*s[i-j];
            else temp+=t*s[i-j+8];
            t=t*2;
        }
        if(temp<num) num=temp;
    }
    return num;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int **p=(int **)malloc(a*sizeof(int *));
    int **ans=(int **)malloc((a-2)*sizeof(int*));
    for(int i=0;i<a-2;i++)
    {
        ans[i]=(int *)malloc((b-2)*sizeof(int));
    }
    for(int i=0;i<a;i++)
    {
        p[i]=(int *)malloc(b*sizeof(int));
        for(int j=0;j<b;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    for(int x=1;x<a-1;x++)
    {
        for(int y=1;y<b-1;y++)
        {
            int temp=p[x][y];
            int s[8]={0};
            if(p[x-1][y-1]>=temp) s[0]=1;
            if(p[x-1][y]>=temp) s[1]=1;
            if(p[x-1][y+1]>=temp) s[2]=1;
            if(p[x][y+1]>=temp) s[3]=1;
            if(p[x+1][y+1]>=temp) s[4]=1;
            if(p[x+1][y]>=temp) s[5]=1;
            if(p[x+1][y-1]>=temp) s[6]=1;
            if(p[x][y-1]>=temp) s[7]=1;
            ans[x-1][y-1]=zhuan(s);
        }
    }
    for(int i=0;i<a-2;i++)
    {
        for(int j=0;j<b-2;j++)
        {
            printf("%d",ans[i][j]);
            if(j!=b-3) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
