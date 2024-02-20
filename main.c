#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"
//lemur
int main() {
    StrList* myList = StrList_alloc();
    int choice;
    //int size;//trying dinamiic array size for each word
    char data[100]; // מחרוזת לקליטת נתונים מהמשתמש

    while (1) {
        if (scanf("%d", &choice) != 1){
            printf("Invalid input.");
            break;
        }

        switch(choice) {
            
            case 1:
                char a;
                getchar();//i have added trying to fix a bug
                scanf("%c", &a);
                    //printf("הכנס מספר מחרוזות להכנס לרשימה: ");
                    int numStrings;
                    scanf("%d", &numStrings);
                    getchar(); // Consume newline character from the previous scanf

                    //printf("הכנס את המחרוזות (הקלד 0 כדי לסיים):\n");
                    for (int i = 0; i < numStrings; ++i) {
                        scanf("%s", data);
                        if (strcmp(data, "0") == 0) {
                        break; // Exit loop if user enters "0"
                        }
                    StrList_insertLast(myList, data);
                    }
                break;

            case 2:
                //printf("הכנס אינדקס: ");
                int index;
                scanf("%d", &index);
                //printf("הכנס מחרוזת: ");
                scanf("%s", data);
                StrList_insertAt(myList, data, index);
                break;
            case 3:
                //printf("הרשימה היא:\n");
                StrList_print(myList);
                break;
            case 4:
                printf("%zu\n", StrList_size(myList));
                break;
            case 5:
                //printf("הכנס אינדקס: ");
                scanf("%d", &index);
                StrList_printAt(myList, index);
                break;
            case 6:
                printf("%d\n", StrList_printLen(myList));
                break;
            case 7:
                //printf("הכנס מחרוזת לחיפוש: ");
                scanf("%s", data);
                printf("%d\n", StrList_count(myList, data));
                break;
            case 8:
                //printf("הכנס מחרוזת למחיקה: ");
                scanf("%s", data);
                StrList_remove(myList, data);
                break;
            case 9:
                //printf("הכנס אינדקס למחיקה: ");
                scanf("%d", &index);
                StrList_removeAt(myList, index);
                break;
            case 10:
                StrList_reverse(myList);
                //printf("הרשימה הופכה בהצלחה.\n");
                break;
            case 11:
                StrList_free(myList);
                myList = StrList_alloc();
                //printf("הרשימה נמחקה בהצלחה.\n");
                break;
            case 12:
                StrList_sort(myList);
                //printf("הרשימה סודרה לפי סדר לקסיקוגרפי.\n");
                break;
            case 13:
                if (StrList_isSorted(myList)) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            case 0:
                //printf("יוצא מהתוכנית.\n");
                StrList_free(myList);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
