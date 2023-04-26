#include<stdio.h>
#include<stdlib.h>
#define N 1000
int main()
void solve(){
{	int n,i,j=0;
	scanf("%d",&n);
	int s[N];
	for(i=0;n/2!=0;i++){
		s[i]=n%2;
		n=n/2;
	}
    int t;
    for(j=0;j<i;j++,i--){
    	t=s[i];
    	s[i]=s[j];
    	s[j]=t;
	}
    int *p=s;
	int cnt=0;
	while(*p!=*p++){
		cnt++;
	}
	printf("%d\n",cnt);

}

int main()
{
	int t,T;
	int i;
	T=t;
	scanf("%d\n",&t);
	for(;t>0;t--){
	  for(i=0;i<T;i++){
    	printf("case #%d:",i);
    	solve();}
	}
	return 0;
 } 