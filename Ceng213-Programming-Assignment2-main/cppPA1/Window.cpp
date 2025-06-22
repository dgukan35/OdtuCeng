#include "Window.h"

Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    // TODO
    if(tabs.isEmpty()==true){
        return Tab();
    }
    else{
       return  tabs.getNodeAtIndex(activeTab)->data;
    }
}

bool Window::isEmpty() const {
    // TODO
    if(tabs.isEmpty()==true){
        return true;
    }
    return false;
}

void Window::newTab(const Tab &tab) {
    // TODO
    if(isEmpty()==true){
        tabs.append(tab);
        activeTab = 0;
        return;
   }
    tabs.insertAfterNode(tab,tabs.getNodeAtIndex(activeTab));
    activeTab++;
}

void Window::closeTab() {
    // TODO
   if(isEmpty()==true){
        activeTab = -1;
        return;
    }
    if(tabs.getNodeAtIndex(activeTab)==tabs.getLastNode()){
        tabs.removeNodeAtIndex(activeTab);
        activeTab--;
    }
    else{
        tabs.removeNodeAtIndex(activeTab);
        
    }
    if(isEmpty()==true){
        activeTab = -1;
    }
}

void Window::moveActiveTabTo(int index) {
    // TODO
    if(index>=tabs.getSize()){
        tabs.moveToIndex(activeTab,tabs.getSize()-1);
        activeTab = tabs.getSize()-1;
        
    }
    else{
        tabs.moveToIndex(activeTab,index);
        activeTab = index;
    }
}

void Window::changeActiveTabTo(int index) {
    // TODO
    if(index>=tabs.getSize()){
        return;
    }
    if(index<0){
        return;
    }
   
    activeTab = index;

}

void Window::addTab(Node<Tab> &tab) {
    // TODO
    if(isEmpty()==true){
        tabs.append(tab.data);
        activeTab = 0;
        return;
    }
    tabs.append(tab.data);
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
