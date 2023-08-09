{\rtf1\ansi\ansicpg1252\cocoartf2639
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
#define MAX_SIZE 100\
\
\
void insert(int arr[], int *size, int element) \{\
    if (*size < MAX_SIZE) \{\
        arr[*size] = element;\
        (*size)++;\
        printf("Element inserted successfully!\\n");\
    \} else \{\
        printf("Array is full. Cannot insert.\\n");\
    \}\
\}\
\
\
void delete(int arr[], int *size, int element) \{\
    int found = 0;\
    for (int i = 0; i < *size; i++) \{\
        if (arr[i] == element) \{\
            found = 1;\
            for (int j = i; j < (*size - 1); j++) \{\
                arr[j] = arr[j + 1];\
            \}\
            (*size)--;\
            printf("Element deleted successfully!\\n");\
            break;\
        \}\
    \}\
    if (!found) \{\
        printf("Element not found in the array.\\n");\
    \}\
\}\
\
\
void traverse(int arr[], int size) \{\
    printf("Array elements: ");\
    for (int i = 0; i < size; i++) \{\
        printf("%d ", arr[i]);\
    \}\
    printf("\\n");\
\}\
\
\
void search(int arr[], int size, int element) \{\
    int found = 0;\
    for (int i = 0; i < size; i++) \{\
        if (arr[i] == element) \{\
            found = 1;\
            printf("Element found at index %d.\\n", i);\
            break;\
        \}\
    \}\
    if (!found) \{\
        printf("Element not found in the array.\\n");\
    \}\
\}\
\
int main() \{\
    int arr[MAX_SIZE];\
    int size = 0;\
    int choice, element;\
\
    do \{\
        printf("\\nMenu:\\n");\
        printf("1. Insert\\n");\
        printf("2. Delete\\n");\
        printf("3. Traverse\\n");\
        printf("4. Search\\n");\
        printf("5. Exit\\n");\
        printf("Enter your choice: ");\
        scanf("%d", &choice);\
\
        switch (choice) \{\
            case 1:\
                printf("Enter element to insert: ");\
                scanf("%d", &element);\
                insert(arr, &size, element);\
                break;\
            case 2:\
                printf("Enter element to delete: ");\
                scanf("%d", &element);\
                delete(arr, &size, element);\
                break;\
            case 3:\
                traverse(arr, size);\
                break;\
            case 4:\
                printf("Enter element to search: ");\
                scanf("%d", &element);\
                search(arr, size, element);\
                break;\
            case 5:\
                printf("Exiting program.\\n");\
                break;\
            default:\
                printf("Invalid choice. Please select a valid option.\\n");\
        \}\
\
    \} while (choice != 5);\
\
    return 0;\
\}\
}