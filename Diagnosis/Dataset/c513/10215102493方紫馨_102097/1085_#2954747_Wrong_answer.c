#include<stdio.h>
#include<string.h>
int main()
{
	char a[501],b[501];
	while(scanf("%s%s",a,b)!=EOF){
	char ret[501];
	int r=0;
	for(int i=strlen(a)-1,j=strlen(b)-1;i>=0||j>=0;i--,j--){
		if(j<0){
			b[j] = '0';
		}
		if(i<0){
			a[i] = '0';
		}
		r = a[i]-b[j]+r;		
		if(r<0){
			ret[i] = r+10;r = -1;
		}else{
			ret[i] = r;r = 0;
		}			
	}
	int k=0;
	while(ret[k]==0)k++;
	for(;k<strlen(a);k++){
		printf("%d",ret[k]);
	}
	printf("\n");
 	}
	return 0;
}