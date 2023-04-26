#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{char a[500];int year;int month;int day;int hour;int minute;long long size;char name[500];} file;
int cmp1(const void*a,const void*b)
{
    file x=*(file*)a;
    file y=*(file*)b;
    return strcmp(x.name,y.name);
}
int cmp2(const void*a,const void*b)
{
    file x=*(file*)a;
    file y=*(file*)b;
    if(x.size==y.size) return cmp1(&x,&y);
    if(x.size>y.size) return 1;
    return -1;
}
int cmp3(const void*a,const void*b)
{
    file x=*(file*)a;
    file y=*(file*)b;
    if(x.year>y.year) return 1;
    if(x.year<y.year) return -1;
    if(x.month>y.month) return 1;
    if(x.month<y.month) return -1;
    if(x.day>y.day) return 1;
    if(x.day<y.day) return -1;
    if(x.hour>y.hour) return 1;
    if(x.hour<y.hour) return -1;
    if(x.minute>y.minute) return 1;
    if(x.minute<y.minute) return -1;
    return cmp1(a,b);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        getchar();
        file f[101];
    char order[20];
        for(int i=0;i<n;i++)
        {
            gets(f[i].a);
            int k=0;
            f[i].year=0;
            for(;f[i].a[k]!='-';k++)
            {
                f[i].year=f[i].year*10+f[i].a[k]-'0';
            }
            f[i].month=0;
            k++;
            for(;f[i].a[k]!='-';k++)
            {
                f[i].month=f[i].month*10+f[i].a[k]-'0';
            }
            f[i].day=0;
            k++;
            for(;f[i].a[k]!=' ';k++)
            {
                f[i].day=f[i].day*10+f[i].a[k]-'0';
            }
            f[i].hour=0;
            k++;
            for(;f[i].a[k]!=':';k++)
            {
                f[i].hour=f[i].hour*10+f[i].a[k]-'0';
            }
            f[i].minute=0;
            k++;
            for(;f[i].a[k]!=' ';k++)
            {
                f[i].minute=f[i].minute*10+f[i].a[k]-'0';
            }
            for(;f[i].a[k]==' ';k++);
            f[i].size=0;
            for(;f[i].a[k]!=' ';k++)
            {
                f[i].size=f[i].size*10+f[i].a[k]-'0';
            }
            k++;
            int j=0;
            for(;k<strlen(f[i].a);k++,j++){f[i].name[j]=f[i].a[k];}
            f[i].name[j]=0;
        }
      gets(order);
      if(!strcmp(order,"LIST /NAME")){qsort(f,n,sizeof(f[0]),cmp1);}
      if(!strcmp(order,"LIST /SIZE")){qsort(f,n,sizeof(f[0]),cmp2);}
      if(!strcmp(order,"LIST /TIME")){qsort(f,n,sizeof(f[0]),cmp3);}
      for(int m=0;m<n;m++){printf("%s\n",f[m].a);}
      printf("\n");
    }

}
