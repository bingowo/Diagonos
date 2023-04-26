#include <stdio.h>
#include <stdlib.h>
void jisuan(int h)
{
    int n=0;
    scanf("%d",&n);
    int i=0;long long a=1;
    for(i=0;i<n;i++){a=a*2;}
    printf("case #%d:\n",h);
    printf("%lld\n",a);
    return 0;
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
