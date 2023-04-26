#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int value; char str[31];
}STR;
int ascii_to_int(char * str)
{
	int value=0,flag=-1;
	while(*str != '\0'){
		if(*str >= '0' && *str <= '9')
		{
			int temp = *str - '0';
			value = value*10 + temp;
			flag=1;
		}
		str++;
	}
	if(flag == -1) return -1;
	else	return value;
}
int strnumcmp(const void* a,const void* b)
{
	STR* str1 = (STR *)a,*str2 = (STR *)b;
	
	if(str1->value > str2->value)
		return 1;
	else if(str1->value == str2->value)
		return strcmp(str1->str,str2->str);
	else
		return -1;
}
int main()
{
	STR p[101];
	int i=0;
	while(scanf("%s",(p+i)->str) != EOF){
		p[i].value = ascii_to_int(p[i].str);
		i++;
	}
	qsort(p,i,sizeof(STR),strnumcmp);
	for(int j=0;j<i;j++){
		printf("%s ",(p+j)->str);
	}
	return 0;
}