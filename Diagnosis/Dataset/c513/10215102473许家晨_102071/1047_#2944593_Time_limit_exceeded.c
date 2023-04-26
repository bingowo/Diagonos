#include<string.h>
#include<stdio.h>
void RLE(char *s) {
    char* pa=s;
    char* pb=pa;
	while(*pb) {
		char temp;
		temp=*pa;
		int len=0;
        while(*pb==*pa)pb++,len++;
        if(pb-pa>255){
        	int i=0;
        	while(pb-pa>255){
        		i++;
				printf("255%c",temp);
			}
			printf("%d%c",(len-i*255),temp);
		}
		else{
			printf("%d%c",len,temp);
		}
		pa=pb;
		pb=pa;
    }
}
int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T){
		char s[501]={'\0'};
		scanf("%s",s);
		printf("case #%d:\n",cnt++);
		RLE(s);
		T--;
	}
	return 0;
}