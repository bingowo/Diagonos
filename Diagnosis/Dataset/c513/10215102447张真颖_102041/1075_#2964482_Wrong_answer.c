#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[200][200]={0};
    char path[400]={0};
    long int sum=0,step=0;
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    sum=a[0][0];
    for(int i=0,j=0;!(i==m-1&&j==n-1);)
    {
        if(a[i][j+1]<a[i+1][j]&&j+1<n&&i+1<m)
            path[step]='R',step+=1,sum+=a[i][j+1],j+=1;
        else
            path[step]='D',step+=1,sum+=a[i+1][j],i+=1;
    }
    printf("%ld\n%s",sum,path);
    return 0;
}