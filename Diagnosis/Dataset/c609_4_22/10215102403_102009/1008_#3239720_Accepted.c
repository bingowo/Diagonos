#include<stdio.h>
#include<string.h>
#include<stdlib.h>
union num{
	int i;
	double d;
	unsigned char c[8];
};
int main(){
	char a[20];
	while(scanf("%s",a)!=EOF){
		union num j;
		if(strchr(a,'.')==0){
			j.i=atoi(a);
			for(int k=0;k<4;k++)
				printf("%02x ",j.c[k]);
			printf("\n");
		}
		else{
			j.d=atof(a);
			for(int k=0;k<8;k++)
				printf("%02x ",j.c[k]);
			printf("\n");
		}
	}
	return 0;
}