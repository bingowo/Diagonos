#include<stdio.h>
#include<string.h>
void itob(int n,char s[1000],int b)
{
    int r;int m;
    m=n;
    int i;int j=0;
    i=0;
    char c1;
    if(n<0) n=-1*n;
    while(n!=0){
        r=n%b;
        if(r<=9)
           c1=r+48;
        if(r>9)
           c1=r+55;
        n=n/b;
        s[i]=c1;
        i=i+1;
        } 
    if(m<0){s[i]='-';s[++i]='\0';}
    else s[i]='\0';
    char t[100];
    n=strlen(s);
    for(i=n-1;i>=0;i--) t[j++]=s[i];
    for(i=0;i<n;i++) s[i]=t[i];
    s[++i]='\0';
}
int main(){
	int T;
	scanf("%d",&T);
	int i,j;
	int n,r;
	for(i=0;i<T;i++){
		char c1;
		int res;
		int k=0;
		long long int sum=0;
		char sumchar;
		scanf("%d %d",&n,&r);
    	while(n!=0){    		
        	res=n%r;
        	n=n/r;
        	sum+=res;
        	k=k+1;
        }
		printf("case #%d:\n", i);
		char s1[1000];
		itob(sum,s1,r);
		printf("%s\n",s1);
		
	}
}