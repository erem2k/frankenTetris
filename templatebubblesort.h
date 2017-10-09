#ifndef TEMPLATEBUBBLESORT_H
#define TEMPLATEBUBBLESORT_H

#include <vector>

template <class T>
class templateBubbleSort
{
public:
    std::vector<T> operator()(std::vector<T>);
};

template <typename T>
std::vector<T> templateBubbleSort<T>::operator()(std::vector<T> receivedVector)
{
    for(int k=0; k<(receivedVector.size()-1); k++)
    {
        for(int j=k+1; j<receivedVector.size(); j++)
        {
            if(receivedVector.at(k)>receivedVector.at(j))
            {
                T bufferElement=receivedVector.at(k);
                receivedVector.at(k)=receivedVector.at(j);
                receivedVector.at(j)=bufferElement;
            }
        }
    }

    return receivedVector;
}

#endif // TEMPLATEBUBBLESORT_H
