#include "linearList.h"

const int defaultSize = 100;

template <class T>
class seqList : public linearList<T>
{
protected:
    T *element;
    int maxSize;
    int last;
    void resize(const int newSize);
};
