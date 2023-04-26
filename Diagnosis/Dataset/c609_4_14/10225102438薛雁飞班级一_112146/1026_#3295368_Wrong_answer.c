#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[21];
    int num;
}sn;
int dnum(char *a)
{
    int n[27]={0};
    int k=0;
    int len=strlen(a);
    for(int i=0;i<len;i++){
        if(a[i]>='A'&&a[i]<='Z'){
            n[a[i]-'A']++;
        }
    }
    for(int i=0;i<26;i++){
        if(n[i]>0)k++;
    }
    return k;
}
int cmp(const void *a,const void *b)
{
    sn s1,s2;
    s1=*((sn*)a);s2=*((sn*)b);
    if(s1.num==s2.num)return(strcmp(s1.s,s2.s));
    else return(s2.num-s1.num);
}
int main()
{
    int q;
    scanf("%d",&q);
    for(int j=0;j<q;j++){
        sn a[101];
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",a[i].s);
            a[i].num=dnum(a[i].s);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d\n",j);
        for(int i=0;i<n;i++)
            printf("%s\n",a[i].s);
    }
    return 0;
}
