#include <stdio.h>
#include <string.h>
int number(char *str)
{
      int len,i,sum=0,flag=0;
      len=strlen(str);
      for(i=0;i<len;i++)
          if(str[i]>='0'&&str[i]<='9')    //提取数字
          {  sum=10*sum+str[i]-'0';     flag=1; }
         if(flag==0) sum=-1; //字符串中没有数字则返回-1
     return sum;
}
int strnumcmp(const void *a,const void *b)
{    int s1,s2;
     char *str1,*str2;
     str1=(char *)a;  str2=(char *)b;
     s1=number(str1);  
     s2=number(str2);  
     if(s1==s2)  return strcmp(str1,str2);
     else
     {    if(s1>s2) return 1;
    else  return -1;
     }
}
int main()
{
    char str[101][31];
    int k=0,i;
    while(scanf("%s",&str[k])!=EOF)
        k++;
    qsort(str,k,sizeof(str[0]),strnumcmp);
    for(i=0;i<k-1;i++)
        printf("%s ",str[i]);
        printf("%s\n",str[i]);
    return 0;
}