#include<stdio.h>
#include<math.h>
#include<string.h>
char* solve(long long x,long long y,char s[]){
	int p=0;
	while(x!=0&&y!=0){
		if(x%2==0){       //x为偶数时，需要在y上做加减 
			if((x/2-(y+1)/2)%2==0){y=(y-1)/2;x/=2;s[p++]='N';}
			else {y=(y+1)/2;x/=2;s[p++]='S';}
		}
		else{            //y为偶数时，需要在x上做加减 
			if(((x+1)/2-y/2)%2==0){x=(x-1)/2;y/=2;s[p++]='E';}
			else{x=(x+1)/2;y/=2;s[p++]='W';}
		}
	}
	while(x!=0){
		if(x==1){
			x-=1;
			s[p++]='E';
		}
		else if(x==-1){
			x+=1;
			s[p++]='W';
		}
		else{
			if(((x+1)/2)%2==0){
				s[p++]='W';
				x=(x-1)/2;
			}
			else{
				s[p++]='E';
				x=(x+1)/2;
			}
		}
	}
	while(y!=0){
		if(y==1){
			y-=1;
			s[p++]='N';
		}
		else if(y==-1){
			y+=1;
			s[p++]='S';
		}
		else{
			if(((y+1)/2)%2==0){
				s[p++]='N';
				y=(y-1)/2;
			}
			else{
				s[p++]='S';
				y=(y+1)/2;
			}
		}
	}
	s[p]='\0';
	return s;	
}
int main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if((x+y)%2==0){
		if(x==0&&y==0) printf("0");
		else printf("-1");
	}
	else{
		int count=0,i;
		long long temp=(x>y)?x:y;
		temp=(temp>fabs(x)+fabs(y))?temp:fabs(x)+fabs(y);
		while(temp!=0){
			count++;
			temp/=2;
		}
		char s[45];
		solve(x,y,s);
		printf("%d\n",count);
		for(i=0;i<strlen(s);i++){
			printf("%c",s[i]);
		}
	}
}