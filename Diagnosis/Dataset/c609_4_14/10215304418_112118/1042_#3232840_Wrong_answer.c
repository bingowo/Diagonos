#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[2234];
char ans[2540][100];

int main(){
    int t;
    scanf("%d",&t);
    for (int l=0;l<t;l++){
        int m;
        scanf("%d",&m);
        gets(st);
        gets(st);
        int i=0;
        int j=0;
        for (int clear=0;clear<=2200;clear++)
            ans[clear][0]='\0';
        for (int pos=0;pos<strlen(st);pos++){
            if (st[pos]==' '){
                if (j!=0) {
                    ans[i][j]='\0';
                    j=0;
                    i++;
                }
            }
            else{
                ans[i][j]=st[pos];
                j++;
            }
        }
        if (j!=0) i++;
        printf("case #%d:\n",l);
        int len=0;
        int num=0;
        int k=0;
        for (k=0;k<i;k++){
            if (len+strlen(ans[k])+num-1<m){
                num++;
                len+=strlen(ans[k]);
            }
            else{
                int kong=(m-len)%(num-1);
                for (int ll=num;ll>0;ll--){
                    printf("%s",ans[k-ll]);
                    if (ll==1) break;
                    if (ll-1<=kong){
                        for (int kongi=1;kongi<=(m-len)/(num-1)+1;kongi++)
                            printf(" ");
                    }
                    else{
                        for (int kongi=1;kongi<=(m-len)/(num-1);kongi++)
                            printf(" ");
                    }
                }
                printf("\n");
                len=strlen(ans[k]);
                num=1;
            }
        }
        for (int ll=num;ll>0;ll--){
            printf("%s",ans[k-ll]);
            if (ll==1) break;
            printf(" ");
        }
        if (l!=t-1) printf("\n");
    }
    return 0;
}
