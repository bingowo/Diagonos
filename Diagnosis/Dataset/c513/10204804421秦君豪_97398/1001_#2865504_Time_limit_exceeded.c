#include <stdio.h>
#include<stdlib.h> 
#include<string.h>
void itob(int n,char *p,int b)
{
	int j;
	char a,temp;
	int i = 0;
	int flag = 0;
	if (n<0){
		n=-1*n;
		flag =1;
	}
    for (i;i<=99;i++)
    {
    	j=n%b;
    	n = n/b;
    	if (j>=10) a='A'+(j-10);
    	else a ='0'+j;
    	*(p+i)=a;
    	if (n==0) break;
	}
	if(flag) 
	{
	*(p+i+1)='-';
	i++;
	}
	*(p+i+1)='\0';
	for(i=strlen(p)-1,j=0;j<i;j++,i--){
		temp=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=temp;
	}

}


int main()
{ 
	long long int T,N,i,R;
	char s[1000];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		char *p;
		p=s;
		scanf("%lld%lld",&N,&R);
		itob(N,p,R);
		printf("%s\n",s);
	} 
	 
     return 0;
}
