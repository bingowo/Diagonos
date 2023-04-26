#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strnumcmp(const void *a,const void *b)
{
    char *p=(char *)a,*q=(char *)b;
    int i,j,pnum,qnum;
    for(i=0;*(p+i);i++)
        if(*(p+i)>='0'&&*(p+i)<='9')
        {
            int it=i;
            pnum=0;
            while(*(p+it)>='0'&&*(p+it)<='9')
            {
                pnum=pnum*10+*(p+it)-'0';
                it++;
            }
            break;
        }
    for(j=0;*(q+j);j++)
        if(*(q+j)>='0'&&*(q+j)<='9')
        {
            int jt=j;
            qnum=0;
            while(*(q+jt)>='0'&&*(q+jt)<='9')
            {
                qnum=qnum*10+*(q+jt)-'0';
                jt++;
            }
            break;
        }

    if(*(p+i)&&*(q+j))return pnum-qnum;
    else if(*(p+i)&&!*(q+j))return 1;
    else if(!*(p+i)&&*(q+j))return -1;
    else return strcmp(p,q);
}
int main()
{
    char s[100][31];
    int i=0;
    while(scanf("%s",s[i++])!=EOF);
    qsort(s,i,sizeof(s[0]),strnumcmp);
    for(int j=0;j<i;j++)printf("%s ",s[j]);
    return 0;
}
