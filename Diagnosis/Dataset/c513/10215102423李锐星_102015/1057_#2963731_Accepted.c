#include <stdio.h>
#include <string.h>

int main()
{
	char w[1001],max[1001];
	scanf("%s",w);
	int i,j,k;
	if(w[0]>='a'&&w[0]<='z'){
		max[0]=w[0]-32;
	}
	else{
		max[0]=w[0];
	}
	for (i=1;i<strlen(w);i++){
		if(w[i]>='a'&&w[i]<='z'){
			w[i]-=32;
		}
		if(w[i]>=max[0]){
			for (j=0,k=i-1;j<k;j++,k--){
				char c;
				c=max[j];
				max[j]=max[k];
				max[k]=c;
			}
			max[i]=w[i];
			for (j=0,k=i;j<k;j++,k--){
				char c;
				c=max[j];
				max[j]=max[k];
				max[k]=c;
			}
		}
		else{
			max[i]=w[i];
		}
	}
	max[i]='\0';
	printf("%s",max);
	return 0;
}