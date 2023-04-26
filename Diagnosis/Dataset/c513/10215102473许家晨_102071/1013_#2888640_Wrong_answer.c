#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*先判断输入的格式：
	是否有小数
	2个函数，分别处理整数和小数部分
输出的格式
*/
long long solveint(char *s){
	int flag=1;
	char *ps=s;
	int x[3]={0,1,-1}; 
	long long result=0;
	if(*ps=='-'){
		flag=-1;
		ps++;
	}
	while(*ps!='\0'){
		if(*ps>='0' && *ps<='2')
        {
            result=result*3+x[*ps-'0'];
        }
        else
        {
            break;
        }
        ps++;
    }
	return result*flag;
}

int main(){
	char input[31];
	scanf("%s",input);
	long long intpart=solveint(input);
	if(strchr(input,'.')=='\0')
	{
		printf("%lld",intpart);	
	}
	//如果是小数，还要考虑小数部分正负决定整数是否加减1；
	 
	return 0;
}