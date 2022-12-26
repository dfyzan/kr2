/////////-1-//////////
#include <stdio.h>
#include <stdlib.h>

void process1(int **array, int *size) {
    if (*size == 0) {
        return;
    }
    int f = (*array)[0];
    for (int i = 0; *size > 0 && i < *size; i++) {
        if ((*array)[i] == f) {
            for (int j = i; j < *size - 1; j++) {
                (*array)[j] = (*array)[j+1];
            }
            i--;
            (*size)--;
        }
    }
}
/////////-2-//////////
#include <stdio.h>
#include <stdlib.h>

void process2(int **array, int *size) {
    if (*array != NULL && *size > 0) {
        for (int i = 0; i < * size; i++) {
            if ((*array)[i] % 2 == 0) {
                (*size)++;
                *array = (int*) realloc(*array, *size * sizeof(int));
                for (int k = *size - 1; k >= i + 1;k--) {
                    (*array)[k] = (*array)[k-1];
                }
                (*array)[i] /= 2;
                (*array)[i+1] /= 2;
                i++;
            }
        }
    }
}
/////////-3-//////////
#include <stdio.h>
#include <stdlib.h>

void process3(int **array, int *size) {
    for (int i = 0; i < * size; i++) {
        int el = (*array)[i];
        if (el % 2 == 0) {
            el /= 2;
            *size++;
            *array = realloc(*array, (*size)*sizeof(int));
            (*array)[i] = el;
            for (int b = *size - 1; b > i; b--) {
                (*array)[b] = (*array)[b-1];
            }
            i++;
        }
    }
}
/////////-4-//////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t"

char *process4(const char *str) {
    char *s = strdup(str);
    int s_len = strlen(s), r_len = 0;
    char *res = malloc(s_len + 1);
    char *word = strtok(s, DELIM);
    while (word != NULL) {
        int w_len = strlen(word);
        int mid = w_len / 2;
        char tmp;

        for (int i = 0; i < mid; i++) {
            tmp = word[i];
            word[i] = word[w_len - i - 1];
            word[w_len - i - 1] - tmp;
        }
        memcpy(res + r_len, word, w_len);
        r_len += w_len;
        res[r_len++] = ' ';
        word = strtok(NULL, DELIM);
    }
    free(s);

    if (r_len > 0) {
        --r_len;
    }
    res[r_len] = '\0';
    res = realloc(res, r_len + 1);

    return res;
}
/////////-5-//////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " "

char *process5(const char *str) {
    char *emp = (char*) malloc(sizeof(char));
    *emp = '/0';
    if (!str || (*str)) {
        return emp;
    }
    char *cop = strdup(str);
    char *word = strtok(cop, DELIM);
    if (!word) return emp;
    char *forb = strdup(word);
    char *res = (char*) malloc(strlen(str) * sizeof(char));
    *res = '\0';
    while(word) {
        if(strcmp(word, forb)) {
            res = strcat(res, word);
            res = strcat(res, " ");
        }
        word = strtok(NULL, DELIM);
    }
    if (res[strlen(res)] == ' ') res[strlen(res)] = '\0';
    return res;
}
/////////-6-//////////
#include <stdlib.h>
#include <string.h>

char* process6(char *s) {
    char* copy = (char*) malloc(strlen(s) + 1);
    strcpy(copy, s);
    int i = 0;
    char* res = (char*) calloc(1, sizeof(char));
    char* ptr = strtok(copy, " ");
    if (ptr == NULL) {
        return copy;
    }
    while (ptr != NULL) {
        res = (char*) realloc(res, strlen(res) + strlen(ptr) + 2);
        strcat(res, ptr);
        strcat(res, " ");
        if (i % 2 == 1) {
            res = (char*) realloc(res, strlen(res) + strlen(ptr) +2);
            strcat(res, ptr);
            strcat(res, " ");
        }
        i++;
        ptr = strtok(NULL, " ");
    }
    return res;
}
/////////-7-//////////
#include <stdio.h>
#include <stdlib.h>
//#include "list.h"

typedef  struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

void process(List *list) {
    if (!list) return;

    if (!(list->head)) return;

    Node *last = list->head;

    while (last->next) {
        last = last->next;
    }

    while (list->head && list->head->data == last->data) {
        list->head = list->head->next;
    }

    if(!(list->head)) return;

    Node *head = list->head;
    Node *curr = head;
    Node *n = head->next;

    while (n && n != last) {
        if (curr->data == last->data) {
            head->next = n;
            curr = n;
            n = curr->next;
        } else {
            head = curr;
            curr = n;
            n = curr->next;
        }
    }
    if (curr->data == last->data) {head->next = NULL;}
    curr->next = NULL;
}
/////////-8-//////////
#include <stdio.h>
#include <stdlib.h>
// #inlcude "list.h"

void process(List *)