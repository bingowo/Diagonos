#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct wj{
    char time1[15],time2[10];
    int size;
    char name[80];
};

int cmp1(const void*a,const void*b)
{
    struct wj p1=*((struct wj*)a);
    struct wj p2=*((struct wj*)b);
    return strcmp(p1.name,p2.name);

}
int cmp2(const void*a,const void*b)
{
    struct wj p1=*((struct wj*)a);
    struct wj p2=*((struct wj*)b);
    int l=strlen(p1.time1);
    int ans1=0;
    for(int i=0;i<l;i++)
    {
        if(p1.time1[i]>='0'&&p1.time1[i]<='9')ans1=10*ans1+p1.time1[i]-'0';
    }
    l=strlen(p1.time2);
    for(int i=0;i<l;i++)
    {
        if(p1.time2[i]>='0'&&p1.time2[i]<='9')ans1=10*ans1+p1.time2[i]-'0';
    }
    l=strlen(p2.time1);
    int ans2=0;
    for(int i=0;i<l;i++)
    {
        if(p2.time1[i]>='0'&&p2.time1[i]<='9')ans2=10*ans2+p2.time1[i]-'0';
    }
    l=strlen(p2.time2);
    for(int i=0;i<l;i++)
    {
        if(p2.time2[i]>='0'&&p2.time2[i]<='9')ans2=10*ans2+p2.time2[i]-'0';
    }
    if(ans1!=ans2)return ans1-ans2;
    else return strcmp(p1.name,p2.name);

}
int cmp3(const void*a,const void*b){
struct wj p1=*((struct wj*)a);
    struct wj p2=*((struct wj*)b);
if(p1.size!=p2.size)return p1.size-p2.size;
else return strcmp(p1.name,p2.name);
}

int main()
{
    int T;scanf("%d",&T);
    char s[12];
    while(1)
    {
        struct wj p[110]={0};

        for(int i=0;i<T;i++)
        {
            scanf("%s%s%d%s",p[i].time1,p[i].time2,&p[i].size,p[i].name);
           //printf("%s %s %16d %s\n",p[i].time1,p[i].time2,p[i].size,p[i].name);
        }
scanf("%s",s);scanf("%s",s);
//printf("%c",s[1]);
if(s[1]=='N')qsort(p,T,sizeof(p[0]),cmp1);
else if(s[1]=='T')qsort(p,T,sizeof(p[0]),cmp2);
else if(s[1]=='S')qsort(p,T,sizeof(p[0]),cmp3);

for(int i=0;i<T;i++)
        {

           printf("%s %s %16d %s\n",p[i].time1,p[i].time2,p[i].size,p[i].name);
        }
        scanf("%d",&T);
        if(T!=0)printf("\n");
        else break;



    }


}