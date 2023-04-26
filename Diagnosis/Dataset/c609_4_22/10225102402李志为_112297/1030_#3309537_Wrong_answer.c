#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double Xu[26]={0};
int cmp(const void*a,const void*b)
{
    char *p1=(char*)a;
    char *p2=(char*)b;
    int d=0,t=0;
    if((*p1)<'a'){ d=1,(*p1)+=32;}
    if((*p2)<'a'){ t=1,(*p2)+=32;}
    if((*p1)==(*p2)) return d-t;
    return Xu[(*p2)-'a']-Xu[(*p1)-'a'];

}
int main()
{
    int m=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        for(int j=0;j<26;j++) scanf("%lf",&Xu[j]);
        char s[101];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
	return 0;
}