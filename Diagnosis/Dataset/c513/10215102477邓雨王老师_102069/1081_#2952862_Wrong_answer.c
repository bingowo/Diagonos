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
void reverse(char s[]){
	int i,j;
	char c;
	for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
          c=s[i],s[i]=s[j],s[j]=c;
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i,j;
	for(i=0;i<chance;i++){
		int m,n;
		scanf("%d%d",&m,&n);  //m表示底数，n表示幂
		printf("case #%d:\n",i);
		if(n==0) printf("1\n");
		else{
			char s[1100];
			s[0]=m+'0';
			for(j=1;j<n;j++){
				solve(s,m);
			}
		    reverse(s);
			printf("%s",s);
			printf("\n");	
		} 
	}
} 