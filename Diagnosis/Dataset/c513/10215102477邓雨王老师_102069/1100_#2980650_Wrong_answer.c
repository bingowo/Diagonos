#include<stdio.h>
#include<string.h>
int solve(char s[],int a,int b){
	int x=0,y=0,x1=0,y1=0; //x,y代表总共的值，x1,y1代表部分的值 
	int i,j;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='U') y++;
		else if(s[i]=='D') y--;
		else if(s[i]=='L') x--;
		else x++;
    }
	if(a==0&&b==0) return 1;
	for(i=0;i<strlen(s);i++){
		for(j=0;j<=i;j++){
			if(s[j]=='U') y1++;
		    else if(s[j]=='D') y1--;
		    else if(s[j]=='L') x1--;
		    else x1++;
	    }
	    int x2=a,y2=b;
	    if(x==0||y==0){
	    	if(x==0&&y!=0&&(y2-y1)%y==0&&(y2-y1)/y>=0) return 1;
	    	else if(y==0&&x!=0&&(x2-x1)%x==0&&(x2-x1)/x>=0) return 1;
	    	else{
	    		if(x2-x1==0&&y2-y1==0) return 1;
			}
		}
		else{
			if((x2-x1)%x==0&&(y2-y1)%y==0/*&&(y2-y1)/y>=0&&(x2-x1)/x>=0*/&&(y2-y1)/y==(x2-x1)/x) return 1; 
		}
		x1=0,y1=0;  
	}
	return -1; 
}
int main(){
	char s[101];
	scanf("%s",&s);
	int chance;
	scanf("%d",&chance);
	int i;
	long long a,b;
	for(i=0;i<chance;i++){
		scanf("%lld %lld",&a,&b);
		if(solve(s,a,b)==1) printf("Yes\n");
		else printf("No\n");
	}
}
