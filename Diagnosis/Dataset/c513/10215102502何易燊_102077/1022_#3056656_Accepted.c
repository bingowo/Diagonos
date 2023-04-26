#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {char *s,*t;} user;
char s[1000001];

int cmp(const void* a,const void* b)
{
    user *aa = (user*)a, *bb = (user*)b;
    if (strcmp(aa->t,bb->t)) return strcmp(aa->t,bb->t);
    else return -strcmp(aa->s,bb->s);
}

int main()
{
    int n;
    scanf("%d",&n);
    user* a = (user*)malloc(n*sizeof(user));
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        char *p = strchr(s,'@');
        a[i].t = (char*)malloc(strlen(p)+1);
        strcpy(a[i].t,p);
        *p = '\0';
        a[i].s = (char*)malloc(strlen(s)+1);
        strcpy(a[i].s,s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++)
    {
        printf("%s%s\n",a[i].s,a[i].t);
        free(a[i].s); free(a[i].t);
    }
    free(a);
    return 0;
}