Parsing of string:
------------------
Using strtok:
-------------
char str[] = "I am a C programmer";
char *token = strtok(str, " ");

cout << token << endl;
while (token != NULL)
{
	token = strtok(NULL, " ");
    	cout << token << endl;
}

Using stringstream:
-------------------
string line = "I am a C++ programmer";
vector <string> tokens;
stringstream ss(line); //stringstream object supports << and >> operator to read and write data to buffer
string word;
// Tokenizing w.r.t. space ' '
while(getline(ss, word, ' '))
{
    tokens.push_back(word);
}


// Discards/clear the input buffer.
cin.sync();

cout << endl  : Inserts a new line and flushes the stream
cout << "\n"  : Only inserts a new line.

// Input: "blablabla 25"
// Output: Value read : 25
scanf("%*s %d", &a);
printf("Input value read : a=%d",a);

// A Method that returns multiple values using tuple in C++.
tuple<int, int, char> foo(int n1, int n2)
{
    // Packing values to return a tuple
    return make_tuple(n2, n1, 'a');
}
int main()
{
    int a,b;
    char cc;
    // Unpack the elements returned by foo
    tie(a, b, cc) = foo(5, 10);
}


BitSet:
-------
A bitset is an array of bool but each boolean value is not stored separately
instead bitset optimizes the space such that each bool takes 1 bit space only.
int M = 32;
bitset<M> bset(20); //initialized with bits of 20 (here M is length)
cout << bset; // 00000000000000000000000000010100

bitset<8> set2; // 000000000
set8[1] = 1;
