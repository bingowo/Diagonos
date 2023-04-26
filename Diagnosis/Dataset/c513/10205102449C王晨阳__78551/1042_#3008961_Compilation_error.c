#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

string S[65536];int temp;

void combination(char *p,int n,vector<char>&result);
void combination(char *p);
void sort_print_string(string *in_array, int n);
int cmp(const void*a,const void*b);
void Encrypt(char* keych,char *key);

int main()
{
    int T;char s[17];
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>s;
        for(int y=0;y<65536;y++)
        {
            S[y]={};
        }
        temp=0;
        char target[17]={};
        Encrypt(target,s);
        qsort(target,strlen(target),sizeof(target[1]),cmp);
        cout<<"case #"<<i<<":"<<endl;
        combination(target);
        sort_print_string(S,temp);
    }
    return 0;
}

void combination(char *p)
{
    if(p==NULL) return;

    vector<char> result;
    int length = strlen(p);
    for(int j=1;j<=length;j++)
    {
        combination(p,j,result);
    }
}

void combination(char *p, int n, vector<char>&result)
{
    if(p==NULL) return;

    if(n==0)
    {
        vector<char>::iterator iter = result.begin();
        for(;iter !=result.end();++iter)
        {
            S[temp]+=*iter;
        }
        temp++;
        return;
    }

    if(*p=='\0') return;

    result.push_back(*p);
    combination(p+1,n-1,result);
    result.pop_back();
    combination(p+1,n,result);
}

void sort_print_string(string *in_array, int n)
{
	vector<string> strArray;
	for (int i = 0; i < n; i++)
	{
		strArray.push_back(in_array[i]);
	}
	sort(strArray.begin(), strArray.end());
	vector<string>::iterator st;
	for (st = strArray.begin(); st != strArray.end(); st++)
	{
		cout<<*st<<endl;
	}
}


int cmp(const void*a,const void*b)
{
	return*(char*)a-*(char*)b;
}


void Encrypt(char* keych,char *key)
{
    keych[0]=key[0];
    int i,j=0,k=0,flag;
    for(i=0;key[i]!='\0';i++)
    {
        flag=1;
        for(k=0;k<j+1;k++)
        {
            if(key[i]==keych[k])
                flag=0;
        }
        if(flag)
        {
            j=j+1;
            keych[j]=key[i];
        }
    }
    keych[j+1]='\0';
}