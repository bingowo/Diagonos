#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    
    int t,n;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        printf("case #%d:\n",j);
        scanf("%d",&n);
        double out1=pow(2,n);
        int out=(int)out1;
        printf("%d\n",out);
}
}
