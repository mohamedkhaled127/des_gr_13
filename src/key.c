/*
 the 56 bit key is  0110011001010101000000000111 1111111111010101011001100000
--------------------------------------
1100110010101010000000001110 1111111110101010110011000001
1001100101010100000000011101 1111111101010101100110000011
0110010101010000000001110110 1111110101010110011000001111
1001010101000000000111011001 1111010101011001100000111111
0101010100000000011101100110 1101010101100110000011111111
0101010000000001110110011001 0101010110011000001111111111
0101000000000111011001100101 0101011001100000111111111101
0100000000011101100110010101 0101100110000011111111110101
1000000000111011001100101010 1011001100000111111111101010
0000000011101100110010101010 1100110000011111111110101010
0000001110110011001010101000 0011000001111111111010101011
0000111011001100101010100000 1100000111111111101010101100
0011101100110010101010000000 0000011111111110101010110011
1110110011001010101000000000 0001111111111010101011001100
1011001100101010100000000011 0111111111101010101100110000
0110011001010101000000000111 1111111111010101011001100000
--------------------------------------%
permutation choice 2 vals are
110011101000100111100000111111100111101110011011
100110010000010010001101111010010111111000101101
000101101001010001001000110011111111100000001100
000010110001011000001110110100011111110001010101
001001110001001001001000101001001111000111000100
001011110100011000010110101100011111000101110110
011001010101000000000101101000101111001111100001
000101001100011100010111011011100101110101101011
010110000100101101000000011001101001111100100101
001010000000100101110011101111111110010000111101
010110000110100000101010011101111001110010010101
100000100010000110110011001101011100010010010011
110100011010100010011010101101010010001011010111
110001101000000110110000101111011011001110011011
010000010010100101011100110111000111101011111011
000101101110000001000101110010110111111100001010
 */



#include <stdio.h>

char bin[64];

void hexToBin(char *hexdec)
{
     int i = 0;




    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':

        	strcat(bin,"0000");

            break;

        case '1':

        	strcat(bin,"0001");
        	break;
        case '2':

                	strcat(bin,"0010");
                	break;
        case '3':

                	strcat(bin,"0011");
                	break;
        case '4':

                	strcat(bin,"0100");
                	break;
        case '5':

                	strcat(bin,"0101");
                	break;
        case '6':

                	strcat(bin,"0110");
                	break;
        case '7':

                	strcat(bin,"0111");
                	break;
        case '8':

                	strcat(bin,"1000");
                	break;
        case '9':

                	strcat(bin,"1001");
                	break;
        case 'A':
        case 'a':

                	strcat(bin,"1010");
                	break;
        case 'B':
        case 'b':

                	strcat(bin,"1011");
                	break;
        case 'C':
        case 'c':

                	strcat(bin,"1100");
                	break;
        case 'D':
        case 'd':

                	strcat(bin,"1101");
                	break;
        case 'E':
        case 'e':

                	strcat(bin,"1110");
                	break;
        case 'F':
        case 'f':

                	strcat(bin,"1111");
                	break;

        }
        i++;
    }


}





int PC1[]=
{
    57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

int PC2[] =
{
    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};


int SHIFTS[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };







void circularShift(int arr[], int d, int n,int tempKey[])
{
    // Storing rotated version of array
    int temp[n];

    // Keepig track of the current index
    // of temp[]
    int k = 0;

    // Storing the n - d elements of
    // array arr[] to the front of temp[]
    for (int i = d; i < n; i++) {
        temp[k] = tempKey[i];
        k++;
    }

    // Storing the first d elements of array arr[]
    //  into temp
    for (int i = 0; i < d; i++) {
        temp[k] = tempKey[i];
        k++;
    }

    // Copying the elements of temp[] in arr[]
    // to get the final rotated array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}









// Driver code
void getAllPC2Keys(int PC2ALL[16][48])
{
    FILE* ptr;
    char ch;
    long long binaryKey=0;

    char hexkey[16];
    int keyP1[56];
    int keyP1Left[28];
    int keyP1Right[28];
   int allLeftKeyShifts[16][28];
   int allRightKeyShifts[16][28];
   int allPc2[16][48];


    // Opening file in reading mode
    ptr = fopen("key.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }



    // Printing what is written in file

    // character by character using loop.
    int i=0;
    do {

        ch = fgetc(ptr);
        hexkey[i]=ch;
        i++;


        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);

    // Closing the file
    fclose(ptr);
    hexToBin(hexkey);

   for(int i=0;i<56;i++){
	   keyP1[i]=(int)bin[PC1[i-1]]-48;
   }

   for(int i=0;i<28;i++)
	   keyP1Left[i]=keyP1[i];


   for(int i=28;i<56;i++)
	   keyP1Right[i-28]=keyP1[i];



/*--------------------------------------------------------------------------------------------------------*/
int sum=0;
for(int i=0;i<16;i++){
	sum+=SHIFTS[i];
	circularShift(allLeftKeyShifts[i],sum,28,keyP1Left);
	circularShift(allRightKeyShifts[i],sum,28,keyP1Right);

}









for(int i=0;i<16;i++){
	for(int j=0;j<48;j++){
		if(PC2[j]<=28)
			allPc2[i][j]=allLeftKeyShifts[i][PC2[j-1]];
		else allPc2[i][j]=allRightKeyShifts[i][PC2[j-29]];
	}
}

for(int i=0;i<16;i++){
	for(int j=0;j<48;j++){
		PC2ALL[i][j]=allPc2[i][j];

	}

	}

}


