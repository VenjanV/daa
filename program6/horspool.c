#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 256
int Table[size];

void shifttable(char p[25]){
	int i,m,x;
	m=strlen(p);
	for(i=0;i<size;i++){
		Table[i]=m;
	}
	for(i=0;i<=m-2;i++){
		Table[p[i]]=m-i-1;
	}
}

int horspool(char t[100],char p[25]){
	int m,n,i,k,x;
	m=strlen(p);
	n=strlen(t);
	i=m-1;
	while(i<=n-1){
		k=0;
		while((k<m) && (p[m-1-k]==t[i-k]))
		k=k+1;
		if(k==m)
		return i-m+1;
		else{
			i=i+Table[t[i]];
		}
	}
	return -1;
}

int main(){
	char text[100],pattern[25];
	int res;
	printf("Text : ");
	scanf("%[^\n]",text);
	printf("Pattern : ");
	scanf("%s",pattern);
	shifttable(pattern);
	res=horspool(text,pattern);
	if(res==-1)
	printf("pattern not found\n");
	else
	printf("pattern found at position %d of text\n",res);
	return 0;
}