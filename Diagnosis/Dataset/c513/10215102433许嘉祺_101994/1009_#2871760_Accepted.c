#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    int t,a,b;
    char s[240];
    scanf("%d",&t);
    int c=getchar();
    for (int i=0; i<t; i++)
    {
        scanf("%[^\n]",s);

        a=0;
        b=strlen(s)*8;
        for (int j=0; j<strlen(s); j++)
        {
            for (int k=0;k<8;k++)
                if ((s[j]>>k)&1==1) a++;
        }
        for (int j=2;j<=a;j++)
        if (b%j==0&&a%j==0) {b=b/j;a=a/j;j--;}
        printf("%d/%d\n",a,b);
        c=getchar();
    }
    return 0;
}
