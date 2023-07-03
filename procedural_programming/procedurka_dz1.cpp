
1. Имя

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout << "vlad" << endl;
}

2. Уравнение

#include <iostream>
#include <vector>
using namespace std;

int main(){
    float a, b;
    cin >> a >> b;
    cout << a+b << " " << a-b << " " << a*b << " ";
    if(b != 0){
        cout << (float) a / b << endl;;
    }
}

3. Ещё уравнение (в вещественных)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    float a, b, c;
    float x1, x2;
    cin >> a >> b >> c;
    if (a == 0){
        if (b == 0){
            if (c == 0){
                cout << "x - любое число" << endl;
                return 0;
            }
            else{
                cout << "Решений нет" << endl;
                return 0;
            }
        }
        else{
            cout << (float) -c / b << endl;
            return 0;
        }
    }
    else{
        float disc;
        disc = b * b - 4 * a * c;
        if (disc < 0){
            cout << "Вещественных решений нет" << endl;
        }
        else{
            x1 = (-b + sqrt(disc)) / (2 * a);
            x2 = (-b - sqrt(disc)) / (2 * a);
            cout << x1 << " " << x2 << endl;
        }
    }
}

4. Лампа со шторой

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    bool day, razdvin, lampa;
    cout << "На улице день? Введите 1, если на улице день, или 0 в противном случае\n";
    cin >> day;
    cout << "Включена ли лампа? Введите 1, если лампа включена, или 0 в противном случае\n";
    cin >> lampa;
    cout << "Раздвинуты ли шторы? Введите 1, если шторы раздвинуты, или 0 в противном случае\n";
    cin >> razdvin;
    if (day && razdvin || lampa){
        cout << "Светло" << endl;
    }
    else{
        cout << "Не светло" << endl;
    }
}




