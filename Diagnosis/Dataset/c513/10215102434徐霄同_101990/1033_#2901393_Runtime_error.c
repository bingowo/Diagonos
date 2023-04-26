#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mon[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
typedef struct {
    int y;
    int m;
    int d;
    char s[7];
} maya;
int cmp(const void *a,const void *b)
{
    maya* a0=(maya*)a;
    maya* b0=(maya*)b;
    if(a0->y!=b0->y)
        return a0->y-b0->y;
    else if(a0->m!=b0->m)
        return a0->m-b0->m;
    else
        return a0->d-b0->d;
}
int main()
{
    maya a[1000];
    int t,n,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d. %s %d",&a[j].d,a[j].s,&a[j].y);
            for(k=0;k<19;k++)
                if(strcmp(mon[k],a[j].s)==0)
                    a[j].m=k;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("%d. %s %d\n",a[j].d,a[j].s,a[j].y);
    }
    return 0;
}
