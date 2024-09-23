//Program to implement Singly Linked List.
//Include header files
#include <stdio.h>
#include <stdlib.h>
//Global declarations
struct Node {
    int data;
    struct Node* next;
};
struct Linked_list {
    struct Node* head;
};
//Function Declarations
void insert_begin (struct Linked_list*, int);
void insert_end (struct Linked_list*, int);
void insert_specific (struct Linked_list* , int, int);
void insert_before (struct Linked_list*, int, int);
void insert_after (struct Linked_list*, int, int);
int delete_begin (struct Linked_list*);
int delete_end (struct Linked_list*);
int delete_specific (struct Linked_list*, int);
int delete_before (struct Linked_list*, int);
int delete_after (struct Linked_list*, int);
int search (struct Linked_list*, int val);
void display (struct Linked_list*);
//Main method to write Menu
int main (int argc, char *argv[]) {
    int val, pos, option, option2;
    struct Linked_list* ll = (struct Linked_list*)malloc(sizeof(struct Linked_list));
    ll -> head = NULL;
    do {
        printf("Linked List Menu : 1. Insert    2. Delete    3. Search    4. Display    5. Exit\n");
        printf("===============================================================================\n");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nInsert : 1. At Beginning    2. At End    3. At Specific position    4. Before Node    5. After Node\n");
                printf("===================================================================================================\n");
                printf("Enter your choice : ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1:
                        printf("\nEnter number to be inseted in linked list : ");
                        scanf("%d", &val);
                        insert_begin(ll, val);
                        break;
                    case 2:
                        printf("\nEnter number to be inseted in linked list : ");
                        scanf("%d", &val);
                        insert_end(ll, val);
                        break;
                    case 3:
                        printf("\nEnter number to be inserted in linked list : ");
                        scanf("%d", &val);
                        printf("\nEnter the position for the number to be inserted : ");
                        scanf("%d", &pos);
                        insert_specific(ll, val, pos);
                        break;
                    case 4:
                        printf("\nEnter number to be inserted in linked list : ");
                        scanf("%d", &val);
                        printf("\nEnter the number before which to be inserted : ");
                        scanf("%d", &pos);
                        insert_before(ll, val, pos);
                        break;
                    case 5:
                        printf("\nEnter number to be inserted in linked list : ");
                        scanf("%d", &val);
                        printf("\nEnter the number after which to be inserted : ");
                        scanf("%d", &pos);
                        insert_after(ll, val, pos);
                        break;
                }
                display(ll);
                break;
            case 2:
                printf("\nDelete : 1. At Beginning    2. At End    3. A Specific Node    4. Before Node    5. After Node\n");
                printf("==============================================================================================\n");
                printf("Enter your choice : ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1:
                        val = delete_begin(ll);
                        if (val != -1) {
                            printf("\nDeleted element is %d\n", val);
                        }
                        break;
                    case 2:
                        val = delete_end(ll);
                        if (val != -1) {
                            printf("\nDeleted element is %d\n", val);
                        }
                        break;
                    case 3:
                        printf("\nEnter the number to be deleted : ");
                        scanf("%d", &pos);
                        val = delete_specific(ll, pos);
                        if (val != -1) {
                            printf("\nDeleted element is %d\n", val);
                        }
                        break;
                    case 4:
                        printf("\nEnter the number before which to be deleted : ");
                        scanf("%d", &pos);
                        val = delete_before(ll, pos);
                        if (val != -1) {
                            printf("\nDeleted element is %d\n", val);
                        }
                        break;
                    case 5:
                        printf("\nEnter the number after which to be deleted : ");
                        scanf("%d", &pos);
                        val = delete_after(ll, pos);
                        if (val != -1) {
                            printf("\nDeleted element is %d\n", val);
                        }
                        break;
                }
                display(ll);
                break;
            case 3:
                printf("\nEnter the number to be searched : ");
                scanf("%d", &val);
                int res = search (ll, val);
                if (res != -1) {
                    printf("\nElement found at %d position.\n\n", res);
                }
                break;
            case 4:
                display(ll);
                break;
            case 5:
                printf("\nEND OF PROGRAM!!");
                break;
        }
    } while(option != 5);
    free(ll);
    return 0;
}
//Function Definitions
void insert_begin (struct Linked_list* ll ,int val) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = ll -> head ;
    ll -> head = new;
}
void insert_end (struct Linked_list* ll, int val) {
    struct Node* curr = ll -> head;
    while (curr -> next != NULL) {
        curr  = curr -> next;
    }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = curr -> next;
    curr -> next = new; 
}
void insert_specific (struct Linked_list* ll, int val, int pos) {
    if (pos == 1) {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new -> data = val;
        new -> next = ll -> head;
        ll -> head = new;
        return;
    }
    struct Node* curr = ll -> head;
    for (int i = 1; i < pos-1; i++) {
        if (curr -> next == NULL) {
            printf("\nPosition does not exist.\n");
            return;
        }
        curr = curr -> next;
    }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = curr -> next;
    curr -> next = new;
}
void insert_before (struct Linked_list* ll, int val, int node) {
    if (ll -> head -> data == node) {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new -> data = val;
        new -> next = ll -> head;
        ll -> head = new;
        return;
    }
    struct Node* curr = ll -> head;
    while (curr -> next -> data != node) {
        if (curr -> next -> next == NULL) {
            printf("\nNode not present in Linked List.\n");
            return;
        }
        curr = curr -> next;
    }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = curr -> next;
    curr -> next = new;
}
void insert_after (struct Linked_list* ll, int val, int node) {
    struct Node* curr = ll -> head;
    while (curr -> data != node) {
        if (curr -> next == NULL) {
            printf("\nNode not present in Linked List.\n");
            return;
        }
        curr = curr -> next;
    }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = curr -> next;
    curr -> next = new;
}
int delete_begin (struct Linked_list* ll) {
    if (ll -> head == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    struct Node* node = ll -> head;
    int val = node -> data;
    ll -> head = ll -> head -> next;
    free(node);
    return val;
}
int delete_end (struct Linked_list* ll) {
    if (ll -> head == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    if (ll -> head -> next == NULL) {
        struct Node* node = ll -> head;
        int val = node -> data;
        ll -> head = NULL;
        free(node);
        return val;
    }
    struct Node* curr = ll -> head;
    while (curr -> next -> next != NULL) {
        curr = curr -> next;
    }
    struct Node* node = curr -> next;
    int val = curr -> next -> data;
    curr -> next = curr -> next -> next;
    free(node);
    return val;
}
int delete_specific (struct Linked_list* ll, int pos) {
    if (ll -> head == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    if (ll -> head -> data == pos) {
        int val = delete_begin(ll);
        return val;
    }
    if (ll -> head -> next == NULL) {
        printf("\nNode not present in Linked List\n");
        return -1;
    }
    struct Node* curr = ll -> head;
    while (curr -> next -> data != pos) {
        if (curr -> next -> next == NULL) {
            printf("\nNode not present in Linked List\n");
            return -1;
        }
        curr = curr -> next;
    }
    struct Node* node = curr -> next;
    int val = curr -> next -> data;
    curr -> next = curr -> next -> next;
    free(node);
    return val;
}
int delete_before (struct Linked_list* ll, int node) {
    if (ll -> head == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    if (ll -> head -> data == node) {
        printf("\nNo element before this.\n");
        return -1;
    }
    if (ll -> head -> next -> data == node) {
        int val = delete_begin(ll);
        return val;
    }
    struct Node* curr = ll -> head;
    while (curr -> next -> next -> data != node) {
        if (curr -> next -> next -> next == NULL) {
            printf("\nNode not present in Linked List.\n");
            return -1;
        }
        curr = curr -> next;
    }
    struct Node* del = curr -> next;
    int val = del -> data;
    curr -> next = curr -> next -> next;
    free(del);
    return val;
}
int delete_after (struct Linked_list* ll, int node) {
    if (ll -> head == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    struct Node* curr = ll -> head;
    while (curr -> data != node) {
        if (curr -> next == NULL) {
            printf("\nNode not present in Linked List.\n");
            return -1;
        }
        curr = curr -> next;
    }
    if (curr -> next == NULL) {
        printf("\nNo element after this\n");
        return -1;
    }
    struct Node* del = curr -> next;
    int val = del -> data;
    curr -> next = curr -> next -> next;
    free(del);
    return val;
}
int search (struct Linked_list* ll, int val) {
    if (ll -> head == NULL) {
        printf("\nLinked List is Empty.\n\n");
        return -1;
    }
    struct Node* curr = ll -> head;
    int count = 1;
    while (curr -> data != val) {
        if (curr -> next == NULL) {
            printf("\nElement not found.\n\n");
            return -1;
        }
        count = count + 1;
        curr = curr -> next;
    }
    return count;
}
void display (struct Linked_list* ll) {
    if (ll -> head == NULL) {
        printf("\nLinked List is Empty.\n\n");
        return;
    }
    struct Node* curr = ll -> head;
    printf("\nLinked List Elements : ");
    while (curr != NULL) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n\n");
}