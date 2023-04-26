#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int num;
    char s[64];
}File;
int mycmp1(const void *p1,const void *p2)
{
    File* a=p1;
    File* b=p2;
    return strcmp((*a).s,(*b).s);
}
int mycmp2(const void *p1,const void *p2)
{
     File* a=p1;
     File* b=p2;
     return (*a).num-(*b).num;
}
int mycmp3(const void *p1,const void *p2)
{
     File* a=p1;
     File* b=p2;
     if((*a).year>(*b).year) return 1;
     else if((*a).year<(*b).year) return -1;
     else
     {
         if((*a).month>(*b).month) return 1;
          else if((*a).month<(*b).month) return -1;
          else
          {
              if((*a).day>(*b).day) return 1;
              else if((*a).day<(*b).day) return -1;
              else
              {
                  if((*a).hour>(*b).hour) return 1;
                  else if((*a).hour<(*b).hour) return -1;
                  else
                  {
                      if((*a).minute>(*b).minute) return 1;
                      else if((*a).minute<(*b).minute) return -1;
                  }
              }
          }
     }
}
int main()
{
   int n;
   scanf("%d",&n);
    while(1)
    {
        File a[100];
        if(n==0) break;
        for(int j=0;j<n;j++)
        {
            char s1[100];
            scanf("%s",s1);
            a[j].year=(s1[0]-'0')*1000+(s1[1]-'0')*100+(s1[2]-'0')*10+s1[3]-'0';
            a[j].month=(s1[5]-'0')*10+(s1[6]-'0');
            a[j].day=(s1[8]-'0')*10+s1[9]-'0';
            a[j].hour=(s1[11]-'0')*10+s1[12]-'0';
            a[j].minute=(s1[14]-'0')*10+s1[15]-'0';
            int k=16;
            while(s1[k]==' ') k++;
            int l=k;
            while(s1[l]!=' ') l++;
            for(;k<l;k++)
            {
                a[j].num=(a[j].num)*10+s1[k]-'0';
            }
            char s4[64]={'0'};
            int n=0;
            l++;
            for(;l<strlen(s1);l++)
            {
                s4[n++]=s1[l];
            }
            strcpy(a[j].s,s4);
        }
        char s3[20];
        scanf("%s",s3);
        if(strcmp(s3,"LIST /NAME")==0)
        qsort(a,n,sizeof(File),mycmp1);
         if(strcmp(s3,"LIST /SIZE")==0)
        qsort(a,n,sizeof(File),mycmp2);
         if(strcmp(s3,"LIST /TIME")==0)
        qsort(a,n,sizeof(File),mycmp3);
        for(int q=0;q<n;q++)
        {
            printf("%d %d %d %d %d %d",a[q].year,a[q].month,a[q].day,a[q].hour,a[q].minute,a[q].num);
            printf("%s",a[q].s);
        }
    }
}
