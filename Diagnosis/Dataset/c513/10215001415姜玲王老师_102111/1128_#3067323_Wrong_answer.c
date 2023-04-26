#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{char a[301];char t[301];char f[301];}link;
int cmp(const void*p1,const void*p2)
{
    link q1=*(link*)p1;
    link q2=*(link*)p2;
    if(strcmp(q1.t,q2.t)) return strcmp(q1.t,q2.t);
    return strcmp(q1.f,q2.f);
}
int main()
{
    int n,i,k=0,j,y;
    scanf("%d",&n);
    link L[100];
    for(i=0;i<n;i++)
    {
        char b[301];
        gets(b);
        if(b[4]!='s')
        {
            strcpy(L[k].a,b);
            for(j=7,y=0;b[j]!='/';j++,y++)
            {
                L[k].t[y]=b[j];
            }
            L[k].t[y]=0;
            for(y=0;j<strlen(b);j++,y++)
            {
                L[k].f[y]=b[j];
            }
            L[k].f[y]=0;
            k++;
        }

    }
    qsort(L,k,sizeof(L[0]),cmp);
    for(i=0;i<k;i++)
    {
        printf("%s\n",L[i].a);
    }

}
