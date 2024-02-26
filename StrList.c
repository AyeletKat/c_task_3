#include "StrList.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

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


