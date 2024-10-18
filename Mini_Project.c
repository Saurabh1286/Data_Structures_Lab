//Snake Game using Queue using Linked Lists.
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int x, int y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* q, int x, int y) {
    struct Node* newNode = createNode(x, y);
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int height = 25, width = 25;
int gameover, score;
int x, y, fruitx, fruity, flag;
struct Queue* tail;
int nTail;
int a = 20;
int delay = 300;
int HighScore = 0;

void setup() {
    gameover = 0;
    x = height / 2; 
    y = width / 2;
    flag = 0;
    nTail = 0; 
    score = 0;
    delay = 300;
    a = 20;

    tail = (struct Queue*) malloc (sizeof(struct Queue));

    do {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    } while (fruitx == x && fruity == y);

    tail -> front = NULL;
    tail -> rear = NULL;
}

int sleep_time(int *delay, int *a) {
    if (score > *a && *delay > 50) {
        *delay = *delay - 50;
        *a = *a + 20;
    }
    return *delay;
}

void input() {
    if (_kbhit()) {
        char keyPressed = _getch();
        switch (keyPressed) {
            case 'a':
                if (flag != 3)
                    flag = 1;
                break;
            case 's':
                if (flag != 4)
                    flag = 2;
                break;
            case 'd':
                if (flag != 1)
                    flag = 3;
                break;
            case 'w':
                if (flag != 2)
                    flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void draw() {
    system("cls");
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                printf("#");
            else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else {
                    bool printTail = false;
                    struct Node* current = tail->front;
                    while (current != NULL) {
                        if (current->x == i && current->y == j) {
                            printf("o");
                            printTail = true;
                            break;
                        }
                        current = current->next;
                    }
                    if (!printTail)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Score = %d", score);
    printf("\nHigh score: %d", HighScore);
    printf("\n");
    printf("Press X to quit the game");
}

void logic() {
    Sleep(sleep_time(&delay, &a));

    int prevX = x;
    int prevY = y;
    bool eaten = false;

    switch (flag) {
        case 1: 
            y--; 
            break;  
        case 2: 
            x++; 
            break;  
        case 3: 
            y++; 
            break;  
        case 4: 
            x--; 
            break;  
        default: 
            break;
    }

    if (x < 1 || x >= height - 1 || y < 1 || y >= width - 1) {
        printf("\nGame over: Hit the boundary\n");
        gameover = 1;
        return;
    }

    if (nTail > 0) {
        struct Node* current = tail->front;
        while (current != NULL) {
            if (current->x == x && current->y == y) {
                printf("\nGame over: Collided with yourself\n");
                gameover = 1;
                return;
            }
            current = current->next;
        }
    }

    if (x == fruitx && y == fruity) {
        do {
            fruitx = rand() % (height - 2) + 1;
            fruity = rand() % (width - 2) + 1;  
        } while ((fruitx == x && fruity == y) || (tail->front && tail->front->x == fruitx && tail->front->y == fruity));

        eaten = true;
        score += 10;
        nTail++;  
    }
    
    enqueue(tail, prevX, prevY); 
    if (!eaten) {
        dequeue(tail); 
    }
}

int main() {
    char ch;
    do {
        setup();
        while (!gameover) {
            input();
            draw();
            logic();
        }
        if (HighScore < score) {
            HighScore = score;
        }

        printf("\nDo you want to continue (y/n) ? ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    return 0;
}
