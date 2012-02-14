#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int precedence(char c)
{
    if (c == '+') return 1;
    if (c == '*') return 2;
}

int apply(char op, int a, int b)
{
    if (op == '+') return a + b;
    if (op == '*') return a * b;
}

int evaluate_arithmetic(char* str, int len)
{
    stack<char> ops; 
    stack<int> nums;

    if (len < 3)
        return 0;

    nums.push(str[0] - '0');
    nums.push(str[2] - '0');
    ops.push(str[1]);

    int i = 3;
    while (i < len)
    {
        printf("i=%d len=%d\n", i, len);
        if (precedence(str[i]) > precedence(ops.top()))
        {
            int val;
            val = apply(str[i], nums.top(), str[i+1] - '0');
            nums.pop();
            nums.push(val);
        }
        else
        {
            int topval = nums.top();
            nums.pop();
            int val = apply(ops.top(), topval, nums.top());
            nums.pop();
            ops.pop();
            nums.push(val);
            nums.push(str[i+1] - '0');
            ops.push(str[i]);
        }
        i = i + 2;
    }
    int topval = nums.top();
    nums.pop();
    return apply(ops.top(), topval, nums.top());

    printf("size of stack: %d\n", (int)nums.size());
    return nums.top();
}

int main(void)
{
    char s[] = "2*3+5*4+1";
    int total = evaluate_arithmetic(s, 9);
    printf("total of %s=%d\n", s, total);

}
