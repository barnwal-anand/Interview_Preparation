>> This could be understood as a function that is passed in as an argument to a function.

void max(int x, int y, int z)
{
}
void min(int x, int y, int z)
{
}

void A(int a, int b, int c, void (*p)(int, int , int))
{
    (*p)(a, b, c);
}

int main()
{
    int x = 10,y = 20, z = 30;
    A(x, y, z, &max);
    A(x, y, z, &min);
}

The above code can be understood as:
Two functions “max” and “min” are defined to find the maximum and minimum of three numbers respectively.
A separate function “A” is defined that is used for callback.
Functions “max” and “min” are callback functions as they are been called from the arguments of function “A”.
