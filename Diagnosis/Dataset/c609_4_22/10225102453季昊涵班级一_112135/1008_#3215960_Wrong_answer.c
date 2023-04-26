#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	char in[1000];
	scanf("%s",in);
	char *p;
	if((p=strchr(in,'.'))!=NULL){
		double a=atof(in);
		int out[8]={0,0,0,0,0,0,0,0};
		int k=0;
		unsigned long long int b=(unsigned long long int)a;
		do{
			int temp=0;
			for(int i=0;i<8;i++){
				int j=b&1;
				temp=temp+j*pow(2,i);
				b=b>>1;
			}
			out[k++]=temp;
		}while(b>>1);
		for(int o=0;o<8;o++){
			if(out[o]>15)
			printf("%x ",out[o]);
			else
			printf("0%x ",out[o]);
		}
		printf("\n");
	}else{
		int a=atoi(in);
		int out[4]={0,0,0,0};
		int k=0;
		int b=(unsigned int)a;
		do{
			int temp=0;
			for(int i=0;i<8;i++){
				int j=b&1;
				temp=temp+j*pow(2,i);
				b=b>>1;
			}
			out[k++]=temp;
	}while(b>>1);
		for(int o=0;o<4;o++){
			if(out[o]>15)
			printf("%x ",out[o]);
			else
			printf("0%x ",out[o]);
		}
		printf("\n");	
	}
	return 0;
}