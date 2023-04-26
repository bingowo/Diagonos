#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        scanf("%s",&s);
        int k=0;
        for(int j=0;j<strlen(s);j++)
        {
            int d=1;
            if(s[j]=='-'){d=-1;}
            if(s[j]=='0'){d=0;}
            k=k*3+d;

        }
        printf("case #%d:\n",i);
        printf("%d\n",k);
    }
    return 0;
}
