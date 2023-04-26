
#include<stdio.h>
#define N 32
int main()
{
    int n;
    scanf("%d",&n);
    int i,x,y,j,m;
    int s[N];
    for(i=0;i<n;i++)
    {
        while(scanf("%d%d",&x,&y)==2)
        {
            j=0;
            if(x>=0)
            {
            while(x!=0)
            {
                s[j]=x%y;
                x=x/y;
                j++;
            }
            for(m=j-1;m>=0;m--)
            {
                if(s[j]<=9)
                printf("%d",s[j]);
                else if(s[j]>9)
                printf("%c",s[j]-10+'A');
            }
            printf("\n");
            }
            else
            {
                x=-x;
                printf("%c",'-');
                while(x!=0)
            {
                s[j]=x%y;
                x=x/y;
                j++;
            }
            for(m=j-1;m>=0;m--)
            {
                if(s[j]<=9)
                printf("%d",s[j]);
                else if(s[j]>9)
                printf("%c",s[j]-10+'A');
            }
            printf("\n");
            }

        }
        printf("\n");
    }
    return 0;

}