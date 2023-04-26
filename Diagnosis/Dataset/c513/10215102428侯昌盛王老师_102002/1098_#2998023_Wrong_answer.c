#include <stdio.h>
#include <string.h>
int main()
{
	int t,w;
	scanf("%d",&t);
	for(w=0;w<t;w++)
	{
		char s[101];
		int r[100];
		scanf("%s",s);
		memset(r,0,sizeof(r));
		int len=strlen(s),i;
		int num=len/4;
		if(len%4==0)
		{
			
			for(i=0;i<len;i++) r[s[i]]++;
			goto ans;
		}
		for(i=0;i<len;i++)
		{
			int n=4;
			if(s[i]=='!')
			{
				while(i+n<len){
					if(s[i+n]!='!') {r[s[i+n]]++;break;}
					else n+=4;
				}
				int k=n;
				n=4;
				while(i+n>=len||i+k>=len) {
					if(s[i-n]!='!') {r[s[i-n]]++;break;}
					else n+=4;
				}
			}
			
		}
		printf("case #%d:\n",w);
		ans:
			if(len%4==0) printf("%d %d %d %d\n",num-r['R'],num-r['B'],num-r['Y'],num-r['G']);
			else printf("%d %d %d %d\n",r['R'],r['B'],r['Y'],r['G']);
		
	}
	return 0;
}