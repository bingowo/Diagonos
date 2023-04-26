#include <stdio.h>
#include <stdlib.h>
int GCD(int m,int n)
{
    int max,min;
    if(m<n){min=m,max=n;}
    else{min=n,max=m;}
    int res;
    res=max%min,max=min,min=res;
    int out=1;
    out=(res==0)?max:GCD(min,max);
    return out;
}

int main()
{
	char a[100];
	int i;
	long long int resa=0;
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='.')break;
		else
		{
			if(a[i]=='2')resa=resa*3-1;
			else resa=resa*3+a[i]-'0';
		}
	}
	if(a[i]=='.')
	{
		i+=1;
		long long int resb=0,resc=1;
		for(;i<strlen(a);i++)
		{
			if(a[i]=='2'){
				resb=resb*3-1;
			}
			else resb=resb*3+a[i]-'0';
			resc=resc*3;
		}
		resb=resb/GCD(resb,resc);
		resc=resc/GCD(resb,resc);
		if(resb<0){
			resa=resa-1;
			resb=resc-resb;}
		else if(resa<0){
			resa=resa+1;
			resb=resc-resb;}
		if(resa!=0&&resb!=0)printf("%lld %lld %lld",resa,resb,resc);
		else if(resa==0)printf("%lld %lld",resb,resc);
		else if(resb==0)printf("%lld",resa);
		
	}
	else printf("%lld",resa);
	return 0;
	
	
}