// #include "StrList.h" // Include the corresponding header file

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct _StrList {
//     char** data; // Array of pointers to strings
//     size_t size; // Number of elements in the list
// } StrList;


// StrList* StrList_alloc() {
//     StrList* newList = (StrList*)malloc(sizeof(StrList));
//     if (newList) {
//         newList->data = NULL;
//         newList->size = 0;
//     }
//     return newList;
// }

// // Function to free the memory and resources allocated to StrList
// void StrList_free(StrList* StrList) {
//     if (StrList) {
//         for (size_t i = 0; i < StrList->size; ++i) {
//             free(StrList->data[i]);
//         }
//         free(StrList->data);
//         free(StrList);
//     }
// }

// // Function to return the number of elements in the StrList
// size_t StrList_size(const StrList* StrList) {
//     return StrList ? StrList->size : 0;
// }

// // Function to insert an element in the end of the StrList
// void StrList_insertLast(StrList* StrList, const char* data) {
//     if (StrList && data) {
//         size_t newSize = StrList->size + 1;
//         char** newData = (char**)realloc(StrList->data, newSize * sizeof(char*));
//         if (newData) {
//             StrList->data = newData;
//             StrList->data[StrList->size] = strdup(data);
//             StrList->size = newSize;
//         }
//     }
// }

// // Function to insert an element at a given index
// void StrList_insertAt(StrList* StrList, const char* data, int index) {
//     if (StrList && data && index >= 0 && (size_t)index <= StrList->size) {
//         size_t newSize = StrList->size + 1;
//         char** newData = (char**)realloc(StrList->data, newSize * sizeof(char*));
//         if (newData) {
//             StrList->data = newData;
//             // Shift elements to make room for the new one
//             for (size_t i = StrList->size; i > (size_t)index; --i) {
//                 StrList->data[i] = StrList->data[i - 1];
//             }
//             StrList->data[index] = strdup(data);
//             StrList->size = newSize;
//         }
//     }
// }

// // Function to return the first data in the StrList
// char* StrList_firstData(const StrList* StrList) {
//     return (StrList && StrList->size > 0) ? StrList->data[0] : NULL;
// }

// // Function to print the StrList to the standard output
// void StrList_print(const StrList* StrList) {
//     if (StrList) {
//         for (size_t i = 0; i < StrList->size; ++i) {
//             printf("%s\n", StrList->data[i]);
//         }
//     }
// }

// // Function to print the word at the given index to the standard output
// void StrList_printAt(const StrList* Strlist, int index) {
//     if (Strlist && index >= 0 && (size_t)index < Strlist->size) {
//         printf("%s\n", Strlist->data[index]);
//     }
// }

// // Function to return the amount of characters in the list
// int StrList_printLen(const StrList* Strlist) {
//     int total_len = 0;
//     if (Strlist) {
//         for (size_t i = 0; i < Strlist->size; ++i) {
//             total_len += strlen(Strlist->data[i]);
//         }
//     }
//     return total_len;
// }

// // Function to count the number of times a string exists in the list
// int StrList_count(StrList* StrList, const char* data) {
//     int count = 0;
//     if (StrList && data) {
//         for (size_t i = 0; i < StrList->size; ++i) {
//             if (strcmp(StrList->data[i], data) == 0) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // Function to remove all appearances of a string in the list
// void StrList_remove(StrList* StrList, const char* data) {
//     if (StrList && data) {
//         for (int i = StrList->size - 1; i >= 0; --i) {
//             if (strcmp(StrList->data[i], data) == 0) {
//                 free(StrList->data[i]);
//                 for (size_t j = i; j < StrList->size - 1; ++j) {
//                     StrList->data[j] = StrList->data[j + 1];
//                 }
//                 StrList->size--;
//             }
//         }
//     }
// }

// // Function to remove the string at a given index
// void StrList_removeAt(StrList* StrList, int index) {
//     if (StrList && index >= 0 && (size_t)index < StrList->size) {
//         free(StrList->data[index]);
//         for (size_t i = index; i < StrList->size - 1; ++i) {
//             StrList->data[i] = StrList->data[i + 1];
//         }
//         StrList->size--;
//     }
// }

// // Function to check if two StrLists have the same elements
// int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
//     if (!StrList1 || !StrList2 || StrList1->size != StrList2->size) {
//         return 0;
//     }

//     for (size_t i = 0; i < StrList1->size; ++i) {
//         if (strcmp(StrList1->data[i], StrList2->data[i]) != 0) {
//             return 0;
//         }
//     }

//     return 1;
// }

// // Function to clone the given StrList
// StrList* StrList_clone(const StrList* Strlist) {
//     if (!Strlist) {
//         return NULL;
//     }

//     StrList* newList = StrList_alloc();
//     if (!newList) {
//         return NULL;
//     }

//     for (size_t i = 0; i < Strlist->size; ++i) {
//         StrList_insertLast(newList, Strlist->data[i]);
//     }

//     return newList;
// }

// // Function to reverse the given StrList
// void StrList_reverse(StrList* StrList) {
//     if (StrList) {
//         size_t left = 0;
//         size_t right = StrList->size - 1;
//         while (left < right) {
//             char* temp = StrList->data[left];
//             StrList->data[left] = StrList->data[right];
//             StrList->data[right] = temp;
//             left++;
//             right--;
//         }
//     }
// }

// // Comparison function for qsort
// int compareStrings(const void* a, const void* b) {
//     const char* stringA = *(const char**)a;
//     const char* stringB = *(const char**)b;
//     return strcmp(stringA, stringB);
// }
// // Function to sort the given StrList in lexicographical order
// void StrList_sort(StrList* StrList) {
//     if (StrList) {
//         qsort(StrList->data, StrList->size, sizeof(char*), compareStrings);
//     }
// }

// // Function to check if the given StrList is sorted in lexicographical order
// int StrList_isSorted(StrList* StrList) {
//     if (StrList) {
//         for (size_t i = 0; i < StrList->size - 1; ++i) {
//             if (strcmp(StrList->data[i], StrList->data[i + 1]) > 0) {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     return 0;
// }
#include "StrList.h"
#include <stdio.h>
#include <string.h>

// Define a node structure for StrList
typedef struct _Node {
    char* data; // String data
    struct _Node* next; // Pointer to the next node
} Node;

// Define the StrList structure
struct _StrList {
    Node* head; // Pointer to the head node
    size_t size; // Number of elements in the list
};

// Function to allocate a new empty StrList
StrList* StrList_alloc() {
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList) {
        newList->head = NULL;
        newList->size = 0;
    }
    return newList;
}

