#include<string.h>
#include<stdio.h>
int main()
{
    int T;
    int i,j,k;
    int n=0;
    char c;
    char s;
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
    {
        scanf("%s",&s);
        n=0;
        while((c=getchar())!='\n')
        {
            if(strcmp(s,"the")==0)
            {
                ;
            }
            else if(strcmp(s,"a")==0)
            {
                ;
            }
            else if(strcmp(s,"A")==0)
            {
                ;
            }
            else if(strcmp(s,"An")==0)
            {
                ;
            }
            else if(strcmp(s,"The")==0)
            {
                ;
            }
            else if(strcmp(s,"an")==0)
            {
                ;
            }
            else if(strcmp(s,"of")==0)
            {
                ;
            }
            else if(strcmp(s,"and")==0)
            {
                ;
            }
            else if(strcmp(s,"for")==0)
            {
                ;
            }
            else
            {
                n++;
            }
            scanf("%s",&s);
        }
        printf("case #%d:\n",i);
        printf("%d\n",n);
    }
    return 0;
}