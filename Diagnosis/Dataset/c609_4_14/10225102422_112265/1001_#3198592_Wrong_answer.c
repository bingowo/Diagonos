#include <stdio.h>
#include <stdlib.h>
#define N 32
int main()
{
    int n;
    scanf("%d",&n);
    int s[N];
    int i,j,x,y;
    for(i=0,j=0;i<n;i++)
    {
        while(scanf("%d%d",&x,&y)!=EOF)
        {
            if(x<0)
            {
                x=-x;
                while(x!=0)
                {
                    x=x/y;
                    s[j]=x%y;
                    if(s[j]>9)
                    s[j]=s[j]-10+'A';
                    j++;
                    
                }
                printf("%c",'-');
                for(int l=0;l<j;l++)
                    printf("%d",s[j]);
            }
            else
            {
                while(x!=0)
                {
                    x=x/y;
                    s[j]=x%y;
                    if(s[j]>9)
                    s[j]=s[j]-10+'A';
                    j++;
                    
                }
                for(int l=0;l<j;l++)
                    printf("%d",s[j]);
            }
            printf("\n");

        }
    }
    return 0;

}