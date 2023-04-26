#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
#define F 65536
int stx(char x)
{
	if(isalpha(x)) return x-'A';
	else return x-'0';
}

int main()
{
	char s[1000];
	int hour=0,minute=0,second=0;
	while(scanf("%s",s)!=0&&strcmp(s,"END")!=0)
	{
		if(strncmp(s,"$GPRMC",6)==0)
		{
			int bz=0;
			int i=strlen(s)-1;
			bz=stx(s[i--]);
			while(s[i]!='*') bz=bz+stx(s[i--])*16;
			int tump=s[1];
			for(int j=2;j<i;j++)
			{
				tump=tump^s[j];
			}printf("%d %d\n",tump%F,bz);
			if(tump%F==bz)
			{
				int m,k=0;
				while(s[k]!=',') k++;
				m=k+1;
				while(s[m]!=','&&s[m]!='*') m++;
				if(s[m+1]=='A')
				{
					hour=((s[++k]-'0')*10+s[++k]-'0'+8)%24;
					minute=(s[++k]-'0')*10+s[++k]-'0';
					second=(s[++k]-'0')*10+s[++k]-'0';
				}
			}
			
		}
	}
	printf("%02d:%02d:%02d",hour,minute,second);
	return 0;
}