#include <iostream>
// #include <vector>
#include <string>

using namespace std;

// #define int long long

struct circle
{
    string data;
    circle *next;
};

circle *newNode(string data)
{
    circle *temp = new circle;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(circle *&head, string data)
{
    circle *temp = newNode(data);
    temp->next = head;
    head = temp;
}

void deleteNode(circle *&head, string data)
{
    circle *temp = head;
    if (temp->data == data)
    {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            circle *temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n;
    cin >> n;
}