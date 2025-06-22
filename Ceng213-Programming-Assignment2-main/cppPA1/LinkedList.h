#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
    /* TODO */
    head = NULL;
    size = 0;
    Node<T> *current = obj.head;
    while(current->next!=obj.head){
        append(current->data);
        current = current->next;
    }
    if(current->next==obj.head){
        append(current->data);
    }
  
   /* *this = obj;*/
    
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
   /*Node<T> *front = head;*/
   
   if(head==NULL){
       delete head;
   }
   else{
       
       Node<T> * tmp;
       Node<T> *front = head;
       while(head->next!=front){
           tmp = head;
           head = head->next;
           delete tmp;
       }
       if(head->next==front){
           delete head;
       }
   }
   size = 0;
  
   
    
  
  
   
   
       
   }


template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    /*if(rhs.size==0){
        removeAllNodes();
    }*/
     if(this!=&rhs){
    removeAllNodes();
    Node<T> *current = rhs.head;
    while(current->next!=rhs.head){
        append(current->data);
        current = current->next;
    }
    if(current->next==rhs.head){
        append(current->data);
    }
    }
    return *this;
 
    
}


template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    if (size==0){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    Node<T> *current = head;
    if(head==NULL){
        return false;
    }
    if(head->next==head){
        if(head==node){
            return true;
        }
        else{
            return false;
        }
    }
    while(current->next!=head){
        if(current==node){
            return true;
        }
        current=current->next;
    }
    if(current->next==head){
        if(current==node){
            return true;
        }
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(size==0){
        return NULL;
    }
    else{
        return head;
    }
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    Node<T> *current = head;
    /*Node<T> *tmp = current;*/
    if(head==NULL){
        return NULL;
    }
    else{
        if(current->next==head){
            return current;
        }
        else{
        while(current!=NULL&&current->next!=head){
            current = current->next;
        }
        }
    return current;
}
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    Node<T> *current = head;
    int i,j,k;
    if(head!=NULL){
    while(current->next!=head){
        if(data == current->data){
            return current;
        }
        current = current->next;
    }
}
    if(head!=NULL&&current->next==head){
        if(data==current->data){
            return current;
        }
    }
    if(head==NULL){
        return NULL;
    }
    if(head==head->next){
        if(data==head->data){
            return head;
        }
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    int i,j,k;
    i = 0;
    Node<T> *current = head;
    if(head==NULL){
        return NULL;
    }
    else{
        while(current->next!=head){
            if(i==index){
                return current;
            }
            else{
                current = current->next;
                i++;
            }
        }
        if(current->next==head&&i==index){
            return current;
        }
        if(head->next==head&&index==0){
            return head;
        }
    }
    return NULL;
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */
    size++;
    if (size==1){
         head = new Node<T>(data);
         head->next = head;
         head->prev = head;
         return;
     }
     else{
     Node<T> *ptr =  new Node<T>(data);
     int i,j;
     if(head->next!=head){
     head->prev->next = ptr;
     ptr->prev = head->prev;
     ptr->next = head;
     head->prev = ptr;
     return;
     }
      if(head->next==head){
         head->next = ptr;
         ptr->prev = head;
         ptr->next = head;
         head->prev = ptr;
         return;
     }
     }
      
    
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    size++;
    if(head==NULL){
        head = new Node<T>(data,NULL,NULL);
        
        head->next = head;
        head->prev = head;
        return;
    }
   else{
    if(head->next!=head){
    Node<T> *ptr = new Node<T>(data);
    ptr->next = head;
    ptr->prev = head->prev;
    head->prev->next = ptr;
     head->prev = ptr;
     head = head->prev;
     return;
      
     
   

   
    }
    else{
        Node<T> *ptr2 = new Node<T>(data,head,head);
        head->next = ptr2;
        head->prev = ptr2;
        head = head->prev;
        return;
    }
    }
     
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
  
    Node<T> *current = head;
    if(head==NULL){
        if(node==NULL){
            append(data);
        }
        return;
    }
    if(head!=NULL&&head->next==head){
        if (head == node){
            Node<T> *ptr = new Node<T>(data);
            head->next = ptr;
            ptr->prev = head;
            ptr->next = head;
            head->prev = ptr;
            size++;
            
            return;
        } 
    }
    if(head!=NULL&&head->next!=head){
        while(current->next!=head){
            if(current==node){
                Node<T> *ptr2 = new Node<T>(data,current,current->next);
                current->next->prev = ptr2;
                current->next = ptr2;
                size++;
              
                return;
            }
            current=current->next;
        }
        if(current->next==head){
            if(current == node){
                Node<T> *ptr3 = new Node<T>(data,current,current->next);
                current->next->prev = ptr3;
                current->next = ptr3;
                size++;
                
                return;
            }
        }
    }
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    
    Node<T> *current = head;
    int ind = 0;
    if(index>=size){
        return;
    }
    if(index==0){
        prepend(data);
        return;
    }
    else{
        Node<T> *ptr = new Node<T>(data);
    while(ind!=index){
        current=current->next;
        ind++;
    }
    ptr->next = current;
    ptr->prev = current->prev;
    current->prev->next = ptr;
    current->prev = ptr;
   
    }
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    int index=0;
    Node<T> *current = head;
    if(head==NULL){
        return -1;
    }
    if(head->next==head){
        if(node==head){
            return 0;
        }
        else{
            return -1;
        }
    }
    while(current->next!=head){
        if(node==current){
            return index;
        }
        current = current->next;
        index++;
    }
    if(current->next==head){
        if(node==current){
            return index;
        }
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    int ind = 0;
    int count = 0;
    Node<T> *current = head;
    if(currentIndex==newIndex){
        return;
    }
    if(head==NULL){
        return;
    }
    if(currentIndex>=size){
        return;
    }
    while(ind!=currentIndex){
        current = current->next;
        ind++;
    }
    Node<T> *ptr = current;
     if(newIndex>=size){
        while(current->next!=head){
            if(current==head){
            ptr = ptr->next;
            ptr->prev = current->prev;
            
            ptr->prev->next = ptr;
            current->prev = ptr;
            current->next = current->next->next;
            current->next->prev = current;
            ptr->next = current;
            currentIndex++;
            head = ptr;
            ptr = current;
            
        }
        else{
            ptr = ptr->next;
            ptr->prev = current->prev;
            ptr->prev->next = ptr;
            current->prev = ptr;
            current->next = current->next->next;
            current->next->prev = current;
            ptr->next = current;
            ptr = current;
        }
        }
    }
    else{
        if(newIndex>currentIndex){
        while(currentIndex!=newIndex){
            if(current==head){
            ptr = ptr->next;
            ptr->prev = current->prev;
            
            ptr->prev->next = ptr;
            current->prev = ptr;
            current->next = current->next->next;
            current->next->prev = current;
            ptr->next = current;
            currentIndex++;
            head = ptr;
            
            ptr = current;
            
        }
        else{
            
            
            ptr = ptr->next;
            
            ptr->prev = current->prev;
            ptr->prev->next = ptr;
            current->prev = ptr;
            current->next = current->next->next;
             current->next->prev = current;
             ptr->next = current;
           
            
            
            
            
           
            currentIndex++;
            ptr = current;
            /*std::cout<<head->next->data<<std::endl;*/
            
        }
        }
            
        }
        else{
            
            Node<T> *tmp = head;
            Node<T> *ptr2 = current;
            while(count!=newIndex){
                tmp=tmp->next;
                count++;
            }
            while(currentIndex!=newIndex){
            if(tmp==head){
                /*tmp->prev->next = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->prev =tmp->prev;
                current->next = tmp;
                tmp->prev=current;
                head=current;*/
                ptr2= ptr2->prev;
                ptr2->next = current->next;
                ptr2->next->prev = ptr2;
                current->next = ptr2;
                current->prev = current->prev->prev;
                current->prev->next = current;
                ptr2->prev = current;
                currentIndex--;
                head = current;
                ptr2= current;
                
            }
            else{
                /*tmp->prev->next = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->prev =tmp->prev;
                current->next = tmp;
                tmp->prev=current;*/
                ptr2= ptr2->prev;
                ptr2->next = current->next;
                ptr2->next->prev = ptr2;
                current->next = ptr2;
                current->prev = current->prev->prev;
                current->prev->next = current;
                ptr2->prev = current;
                currentIndex--;
                ptr2 = current;
                
            }
        }
        }
        }
    }
    
    


template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    Node<T> *current = head;
    if(head!=NULL){
        if(head==node){
            if(size==1){
                Node<T> *ptr3 = head;
                head = NULL;
                delete ptr3;
                size--;
                return;
            }
            Node<T> *ptr= head;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            head = ptr->next;
            delete ptr;
            size--;
            return;
        }
        if(head->next!=head){
            while(current->next!=head){
                if(current==node){
                  
                    Node<T> *tmp2 = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete tmp2;
                    size--;
                    return;
                }
                
                current = current->next;
            }
            if(current->next==head){
                if(current==node){
                    Node<T> *tmp3 = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete tmp3;
                    size--;
                    return;
                }
               
            }
        }
         
        
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    if(head==NULL){
        return;
    }
    Node<T> *current = head;
        if(head->data==data){
            if(size==1){
                Node<T> *ptr3 = head;
                head = NULL;
                delete ptr3;
                size--;
                return;
            }
            else{
            Node<T> *ptr= head;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            head = ptr->next;
            delete ptr;
            size--;
            }
        
        }
    
    else{
        while(current->next!=head){
            if(current==head){
                if(head->data==data){
                Node<T> *ptr1= head;
                ptr1->next->prev = ptr1->prev;
                ptr1->prev->next = ptr1->next;
                head = ptr1->next;
                current = current->next;
                delete ptr1;
                size--;
                }
                else{
                    current = current->next;
                }
            }
            else if(current->data==data){
                Node<T> *tmp = current;
                current->prev->next=current->next;
                current->next->prev=current->prev;
                current=current->next;
                delete tmp;
                size--;
            }
            else{
                current=current->next;
            }
            
        }
        if(current->next==head){
            if(current->data==data){
                Node<T> *tmp2 = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete tmp2;
                size--;
            }
        }
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    int count = 0;
    if(head==NULL){
        return;
    }
     if(index >= size){
        return;
     }
    Node<T> *current = head;
    if(index==0){
        if(size==1){
            Node<T> *ptr2 = head;
            head = NULL;
            delete ptr2;
            size--;
            return;
        }
        else{
        Node<T> *ptr = head;
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        head = ptr->next;
        delete ptr;
        size--;
        return;
        }
    
   }
    while(current->next!=head){
        if(count==index){
            Node<T> *tmp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete tmp;
            size--;
            return;
        }
        count++;
        current = current->next;
    }
    if(current->next==head){
        if(count==index){
            Node<T> *tmp2 = current;
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete tmp2;
            size--;
            return;
        }
    }
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    if(head==NULL){
       return;
   }
   else{
       
       
       
      
       for(int i = 0;i<size;i++){
           if(i==size-1){
               Node<T> *ptr = head;
               head = NULL;
               delete ptr;
           }
           else{
           Node<T> *tmp = head;
           head = head->next;
           delete tmp;
           }
       }
   
       
       
   }
   size = 0;
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H
