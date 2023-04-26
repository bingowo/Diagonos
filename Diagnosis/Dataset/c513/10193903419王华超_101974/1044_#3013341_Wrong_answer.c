#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100005

int main() {
	char line[N];
	int flag=0;
	gets(line);
	for(int i=0;i<strlen(line)-1;i++){
		if(line[i]=='0'&&line[i+1]=='x'){
			int j=i+2;
			char ox[100];
			while(line[j]>='0'&&line[j]<='9'||line[j]>='a'&&line[j]<='f'){
				ox[j-i-2]=line[j];
				j++;
			}
			int len=j-i-2;
			if(len==0){
				printf("%d ",0);
				flag=1;
				i=j;
			}
			else{
				long long int sum=0;
				for(int k=0;k<len;k++){
					if(ox[k]>='0'&&ox[k]<='9'){
						sum+=(ox[k]-'0')*pow(16,len-k-1);
					}
					else{
						sum+=(ox[k]-'W')*pow(16,len-k-1);
					}
				}	
				printf("%lld ",sum);
				flag=1;
				i=j;
			}
		}
	}
	if(flag==0){
		printf("%d",-1);
	}
	return 0;
}