#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(int x,int y){
    int i,res[15]={0};
    for(i=p-1;i>=0;i--)
    {
        if(x==0) break;
        res[i]=x%2;
        x/=2;
    }
    for(i=0;i<p;i++)
    {
        printf("%d",res[i]);
    }
} 
int main(){
	char str[600];
	scanf("%s",str);
	printf("0001");
	solve(strlen(str),10);
	int i=0,temp;
	while(strlen(str)-i>=3){
		temp=(str[i]-'0')*100+(str[i+1]-'0')*10+(str[i+2]);
		solve(temp,10);
		i+=3;
	}
	if(strlen(str)-i==2)
    {
        int tmp=(str[i]-'0')*10+(str[i+1]-'0');
        solve(tmp,7);
    }
    else if (strlen(str)-i==1)
    {
        int tmp=(str[i]-'0');
        solve(tmp,4);
    }
    return 0;
}