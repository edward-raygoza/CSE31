#include <stdio.h>

/*
    Read a set of values from the user.
    Store the sum in the sum variable and return the number of values read.
*/
int read_values(double *sum) {//pointer
  int values=0,input=0;
  *sum = 0;//pointer
  printf("Enter input values (enter 0 to finish):\n");
  scanf("%d",&input);
  while(input != 0) {
    values++;
    *sum = *sum + input;//pointer added
    scanf("%d",&input);
  }
  return values;
}

int main() {
  double sum=0;
  int values;
  values = read_values(&sum);//reference added
  printf("Average: %G\n",sum/values);
  return 0;
}

