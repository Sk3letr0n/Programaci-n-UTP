#include <iostream>

using namespace std;

template <typename T>
class list {
private:
    class Node{
      private:
        T data;
        Node* next;
      public:
        Node (const T& d): data(d), next(nullptr){}
        void setNext(Node* n) {next = n;}
        Node* getNext() {return next;}
        bool hasNext() {return next != nullptr;}
        const T& getData() {return data;}
    };
    
    Node* First;
    Node* last;
    unsigned int sz;
public:
    list() : First(nullptr), last(nullptr), sz(0) {}
    bool empty() {return First == nullptr;}
    unsigned int size() {return sz;}
    
    void push_back(const T& elem) {
        Node* n = new Node(elem);
        if(empty()){
            First=n;
        }else{
            last->setNext(n);
        }
        last = n;
        sz++;
    }
    
    void print(){
        cout << "<" ;
        Node* n=First;
        while (n != nullptr){
            cout << " " << n->getData();
            n=n->getNext();
        }
        cout << " >" << endl ;
    }
    
    const T& at(unsigned int pos){
        Node* n=First;
        for(int i=0;i<pos;i++){
            n=n->getNext();
        }
        return n->getData();
    }
    
    const T& back(){return last->getData();}
    const T& front(){return First->getData();}
    
    void push_front(const T& elem){
        Node* n= new Node(elem);
        if(empty()){
            First=n;
            last = n;
        }else{
            n->setNext(First);
        }
        First=n;
        sz++;
    }
    
    void insert(const T& elem, unsigned int pos){
        if(empty() or (pos >= sz)){
            cout<<"Error: The position is incorrect."<<endl;
            return;
        }
            
        if(pos == (sz-1)){
            push_back(elem);
            return;
        }
        
        if(pos == 0){
            push_front(elem);
            return;
        }else{
            Node* n = new Node(elem);
            Node* m = First;
            int i = 0;
            while(i < (pos - 1)){
                m = m -> getNext();
                i++;
            }
            n->setNext(m->getNext());
            m->setNext(n);
            sz++;
        }
    }
    
    void pop_back(){
        Node* n = First;
        int i = 0;
        while(i < sz - 2){
            n = n -> getNext();
            i++;
        }
        delete n -> getNext();
        n -> setNext(nullptr);
        last = n;
        sz--;
    }
    
    void pop_front(){
        Node* n=First;
        First=First->getNext();
        delete n;
        sz--;
    }
    
    void erase(unsigned int pos){
        if(empty() or (pos >= sz)){
            cout<<"Error: The position is incorrect."<<endl;
            return;
        }
        
        if(pos == (sz-1)){
            pop_back();
            return;
        }
        
        if(pos == 0){
            pop_front();
            return;
        }else{
            Node* n = First;
            Node* apo;
            for(unsigned int i = 0; i < pos; i++){
                if(i == (pos-1)){
                    apo = n;
                }
                n = n->getNext();  
            }
            Node* apo_2 = n->getNext();
            apo->setNext(apo_2);
            delete n;
            sz--;
        }
    }
};

int main()
{
    list<int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    cout << " " << l.at(0)<< endl;
    cout << " " << l.back()<< endl;
    cout << " " << l.front()<< endl;
    l.print();
    l.insert(2,2);
    l.print();
    l.push_front(1);
    l.print();
    l.pop_front();
    l.print();
    l.push_back(9);
    l.print();
    l.pop_back();
    l.print();
    l.erase(2);
    l.print();
    
    return 0;
}
