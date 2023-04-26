#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void itob(int n,char*p)
{
	do{ (*p--)=(n%2==1)?'1':'0';
	}
	while(n/=2);
}
int main()
{
	char s[501];
	scanf("%s",s);
	//printf("%d",s[2][0]);
	int n;
    for(int i=0;i<501;i++)
    {
        if(s[i]==0)
		{n=i;break;} 
	}
	//printf("%d\n",n);

	
	int thr[n/3+(n%3==0)?0:1];//每3个数一分组 
	int zushu=(n%3==0)?0:1+n/3;	
	//printf("\n%d\n",zushu);
	for(int i=0,c=0;c<zushu;i+=3,c++)
	{
		char temp[3];
		if(c!=zushu-1||(n%3==0))
		{temp[0]=s[i];temp[1]=s[i+1];temp[2]=s[i+2];
		thr[c]=atoi(temp);}
		else if(c==zushu-1&&(n%3==1))
		{char temp1[1];temp1[0]=s[i];thr[c]=atoi(temp1);}
		else if(c==zushu-1&&(n%3==2))
		{char temp2[2];temp2[0]=s[i];temp2[1]=s[i+1];thr[c]=atoi(temp2);}
	//	printf("%d\n",thr[c]);//行指针，求3个数转换成int10进制 
	}
	
	int k;//result数组的长度 
	if(n%3==0) {k=4+10+n/3*10;}
	else if(n%3==1) {k=4+10+n/3*10+4;}
	else  {k=4+10+n/3*10+7;}
	char res[k];
	//printf("\n%d\n",k);
	
	//memset(a, -1, 123 * sizeof(int));
	//memset(res,4,k*sizeof(int));//res全置0 ,char res[k]好像置不了0 
	for(int i=0;i<k;i++)
	{
		res[i]='0'; 
	} 
	//printf("%d\n%d\n%d",res[0],res[1],res[2]);
	res[3]='1';//前四个为0001 
//	printf("%c %c %c %c",res[0],res[1],res[2],res[3]);
	char*p0,*p1;
	p0=res+13;p1=res+13;
	//指针用于向res输入n的10bits二进制 和 每三位的10bits二进制 
	itob(n,p1);
	/*for(int i=0;i<14;i++)
	{printf("%c",res[i]);
	}*/
	//char* kk=p0;
	int j;
	for(j=0;j<n/3;j++)
	{
		p1=p0;
	    p0=p0+10;p1=p1+10;
		itob(thr[j],p1);
	}
	if(n%3==1) {
		p1=p0;
		p0=p0+4;p1=p1+4;
		itob(thr[j],p1);
	}
	if(n%3==2) {
		p1=p0;
		p0=p0+7;p1=p1+7;
		itob(thr[j],p1);
	}
	//printf("\n%d\n",p0-kk);
	for(int i=0;i<k;i++)
	printf("%c",res[i]);
	return 0;
}