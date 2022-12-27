#include<stdio.h>
#include <stdlib.h>

struct Array
{
    int *arr;
    int index, size;
};

/*Array Implimentation Function*/
void intialize(struct Array *a);
int create(struct Array *a);
int input(struct Array *a);
void display(struct Array a);
/*Array Implimentation Function*/

/*SunSet_View*/
int SunSet_View(struct Array a);

int main(){
    struct Array array;
    intialize(&array);
    create(&array);
    SunSet_View(array);
    
    return 0;
}

void intialize(struct Array *a)
{
    a->index = -1;
    printf("Enter the Number of Buildings : ");
    scanf("%d", &(a->size));
    printf("%d\n", a->size);
}

int create(struct Array *a)
{
    a->arr = (int *)malloc(a->size * sizeof(int));
    input(a);
}

int input(struct Array *a)
{
    int element;
    printf("Enter the Lenghts of Building from west to east : \n");
    for (int i = 0; i < a->size; ++i)
    {
        scanf("%d", &element);
        a->index++;
        *(a->arr + a->index) = element;
    }
}

void display(struct Array a)
{
    for (int i = 0; i < a.size; ++i)
    {
        printf("%d ", a.arr[i]);
    }
    printf("\n");
}

int SunSet_View(struct Array a){
    int count = 0;
    printf("The building having view to sunset are : ");
    for(int i = 0; i < a.size; i++){
        if(i == 0){
            count++;
            printf("%d ", i+1);
        }else if(i>0 && i < a.size-1){
            if(a.arr[i] < a.arr[i+1]){
                printf("%d ", i+2);
                count++;
            }
        }
    }
    printf("\nThe number of buiding watching Sunset : %d\n", count);
}