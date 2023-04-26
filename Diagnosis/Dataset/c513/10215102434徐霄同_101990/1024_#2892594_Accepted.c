#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char s[12];
    int s0;
} stu;
int cmp(const void *a,const void *b)
{
    stu* a0=(stu*)a;
    stu* b0=(stu*)b;
    if(a0->s0!=b0->s0)
        return b0->s0-a0->s0;
    return strcmp(a0->s,b0->s);
}
int main()
{
    stu a[500];
    int f[10];
    int t,m,n,g,s,x,num,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d%d",&n,&m,&g);
        num=0;
        for(j=0;j<m;j++)
            scanf("%d",&f[j]);
        for(j=0;j<n;j++){
            scanf("%s%d",a[j].s,&s);
            a[j].s0=0;
            for(k=0;k<s;k++){
                scanf("%d",&x);
                a[j].s0+=f[x-1];
            }
            if(a[j].s0>=g)
                num++;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",num);
        for(j=0;j<num;j++)
            printf("%s %d\n",a[j].s,a[j].s0);
    }
    return 0;
}
