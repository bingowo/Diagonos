#include <stdio.h>
#include <math.h>
int main()
{
    int N,i = 0;
    while(scanf("%d",&N)!=EOF)
    {
        printf("case #%d:\n",i++);
        printf("%d\n",(int)pow(2,N));
    }
    return 0;
}
