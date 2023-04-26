#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int a1,a2,c1,c2;
int a,b,c;
char s[50];
	
void read(char*s);
int main ()
{
	int temp;
	scanf("%s",s);
	read(s);
//	printf("%d %d %d\n",a,b,c);
	if (c != 0)
	{
		for (int i = 1,n = 0; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			a1 = i; a2 = a/i;
		}
		if (c > 0&& b > 0)
		{
			for (int i = 1,n = 0; i<=sqrt(c); i++)
			{
				if (c%i == 0)
				{
				c1 = i; c2 = c/i;
				}
				if (a1*c2+a2*c1 == b)
				{
					if (a1 == a2 && c1 > c2)
					temp = c1, c1 = c2, c2 = temp;
					printf("%d %d %d %d",a1,c1,a2,c2);
					return 0;
				}
			}
		}
		else if (c > 0 && b < 0)
		{
			for (int i = 1,n = 0; i<=c; i++)
			{
				if (c%i == 0)
				{
				c1 = -i; c2 = -c/i;
				}
				if (a1*c2+a2*c1 == b)
				{
					if (a1 == a2 && c1 > c2)
					temp = c1, c1 = c2, c2 = temp;
					printf("%d %d %d %d",a1,c1,a2,c2);
					return 0;
				}
			}
		}
		else if (c < 0 && b > 0)
		{
			for (int i = 1,n = 0; i<=abs(c); i++)
			{
				if (c%i == 0)
				{
				c1 = -i; c2 = c/-i;
				}
				if (a1*c2+a2*c1 == b)
				{
					if (a1 == a2 && c1 > c2)
					temp = c1, c1 = c2, c2 = temp;
					printf("%d %d %d %d",a1,c1,a2,c2);
					return 0;
				}
			}
		}
		else
		{
			for (int i = 1,n = 0; i<=abs(c); i++)
			{
				if (c%i == 0)
				{
				c1 = -i; c2 = c/-i;
				}
				if (a1*c2+a2*c1 == b)
				{
					if (a1 == a2 && c1 > c2)
					temp = c1, c1 = c2, c2 = temp;
					printf("%d %d %d %d",a1,c1,a2,c2);
					return 0;
				}
			}
			for (int i = 1,n = 0; i<=abs(c); i++)
			{
				if (c%i == 0)
				{
				c1 = i; c2 = c/i;
				}
				if (a1*c2+a2*c1 == b)
				{
					if (a1 == a2 && c1 > c2)
					temp = c1, c1 = c2, c2 = temp;
					printf("%d %d %d %d",a1,c1,a2,c2);
					return 0;
				}
			}
		}
	}
	}
	else
	{
		a1 = 1; a2 = a; c1 = 0; c2 = b;
		if (a1 == a2 && c1 > c2)
		temp = c1, c1 = c2, c2 = temp;
		printf("%d %d %d %d",a1,c1,a2,c2);
		return 0;
	}
	printf("No Answer!");
	return 0;
}
void read(char*s){
	
	int i=0,len=strlen(s),flag=1;
	if(s[0]=='x') {
		a=1;
		i++;
	}
	else if(s[0]=='-'&&s[1]=='x'){
		a==-1;
		i++;
	}
	else {
	if(s[0]=='-'&&isdigit(s[1])) flag=-1;
	for(;i<len&&isdigit(s[i]);i++)
{
    	a=a*10+s[i]-'0';
} a*=flag;
	}
	 flag=1;
    while(s[i]!='+'&&s[i]!='-') i++;
    if(s[i]=='-') flag=-1;
    i++;
    if (s[i] == 'x')
    b = 1;
    for(;i<len&&isdigit(s[i]);i++){

	 b=b*10+s[i]-'0';
    }b*=flag;
   if(i==len) {
    	c=b;
    	b=0;
   }
   
	else{
		flag=1;
		while(s[i]!='+'&&s[i]!='-') i++;
    if(s[i]=='-') flag=-1;
    i++;
    for(;i<len&&isdigit(s[i]);i++){

	 c=c*10+s[i]-'0';
    }c*=flag;	
	}
}