#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>

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
    char str[110][40];
    int count = 0;
    while (scanf("%s", &str[count]) != EOF)
    {
        count++;
    }
    qsort(str,count,sizeof(char),strnumcmp);
    for (i = 0; i < count; ++i)printf("%s ", str[i]);
    printf("%s\n", str[i]);
}

