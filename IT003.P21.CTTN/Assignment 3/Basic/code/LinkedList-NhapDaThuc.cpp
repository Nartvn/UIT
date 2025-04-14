#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


/// code here

vector < pair < double , int > > vc;
void Nhap(DATHUC B, double heso, int somu)
{
    //cout << heso << ' ' << somu << '\n';
    vc.push_back(pair<double, int >(heso, somu));
    return;
}

void Xuat(DATHUC B)
{
    bool ok = 0;
    bool check = 0;
    for (int i = 0 ; i < vc.size() ; ++i)
    {
        double heso = vc[i].first;
        int somu = vc[i].second;
        if (heso == 0) continue;
        if (ok)
        {
            if (heso >= 0) cout << '+';
            else cout << '-';

            if (abs(heso) == 1 && somu == 0)
            {
                cout << 1;
                continue;
            }

            if (abs(heso) != 1) cout << abs(heso);
            check = 1;

            if(somu == 1) cout << "x";
            else if (somu > 1) cout << "x^" << somu;
            else continue;
        }
        else
        {
            ok = 1;
            if (heso < 0) cout << '-';

            if (abs(heso) == 1 && somu == 0)
            {
                cout << 1;
                continue;
            }

            if (abs(heso) != 1) cout << abs(heso);
            check = 1;

            if(somu == 1)cout << "x";
            else if (somu > 1) cout << "x^" << somu;
            else continue;
        }
    }
    if (check == 0) cout << 0;
    cout << '\n';
    return;
}

double TinhDaThuc(DATHUC B, double x)
{
    double ans = 0;
    for (int i = 0 ; i < vc.size() ; ++i)
    {
        double heso = vc[i].first;
        double somu = vc[i].second;
        ///cout << i << " : " << heso << ' ' << somu << '\n';
        ans += (double)heso * pow(x, somu);
    }
    return ans;
}

/// end


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
