#include<iostream>
using namespace std;

class remoteLampu {
private:
    string saklarNo[10];
public:
    void setsaklarNo( int i, string value) {
        saklarNo[i] = value;
    }
    string getsaklarNo(int i) {
        return saklarNo[i];
    }
};

int main() {
   remoteLampu lampuRumah;
    
    lampuRumah.setsaklarNo(0, "lampu teras rumah");
    lampuRumah.setsaklarNo(1, "lampu ruang tamu");
    lampuRumah.setsaklarNo(2, "lampu kamar tidur");
    lampuRumah.setsaklarNo(3, "lampu dapur");

    cout << lampuRumah.getsaklarNo(0) << endl;
    cout << lampuRumah.getsaklarNo(1) << endl;
    cout << lampuRumah.getsaklarNo(2) << endl;
    cout << lampuRumah.getsaklarNo(3) << endl;

    return 0;



}