#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int zhishu(int x){
	int i=1;
	while(x>0){
		i*=3;x--;
	}
	return i;
}
int GCD(int a,int b)
{
    int m,n;
    m = (a>b)?a:b;
    n = (a>b)?b:a;
    if(n == 0) return m;
    else return GCD(n,m%n);
}

int main() {
	char s[31],zhengshu[31],xiaoshu[31];
	int i,j,result,x,len,len1,a,k,result1=0,result2=0;
	scanf("%s",s);
	if(strchr(s,'.')==NULL){
		len=strlen(s);result=0;
		len1=len-1;
		for(i=0;i<len;i++){
			if(s[i]=='2')x=-1;
			else x=s[i]-'0';
			result+=(x*zhishu(len1));
			len1--;
		}
		printf("%d",result);
	}   //不带小数点的计算 
	else{
		i=0;
		while(s[i]!='.'){
			zhengshu[i]=s[i];
			i++;
		}   //整数部分计入一个字符数组,i是字符个数
		len=i;result=0;len1=len-1;
		for(k=0;k<len;k++){
			if(zhengshu[k]=='2')x=-1;
			else x=zhengshu[k]-'0';
			result+=(x*zhishu(len1));
			len1--;
		}   //result为整数部分十进制 
		len=strlen(s);j=0;i++;
		while(i<len){
			xiaoshu[j]=s[i];
			i++;j++;
		}   //小数部分计入一个字符数组,j是字符个数
		len=j;
		result2=zhishu(len);  //分母 
		for(k=0;k<len;k++){
			if(xiaoshu[k]=='2')x=-1;
			else x=xiaoshu[k]-'0';
			result1+=(x*zhishu(len-k-1));  //分子 
		}
		if(result1<0){
			if(result>0){
			    result--;result1=result2+result1;		
			}
		}
		
		else if(result<0){
			if(result1>0){
				result++;result1=result2-result1;
			}
		}
		
		if(result1>0)a=GCD(result1,result2);
		else if(result1<0)a=GCD(-result1,result2);
		
		if(result==0)printf("%d %d",result1/a,result2/a);
		else printf("%d %d %d",result,result1/a,result2/a);
	}
	return 0;
}