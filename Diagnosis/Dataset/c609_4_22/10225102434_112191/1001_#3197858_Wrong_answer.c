#include <stdio.h>
#include <stdlib.h>

void Turn(int x,int y)
{
    int i,j,n,k;
    char s[10000];
    if(x<0){
            k = x;
    x = -x;
    }
    for(i = 0;x>0;i++)
    {
        n = x%y;
        x = x/y;
        if(n<10) s[i] =n +'0';
        else s[i] = n+'A'-10;
    }
    if(k<0)printf("-");
    for(j = i-1;j>=0;j--)
    {
        printf("%c",s[j]);
    }
}
int main()
{
    int n ;
    scanf("%d",&n);
    int i;
    int s[n][2];
    for(i = 0;i<n;i++)
    {
        scanf("%d",&s[i][0]);
        scanf("%d",&s[i][1]);
    }

    for(i = 0;i<n;i++)
    {
        Turn(s[i][0],s[i][1]);
        printf("\n");
    }
    return 0;
}
