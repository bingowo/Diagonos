#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    char s[31];
    int num;
} str;
int cmp(const void *a,const void *b)
{
    str* a0=(str*)a;
    str* b0=(str*)b;
    if(a0->num!=b0->num)
        return a0->num-b0->num;
    return strcmp(a0->s,b0->s);
}
int main()
{
    str a[100];
    int i,n,t,l;
    n=0;
    while(scanf("%s",a[n].s)!=EOF){
        l=strlen(a[n].s);
        i=0;
        t=0;
        a[n].num=0;
        while(i<l){
            if(isdigit(a[n].s[i])){
                t=1;
                a[n].num=a[n].num*10+a[n].s[i]-'0';
            }
            i++;
        }
        if(t==0)
            a[n].num=-1;
        n++;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++){
        printf("%s",a[i].s);
        if(i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
