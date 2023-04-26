#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int m[9][10000]={0};
    m[1][0]=1;
    for(int i=2;i<=8;i++)
    {
        int num=pow(2,i-1);
        for(int j=0;j<num;j++)
        {
            m[i][j]=m[i-1][j/2]*10;
            j++;
            m[i][j]=m[i-1][j/2]*10+1;
        }
    }
    int ans=0;
    int flag=0;
    int a;
    scanf("%d",&a);
    for(int i=1;i<=8;i++)
    {
        int num=pow(2,i-1);
        for(int j=0;j<num;j++)
        {
           if(m[i][j]!=0&&flag==0&&m[i][j]%a==0)
           {
               ans=m[i][j];
               flag++;
           }
           else continue;
        }
    }
    if(ans<10000000) printf("%d",ans);
    else printf("-1");
}
