#include <stdio.h>
#include <stdlib.h>
int count(int N,int R)
{
    int a[100];
    int i=0;
    while(N/R!=0){
        if(N<0){N=-N;printf("-");}
        a[i]=N%R;
        N=N/R;
        i++;
    }
    if(N>=10)printf("%c",'A'+N-10);
    else printf("%d",N);
    for(int j=i-1;j>=0;j--)
        {
        if(a[j]>=10)printf("%c",'A'+a[j]-10);
        else printf("%d",a[j]);
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    int s[T+1][2];
    for(int i=0;i<T;i++)
        scanf("%d%d",&s[i][0],&s[i][1]);
    for(int i=0;i<T;i++)
        {count(s[i][0],s[i][1]);printf("\n");}
    return 0;
}
