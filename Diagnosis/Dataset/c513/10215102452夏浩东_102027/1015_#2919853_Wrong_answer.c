#include <stdio.h>
int isPrime(int k)
{
    if(k==2) return 1;
    if(k%2==0) return 0;
    for(int i=3;i*i<=k;i+=2) if(k%i==0) return 0;
    return 1;
}
int main()
{
    int num=0;
    scanf("%d",&num);
    int L1[25]={0};
    int L2[25]={0};
    int L3[25]={0};
    int L[25]={0};
    for(int k=2,i=0;i<25;k++) if(isPrime(k)==1){L[i]=k;i++;}
    for(int k=0;k<num;k++)
    {
        int i=0,j=0;
        char c=',';
        while(c!=' ') {scanf("%d%c",&L1[i],&c);i++;}
        while(c!='\n'){scanf("%d%c",&L2[j],&c);j++;}
        if(i<j){for(int n=j-1;n>=j-i;n--){L1[n]=L1[n-j+i];L1[n-j+i]=0;}}
        else if(j>i){for(int n=i-1;n>=i-j;n--){L2[n]=L2[n-i+j];L2[n-i+j]=0;}}
        int left=0;
        int max= i>j ? i:j;
	    for(int n=max-1,m=0;n>=0;n--,m++)
	    {
	        if(L1[n]+L2[n]+left<L[m]) {L3[n]=L1[n]+L2[n]+left; left=0;}
	        else {L3[n]=-L[m]+L1[n]+L2[n]+left; left=1;}
	    }
	    printf("case #%d:\n",k);
	    if(left==1) printf("1,");
	    for(int n=0;n<max;n++)
	    {
	        if(n!=max-1) printf("%d,",L3[n]);
	        else printf("%d\n",L3[n]);
	    }
    }
    return 0;
}