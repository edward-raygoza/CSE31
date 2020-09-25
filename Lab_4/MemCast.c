#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i=0; i<4; i++){
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);

    four_c = (char*)four_ints;
	}
	for(i=0; i<4; i++){
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.
			// Add your code for the exercises here:
	printf("\nValue of four_ints[0]:%x\n",four_ints[0]);
	printf("Value of four_ints[1]:%x\n\n",four_ints[1]);

	printf("Address of four_ints:%p\n",four_ints);
	printf("Address of four_c:%p\n\n",four_c);
	}
	for(i=0; i<4; i++){
   printf("Address of four_int[%d]:%p\n", i,&four_ints[i]);
	 printf("Value of four_int[%d]:%ls\n", i,&four_ints[i]);
	}
	printf("\n");
	for(i=0; i<4; i++){
	printf("Address of four_c[%d]:%p\n",i,&four_c[i]);
	printf("Value of four_c[%d]:%s\n", i,&four_c[i]);
	}
	printf("\n");


	return 0;
}


