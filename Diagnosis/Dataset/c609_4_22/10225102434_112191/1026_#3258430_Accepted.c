#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp0(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}
int Num(char*p)
{
    char*p2 =(char*)malloc(21*sizeof(char));
    strcpy(p2,p);
    qsort(p2,strlen(p2),sizeof(p2[0]),cmp0);
    int num = 0;
    while(*(p2+1)!='\0')
    {
        if(*p2!=*(p2+1))num++;
        p2++;
    }
    return num;
}
int cmp(const void*a,const void*b)
{
    char*p1 = (char*)a,*p2 = (char*)b;
    int x1 = Num(p1),x2 = Num(p2);
    if(x1!=x2)return x2-x1;
    else return strcmp(p1,p2);
}
int main()
{
    int n,m,i,j;char s[100][21];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&m);
        for(j = 0;j<m;j++)
        {
            scanf("%s",s[j]);
            //qsort(s[j],strlen(s[j]),sizeof(s[0][0]),cmp0);
        }
        qsort(s,m,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j<m;j++)printf("%s\n",s[j]);
    }
    return 0;
}


