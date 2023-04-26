#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>
/**
实现int strnumcmp(char * str1,char * str2);函数，当两个字符串的比较部分不包含数字时，函数功能和strcmp一样。否则比较字符串中的数字大小。例如：
"abc32"<"abc6";
"abcd">"abc9";
"abcd"<"abce";
基本思想：当前位置如果全是是数字，则计数；否则采用strcmp的方法比较
**/
int strnumcmp(char *str1,char *str2){

	int i,j;
	int len1=strlen(str1);
	int len2=strlen(str2);
	int int1;
	int int2;
	for(i=0,j=0;i<len1,j<len2;i++,j++){
		int1=0;
		int2=0;
        //当前值不等，且不全是数字，直接采用strcmp的方法
		if (str1[i]!=str2[j] && !(isdigit(str1[i]) && isdigit(str2[j])))
		{
			return str1[i]-str2[j];
		}
		//str1遇到数字，则进行迭代
		while (isdigit(str1[i]))
		{
			int1=int1*10+str1[i]-'0';
			i++;
		}
		//str2遇到数字，则进行迭代
		while (isdigit(str2[j]))
		{
			int2=int2*10+str2[j]-'0';
			j++;
		}

		//比较大小
		if (int1!=int2)
		{
			return int1-int2;
		}
	}

	return 0;
}
int main()
{
	char* str[100];
	int i=0;
	for(i=0;i<100;i++){
        scanf("%s",str[i]);
        if(str[i]==EOF) break;
	}
	for(int j=0;j<i;j++){
        printf("%s ",str[j]);
	}
	
	for(int j=0;j<i-1;j++){
        for(int k=0;k<i-j-1;k++){
             if(strnumcmp(str[k],str[k+1])==0){
                char temp[30];
                strcpy(temp,str[k]);
                strcpy(str[k],str[k+1]);
                strcpy(str[k+1],str[k]);
            }
        }
        for(int k=0;k<i;k++){
            printf("%s ",str[j]);
        }

	}
	
	return 0;
}