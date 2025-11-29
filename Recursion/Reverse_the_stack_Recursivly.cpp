#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack recursively
void insertAtBottom(stack<int> &st, int element)
{
    // Base case: if stack is empty, push element
    if (st.empty())
    {
        st.push(element);
        return;
    }

    // Otherwise, pop the top, insert element at bottom, then push top back
    int temp = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(temp);
}

// Function to reverse the stack recursively
void reverseStack(stack<int> &st)
{
    // Base case: empty stack is already reversed
    if (st.empty())
        return;

    // Pop the top element
    int temp = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the popped element at the bottom
    insertAtBottom(st, temp);
}

// Utility function to print a stack from top to bottom
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    // Example input
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top -> bottom): ";
    printStack(st);

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed Stack (top -> bottom): ";
    printStack(st);

    return 0;
}
