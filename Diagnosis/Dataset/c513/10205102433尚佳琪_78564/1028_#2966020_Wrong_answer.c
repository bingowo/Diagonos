#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void*a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    char c;
    scanf("%c",&c);
    getchar();
    char a[1000];
    int num[105]={0};
    int len,flag=0,k=0;
    gets(a);
    len=strlen(a);
   // printf("%s %d",a,len);
    for(int i=0;i<len;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            num[k]=num[k]*10+a[i]-'0';
        }
        else if(a[i]==' ')
        {
            k++;
        }
    }
    if(c=='A')
        qsort(num,k+1,sizeof(num[0]),cmp);
    else if(c=='D')
        qsort(num,k+1,sizeof(num[0]),cmp2);
    for(int i=0;i<=k;i++)
    {
        if(num[i]==num[i+1])
            i++;
        else
            printf("%d ",num[i]);
    }
       // printf("%d ",num[i]);
    return 0;
}
