#include <stdio.h>
#include <string.h>


void carry(int a[],int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        if(a[i] >= 10)
        {
            a[i] -= 10;
            a[i + 1]++;
        }
    }
    if(a[len - 1] >= 10)
    {
        a[len - 1] -= 10;
        a[len]++;
        len++;
    }
}
int jud(int a[],int len)
{
    for(int i = len - 1; i > 0; i--)
    {
        if(a[i] == a[i - 1])
            return i;
    }
    return 0;
}
void func(int a[],int len)
{
    a[0]++;
    carry(a,len);
    while(jud(a,len))
    {
        a[0]++;
        carry(a,len);
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        char str[1000000000000000000000];
        int a[5000];
        scanf("%s",str);
        memset(a,0,sizeof(a));
        int len = (int)strlen(a);
        for(int i = 0, j = len - 1; i < len; i++, j--)
        {
            a[i] = str[j] - '0';
        }
        func(a,len);
        printf("case #%d:\n",i);
        for(int i = len - 1; i >= 0; i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}



