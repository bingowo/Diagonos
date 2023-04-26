#include <stdio.h>
#include <string.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        char s[101];
        scanf("%s",s);
        int R=0,G=0,B=0,Y=0,len=(int)strlen(s),begin=0;
        for(int i=0;i<len;i++)
        {
            int num=0;
            for(int j=i;j<i+4 && j<len;j++)
            {
                if(s[j]!='!') num++;
            }
            if(num>=3){begin=i;break;}
        }
        int L[]={0,0,0,0};
        int target=-1;
        for(int i=begin;i<begin+4 && i<len;i++)
        {
            if(s[i]=='R') L[0]=1;
            else if(s[i]=='G') L[1]=1;
            else if(s[i]=='B') L[2]=1;
            else if(s[i]=='Y') L[3]=1;
            else target=i;
        }
        if(target!=-1)
        {
        	if(L[0]==0){s[target]='R';R++;}
	        else if(L[1]==0){s[target]='G';G++;}
	        else if(L[2]==0){s[target]='B';B++;}
	        else if(L[3]==0){s[target]='Y';Y++;}	
		}
        for(int i=begin+4; i<len; i++)
        {
            if(s[i]=='!'){
                if(s[i-4]=='R') R++;
                else if(s[i-4]=='G') G++;
                else if(s[i-4]=='B') B++;
                else if(s[i-4]=='Y') Y++;
            }
        }
        for(int i=0;i<begin;i++)
        {
            if(s[i]=='!'){
                if(s[i+4]=='R') R++;
                else if(s[i+4]=='G') G++;
                else if(s[i+4]=='B') B++;
                else if(s[i+4]=='Y') Y++;
            }
        }
        printf("case #%d:\n",k);
        printf("%d %d %d %d\n",R,B,Y,G);
    }
}