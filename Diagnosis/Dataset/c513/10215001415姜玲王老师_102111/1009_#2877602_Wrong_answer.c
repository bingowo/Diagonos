int gcd(int a,int b)
{int c;
    while(a%b)
{c=a%b;
a=b;
b=c;
}
return b;
}
void number(char *p)
{int c,d=0,i,k,m;
 char a;
c=strlen(p)*8;
for(i=0;i<strlen(p);i++)
{a=p[i];
    while(a!=0)
{if(a%2!=0) d++;
a=a/2;}}
m=gcd(d,c);
c=c/m;
d=d/m;
printf("%d/%d\n",d,c);}
int main()
{int n,i;
scanf("%d",&n);
getchar();
for(i=0;i<n;i++)
{char a;
char str[121]={"\0"};
int l=0;
while((a=getchar())!='\n')
{str[l++]=a;}
number(str);
}
}