#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s1[80],s2[80],s[80];
        scanf("%s",&s1);
        scanf("%s",&s2);
        scanf("%s",&s);
        int l1=strlen(s1),l2=strlen(s2),l=strlen(s);
        int start=0;
        int n1=0;
        for(int j=0;j<l;j++)
        {
            int m=j;
            for(int k=m;k<m+l1;k++)
            {
                if(s1[k-m]==s[k])
                {
                    start++;
                }
                else
                {
                    start=0;
                    continue;
                }
            }
            if(start==l1)
            {
                n1=m+start;
                break;
            }
        }
        int end=l-1;
        int n2=0;
        for(int j=l-1;j>0;j--)
        {
            int m=j;
            for(int k=m;k>m-l2;k--)
            {
                if(s2[k-m+l2-1]==s[k])
                {
                    end--;
                }
                else
                {
                    end=l-1;
                    continue;
                }
            }
            if(end==l-1-l2)
            {
                n2=m-l2+2;
                break;
            }
        }
        printf("case #%d:\n",i);
        if(n2-n1<=1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",n2-n1-1);
        } 
    }
    return 0;
}