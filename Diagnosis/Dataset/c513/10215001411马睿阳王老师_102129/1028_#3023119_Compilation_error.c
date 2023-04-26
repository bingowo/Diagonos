#include<stdio.h>
#include<string.h>

int cmp1(const void*a,const void*b)//升序
{
    int c=*(int *)a;
    int d=*(int *)b;
    if(c<d) return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)//降序
{
    int c=*(int *)a;
    int d=*(int *)b;
    if(c<d) return 1;
    else return -1;
}
int main()
{
    char a;
    int i=0,j=0,l=0;
    int d[1000]={0},b[1000]={0},c[1000]={0};
    scanf("%c",&a);
    for(i=0;i<1000;i++)
        b[i]=1;

   while(scanf("%d",&d[i])！=EOF)
  {
   if(b[d[i]]==1)
   {
       c[j]=d[i];
       j++;
       b[d[i]]=0;
   }
   i++;
  }

   l=j;
   if(a=='A') qsort(c,l-1,sizeof(int),cmp1);
   else if(a=='D') qsort(c,l-1,sizeof(int),cmp2);
   for(j=0;j<l;j++)
    printf("%d ",c[j]);
   return 0;
}
