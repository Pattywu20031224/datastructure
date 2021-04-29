#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

#define MAX 5

class Stack {
    private:
            char item[MAX][20];
            int top;
    public:
            Stack();
            void push_f(void);
            void pop_f(void);
            void list_f(void);
};
Stack::Stack()
{
    top = -1;
}

void Stack::push_f(void){
    if (top >= MAX-1){
        cout<<"\n\nStack is full !\n";
    }else{
        top++;
        cout<<"\n\n Please enter item to insert: ";
        cin.getline(item[top], 21);
    }
}

void Stack::pop_f(void){
    if(top<0){
        cout<<"\n No item, stack is empty !\n";
    }else{
        cout<<"\n Item "<<item[top]<<" deleted\n";
        top--;
    }
}

void Stack::list_f(void){
    int count = 0, i;
    if(top < 0){
        cout<<"\n No item, stack is empty\n";
    }else{
        cout<<"\n ITEM\n ";
        cout<<"---------------\n";
        cout.setf(ios::left, ios::adjustfield);
        for(i=0; i<=top; i++){
            cout<<" ";
            cout.width(20);
            cout<<item[i]<<"\n";
            count++;
            if (count %20 ==0){
                getch();
            }
        }
        cout.setf(ios::left, ios::adjustfield);
        cout<<"---------------\n";
        cout<<"total item: "<<count<<"\n";
    }
}

int main(){
    Stack obj;
    char option;
    while(true){
        cout<<"\n******************************\n";
        cout<<"    <1> insert (push)\n";
        cout<<"    <2> delete (pop)\n";
        cout<<"    <3> list \n";
        cout<<"    <4> quit \n";
        cout<<"******************************\n";
        cout<<"Please enter your choice...";
        while(cin.get(option) && option =='\n');
        cin.get();
        switch(option){
            case '1': obj.push_f();
                        break;
            case '2': obj.pop_f();
                        break;
            case '3': obj.list_f();
                        break;
            case '4': system("PAUSE");
                        return 0;

        }
    }
    return 0;
}