1. Алгоритм Евклида

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int gcd_d(int a, int b){
    if (a == 0)
        return b;
    return gcd_d(b % a, a);
}

int gcd_s(int a, int b){
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        return b;
    }
    return (gcd_s(b - a, a));
}

int main(){
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cout <<  "division: " << gcd_d(a, b) << " substracting: " << gcd_s(a ,b) << endl;
    return 0;
}

2. Решето Эратосфена

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

vector<bool> primes(int n){
    vector<bool> prime(n + 1);
    fill(prime.begin(), prime.end(), true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p   * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

int main()
{
    int a;
    vector<bool> hd;
    cout << "Enter end of range: " << endl;
    cin >> a;
    hd = primes(a);
    for (int i = 2; i < hd.size() - 1; i++) {
        if (hd[i]) {
            cout << i << endl;
        }
    }
    return 0;
}

3. Обработка текстовых файлов
// 19. Статистическая обработка текстового файла: поиск наиболее часто встречающегося символа.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
using namespace std;

int main(){
    map<char, int> arolf;
    string line;
    pair<char, int> maximka ((char)"!", 0);
    for (int i = 33; i <= 126; i++) {
        arolf[(char)i] = 0;
    }
    ofstream zorich ("zorich.txt");
    zorich << "hfy582093i09iz6u5jgf78689zz290!*kop[fod[zpplvmm,nqpp]a;z/mcnmbkjakjdlf2jn3n5bvmz3jkswbqhbxhgzzzbgjr8818937h4b37vb40z19054ofjk!!v87utv87h4" << endl;
    ifstream zzorich ("zorich.txt");
    while (getline(zzorich, line)) {
        for (auto c : line) {
            arolf[c]++;
        }
    }
    for (auto elem : arolf) {
        if (elem.second > maximka.second) {
            maximka = elem;
        }
    }
    cout << "The most common symbol is " << maximka.first << " counted " << maximka.second << " times" << endl;
    return 0;
}
// 39. Подсчет числа вхождений символов в текстовый файл.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
using namespace std;

int main(){
    map<char, int> arolf;
    string line;
    for (int i = 33; i <= 126; i++) {
        arolf[(char)i] = 0;
    }
    ofstream zorich ("zorich.txt");
    zorich << "hfy582093i09i6u5jgf78689290019054ofjkv87utv87h4" << endl;
    ifstream zzorich ("zorich.txt");
    while (getline(zzorich, line)) {
        for (auto c : line) {
            arolf[c]++;
        }
    }
    for (auto elem : arolf) {
        cout << "Symbol " << elem.first << " counted " << elem.second  << " times in a file" << endl;
    }
    return 0;
}

4. Ряды
//3)

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
using namespace std;

long long factorial(long long n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
double sinun(long long k) {
    double res = 0;
    for (long long i = 2; i < 2 * k; i += 2) {
        res += sin(i);
    }
    return res;
}
int main(){
    long long n;
    double result=0;
    cout << "Enter number of iterations: " << endl;
    cin >> n;
    for (long long i = 1; i < n; i++) {
        for (long long k = 2; k < 2 * i; k += 2) {
            result += factorial(n) / sinun(k);
        }
    }
    cout << result << endl;
    return 0;
}

//13)

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
using namespace std;

int main(){
    int m;
    cout << "Enter sum of digits: (less than 27)" << endl;
    cin >> m;
    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                if (a + b + c == m) {
                    cout << a * 100 + b * 10 + c << endl;
                }
            }
        }
    }
    return 0;
}

5. Файлы
// 3) Организовать файл 1, компонентами которого являются 10 целочисленных одномерных массивов.
// Максимальные и минимальные элементы всех массивов заменить на нули. Полученные массивы 
// сохранить в файл 2. 2. Каждый массив преобразовать в квадратную матрицу размера 10*10. Если 
// количество элементов недостаточно, то добавить их с использованием генератора случайных чисел. 
// Результат сохранить в файл 3. Предусмотреть возможность просмотра полученных файлов.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <random>
#include <windows.h>
#include <sstream>

using namespace std;

int main(){
    mt19937 rnd(time(nullptr));
    string line;
    ofstream zorich("zorich.txt");
    for (int j = 0; j < 10; j++) {
        int c = rnd() % 100;
        while (c == 0) {
            c = rnd() % 10;
        }
        for (int i = 0; i < c; i++) {
            int b = rnd() % 100;
            zorich << b << " ";
        }
        zorich << endl;
    }
    cout << "first stage completed" << endl;
    ifstream zzorich("zorich.txt");
    ofstream zorich2("zorich2.txt");
    while (getline(zzorich, line)) {
        vector<int> arolf;
        pair<int, int> maxim{ 0, 0 }, minim{ 0, INT_MAX };
        stringstream iss(line);
        int n;
        while (iss >> n) {
           arolf.push_back(n);
        }
        for (int i = 0; i < arolf.size(); i++) {
            if (arolf[i] > maxim.second) {
                maxim = make_pair(i, arolf[i]);
            }
            if (arolf[i] < minim.second) {
                minim = make_pair(i, arolf[i]);
            }
        }
        arolf[maxim.first] = 0;
        arolf[minim.first] = 0;
        for (auto c : arolf) {
            zorich2 << c << " ";
        }
        zorich2 << endl;
    }
    cout << "second stage completed" << endl;
    ifstream zzorich2("zorich2.txt");
    ofstream zorich3("zorich3.txt");
    for (int k = 0; k < 10; k++) {
        getline(zzorich2, line);
        if (!line.empty()) {
            int abolf[10][10];
            vector<int> helpa;
            stringstream iss(line);
            int n;
            while (iss >> n) {
                helpa.push_back(n);
            }
            int index = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (helpa.size() > index) {
                        abolf[i][j] = helpa[index];
                        index++;
                    }
                    else {
                        int d = rnd() % 100;
                        abolf[i][j] = d;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    zorich3 << abolf[i][j] << " ";
                }
                zorich3 << endl;
            }
            zorich3 << endl;
        }
    }
    cout << "third stage completed" << endl;
    while (true) {
        ifstream ss1("zorich.txt");
        ifstream ss2("zorich2.txt");
        ifstream ss3("zorich3.txt");
        string input;
        cout << "Enter stage(1/2/3) to view or exit to discard: " << endl;
        cin >> input;
        if (input == "exit") {
            return 0;
            ss1.close();
            ss2.close();
            ss3.close();
        }
        else {
            int iiput = stoi(input);
            int index = 1;
            switch (iiput) {
            case 1:
                while (getline(ss1, line)) {
                    cout << index << ". ";
                    for (auto a : line) {
                        cout << a;
                    }
                    cout << endl;
                    index++;
                }
                break;
            case 2:
                while(getline(ss2, line)) {
                    cout << index << ". ";
                    for (auto a : line) {
                        cout << a;
                    }
                    cout << endl;
                    index++;
                }
                break;
            case 3:
                cout << index << ". " << endl;
                index++;
                while (getline(ss3, line)) {
                    for (auto a : line) {
                        cout << a;
                    }
                    cout << endl;
                    if (line.empty() && index < 11) {
                        cout << index << ". " << endl;
                        index++;
                    }
                }
                break;
            default:
                cout << "something went wrong..." << endl;
                break;
            }
        }
    }
    return 0;
}


