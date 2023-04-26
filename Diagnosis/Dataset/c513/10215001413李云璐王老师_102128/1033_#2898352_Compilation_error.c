#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{int ri;int yue;char s[10];int nian;}TIAN;

int cmp(const void*a1,const void *a2)
{
    TIAN*a=*(TIAN*)a1;
    TIAN*b=*(TIAN*)a2;
    char chu[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
    "yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<19;i++)
    {if(strcmp(a.s,chu[i])==0) a.yue=i;
    if(strcmp(b.s,chu[i])==0) b.yue=i;}
    if(a.nian!=b.nian) return a.nian-b.nian;
    else if(a.yue!=b.yue) return a.yue-b.yue;
    else return a.ri-b.ri;
    
    
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        TIAN*a=NULL;
        a=(TIAN*)malloc(m*sizeof(TIAN));
        for(int k=0;k<m;k++)
        scanf("%d. %s %d",&a[k].ri,a[k].s,&a[k].nian);
        qsort(a,m,sizeof(TIAN),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++)
        printf("%d. %s %d\n",a[k].ri,a[k].s,a[k].nian);
    }
    return 0;
}
