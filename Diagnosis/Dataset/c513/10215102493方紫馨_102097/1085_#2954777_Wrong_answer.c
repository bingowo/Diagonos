#include<stdio.h>
#include<string.h>
int compare(char a[],char b[]){
	if(strcmp(a,b)==0)
		return 0;
	int len_a = strlen(a);
	int len_b = strlen(b);
	if(len_a!=len_b)
		return len_a - len_b;
	int i=0;
	while(a[i]==b[i])i++;
	return a[i] - b[i];
}
int main()
{
	char a[501],b[501],t[501];
	while(scanf("%s%s",a,b)!=EOF){
	int sign=compare(a,b);
	if(sign==0){
		printf("0");continue;
	}
	if(sign<0){
		strcpy(t,a);strcpy(a,b);strcpy(b,t);
	}
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
	if(sign<0)
		printf("-");
	for(;k<strlen(a);k++){
		printf("%d",ret[k]);
	}
	printf("\n");
 	}
	return 0;
}