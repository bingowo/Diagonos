#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s1[20],s2[10],s3[20],name[100];
    int year,m,d;
    int size;
    long long t,time;
}node;
int cmp1(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return strcmp(s1.name,s2.name);
}
int cmp2(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.size!=s2.size)
        return s1.size-s2.size;
    else
        return strcmp(s1.name,s2.name);
}
int cmp3(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.time!=s2.time)
        return s1.time-s2.time;
    else
    {
        if(s1.t!=s2.t)
            return s1.t-s2.t;
        else
            return strcmp(s1.name,s2.name);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        node f[n];
        for(int i=0;i<n;i++)
            f[i].size=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %s %s",f[i].s1,f[i].s2,f[i].s3,f[i].name);
            f[i].year=(f[i].s1[0]-'0')*1000+(f[i].s1[1]-'0')*100+((f[i].s1[2]-'0')*10)+(f[i].s1[3]-'0');
            f[i].m=(f[i].s1[5]-'0')*10+(f[i].s1[6]-'0');
            f[i].d=(f[i].s1[8]-'0')*10+(f[i].s1[9]-'0');
            f[i].t=(f[i].s2[0]-'0')*1000+(f[i].s2[1]-'0')*100+(f[i].s2[3]-'0')*10+(f[i].s2[4]-'0');
            f[i].time=f[i].year*10000+f[i].m*100+ f[i].d;
            int len=strlen(f[i].s3);
            for(int j=0;j<len;j++)
            {
                f[i].size=f[i].size*10+f[i].s3[j]-'0';
            }

           // printf("%10lld %5lld \n\n",f[i].time,f[i].t);
            //printf("%16d %s\n\n",f[i].size,f[i].name);
            //printf("%lld %lld %d %s\n\n",f[i].time,f[i].t,f[i].size,f[i].name);
        }
        char string1[10],string2[10];
        scanf("%s %s",string1,string2);
        if(strcmp(string2,"/NAME")==0)
            qsort(f,n,sizeof(f[0]),cmp1);
        else if(strcmp(string2,"/SIZE")==0)
            qsort(f,n,sizeof(f[0]),cmp2);
        else if(strcmp(string2,"/TIME")==0)
            qsort(f,n,sizeof(f[0]),cmp3);
       for(int i=0;i<n;i++)
       {
            printf("%s %s ",f[i].s1,f[i].s2);
            printf("%16d %s\n",f[i].size,f[i].name);
       }
       printf("\n");
    }

    return 0;
}
