#include <stdio.h>
#include <string.h>
int ato(int A,char a[]){
    int n;
n = strlen(a);
	int i,sum=0;
	for(i=0;i<n;i++)
        {
		if(a[i]>='0'&&a[i]<='9')
            {
			sum=sum*A+a[i]-'0';
		}
    else if(a[i]>='A'&&a[i]<='F')
		{
			sum = sum*A+a[i]-'A'+10;
		}
		else
        {
            sum=sum*A+a[i]-'a'+10;
        }
	}
	return sum;
}
void tob(int sum,int b){
	char a[100];
	int i,j=0,m;
	while(sum!=0){
		m= sum%b;
		if(m>=10)
            {
			a[j] =m-10+'A';
		}
		else
		{
			a[j] = m+'0';
		}
		sum = sum/b;
		j++;
	}
	for(i=j-1;i>=0;i--){
		printf("%c",a[i]);
	}
}
int main(){
	char a[100];
	int A,b;
	int m;
	scanf("%s%d%d",a,&A,&b);
m=ato(A,a);
	tob(m,b);
	return 0;
}
