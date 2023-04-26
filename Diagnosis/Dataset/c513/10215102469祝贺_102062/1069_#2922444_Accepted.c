#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s1[10000];int sp1=0;
char s2[10000];int sp2=0;

int main()
{	
	scanf("%s",s1);sp1=strlen(s1);
	int cnt=0;int tag=1;
	while(tag!=0){
		int carry=0;tag=0;
		if(cnt%2==1){
			for(int i=0;i<sp2;i++){
				int t=s2[i]+s2[sp2-i-1]+carry-'0'-'0';
				carry=t/10;
				s1[sp1++]=t%10+'0';
				if(carry!=0)tag=1;
			}
			while(carry!=0){
				s1[sp1++]=carry%10+'0';
				carry/=10;
			}sp2=0;
			if(tag!=1)tag=0;
		}
		if(cnt%2==0){
			for(int i=0;i<sp1;i++){
				int t=s1[i]+s1[sp1-i-1]+carry-'0'-'0';
				carry=t/10;
				s2[sp2++]=t%10+'0';
				if(carry!=0)tag=1;
			}
			
			while(carry!=0){
				s2[sp2++]=carry%10+'0';
				carry/=10;
			}sp1=0;
			if(tag!=1)tag=0;
		}
		cnt++;
	}
	printf("%d ",cnt);
	s1[sp1]=0;s2[sp2]=0;
	if(cnt%2==0)printf("%s",s1);
	else printf("%s",s2);
	return 0;
}