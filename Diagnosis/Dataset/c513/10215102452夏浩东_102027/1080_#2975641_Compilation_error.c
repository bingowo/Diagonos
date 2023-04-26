#include <stdio.h>
int main()
{
    int cnt=0; scanf("%d",&cnt);
    for(int i=0;i<cnt;i++) {
        char NL[102];
        for(int j=0;j<101;j++) NL[j]='\0';
        int L[334];
        for(int i=0;i<334;i++) L[i]=0;
        scanf("%s",NL);
        int len=0;
        len=strlen(m);
		int sum=1,size=0; 
		while(sum){
			sum=0;
			for(int i=0;i<len;i++){
				int x=NL[i]-'0';
				int d=x/2;
				sum+=d;
				if(i<len-1){
					NL[i+1]=x%2*10+NL[i+1];
				}
				if(i==len-1){
					L[size++]=x%2+'0'; 
				}
				NL[i]=d+'0';
			}
		}
		for(int k=333;k>=334/2;k--)
		{
		    int temp = L[k];
		    L[k]=L[333-k];
		    L[333-k]=L[k];
		}
		int zero=0,t=0;
		while(L[t++]==0) zero++;
		int RES[100],num=0,S=0;
		for(int k=333;k>=zero;k--)
		{
		    S+=SL[k];
		    if(S>=10) RES[num++]=S%10
		}
    }
}