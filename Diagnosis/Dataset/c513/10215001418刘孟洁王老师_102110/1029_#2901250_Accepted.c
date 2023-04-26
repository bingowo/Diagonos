#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 201

int cmp(const void*a,const void*b)
{
    char c=*(char*)a;
    char d=*(char*)b;
    return c-d;
}

int main()
{
    int n,i,j,k,x,l;
    char t[N],s[N];
    scanf("%d",&n);
    gets(t);
    for(i=0;i<n;i++)
    {
        gets(t);
        j=0;
        k=0;
        while(t[j]!='\0')
        {
            if(t[j]>='A'&&t[j]<='Z')s[k]=t[j],k++,j++;
            else j++;
        }
        qsort(s,k,sizeof(s[0]),cmp);
        x=0;j=0;
        while(t[j]!='\0')
        {
            if(t[j]>='A'&&t[j]<='Z')t[j]=s[x],x++,j++;
            else j++;
        }
        printf("case #%d:\n",i);
        printf("%s\n",t);
        for(l=0;l<k;l++)s[j]='\0';
    }
    return 0;
}
