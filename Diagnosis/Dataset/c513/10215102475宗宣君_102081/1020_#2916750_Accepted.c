#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
int year;
int month;
int day;
int hour;
int minute;
int size;
char s[100];
}N;
int cmp(const void*a,const void*b)
{
    return strcmp((*(N*)a).s,(*(N*)b).s);
}
int cmp1(const void*a,const void*b)
{
    N A,B;
    A = *(N*)a;B = *(N*)b;
    if(A.year>B.year) return 1;
    else if(A.year==B.year&&A.month>B.month) return 1;
    else if(A.year==B.year&&A.month==B.month&&A.day>B.day) return 1;
    else if(A.year==B.year&&A.month==B.month&&A.day==B.day&&A.hour>B.hour) return 1;
    else if(A.year==B.year&&A.month==B.month&&A.day==B.day&&A.hour==B.hour&&A.minute>B.minute) return 1;
    else if(A.year==B.year&&A.month==B.month&&A.day==B.day&&A.hour==B.hour&&A.minute==B.minute) return strcmp(A.s,B.s);
    else return -1;
}
int cmp2(const void*a,const void*b)
{
    N A,B;
    A = *(N*)a;B = *(N*)b;
    if(A.size>B.size) return 1;
    else if(A.size==B.size) return strcmp(A.s,B.s);
    else return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        N A[n];int i,j;
        char b[10];
        for(i = 0;i<n;i++)
       scanf("%d-%02d-%02d %02d:%02d %16d %s\n",&A[i].year,&A[i].month,&A[i].day,&A[i].hour,&A[i].minute,&A[i].size,A[i].s);
    scanf("LIST /%s",b);
    if(b[0]=='N') qsort(A,n,sizeof(N),cmp);
    else if(b[0]=='T') qsort(A,n,sizeof(N),cmp1);
    else qsort(A,n,sizeof(N),cmp2);
    for(j = 0;j<n;j++)
    printf("%d-%02d-%02d %02d:%02d %16d %s\n",A[j].year,A[j].month,A[j].day,A[j].hour,A[j].minute,A[j].size,A[j].s);
    printf("\n");
    scanf("%d",&n);
    }
    return 0;
}
