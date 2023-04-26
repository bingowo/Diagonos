#include<stdio.h>
#include<string.h>
int month2idx(char *m)
{
    int i;
    static char *month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
                          "zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"}
    for(i=0;;i++) if(!strcmp(m,month[i])) return i;
}
typedef struct
{
    int val;
    int y;
    int d;
    char m[7];
}data;
data a[10001];
char s[300];
int cmp(const void *a,const void *b)
{
    return ((data *)a)->val-((data *)b)->val;
}
int main()
{
    int T,n;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d\n",&n);
        for(int j=0;j<n;j++)
        {
            read(i);
        }
        qsort(a,n,sizeof(data),cmp);
        printf("case #%d:\n",i);
        for(int p=0;p<n;p++)
        {
            printf("%d. %s %d\n",a[p].d,a[p].m,a[p].y);
        }
    }
    return 0;
}