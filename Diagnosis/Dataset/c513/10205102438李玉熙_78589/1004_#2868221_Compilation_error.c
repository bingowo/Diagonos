#include<bits/stdc++.h>
using namespace std;
int main()
{
        char str[101];
        while(scanf("%s",str)!=EOF){
                int flag=0;
                for(int i=0;i<strlen(str);i++){
                        if(str[i]=='.') flag=1;
                }
                if(flag==1){
                        double n=atof(str);
                        int p=sizeof(n);
                        unsigned char *e=(unsigned char *)&n;
                        while(p--){
                                printf("%02x ",*e++);
                        }
                        printf("\n");
                }
                else if(flag==0){
                        int n=atoi(str);
                        int p=sizeof(n);
                        unsigned char*e=(unsigned char *)&n;
                        while(p--){
                                printf("%02x ",*e++);
                        }
                        printf("\n");
                }
        }
}
