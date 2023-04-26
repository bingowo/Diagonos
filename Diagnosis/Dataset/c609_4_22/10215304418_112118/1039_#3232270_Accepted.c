#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[1234];
char st1[1234];
char st2[1234];

int main(){
    int t;
    char s[1234];
    scanf("%d",&t);
    gets(s);
    for (int l=1;l<=t;l++){
        scanf("%s",st1);
        scanf("%s",st2);
        scanf("%s",st);
        int head1=-1,tail1=-1;
        for (int i=0;i<strlen(st);i++){
            if (st[i]==st1[0]){
                int f=0;
                for (int j=0;j<strlen(st1);j++){
                    if (i+j>=strlen(st)) {
                        f=1;
                        break;
                    }
                    if (st[i+j]!=st1[j]) {
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    head1=i+strlen(st1)-1;
                    break;
                }
            }
        }
        int len=strlen(st);
        for (int i=len-1;i>=0;i--){
            if (st[i]==st1[strlen(st1)-1]){
                int f=0;
                for (int j=strlen(st1)-1;j>=0;j--){
                    if (i-strlen(st1)+1+j<0) {
                        f=1;
                        break;
                    }
                    if (st[i-strlen(st1)+1+j]!=st1[j]) {
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    tail1=i-strlen(st1)+1;
                    break;
                }
            }
        }
        int head2=-1,tail2=-1;
        for (int i=0;i<strlen(st);i++){
            if (st[i]==st2[0]){
                int f=0;
                for (int j=0;j<strlen(st2);j++){
                    if (i+j>=strlen(st)) {
                        f=1;
                        break;
                    }
                    if (st[i+j]!=st2[j]) {
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    head2=i+strlen(st2)-1;
                    break;
                }
            }
        }
        for (int i=len-1;i>=0;i--){
            if (st[i]==st2[strlen(st2)-1]){
                int f=0;
                for (int j=strlen(st2)-1;j>=0;j--){
                    if (i-strlen(st2)+1+j<0) {
                        f=1;
                        break;
                    }
                    if (st[i-strlen(st2)+1+j]!=st2[j]) {
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    tail2=i-strlen(st2)+1;
                    break;
                }
            }
        }
        printf("case #%d:\n",l-1);
        if (head1==-1 || tail1==-1 || head2==-1 || tail2==-1)
            printf("0\n");
        else if (tail1-head2<0 && tail2-head1<0) printf("0\n");
        else if (tail1-head2>tail2-head1) printf("%d\n",tail1-head2-1);
        else printf("%d\n",tail2-head1-1);
    }
    return 0;
}
