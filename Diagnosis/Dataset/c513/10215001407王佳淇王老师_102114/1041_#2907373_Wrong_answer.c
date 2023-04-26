#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s[1000];
	scanf("%s",s);
	int len=strlen(s),start,end,i,j,max=0;
	for(i=0;i<len;i++){
		if((i==0||s[i]!=s[i-1])&&(s[i]!=s[i+1]||s[i+1]=='\0')){
			start=i;
		for	(j=start;j<len;j++){
			if((j==0||s[j]!=s[j-1])&&(s[j]!=s[j+1]||s[j+1]=='\0')) end=j;
			else break;	}	
		}
		else i++;
		max=fmax(max,end-start);
	}
	printf("%d",max+3);
	return 0;
	
}