

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//declaration of a structure which comprises of datatypes int float and pointer to itself
//4 byte, 4byte and 8 byte data types below
struct Node {
    int iValue;
    float fValue ;
    struct Node *next; //pointer variable(undefined value) of Node datatype
};

int main() {

    //malloc maps a memory address to the struct node pointer head
    //allocates memory to head
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));

    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
	printf("Address of head %p\n", &head);//prints memory address of head
    printf("Value of head %p\n", head);//print value of head
    printf("Address of iValue %p\n", &(head -> iValue));//memory address of iValue of head
    printf("Address of fValue %p\n", &(head -> fValue));
    printf("Address of next %p\n", &(head -> next));
	return 0;
}