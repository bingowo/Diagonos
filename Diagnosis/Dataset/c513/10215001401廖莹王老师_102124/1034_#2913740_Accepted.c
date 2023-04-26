#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double p[27];
int cmp(const void*a,const void*b)
{
    char s1,s2;
    double k1,k2;
    int p1,p2;
    s1=*((char *)a);
    s2=*((char*)b);
    if(s1>='a' && s1<='z'){p1=s1-'a';k1=p[p1];}
    else {p1=s1-'A';k1=p[p1];}
    if(s2>='a' && s2<='z'){p2=s2-'a';k2=p[p2];}
    else {p2=s2-'A';k2=p[p2];}
    if(k1>k2)return -1;
    else if(k1<k2)return 1;
    else
    {
        if(p1==p2)return s2-s1;
        else return p1-p2;
    }

}
void paixu(int h)
{

    int i;
    for(i=0;i<26;i++){scanf("%lf",&p[i]);}
    char s[110];
    scanf("%s",s);
    qsort(s,strlen(s),sizeof(s[0]),cmp);
    printf("case #%d:\n",h);
    printf("%s\n",s);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        paixu(h);
}
