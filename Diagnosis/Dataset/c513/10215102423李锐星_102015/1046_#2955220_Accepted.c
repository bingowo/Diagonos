#include <stdio.h>
#include <string.h>

int strcm(char *s)
{
	int len=strlen(s);
	if(len>3){
		return 0;
	}
	else if(len==1){
		if(s[0]=='a'||s[0]=='A'){
			return 1;
		}
		else{
			return 0;
		}
	} 
	else if(len==2){
		if(s[0]=='a'||s[0]=='A'){
			if(s[1]=='n'||s[1]=='N'){
				return 1;
			}
		}
		else if(s[0]=='o'||s[0]=='O'){
			if(s[1]=='f'||s[1]=='F'){
				return 1;
			}
		}
		else{
			return 0;
		}
	}
	else if(len==3){
		if(s[0]=='t'||s[0]=='T'){
			if(s[1]=='h'||s[1]=='H'){
				if(s[2]=='e'||s[2]=='E'){
					return 1;
				}
			}
		}
		else if(s[0]=='f'||s[0]=='F'){
			if(s[1]=='o'||s[1]=='O'){
				if(s[2]=='r'||s[2]=='R'){
					return 1;
				}
			}
		}
		else if(s[0]=='a'||s[0]=='A'){
			if(s[1]=='n'||s[1]=='N'){
				if(s[2]=='d'||s[2]=='D'){
					return 1;
				}
			}
		}
		else{
			return 0;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	char c;
	c=getchar();
	char s[101];
	for (i=0;i<T;i++){
		int cnt=0;
		int j=0;
		while((c=getchar())!='\n'){
			if(c!=' '){
				s[j]=c;
				j++;
			}
			else{
				s[j]='\0';
				j=0;
				if(strcm(s)==0){
					cnt++;
				}
			}
		}
		s[j]='\0';
		if(strcm(s)==0){
			cnt++;
		}
		printf("case #%d:\n",i);
		printf("%d\n",cnt);		
	}
	return 0;
}