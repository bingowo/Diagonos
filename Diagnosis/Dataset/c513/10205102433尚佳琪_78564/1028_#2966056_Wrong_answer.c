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
    int i;
    for(i=0;i<k;i++)
    {
        if(num[i]==num[i+1])
        {
            flag=1;
            if(i==k-1)
                flag=0;
        }
        else
        {
             printf("%d ",num[i]);
             flag=0;
        }
    }
    if(flag==0)
        printf("%d",num[k]);
       // printf("%d ",num[i]);
    return 0;
}