// Function to free the memory and resources allocated to StrList
void StrList_free(StrList* StrList) {
    if (StrList) {
        Node* current = StrList->head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->data);
            free(temp);
        }
        free(StrList);
    }
}

// Function to insert an element at the end of the StrList
void StrList_insertLast(StrList* StrList, const char* data) {
    if (StrList) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode) {
            newNode->data = strdup(data); // Duplicate the string
            newNode->next = NULL;

            if (StrList->head == NULL) {
                StrList->head = newNode;
            } else {
                Node* current = StrList->head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
            StrList->size++;
        }
    }
}

// Function to return the number of elements in the StrList
size_t StrList_size(const StrList* StrList) {
    return (StrList != NULL) ? StrList->size : 0;
}

// Function to print the StrList to the standard output
void StrList_print(const StrList* StrList) {
    if (StrList) {
        Node* current = StrList->head;
        while (current != NULL) {
            printf("%s", current->data);
            if ((current!=NULL) && (current -> next !=NULL)) printf(" ");
            current = current->next;
        }
        printf("\n");
    }
}

// Function to insert an element at a given index in the StrList
void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if (StrList && index >= 0 && index <= StrList->size) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode) {
            newNode->data = strdup(data); // Duplicate the string
            newNode->next = NULL;

            if (index == 0) {
                newNode->next = StrList->head;
                StrList->head = newNode;
            } else {
                Node* current = StrList->head;
                for (int i = 0; i < index - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
            StrList->size++;
        }
    }
}

