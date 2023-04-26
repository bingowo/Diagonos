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
        if(len>255){
        	int i=0;
        	while(len>255){
        		i++;
				printf("255%c",temp);
				len-=255;
			}
			printf("%d%c",len,temp);
		}
		else{
			printf("%d%c",len,temp);
		}
		pa=pb;
		pb=pa;
    }  printf("\n");
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