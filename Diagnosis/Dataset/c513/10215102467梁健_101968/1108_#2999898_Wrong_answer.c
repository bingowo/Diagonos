#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        double a,b;scanf("%lf %lf",&a,&b);
        printf("%lf\n",a/b);
    }
    return 0;
}
