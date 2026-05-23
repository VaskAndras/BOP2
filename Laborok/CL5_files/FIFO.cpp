#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

FIFO::FIFO() {
    elementNum = 0;
    pData = NULL;
}

FIFO::FIFO(const FIFO &theOther) {
    elementNum = theOther.elementNum;
    if (elementNum > 0){
        pData = (int*)malloc(elementNum*sizeof(int));
        for (int i=0; i < elementNum; i++){
            pData[i]= theOther.pData[i];
        }
    } else {
        pData=NULL;
    }
    }

FIFO::~FIFO(){
    if(pData != NULL){
        free(pData);
    }
}

bool FIFO::push(int element) {
if (pData != NULL) {
int* newData = (int*)realloc(pData, (elementNum + 1) * sizeof(int));
if (newData == NULL) {
return false;
}

    pData = newData;
    pData[elementNum] = element;
    elementNum++;
    
} else {
    pData = (int*)malloc(sizeof(int));
    if (pData == NULL) {
        return false;
    }
    pData[0] = element;
    elementNum = 1;
}
return true;
}

bool FIFO::pop(int &element) {
if (elementNum == 0) {
return false;
}

element = pData[0];

for (int i = 0; i < elementNum - 1; i++) {
    pData[i] = pData[i+1];
}

elementNum--;

if (elementNum == 0) {
    free(pData);
    pData = NULL;
} else {
    int* newData = (int*)realloc(pData, elementNum * sizeof(int));
    if (newData != NULL) {
        pData = newData;
    }
}

return true;
}

void FIFO::print() {
printf("FIFO: ");
for (int i = 0; i < elementNum; i++) {
printf("%d ", pData[i]);
}
printf("\n");
}