#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    unsigned long long a,b;scanf("%llu %llu",&a,&b);
    do{
        printf("%llu\n",a-b);
        scanf("%llu %llu",&a,&b);
    }while(a!=EOF&&b!=EOF);
    return 0;
}
