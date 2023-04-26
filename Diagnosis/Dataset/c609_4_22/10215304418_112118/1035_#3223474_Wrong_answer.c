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
        int prelen=strlen(st);
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
        ans=prelen-strlen(st);
        int maxlen=1;
        for (int j=0;j<strlen(st);j++){
            int k=0;
            while (j-k>=0 && j+k<strlen(st) && st[j-k]==st[j+k]) k++;
            if (maxlen<2*k) maxlen=2*k;
        }
        ans+=maxlen;
        printf("%d\n",ans);
    }
    return 0;
}
/*BBABCABCCBCABCCBAABBBBACAAACBCBACCACAAACACBABBAAA*/
