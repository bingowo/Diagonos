#include<stdio.h>
int main()
{
    int t;
    int i=0,j=0,p=0,num=0,sz=0;
    int s[]={0};
    scanf("%d\n",&t)!=EOF;
    char a[61];
    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        while(scanf("%s\n",a)!=EOF)
        {
            printf("%s\n",a);
        }
    }
    return 0;
}