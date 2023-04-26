#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    char c;
    int num=0;
    char* s;
    scanf("%d",&n);
    while((c=getchar())==' ' || c=='\n'); 
    for(int i=0;i<n;i++)
    {
    while(scanf("%s",&s)!=EOF)
    {
        num++;
    }
    printf("case #%d: \n",i);
    printf("%d\n",num);
    }
    return 0;
    
}