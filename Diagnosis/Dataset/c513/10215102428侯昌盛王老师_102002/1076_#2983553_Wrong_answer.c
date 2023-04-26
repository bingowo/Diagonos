#include <stdio.h>
#include <string.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[101],s2[101];
		scanf("%s",str);
		int len=strlen(str),j,k=1;
		s2[0]='1';
		s2[k]=str[0];
		for(j=1;j<len;j++)
		{
			switch(str[j])
			{
				case '(':{
					if(s2[k]=='['||k==0){s2[k+1]=str[j];k++;}
					else goto ans;
					break;
				}
				case ')':{
					if(s2[k]=='(') k--;
					else goto ans;
					break;
				}
				case '[':{
					if(s2[k]=='{'||k==0){s2[k+1]=str[j];k++;}
					else goto ans;
					break;
				}
				case ']':{
					if(s2[k]=='[') k--;
					else goto ans;
					break;
				}
				case '{':{
					if(s2[k]=='('||k==0) {s2[k+1]=str[j];k++;}
					else goto ans;
					break;
				}
				case '}':{
					if(s2[k]=='{') k--;
					else goto ans;
					break;
				}
				
				
			}
			
				
				
		}

		ans:
			if(j==len) printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}