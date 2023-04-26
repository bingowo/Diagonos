#include <stdio.h>
int main(){
	int T,i;
	scanf("%d",&T);
	getchar();
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char ch;
		char s[101];
		int l=0;
		int cnt=0;
		while((ch=getchar())!='\n'){
			s[l]=ch;
			if(s[l]==' '){
				if(l==1){
					if(s[0]!='a') cnt++;
				}
				else if(l==2){
					if(s[0]=='a' && s[1]=='n') cnt=cnt;
					else{
						if(s[0]=='o' && s[1]=='f') cnt=cnt;
						else cnt++;
					}
				}
				else if(l==3){
					if((s[0]=='a' && s[1]=='n'&& s[2]=='d')||(s[0]=='t' && s[1]=='h'&& s[2]=='e')||(s[0]=='f' && s[1]=='o'&& s[2]=='r')){
						cnt=cnt;
					}
					else cnt++;
				}
				else if(l>3) cnt++;
				l=-1;
			}
			l++;
		}
		if(l==1){
			if(s[0]!='a') cnt++;
		}
		else if(l==2){
			if(s[0]=='a' && s[1]=='n') cnt=cnt;
			else{
				if(s[0]=='o' && s[1]=='f') cnt=cnt;
				else cnt++;
			}
		}
		else if(l==3){
			if((s[0]=='a' && s[1]=='n'&& s[2]=='d')||(s[0]=='t' && s[1]=='h'&& s[2]=='e')||(s[0]=='f' && s[1]=='o'&& s[2]=='r')){
				cnt=cnt;
			}
			else cnt++;
		}
		else if(l>3) cnt++;		
		printf("%d\n",cnt);
	}
}