#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int t,i,j,flag,number,r;
	long long int times[100],result[20];
	char s[61]; 
	scanf("%lld",&t);
	getchar();
	for(i=0;i<t;i++){
		r=0;flag=1;number=0;  //进制初始化 
		for(j=0;j<100;j++)times[j]=0; //出现次数的初始化 
        for(j=0;j<20;j++)result[j]=0;
		scanf("%s",s);  //输入神秘信息
		for(j=0;j<strlen(s);j++){
			if(times[s[j]-'0']==0){
				if(j==0){
					flag=0;times[s[j]-'0']=1;  //第一位数字为1 
					result[j]=times[s[j]-'0'];
				} 
				else if(flag==0){ 
					flag=1;times[s[j]-'0']=-1;  //第二位为0 
					result[j]=0; 
				}
				else if(flag){
					times[s[j]-'0']=r;result[j]=times[s[j]-'0'];  //按照正常顺序进行计算 
				}
				r++;
			}
			else if(times[s[j]-'0']!=0){  //数字重复出现
			    if(times[s[j]-'0']==-1)result[j]=0;
			    else result[j]=times[s[j]-'0'];
			}
		}  //转化成数字
		if(r==1)r++;
		for(j=0;j<strlen(s);j++){
			number=number*r+result[j];
		}
		printf("case #%lld:\n%lld\n",i,number);
	}
	return 0;
}