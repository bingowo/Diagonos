#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>//没有用到
int part(const char s[][15],char*c,int n)
{//s:词典,c[]：字符串，n：词典的长度
int len1=strlen(c);  //计算单词串的长度:没有用到
    int b[4005];
    for(int i=0;i<n;i++) b[i]=strlen(s[i]); //计算词典中每个词的长度
    int len2=b[0];
    for(int i=1;i<n;i++)
    {
        if(b[i]>len2) len2=b[i];  //找到词典中的最长词的长度
        else len2=b[i-1];
    }
    int m;
  char co[len2+1];//定义为常数数组
 for(int m=len2;m>0;m--)  //从最长词开始寻找相同单词
    {   int num=0;
        strncpy(co,c,m); //将单词串中前m位复制到co中
        if(m!=1)  //当查找的单词长度不为1时
        {
            int p=0;
            while(p<n)  //找到m长度的单词进行比较
         {
            if(b[p]==m && strcmp(co,s[p])==0)
            {
                num=1;
                break;
            }
            p++;
         }
        }

        else 
{
num=1;//当查找的单词长度为1时

}
        if(num==1) break;
}

for(int i=0;i<m;i++) printf("%s",co);
char *pt=&c[m];
   // c=c+m;
if(c+m=='/0')  
 return 0;
    else return part(s,c,n);//pt
}

int main()
{  int n;
   scanf("%d",&n);
   char s[4005][15];
   for(int i=0;i<n;i++) scanf("%s",s[i]); //输入词典中的词
   char c[5001];
   scanf("%s",c);//输入字符串
   part(s,c,n);
   printf("\n");
   return 0;
}



