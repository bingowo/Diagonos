#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[17], a[17], b[17];
int l, len, t;
int cmp(const void*a,const void*b){
	char*a1=(char*)a;
	char*b1=(char*)b;
	return *a1>*b1?1:-1;
	
}
void go(int k)
{
 b[l] = a[k];
 printf("%s",&b[l]);
 l++;
 for (int i = k + 1; i < t; i++)
  go(i);
 l--;
 b[l] = '\0';
}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int v=0;v<T;v++){
    int f[150] = {0};
	scanf("%s\n",s); 
	printf("case #%d:\n",v);
	len = strlen(s);
	t = 0;
	for (int i = 0; i < len; i++)
 {
      if (!f[s[i]])
  {
   f[s[i]] = 1;
   a[t++] = s[i];
  }
 }
 qsort(a,t,sizeof(char),cmp);//上面一堆找出字符并降序排序
 l = 0;
 for (int i = 0; i < t; i++)
  {go(i);
  printf("\n");
  }}
 return 0;
}