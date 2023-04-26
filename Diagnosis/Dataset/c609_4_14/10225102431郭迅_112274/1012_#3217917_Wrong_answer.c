#include<stdio.h>
#include<math.h>
#include<string.h> 
int main()
{
	int t;scanf("%d",&t);
	char s[t][60];
    for(int i=0;i<t;i++){
    	scanf("%s",s[i]);}
    for(int i=0;i<t;i++){
    	double c=0;
    	int l=strlen(s[i])-2;
    	for(int j=2;j<l+2;j++){
    		if(s[i][j]!='0'){
    		c+=(s[i][j]-48)*pow(8,1-j);
		}
		}
		int m=3*l;
		printf("case #%d:\n",i);
		printf("%.mf\n",c);
}}