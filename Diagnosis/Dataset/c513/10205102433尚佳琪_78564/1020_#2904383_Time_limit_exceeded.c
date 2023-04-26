#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[100];
    int time0,time1,time2,time3,time4;
    int size;
}NODE;
int cmp1(const void *s1,const void *s2)
{
    NODE a=*(NODE*)s1;
    NODE b=*(NODE*)s2;
    return strcmp(a.name,b.name);
}
int cmp2(const void *s1,const void *s2)
{
    NODE a=*(NODE*)s1;
    NODE b=*(NODE*)s2;
    return a.size-b.size;
}
int cmp3(const void *s1,const void *s2)
{
    NODE a=*(NODE*)s1;
    NODE b=*(NODE*)s2;
    if(a.time0!=b.time0)
        return a.time0-b.time0;
    else
    {
        if(a.time1!=b.time1)
            return a.time1-b.time1;
        else{
            if(a.time2!=b.time2)
                return a.time2-b.time2;
            else{
                if(a.time3!=b.time3)
                    return a.time3-b.time3;
                else
                {
                    if(a.time4!=b.time4)
                        return a.time4-b.time4;
                    else
                        return -1;
                }
            }
        }
    }
}
int main()
{
    while(1)
    {
         int n;
         scanf("%d",&n);
         if(n==0)
            break;
         NODE ans[n];
         for(int i=0;i<n;i++)
         {
             char s[100],s2[100];
             scanf("%s %s %d %s",s,s2,&ans[i].size,ans[i].name);
            // printf("%s %s %d %s\n",s,s2,ans[i].size,ans[i].name);
            ans[i].time0=0;
            ans[i].time1=0;
            ans[i].time2=0;
            ans[i].time3=0;
            ans[i].time4=0;
             for(int j=0;j<4;j++)
                ans[i].time0=ans[i].time0*10+s[j]-'0';
             for(int j=5;j<7;j++)
                ans[i].time1=ans[i].time1*10+s[j]-'0';
             for(int j=8;j<10;j++)
                ans[i].time2=ans[i].time2*10+s[j]-'0';
             for(int j=0;j<2;j++)
                ans[i].time3=ans[i].time3*10+s2[j]-'0';
             for(int j=3;j<5;j++)
                ans[i].time4=ans[i].time4*10+s2[j]-'0';
         //   printf("%d-%d-%d %d-%d\n\n",ans[i].time0,ans[i].time1,ans[i].time2,ans[i].time3,ans[i].time4);
         }
        char zl[50];
        getchar();
        gets(zl);
        if(strcmp(zl,"LIST /NAME")==0)
            qsort(ans,n,sizeof(ans[0]),cmp1);
        else if(strcmp(zl,"LIST /SIZE")==0)
            qsort(ans,n,sizeof(ans[0]),cmp2);
        else
            qsort(ans,n,sizeof(ans[0]),cmp3);
         for(int i=0;i<n;i++)
         {
            printf("%d-%02d-%02d ",ans[i].time0,ans[i].time1,ans[i].time2);
            printf("%02d:%02d",ans[i].time3,ans[i].time4);
            printf("%17d ",ans[i].size);
            printf("%s",ans[i].name);
            printf("\n");
         }
         printf("\n");
    }

    //printf("Hello world!\n");
    return 0;
}
