#include <iostream>
using namespace std;

int fibonacci_recursive(int n, bool reset_count = false, bool get_count = false)
{
    static int call_count = 0;

    if (reset_count)
    {
        call_count = 0;
        return 0;
    }

    if (get_count)
    {
        return call_count;
    }

    call_count++;

    if (n == 1 || n == 2)
    {
        return 1;
    }

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_loop(int n, int& iterations)
{
    iterations = 0;

    if (n == 1 || n == 2)
    {
        return 1;
    }

    int previous = 1;
    int current = 1;
    int next = 0;

    for (int i = 3; i <= n; i++)
    {
        next = previous + current;
        previous = current;
        current = next;
        iterations++;
    }

    return current;
}

int main()
{
    int n;

    cout << "Enter a Fibonacci number position: ";
    cin >> n;

    while (n < 1)
    {
        cout << "Please enter a number 1 or greater: ";
        cin >> n;
    }

    fibonacci_recursive(0, true);
    int recursive_answer = fibonacci_recursive(n);
    int recursive_calls = fibonacci_recursive(0, false, true);

    int loop_iterations = 0;
    int loop_answer = fibonacci_loop(n, loop_iterations);

    cout << endl;
    cout << "Recursive Fibonacci answer: " << recursive_answer << endl;
    cout << "Recursive function calls: " << recursive_calls << endl;

    cout << endl;
    cout << "Loop Fibonacci answer: " << loop_answer << endl;
    cout << "Loop iterations: " << loop_iterations << endl;

    cout << endl;

    fibonacci_recursive(0, true);
    fibonacci_recursive(10);
    cout << "When n is 10, the recursive function gets called "
         << fibonacci_recursive(0, false, true) << " times." << endl;

    int test_iterations = 0;
    fibonacci_loop(10, test_iterations);
    cout << "When n is 10, the loop runs "
         << test_iterations << " times." << endl;

    return 0;
}
