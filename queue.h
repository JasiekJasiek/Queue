template < typename Type >
class QUEUE{
private:

    struct NODE{
        Type value;
        NODE* next;
        NODE(Type val){
            value = val;
            next = nullptr;
        }
    };

    NODE* first;
    NODE* last;
    int cap;

public:

    QUEUE(){ // initializing values
        cap = 0;
        first = nullptr;
        last = nullptr;
    }

    ~QUEUE(){
        while(!isEmpty()){
            pop();
        }
    }

    bool isEmpty(){ // check if queue is empty
        return cap == 0;
    }

    int getSize(){ // returning number of elements in queue
        return cap;
    }

    Type front(){ // acces to front element
        if(isEmpty()){
            std::cout << "runtime_error" << '\n';
        }
        return first -> value;
    }

    void pop(){ // remove front element from queue
        if(isEmpty()){
            std::cout << "Queue is empty" << '\n';
            return;
        }
        NODE* temp = first;
        first = first -> next;
        delete temp;
        cap--;
    }

    void add(Type val){ // push new element to queue
        NODE* newNode = new NODE(val);
        if(isEmpty()){
            first = last = newNode;
        }
        else{
            last -> next = newNode;
            last = newNode;
        }
        cap++;
    }

};
