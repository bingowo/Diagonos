#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int llu;
llu a,b;
int main()
{
    while(scanf("%llu %llu",&a,&b)!=EOF){
    
    llu c=a-b;
    printf("%llu\n",c);
}
}
