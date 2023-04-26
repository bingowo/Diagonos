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
			
			for(j=i-1;j>=0;j--)
			{
				if(s[i]>s[j])
				{
				//	printf("h\n");
					int k=j,r=0;
					for(k;k<i;k++)
					{
						s2[r++]=s[k];
					}
					s2[r]='\0';
					//printf("%s\n",s2);
				//	printf("%d\n",i);
					int k2=i;
					for(k2;k2<=len;k2++)
					{
						s[j++]=s[k2];
					}
					int w=j;
					for(w;w<=len;w++) s[w]='\0';
					
					strcat(s,s2);
					goto ans;
				}
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