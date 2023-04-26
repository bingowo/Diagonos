#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void tolow(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]<97)s[i]=s[i]+32;
    }
}
typedef struct
{
    char s[101];
}ch;
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++)
    {
        ch ans[101];
        int index=0,count=0;
         while(1)
         {
             scanf("%s",ans[index].s);
             index++;
             if((c=getchar())=='\n')
                break;
         }
         for(int j=0;j<index;j++)
         {
             tolow(ans[j].s);
             if(strcmp(ans[j].s,"the")!=0&&strcmp(ans[j].s,"a")!=0&&strcmp(ans[j].s,"an")!=0&&strcmp(ans[j].s,"of")!=0&&strcmp(ans[j].s,"for")!=0&&strcmp(ans[j].s,"and")!=0)
               count++;
         }
         printf("case #%d:\n",i);
         printf("%d\n",count);



    }
    return 0;
}
