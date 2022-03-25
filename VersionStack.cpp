#include <iostream> 
#include <string>
#include <vector>

using namespace std;

struct stack {
    int storage[1000];
    int head;
    stack() {
        head = 0;
    }

    void push(int n) {
        storage[head] = n;
        head++;
    }

    void pop() {
		
        int storage2[1000];
        for (int i = 0; i < head - 1; i++) {
            storage2[i] = storage[i];
        }
        for (int i = 0; i < 1000; i++) {
            storage[i] = storage2[i];
        }
        head--;
    }
    string exit() {
        return "bye";
    }
};

int main() {
    string a;
    stack x;
    vector <stack> consists;
    while (cin >> a) {
        if (a == "push") {
            int n;
            cin >> n;
            x.push(n);
            cout << "ok" << endl;
        }
        if (a == "rollback") {
            int n;
            cin >> n;
            x = consists[n - 1];
            cout << "ok" << endl;
        }
        if (a == "pop") {
            x.pop();
            cout << "ok" << endl;
        }
        if (a == "forget") {
            vector <stack> consists2;
            consists = consists2;
            cout << "ok" << endl;
        }
        if (a == "exit") {
            cout << x.exit() << endl;
            break;
        }
        if (a != "forget") {
            consists.push_back(x);
        }
    }
    for (int i = 0; i < x.head; i++) {
        cout << x.storage[i] << endl;
    }
    return 0;
}