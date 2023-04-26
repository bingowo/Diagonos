#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[101];
}ch;
void tolow(char s[])
{
    int len=strlen(s);
    for(int i=0;i>len;i++)
    {
        if(s[i]<97) s[i]=s[i]+32;
    }
}

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
             tolow(ans[index].s);
             index++;
             if((c=getchar())=='\n')
                break;
         }
         for(int j=0;j<index;j++)
         {
             if(strcmp(ans[j].s,"the")!=0&&strcmp(ans[j].s,"a")!=0&&strcmp(ans[j].s,"an")!=0&&strcmp(ans[j].s,"of")!=0&&strcmp(ans[j].s,"for")!=0&&strcmp(ans[j].s,"and")!=0)
               count++;
         }
         printf("case #%d:\n",i);
         printf("%d\n",count);



    }
    return 0;
}
