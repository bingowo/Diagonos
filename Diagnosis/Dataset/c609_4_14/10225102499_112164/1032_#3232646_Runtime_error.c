#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a>b?a:b;
}

int solve(char* s){
	char *p;
	if(!*p)return 0;
	while(*(p+1)&&*p!=*(p+1))p++;
	return max(p+1-s,solve(p+1));
}

int main()
{
    char s[50]={0};
    int i=0,max=1,n=1;
    fgets(s,sizeof(s),stdin);
    if(s[strlen(s)-1]=='\n')s[strlen(s)-1]=0;
//    for(i=0;s[i+1]!=0;i++){
//        while(s[i]!=s[i+1]&&s[i+1]!=0)i++,n++;
//        max=max>n?max:n;
//        n=1;
//    }
    printf("%d",solve(s));
    return 0;
}
