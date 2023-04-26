#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int qu(char s1[],char s2[])
{
    int ret=0,index=0;
    char*p=s1;
    while(*p!='\0')
    {
        if(*p==','||*p=='!'||*p=='?'||*p=='.')
        {
            *p='\0';
            ret=1;
            break;
        }
        p++;
    }
    p++;
    if(*p) ret=2;
    while(*p!='\0')
    {
        s2[index++]=*p;
        p++;
    }
    s2[index]='\0';
    return ret;
}
struct dic
{
    char s[501];

};
int cmp(const void*a,const void*b)
{
    struct dic*x=(struct dic*)a;
    struct dic*y=(struct dic*)b;
    return strcmp(x->s,y->s)<=0?-1:1;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
         struct dic ans[501];
         int index=0;
         while(1)
         {

        char s1[501],s2[501]={0};

        scanf("%s",s1);
        int r=qu(s1,s2);
        if(r==2)
        {
            strcpy(ans[index++].s,s1);
            strcpy(ans[index++].s,s2);
        }
        else strcpy(ans[index++].s,s1);
        char c=getchar();
        if(c=='\n') break;

         }
         qsort(ans,index,sizeof(struct dic),cmp);
         printf("case #%d:\n",i);
         for(int j=0;j<index-1;j++)
         {
             if(strcmp(ans[j].s,ans[j+1].s)!=0)
             {
                 printf("%s ",ans[j].s);
             }
         }
         printf("%s\n",ans[index-1].s);

    }
    return 0;
}
