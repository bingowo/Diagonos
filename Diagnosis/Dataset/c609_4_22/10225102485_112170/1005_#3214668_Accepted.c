#include<stdio.h>
#include<math.h>
int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++){
        char s[100];
        scanf("%s",s);
        int ans=0,pos=0;
        while(s[pos]!=0){
            if(s[pos]=='-')ans=ans*3-1;
            else ans=ans*3+s[pos]-'0';
            pos++;
        }
        printf("case #%d:\n%d\n",j,ans);
	}
	return 0;
}
