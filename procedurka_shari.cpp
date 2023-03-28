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
#include <algorithm>

using namespace std;

/// Из урны с 10 пронумерованными шариками вынимают по одному шарику. Подсчитать общее количество ситуаций, когда номер хотя бы одного
///  вынутого шарика совпадает с порядковым номером действия "вынимания", например, когда шарик N 3 будет вынут 3-им по порядку.

int main() {
    vector<int> arolf{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    long counter = 0;
    do {
        for (int i = 1; i < 11; i++) {
            if (arolf[i - 1] == i) {
                counter++;
                break;
            }
        }
    } while (next_permutation(arolf.begin(), arolf.end()));
    cout << counter << endl;
    return 0;
}
