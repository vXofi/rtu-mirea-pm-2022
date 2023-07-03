1. Заём

#include <bits/stdc++.h>

using namespace std;


int main(){
    float s, p, n, m, r;
    cout << "Введите значение S >> ";
    cin >> s;
    cout << endl;
    cout << "Введите значение p >> ";
    cin >> p;
    cout << endl;
    cout << "Введите значение n >> ";
    cin >> n;
    cout << endl;
    r = p / 100;
    m = s * r * pow(1+r, n) / (12 * (pow(1+r, n) - 1));
    cout << m;
}

2. Ссуда

#include <bits/stdc++.h>

using namespace std;


int main(){
    float s, n, m, r, min=INFINITY, win, att;
    cout << "Введите значение S >> ";
    cin >> s;
    cout << endl;
    cout << "Введите значение m >> ";
    cin >> m;
    cout << endl;
    cout << "Введите значение n >> ";
    cin >> n;
    cout << endl;
    for (float p = 0.0001; p < 100; p += 0.0001){
        r = p / 100;
        att = abs(s * r * pow(1+r, n) / (12 * (pow(1+r, n) - 1)) - m);
        if (att < min){
            win = p;
            min = att;
        }
    }
    cout << win << endl;
}

3. Копирование файла

#include <bits/stdc++.h>
#include <windows.h>

using namespace std;


int main(){
    ofstream zorich ("zorich.txt");
    ShellExecuteW(NULL, L"open", L"D:\\cppProjects\\zorich.txt", NULL, L"D:\\cppProjects\\", SW_SHOW);
    zorich.close();

    return 0;
}

4. Фильтр

#include <bits/stdc++.h>

using namespace std;


int main(){
    string line;
    ofstream zorich ("zorich.txt");
    zorich << "hfy582093i09i6u5jgf78689290019054ofjkv87utv87h4" << endl;
    ifstream zzorich ("zorich.txt");
    while (getline(zzorich, line)){
        for(char& c : line) {
            int cc = int(c);
            if (cc <= 57 && cc >= 48){
                cout << c; 
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    zorich.close();
    return 0;
}

5. Сортировка букв

#include <bits/stdc++.h>

using namespace std;


int main(){
    string line;
    vector<char> arolf, aRolf;
    line = "BNGJDKGHTOFPKGLVHQZCMANVHGOTJDajfkqokpoivnnfmdhjiebhs";
    cout << "До сортировки:\n" << line << endl; 
    for (char&c : line){
        if (c >= 'a' && c <= 'z'){
            arolf.push_back(c);
        }
        if (c >= 'A' && c <= 'Z'){
            aRolf.push_back(c);
        }
    }
    sort(arolf.begin(), arolf.end());
    sort(aRolf.begin(), aRolf.end());
    cout << "После сортировки:\n";
    int ukaz=0, Ukaz=0;
    ukaz = 0;
    Ukaz = 0;
    for (int i=0; i < size(aRolf); i++){
        if (i != size(aRolf)){
            if (aRolf[i] != aRolf[i + 1]){
                cout << aRolf[i];
                while (arolf[ukaz] <= tolower(aRolf[i]) && ukaz < size(arolf)){
                    cout << arolf[ukaz];
                    ukaz++;
                }
                while (arolf[ukaz] < tolower(aRolf[i + 1]) && ukaz < size(arolf)){
                    cout << arolf[ukaz];
                    ukaz++;
                }
            }
            else{
                cout << aRolf[i];
            }
        }
        else{
            cout << aRolf[i];
            while (arolf[ukaz] == tolower(aRolf[i]) && ukaz < size(arolf)){
                    cout << arolf[ukaz];
                    ukaz++;
                }
        }
    }
    for (int i = ukaz; i < size(arolf); i++){
        cout << arolf[i];
    }
    cout << endl;
    return 0;
}

