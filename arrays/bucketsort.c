#include <stdio.h>
#include <stdlib.h>

#define NARRAY 7   
#define NBUCKET 6  
#define INTERVAL 10  

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getIndex(int value);

void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

 
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

 
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }


  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }


  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  
  printf("\nBucktets after sorting\n");
  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];  
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

struct Node *InsertionSort(struct Node *head) {
  struct Node *k, *nodeList;
  if (head == 0 || head->next == 0) {
    return head;
  }

  nodeList = head;
  k = head->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getIndex(int value) {
  return value / INTERVAL;
}

void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}


void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}


int main(void) {
  int array[NARRAY] = {42, 32, 33, 52, 37, 47, 51};
  printf("Initial array: ");
  print(array);
  BucketSort(array);
  printf("\nSorted array: ");
  print(array);
  return 0;
}