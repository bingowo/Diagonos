#include<stdio.h>
#include<string.h>
#include<stdlib.h>
union num{
	int i;
	double d;
	unsigned char c[8];
};
int main(){
	char a[10];
	int m;
	scanf("%s",a); 
	while(a){
		union num j;
		if(strchr(a,'.')==0){
			j.i=atoi(a);
			m=4;
			for(int k=0;k<m;k++)
				printf("%02x ",j.c[k]);
			printf("\n");
		}
		else{
			j.d=atof(a);
			m=8;
			for(int k=0;k<8;k++)
				printf("%02x ",j.c[k]);
			printf("\n");
		}
		scanf("%s",a);
	}
	return 0;
}