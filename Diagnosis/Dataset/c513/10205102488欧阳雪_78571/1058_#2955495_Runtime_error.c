#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[1000][1000]={0};
	int t1=0,t2=0;
	char temp[1000]={0};
	char c;
	int k=0;
	while(scanf("%s",temp)!=EOF)
	{
		//strcpy(s[t1],temp);
		for(int m=0;m<strlen(temp);m++)
		{
			s[t1][k++]=temp[m];
		}
	//	printf("test:%d ",t1);
		//puts(s[t1]);
		c=getchar();
		while(c!='\n')
		{
			s[t1][k++]=c;
			c=getchar();
		}
	    if(c=='\n')
		{
			t1++;
			k=0;
		}
	}
	//printf("t1:%d\n",t1);
/*	for(int n=0;n<t1;n++)
	{
		puts(s[n]);
	}*/
	t2=0;
	for(int i=0;i<t1;i++)
	{
		int flg=0;
		while(s[i][t2])
		{
			if(s[i][t2]=='"')
			{
				flg++;
				//t2++;
			}
			if(s[i][t2]=='/'&&s[i][t2+1]=='/' )//说明//没在""内 
			{
				if(flg%2!=0)
				{
					while(s[i][t2]!='\0')
					{
						printf("%c",s[i][t2]);
						t2++;
					}
				   if(s[i][t2]=='\0')
				   {
				   	i++;
				   	printf("\n");
				   	t2=0;
				   }
				}
				else{
				i++; 
				printf("\n");
				t2=0;
				}
			}
			
			if(s[i][t2]=='/'&&s[i][t2+1]=='*')
			{
				t2+=2;
				//printf("t2:%d\n",t2);
				while(s[i][t2]!='*')
				{
					if(s[i][t2]=='\0')//到下一行 
					{
						i++;
						t2=0;
						continue;
					}
					//printf("%c",s[i][t2]);
					t2++;
				}
				if(s[i][t2]=='*'&&s[i][t2+1]=='/')
				{
					t2+=2;
				}
				
			}
			if(s[i][t2]=='\n'){
				i++;
				t2=0;
			}
			printf("%c",s[i][t2]);
			t2++;
		}
	}
}