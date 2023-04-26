#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    char*s1,*s2;
    s1=*((char*)a);
    s2=*((char*)b);
    return s1-s2;
}
int number(int k,int h)
{
    int i=0,sum=1;
    for(i=0;i<h;i++)sum=sum*(k-i);
    for(i=0;i<h;i++)sum=sum/(i+1);
    return sum;
}
void paixu(int o)
{
    char s[20]={0};
    char t[20]={0};
    char a[1000][20]={0};
    scanf("%s",s);
    int i=0,count=0,j=0,k=0;
    t[k]=s[0];
    for(i=1;s[i];i++)
    {
        count=0;
        for(j=0;j<=k;j++){if(s[i]==t[j])count=0;if(s[i]!=t[j])count++;}
        if(count==k+1){k++;t[k]=s[i];}
    }
    qsort(t,k+1,sizeof(t[0]),cmp);
    int r=0,l=0,h=0,c=0,n=0,p=0;
    for(i=0;i<k+1;i++)
    {
        for(h=0;h<(k+1-i);h++)
        {
            n=number(k-i,h);
            for(p=0;p<n;p++)
            {
                a[c][0]=t[i];
                for(l=1;l<h+1;l++)
            {
                a[c][l]=t[l+i+p];
            }
            c++;

            }

        }
    }
    printf("case #%d:\n",o);
    for(i=0;i<c;i++)printf("%s\n",a[i]);
    printf("%s",a[i]);
}
int main()
{
    int N,o;
    scanf("%d",&N);
    for(o=0;o<N;o++)
        paixu(o);
}
