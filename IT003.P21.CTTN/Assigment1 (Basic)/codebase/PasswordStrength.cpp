#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
char err[] = {'.', (char)92, '/', ' ', ','};

void check()
{
    if (s.size() < 8)
    {
        cout << "KhongHopLe";
        exit(0);
    }

    for (int i = 0 ; i < s.size() ; ++i)
    {
        char c = s[i];
        for (int i = 0 ; i <= 4 ; ++i)
            if (c == err[i])
            {
                cout << "KhongHopLe";
                exit(0);
            }
    }
}

bool TinhInHoa()
{
    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] >= 'A' && s[i] <= 'Z')
            return 1;
    return 0;
}

bool TinhChuSo()
{
    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] >= '0' && s[i] <= '9')
            return 1;
    return 0;
}

bool TinhDacBiet()
{
    char val[] = {'!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' , '?' , '_' , '~'};
    for (int i = 0 ; i < s.size() ; ++i)
        for (int j = 0 ; j <= 10 ; ++j)
            if (s[i] == val[j])
                return 1;
    return 0;
}

int check_Bonus_FlatLower()
{
    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] <= 'a' || s[i] > 'z') return 0;
    return -15;
}

int check_Bonus_FlatNumber()
{
    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] <= '0' || s[i] > '9') return 0;
    return -35;
}

void Solve()
{
    int InHoa = TinhInHoa();
    int DacBiet = TinhDacBiet();
    int ChuSo = TinhChuSo();
    //-----------------------
    int BaseScore = 40;
    int Bonus_Excess = 3;
    int Bonus_Upper = 4;
    int Bonus_Number = 5;
    int Bonus_Symbols = 5;

    int Bonus_Combo = InHoa + DacBiet + ChuSo;
    if (Bonus_Combo == 3) Bonus_Combo = 25;
    else if (Bonus_Combo == 2) Bonus_Combo = 15;
    else Bonus_Combo = 0;

    int Bonus_FlatLower = check_Bonus_FlatLower();
    int Bonus_FlatNumber = check_Bonus_FlatNumber();
    int Number_Execess = (int)s.size() - 8;

    int Number_Upper = 0;
    for (int i = 0 ; i < s.size() ; ++i)
        Number_Upper += (s[i] >= 'A' && s[i] <= 'Z');

    int Number_Numbers = 0;
    for (int i = 0 ; i < s.size() ; ++i)
        Number_Numbers += (s[i] >= '0' && s[i] <= '9');

    int Number_Symbols = 0;
    char val[] = {'!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' , '?' , '_' , '~'};
    for (int i = 0 ; i < s.size() ; ++i)
        for (int j = 0 ; j <= 10 ; ++j)
            Number_Symbols += (s[i] == val[j]);

    int score = BaseScore + (Number_Execess * Bonus_Excess)
            + (Number_Upper * Bonus_Upper)+ (Number_Numbers * Bonus_Number) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower
            + Bonus_FlatNumber;

    if (score < 50) cout << "Yeu";
    else if (score < 75) cout << "Vua";
    else if (score < 100) cout << "Manh";
    else cout << "RatManh";
    return;
}

int32_t main()
{
    cin >> s;
    check();
    Solve();
    return 0;
}