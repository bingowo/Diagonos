#include<stdio.h>
#include<string.h>
void solve(char s[],int m){
	int p=0;
	int temp=0;
	char c;
	int length=strlen(s);
	while(p<length||temp!=0){
		if(p==length){s[p]=temp+'0';c='0';temp=0;}
		else {c=s[p];s[p]=((s[p]-'0')*m+temp)%10+'0';temp=((c-'0')*m+temp)/10;}
		p++;
	}
	s[p]='\0';
}
int main(){
	char s[110];
	int chance;
	scanf("%d",&chance);
	int i,j;
	for(i=0;i<chance;i++){
		int m,n;
		printf("case #%d:\n",i);
		scanf("%d%d",&m,&n);  //m表示底数，n表示幂
		if(n==0) printf("1\n");
		else{
			s[0]=m+'0';
			for(j=1;j<n;j++){
				solve(s,m);
			}
		    for(j=0;j<strlen(s);j++){
		    	printf("%c",s[strlen(s)-1-j]);
			}
			printf("\n");	
		} 
	}
} 