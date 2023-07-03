1. Спиннеры

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

int main() {
    long a, b, c;
    cin >> a >> b >> c;
    cout << (c - a) / b << endl;
    return 0;
}

2. Снова спиннеры

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

int main() {
    long m;
    cin >> m;
    long four = m % 3;
    if ((m - 4 * four) / 3 >= 0) {
        cout << (m - 4 * four) / 3 << endl << four << endl;
    }
    else {
        cout << 0 << endl << 0 << endl;
    }
    return 0;
}

3. Не про спиннеры

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

int main() {
    long n, m;
    cin >> n >> m;
    cout << n * (n + 1) / 2 * m * (m + 1) / 2 << endl;
    return 0;
}

4. Плацкартный вагон

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

long section(long k) {
    if (k <= 36) {
        return (k - 1) / 4;
    }
    else {
        return 8 - (k - 37) / 2;
    }
}

int main() {
    vector<long> counter(9, 0);
    long n, h, answr=0, tod=0;
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> h;
        counter[section(h)]++;
    }
    for (int i = 0; i < 9; i++) {
        if (counter[i] == 6) {
            tod++;
            answr = max(answr, tod);
        }
        else {
            tod = 0;
        }
    }
    cout << answr << endl;
    return 0;
}

5. Кинотеатр

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

int main() {
    map<long, long> arolf;
    long n, k, m, counter, ans1, ans2;
    cin >> n >> k;
    arolf[n] = 1;
    while (k > 0) {
        m = 0;
        for (auto a : arolf) {
            m = max(m, a.first);
        }
        counter = min(k, arolf[m]); 
        arolf.erase(m);
        k -= counter;
        ans1 = (m - 1) / 2;
        ans2 = m - 1 - ans1;
        if (arolf.count(ans1) >= 1) {
            arolf[ans1] += counter;
        }
        else {
            arolf[ans1] = counter;
        }
        if (arolf.count(ans2) >= 1) {
            arolf[ans2] += counter;
        }
        else {
            arolf[ans2] = counter;
        }
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}

