#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct node{
    int key;
    node* next = NULL;
    node* prev = NULL;
};

struct header{
    node *head = NULL;
    header* next = NULL;
    header* prev = NULL;
    int size = 0;
};


void gotoxy(int x, int y);
void ClearScreen();
node *createNode(int data);
void addNode(node *&pHead, int data, int &size);
void deleteNode(int pos, header *&head);
node * trace(node * head, int m);
header *createHeader(node *data);
void addHeader(header *&pHead, node* data, int &size);
header * traceH(header * head, int m);
void deleteH(header *&head);