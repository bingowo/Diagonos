#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    float pl;
    char c;
}zm;
int x[26];
int cmp1(const void *a, const void *b)
{
    zm *a0=(zm*)a;
    zm *b0=(zm*)b;
    if(a0->pl>b0->pl)
        return -1;
    else
        return 1;
}
int cmp2(const void *a, const void *b)
{
    char a0=*(char*)a;
    char b0=*(char*)b;
    if(a0==b0 || a0-b0=='a'-'A')
        return -1;
    else if(a0-b0=='A'-'a')
        return 1;
    else{
        if(a0>='A' && a0<='Z')
            a0=a0-('A'-'a');
        if(b0>='A' && b0<='Z')
            b0=b0-('A'-'a');
        return x[a0-'a']-x[b0-'a'];
    }
}
int main()
{
    zm a[26];
    char s[101];
    int t,i,j,l;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        for(j=0;j<26;j++){
            scanf("%f",&a[j].pl);
            a[j].c='a'+j;
        }
        scanf("%s",s);
        l=strlen(s);
        qsort(a,26,sizeof(a[0]),cmp1);
        for(j=0;j<26;j++)
            x[a[j].c-'a']=j;
        qsort(s,l,sizeof(s[0]),cmp2);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
