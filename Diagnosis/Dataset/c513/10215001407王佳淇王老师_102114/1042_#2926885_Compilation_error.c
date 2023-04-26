#include <stdio.h>
#include <string.h>
#include <calgorithm>
int cmp(const void*a,const void*b){
	char*a1=(char*)a;
	char*b1=(char*)b;
	return *a1>*b1;
	
}
int main()
{int T;
scanf("%d",&T);
for(int v=0;v<T;v++){
 char s[17], a[17];
 int f[150] = { 0 };
 scanf("%s",s);
 int len = strlen(s);
 int t = 0;
 for (int i=0; i<len;i++)
 {
  if (!f[s[i]])
  {
   f[s[i]] = 1;
   a[t++] = s[i];
  }
 }
 qsort(a,t,sizeof(char),cmp);//上面一堆找出字符并降序排序
 printf("case #%d:\n",v);
 for (int i=0; i<t;i++)//从哪个字符开始
  for (int j=1;j<=t-i;j++)//每次输出多少位
  {
   for (int k = i; k < i + j; k++)//输出每个值
    printf("%s\n",a[k]);
  }
  }
 return 0;
}