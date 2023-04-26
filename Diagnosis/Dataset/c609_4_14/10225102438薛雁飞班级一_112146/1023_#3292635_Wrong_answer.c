#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int d;
    char m[7];
    int y;
}date;
int trans(char* a)
{
    char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<19;i++){
        if(strcmp(a,month[i])!=0)return i;
    }
}
int cmp(const void* a,const void* b)
{
    date s1,s2;
    s1=*(date*)a;s2=*(date*)b;
    int x,y;
    x=s1.d+trans(s1.m)*20+s1.y*1000;
    y=s2.d+trans(s2.m)*20+s2.y*1000;
    return(x-y);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        int n;
        scanf("%d",&n);
        date a[1001];
        for(int i=0;i<n;i++){
            scanf("%d. %s %d",&a[i].d,a[i].m,&a[i].y);
        }
        qsort(a,n,sizeof(date),cmp);
        printf("case #%d:\n",k);
        for(int i=0;i<n;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}
