#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,91,97};
void Readnumber(char*s,int* a){
	int j=0,l=0,t;
	int ss[100]={0};
	while(j<strlen(s)) { t=0;
		for(;s[j]!=','&&j<strlen(s);j++) t=t*10+s[j]-'0';
		ss[l++]=t;
		j++;
	} 
	for(j=0;j<l;j++){
		a[l-j-1]=ss[j];
	}
}
	void carry(int* dex){
		int i;
		for(i=999;i>0;i--){//转十进制，满10进一 
			dex[i-1]+=dex[i]/10;
			dex[i]%=10;
		}
	}

	void Mult(int *dex,int count){//每一位置的数乘以此次循环的位权 
		int i; 
		for(i=999;i>=0;i--) dex[i]*=prime[count];
		carry(dex);
	}
	
	
	void Add(int*dex,int a){
		  int count = 999;
    	while(a!=0)
    {
        dex[count--] += a % 10;
        a /= 10;
    }
    
    	carry(dex);
						}
								
int main(){
	int DEX[1000]={0};
		char s[100]={'\0'};
		int a[27]={0};
		int j,i;
			scanf("%s",s);
			Readnumber(s,a);
			for(j=26;j>=0&&a[j]==0;j--);//00001203的1的位置 
		for(;j>=0;j--){
			Mult(DEX,j);
			Add(DEX,a[j]);
		}
		 int d=0;
		 while(DEX[d]==0&&d<1000)d++;
		 while(d<1000) printf("%d",DEX[d++]);
		return 0;
}