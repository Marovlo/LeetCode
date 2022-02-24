#include"resources.h"

class Solution
{
public:
	
};

class father
{
public:
    virtual void fun1() { cout << "father::fun1" << endl; }
};

class child :public father
{
public:
    void fun1() override{ cout << "child::fun1" << endl; }
};

class a
{
public:
    a() { cout << "a cons" << endl; }
    ~a() { cout << "a des" << endl; }
};

class b
{
public:
    b() { cout << "b cons" << endl; }
    ~b() { cout << "b des" << endl; }
};

class c
{
public:
    a aa;
    b bb;
    c()
    {
        aa = a();
        bb = b();
        cout << "c cons" << endl;
    }
    ~c()
    {
        aa.~a();
        bb.~b();
        cout << "b des" << endl;
    }
};


typedef struct NODE
{
    int data;
    shared_ptr<NODE> next;
    NODE(int a) :data(a),next(nullptr) {};
}node;


void shard_point_test()
{
    shared_ptr<node> sptr = make_shared<node>(0);
    shared_ptr<node> pre = sptr, cur = nullptr;
    for (int i = 1; i < 10; ++i)
    {
        cur = make_shared<node>(i);
        pre->next = cur;
        pre = pre->next;
    }
    while (sptr)
    {
        cout << sptr->data << " ";
        sptr = sptr->next;
    }
    cout << "\n";
    shared_ptr<int> t = make_shared<int>(1);
    shared_ptr<int>* p;
    p = &t;
    cout << (**p);
}


void pointer_size_test()
{
    int* i;
    cout << sizeof(i);
    int a = 10;
    int& b = a;
    vector<int> c(10, 100);
    vector<int>& d = c;
    cout << endl << sizeof(b) << endl;
    cout << sizeof(c) << endl;
}

class m { 
    int a[10];
    virtual void f() = 0;
};
int main(void)
{
    cout << sizeof(m) << endl;
    return 0;
}