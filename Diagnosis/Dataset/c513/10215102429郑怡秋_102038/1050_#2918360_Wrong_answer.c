#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int find_str(char* str1,char* str2,int n)
{
    int i,j,flag=-1;
    for(i=n,j=0;str1[i]!=NULL;i++)
    {
        while(str1[i]==str2[j]&&str1[i]&&str2[j])
        {
            i++;
            j++;
            if(str2[j]==NULL)
            {
                flag=i-j;
                return flag;
            }
        }
        j=0;
    }
    return flag;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char a[90],b[90],c[90];
		scanf("%s%s%s",a,b,c);
		int n1=0,n2=0;
		int l=find_str(c,a,n1);
		while(n1<=l) n1=l,l=find_str(c,a,n1+1);
		n2=find_str(c,b,0);
		int max1=abs(n1-n2-strlen(b));
		n1=0;n2=0;
		n1=find_str(c,a,0);
		int ll=find_str(c,b,n2);
		while(n2<=ll) n2=ll,ll=find_str(c,b,n2+1);
		int max2=abs(n2-n1-strlen(a));
		printf("case #%d:\n",i);
		if(max1>max2) printf("%d\n",max1);
		else printf("%d\n",max2);
	}
	return 0;
}