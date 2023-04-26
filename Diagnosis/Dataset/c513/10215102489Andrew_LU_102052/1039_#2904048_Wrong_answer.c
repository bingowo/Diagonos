#include<stdio.h>
#include<string.h>	
long long bian[127][127][127][50];
int bianlen[126][126][126]={0};
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		char a[150][10];
		for(int j=0;j<150;j++){
			for(int k=0;k<10;k++){
				a[j][k]='\0';
			}
		}
		char cc;
		int len=0;
		int cnt=0;
		long long num[150]={0};
		for(int j=0;j<150;j++){
			num[j]=-1;
		}
		long long cun[150]={0};
		long long ansbian[150]={0};
		int ansbianlen=0; 
		while(scanf("%c",&cc)!=EOF){
			if(cc=='\n') break;
			if(cc==' '){
				if(a[len][0]<='z' && a[len][0]>='a'){
					if(a[len][1]>'z' || a[len][1]<'a') a[len][1]='0';
					if(a[len][2]>'z' || a[len][2]<'a') a[len][2]='0';
				} 
				cnt=0;
				len++;
			}
			else{
				if(cc>='0' && cc<='9'){
					if(num[len]==-1) num[len]=cc-'0';
					else num[len]=num[len]*10+cc-'0';
				}
				a[len][cnt++]=cc;
			}
		}
		//printf("num=%d %d %d\n",num[2],num[3],num[4]);
		long long ans=0;
		int f=0;
		int l=len+1;
		while(l>0){
			l--;
			if(num[l]!=-1){
				ans=num[l]; 
				break;
			}
			else if(a[l][0]>='a' && a[l][0]<='z'){
				f=1;
				for(int j=0;j<bianlen[a[l][0]][a[l][1]][a[l][2]];j++)
					ansbian[j]=bian[a[l][0]][a[l][1]][a[l][2]][j];
				ans=ansbian[0];
				ansbianlen=bianlen[a[l][0]][a[l][1]][a[l][2]];
				break;
			}
		}
		int dir=0;
		for(int j=len;j>=0;j--){
			//printf("j=%d\n",j);
			if(a[j][0]=='='){	
				int tt=0;
				if(a[j+1+tt][0]>='0' && a[j+1+tt][0]<='9'){
					while(j+tt<len && a[j+1+tt][0]<='9' && a[j+tt+1][0]>='0'){
						//printf("hello now=%d\n",j+1+tt);
						bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][tt]=num[j+1+tt];
						//printf("%d",tt);
						ansbian[tt]=num[j+1+tt];
						tt++;
					}
					bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]=tt;
					ansbianlen=tt;
				}
				else{
					//printf("yes=%d\n",ansbianlen);
					for(int k=0;k<ansbianlen;k++){
						bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]=ansbian[k];
					}
					bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]=ansbianlen;
				}
				f=1;
				//printf("out");
				//向量==向量？ 
			}
			if(a[j][0]=='-'){
				if(a[j+1][0]=='/'){ //对向量运算 
					//printf("hel");
					for(int k=bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]-1;k>=0;k--){
						//printf("k=%d\n",k);
						bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k]-=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k+1];
					}
					
					bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]=1;
					//printf("yes");
					ans=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][0];
					f=0;
				}
				else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算 
						ans=num[j-1]-ans;
						num[j-1]=num[j-1]-ans;
						f=0;
					}
					else{
						for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
							//bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]-=num[j+1;
							ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]-ans;
						}
						ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
						f=1;
					}
				}
				else{
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){
						ans=num[j-1]-ans;
						f=0;
					}
					else{
						ansbian[0]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][0]-ansbian[0];
						f=1;
					}
				}
			}
			if(a[j][0]=='+'){
				if(a[j+1][0]=='/'){ //对向量运算 
					for(int k=bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]-1;k>=0;k--){
						bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k]+=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k+1];
					}
					bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]=1;
					ans=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][0];
					f=0;
				}
				else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算 
						ans=num[j-1]+ans;
						num[j-1]=num[j-1]+ans;
						f=0;
					}
					else{
						for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
						//	bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]+=ans;
							ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]+ans;
						}
						ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
						f=1;
					}
				}
				else{
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){
						ans=num[j-1]+ans;
						f=0;
					}
					//无双向量运算 
					ansbian[0]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][0]+ansbian[0];
				}
			}
			if(a[j][0]=='*'){
				if(a[j+1][0]=='/'){ //对向量运算 
					for(int k=bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]-1;k>=0;k--){
						bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k]*=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k+1];
					}
					bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]=1;
					ans=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][0];
					f=0;
				}
				else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算 
						ans=num[j-1]*ans;
						num[j-1]=num[j-1]*ans;
						f=0;
					}
					else{
						for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
						//	bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]*=ans;
							ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]*ans;
						}
						ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
						f=1;
					}
				}
				else{
					if(a[j-1][0]>='0' && a[j-1][0]<='9'){
						ans=num[j-1]*ans;
						f=0;
					}
					//无双向量运算 
					ansbian[0]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][0]*ansbian[0];
				}
			}
			//printf("ans=%d\n",ans);
		}
		if(f==0) printf("%lld\n",ans);
		else{
			//printf("ansbianlen=%d",ansbianlen);
			for(int j=0;j<ansbianlen;j++){
				printf("%lld ",ansbian[j]);
			}
			printf("\n");
		}
	}
}