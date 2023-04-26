#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
void paixu(int t[25],int k,int j)
{
   int i=0,min=0,l=0;int m[25]={0};
   for(i=0;i<=k;i++){if(t[i]>0 && t[i]<t[min])min=i;}
   l=t[min];t[min]=0;t[k+1]=l;
   if(k==j-1)j++;
   for(i=0;i<=k;i++){m[i]=t[i];}
   qsort(m,25,sizeof(int),cmp);
   for(i=j-1;i>k;i--)printf("%d",t[i]);
   for(i=k;i>=0;i--)printf("%d",m[i]);
   printf("\n");
   return 0;
}
void jisuan(h)
{
    int t[25]={0};char s[25]={0};
    int i=0,j=0;
    scanf("%s",s);j=strlen(s);
    for(i=0;s[i];i++){t[j-i-1]=s[i]-'0';}
    printf("case #%d:\n",h);
    for(i=0;i<=j-1;i++)
    {
        if(t[i]>t[i+1] && i+1<j && t[i+1]!=0)
        {int m=0;m=t[i];t[i]=t[i+1];t[i+1]=m;
         for(i=j-1;i>=0;i--)printf("%d",t[i]);printf("\n");
         return ;
        }
        else if(t[i]>t[i+1] && i+1<j && t[i+1]==0)
        {
            paixu(t,i,j);return ;
        }
    }
    if(i==j)
    {
        for(i=0;i<j;i++){if(t[i]!=0)break;}
        if(i==j-1){for(i=j-1;i>=0;i--)printf("%d",t[i]);printf("0\n");}
        else paixu(t,j-1,j);
    }
    return ;



}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
