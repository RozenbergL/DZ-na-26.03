#include <iostream> 
#include <string>
using namespace std;
 
struct queue{
    int storage[100000];
    int start;
    int finish;
    queue(){
        start = 0;
        finish = 0;
    }
 
    void push(int n){
        storage[finish] = n;
        finish++;
    }
 
    int pop(){
        int a = storage[start];
        start++;
        return a;
    }
 
    int front(){
        return storage[start];
    }
 
    int size(){
        return finish - start;
    }
 
    string clear(){
        finish = 0;
        start = 0;
        return "ok";
    }
 
    string exit(){
        return "bye";
    }
};
 
int main() {
    string a;
    int ccc = 0;
    queue x;
    while(cin >> a){
        if(a == "push"){
            int n;
            cin >> n;
            x.push(n);
            cout << "ok" << endl;
            ccc++;
        }
        if(a == "pop"){
        	if (ccc == 0){
        		cout << "error\n";
        	}else{
            	cout << x.pop() << endl;
            	ccc--;
        	}
        }
        if(a == "front"){
        	if (ccc == 0){
        		cout << "error\n";
        	}else{
        		cout << x.front() << endl;
        	}
        }
        if(a == "size"){
            cout << x.size() << endl;
        }
        if(a == "clear"){
            cout << x.clear() << endl;
            ccc = 0;
        }
        if(a == "exit"){
            cout << x.exit() << endl;
            return 0;
        }
    }
    return 0;
}