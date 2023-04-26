#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int judge(char*a,int j)
{
    int m=strlen(a);
    for(int i=1;i<j;i++)
    {
        if(a[m-i]>a[m-i-1]) return 1;
    }
    return 0;
}
int cmp(char*a,char*b)
{
    return *a-*b;
}
int main()
{
    int t,i,j,m,c,k,h;
    char a[22],b[22];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {scanf("%s",a);
    printf("case #%d:\n",i);
    m=strlen(a);
    for(j=2;j<=m;j++)
    {if(judge(a,j)) break;}
    if(j<m+1)
        {
            for(k=0;a[m-1-k]<=a[m-j];k++);
            c=a[m-j];
            a[m-j]=a[m-1-k];
            a[m-1-k]=c;
            for(h=0;h<=(j-1);h++)
            {b[h]=a[m-h-1];}
            qsort(b,j-1,sizeof(char),cmp);
            for(h=0;h<j-1;h++)
            {a[m-j+1+h]=b[h];}}
    else{
    qsort(a,m,sizeof(char),cmp);
    for(k=0;k<m;k++)
    {a[m-k]=a[m-k-1];}
    if(a[1]=='0')
{   a[0]='0';
    for(h=1;a[h]=='0';h++);
    c=a[h];
    a[h]='0';
    qsort(a,m+1,sizeof(char),cmp);
    a[0]=c;



    }
    else{a[0]=a[1];
         a[1]='0';}
    }
    printf("%s\n",a);}

}
