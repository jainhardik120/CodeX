#include <iostream>


const int MAX_SIZE = 1000; // Adjust as needed


// Stack implementation
class Stack {
private:
    int top;
    int arr[MAX_SIZE];


public:
    Stack() : top(-1) {}


    void push(int x) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }


    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }


    bool isEmpty() {
        return (top < 0);
    }


    int size() {
        return top + 1;
    }


    void display() {
        for (int i = top; i >= 0; i--)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};


// Queue implementation
class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];


public:
    Queue() : front(-1), rear(-1) {}


    void enqueue(int x) {
        if (rear >= MAX_SIZE - 1) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
    }


    int dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front++];
        if (front > rear)
            front = rear = -1;
        return x;
    }


    bool isEmpty() {
        return (front == -1 || front > rear);
    }


    int size() {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }


    void display() {
        for (int i = front; i <= rear; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};
// Function to swap contents of stack and queue
void swapContents(Stack& st, Queue& q) {
    int qSize = q.size();
    int stSize = st.size();

    // Step 1: Move all elements from stack to queue
    for (int i = 0; i < stSize; i++) {
        q.enqueue(st.pop());
    }

    // Step 2: Rotate the queue to get the original stack elements at the end
    for (int i = 0; i < qSize; i++) {
        q.enqueue(q.dequeue());
    }

    // Step 3: Move the original queue elements to the stack
    for (int i = 0; i < qSize; i++) {
        st.push(q.dequeue());
    }

    // Step 4: Reverse the stack elements using only the stack operations
    for (int i = 0; i < qSize; i++) {
        int temp = st.pop();
        for (int j = 0; j < qSize - i - 1; j++) {
            st.push(st.pop());
        }
        st.push(temp);
        for (int j = 0; j < qSize - i - 1; j++) {
            st.push(st.pop());
        }
    }
}


int main() {
    Stack st;
    Queue q;


    // Input for stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);


    // Input for queue
    q.enqueue(8);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(5);


    std::cout << "Before swapping:\n";
    std::cout << "Stack: ";
    st.display();
    std::cout << "Queue: ";
    q.display();


    swapContents(st, q);


    std::cout << "After swapping:\n";
    std::cout << "Stack: ";
    st.display();
    std::cout << "Queue: ";
    q.display();


    return 0;
}
