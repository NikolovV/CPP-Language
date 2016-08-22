#include <iostream>
#include <algorithm>
//#include <list>
//#include <map>
//#include <set>
#include <vector>

using namespace std;

class A
{
public:
    A() {};
    A(int x) : _x(x) {};
    friend ostream &operator << (ostream &out, const A &obj); // For map output
    bool operator==(int x) {return (this->_x == x) ? true : false;} // for map.find and vector std::find
    friend bool operator <(const A &left, const A &right);  // For set.insert
    int _x;
};

bool operator <(const A &left, const A &right) {return left._x < right._x;}
ostream &operator << (ostream &out, const A &obj) {cout << obj._x;}

int main()
{
/*
    list<int> list1 = {1, 2, 3, 4};
    list<int> list2 = {5, 6, 7, 8};
    list<int>::iterator it;
    
    cout << "list1 = "; for (auto elem : list1) {cout << elem << ' ';} cout << endl;
    cout << "list2 = "; for (auto elem : list2) {cout << elem << ' ';} cout << endl;

    it = list1.begin();
//  ++it; //pointing to second position           
    advance(it, 4);
    list1.splice(it, list2);
    cout << "list1 = "; for (auto elem : list1) {cout << elem << ' ';} cout << endl;
    cout << "list2 = "; for (auto elem : list2) {cout << elem << ' ';} cout << endl;

    it = list1.begin();
    it++; it++; 
    list2.push_back(123);
    list2.push_back(21);
    list<int>::iterator it2 = list2.begin();
    it2++; 
    list2.splice(it2, list1, it, list1.end());
    cout << "list1 = "; for (auto elem : list1) {cout << elem << ' ';} cout << endl;
    cout << "list2 = "; for (auto elem : list2) {cout << elem << ' ';} cout << endl;
  */

/*
    map<int, int> m{ {1, 2}, {3, 4}, {5, 6} };
    
//    for (auto elem : m) {cout << elem.first << "->" << elem.second << ' ';} cout << endl;

    map<string, int> map1;
    map1["acb"] = 200; // inserts key = "b" with value = 200
    map1["abc"] = 100; // inserts key = "abc" with value = 100
    map1["cab"] = 400; // inserts key = "def" with value = 400
    map1["bca"] = 300; // inserts key = "c" with value = 300
    map1["bac"] = 333;
//    for (auto elem : map1) {cout << elem.first << "->" << elem.second << ' ';} cout << endl;

    map<string, int> map2(map1.begin(), map1.end());
//    for (auto elem : map2) {cout << elem.first << "->" << elem.second << ' ';} cout << endl;

    map<int, int> map3(m);
//    for (auto elem : map3) {cout << elem.first << "->" << elem.second << ' ';} cout << endl;
    
    map<int, A> map4;
    map4.emplace(3, A(3));
    map4.emplace(1, A(1));
    map4.insert(make_pair(5, A(5)));
    map4.insert(pair<int, A>(6, A(6)));
    cout << map4[5] << endl;
//    pair<int, A> highest = map4.rbegin();
    map<int, A>::iterator it;
//    while ((map4.value_comp()(*it++, highest)))
//    {
//        cout << it->first << "->" << it->second._x << endl;
//    }
    it = map4.find(5);
    cout << it->first << "->" << (*it).second._x << endl;
    map4.erase(it);
    map4.erase(1);
    for (auto elem : map4) {cout << elem.first << "->" << elem.second._x << ' ';} cout << endl;
    */
 
/*
    set<A> st;
    set<A>::iterator it;
    
    st.insert(5);
    st.insert(3);
    st.insert(7);
    st.insert(5);
    st.insert(9);
    st.emplace(6);
    it = st.begin();
    advance(it, 1);
    st.insert(it, 1);
    st.erase(3);
    it = st.find(9);
    st.erase(it);
    
    for (auto elem : st) {cout << elem._x << endl;}
*/
 
/*
    vector<A> v;
    vector<A>::iterator it;
    
    v.push_back(A(6));
    v.push_back(A(7));
    it = v.begin();
    it += 1;
    v.insert(it, A(8));
    it = v.begin();
    v.emplace(it + 1, A(9));
    
    it = find(v.begin(), v.end(), 8);
    v.erase(it);
    
    for (auto elem : v) {cout << elem._x << endl;}
*/
    
    return 0;
}

