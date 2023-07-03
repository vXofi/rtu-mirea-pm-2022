1. Файл

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;


int main(){
    float ss = 0;
    string line;
    ofstream zorich ("zorich.txt");
    for (float i = 12; i < 12 + 12; i += 1.2){
        zorich << i << endl;
    }
    zorich.close();
    ifstream zzorich ("zorich.txt");
    while (getline(zzorich, line)){
        ss += stof(line);
    }
    cout << ss << endl;
    return 0;
}

2. Знак числа

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int sign(float x){
    if (x > 0){
        return 1;
    }
    else if (x == 0){
        return 0;
    }
    else{
        return -1;
    }
}

int main(){
    float n;
    cout << "Введите число:" << endl;
    cin >> n;
    cout << sign(n);
    return 0;
}

3. Геометрические фигуры

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;


float kub(float k, float q){
    return k*q;
}

float krug(float r){
    return r * r * atan(1) * 4;
}

float treyg(float k, float q, float v){
    float pol = (k + q + v) / 2;
    return sqrt(pol * (pol - k) * (pol - q) * (pol - v));
}

int main(){
    float n;
    float a, b, c;
    cout << "Укажите номер искомой фигуры (1. прямоугольник/2. треугольник/3. круг):\n";
    cin >> n;
    if (n == 1){
        cout << "Введите длину первой стороны прямоугольника:\n";
        cin >> a;
        cout << "Введите длину второй стороны прямоугольника:\n";
        cin >> b;
        cout << kub(a, b) << endl;
    }
    else if (n == 2){
        cout << "Введите длину первой стороны треугольника:\n";
        cin >> a;
        cout << "Введите длину второй стороны треугольника:\n";
        cin >> b;
        cout << "Введите длину третьей стороны треугольника:\n";
        cin >> c;
        cout << treyg(a, b, c) << endl;
    }
    else if (n == 3){
        cout << "Введите радиус круга:\n";
        cin >> a;
        cout << krug(a) << endl;
    }
    else{
        cout << "Ошибка ввода данных" << endl;
    }
    return 0;
}

4. Былая слава

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int a, b;
	for (int i = 0; i < 13; i++) {
		if (i < 6) {
			if (i % 2 == 0) {
				for (int j = 0; j < 64; j++) {
					if (j < 17) {
						if (j % 2 != 0) {
							cout << "*";
						}
						else {
							cout << " ";
						}
					}
					else {
						cout << " ";
					}
				}
				cout << endl;
			}
			else {
				for (int j = 0; j < 64; j++) {
					if (j < 17) {
						if (j % 2 != 0) {
							cout << "*";
						}
						else {
							cout << " ";
						}
					}
					else {
						cout << "*";
					}
				}
				cout << endl;
			}
		}
		else {
			if (i % 2 == 0) {
				for (int j = 0; j < 64; j++) {
					cout << " ";
				}
				cout << endl;
			}
			else {
				for (int j = 0; j < 64; j++) {
					cout << "*";
				}
				cout << endl;
			}
		}
	}
	return 0;
}

5. Синусоида

#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int main() {
	float pi = atan(1) * 4;
	vector<vector<string>> arolf(17, vector<string>(128));
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 128; j++) {
			if (i == 9) {
				if (j == 127) {
					arolf[i][j] = ">";
				}
				else if (j == 0) {
					arolf[i][j] = "+";
				}
				else{
					arolf[i][j] = "-";
				}
			}
			else if (j == 0) {
				arolf[i][j] = "|";
			}
			else {
				arolf[i][j] = ".";
			}
		}
	}
	for (float i = 0; i < 128; i++) {
		float xd = sin(i/(2 * pi)) * 8;
		arolf[int(xd + 9)][i] = "*";
	}
	 for (int i = 1; i < 17; i++) {
		for (int j = 0; j < 128; j++) {
			cout << arolf[i][j];
		}
		cout << endl;
	}
	return 0;
}

6. Автоматный распознователь

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int cringe_to_baza(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;
	return -1;
}

bool isValid(string& roman) {
	int n = roman.size();
	if (n == 1) return true;
	for (size_t i = 0; i < n; i++) {
		if (cringe_to_baza(roman[i]) >= cringe_to_baza(roman[i + 1]) ||
			(5 * cringe_to_baza(roman[i]) == cringe_to_baza(roman[i + 1]) && cringe_to_baza(roman[i - 1]) != cringe_to_baza(roman[i])) ||
			(10 * cringe_to_baza(roman[i]) == cringe_to_baza(roman[i + 1]) && cringe_to_baza(roman[i - 1]) != cringe_to_baza(roman[i])));
		else return false;
	}
	return true;
}

