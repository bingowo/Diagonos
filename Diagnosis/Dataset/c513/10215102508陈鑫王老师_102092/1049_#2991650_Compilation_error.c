#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dic
{
    char s[501];
};
void qu(char s[])
{
    char *p=s;
    while(*p!='\0')
    {
        if(*p==','||*p=='.'||*p=='!'||*p=='?')
            *p=' ';
        p++;
    }
}
int cmp(const void*a,const void*b)
{
    struct dic *x=(struct dic*)a;
    struct dic *y=(struct dic*)b;
    return strcmp(x->s,y->s)<=0?-1:1;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[501];
        gets(s);
        qu(s);
        struct dic ans[501];
        int index=0,temp=0,ret=0;
        char*p=s;
        while(*p!='\0')
        {
            if(*p==' ')
            {
                ret++;
               memmove(ans[index].s,p-temp,sizeof(char)*temp);
               ans[index].s[temp]='\0';
               index++;
               temp=0;
               while(*p==' ')
               {p++;}
            }
            else temp++，p++;

        }
        if(ret==0) {index=1,strcpy(ans[0].s,s);}
        qsort(ans,index,sizeof(struct dic),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<index-1;j++)
        {
            if(strcmp(ans[j].s,ans[j+1].s)!=0)
                printf("%s ",ans[j].s);
        }
        printf("%s\n",ans[index-1].s);


    }
    return 0;
}
