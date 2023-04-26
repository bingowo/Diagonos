#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    scanf("%d\n",&a);
    char s[100];
    for (int i=0;i<=a-1;i++)
    {
        scanf("%s\n",s);
        int l=strlen(s);
        int n=0;
        int x;
        int y=1;
        printf("case #%d:\n",i);
        for (int j=0;j<=l;j++)
        {
            if (s[j]=='1')
                x=1;
            else if (s[j]=='0')
                x=0;
            else if (s[j]=='-')
                x=-1;
            n+=x*y;
            y*=3;
        }
        printf("%d\n",n);
    }
}
