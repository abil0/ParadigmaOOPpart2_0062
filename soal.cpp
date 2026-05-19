#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
protected:
    string namaNasabah;
    int saldo;

public:
    RekeningBank(string nama, int saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0; 
    int getSaldo() {
        return saldo;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, int saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Memproses Nasabah (Syariah) : " << namaNasabah << endl;
        cout << "Status: Bebas biaya admin. Saldo tetap: Rp " << saldo << "\n" << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, int saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Memproses Nasabah (Konvensional) : " << namaNasabah << endl;
        saldo -= 15000; 
        cout << "Status: Dipotong admin Rp 15.000. Saldo akhir: Rp " << saldo << "\n" << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, int saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Memproses Nasabah (Premium) : " << namaNasabah << endl;
        if (saldo > 10000000) {
            cout << "Status: Saldo > Rp 10.000.000. Bebas biaya admin. Saldo akhir: Rp " << saldo << "\n" << endl;
        } else {
            saldo -= 50000;
            cout << "Status: Saldo <= Rp 10.000.000. Dipotong admin Rp 50.000. Saldo akhir: Rp " << saldo << "\n" << endl;
        }
    }
};

int main() {
    cout << " Sistem Automasi Akhir Bulan Bank Gibran Jaya " << "\n\n";
    RekeningBank* daftarRekening[4];
    RekeningSyariah nasabah1("Pakaya", 5000000);
    RekeningKonvensional nasabah2("anton", 2500000);
    RekeningPremium nasabah3("yudi", 15000000); 
    RekeningPremium nasabah4("Enggar", 8000000);  
    daftarRekening[0] = &nasabah1;
    daftarRekening[1] = &nasabah2;
    daftarRekening[2] = &nasabah3;
    daftarRekening[3] = &nasabah4;

    for (int i = 0; i < 4; i++) {
        daftarRekening[i]->potongAdmin();
    }

    return 0;
}