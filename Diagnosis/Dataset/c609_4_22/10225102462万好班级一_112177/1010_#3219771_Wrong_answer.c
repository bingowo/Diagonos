#include <stdio.h>

int main() {

    int a,b;
    scanf("%d %d",&a,&b);
    char sex[36] = {'0','1','2','3','4',
                    '5','6','7','8','9',
                    'A','B','C','D','E',
                    'F','G','H','I','J',
                    'K','L','M','N','O',
                    'P','Q','R','S','T',
                    'U','V','W','X','Y','Z'};

    int arr[100];




        int i = 0;int m;
        while(a){
            if(a%b >=0)
            {int yu;yu = a%b;arr[i++] = yu;a = a/b;}
            else
            {int yu;yu = -b+a%b;arr[i++] = yu;a = a/b +1;}
        }
        for(i = i -1;i>=0;i--){
            m = arr[i];
            printf("%c",sex[m]);
        }
    }
