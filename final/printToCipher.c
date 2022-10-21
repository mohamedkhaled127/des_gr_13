
#include <stdio.h>
#include <stdlib.h>

 int num;
   FILE *fcipher;

   void binToHex(int data[],int size){
	   unsigned long long temp=1<<size-1;
	   unsigned long long res=0;
	   for(int i=0;i<size;i=i+4){
	          int val=8*data[i]+4*data[i+1]+2*data[i+2]+data[i+3];

	          fprintf(fcipher,"%x",val);
	      }


   }


void printToCipher (int round , int leftOutput[32],int rightOutput[32],int key[48])
{

   // use appropriate location if you are using MacOS or Linux
	if(round==0)
   fcipher = fopen("cipher.txt","w");

   if(fcipher == NULL)
   {
      printf("Error!");
      exit(1);
   }

   fprintf(fcipher,"%d",round);
   fprintf(fcipher,"%s","             ");
   binToHex(leftOutput,32);
   fprintf(fcipher,"%s","             ");
   binToHex(rightOutput,32);
   fprintf(fcipher,"%s","             ");
   binToHex(key,48);
   fprintf(fcipher,"\n");





}
void printCypherOutput(int res[64]){
	fprintf(fcipher,"%s"," cipher text is : ");
	binToHex(res,64);
}


void closeCipherText(){
	fclose(fcipher);
}
