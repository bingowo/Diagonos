#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char table[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char padding_char='=';

int findchr(char *array,char ch){
    for(int i=0;i<strlen(array);i++){
        if(array[i]==ch){
            return i;//返回位置
        }
    }
    return 0;
}

void base64_encode(char *src,char *result){

    int fill_bit=0;
    int data_length;
    int result_length;
    int index;
    data_length=strlen(src);
    //printf("length:%d\n",data_length);
    fill_bit=((3-strlen(src)%3)%3);
    //printf("fill_bit:%d\n",fill_bit);
    for(int k=0;k<fill_bit;k++){
        src[data_length+k]='\0';
    }
    int j=0;
    //printf("enfill_data_length:%d\n",strlen(src));
    //��Ϊǰ����������'\0'���Ի�����ʾ4������ǰ���ĳ�'\1'�ͳ���6��
    for(int i=0;i<data_length;i+=3){
        index=src[i]>>2;//�ѵ�һ����������2λ��Ҳ����ȡǰ6bit
        //printf("index:%d\n",index);
        result[j++]=table[index];
        index=((src[i]&3)<<4)+(src[i+1]>>4);//&3������ȡ��һ��q�ĺ���λ��Ȼ������4λ���ټ��Ϻ�һ��w����4λ�õ���ǰ��λһ��6λ
        //printf("index:%d\n",index);
        result[j++]=table[index];
        index=((src[i+1]&15)<<2)+(src[i+2]>>6);
        //printf("index:%d\n",index);
        result[j++]=table[index];
        index=(src[i+2]&63);
        //printf("index:%d\n",index);
        result[j++]=table[index];
        //<< >> �����������ȼ�����+ -��ע��������
    }
    result_length=strlen(result);
    for(int k=0;k<fill_bit;k++){
        result[result_length-1-k]=padding_char; //��'\0'�ַ��滻Ϊ=
    }
}

void base64_decode(char *src,char *result){
    int base_len;
    int j=0;
    base_len=strlen(src);
    //printf("length:%d\n",base_len);
    for(int i=0;i<base_len;i++){
        if(src[i]==padding_char)
            src[i]='A';
    }
    //printf("%s\n",src);
    for(int i=0;i<base_len;i+=4){
        //printf("index_in_table:%d\n",findchr(table,src[i]));
        //printf("index_in_table:%d\n",findchr(table,src[i+1]));
        //printf("index_in_table:%d\n",findchr(table,src[i+2]));
        //printf("index_in_table:%d\n",findchr(table,src[i+3]));
        result[j++]=(findchr(table,src[i])<<2)+((findchr(table,src[i+1])& 0xF0)>>4);
        result[j++]=((findchr(table,src[i+1])& 0x0F)<<4)+((findchr(table,src[i+2])& 0x3C)>>2);
        result[j++]=((findchr(table,src[i+2])& 0x03)<<6)+(findchr(table,src[i+3]));
        //ע��������table��Ӧ�ı��룬����ԭ����ascii��
        //��λ���������ȼ�����λ����������ע������
    }
}

int main(   )
{
    //char flag[]="YWV1Y3Rme2YzNzVmOWI3ZjczMGFjNmNjYWQ4YTVmYTA1MWY2NDJlfQ==";
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char words[100];
        scanf("%s",words);
        char en_words[100]="";
    //char de_words[100]="";
        base64_encode(words,en_words);
        printf("case #%d:\n""%s\n",i,en_words);
        //base64_decode(words,de_words);//解码
    //printf("decode:%s\n",de_words);
    }
        return 0;
}