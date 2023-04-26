#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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
        int a,b,j;
        scanf("%d %d",&a,&b);
        if(x[k]==0||y[k]==0)
        {
            if(x[k]==0&&y[k]!=0)b=b-abs(b/y[k])*y[k];
            else if(x[k]!=0&&y[k]==0)a=a-abs(a/x[k])*x[k];
            for(j=0;j<=strlen(s);j++)
            {
                if(a==x[j]&&b==y[j]){printf("Yes\n");break;}
            }
            if(j>strlen(s))printf("No\n");
        }
        else
        {
            for(j=1;j<=k;j++)
            {
                if((a-x[j])%x[k]==0&&(b-y[j])%y[k]==0)
                {
                    if((a-x[j])/x[k]==(b-y[j])/y[k]){printf("Yes\n");break;}
                }
            }
            if(j>k)printf("No\n");
        }
    }
}
