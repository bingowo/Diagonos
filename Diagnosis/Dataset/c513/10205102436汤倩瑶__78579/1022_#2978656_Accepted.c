#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{int k;char *yj;}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);

    if(strcmp(p1.yj+p1.k,p2.yj+p2.k)!=0)return strcmp(p1.yj+p1.k,p2.yj+p2.k);
    else return strcmp(p2.yj,p1.yj);

}
int main()
{
    int T;
    scanf("%d",&T);
    node*p=(node*)malloc(sizeof(node)*T);


    for(int i=0;i<T;i++)
    {

         char s[1000005];
        scanf("%s",s);
        int len=strlen(s);
        char *tmp=(char *)malloc(sizeof(char)*(len+1));
        strcpy(tmp,s);
        p[i].yj=tmp;
        int j;
        for(j=0;j<len;j++)
        {
            if(tmp[j]=='@')break;
        }
p[i].k=j+1;
    }
qsort(p,T,sizeof(p[0]),cmp);
for(int i=0;i<T;i++)
printf("%s\n",p[i].yj);

free(p);
return 0;

}
