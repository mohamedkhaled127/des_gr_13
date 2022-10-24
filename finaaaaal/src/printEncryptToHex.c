
#include <stdio.h>
#include <stdlib.h>


   FILE *encrToHex;

   void binEncryptToHex(int data[],int size){
	   unsigned long long temp=1<<size-1;
	   unsigned long long res=0;
	   for(int i=0;i<size;i=i+4){
	          int val=8*data[i]+4*data[i+1]+2*data[i+2]+data[i+3];

	          fprintf(encrToHex,"%x",val);
	      }


   }



void printEncrToHex(int res[64]){
	//fprintf(fplain,"%s"," plain text is : ");
	if(!encrToHex)
		encrToHex = fopen("encrypt_hex.txt","w");
	binEncryptToHex(res,64);
	//fprintf(fplain,"\n");
}


void closeEncHexText(){
	fclose(encrToHex);
}
