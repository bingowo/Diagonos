#include <stdio.h>


int main()
{
	char s[100][100];
	int n=0,c=0;
	while((c=getchar())!=EOF) gets(s[n++]);
//	printf("%s",s[0]);
	int i=0,j=0;
	for(i;i<n;i++)
	{
		while(s[i][j]!='\n'){
		
			if(s[i][j]=='/'&&s[i][j+1]=='/')
		{
			while(s[i][j]!='\n')
			{
				s[i][j]=' ';
				j++;
			}
		}
		else if(s[i][j]=='/'&&s[i][j+1]=='*')
		{
			int k=j;
            j=j+2;
            while(!(s[i][j]=='*'&&s[i][j+1]=='/')) j++;
            int m=k;;
            for(m;m<=j+1;m++) s[i][m]=' ';
		}
		else j++;
		
		}
	
		
	}
	int u=0;
	for(u;u<n;u++) printf("%s\n",s[u]);
	return 0;
}