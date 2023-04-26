#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*先判断输入的格式：
	是否有小数
	2个函数，分别处理整数和小数部分
输出的格式
*/
long long solveint(char *s)
{
    int flag=1;
    char *ps=s;
    int x[3]= {0,1,-1};
    long long result=0;
    if(*ps=='-')
    {
        flag=-1;
        ps++;
    }
    while(*ps!='\0')
    {
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
void solveflo(long long *result,char *flo)
{
    int x[3]= {0,1,-1};
    
    long long denom=1;
    long long numer=0;
    while(*flo!='\0')
    {
        if(*flo>='0' && *flo<='2')
        {
            denom=3*denom;
			numer=numer*3+x[*flo-'0'];
        }
        else
        {
            break;
        }
        flo++;
    }
    result[0]=numer;
    result[1]=denom;


}

int main()
{
    char input[31];
    int flag=1;
    if(input[0]=='-')flag=-1;
	scanf("%s",input);
    long long intpart=solveint(input);
    if(strchr(input,'.')=='\0')
    {
        printf("%lld",intpart);
    }
    //如果是小数，还要考虑小数部分正负决定整数是否加减1；
	else{
		//有小数部分
		char *res=strchr(input,'.');
		res++;
		long long result[2]; 
		solveflo(result,res);
		if(intpart==0){
			//整数部分为0
			printf("%lld %lld",result[0]*flag,result[1]);
		} 
		else{
			//整数部分不为0
			if(intpart>0 && result[0]<0){
				intpart-=1;
				printf("%lld %lld %lld",intpart,result[1]+result[0],result[1]);
			} 
			else if (intpart<0 &&result[0]>0){
				intpart+=1;
				printf("%lld %d %d",intpart,result[1]-result[0],result[1]);
			}
			else if (intpart<0 &&result[0]<0){
				printf("%lld %d %d",intpart,result[0]*-1,result[1]);
			}
			else{
				printf("%lld %d %d",intpart,result[0],result[1]);
			}
		}
	}
    return 0;
}