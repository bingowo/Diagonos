#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    int n;
    int res=1,i=0;
    do 
    {
        scanf("%d",&n);
        res=res<<n;
        printf("case #%d:\n",i);
        i++;
        printf("%d\n",res);
        
    }
    while((c=getchar())!=EOF);
    return 0;
}