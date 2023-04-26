#include <stdio.h>
#include <string.h>
using namespace std;
char s[100];
int cal(int l,int r){
	//printf("%d %d\n",l,r);
	if(l+1==r){
		return 1;
	}
	int sum = 0;
	int zt = 0,p1 = l,p2 = l;
	if(s[l]=='(') zt = 1;
	else zt = -1;
	while(p2<=r){
		if(zt==0){
			if(p1+1==p2){
				sum += 1;
			}
			else sum += 2*(cal(p1+1,p2-1));
			p2++;
			p1 = p2;
			if(s[p1]=='(') zt = 1;
			else zt = -1;
		}
		else{
			p2++;
			if(s[p2]=='(') zt++;
			else zt--;
		}
	}
	return sum;
}
int main(void)
{
	scanf("%s",s);
	//printf("%d",strlen(s)-1);
	int res = cal(0,strlen(s)-1);
	printf("%d",res);
	return 0;
}