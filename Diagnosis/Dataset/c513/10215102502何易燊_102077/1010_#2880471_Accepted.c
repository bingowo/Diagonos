#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int n,int k)
{
    for (int i=k-1;i>=0;i--) printf("%d",(n>>i)&1);
}

main()
{
    char s[501] = {};
    scanf("%s",s);
    int rec = 0, num = 0;
    printf("0001"); print(strlen(s),10);
    for (int i=0;s[i];i++)
    {
        num = num * 10 + s[i] - '0';
        rec++;
        if (rec==3) {rec = 0; print(num,10); num = 0;}
    }
    if (rec) print(num,rec*3+1);
    system("pause");
    return 0;
}