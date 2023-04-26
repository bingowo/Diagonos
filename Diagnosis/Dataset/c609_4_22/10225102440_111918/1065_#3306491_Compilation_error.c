#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int t,i,j,m,n,sign=0;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        double a[50]={0};
        char b[50]={0},s[101]={0};
        m=n=0;
        gets(s);
        for(j=0;j<strlen(s);j++){
            if(s[j]==' ') continue;
            if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                b[n++]=s[j];
                sign=0
            }
            else{
                char c[50]={0};
                int num=0;
                while(s[j]!=' '&&s[j]!=0){
                    c[num++]=s[j++];
                }
                c[num]=0;
                if(m>0&&n>0&&sign==1){
                    double temp=atof(c);
                    n--,m--;
                    switch(b[n]){
                case '+':
                    a[m]=a[m]+temp;
                    break;
                case '-':
                    a[m]=a[m]-temp;
                    break;
                case '*':
                    a[m]=a[m]*temp;
                    break;
                case '/':
                    a[m]=a[m]/temp;
                    break;
                    }
                    m++;
                }
                else {
                    a[m++]=atof(c);
                    sign++;
                }
            }
        }
        while(m>0&&n>0){
            double temp=a[--m];
            n--,m--;
            switch(b[n]){
        case '+':
            a[m]=a[m]+temp;
            break;
        case '-':
            a[m]=a[m]-temp;
            break;
        case '*':
            a[m]=a[m]*temp;
            break;
        case '/':
            a[m]=a[m]*1.0/temp;
            break;
            }
            m++;
        }
        printf("case #%d:\n%lf\n",i,a[0]);
    }
    return 0;
}
