#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"
//lemur
int main() {
    StrList* myList = StrList_alloc();
    int choice;
    char data[200];

    while (1) {
        if (scanf("%d", &choice) != 1){
            printf("Invalid input.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        switch(choice) {
            
            case 1:
                int numStrings;//number of strings to be entered
                scanf("%d", &numStrings);
                getchar(); // Consume newline character from the previous scanf

                //if suddenly entered 0 to end program
                for (int i = 0; i < numStrings; ++i) {
                    scanf("%s", data);
                    StrList_insertLast(myList, data);
                }
                break;

            case 2:
                int index;//index to enter data at
                scanf("%d", &index);
                scanf("%s", data);//string to be added at this index
                StrList_insertAt(myList, data, index);
                break;
            case 3:
                StrList_print(myList);//printing the list
                break;
            case 4:
                printf("%zu\n", StrList_size(myList));//printing list's size, how many strings it contains.
                break;
            case 5:
                scanf("%d", &index);//index of list's content to print
                StrList_printAt(myList, index);
                break;
            case 6:
                printf("%d\n", StrList_printLen(myList));//prints the amount of chars in list
                break;
            case 7:
                scanf("%s", data);//string to be searched
                printf("%d\n", StrList_count(myList, data));
                break;
            case 8:
                scanf("%s", data);//string to be deleted
                StrList_remove(myList, data);
                break;
            case 9:
                scanf("%d", &index);//index of string to be removed
                StrList_removeAt(myList, index);
                break;
            case 10:
                StrList_reverse(myList);//calling reverse function
                break;
            case 11:
                StrList_free(myList);//deleting current list
                myList = StrList_alloc();//and creating a new empty one
                break;
            case 12:
                StrList_sort(myList);//calling lexicographic sorting function
                break;
            case 13:
                if (StrList_isSorted(myList)) {//simple condition
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            case 0:
                StrList_free(myList);//exiting the program, therfore freeing allocated memory
                return 0;
            default:
                break;
        }
    }

    return 0;
}
