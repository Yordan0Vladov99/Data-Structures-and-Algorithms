#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Student
{
    string name;
    long long group;
    long long order;
    Student()
    {
        this->name = "";
        this->group = 0;
        this->order = 0;
    }
    Student(string _name, long long _group, long long _order)
    {
        this->name = _name;
        this->group = _group;
        this->order = _order;
    }
};
ostream & operator << (ostream &out, const Student &c)
{
    out << c.name;
    out << " " << c.order;
    return out;
}
int main()
{
    long long N;
    long long R;
    cin >> N >> R;
    Student* s = new Student[N];
    queue<long long> GroupOrder;
    queue<Student>* Queue = new queue<Student>[R + 1];
    
    for (long long i = 0; i < N; i++)
    {
        cin >> s[i].name >> s[i].group;
        s[i].order = i;
    }
    long long counter = 0;
    for (long long i = 0; i < N; i++)
    {
        if (Queue[s[i].group].empty())
        {
            GroupOrder.push(s[i].group);
        }
        Queue[s[i].group].push(s[i]);
        if (i % 2 == 0 && i > 0)
        {
            cout << Queue[GroupOrder.front()].front() << " " << i << endl;
            Queue[GroupOrder.front()].pop();
            if (Queue[GroupOrder.front()].empty())
            {
                GroupOrder.pop();
            }
            counter = i;
        }
    }
    while (counter < 2*N)
    {
        counter += 2;
        cout << Queue[GroupOrder.front()].front() << " " << counter << endl;
        Queue[GroupOrder.front()].pop();
        if (Queue[GroupOrder.front()].empty())
        {
            GroupOrder.pop();
        }
    }
    return 0;
}