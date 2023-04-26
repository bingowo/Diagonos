#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int h=0;h<n;h++)
    {
        char s1[100],s2[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s1);
        char *p=s1;
        int a1,b1,i=0;
        while(*p)
    {
       if(*p!=',') a[i]=*p-'0',i++;
       p++;
    }
    a1=i;
        scanf("%s",s2);
        p=s2;
        i=0;
    while(*p)
    {
       if(*p!=',') b[i]=*p-'0',i++;
       p++;
    }
    b1=i;
        int prime[25]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

       for(int t=0;t<a1/2;t++)
    {
        int me=a[t];
        a[t]=a[a1-1-t];
        a[a1-1-t]=me;
    }//第一组数据换位置
    for(int t=0;t<b1/2;t++)
    {
        int me=b[t];
        b[t]=b[b1-1-t];
        b[b1-1-t]=me;
    }//第二组数据换位置


        int j=0,m,count=(a1>b1)?a1:b1;

        for(m=0,n=0;m<count;m++,n++)
            {c[m]=(a[m]+b[m]+j)%prime[n];
            j=(a[m]+b[m]+j)/prime[n];}
            if((a[m-1]+b[m-1]+j)>=prime[n-1]) {c[m]=(a[m-1]+b[m-1]+j)/prime[n-1];count++;}
       for(int i=0;i<12;i++)
        {
            int me=c[i];
            c[i]=c[24-i];
            c[24-i]=me;
        } //c调换位置
       printf("case #%d:\n",h);
        for(int i=25-count;i<24;i++)
        {
           printf("%d,",c[i]);
        }
        printf("%d",c[24]);
        printf("\n");


}
    return 0;
}
