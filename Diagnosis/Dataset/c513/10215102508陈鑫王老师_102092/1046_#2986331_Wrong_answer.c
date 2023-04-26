#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
             if(strcmp(ans[j].s,"the")!=0&&strcmp(ans[j].s,"a")!=0&&strcmp(ans[j].s,"an")!=0&&strcmp(ans[j].s,"of")!=0&&strcmp(ans[j].s,"for")!=0&&strcmp(ans[j].s,"and")!=0&&strcmp(ans[j].s,"OF")!=0&&strcmp(ans[j].s,"A")!=0&&strcmp(ans[j].s,"Of")!=0&&strcmp(ans[j].s,"An")!=0&&strcmp(ans[j].s,"AN")!=0&&strcmp(ans[j].s,"THE")!=0&&strcmp(ans[j].s,"The")!=0&&strcmp(ans[j].s,"THe")!=0&&strcmp(ans[j].s,"For")!=0&&strcmp(ans[j].s,"FOR")!=0&&strcmp(ans[j].s,"And")!=0&&strcmp(ans[j].s,"AND")!=0)
               count++;
         }
         printf("case #%d:\n",i);
         printf("%d\n",count);



    }
    return 0;
}
