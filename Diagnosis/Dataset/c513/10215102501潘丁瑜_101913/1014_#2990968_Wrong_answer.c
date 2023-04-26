#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    long long int A,B,i=0,j=0;
    long long int temp=0;
    int r,t;
    char a[10000]={0};
    char a2[10000]={0};
    scanf("%lld",&A);
    scanf("%lld",&B);
    r=log(B)/log(3);
    while(A>0)
    {
        a[i++]=A%3+'0';
        temp=A/3;
        A=temp;
    }
    for(j=0;i>0;j++)
        a2[j]=a[--i];
    if(r!=0)
        a2[j]='.';
    t=j;
    j--;
    if(r!=0)
    {
        while(j>=0 && a2[j+r+1]!='.')
        {
            if(a2[j] == '0' && a2[j+1]==0) 
            {
                a2[j]==0;
                j--;
                continue;
            }
            a2[j+r+1] = a2[j];
            a2[j]='0';
            j--;
        }
        while(j>=0)
        {
            a2[j+r] = a2[j];
            a2[j]='0';
            j--;
        }
    }
    if(t<r)
    {
        t=r;
        while(a2[t] != '.') a2[t--] ='0';
    }
    j=strlen(a2);
    char str1[1000]="1";
    while(j>=0)
    {
    	if(a2[j] == '2')
        {
            if(a2[j-1] == 0)
            {
                strcat(str1,a2);
                strcpy(a2,str1);
            }
            else if(a2[j-1] != '.')
                a2[j-1] = a2[j-1] +1;
            else a2[j-2]=a2[j-2]+1;
        }
    		
    	else if(a2[j] == '3')
    	{
            a2[j]='0';
            if(j-1>=0)
            {
                if(a2[j-1] != '.')
                    a2[j-1] += 1;
                else a2[j-2]+=1;
            }
    		    
            else 
            {
                strcat(str1,a2);
                strcpy(a2,str1);
            }
		}
		j--;
	}
    if(r!=0)
    {
        for(i=strlen(a2);i>=0;i--)
        {
            if(a2[i] == '0' && a2[i+1] == 0)
                a2[i] = 0;
            if(a2[i] == '.' && a2[i+1] == 0)
            {
                a2[i] = 0;
                break;
            }   
        }
    }
    
    i=0;
    while(a2[i] == '0' && a2[i+1] >= '0')
        i++;
    for(i;i<strlen(a2);i++)
        printf("%c",a2[i]);
	
    return 0;
}