// Function to return the first data in the StrList
char* StrList_firstData(const StrList* StrList) {
    return (StrList && StrList->head) ? StrList->head->data : NULL;
}

// Function to print the word at the given index to the standard output
void StrList_printAt(const StrList* StrList, int index) {
    if (StrList && index >= 0 && index < StrList->size) {
        Node* current = StrList->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        printf("%s\n", current->data);
    }
}

// Function to return the amount of characters in the list
int StrList_printLen(const StrList* StrList) {
    int totalLength = 0;
    if (StrList) {
        Node* current = StrList->head;
        while (current != NULL) {
            totalLength += strlen(current->data);
            current = current->next;
        }
    }
    return totalLength;
}

// Function to count the number of times a string exists in the list
int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    if (StrList) {
        Node* current = StrList->head;
        while (current != NULL) {
            if (strcmp(current->data, data) == 0) {
                count++;
            }
            current = current->next;
        }
    }
    return count;
}

// Function to remove all occurrences of a string from the list
void StrList_remove(StrList* StrList, const char* data) {
    if (StrList) {
        Node* current = StrList->head;
        Node* prev = NULL;
        while (current != NULL) {
            if (strcmp(current->data, data) == 0) {
                if (prev == NULL) {
                    StrList->head = current->next;
                } else {
                    prev->next = current->next;
                }
                Node* temp = current;
                current = current->next;
                free(temp->data);
                free(temp);
                StrList->size--;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

// Function to remove the element at a given index from the list
void StrList_removeAt(StrList* StrList, int index) {
    if (StrList && index >= 0 && index < StrList->size) {
        Node* current = StrList->head;
        if (index == 0) {
            StrList->head = current->next;
            free(current->data);
            free(current);
        } else {
            Node* prev = NULL;
            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            free(current->data);
            free(current);
        }
        StrList->size--;
    }
}

// Function to check if two StrLists have the same elements
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    if (StrList1 && StrList2 && StrList1->size == StrList2->size) {
        Node* current1 = StrList1->head;
        Node* current2 = StrList2->head;
        while (current1 != NULL) {
            if (strcmp(current1->data, current2->data) != 0) {
                return 0;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return 1;
    }
    return 0;
}

// Function to clone the given StrList
StrList* StrList_clone(const StrList* strList) {
    if (strList) {
        StrList* newList = StrList_alloc();
        if (newList) {
            Node* current = strList->head;
            while (current != NULL) {
                StrList_insertLast(newList, current->data);
                current = current->next;
            }
        }
        return newList;
    }
    return NULL;
}

// Function to reverse the given StrList
void StrList_reverse(StrList* StrList) {
    if (StrList && StrList->head) {
        Node* prev = NULL;
        Node* current = StrList->head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        StrList->head = prev;
    }
}

// Function to sort the given StrList in lexicographical order
void StrList_sort(StrList* StrList) {
    if (StrList && StrList->head) {
        char* temp;
        Node* currentI;
        Node* currentJ;
        for (currentI = StrList->head; currentI != NULL; currentI = currentI->next) {
            for (currentJ = currentI->next; currentJ != NULL; currentJ = currentJ->next) {
                if (strcmp(currentI->data, currentJ->data) > 0) {
                    temp = currentI->data;
                    currentI->data = currentJ->data;
                    currentJ->data = temp;
                }
            }
        }
    }
}

// Function to check if the given list is sorted in lexicographical order
int StrList_isSorted(StrList* StrList) {
    if (StrList && StrList->head) {
        Node* current = StrList->head;
        while (current->next != NULL) {
            if (strcmp(current->data, current->next->data) > 0) {
                return 0;
            }
            current = current->next;
        }
        return 1;
    }
    return 0;
}


