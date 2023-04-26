#include<stdio.h>
#include<stdlib.h>
int number(char* str)
{ int len,l,sum=0,flag=0;
 len=strlen(str);
 for(l=0;l<len;l++)
 if ((str[l]>='0')&&(str[l]<='9'))
   { sum=sum*10+str[l]-'0';
     flag=1;
 }
    if (flag==0) sum=-1;
    return sum;
}
int strnumcmp(const void* a, const void* b) {
    int s1,s2;
    char* str1, *str2;
    str1 = (char*)a;  
    str2 = (char*)b;
    s1 = number(str1);  			//提取第一个字符串中的数字
    s2 = number(str2); 			//提取第二个字符串中的数字
    if(s1 == s2)  return strcmp(str1, str2);   
    else {
        if(s1 > s2) return 1;
        else  return -1;
    }
}

int main()
{char s[110][50];
 int i=0,j=0;
while (scanf("%s", s[i])!= EOF)
    i++;
 qsort(s,i,sizeof(s[0]),strnumcmp);
 for(j=0;j<i-1;j++)
 { printf("%s ",s[j]);
 }
 printf("%s\n",s[i-1]);
 return 0;
}