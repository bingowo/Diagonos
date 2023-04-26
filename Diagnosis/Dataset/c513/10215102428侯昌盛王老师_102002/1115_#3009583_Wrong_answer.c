#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	char p=*(char*)a;
	char q=*(char*)b;
	if(p<=q) return -1;
	else return 1;
}
int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		char s[22],s2[22];
		scanf("%s",s);
		int len,i,j;
		len=strlen(s)-1;
		for(i=len;i>0;i--)
		{
			//printf("h\n");
			if(s[i]>s[i-1])
			{
				//printf("h\n");
				int k=i,r=0,p;
				char min='9';
				for(k;k<=len;k++)
				{
					if(s[k]>s[i-1]&&s[k]<min)
					{
						min=s[k]; 
						p=k;
					}
					
				}
				//printf("%c\n",min);
				for(k=i-1;k<=len;k++)
				{
					if(k==p) continue;
					s2[r++]=s[k];
				}
				s2[r]='\0';
				//printf("%s\n",s2);
				
				qsort(s2,r,sizeof(s2[0]),cmp);
				
				s[i-1]=min;
				for(k=i;k<=len;k++) s[k]='\0';
				//printf("%s\n",s);
				strcat(s,s2);
				goto ans;
			}
			
		}
		len++;
		s[len]='0';
		s[len+1]='\0';
		len+=1;
		//printf("h\n");
		qsort(s,len,sizeof(s[0]),cmp);
	
		char m;
		int te=0;
		for(te;s[te]=='0';te++);
		m=s[te];
		s[te]=s[0];
		s[0]=m;
		ans:
			printf("case #%d:\n",e);
			printf("%s\n",s);
		
	}
	return 0;
}