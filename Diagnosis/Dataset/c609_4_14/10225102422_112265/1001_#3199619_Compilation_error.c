
#include<stdio.h>
#define N 32;
int main()
{
    int n;
    scanf("%d",&n);
    int i,x,y,j,m;
    char s[N];
    for(i=0;i<n;i++)
    {
        while(scanf("%d%d",&x,&y)==2)
        {
            j=0;
            if(x>=0)
            {
            while(x!=0)
            {
                m=x%y;
                x=x/y;
                if(m<=9)
                    s[j]=m;
                else
                    s[j]=m-10+'A';
                    j++;
            }
            for(m=j-1;m>=0;m--)
            printf("%c",s[m]);
            printf("\n");
            }
            else
            {
                x=-x;
                printf("%c",'-');
                while(x!=0)
            {
                m=x%y;
                x=x/y;
                if(m<=9)
                    s[j]=m;
                else
                    s[j]=m-10+'A';
                    j++;
            }
            for(m=j-1;m>=0;m--)
            printf("%c",s[m]);
            printf("\n");
            }

        }
        printf("\n");
    }
    return 0;

}