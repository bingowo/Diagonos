#include <stdio.h>
#include <stdlib.h>

int jc(int zi,int mu)
{
    int k=1,max=1;
    for(;k<=zi;k++){
        if(zi%k==0&&mu%k==0){
            max=k;
        }
    }
    return max;
}

int main()
{
    int n=0,s=0,p=0;
    scanf("%d %d %d",&n,&s,&p);
    p--;
    int a[1000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int zi=0,mu=0,zil=0,mul=0,zir=0,mur=0;
    while(s>0){
        int left=0,right=0,zhong=0;
        int jizhun=a[p],zuo=p-1,you=p+1;
        for(;zuo>=0;zuo--){
            if(a[zuo]>jizhun) break;
            left+=(jizhun-a[zuo]);
        }
        for(;you<n;you++){
            if(a[you]>jizhun) break;
            right+=(jizhun-a[you]);
        }
        if(left==0&&right==0&&(zuo>=0||you<n)){
            if(zuo>=0&&you<n)jizhun= (a[zuo]>a[p]&&a[zuo]<=a[you]) ? a[zuo]:a[you];
            else if(zuo<0&&you<n) jizhun=a[you];
            else jizhun=a[zuo];
            for(int i=zuo;i<you;i++){
                if(jizhun>a[i]) zhong+=(jizhun-a[i]);
            }
            //printf("%d %d %d\n",zuo,you,zhong);
            if(zhong<s){
                s-=zhong;
                for(int i=zuo;i<=you;i++){
                    if(jizhun>a[i]) a[i]=jizhun;
                }
            }
            else{
                mu=you-zuo-1;
                for(;s>=mu;s-=mu){
                    for(int i=zuo+1;i<you;i++){
                        a[i]++;
                    }
                }
                zi=s;
                s=0;
                int gong=jc(zi,mu);
                zi/=gong,mu/=gong;
                for(int i=0;i<=zuo;i++) printf("%d ",a[i]);
                if(zi>0) {
                    for(int i=zuo+1;i<you;i++) printf("%d+%d/%d ",a[i],zi,mu);
                }
                else {
                    for(int i=zuo+1;i<you;i++) printf("%d ",a[i]);
                }
                for(int i=you;i<n;i++) printf("%d ",a[i]);
                printf("\n");
            }
        }
        else if(left==0&&right==0){
            int x=s/n;
            mu=n;
            zi=s%n;
            s=0;
            int gong=jc(zi,mu);
            zi/=gong;
            mu/=gong;
            if(zi>0) {
                for(int i=0;i<n;i++) printf("%d+%d/%d ",a[i]+x,zi,mu);
            }
            else {
                for(int i=0;i<n;i++) printf("%d ",a[i]+x);
            }
        }
        else {
            if(left+right>=s){
                if(left>=right&&right<=s/2){
                    for(int i=p;i<you;i++){
                        if(a[i]<jizhun) a[i]=jizhun;
                    }
                    s-=right;
                    int min=jizhun;
                    while(s>0){
                        int wei=0,wei1=0;
                        mul=0;
                        min=jizhun;
                        for(int i=p-1;i>zuo;i--){
                            if(a[i]<min) {mul=1;min=a[i];}
                            else if(a[i]==min) mul++;
                            else {wei=i;break;}
                            if(i==0) wei=zuo;
                        }
                        wei1=wei+mul+1;
                        if(s>mul){
                            for(int i=0;i<mul;i++){
                                a[wei+1+i]++;
                            }
                            s-=mul;
                        }
                        else {
                            zil=s;
                            s=0;
                            int gong=jc(zil,mul);
                            zil/=gong;
                            mul/=gong;
                            for(int i=0;i<=wei;i++) printf("%d ",a[i]);
                            if(zil/mul<1) {
                                for(int i=wei+1;i<wei1;i++) printf("%d+%d/%d ",a[i],zil,mul);
                            }
                            else {
                                for(int i=wei+1;i<wei1;i++) printf("%d ",a[i]+1);
                            }
                            for(int i=wei1;i<n;i++) printf("%d ",a[i]);
                            printf("\n");
                        }
                    }
                }
                else if(left<=right&&left<=s/2){
                    for(int i=p;i>zuo;i--){
                        if(a[i]<jizhun) a[i]=jizhun;
                    }
                    s-=left;
                    int min=jizhun;
                    while(s>0){
                        int wei=0,wei1=0;
                        mul=0;
                        min=jizhun;
                        for(int i=p+1;i<you;i++){
                            if(a[i]<min) {mul=1;min=a[i];}
                            else if(a[i]==min) mul++;
                            else {wei=i;break;}
                            if(i==n-1) wei=you;
                        }
                        wei1=wei-mul-1;
                        if(s>mul){
                            for(int i=0;i<mul;i++){
                                a[wei-1-i]++;
                            }
                            s-=mul;
                        }
                        else {
                            zil=s;
                            s=0;
                            int gong=jc(zil,mul);
                            zil/=gong;
                            mul/=gong;
                            for(int i=0;i<=wei1;i++) printf("%d ",a[i]);
                            if(zil/mul<1) {
                                for(int i=wei1+1;i<wei;i++) printf("%d+%d/%d ",a[i],zil,mul);
                            }
                            else {
                                for(int i=wei1+1;i<wei;i++) printf("%d ",a[i]+1);
                            }
                            for(int i=wei;i<n;i++) printf("%d ",a[i]);
                            printf("\n");
                        }
                    }
                }
                else {
                    int l=s/2,r=s/2,sheng=0;
                    if(s%2!=0) sheng=1;
                    s=0;
                    if(sheng==0||sheng==1){
                        while(l>0){
                        int wei=0,wei1=0;
                        mul=0;
                        int min=jizhun;
                        for(int i=p-1;i>zuo;i--){
                            if(a[i]<min) {mul=1;min=a[i];}
                            else if(a[i]==min) mul++;
                            else {wei=i;break;}
                            if(i==0) wei=zuo;
                        }
                        wei1=wei+mul+1;
                        if(l>mul){
                            for(int i=0;i<mul;i++){
                                a[wei+1+i]++;
                            }
                            l-=mul;
                        }
                        else {
                            zil=l;
                            l=0;
                            int gong=jc(zil,mul);
                            zil/=gong;
                            mul/=gong;
                            for(int i=0;i<=wei;i++) printf("%d ",a[i]);
                            if(zil/mul<1) {
                                for(int i=wei+1;i<wei1;i++) printf("%d+%d/%d ",a[i],zil,mul);
                            }
                            else {
                                for(int i=wei+1;i<wei1;i++) printf("%d ",a[i]+1);
                            }
                            for(int i=wei1;i<p;i++) printf("%d ",a[i]);
                        }
                    }
                    while(r>0){
                        int wei=0,wei1=0;
                        mul=0;
                        int min=jizhun;
                        for(int i=p+1;i<you;i++){
                            if(a[i]<min) {mul=1;min=a[i];}
                            else if(a[i]==min) mul++;
                            else {wei=i;break;}
                            if(i==n-1) wei=you;
                        }
                        wei1=wei-mul-1;
                        if(r>mul){
                            for(int i=0;i<mul;i++){
                                a[wei-1-i]++;
                            }
                            r-=mul;
                        }
                        else {
                            zil=r;
                            r=0;
                            int gong=jc(zil,mul);
                            zil/=gong;
                            mul/=gong;
                            for(int i=p;i<=wei1;i++) printf("%d ",a[i]);
                            if(zil/mul<1) {
                                for(int i=wei1+1;i<wei;i++) printf("%d+%d/%d ",a[i],zil,mul);
                            }
                            else {
                                for(int i=wei1+1;i<wei;i++) printf("%d ",a[i]+1);
                            }
                            for(int i=wei;i<n;i++) printf("%d ",a[i]);
                            printf("\n");
                        }
                    }
                    }
                }
            }
            else {
                for(int i=zuo+1;i<you;i++) {
                    if(a[i]<jizhun) a[i]=jizhun;
                }
            }
        }
    }
    return 0;
}
