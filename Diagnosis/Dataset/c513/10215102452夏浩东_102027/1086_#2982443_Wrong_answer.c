#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1100],s2[1100],s[1100];
    int num=0;
    scanf("%s %s %d",s1,s2,&num);
    int len1=(int)strlen(s1),len2=(int)strlen(s2);
    int dot1=-1,dot2=-1;
    for(int i=0;i<len1;i++) if(s1[i]=='.'){dot1=i;break;}
    for(int i=0;i<len2;i++) if(s2[i]=='.'){dot2=i;break;}
    if(dot1==-1) dot1=len1;
    if(dot2==-1) dot2=len2;
    int dot = dot1>dot2?dot1:dot2;
    if(dot1>dot2) {
        int mov = dot1-dot2;
        for(int i=len2;i>=0;i--)
        {
            s2[i+mov]=s2[i];
        }
        for(int i=0;i<mov;i++) s2[i]='0';
        len2+=mov;
    }
    else{
        int mov = dot2-dot1;
        for(int i=len1;i>=0;i--)
        {
            s1[i+mov]=s1[i];
        }
        for(int i=0;i<mov;i++) s1[i]='0';
        len1+=mov;
    }
    for(int i=len1;i<1100;i++) s1[i]='0';
    for(int i=len2;i<1100;i++) s2[i]='0';
    int flag=1;
    for(int i=0;i<1100;i++)
	{
		if(s1[i]-'0'>s2[i]-'0') {flag=1;break;}
		else if(s1[i]-'0'<s2[i]-'0'){flag=-1;break;}
		else continue;
	}
	int left=0;
	if(flag==1)
	{   
	    for(int i=dot+num+3;i>=0;i--)
	    {
	        if(i==dot) s[i]='.';
	        else{
	            if(s1[i]>=s2[i]) {s[i]=s1[i]-s2[i]+'0';}
	            else{
				s[i]=s1[i]+10-s2[i]+'0';
				if((i-1)!=dot) s1[i-1]=s1[i-1]-1;
				else s1[i-2] = s1[i-2]-1;
				}
	        }
	    }
	}
	else{
		for(int i=1100;i>=0;i--)
	    {
	        if(i==dot) s[i]='.';
	        else{
	            if(s2[i]>=s1[i]) s[i]=s2[i]-s1[i]+'0';
	            else{s[i]=s2[i]+10-s1[i]+'0';
				if((i-1)!=dot) s2[i-1]=s2[i-1]-1;
				else s2[i-2]=s2[i-2]-1;
				}
	        }
	    }
	}	
    if(s[dot+num+1]>='5') s[dot+num]+=1;
    if(flag==-1) printf("-");
    if(dot==0 && left==0) printf("0");
    else if(left!=0) printf("%d",left);
    int zero=0;for(int i=0;i<1100;i++) 
	{
		if(s[i]=='0' && s[i+1]!='.' && left==0) zero++;
		else break;
	}
    for(int i=zero;i<=dot+num;i++) printf("%c",s[i]);
    return 0;
}