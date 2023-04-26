#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	char a[5],b[5],c[5],ans[10];
	scanf("%s%s%s",a,b,c);
	int na=strlen(a),nb=strlen(b),nc=strlen(c);
	if((a[0]=='O'&&b[0]=='O')||(a[0]=='O'&&c[0]=='O')||(b[0]=='O'&&c[0]=='O'))strcpy(ans,"{O}");
	else if(a[0]=='A'&&b[0]=='A')strcpy(ans,"{A,O}");
	else if((a[0]=='A'&&b[0]=='B')||(a[0]=='B'&&b[0]=='A'))strcpy(ans,"{A,AB,B,O}");
	else if(a[0]=='B'&&b[0]=='B')strcpy(ans,"{B,O}");
	else if(na==2&&nb==2)strcpy(ans,"{A,AB,B}");
	else if((a[0]=='A'&&nb==2)||(na==2&&b[0]=='A'))strcpy(ans,"{A,AB,B}");
	else if((a[0]=='B'&&nb==2)||(na==2&&b[0]=='B'))strcpy(ans,"{A,AB,B}");
	else if((a[0]=='B'&&c[0]=='B')||(b[0]=='B'&&c[0]=='B'))strcpy(ans,"{A,AB,B,O}");
	else if(nc==2&&(na==2||nb==2))strcpy(ans,"{A,AB,B}");
	else if(nc==2&&(a[0]=='A'||b[0]=='A'))strcpy(ans,"{AB,B}");
	else if(c[0]=='A'&&(na==2||nb==2))strcpy(ans,"{A,AB,O}");
	else if(c[0]=='B'&&(na==2||nb==2))strcpy(ans,"{A,AB,B,O}");
	else if(nc==2&&(a[0]=='B'||b[0]=='B'))strcpy(ans,"{A,AB}");
	else if((a[0]=='A'&&b[0]=='O')||(a[0]=='O'&&b[0]=='A'))strcpy(ans,"{A,O}");
	else if((a[0]=='B'&&b[0]=='O')||(a[0]=='O'&&b[0]=='A'))strcpy(ans,"{B,O}");
	else if((na==2&&b[0]=='O')||(a[0]=='O'&&nb==2))strcpy(ans,"{A,B}");
	else if(c[0]=='O'&&(a[0]=='A'||b[0]=='A'||a[0]=='B'||b[0]=='B'))strcpy(ans,"{A,B,O}");
	else if(c[0]=='A'&&(a[0]=='O'||b[0]=='O'))strcpy(ans,"{A,AB}");
	else if(c[0]=='B'&&(a[0]=='O'||b[0]=='O'))strcpy(ans,"{AB,B}");
	else strcpy(ans,"impossible");
	if(a[0]=='?')printf("%s ",ans);else printf("%s ",a);
	if(b[0]=='?')printf("%s ",ans);else printf("%s ",b);
	if(c[0]=='?')printf("%s ",ans);else printf("%s ",c);
	return 0;
}