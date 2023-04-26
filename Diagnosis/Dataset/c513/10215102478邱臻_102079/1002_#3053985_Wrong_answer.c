#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int count,t,z,i,j,flag,number;
	char s[61];
	int num[100]={},result[100];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		for(j=0;j<100;j++){num[j]=0;result[j]=0;}
		z=2;flag=0;count=0;number=0;
		scanf("%s",s);
		for(j=0;j<strlen(s);j++){
			if(num[s[j]-'0']==0){
				if(j==0){
					result[j]=1;flag=1;
					num[s[j]-'0']=1;
				}
				else if(flag==1){
					result[j]=0;flag=0;
					num[s[j]-'0']=-1;
				}
				else {
					result[j]=z;num[s[j]]=z;
					z++;
				}
				count++;
			}
			else {
				if(num[s[j]]>0)result[j]=num[s[j]];
				else result[j]=0;
			}
		}  //化为整数
		j=0;
		while(j<strlen(s)){
			number=number*count+result[j];
			j++;
		}  //十进制计算 
		printf("case #%d:\n%d\n",i,number);
	}
	return 0;
}