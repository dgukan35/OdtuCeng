#include "Browser.h"

Browser::Browser() {
    windows.append(Window());
}

void Browser::newWindow() {
    // TODO
    windows.prepend(Window());
}

void Browser::closeWindow() {
    // TODO
    if(windows.isEmpty()==true){
        return;
    }
    windows.removeNodeAtIndex(0);
    return;
}

void Browser::switchToWindow(int index) {
    // TODO
    windows.moveToIndex(index,0);
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    // TODO
    to.newTab(from.getActiveTab());
    from.closeTab();

}

void Browser::mergeWindows(Window &window1, Window &window2) {
    // TODO
    window2.changeActiveTabTo(0);
    
    while(window2.isEmpty()!=true){
    moveTab(window2,window1);
    }
    
    
}

void Browser::mergeAllWindows() {
    // TODO
    /*Window window1 = windows.getFirstNode()->data;*/
   /* mergeWindows(window1,getWindow(1));*/
    /*mergeWindows(window1,getWindow(2));*/
    int i = 0;
    for(; i<windows.getSize()-1;i++){
       
            mergeWindows(getWindow(0),getWindow(i+1));
        }
        
    }


void Browser::closeAllWindows() {
    // TODO
    windows.removeAllNodes();
    
}

void Browser::closeEmptyWindows() {
    // TODO
    if(windows.isEmpty()==true){
        return;
    }
    int i = 0;
    while(i<windows.getSize()){
        if(getWindow(i).isEmpty()==true){
            windows.removeNodeAtIndex(i);
            
        }
        else{
            i++;
        }
    }
}

void Browser::print() {
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) {
        std::cout << "The browser is empty" << std::endl;
    } else {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) {
            (head -> data).print();
            head = head -> next;
        }
    }
}
