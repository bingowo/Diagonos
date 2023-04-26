#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[200][200];
char s[500];
int ans=0;
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    ans+=a[0][0];
    for(int i=0,j=0;;)
    {
         int x=10002,y=10002;
         if(j<n-1) x=a[i][j+1];
         if(i<m-1) y=a[i+1][j];
         if(x<y)
         {
            ans+=x;
            s[k++]='R';
            j++;
         }
        else
         {
            ans+=y;
            s[k++]='D';
            i++;
         }
         if(i==m-1 && j==n-1) break;
    }
    printf("%d\n",ans);
    s[k]='\0';
    printf("%s",s);
    return 0;
}
