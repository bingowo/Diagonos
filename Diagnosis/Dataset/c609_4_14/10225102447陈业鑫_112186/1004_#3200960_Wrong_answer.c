#include<stdio.h>
#include<string.h>
char changtable[] = {"0123456789ABCDEF"};
char gettable[] = {"0123456789ABCDEFabcdef"};
int main(){
	char outp[32] = {'0'};
	char gech[100] = {'\0'};
	int A, B;
	scanf("%d", &A);
	int len = 0;
	scanf("%s", &gech);
	scanf("%d", &B);
	int rest = 0;
	len = strlen(gech);
	int loca = 1;//定位读入的A的位
	int toA = 1;
	int ge = 0;//将A转成10进制值
	while(len-loca>=0){
		while(gech[len-loca]!=gettable[rest]){
			if(rest>=10){
				if(gech[len-loca]==gettable[rest+6])break;
			}
			rest++;
		}//取值，兼容a/A = 10
		ge += toA*rest;
		rest = 0;
		toA *= A;
		loca++;
	}
	int j = 0;
	if(ge==0)outp[j] = changtable[ge];
	while(ge>0){
		outp[j] = changtable[ge%B];
		ge /= B;
		j++;
	}
	for(int i=j-1;i>=0;i--){
		printf("%c", outp[i]);
	}
	return 0;
}
