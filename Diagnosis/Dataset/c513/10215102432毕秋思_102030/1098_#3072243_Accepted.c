#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d\n",&T);
	for(int t=0;t<T;t++)
	{
        char s[110];
        scanf("%s",&s);
        int len=strlen(s);
        int r=0,b=0,y=0,g=0;
        int i=0,j=0,k=0,l=0;
        while(i<len-1 && s[i]!='R') i++;
        while(j<len-1 && s[j]!='B') j++;
        while(k<len-1 && s[k]!='Y') k++;
        while(l<len-1 && s[l]!='G') l++;
        if(i==len-1 && s[i]!='R')
        {
            while(s[i]!='!') i--;
        }
        if(j==len-1 && s[j]!='B')
        {
            while(s[j]!='!') j--;
        }
        if(k==len-1 && s[k]!='Y')
        {
            while(s[k]!='!') k--;
        }
        if(l==len-1 && s[l]!='G')
        {
            while(s[l]!='!') l--;
        }
        while(i<len-4) i+=4;
        while(j<len-4) j+=4;
        while(k<len-4) k+=4;
        while(l<len-4) l+=4;
        while(i>=0)
        {
            if(s[i]=='!') {r++;}
            i-=4;
        }
        while(j>=0)
        {
            if(s[j]=='!') {b++;}
            j-=4;
        }
        while(k>=0)
        {
            if(s[k]=='!') {y++;}
            k-=4;
        }
        while(l>=0)
        {
            if(s[l]=='!') {g++;}
            l-=4;
        }
        printf("case #%d:\n",t);
        printf("%d %d %d %d\n",r,b,y,g);
    }
	return 0;
}

