#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,x,y,m;
    for(i=0;i<n;i++)
    {
        while(scanf("%d%d",&x,&y)!=EOF)
        {
            while(x!=0)
            {
                m=x%y;
                x=x/y;
                if(m<=9)
                    printf("%d",m);
                else if(m>9)
                    printf("%c",m-10+'A');

            }

        }
    printf("\n");
    }
    return 0;

}