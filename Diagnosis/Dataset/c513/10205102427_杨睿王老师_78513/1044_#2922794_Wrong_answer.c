//1044
#include <stdio.h>
int main(){
	char ch;
	char a[100000];
	int l=0;
	while((ch=getchar())!='\n'){
		a[l]=ch;
		l++;
	}
	int flag=0;
	for(int i=0;i<l;i++){
		if(a[i]=='0' && a[i+1]=='x'){
			//printf("yes\n");
			int j=i+2;
			int num[200];
			int ln=0;
			int ans=0;
			while(1){
				int mark=0;
				if(a[j]=='0'&& a[j+1]=='x'){
					break;
				}
				if(j>=l) break;
				//printf("test:j:%d\n",j);
				if(a[j]>='0'&& a[j]<='9'){
						num[ln]=a[j]-48;
						mark=1;
						//printf("/%d/",num[ln]);
				}
				else if(a[j]>='a' && a[j]<='f'){
						num[ln]=a[j]-'a'+10;
						mark=1;
				}
				if(mark==0){
					//printf("pass");
					break;	
				}			
				ln++;
				j++;
			}
			i=j;
			i--;
			//printf("\ntest:i:%d\n",i);
			//printf("\ntest:ln:%d\n",ln);
			for(int y=0;y<ln-1;y++){
				//printf("%d ",num[y]);
				ans=(ans+num[y])*16;
			}
			ans+=num[ln-1];
			flag=1;
			printf("%d ",ans);	
		}
		//printf("pass");
	}
	if(flag==0) printf("-1");
}