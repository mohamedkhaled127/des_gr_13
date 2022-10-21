/*
 ============================================================================
 Name        : des-13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "key.h"
#include "initialPermutation.h"

int allPC216[16][48];
int inputSliced[64]={0};
int outputSliced[64]={0};
int leftOutputSliced[32];
int rightOutputSliced[32];
int outExpansion[48];
int sboxOutput[32];
int outputPermutation[32];
int bitSwap[64];
int cipherBinary[64];

FILE *out;




void convertToBinary(int n)
{
    int k, m;
    for (int i = 7; i >= 0; i--)
    {
        m = 1 << i;
        k = n & m;

        if (k == 0) {
            fprintf(out, "0");
        }
        else {
            fprintf(out, "1");
        }
    }
}








int main(){

	FILE* inp = fopen("input.txt", "rb");
	    out = fopen("bits.txt", "wb+");
	    int n=8;
	    char ch;
	    int i = n * 8;

	    while (i)
	    {
	        ch = fgetc(inp);
	        if (ch == -1) {
	            break;
	        }
	        i--;
	        convertToBinary(ch);
	    }
	    fclose(out);
	    fclose(inp);

	    //input text reading
	/*-------------------------------------------------------*/
		getAllPC2Keys(allPC216);
	   /* printf("\n");
		for(int i=0;i<16;i++){
			for(int j=0;j<48;j++){
				printf("%d",allPC216[i][j]);
			}
			printf("\n");
			}*/

	    /*key reading*/
	    /*-----------------------------------------------------------*/

	    inp = fopen("bits.txt", "r");

	    if (NULL == inp) {
	        printf("file can't be opened \n");
	    }



	    // Printing what is written in file

	    // character by character using loop.
	    int j=0;
	    do {

	        ch = fgetc(inp);
	        int temp=(int)ch-48;
	        inputSliced[j]=temp;
	        j++;

	        if(j==64){
	        	j=0;
	        	initialPermutation(inputSliced,outputSliced);  //initial permutation
	        	/*for(int ii=0;ii<64;ii++){
	        		printf("%d",outputSliced[ii]);

	        	}
	        	printf("\n");*/

	        	for(int ii=0;ii<32;ii++){
	        		leftOutputSliced[ii]=outputSliced[ii];
	        		rightOutputSliced[ii]=outputSliced[ii+32];

	        	}/*
	        	for(int ii=0;ii<32;ii++)
	        		printf("%d",leftOutputSliced[ii]);
	        		*/

	        	/*printf("rigght ");


	        	for(int ii=0;ii<32;ii++)
	        		       printf("%d",rightOutputSliced[ii]);*/


         //  printf("\n");

for(int rounds=0;rounds<16;rounds++){
	        	exp_Permutation(rightOutputSliced,outExpansion); //expansion permutation

	        	/*for(int ii=0;ii<48;ii++)
	        		printf("%d",outExpansion[ii]);
	        	printf("\n");*/
	        	for(int k=0;k<48;k++){
	        		outExpansion[k]=outExpansion[k] ^ allPC216[rounds][k];
	        		//printf("%d",outExpansion[k]);
	        	}
	        	//printf("\n");

	        	Sbox(outExpansion,sboxOutput);  //sbox

	          /*	for(int k=0;k<32;k++)
	        	     printf("%d",sboxOutput[k]);*/



	          	permutation(sboxOutput, outputPermutation); //permutation

	          	//printf("\n");

	        	//for(int k=0;k<32;k++)
	        	     // printf("%d",outputPermutation[k]);
              //  printf("\n");

	        	int *rightArr=outputPermutation;
	        	for(int k=0;k<32;k++)
	        		rightArr[k]=rightArr[k] ^ leftOutputSliced[k];



	        	/*for(int k=0;k<32;k++)
	        		   printf("%d",rightArr[k]);*/




	        	for(int k=0;k<32;k++) //left = right
	        		leftOutputSliced[k]=rightOutputSliced[k];

	        	for(int k=0;k<32;k++)  //righht =xor output
	        		      rightOutputSliced[k]=rightArr[k];


               // printf("\n");
                for(int k=0;k<32;k++)
                	printf("%d",leftOutputSliced[k]);
                printf(" ");
                for(int k=0;k<32;k++)
                               	printf("%d",rightOutputSliced[k]);
                printf("\n");
                printToCipher(rounds,leftOutputSliced,rightOutputSliced,allPC216[rounds]);


}
printf("\n");

for(int k=0;k<32;k++){   //32 bit swap
	bitSwap[k]=rightOutputSliced[k];
	bitSwap[k+32]=leftOutputSliced[k];
}
for(int k=0;k<64;k++)
	printf("%d",bitSwap[k]);

inversePermutation(bitSwap,cipherBinary);

printf("\n");
for(int k=0;k<64;k++)
	printf("%d",cipherBinary[k]);



/*----------------------------------------------------------------------------------------------*/
printCypherOutput(cipherBinary);
printf("\n","encryption finished");


initialPermutation(cipherBinary,outputSliced);  //initial permutation
	        	/*for(int ii=0;ii<64;ii++){
	        		printf("%d",outputSliced[ii]);

	        	}
	        	printf("\n");*/


for(int ii=0;ii<32;ii++){
        		leftOutputSliced[ii]=outputSliced[ii];
        		rightOutputSliced[ii]=outputSliced[ii+32];

        	}




for(int rounds=15;rounds>=0;rounds--){
	        	exp_Permutation(rightOutputSliced,outExpansion); //expansion permutation

	        	/*for(int ii=0;ii<48;ii++)
	        		printf("%d",outExpansion[ii]);
	        	printf("\n");*/
	        	for(int k=0;k<48;k++){
	        		outExpansion[k]=outExpansion[k] ^ allPC216[rounds][k];
	        		//printf("%d",outExpansion[k]);
	        	}
	        	//printf("\n");

	        	Sbox(outExpansion,sboxOutput);  //sbox

	          /*	for(int k=0;k<32;k++)
	        	     printf("%d",sboxOutput[k]);*/



	          	permutation(sboxOutput, outputPermutation); //permutation

	          	//printf("\n");

	        	//for(int k=0;k<32;k++)
	        	     // printf("%d",outputPermutation[k]);
              //  printf("\n");

	        	int *rightArr=outputPermutation;
	        	for(int k=0;k<32;k++)
	        		rightArr[k]=rightArr[k] ^ leftOutputSliced[k];



	        	/*for(int k=0;k<32;k++)
	        		   printf("%d",rightArr[k]);*/




	        	for(int k=0;k<32;k++) //left = right
	        		leftOutputSliced[k]=rightOutputSliced[k];

	        	for(int k=0;k<32;k++)  //righht =xor output
	        		      rightOutputSliced[k]=rightArr[k];


               // printf("\n");
                for(int k=0;k<32;k++)
                	printf("%d",leftOutputSliced[k]);
                printf(" ");
                for(int k=0;k<32;k++)
                               	printf("%d",rightOutputSliced[k]);
                printf("\n");
                printToPlain(rounds-15,leftOutputSliced,rightOutputSliced,allPC216[rounds]);

}
printf("\n");

for(int k=0;k<32;k++){   //32 bit swap
	bitSwap[k]=rightOutputSliced[k];
	bitSwap[k+32]=leftOutputSliced[k];
}
for(int k=0;k<64;k++)
	printf("%d",bitSwap[k]);

inversePermutation(bitSwap,cipherBinary);

printf("\n");
for(int k=0;k<64;k++)
	printf("%d",cipherBinary[k]);

printPlainOutput(cipherBinary);

/*----------------------------------------------------------------------------------------------*/
printf("\n","decryption finished");

























	        }


	    } while (ch != EOF);

	    // Closing the file
	    closeCipherText();
	    closePlainText();
	    fclose(inp);




}
