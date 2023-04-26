#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p[35]={2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,91,97};
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s1[55],s2[55];
        int a[50]={0},m=0,b[50]={0},n=0,c[100]={0},t=0;
        int a1[50]={0},m1=0,b1[50]={0},n1=0;
        scanf("%s %s",s1,s2);
        int len1=strlen(s1),len2=strlen(s2);
        for(int i=0;i<len1;i++)
        {
            if(s1[i]!=',')
                a[m]=a[m]*10+s1[i]-'0';
            else if(s1[i]==',')
            {
                m++;
            }
        }
        m++;
        for(int i=0;i<len2;i++)
        {
            if(s2[i]!=',')
                b[n]=b[n]*10+s2[i]-'0';
            else if(s2[i]==',')
            {
                n++;
            }
        }
        n++;
        for(int i=m-1;i>=0;i--)
            a1[m1++]=a[i];
        for(int i=n-1;i>=0;i--)
            b1[n1++]=b[i];
        int len=m>n?m:n;
        int carry=0;
        //printf("%d\n",len);
        for(int i=0;i<len;i++)
        {
            c[t]=(a1[i]+b1[i]+carry)%p[i];
            carry=(a1[i]+b1[i]+carry)/p[i];
           // printf("%d %d %d\n",a[i],b[i],c[t]);
            t++;
        }
        if(carry!=0)
        {
            c[t]=carry;
         //   printf("%d \n",c[t]);
            t++;
        }

        printf("case #%d:\n",i);
       for(int i=t-1;i>0;i--)
            printf("%d,",c[i]);
        printf("%d\n",c[0]);
        //printf("%d\n",t);
    }
}
