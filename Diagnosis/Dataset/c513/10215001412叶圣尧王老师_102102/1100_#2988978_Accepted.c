#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int solution(int t,int r)
{
    if (t==0&&r!=0) return -2;
    if (t==0&&r==0) return -1;
    if (r%t!=0||r/t<0) return -2;
    return r/t;                                      
}

int main()
{
    char s[101];scanf("%s",s);int x[101]={0},y[101]={0};
    int q,i;scanf("%d",&q);int k=strlen(s);
    for(i=1;i<=strlen(s);i++)
    {
        if(s[i-1]=='U'){x[i]=x[i-1];y[i]=y[i-1]+1;}
        else if(s[i-1]=='D'){x[i]=x[i-1];y[i]=y[i-1]-1;}
        else if(s[i-1]=='L'){x[i]=x[i-1]-1;y[i]=y[i-1];}
        else {x[i]=x[i-1]+1;y[i]=y[i-1];}
    }
    for(i=0;i<q;i++)
    {
        int a,b,j,flag=0;
        scanf("%d %d",&a,&b);
        for(j=0;j<=k;j++)
        {
            int m1=solution(-x[k],x[j]-a);
            int m2=solution(-y[k],y[j]-b);
            if(m1==-2||m2==-2)continue;
            if(m1==-1||m2==-1||m1==m2){flag=1;break;}
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
}
