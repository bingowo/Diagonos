#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double p[27];
int cmp(const void *a,const void *b)
{
char ch1,ch2; //ch1,ch2 为待比较的字母
int p1,p2; //p1,p2 为 ch1,ch2 在字母顺序表中的序号
ch1=*((char *)a);
ch2=*((char *)b);
if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
if(ch2>='a'&&ch2<='z') p2=ch2-'a'; else p2=ch2-'A';
if(p[p2]>p[p1]) return 1; // 按照字母使用频率由大到小重排
else if(fabs(p[p2]-p[p1])<1e-8) // 字母使用频率 相同的情况
if(p1==p2) return ch2-ch1; // 相同字母，小写在大写前面
else return p1-p2;
// 不同字母，但使用频率相同，则按照字母表顺序排列
else return -1;
}
int main()
{
    int x,i,k;
    scanf("%d",&x);
    for(k=0;k<x;k++){
    printf("case #%d:\n",k);

    for(i=0;i<26;i++) scanf("%lf",&p[i]);
    char str[101]; scanf("%s",str);
    qsort(str,strlen(str),sizeof(str[0]),cmp);
    printf("%s\n",str);

    }
}
