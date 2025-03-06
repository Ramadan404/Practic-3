#include <iostream>
#include <random>
using namespace std;
int main()
{   int x=0;
    int number;
    while(x!=1){
    setlocale(LC_ALL, "Russian");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    int secretNumber = distrib(gen);
    
    cout<<"Игра угадай число!\n"<<endl;  
    
    while(1){
        cout<<"Введите число: ";
        while (!(cin >> number)){
        cout << "Ошибка попробйуте еще раз \n Введите число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }
        
        if(number==secretNumber){
            cout<<"Вы угадали число, поздравляю!"<<endl;
            break;
        }else{if(number<secretNumber){cout<<"Неправильно, подксказка: загаданное число больше"<<endl; continue;}
        else{cout<<"Неправильно, подксказка: загаданное число меньше"<<endl;continue;}
            
        }
    }
    cout<<"Если хотите сыграть еше раз нажмите цифру 0, если хотите закончить нажмите 1\n";
    cin>>x;    
    }
    cout<<"До свидания, возвращайтесь еще ";
  
    
}