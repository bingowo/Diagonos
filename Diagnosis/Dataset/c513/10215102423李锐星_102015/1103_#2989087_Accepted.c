#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trans(char *s)
{
	if(s[0]=='A') return 1;
	if(s[0]=='B') return 2;
	if(s[0]=='C') return 3;
	return 4;
}

int main()
{
	char s1[4],s2[100];
	int a[5];
	int i;
	for (i=0;i<5;i++){
		a[i]=0;
	}
	while((scanf("%s%s",s1,s2))!=EOF){
		if(strcmp(s1,"OUT")==0){
			int flag=trans(s2);
			printf("%d\n",a[flag]);
		}
		else {
			char s3[100];
			int j=0;
			for (i=0;s2[i]!=',';i++);
			i++;
			for (;s2[i]!=0;i++){
				s3[j]=s2[i];
				j++;
			}
			s3[j]='\0';
			s2[2]='\0';
			if(s1[0]=='I'){
				int flag=trans(s2);
				a[flag]=atoi(s3);
			}
			
			else{
				int flag1,flag2;
				flag1=trans(s2);
				flag2=trans(s3);
				if(strcmp(s1,"MOV")==0){
					a[flag1]=a[flag2];
				}
				else if(s1[0]=='A'){
					a[flag1]+=a[flag2];
				}
				else if(s1[0]=='S'){
					a[flag1]-=a[flag2];
				}
				else if(s1[0]=='M'){
					a[flag1]*=a[flag2];
				}
				else{
					a[flag1]/=a[flag2];
				}
			}
		}
	}
	return 0;
}