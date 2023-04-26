#include <stdio.h>
#include <string.h>
int main() {
    int N;
    char a[501],b[501];
    int ret[552]={0};
    scanf("%s%s%d",a,b,&N);
    int len1= strlen(a);
    int len2= strlen(b);
    int sign1=len1,sign2=len2,sign=0;
    char *p1,*p2;
    p1=strchr(a,'.');
    p2= strchr(b,'.');
    int len=len2<len1?len2:len1;
    if(p1!=NULL){
        sign1=p1-a;
    }
    if(p2!=NULL){
        sign2=p2-b;
    }
    if(sign2>sign1){
        sign=1;
    } else if(sign1==sign2){
        int q=0;
        while (a[q]==b[q]&&q<len){
            q++;
        }
        if(q<len&&b[q]>a[q]){
            sign=1;
        }else if(q==len){
            if(len2>len1){
                sign=1;
            } else if(len1==len2){
                sign=2;
            }
        }
    }
    if(sign!=2){
        if(sign==0){
            for(int i=sign1-1,j=499;i>=0;i--,j--){
                ret[j]=a[i]-'0';
            }
            if(sign1!=len1){
                for(int i=sign1+1,j=500;i<len1&&j<=550;i++,j++){
                    ret[j]=a[i]-'0';
                }
            }
            for(int i=0,j=499-(sign2-1);i<len2&&j<=550;i++,j++){
                if(b[i]=='.'){
                    j--;
                    continue;
                }
                int t=b[i]-'0';
                if(ret[j]<t){
                    ret[j]+=10;
                    ret[j-1]--;
                    int j2=j-1;
                    while (ret[j2]<0){
                        ret[j2-1]--;
                        ret[j2]+=10;
                        j2--;
                    }
                }
                ret[j]=ret[j]-t;
            }
        }else{
            for(int i=sign2-1,j=499;i>=0;i--,j--){
                ret[j]=b[i]-'0';
            }
            if(sign2!=len2){
                for(int i=sign2+1,j=500;i<len2&&j<=550;i++,j++){
                    ret[j]=b[i]-'0';
                }
            }
            for(int i=0,j=499-(sign1-1);i<len1&&j<=550;i++,j++){
                if(a[i]=='.'){
                    j--;
                    continue;
                }
                int t=a[i]-'0';
                if(ret[j]<t){
                    ret[j]+=10;
                    ret[j-1]--;
                    int j2=j-1;
                    while (ret[j2]<0){
                        ret[j2-1]--;
                        ret[j2]+=10;
                        j2--;
                    }
                }
                ret[j]=ret[j]-t;
            }
        }
        int m=500+N,carry=0;
        if(ret[m]>=5){
            do{
                m--;
                ret[m]++;
                carry=ret[m]/10;
                ret[m]=ret[m]%10;
            }while (carry);
        }
        int i=0;
        if(sign==1){
            printf("-");
        }
        while (ret[i]==0&&i<500){
            i++;
        }
        if(i<500){
            for(;i<500;i++){
                printf("%d",ret[i]);
            }
        }else{
            printf("0");
        }
        printf(".");
        for(;i<500+N;i++){
            printf("%d",ret[i]);
        }
        printf("\n");
    }else{
        printf("0.");
        while (N--){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
