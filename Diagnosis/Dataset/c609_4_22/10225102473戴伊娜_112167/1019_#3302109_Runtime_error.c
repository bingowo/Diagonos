#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    char *s1;
    char *s2;
    s1=(char*)a;
    s2=(char*)b;
    char *p1;
    char *p2;
    for(p1=s1;*p1;p1++);
    for(p2=s2;*p2;p2++);
    int t1=p1-s1;
    int t2=p2-s2;
    if(t1!=t2)
        return t2-t1;
    int sign1,sign2;
    sign1=sign2=1;
    if(*s1=='-')
        {sign1=-1;s1++;}
    if(*s2=='-')
        {sign2=-1;s2++;}
    return (sign1/sign2)*strcmp(s1,s2);

}

int main()
{
    char s[1000000][1000000];
    int i,q;
    for(i=0;getchar()!=EOF;i++)
    {
        scanf("%s",s[i]);
    }
    qsort(s,i,sizeof(char),cmp);
    for(q=0;q<i;q++)
        {
            printf("%s",s[q]);
        }
    return 0;
}
