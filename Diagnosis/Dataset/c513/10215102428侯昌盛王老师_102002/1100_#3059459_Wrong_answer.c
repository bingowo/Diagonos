#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char s[101];
	scanf("%s",s);
	int a[27]={0};
	int i;
	for(i=0;i<strlen(s);i++)
	{
		a[s[i]]++;
	}
	int x0=0,y0=0;
	x0+=a['R'];x0-=a['L'];
	y0+=a['U'];y0-=a['D'];
	//printf("ll=%d %d\n",x0,y0);
	int q,e;
	scanf("%d",&q);
	for(e=0;e<q;e++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		//printf("h=%d\n",y*y0);
		if(x*x0<0||y*y0<0) printf("No\n");
		else if(x0==0&&y0==0) printf("Yes\n");
		else if(x0==0&&(y0!=0)&&y%y0==0) printf("Yes\n");
		else if(y0==0&&(x0!=0)&&x%x0==0) printf("Yes\n");
		else if(x%x0==0&&y%y0==0&&x/x0==y/y0) printf("Yes\n");
 		else printf("No\n");
	}
	return 0;
}