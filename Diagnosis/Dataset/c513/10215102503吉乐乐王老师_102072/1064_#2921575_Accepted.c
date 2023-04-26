#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char s[]){
    int i=0,j=strlen(s)-1;
    while(i<j){
        char t=s[i];
        s[i]=s[j];
        s[j]=t;
        i++;j--;
    }
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s[100];
        gets(s);
        int n=strlen(s)-1;
        double nums[100];double *pn=nums;
        while(n>=0){
            char temp[11];char *p=temp;
            while(n>=0&&s[n]!='-'&&s[n]!='+'&&s[n]!='*'&&s[n]!='/'){
                if(s[n]==' '){
                    *p='\0';
                    reverse(temp);
                    *pn=atof(temp);
                    p=temp;pn++;
                }
                else {*p=s[n];p++;}
                n--;
            }
            char ope=s[n];n--;
            double num1=*(--pn);
            double num2=*(--pn);
            switch (ope)
            {
            case ('+'):
                *pn=num1+num2;
                break;
            case ('-'):
                *pn=num1-num2;
                break;
            case ('*'):
                *pn=num1*num2;
                break;
            case ('/'):
                *pn=num1/num2;
                break;
            }
            pn++;
            n--;
        }
        printf("case #%d:\n%.6lf\n",cas++,nums[0]);
    }
}