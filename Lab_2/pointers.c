#include <stdio.h>
int main(){
    int x,y, *px,*py;
    int arr[10];
    printf("%d %d %p %p", x, y,px,py);

    x = 0, y = 0;
    for(int i =0; i<10;i++)
    arr[i]=0;
    
    printf("%p ", (void *) &x);
    printf("%p ", (void *) &y);

    px=&x;
    py=&y;
    printf("%p ", px);
    printf("%p ", py);

    for(int i=0;i<10;i++)
        printf("%d ",*(&arr[0]+i));

    if(arr==&arr[0])
        printf(" addres are same");
        printf(" %p",&arr);
        printf(" %p",&arr[0]);
    return 0;
}