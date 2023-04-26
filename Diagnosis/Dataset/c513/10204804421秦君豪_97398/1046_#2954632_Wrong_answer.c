#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char *s)
{
    if(strcmp(s,"the")==0||strcmp(s,"an")==0||strcmp(s,"a")==0||strcmp(s,"of")==0||strcmp(s,"for")==0
       ||strcmp(s,"and")==0)
        return 0;
    else return  1;

}
void tosmall(char*s)
{
    if (s[0]>='A'&&s[0]<='Z')
    {
        s[0]+=32;
    }
}
int main(void)
{
    int T;
    int a,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int cnt=0;
        char s[101];
        char c;
        do
        {
            scanf("%s%c",&s,&c);
            tosmall(s);
            if (cmp(s))
                cnt++;
        }while(c!='\n');
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}
