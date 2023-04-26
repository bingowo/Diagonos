#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[17], a[17], b[17];
int l, len, t;
void go(int k)
{
 b[l] = a[k];
 printf("%s",b[l]);
 l++;
 for (int i = k + 1; i < t; i++)
  go(i);
 l--;
 b[l] = '\0';
}
int cmp(const void*a,const void*b){
	char*c=(char*)a;
	char*d=(char*)b;
	if(*c!=*d) return *c>*d?1:-1;
	else return 0;
}
int main()
{int T;
scanf("%d",&T);
getchar();
for(int v=0;v<T;v++){
printf("case #%d:\n",v);
 int f[150] = { 0 };
scanf("%s",s);
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
 qsort(a, t,sizeof(a[0]),cmp);//上面一堆找出字符并降序排序
 l = 0;
 for (int i = 0; i < t; i++)
  go(i);}
 return 0;
}