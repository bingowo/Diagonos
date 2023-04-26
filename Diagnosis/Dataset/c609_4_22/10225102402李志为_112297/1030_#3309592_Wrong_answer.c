#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double Xu[26];
int cmp(const void*a,const void*b)
{
    char p1=*(const char*)a;
    char p2=*(const char*)b;
    int d=0,t=0;
    if(p1<'a'){ d=1,p1+=32;}
    if(p2<'a'){ t=1,p2+=32;}
    if(p1==p2) return d-t;
    if(Xu[(p2)-'a']>Xu[(p1)-'a']) return 1;
    else return 0;

}
int main()
{
    int m=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        for(int j=0;j<26;j++) scanf("%lf",&Xu[j]);
        char s[102];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",i,s);
    }
	return 0;
}