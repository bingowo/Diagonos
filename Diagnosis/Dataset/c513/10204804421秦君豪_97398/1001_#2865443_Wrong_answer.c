#include <stdio.h>
#include<string.h>
void itob(int n,char *p,int b)
{
	int j;
	char a,temp;
	int i = 0;
	int flag = 0;
	if (n<0){  //ÅÐ¶ÏnÊÇ·ñÎª¸ºÊý£¬Îª¸ºflag¸³ÖµÎª1 
		n=-1*n;
		flag =1;
	}
    for (i;i<=99;i++)//Ê®½øÖÆ×ªÆäËû½øÖÆ 
    {
    	j=n%b;
    	n = n/b;
    	if (j>=10) a='A'+(j-10);
    	else a ='0'+j;
    	*(p+i)=a;
    	if (n==0) break;
	}
	if(flag) {
	*(p+i+1)='-';
	i++;
	}//Èç¹ûÎª¸ºÊý£¬ÔòÔÚÊý×éÄ©Î²¼Ó¸ö- 
	*(p+i+1)='\0';
	for(i=strlen(p)-1,j=0;j<i;j++,i--){//µßµ¹Êý×é 
		temp=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=temp;
	}

}

int main()
{
    long long int n,b;
    char s[100];
    char *p;
    p=s;
    scanf("%lld%lld",&n,&b);
    itob(n,p,b);
    printf("%s\n",s);
    
    return 0;
}