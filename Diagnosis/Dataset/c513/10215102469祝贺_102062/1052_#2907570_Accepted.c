#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char ans[7];int sp=0;
char table[20]="GUWXZFHSVRTINOE";
int find[256];
int cmp1(const void*a,const void*b){
	char s1=*((char*)a),s2=*((char*)b);
	return find[s1]-find[s2];
}
int cmp(const void*a,const void*b){
	char s1=*((char*)a),s2=*((char*)b);
	return s1-s2;
}
void solve(char* s){
	int i=0;
	while(i<strlen(s)){
	    while(i<strlen(s) && s[i]=='a')i++;
		if(i==strlen(s))break;
		switch(s[i]){
			case('G'):{
				{	s[strchr(s,'E')-s]='a';
					s[strchr(s,'I')-s]='a';
					s[strchr(s,'G')-s]='a';
					s[strchr(s,'H')-s]='a';
					s[strchr(s,'T')-s]='a';
					ans[sp++]='8';
				}
				break;
			}
			case('U'):{
				{
					s[strchr(s,'F')-s]='a';
					s[strchr(s,'O')-s]='a';
					s[strchr(s,'U')-s]='a';
					s[strchr(s,'R')-s]='a';
					ans[sp++]='4';
				}
				break;
			}
			case('W'):{
				{
					s[strchr(s,'T')-s]='a';
					s[strchr(s,'W')-s]='a';
					s[strchr(s,'O')-s]='a';
					ans[sp++]='2';
				}
				break;
			}
			case('X'):{
				{
					s[strchr(s,'S')-s]='a';
					s[strchr(s,'I')-s]='a';
					s[strchr(s,'X')-s]='a';
					ans[sp++]='6';
				}
				break;
			}
			case('Z'):{
				{
					s[strchr(s,'Z')-s]='a';
					s[strchr(s,'E')-s]='a';
					s[strchr(s,'R')-s]='a';
					s[strchr(s,'O')-s]='a';
					ans[sp++]='0';
				}
				break;
			}
			case('F'):{
				{
					s[strchr(s,'F')-s]='a';
					s[strchr(s,'I')-s]='a';
					s[strchr(s,'V')-s]='a';
					s[strchr(s,'E')-s]='a';
					ans[sp++]='5';
				}
				break;
			}
			case('H'):{
				{
					s[strchr(s,'T')-s]='a';
					s[strchr(s,'H')-s]='a';
					s[strchr(s,'R')-s]='a';
					s[strchr(s,'E')-s]='a';
					s[strchr(s,'E')-s]='a';
					ans[sp++]='3';
				}
				break;
			}
			case('S'):{
				{
					s[strchr(s,'S')-s]='a';
					s[strchr(s,'E')-s]='a';
					s[strchr(s,'V')-s]='a';
					s[strchr(s,'E')-s]='a';
					s[strchr(s,'N')-s]='a';
					ans[sp++]='7';
				}
				break;
			}
			case('I'):{
				{
					s[strchr(s,'N')-s]='a';
					s[strchr(s,'I')-s]='a';
					s[strchr(s,'N')-s]='a';
					s[strchr(s,'E')-s]='a';
					ans[sp++]='9';
				}
				break;
			}
			case('N'):{
				{
					s[strchr(s,'N')-s]='a';
					s[strchr(s,'O')-s]='a';
					s[strchr(s,'E')-s]='a';
					ans[sp++]='1';
				}
				break;
			}
			default:break;
		}
		i=0;
	}
}

int main(){
	int t;scanf("%d",&t);
	for(int i=0;i<15;i++){
		find[table[i]]=i;
	}
	for(int m=0;m<t;m++){
		char s[30];scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp1);
		solve(s);
		qsort(ans,sp,sizeof(s[0]),cmp);
		printf("case #%d:\n",m);
		for(int i=0;i<sp;i++){
			printf("%c",ans[i]);
			
		}
		sp=0;printf("\n");
	} 
	return 0;
}