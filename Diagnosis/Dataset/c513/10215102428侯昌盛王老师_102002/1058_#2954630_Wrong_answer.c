#include <stdio.h>
#include <string.h>

int main()
{
	char s[100][100];
	int n=0;
	int c;
	while((c=getchar())!=EOF){
		char s2[100]={'0'};
		s2[0]=c;
		int len=strlen(s2);
		s2[len]='\0';
		gets(s[n]);
		strcat(s2,s[n]);
		strcpy(s[n],s2);
		n++;
	}
	
//	printf("%s",s[0]);
	int i=0,j=0;
	for(i;i<n;i++)
	{
		while(s[i][j]!='\0'){
		
			if(s[i][j]=='/'&&s[i][j+1]=='/'&&s[i][j-1]!='\"')
			{
				while(s[i][j]!='\0')
				{
					s[i][j]=' ';
					j++;
			//	printf("%d\n",j);
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
		j=0;
	
		
	}
	//printf("%d\n",j);
	int u=0;
	for(u;u<n;u++) printf("%s\n",s[u]);
	return 0;
}