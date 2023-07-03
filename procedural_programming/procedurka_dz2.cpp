1. Конус

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    float pi = atan(1) * 4;
    float r, rr, h, l;
    float volume, square;
    cout << "Введите радиус нижнего основания конуса:\n";
    cin >> rr;
    cout << "Введите радиус верхнего основания конуса:\n";
    cin >> r;
    cout << "Введите высоту конуса:\n";
    cin >> h;
    if ((rr-r) * (rr-r) + h * h >= 0){
        l = sqrt((rr-r) * (rr-r) + h * h);
    }
    else{
        cout << "Ошибка: извлечение корня из отрицательного числа" << endl;
        return 0;
    }
    volume = ((float) 1/3) * pi  * h * (rr * rr + rr * r + r * r);
    square = pi * (rr * rr + l * (rr + r) + r * r);
    cout << volume << " " << square << endl;
}

2. Разветвление

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    float x, a, w;
    cout << "Введите значение x:\n";
    cin >> x;
    cout << "Введите значение a:\n";
    cin >> a;
    if (abs(x) < 1){
        if (x != 0){
            w = a * log(abs(x));
        }
        else{
            cout << "Ошибка" << endl;
            return 0;
        }
    }
    else{
        if (a - x * x >= 0){
            w = sqrt(a - x * x);
        }
        else{
            cout << "Ошибка: извлечение корня из отрицательного числа";
            return 0;
        }
    }
    cout << w << endl;
}

3. Функция

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    float x, y, b;
    cout << "Введите значение x:\n";
    cin >> x;
    cout << "Введите значение y:\n";
    cin >> y;
    cout << "Введите значение b:\n";
    cin >> b;
    if (b-y > 0){
        if (b - x >= 0){
            cout << log(b-y) * sqrt(b-x) << endl;
        }
        else{
            cout << "Ошибка: извлечение корня из отрицательного числа" << endl;
            return 0;
        }
    }
    else{
        cout << "Ошибка: взятие логарифма от неположительного числа" << endl;
        return 0;
    }
}


4. Порядок

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    float n;
    int nn;
    int cc = 0;
    cout << "Введите значение числа:\n";
    cin >> n;
    nn = floor(n);
    if (n > 0){
        if (n > nn){
            for (int i = nn + 1; i < nn + 10; ++i){
                cout << i << endl;
            }
        }
        else{
            for (int i = nn; i < nn + 10; ++i){
                cout << i << endl;
            }
        }
    }
    else{
        for (int i = 0; i < 10; ++i){
            if (nn + i > 0){
                cout << nn + i << endl;
                cc++;
            }
        }
        if (cc == 0){
            cout << "Таких чисел нет" << endl;
        }
    }
    
}

5.

Табуляция

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;


int main(){
    cout << "Табуляция функции" << endl;
    for (float x = -4; x <= +4; x += 0.5){
        if (x != 1){
            cout << x << " -> " << (x * x - 2 * x + 2) / (x - 1) << endl;
        }
    }
}


