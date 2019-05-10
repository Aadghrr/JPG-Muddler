#include<stdio.h>
#include<stdlib.h>
unsigned char* muddle(unsigned char *buff,long len,unsigned int n);
int main(int argc,char *argv[]){
	FILE *img = fopen(argv[1],"rb");
	unsigned char *buff;long len;int n = atoi(argv[3]);
	if(img){
		fseek(img,0,SEEK_END);
		len = ftell(img);
		fseek(img,0,SEEK_SET);
		buff = malloc(len);
		if (buff){
			fread(buff,sizeof(unsigned char),len,img);}
		fclose(img);}
	if(buff){
		buff = muddle(buff,len,n);
		FILE *write =fopen(argv[2],"wb");
		fwrite(buff,1,len,write);
		fclose(write);}return 0;}
unsigned char* muddle(unsigned char *buff,long len,unsigned int n){
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0;i<=n;i++){
		long j = 1500 + rand()%(len-1500); 
		buff[j] = (unsigned char)rand() % 16;}
	return buff;}

