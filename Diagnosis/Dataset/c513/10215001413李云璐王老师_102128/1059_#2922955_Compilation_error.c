#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int cmp(const void*a1,const void*a2)
{
    int a=*(int*)a1;
    int b=*(int*)a2;
    return a-b;
}

int qh(int*c,int n,int min)
{
    data=0;
    for(int k=min;k<=n;k++)
    data+=c[k];
    return data;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);//将数组从小到大排序
    int min=a[0],max=a[n-1];
    int b[max]={0},c[max]={1},d[n]={0};
    d[0]=a[0];
    for(int i=0,l=1;i<n-1;i++)
    if(a[i]!=a[i+1]) {b[a[i]]=a[i+1]-a[i];d[l]=a[i+1];l++;}
    else c[a[i]]++;
   //b里存储a[i]高度差，c里存储a[i]高度的个数,d里存储a中的非重复数字从小到大
   for(int g=0;g<max;g++) printf("%d ",b[g]);
   for(int g=0;g<max;g++) printf("%d ",c[g]);
   
   int k;
   for(k=0;k<l;k++)
   {if(s>=0) s-=b[d[k]]*qh(c,d[k],min);
   else break;}
   int h;
   if(s>0) printf("%d+%d/%d",b[d[k]],s,qh(c,l-1,min));
   if(s<0) {s+=b[d[k-1]]*qh(c,d[k-1],min);
   return 0;
}