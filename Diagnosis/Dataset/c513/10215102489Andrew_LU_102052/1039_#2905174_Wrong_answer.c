#include<stdio.h>
#include<string.h>	
long long bian[127][127][127][50];
int bianlen[126][126][126]={0};
char a[150][10];
char cc;
int len=0;
int cnt=0;
long long num[150]={0};
int f=0;
long long ansans=0;
long long ansansbian[150]={0};
int ansansbianlen=0;
int d(int s,int p){
	long long ansbian[150]={0};
	int ansbianlen=0;
	long long ans=0;
//	printf("%d %d\n",s,p);
	int l=p+1;
	f=0;
	int fff=0;
	while(l>0){
		l--;
		if(num[l]!=-1){
			ansbian[0]=num[l];
			ans=num[l]; 
			ansbianlen=1;
			break;
		}
		else if(a[l][0]>='a' && a[l][0]<='z'){
			//printf("memorize\n");
			f=1;
			//printf("%c%c%c=",a[l][0],a[l][1],a[l][2]);
			//printf("%d",bianlen[a[l][0]][a[l][1]][a[l][2]]);
			for(int j=0;j<bianlen[a[l][0]][a[l][1]][a[l][2]];j++)
				ansbian[j]=bian[a[l][0]][a[l][1]][a[l][2]][j];
			ans=ansbian[0];
			ansbianlen=bianlen[a[l][0]][a[l][1]][a[l][2]];
			break;
		}
	}
	//printf("%d\n",ansbian[0]);
	for(int j=p;j>=s;j--){
		//if(s==0) printf("j=%d\n",j);
		if(a[j][0]==')'){
			//printf("syeilsasd");
			int t=j;
			fff=1;
			int cntt=1;
			while(cntt!=0){
				t--;
				if(a[t][0]=='(') cntt--;
				else if(a[t][0]==')') cntt++;
			}
			d(t,j-1);
			ans=ansans;
			for(int k=0;k<ansansbianlen;k++){
				ansbian[k]=ansansbian[k];
			}
			ansbianlen=ansansbianlen;
			j=t;
			continue;
		}
		if(a[j][0]=='='){	
			//printf("j=%d ans=%d num=%d\n",j,ans,bian[97][48][48][0]);
			int tt=0;
			if(a[j+1+tt][0]>='0' && a[j+1+tt][0]<='9'){
				while(j+tt<len && a[j+1+tt][0]<='9' && a[j+tt+1][0]>='0'){
					//printf("hello now=%d\n",num[j+1+tt]);
					bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][tt]=num[j+1+tt];
					//printf("%d",tt);
					ansbian[tt]=num[j+1+tt];
					tt++;
				}
				bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]=tt;
				ansbianlen=tt;
				//printf("tt is here tt=%d\n\n\n\n\n",tt);
			}
			else{ //右边为变量与右边为括号运算方式一致。 
				//printf("yes is here yes=%d\n",ansbianlen);
				for(int k=0;k<ansbianlen;k++){
					bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]=ansbian[k];
				}
				bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]=ansbianlen;
			}
			f=1;
			//printf("j=%d ans=%d num=%d\n",j,ans,bian[97][48][48][0]);
				//printf("out");
				//向量==向量？ 
			//printf("innerj=%d	ans=%d	ansbian=%d	a=%d\n",j,ans,ansbian[0],bian[97][48][48][0]);
		}
		if(a[j][0]=='*'){
			if(a[j+1][0]=='/'){ //对向量运算 
				for(int k=bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]-1;k>=0;k--){
					bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k]*=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k+1];
				}
				bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]=1;
				ans=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][0];
				ansbian[0]=ans;
				ansbianlen=1;
				f=0;
			}
			else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算
					ansbian[0]=num[j-1]*ans; 
					ans=num[j-1]*ans;
					ansbianlen=1;
					num[j-1]=ans;
					f=0;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					if(f==1){
						for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
							ansbian[k]=ansansbian[k]*ans;
						}
						ansbianlen=ansansbianlen;
					}
					else{
						ans=ansans*ans;
						ansbian[0]=ans;
						ansbianlen=1;
					}
					j=t;
				} 
				else{
					for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
						ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]*ans;
					}
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					f=1;
				}
			}
			else{
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){
					ans=num[j-1]*ans;
					ansbian[0]=ans;
					ansbianlen=1;
					num[j-1]=ans;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
					 ansbian[k]=ansansbian[k]*ans;
					}
					ansbianlen=ansansbianlen;
					ans=ansbian[0];
					j=t;
				} 
				else{
					for(int k=0;k<bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];k++)
					 ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]*ans;
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					num[j-1]=ansbian[0];
					ans=ansbian[0];
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
				ansbian[0]=ans;
				ansbianlen=1;
				f=0;
			}
			else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算
					ansbian[0]=num[j-1]+ans; 
					ans=num[j-1]+ans;
					ansbianlen=1;
					num[j-1]=ans;
					f=0;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					if(f==1){
						for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
							ansbian[k]=ansansbian[k]+ans;
						}
						ansbianlen=ansansbianlen;
					}
					else{
						ans=ansans+ans;
						ansbian[0]=ans;
						ansbianlen=1;
					}
					j=t;
				} 
				else{
					for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
						ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]+ans;
					}
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					f=1;
				}
			}
			else{
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){
					ans=num[j-1]+ans;
					ansbian[0]=ans;
					ansbianlen=1;
					num[j-1]=ans;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
					 ansbian[k]=ansansbian[k]+ans;
					}
					ansbianlen=ansansbianlen;
					ans=ansbian[0];
					j=t;
				} 
				else{
					for(int k=0;k<bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];k++)
					 ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]+ans;
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					num[j-1]=ansbian[0];
					ans=ansbian[0];
					f=1;
				}
			}
		}
		if(a[j][0]=='-'){
			if(a[j+1][0]=='/'){ //对向量运算 
				//printf("hello its me");
				for(int k=bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]-1;k>=0;k--){
					bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k]-=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][k+1];
				}
				bianlen[a[j+2][0]][a[j+2][1]][a[j+2][2]]=1;
				ans=bian[a[j+2][0]][a[j+2][1]][a[j+2][2]][0];
				ansbian[0]=ans;
				ansbianlen=1;
				f=0;
			}
			else if(a[j+1][0]>='0' && a[j+1][0]<='9'){
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){  //双数字运算
					ansbian[0]=num[j-1]-ans; 
					ans=num[j-1]-ans;
					ansbianlen=1;
					num[j-1]=ans;
					f=0;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					if(f==1){
						for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
							ansbian[k]=ansansbian[k]-ans;
						}
						ansbianlen=ansansbianlen;
					}
					else{
						ans=ansans-ans;
						ansbian[0]=ans;
						ansbianlen=1;
					}
					j=t;
				} 
				else{
					for(int k=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]]-1;k>=0;k--){ //左变量右数 
						ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]-ans;
					}
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					f=1;
				}
			}
			else{
				if(a[j-1][0]>='0' && a[j-1][0]<='9'){
					ans=num[j-1]-ans;
					ansbian[0]=ans;
					ansbianlen=1;
					num[j-1]=ans;
				}
				else if(a[j-1][0]==')'){
					int t=j-1;
					fff=1;
					int cntt=1;
					while(cntt!=0){
						t--;
						if(a[t][0]=='(') cntt--;
						else if(a[t][0]==')') cntt++;
					}
					d(t,j-2);
					for(int k=ansansbianlen-1;k>=0;k--){ //左变量右数 
					 ansbian[k]=ansansbian[k]-ans;
					}
					ansbianlen=ansansbianlen;
					ans=ansbian[0];
					j=t;
				} 
				else{
					for(int k=0;k<bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];k++)
					 ansbian[k]=bian[a[j-1][0]][a[j-1][1]][a[j-1][2]][k]-ans;
					ansbianlen=bianlen[a[j-1][0]][a[j-1][1]][a[j-1][2]];
					num[j-1]=ansbian[0];
					ans=ansbian[0];
					f=1;
				}
			}
			
		}
		//printf("ans=%d\n",ansbian[0]);
	//	printf("ansbian=%d\n",ansbian[1]);
		//printf("j=%d	ans=%d	ansbian=%d	a=%d\n",j,ans,ansbian[0],bian[97][48][48][0]);
	}
	//if(s==0){
		//printf("f=%d\n",f);
	ansans=ans;
	for(int j=0;j<ansbianlen;j++){
		ansansbian[j]=ansbian[j];
	}
	ansansbianlen=ansbianlen;
	//}
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		len=0;
		cnt=0;
		for(int j=0;j<150;j++){
			for(int k=0;k<10;k++){
				a[j][k]='\0';
			}
		}
		for(int j=0;j<150;j++){
			num[j]=-1;
		}	
		while(scanf("%c",&cc)!=EOF){
			if(cc=='\n') {
				if(a[len][0]<='z' && a[len][0]>='a'){
					if(a[len][1]>'z' || a[len][1]<'a') a[len][1]='0';
					if(a[len][2]>'z' || a[len][2]<'a') a[len][2]='0';
				} 
				cnt=0;
				len++;
				break;
			}
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
		//if(a[len][0]<='z' && a[len][0]>='a'){
		//	if(a[len][1]>'z' || a[len][1]<'a') a[len][1]='0';
		//	if(a[len][2]>'z' || a[len][2]<'a') a[len][2]='0';
		//} 
		//printf("first len = len %d\n",bianlen[a[len][0]][48][48]);
		//printf("num=%d %d %d\n",num[2],num[3],num[4]);
		d(0,len);
		//printf("len=%dlenlen\n\n\n\n\n",bianlen[97][48][48]);
		//if(f==0) printf("%lld\n",ansans);
		//else{
			//printf("ansbianlen");
			for(int j=0;j<ansansbianlen;j++){
				printf("%lld ",ansansbian[j]);
			}
			printf("\n");
		//}
	}
}