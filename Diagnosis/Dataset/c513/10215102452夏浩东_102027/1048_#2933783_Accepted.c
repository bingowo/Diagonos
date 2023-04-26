#include <stdio.h>
int max(int a,int b)
{
    if(a<b) return b;
    else return a;
}
int main()
{
	char s1[300],s2[300];
    while(scanf("%s %s",s1,s2)==2)
    {
    	int L1[50]={0},L2[50]={0};
    	int L[100]={0};
	    int num=0,t=0,flag=1,readx=0;
	    for(int i=0;s1[i]!='\0';i++)
	    {
	        if(s1[i]=='-') flag=-1;
	        else if(s1[i]<='9' && s1[i]>='0' && readx==0) num=num*10+s1[i]-'0';
	        else if(s1[i]<='9' && s1[i]>='0' && readx==1) t=t*10+s1[i]-'0';
	        else if(s1[i]=='x') {num=max(num,1)*flag;readx=1;}
	        
	        if(readx==1 && (s1[i+1]=='-'||s1[i+1]=='+')) 
	        {
	        	t=max(t,1);
	            L1[t]=num;
	            num=0;t=0;flag=1;readx=0;
	        }
	        if(s1[i+1]=='\0') L1[0]=flag*num;
	    }
	    num=0;t=0;flag=1;readx=0;
	    for(int i=0;s2[i]!='\0';i++)
	    {
	        if(s2[i]=='-') flag=-1;
	        else if(s2[i]<='9' && s2[i]>='0' && readx==0) num=num*10+s2[i]-'0';
	        else if(s2[i]<='9' && s2[i]>='0' && readx==1) t=t*10+s2[i]-'0'; 
	        else if(s2[i]=='x') {num=max(num,1)*flag;readx=1;}
	        
	        if(readx==1 && (s2[i+1]=='-'||s2[i+1]=='+')) 
	        {
	        	t=max(t,1);
	            L2[t]=num;
	            num=0;t=0;flag=1;readx=0;
	        }
	        if(s2[i+1]=='\0') L2[0]=flag*num;
	    }
	    for(int k=0;k<50;k++)
	    {
	        for(int j=0;j<50;j++)
	        {
	            L[k+j]+=L1[k]*L2[j];
	        }
	    }
	    for(int k=98;k>=0;k--) if(L[k]!=0) printf("%d ",L[k]);
	    printf("\n");
    }
    return 0;
}