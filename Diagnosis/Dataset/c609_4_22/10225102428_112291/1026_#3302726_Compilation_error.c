#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
 {
 char s[2001];
 char c[2001];
 int differ;
 } Array;

int cmp(const void*a, const void*b)
 {
     int r;
     Array *aa=(Array*)a;
     Array *bb=(Array*)b;
     return (r=bb->differ-aa->differ)?r:strcmp(aa->s,bb->s);
 }

int cmp1(const void*a,const void*b)
 {
     return *(char*)a-*(char*)b;
 }

int main()
 {
     int T,t,n,i,j;
     Array a[2001];
     scanf("%d",&T);
     for(t=0; t<T; t++)
    {

        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s",a[i].s);
            a[i].differ=0;
            strcpy(a[i].c,a[i].s);
        }
        for(i=0; i<n; i++)
        {
            qsort(a[i].s,strlen(a[i].s),sizeof(char),cmp1);//按字母顺序排好，方便后续统计
            while(a[i].s[k]!='\0')printf("%s",a[i].s[k]),k++;
            for(j=0; j<strlen(a[i].s); j++)
            {
                if(a[i].s[j]!=a[i].s[j+1])
                    a[i].differ+=1;
            }
        }
        qsort(a,n,sizeof(Array),cmp);
        printf("case #%d:\n",t);
        for(i=0; i<n; i++)
            printf("%s\n",a[i].c);
}
    return 0;
}
