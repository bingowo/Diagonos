#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char ans[1234];

int main(){
	int t;
    scanf("%d",&t);
	for (int i=0;i<t;i++){
		int m;
		scanf("%d",&m);
		printf("case #%d:\n",i);
		char s[1234];
		ans[0]='\0';
		char readchar[11234];
		gets(readchar);
		gets(readchar);
		int ii=0;
		while (ii<strlen(readchar)){
            while (readchar[ii]==' ') ii++;
            if (ii>=strlen(readchar)) break;
            int xi=0;
            while (readchar[ii]!=' ' && ii<strlen(readchar)) {
                s[xi]=readchar[ii];
                ii++;
                xi++;
            }
            s[xi]='\0';
			if (strlen(ans)==0){
				strcpy(ans,s);
				continue;
			}
			if (strlen(ans)+strlen(s)+1<=m){
                int len=strlen(ans);
                ans[len]=' ';
                for (int j=0;j<=strlen(s);j++)
                    ans[len+j+1]=s[j];
			}
			else {
				while (strlen(ans)<m){
					for (int j=strlen(ans)-1;j>=0;j--){
						if (strlen(ans)==m) break;
						else if (ans[j]==' ' && ans[j-1]!=' '){
                            for (int k=strlen(ans)+1;k>=j;k--)
                                ans[k]=ans[k-1];
							ans[j]=' ';
						}
					}
				}
				printf("%s\n",ans);
                ans[0]='\0';
				strcpy(ans,s);
			}
		}
        printf("%s\n",ans);
	}
    return 0;
}
