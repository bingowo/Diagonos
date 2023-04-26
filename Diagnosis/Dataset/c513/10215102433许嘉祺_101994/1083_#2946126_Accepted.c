#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int t;
    scanf("%d",&t);
    int a;
    for (int i=0;i<t;i++){
        scanf("%d",&a);
        int count=0;
        int b=5;
        while (a>=b){count+=a/b;b=b*5;}
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }



    return 0;
}
