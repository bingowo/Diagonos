#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {char* s1; char* s2; char* s1_; char* s2_;} mail;

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
    	char *s;
        //char s[100006];
        s = (char*)malloc(1e6*sizeof(char));
        scanf("%s",s);
        //printf("%d\n",strlen(s));
        a[i].s1 = (char*)malloc(strlen(s)*sizeof(char));
        a[i].s2 = (char*)malloc(strlen(s)*sizeof(char));
        a[i].s1_ = a[i].s1;
        a[i].s2_ = a[i].s2;
        a[i].s1 = strtok(s,"@");
        a[i].s2 = strtok(NULL,"@");
        //printf("s=%s\ns=%s\n",a[i].s1,a[i].s2);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++) printf("%s@%s\n",a[i].s1,a[i].s2);
    return 0;
}
