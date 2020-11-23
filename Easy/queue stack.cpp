//Design a class to implement a stack using only a single queue.

class Stack{
    queue<int>q;
public:
    void push(int val);
    void pop();
    int top();
    bool empty();
};

void Stack::push(int val){
    int s = q.size();
    q.push(val);
    // Pop (or Dequeue) all previous elements and put them after current element and delete all elements from beginning till that element
    for(int i=0; i<s; i++){
        // this will add front element into
        // rear of queue
        q.push(q.front());
        // this will delete front element
        q.pop();
    }
}

void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}

int  Stack::top()
{
    return (q.empty())? -1 : q.front();
}

bool Stack::empty()
{
    return (q.empty());
}
