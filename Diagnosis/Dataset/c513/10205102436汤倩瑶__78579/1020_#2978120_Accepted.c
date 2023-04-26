#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
int time,size;
char t1[15],t2[10];
char name[65];
}node;
int cmp1(const void*a,const void*b)
{
node p1=*((node*)a);
node p2=*((node*)b);
return strcmp(p1.name,p2.name);
}
int cmp2(const void*a,const void*b)
{
node p1=*((node*)a);
node p2=*((node*)b);
if(p1.size!=p2.size)return p1.size-p2.size;
else return strcmp(p1.name,p2.name);
}
int cmp3(const void*a,const void*b)
{
node p1=*((node*)a);
node p2=*((node*)b);
if(p1.time!=p2.time)return p1.time-p2.time;
else return strcmp(p1.name,p2.name);
}



int main()
{
    int T;

    while(scanf("%d",&T)!=EOF){
        if(T==0)break;
        node*p=(node*)malloc(sizeof(node)*T);


        for(int i=0;i<T;i++)
        {
            scanf("%s%s%d%s",p[i].t1,p[i].t2,&p[i].size,p[i].name);

int sum=0;
for(int j=0;j<10;j++)
    {
        if(p[i].t1[j]>='0'&&p[i].t1[j]<='9')sum=sum*10+p[i].t1[j]-'0';

    }
    for(int j=0;j<5;j++)
    {
        if(p[i].t2[j]>='0'&&p[i].t2[j]<='9')sum=sum*10+p[i].t2[j]-'0';
    }
    p[i].time=sum;
        }
        char ml[15];
        scanf("%s",ml);
        scanf("%s",ml);
        if(ml[1]=='N')qsort(p,T,sizeof(p[0]),cmp1);
        if(ml[1]=='S')qsort(p,T,sizeof(p[0]),cmp2);
        if(ml[1]=='T')qsort(p,T,sizeof(p[0]),cmp3);
         for(int i=0;i<T;i++)
        {
            printf("%s %s %16d %s\n",p[i].t1,p[i].t2,p[i].size,p[i].name);
        }
        printf("\n");
 free(p);

    }




}
