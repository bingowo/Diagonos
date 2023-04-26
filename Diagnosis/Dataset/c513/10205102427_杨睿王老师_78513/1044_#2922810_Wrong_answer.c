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
			int cnt=0;
			while(1){
				int mark=0;
				if(a[j]=='0'&& a[j+1]=='x'){
					if(a[j+2]>='a'&& a[j+2]<='f'){
						break;
					}
					if(a[j+2]>='0'&& a[j+2]<='9'){
						break;
					}										
				}
				if(j>=l) break;
				//printf("test:j:%d\n",j);
				if(a[j]>='0'&& a[j]<='9'){
						num[ln]=a[j]-48;
						mark=1;
						cnt++;
						//printf("/%d/",num[ln]);
				}
				else if(a[j]>='a' && a[j]<='f'){
						num[ln]=a[j]-'a'+10;
						mark=1;
						cnt++;
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
			if(cnt==0) continue;
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