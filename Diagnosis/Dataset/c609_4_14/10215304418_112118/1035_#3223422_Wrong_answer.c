#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123456];
char temp[1234];

int check(){
    for (int i=1;i<strlen(st);i++)
        if (st[i]==st[i-1]) return 1;
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",st);
        int ans=0;
        while (check()){
            int k=0;
            for (int j=0;j<strlen(st);j++){
                if (st[j]==st[j+1]){
                    while (st[j]==st[j+1]){
                        j++;
                        ans++;
                    }
                    ans++;
                }
                else {
                    temp[k]=st[j];
                    k++;
                }
            }
            temp[k]='\0';
            strcpy(st,temp);
        }
        int f=0;
        printf("case #%d:\n",i-1);
        if (strlen(st)==0) {
            printf("%d\n",ans+1);
            continue;
        }
        for (int i=1;i<strlen(st)-1;i++){
            if (st[i-1]==st[i+1]) {
                f=1;
                ans+=4;
                break;
            }
        }
        if (f==0){
            printf("%d\n",ans+2);
        }
        else printf("%d\n",ans);
    }
    return 0;
}
