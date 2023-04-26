#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {char* s1; char* s2;} mail;

int cmp(const void* a,const void* b)
{
    mail* a_ = (mail*)a; mail* b_ = (mail*)b;
    if (strcmp(a_->s2,b_->s2)) return strcmp(a_->s2,b_->s2);
    else return strcmp(b_->s1,a_->s1);
}

main()
{
    int n; scanf("%d",&n);
    mail* a = (mail*)malloc(n*sizeof(mail));
    for (int i=0;i<n;i++)
    {
        char* s;
        s = (char*)malloc(100001);
        scanf("%s",s);
        //a[i].s1_ = a[i].s1;
        //a[i].s2_ = a[i].s2;
        char* p = strtok(s,"@");
        char* q = strtok(NULL,"@");
        a[i].s1 = (char*)malloc(strlen(p)+1);
        a[i].s2 = (char*)malloc(strlen(q)+1);
        a[i].s1 = p; a[i].s2 = q;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++) printf("%s@%s\n",a[i].s1,a[i].s2);
    free(a);
    system("pause");
    return 0;
}