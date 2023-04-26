#include <stdio.h>

int main(){
    int system;
    scanf("%d",&system);
    char a[1000];
    int i=0,re=0;
    scanf("%s",a);
    while(a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
    {
        if(a[i]>='0'&&a[i]<='9'){

            re=re*system+a[i]-'0';
        }          //a[i]-'0'利用ASCII码值差值求该位的值
        else if(a[i]>='a'&&a[i]<='f'){

            re=re*system+a[i]+10-'a';
        }          //a[i]-'a'利用ASCII码值差值求该位的值
        else if(a[i]>='A'&&a[i]<='F'){

            re=re*system+a[i]+10-'A';
        }          //a[i]-'A'利用ASCII码值差值求该位的值
        i++;       //从最高位依次往低一位遍历

    }char sex[36] = {'0','1','2','3','4',
                     '5','6','7','8','9',
                     'A','B','C','D','E',
                     'F','G','H','I','J',
                     'K','L','M','N','O',
                     'P','Q','R','S','T',
                     'U','V','W','X','Y','Z'};
    int arr[100];
    int b;
        scanf("%d",&b);
        int k = 0;int m;
        while(re){
            int yu;yu = re%b;arr[k++] = yu;re = re/b;
        }
        for(i = k -1;i>=0;i--){
            m = arr[i];
            printf("%c",sex[m]);
        }printf("\n");

}