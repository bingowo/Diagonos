#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,k;scanf("%d",&T);
    char s[T][101],c[T][101];int i,j,d[T][101];
    for(i=0;i<T;i++)
    {
        scanf("%s",s[i]);
        for(j=0;j<strlen(s[i]);j++)
        {
            if(j==0){k=0;d[i][k]=1;c[i][k]=s[i][j];}
            else if(s[i][j]!=s[i][j-1]){k++;d[i][k]=1;c[i][k]=s[i][j];}
            else d[i][k]++;
        }
        c[i][k+1]='\0';
    }int flag=0;
    for(i=0;i<=k&&flag==0;i++)
    {
        for(j=1;j<T&&flag==0;j++)if(c[j][i]!=c[0][i])
        {flag=1;break;}
    }
    for(i=1;i<T;i++)
    if(strlen(c[i])!=strlen(c[0])){flag=1;break;}
    if(flag==1)printf("-1");
    else
    {
        int max[k+1],min[k+1];
        for(i=0;i<=k;i++)
        {
            max[i]=0;min[i]=100;
            for(j=0;j<T;j++)
             {
                 max[i]=max[i]>d[j][i]? max[i]:d[j][i];
                 min[i]=min[i]<d[j][i]? min[i]:d[j][i];
             }
        }
        int sum=0;
        for(j=0;j<=k;j++)
        {
            int n=100;
            for(i=min[j];i<=max[j];i++)
            {
                int temp=0;
                for(int e=0;e<T;e++)
                temp+=abs(d[e][j]-i);
                if(n>temp)n=temp;
            }
            sum+=n;
        }
        printf("%d",sum);
    }
}
