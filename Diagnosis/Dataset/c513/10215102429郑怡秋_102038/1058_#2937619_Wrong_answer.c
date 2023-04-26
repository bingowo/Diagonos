#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
    char ans[10001];int ii=0;
    char c;
    int s=0,a=0,b=0,i=0;
    while((c=getchar())!=EOF)
    {
        if(c=='"'&&b==0&&a==0) a++;
		else if(c=='"'&&b==0&&a>0) a--;
		else if(b>0) b--;
		else if(c=='\\') b++;
		  
		if(c=='/'&&a==0&&s==0) s=1;
		else if(s==1&&c=='*') s=2;
		else if(s==1&&c=='/') s=3;
		else if(s==3&&c=='\n') {s=0;ans[0]='\0';}
		else if(s==2&&c=='*') s=4;
		else if(s==4&&c=='/') {s=0;ans[0]='\0';continue;}
		else if(s==4&&c=='\n') s=2;
		if(s==0) printf("%c",c);
		else ans[ii++]=c;
    }
	
	return 0;
}