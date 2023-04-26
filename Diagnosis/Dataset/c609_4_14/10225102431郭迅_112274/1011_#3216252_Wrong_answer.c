#include<stdio.h>
#include<math.h>
#include<string.h> 
int main()
{
	char s[30];
	scanf("%s",s);
	int l=strlen(s);
	int i=0,c=0,j;
	if(strchr(s,'.')==0)j=l;
	else {
		for(i=0;i<l;i++){
			if(s[i]=='.'){j=i;break;
			}
		}
	}
	double d=0;
	for(i=0;i<j;i++){
		if(s[i]=='2'){c-=pow(3,j-1-i);printf("%d ",c);
		}
		else if(s[i]=='1'){c+=pow(3,j-1-i); printf("%d ",c);
		}
	}
	for(i=j+1;i<l;i++){
		if(s[i]=='2'){d-=pow(3,j-i);
		}
		else if(s[i]=='1'){d+=pow(3,j-i); 
		}
	}
	if(d!=0)
	printf("%d %f",(int)(c+d),d);
	else printf("%d",c);
}