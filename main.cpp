#include <iostream>
#include <stack>
#include <queue> // Tanto queue, priority_queue
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <fstream>
#include <type_traits>
using namespace std;

template <typename T, typename ...Params, template<typename...> typename Adapter, typename Function>
void for_adapter(Adapter<T, Params...>& adapter, const Function& fn) {
    while (!adapter.empty()) {
        if constexpr(is_same_v<Adapter<T>, queue<T>> == true)
            fn(adapter.front());
        else
            fn(adapter.top());
        adapter.pop();
    }
}

void ejemplo_1() {
    stack<int> s1;
    // Ingreso de valores
    s1.push(1);
    s1.push(23);
    s1.push(12);
    for_adapter(s1, [](auto v) {
        cout << v << endl;
    });
}

void ejemplo_2() {
    deque<int> v1 = {1, 20, 30, 40};
    stack<int> s1(v1);
    for_adapter(s1, [](auto v) {
        cout << v << endl;
    });
}

void ejemplo_3() {
    vector<int> v1 = {1, 200, 300, 400};
    stack<int, vector<int>> s1(v1);
    for_adapter(s1, [](auto v) {
        cout << v << endl;
    });
}

void ejemplo_4() {
    ifstream file("../in.txt");
    deque<int> d1{istream_iterator<int>(file), istream_iterator<int>()};
    stack<int> s1(d1);
    for_adapter(s1, [](auto v) {
        cout << v << endl;
    });
}

void ejemplo_5() {
    ifstream file("../in.txt");
    deque<int> d1{istream_iterator<int>(file), istream_iterator<int>()};
    queue<int> q1(d1);
    for_adapter(q1, [](auto v) {
        cout << v << endl;
    });
}

void ejemplo_6() {
    ifstream file("../in.txt");
    list<int> l1{istream_iterator<int>(file), istream_iterator<int>()};
    queue<int, list<int>> q1(l1);
    for_adapter(q1, [](auto v) {
        cout << v << endl;
    });
}

int main() {
//    ejemplo_1();
//    ejemplo_2();
//    ejemplo_3();
    ejemplo_4();
    cout << "---\n";
//    ejemplo_5();
    ejemplo_6();
    return 0;
}