int task(string& str) {
	int res = 0;

	for (int i = 0; i < str.length(); i++) {
		int s1 = cringe_to_baza(str[i]);
		if (i + 1 < str.length()) {
			int s2 = cringe_to_baza(str[i + 1]);
			if (s1 >= s2) {
				res = res + s1;
			}
			else {
				res = res + s2 - s1;
				i++;
			}
		}
		else {
			res = res + s1;
		}
	}
	return res;
}

int main() {
	string word;
	cout << "Введите число в римской системе счисления (допускаются только символы {I, V, X, L, C, D, M}):" << endl;
	cin >> word;
	if (isValid(word)) {
		cout << task(word) << endl;
	}
	else {
		cout << "Not a valid number";
	}
	return 0;
}

7. Генератор псевдослучайных чисел

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int type1(int iter){
	int m = 37, b = 3, c = 64;
	if (iter != 0) {
		return(m * type1(iter - 1) + b) % c;
	}
	else {
		return (m * 0 + b) % c;
	}
}

int type2(int iter) {
	int m = 25173, b = 13849, c = 65537;
	if (iter != 0) {
		return (m * type2(iter - 1) + b) % c;
	}
	else {
		return (m * 0 + b) % c;
	}
}


int main()
{
	int a;
	cout << "Введите число итераций: " << endl;
	cin >> a;
	cout << type1(a) << " " << type2(a) << endl;
	return 0;
}


8. Умножение матриц

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

vector<vector<float>> multik(vector<vector<float>> mat1, vector<vector<float>> mat2){
    const int row = mat1.size();
    const int cols1 = mat1[0].size();
    const int cols2 = mat2[0].size();
    vector<vector<float>> rslt(row, vector<float>(cols2, 0));
    for (int i = 0; i < cols2; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < row; k++) {
                rslt[k][i] += mat1[k][j] * mat2[j][i];
            }
        }
    }   
    return rslt;
}

int main(){
    vector<vector<float>> arolf = {
        {5, 2, 0, 10},  
        {3, 5, 2, 5},
        {3, 20, 0, 0}
    }, abolf = {
        {1.20, 0.5},
        {2.8, 0.4},
        {5., 1.},
        {2., 1.5}
    }, c;
    c = multik(arolf, abolf);
    float d_maxim=0, dwin, dlose, kwin, klose, d_minim=INT_MAX, k_maxim=0, k_minim=INT_MAX, dsum=0,ksum=0;
    for (int i = 0; i < c.size(); i++) {
        vector<float> n = c[i];
        dsum += n[0];
        ksum += n[1];
        if (n[0] > d_maxim) {
            d_maxim = n[0];
            dwin = i + 1;
        }
        if (n[1] > k_maxim) {
            k_maxim = n[1];
            kwin = i + 1;
        }
        if (n[0] < d_minim) {
            d_minim = n[0];
            dlose = i + 1;
        }
        if (n[1] < k_minim) {
            k_minim = n[1];
            klose = i + 1;

        }
        // вывод матрицы С
        //for (auto b: n){
        //    cout << setw(4) << b << " ";
        //}
        //cout << endl;
    }
    cout << "Больше выручил продавец " << dwin << endl;
    cout << "Меньше выручил продавец " << dlose << endl;
    cout << "Больше комиссионных получил " << kwin << endl;
    cout << "Больше комиссионных получил " << klose << endl;
    cout << "Общая сумма выручки составила " << dsum << endl;
    cout << "Всего комиссионных получили " << ksum << endl;
    cout << "Общая сумма прошедших денег " << dsum + ksum << endl;

}

9. Системы счисления

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

char reVal(int num){
        if (num >= 0 && num <= 9)
            return (char)(num + '0');
        else
            return (char)(num - 10 + 'A');
    }

int toVal(char n) {
    if (n >= '0' && n <= '9') {
        return n - '0';
    }
    else {
        return 'A' + n - 120;
    }
}

string fromDeci(int base, int inputNum){
    string res;
    int index = 0;
    if (inputNum == 0) {
        return "0";
    }
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        index++;
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int toDeci(string num, int base) {
    int res = 0;
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.length(); i++) {
        res += toVal(num[i]) * pow(base, i);
    }
    return res;
}
int main(){
    int bases, based;
    string number;
    cout << "Введите число: " << endl;
    cin >> number;
    cout << "Введите исходную систему счисления: " << endl;
    cin >> bases;
    cout << "Введите основание новой системы счисления: " << endl;
    cin >> based;
    cout << fromDeci(based, toDeci(number, bases)) << endl;
    return 0;
}





