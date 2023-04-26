#include <stdio.h>
#include <string.h>

char trans(char* s)
{
	if(strcmp(s,".-")==0){
		return 'A';
	}
	if(strcmp(s,"-...")==0){
		return 'B';
	} 
	if(strcmp(s,"-.-.")==0){
		return 'C';
	}
	if(strcmp(s,"-..")==0){
		return 'D';
	}
	if(strcmp(s,".")==0){
		return 'E';
	}
	if(strcmp(s,"..-.")==0){
		return 'F';
	}
	if(strcmp(s,"--.")==0){
		return 'G';
	}
	if(strcmp(s,"....")==0){
		return 'H';
	}
	if(strcmp(s,"..")==0){
		return 'I';
	}
	if(strcmp(s,".---")==0){
		return 'J';
	}
	if(strcmp(s,"-.-")==0){
		return 'K';
	}
	if(strcmp(s,".-..")==0){
		return 'L';
	}
	if(strcmp(s,"--")==0){
		return 'M';
	}
	if(strcmp(s,"-.")==0){
		return 'N';
	}
	if(strcmp(s,"---")==0){
		return 'O';
	}
	if(strcmp(s,".--.")==0){
		return 'P';
	}
	if(strcmp(s,"--.-")==0){
		return 'Q';
	}
	if(strcmp(s,".-.")==0){
		return 'R';
	}
	if(strcmp(s,"...")==0){
		return 'S';
	}
	if(strcmp(s,"-")==0){
		return 'T';
	}
	if(strcmp(s,"..-")==0){
		return 'U';
	}
	if(strcmp(s,"...-")==0){
		return 'V';
	}
	if(strcmp(s,".--")==0){
		return 'W';
	}
	if(strcmp(s,"-..-")==0){
		return 'X';
	}
	if(strcmp(s,"-.--")==0){
		return 'Y';
	}
	if(strcmp(s,"--..")==0){
		return 'Z';
	}
	if(strcmp(s,"-----")==0){
		return '0';
	}
	if(strcmp(s,".----")==0){
		return '1';
	}
	if(strcmp(s,"..---")==0){
		return '2';
	}
	if(strcmp(s,"...--")==0){
		return '3';
	}
	if(strcmp(s,"....-")==0){
		return '4';
	}
	if(strcmp(s,".....")==0){
		return '5';
	}
	if(strcmp(s,"-....")==0){
		return '6';
	}
	if(strcmp(s,"--...")==0){
		return '7';
	}
	if(strcmp(s,"---..")==0){
		return '8';
	}
	if(strcmp(s,"----.")==0){
		return '9';
	}
}

void solve()
{
	char s[1001];
	scanf("%s",s);
	int len=strlen(s);
	int i=0;
	char t[10];
	t[0]=0; 
	int k;
	while(i<=len){
		if(i==0){
			k=0;
			while(s[i]!='/'&&s[i]!='\0'){
				t[k]=s[i];
				i++;
				k++;
			}
			t[k]=0;
			printf("%c",trans(t));
		}
		else if(s[i]=='/'){
			i++;
			k=0;
			if(s[i]=='/'){
				int cnt=1;
				i++;
				while(s[i]=='/'){
					cnt++;
					i++;
				}
				i--;
				if(cnt==2){
					printf(" ");
				}
				else if(cnt==4){
					printf(".");
				}
			}
			else{
				while(s[i]!='/'&&s[i]!='\0'){
					t[k]=s[i];
					i++;
					k++;
				}
				t[k]='\0';
				printf("%c",trans(t));
				if(s[i]=='\0'){
					printf("\n");
					return;
				}
			}
			
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
 } 