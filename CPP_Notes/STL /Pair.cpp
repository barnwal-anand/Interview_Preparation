Pair container is defined in <utility> header and provides a way to store 2 heterogeneous objects as single unit.

pair <char, int> pair1;
pair1.first = 'A';
pair1.second = 10;

pair1 = {'A', 10}; // or pair <char, int> pair1 ('A', 10)

make_pair() : template function allows to create a value pair without writing the types explicitly.
pair1 = make_pair('A', 10);

pair<int, int> pair1 = make_pair(1, 12);
pair<int, int>  pair2 = make_pair(9, 12);

cout << (pair1 == pair2) << endl;        // 0 as (1, 12) != (9, 12)
cout << (pair1 != pair2) << endl;        // 1
cout << (pair1 >= pair2) << endl;        // 0 as 1 < 9
cout << (pair1 <= pair2) << endl;        // 1

pair1.swap(pair2); // Now pair1 - (9, 12) and pair2 - (1, 12)

pair<int, int>pair3(p2);
