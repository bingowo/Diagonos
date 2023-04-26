#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *nocount[6]={"the","an","for","a","and","of"};

int isIgnore(char *s)
{
   char temp[101];
   for(int i=0;s[i];i++)
   {
       temp[i] = tolower(s[i]);
   }
   temp[strlen(s)]='\0';

   
   for(int i=0;i<6;i++)
   {
       if(strcmp(temp,nocount[i])==0) return 1;
   }
   return 0;
}

int countwords(char *s)
{
    char arr[101];int ret=0;
    char* pa = s, *pb = s;
    
    while(*pb!=0)
    {
       while(*pb ==' ') pb++;//pb跳过前导空格，到达单词的第一个字母，并将pa固定在首字母，用于pb-pa记录单词长度
       pa = pb;

       while(*pa)//pb后移，一直到单词结束的下一个位置，while(*pb)防止*pb=='\0'进入
       {   
           int flag=0;
           if(*pb==' ' || *pb=='\0')//该单词结束
           {
               memmove(arr,pa,pb-pa);
               arr[pb-pa]='\0';
               if(!isIgnore(arr)) ret++;
               flag=1;
           }
           if(flag==1) break;//已记录该单词，break开始下一轮找单词
           else pb++;
       }
    }
    return ret;

}

int main()
{
    int t;
    scanf("%d",&t);
    char c = getchar();
    for(int j = 0; j < t; j++)
    {
       char s[101];
       int count;
       gets(s);
       count = countwords(s);
       printf("case #%d:\n",j);
       printf("%d\n",count);
    }
    return 0;
}