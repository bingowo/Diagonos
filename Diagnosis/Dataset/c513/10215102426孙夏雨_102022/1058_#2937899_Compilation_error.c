#include <stdlib.h>
#include <stdio.h>

int main()
{
	char c;int s=0,a=0,b=0;
	while((c=getchar())!=EOF)
	{
		if(c=='"'&&b==0&&a==0) a++;
		else if(c=='"'&&b==0&&a>0) a--;
		else if(b>0) b--;
		else if(c=='\\') b++;

		if(c=='/'&&a==0&&s==0) s=1;
		else if(s==1&&c=='*') s=2;
		else if(s==1&&c=='/') s=3;
		else if(s==3&&c=='\n') s=0;
		else if(s==2&&c=='*') s=4;
		else if(s==4&&c=='/') s=0;continue;
		else if(s==4&&c=='\n') s=2;
		else if(s==1) s=0,printf("/");
		if(s==0) printf("%c",c);
	}
	return 0;
}
