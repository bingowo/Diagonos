#include<stdio.h>


int CountZero(int n)
{
    int count = 0;
    if (n)return -1;
    for (int i = 5; n / i > 0; i *= 5)
        count += n / i;
    return count;
}
int main()
{
    int i,t;
    scanf("%d",&t);
    int N;
    for(i=0;i<y;i++){
        scanf("%d",&N);
        printf("case #%d\n",i);
        printf("%d",CountZero(N));
    }
}