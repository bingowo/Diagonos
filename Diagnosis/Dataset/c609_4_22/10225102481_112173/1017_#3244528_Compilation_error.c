#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define INF 101
char type,str;

bool cmp(int a,int b)//int为数组数据类型
{
    return a>b;//降序排列
    //return a<b;//默认的升序排列
}

int main() {
    int i,len,num,a[1010];
 int start=0,j;num=0;
    memset(a,0,sizeof(a));
 
 scanf("%c",&type);
 getchar();
 int mark=0;
 while ((str = getchar()) != EOF){//可多行读取，采用EOF读取截止
   if(str==' '||str=='\n') {
    if(mark==0){
    mark=1;
    num++;}
   }
   else
   {
    mark=0;
    a[num]=a[num]*10+str-'0';
   }
 }
 if(type=='A')
  sort(a,a+num);
 else
  sort(a,a+num,cmp);
 int last=a[0],sortnum=1;
    for(i=1; i<num; i++) {
        if(last==a[i])
   continue;
  else
  {a[sortnum]=a[i];  
  sortnum++;
  last=a[i];}
  
    }
 for(i=0;i<sortnum;i++){
  if(i==sortnum-1)
   printf("%d\n",a[i]);
  else
   printf("%d ",a[i]);
 }