// initialization by raw string
string str1("first string");               // str1 = first string

// initialization by another string
string str2(str1);                         // str2 = first string

// initialization by character with number of occurence
string str3(5, '#');                       // str3 = #####

// initialization by part of another string from 6th index 6 chars
string str4(str1, 6, 6);                   // str4 = string

// initialization by part of another string : iteartor version
string str5(str2.begin(), str2.begin() + 5); // str5 = first

//  assignment operator
string str6 = str4;

// clear function deletes all character from string
str4.clear();

//  both size() and length() return length of string
int len = str6.length();

// a particular character can be accessed using at [] operator
char ch = str6.at(2); //  Same as "ch = str6[2];"

// append add the argument string at the end
str6.append(" extension"); //  same as str6 = str6 + " extension"

// another version of appends, which appends part of other string
str4.append(str6, 0, 6);  // at 0th position 6 character

//  find returns index where pattern is found.
//  If pattern is not there it returns predefined constant npos whose value is -1
if (str6.find(str4) != string::npos)
    cout << "str4 found in str6 at " << str6.find(str4)
         << " pos" << endl;
else
    cout << "str4 not found in str6" << endl;

//  substr(a, b) function returns a substring of b length starting from index a
cout << str6.substr(7, 3) << endl;    // str6 = string extension; returns ext

//  if second argument is not passed, string till end is taken as substring
cout << str6.substr(7) << endl;       // returns extension

//  erase(a, b) deletes b character at index a
str6.erase(7, 4);                    // string becomes "string nsion"

str6 = "This is a examples";
//  replace(a, b, str)  replaces b character from a index by str
str6.replace(2, 7, "ese are test");  // str6 = These are test examples

// Reverse str[beign..end]
reverse(str.begin(), str.end());

cin.getline(str, 20); // to take multi word input

string str = "Anand";
str += to_string(i); //append int (int i = 10)
