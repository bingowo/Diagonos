#include<stdio.h>
#include<string.h>
int Addl(char A[],int k)
{	int i=k;
	while(i>=0)
	{
	  A[i]+=1;
 	  if(A[i]<='9')	return i;
	  A[i] = '0';
	  i--;
	}
	return i;
}

int main()
{
     int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        char num[102];
        scanf("%s",num);
        printf("case #%d:\n",I);
        int len=strlen(num);
        int i,j;
        Addl(num,len-1);
        for(i=1;i<len;i++)
        {
            if(num[i]==num[i-1]) break;
        }
        if(i!=len)
        {
            i=Addl(num,i);
            while(i>0)
            {
                if(num[i]!=num[i-1]) break;
		        i=Add1(num,i);
            }
            for(j=i+1;j<len;j++)
            {
                num[j]=(j-i+1)%2+'0';
            }
        }
        if(num[0]!='0') printf("%c",num[0]);
        printf("%s\n",num+1);
    }
    return 0;
}