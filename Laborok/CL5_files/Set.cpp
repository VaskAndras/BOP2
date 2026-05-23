#include "Set.h"
#include <stdio.h>
#include <stdlib.h>
Set::Set() {
    elementNum = 0;
    pData = NULL;
}

Set::Set(const Set &theOther) {
    elementNum = theOther.elementNum;
    if (elementNum > 0) {
        pData = (int*)malloc(elementNum * sizeof(int));
        for (int i = 0; i < elementNum; i++) {
            pData[i] = theOther.pData[i];
        }
    } else {
        pData = NULL;
    }
}   
Set::~Set() {
    if (pData != NULL) {
        free(pData);
    }
}

bool Set::insert(int element) {
    if (isElement(element)) {
        return true;
    }
    int* newData = (int*)realloc(pData, (elementNum +1) * sizeof(int));
    if (newData == NULL) {
        return false;
    }
    pData = newData;
    pData[elementNum] = element;
    elementNum++;
    return true;
}

bool Set::remove(int element) {
    for (int i = 0; i < elementNum; i++) {
        if (pData[i] == element) {
            for (int j = i; j < elementNum - 1; j++) {
                pData[j] = pData[j + 1];
            }
            elementNum--;
            int* newData = (int*)realloc(pData, elementNum * sizeof(int));
            if (newData != NULL || elementNum == 0) {
                pData = newData;
            }
            return true;
        }
    }
    return false;
}

bool Set::isElement(int element) {
    for (int i = 0; i < elementNum; i++) {
        if (pData[i] == element) {
            return true;
        }
    }
    return false;
}

void Set::print() {
    printf("\n");
    for (int i = 0; i < elementNum; i++) {
        printf("%d ", pData[i]);
    }
    printf("\n");
}
