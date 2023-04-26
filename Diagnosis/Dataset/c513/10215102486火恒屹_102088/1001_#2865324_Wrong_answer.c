#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    char c[100]={'\0'};
    scanf("%d",&a);
    int i=1;
    int num;
    int sit;
    int b;
    for(i=0;i<a;i++)
    {
        scanf("%d %d",&num,&sit);
        int j=0;
        while (num!=0)
        {
            b=num%sit;
            num=num/sit;
            if (b<=9) c[j]=b+48;
            else c[j]=b+55;
            j=j+1;
        }
        printf("%s\n",c);
    }
    return 0;
}
