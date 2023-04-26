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
    int data=0;
    for(int k=min;k<=n;k++)
    data+=c[k];
    return data;
}//求和
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);//将数组从小到大排序
    int min=a[0],max=a[n-1];
    int b[max],c[max],d[n];
    for(int g=0;g<max;g++) {b[g]=0;c[g]=1;}
    for(int g=0;g<n;g++) d[g]=0;
    d[0]=a[0];
    int h,l;
    for(h=0,l=1;h<n-1;h++)
    if(a[h]!=a[h+1]) {b[a[h]]=a[h+1]-a[h];d[l]=a[h+1];l++;}
    else c[a[h]]++;
   //b里存储a[i]高度差，c里存储a[i]高度的个数,d里存储a中的非重复数字从小到大
   for(int g=0;g<max;g++) printf("%d ",b[g]);
   for(int g=0;g<max;g++) printf("%d ",c[g]);
   
   int k;
   for(k=0;k<l;k++)
   {if(s>=0) s-=b[d[k]]*qh(c,d[k],min);
   else break;}
   
   if(s>0) printf("%d+%d/%d",b[d[k]],s,qh(c,l-1,min));
   if(s<0) {s+=b[d[k-1]]*qh(c,d[k-1],min);
   return 0;
}