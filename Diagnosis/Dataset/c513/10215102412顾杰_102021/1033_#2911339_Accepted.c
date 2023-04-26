#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
typedef struct {int day,year;char month[10];}maya;
char st[]="pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu, uayet";
int cmp(const void*a,const void*b)
{
    maya ma=*(maya*)a,mb=*(maya*)b;
    int pa=ma.day+(strstr(st,ma.month)-st)/4*100+ma.year*10000,pb=mb.day+(strstr(st,mb.month)-st)/4*100+mb.year*10000;
    return pa>pb?1:-1;
}
int main() {
    int n,k,i,j;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&n);
        maya a[10000];
        char s[10];
        for(j=0;j<n;j++)
        {
            scanf("%d. %s %d",&a[j].day,&a[j].month,&a[j].year);
            //a[j].month=(strstr(st,s)-st)/4;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)printf("%d. %s %d\n",a[j].day,a[j].month,a[j].year);
    }
    return 0;
}
