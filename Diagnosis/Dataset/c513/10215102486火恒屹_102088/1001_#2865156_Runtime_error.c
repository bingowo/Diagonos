#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    int i=1;
    int num;
    int sit;
    int b;
    for(i=1;i++;i<=a)
    {
        scanf("%d %d",&num,&sit);
        while (num!=0)
        {
            b=num%sit;
            num=num/sit;
            if (b<=9) printf("&d",b);
            else printf("%s",b+31);
        }
        printf('\n');
    }
    return 0;
}
