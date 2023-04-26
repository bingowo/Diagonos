#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[81];
	while(gets(s)){
        int len=strlen(s);
        char ss[2*len+1][2*len+1];
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                ss[i][j]=' ';
        int row=len;
        ss[row][0]=s[0];
        for(int i=1;i<len;i++)
        {
            if(s[i]>s[i-1]){
                row++;
                ss[row][i]=s[i];
            }
            if(s[i]<s[i-1]){
                row--;
                ss[row][i]=s[i];
            }
            else ss[row][i]=s[i];
        }
        for(int i=0;i<2*len+1;i++)
            printf("%s\n",ss[i]);
	}
	return 0;
}
