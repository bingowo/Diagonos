#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	char s[t][32];
	int i,m;
	for(i=0;i<t;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<t;i++){
		int n=0;
	m=strlen(s[i])-1;
	int j;
	for(j=0;j<=m;j++){
		if(s[i][j]=='0'){n+=0;
		}
		else if(s[i][j]=='-'){n-=pow(3,m-j);
		}
		else{n+=pow(3,m-j);
		}
	}
	printf("case #%d:\n%d\n",i,n);
}
	
}