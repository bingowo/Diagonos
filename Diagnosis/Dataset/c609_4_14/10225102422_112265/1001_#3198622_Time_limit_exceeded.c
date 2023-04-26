
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,x,y;
    for(i=0;i<n;i++)
    {
        while(scanf("%d%d",&x,&y)==2)
        {
            if(x>=0)
            {
            while(x!=0)
            {
                int m=x%y;
                if(m<=9)
                    printf("%d",m);
                else
                    printf("%c",m-10+'A');
            }
            printf("\n");
            }
            else
            {
                x=-x;
                printf("%c",'-');
                while(x!=0)
            {
                int m=x%y;
                if(m<=9)
                    printf("%d",m);
                else
                    printf("%c",m-10+'A');
            }
            printf("\n");
            }

        }
        printf("\n");
    }
    return 0;

}