#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {char s1[100001],s2[100001];} mail;

int cmp(const void* a,const void* b)
{
    mail* a_ = (mail*)a; mail* b_ = (mail*)b;
    if (strcmp(a_->s2,b_->s2)) return strcmp(a_->s2,b_->s2);
    else return strcmp(b_->s1,a_->s1);
}

main()
{
    int n; scanf("%d",&n);
    mail a[100001];
    for (int i=0;i<n;i++)
    {
        char s[100001] = {}; scanf("%s",s);
        int j = 0,k = 0;
        while (s[j]!='@') a[i].s1[k++] = s[j++];
        k = 0;
        while (s[j+1]) a[i].s2[k++] = s[++j];
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++) printf("%s@%s\n",a[i].s1,a[i].s2);
    return 0;
}