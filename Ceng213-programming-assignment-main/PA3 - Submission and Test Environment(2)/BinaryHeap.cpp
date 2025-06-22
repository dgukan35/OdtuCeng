#include "BinaryHeap.h"


BinaryHeap::BinaryHeap()
{
    // TODO: or not
    HeapElement temp;
    temp.uniqueId = 0;
    temp.weight = 0;
    elements.push_back(temp);
    theSize= 0;
    
    
}


bool BinaryHeap::Add(int uniqueId, double weight)
{
    // TODO:
    int i;
    if(theSize>0){
        for(i=1;i<theSize+1;i++){
            if(elements[i].uniqueId==uniqueId){
                return false;
            }
        }    
    }
    /*if(theSize==0){
        elements.resize(2*elements.size( ) + 1);
        elements[1].uniqueId = uniqueId;
        elements[1].weight = weight;
        theSize++;
       
        return true;
    }*/
    if(theSize>=0){
        
    if((theSize + 1) == ((int) elements.size())){
        elements.resize(elements.size( )*2 + 1);
    }
        elements[0].uniqueId = uniqueId;
        elements[0].weight = weight;
        /*elements.resize(2*elements.size() + 1);*/
    
    int tmp = ++theSize;;
    for( ; weight < elements[tmp/2].weight; tmp /= 2 ){
        elements[tmp].weight = elements[tmp/2].weight;
        elements[tmp].uniqueId = elements[tmp/2].uniqueId;
    }
    elements[tmp].uniqueId = uniqueId;
    elements[tmp].weight = weight;
    return true;
    }
   
    
}

bool BinaryHeap::PopHeap(int& outUniqueId, double& outWeight)
{
    // TODO:
    if(theSize==0){
    return false;
    }
    outUniqueId = elements[1].uniqueId;
    outWeight = elements[1].weight;
    elements[1] = elements[theSize];
    theSize--;
    bubbledown(1);
    return true;
}
void BinaryHeap::bubbledown(int hole){
    int child;
    HeapElement tmp = elements[hole];
    for(;hole*2<=theSize;hole=child){
        child = hole*2;
        if(child!=theSize&&elements[child+1].weight<elements[child].weight){
            child++;
        }
        if(elements[child].weight<tmp.weight){
            elements[hole] = elements[child];
        }
        else{
            break;
        }
    }
    elements[hole] = tmp; 
    
}

bool BinaryHeap::ChangePriority(int uniqueId, double newWeight)
{
    // TODO:
    int i;
    for(i=1;i<theSize+1;i++){
        if(elements[i].uniqueId==uniqueId){
            elements[i].weight = newWeight;
             while (i > 1 && elements[i].weight < elements[i / 2].weight) {
            HeapElement temp = elements[i];
            elements[i] = elements[i/2];
            elements[i/2] = temp;
            i/=2;
    }
    bubbledown(i);
            /*build();*/
            return true;
        }
    }
    return false;
}
void BinaryHeap::build(){
    int i;
    for(i=theSize/2;i>0;i--){
        bubbledown(i);
    }
}

int BinaryHeap::HeapSize() const
{
    // TODO:
    
    return theSize;
}