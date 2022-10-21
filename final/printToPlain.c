
#include <stdio.h>
#include <stdlib.h>


   FILE *fplain;

   void binpToHex(int data[],int size){
	   unsigned long long temp=1<<size-1;
	   unsigned long long res=0;
	   for(int i=0;i<size;i=i+4){
	          int val=8*data[i]+4*data[i+1]+2*data[i+2]+data[i+3];

	          fprintf(fplain,"%x",val);
	      }


   }


void printToPlain (int round , int leftOutput[32],int rightOutput[32],int key[48])
{

   // use appropriate location if you are using MacOS or Linux
	if(round==0 &&!fplain)
   fplain = fopen("plain.txt","w");

   if(fplain == NULL)
   {
      printf("Error!");
      exit(1);
   }

   fprintf(fplain,"%d",round);
   fprintf(fplain,"%s","             ");
   binpToHex(leftOutput,32);
   fprintf(fplain,"%s","             ");
   binpToHex(rightOutput,32);
   fprintf(fplain,"%s","             ");
   binpToHex(key,48);
   fprintf(fplain,"\n");





}
void printPlainOutput(int res[64]){
	fprintf(fplain,"%s"," plain text is : ");
	binpToHex(res,64);
	fprintf(fplain,"\n");
}


void closePlainText(){
	fclose(fplain);
}
