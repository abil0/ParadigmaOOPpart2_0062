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

