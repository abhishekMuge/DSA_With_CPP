#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into a stack that is already sorted in descending order
void insertInSortedOrder(stack<int> &st, int element)
{
    // Base case: if stack is empty or element >= top, push it
    if (st.empty() || element >= st.top())
    {
        st.push(element);
        return;
    }

    // Otherwise, pop the top, recursively insert element, then push top back
    int temp = st.top();
    st.pop();
    insertInSortedOrder(st, element);
    st.push(temp);
}

// Function to sort the stack in descending order
void sortStack(stack<int> &st)
{
    // Base case: empty stack is already sorted
    if (st.empty())
        return;

    // Pop the top element
    int temp = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element back in sorted order
    insertInSortedOrder(st, temp);
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
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack (top -> bottom): ";
    printStack(st);

    // Sort the stack
    sortStack(st);

    cout << "Sorted Stack (top -> bottom): ";
    printStack(st);

    return 0;
}
