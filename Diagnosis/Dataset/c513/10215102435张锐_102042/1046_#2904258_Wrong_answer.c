#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int num=0;
        char s[100]={'0'};
        do{
            scanf("%s",s);
            num++;
        }while(getchar()!='\n');
        printf("%d",num);
    }
}