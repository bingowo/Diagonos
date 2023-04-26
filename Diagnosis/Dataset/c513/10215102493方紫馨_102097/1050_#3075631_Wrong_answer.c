#include<stdio.h>
#include<string.h> 
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		char s1[81];
		char s2[81];
		char s[81];
		scanf("%s%s%s",s1,s2,s);
		char a[81],b[81];
		int begin,end;
		for(int j=0;j<strlen(s);j++){
			if(s1[0]==s[j]){
				strncpy(a,s+j,strlen(s1));
				a[strlen(s1)]='\0';
				if(strcmp(a,s1)==0){
					begin=j+strlen(s1);
					break;
				}
			}
		}
		int len2=strlen(s2);
		for(int j=strlen(s)-1;j>=00;j--){
			if(s[j]==s2[len2-1]){
				strncpy(b,s+j-len2+1,len2);
				b[len2]='\0';
				if(strcmp(b,s2)==0){
					end=j-len2+1;
					break;
				}
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",end-begin);
	}
	
	return 0;
}