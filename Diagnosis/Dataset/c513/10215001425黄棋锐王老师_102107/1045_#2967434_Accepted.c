#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	char c;
	int cnt;
}PAIR;
#define N 100000
int cn(char*s,PAIR*r)//求此行的各个字母重复次数 ,最后给出此行不同字母数(有效数组下标） 
{     int l=0,po=0;
	char*p=s;
	while(*p){
	for(r[po].c=*p,p=p+1,l=1;*p&&*p==*(p-1);p++,l++);
	     r[po].cnt=l;
	     po++;
       }
       return po;//此行不同字母数 ，放在一个数组fn[]中 
}

int whether(int n,int*fn,PAIR(*f)[101])//判断是否可操作 
{   int i,j;
	for(i=1;i<n;i++) if(fn[i]!=fn[0]) return 0;//有一行所含字母数不同 
	for(i=0;i<fn[0];i++)//j行第i个单独字母 
		for(j=1;j<n;j++) if(f[j][i].c!=f[j-1][i].c) return 0;
		return 1;
}
int cmp(const void*a,const void*b)//排序找中位数 
{  return *(int*)a-*(int*)b; 
}
 int main()
 {   PAIR f[N][101];//100000行，各有101个字符 
 	int n,i,j,m,sum=0;
 	int fn[N]={0};
 	int a[N]={0};
 	scanf("%d\n",&n);
 	char s[102]={'\0'};
 	for(i=0;i<n;i++)
 	{    scanf("%s\n",s);
 		fn[i]=cn(s,f[i]);//把s按字母拆开，fn记录字母数 
	 }
	 if(whether(n,fn,f))
	 {
	 	for(j=0;j<fn[0];j++)//f一列一列处理，即一个字母一个字母处理 
	 	{for(i=0;i<n;i++) a[i]=f[i][j].cnt;
	 	qsort(a,n,sizeof(int),cmp);
	 	if(n%2!=0) m=a[(n-1)/2];
		 else m=(a[(n-1)/2]+a[(n+1)/2])/2;
		  for(i=0;i<n;i++) {
		  	if(a[i]>m) sum+=a[i]-m;
		  	else sum+=m-a[i];
		  }
		 }
		 printf("%d\n",sum);
	 }
	 else printf("-1");
		return 0;
}