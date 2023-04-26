#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int number(char *str)
{
     char t[100]={0};
    int i,count=0,j=0,k=0,l=0;
    l=strlen(str);
    t[k]=str[0];
    for(i=1;i<l;i++)
    {
        count=0;
        for(j=0;j<=k;j++){if(str[i]==t[j])count=0;if(str[i]!=t[j])count++;}
        if(count==k+1){k++;t[k]=str[i];}

    }
    return k+1;
}
int cmp(const void*a,const void*b)
{
    int k1,k2;
    char*s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    k1=number(a);
    k2=number(b);
    if(k1!=k2)return k2-k1;
    else return strcmp(s1,s2);

}
void paixu(int h)
{
   char s[110][30];
   int n,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%s",s[i]);
     qsort(s,n,sizeof(s[0]),cmp);
     printf("case #%d:\n",h);
      for(i=0;i<n;i++)
    printf("%s\n",s[i]);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
    {
        paixu(h);
    }
}
