#include <stdio.h>
#include <string.h>
void mul(int *L)
{
	int left=0;
	for(int i=100;i>0;i--)
	{
		int d = (L[i]*2+left)%10;
		left = (L[i]*2+left)/10;
		L[i]= d;
	}
	if(left!=0) L[0]=left;
}
void plus(int* L, int num)
{
	int k=99;
	int left = (L[100]+num)/10;
	L[100]=(L[100]+num)%10;
	while(left!=0)
	{
		int d=(left+L[k])%10; 
		left=(left+L[k])/10;
		L[k]=d;
	}
} 
int main()
{
    int cnt=0; scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        char s[102];
        int L[334],num=0;
        for(int i=0;i<334;i++) L[i]=0;
        scanf("%s",s);
        int len = strlen(s);
        while(1)
        {
            int flag=0;
            L[num++]=(s[len-1]-'0')%2;
            int left=0;
            for(int i=0;i<len;i++)
            {
                char c =(char)((s[i]-'0'+left*10)/2+'0');
                left = (s[i]-'0'+(left*10))%2;
                s[i] = c;
            }
            for(int i=0;i<len;i++) if(s[i]!='0') flag=1;
            if(flag==0) break;
        }
        //for(int i=0;i<num;i++) printf("%d ",L[i]);
        //printf("\n");
        int zero=0;
        while(L[zero]==0) zero++;
        int res[101]; 
        for(int i=0;i<102;i++) res[i]=0;
        for(int i=zero;i<num;i++)
        {
        	mul(res);
            plus(res,L[i]);
        }
        printf("case #%d:\n",k);
        int begin=0;
        for(int i=0;res[i]==0;i++) begin++;
        for(int i=begin;i<101;i++) printf("%d",res[i]);
        if(begin>=101) printf("0");
        printf("\n");
    }
    return 0;
}