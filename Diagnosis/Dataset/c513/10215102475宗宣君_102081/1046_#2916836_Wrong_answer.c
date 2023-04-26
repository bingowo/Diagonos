#include <stdio.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i<T;i++)
    {
        char s[1000];
        char *a;int n = 0;
        gets(s);
        a = strtok(s," ");
        while(a!=NULL)
        {
            if(strcmp(a,"the")== 0 || strcmp(a,"a")== 0 ||strcmp(a,"an")==0||strcmp(a,"of")==0||strcmp(a,"for")==0||strcmp(a,"and")==0);
            else n++;
            a = strtok(NULL," ");
        }
        printf("case #%d:\n%d\n",i,n);

    }
    return 0;
}