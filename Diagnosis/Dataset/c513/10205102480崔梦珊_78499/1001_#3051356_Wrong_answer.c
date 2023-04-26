#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
        int n,r;
        scanf("%d",&n);
        scanf("%d",&r);
        if(n>0&&r<10)
        {
            int s[1000];
            int j=0;
            int chu=n/r;
            int yu=n%r;
            s[0]=yu;
            while(chu!=0)
            {
                j++;
                yu=chu%r;
                chu=chu/r;
                s[j]=yu;
            }
            for(j;j>=0;j--)
            {
                printf("%d",s[j]);
            }
        }
        else if(n<0&&r<10)
        {
            n=-n;
            int s[1000];
            int j=0;
            int chu=n/r;
            int yu=n%r;
            s[0]=yu;
            while(chu!=0)
            {
                j++;
                yu=chu%r;
                chu=chu/r;
                s[j]=yu;
            }
            printf("-");
            for(j;j>=0;j--)
            {
                printf("%d",s[j]);
            }
        }
        else if(n>0&&r>=10)
        {
            char s[1000];
            char temp;
            int j=0;
            int chu=n/r;
            int yu=n%r;
            if(yu>9)
            {
                temp=yu+55;
            }
            else
            {
                temp=yu+48;
            }
            s[0]=temp;
            while(chu!=0)
            {
                j++;
                yu=chu%r;
                chu=chu/r;
                if(yu>9)
            {
                temp=yu+55;
            }
            else
            {
                temp=yu+48;
            }
                s[j]=temp;
            }
            for(j;j>=0;j--)
            {
                printf("%c",s[j]);
            }
        }
         else if(n<0&&r>=10)
        {
            n=-n;
            char s[1000];
            char temp;
            int j=0;
            int chu=n/r;
            int yu=n%r;
            if(yu>9)
            {
                temp=yu+55;
            }
            else
            {
                temp=yu+48;
            }
            s[0]=temp;
            while(chu!=0)
            {
                j++;
                yu=chu%r;
                chu=chu/r;
                if(yu>9)
            {
                temp=yu+55;
            }
            else
            {
                temp=yu+48;
            }
                s[j]=temp;
            }
            for(j;j>=0;j--)
            {
                printf("%c",s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
