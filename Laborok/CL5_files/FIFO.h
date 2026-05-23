#ifndef FIFO_H
#define FIFO_H

class FIFO
{
    int elementNum;
    int* pData; 
public:
    FIFO();
    FIFO(const FIFO &theOther);
    ~FIFO();
    bool push(int element);
    bool pop(int &element);
    void print();
};
#endif /* FIFO_H */