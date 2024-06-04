#include <iostream>
using namespace std;

const int JUMLAH_TRIBUN = 4;

// struct (ini agar menyatu dengan array)
struct Tribun {
    string nama;
    int harga;
};

// array
Tribun daftarTribun[JUMLAH_TRIBUN] = {
    {"TRIBUN BARAT (VIP)", 100000},
    {"TRIBUN UTARA (REGULER)", 50000},
    {"TRIBUN TIMUR (REGULER)", 50000},
    {"TRIBUN SELATAN (REGULER)", 50000}
};

void inputNama(string &nama) {
    cout << "MASUKAN NAMA : ";
    cin >> nama;
}

void inputUmur(int &umur) {
    cout << "MASUKAN UMUR : ";
    cin >> umur;
}

void printTicket(string nama, int umur, int tribun, int zona, int metodepembayaran, int print, int jumlahTiket, int kursi, string metodeBayarDetail) {
    int hargaTiket = 0;

    if (print == 1) {
        cout << "==============PRINT TIKET==============" << endl;
        cout << endl;
        cout << "------------------" << endl;
        cout << "ATAS NAMA : " << nama << ", " << umur << " tahun" << endl;

        cout << "TRIBUN : ";
        switch (tribun) {
            case 1:
                cout << "TRIBUN BARAT (VIP)";
                hargaTiket = 100000;
                break;
            case 2:
                cout << "TRIBUN UTARA (REGULER)";
                hargaTiket = 50000;
                break;
            case 3:
                cout << "TRIBUN TIMUR (REGULER)";
                hargaTiket = 50000;
                break;
            case 4:
                cout << "TRIBUN SELATAN (REGULER)";
                hargaTiket = 50000;
                break;
            default:
                cout << "Tidak Valid";
                break;
        }
        cout << endl;

        cout << "ZONA : " << zona << endl;
        cout << "KURSI : " << kursi << endl;
        cout << "METODE PEMBAYARAN : ";

        switch (metodepembayaran) {
            case 1:
                cout << "Cash (Silahkan bayar di tempat)";
                break;
            case 2:
            case 3:
                cout << metodeBayarDetail;
                break;
            default:
                cout << "Tidak Valid";
                break;
        }
        cout << endl;

        int totalHarga = hargaTiket * jumlahTiket;
        cout << "TOTAL HARGA TIKET (" << jumlahTiket << " tiket): Rp " << totalHarga << endl;
        cout << "---------------------------------------" << endl;
        cout << "DUKUNG TIM KESAYANGANMU !!" << endl;
        cout << "---------------------------------------" << endl;
    } else {
        cout << "ANDA TIDAK MENGEPRINT TIKET\n";
    }
}

void pilihZona(int tribun, int &zona, int &kursi) {
    cout << "===========SILAHKAN PILIH ZONA===========" << endl;
    for (int i = 1; i <= 4; ++i) {
        cout << i << ". ZONA " << i << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi Zona : ";
    cin >> zona;
    cout << "-------------------------------------------" << endl;

// perulangan nested loop
    if (tribun == 1 && zona <= 4) {
        int kursi1 = 0;
        cout << "PILIHAN KURSI VIP: " << endl;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 15; j++) {
                if (kursi1 < 105) {
                    cout << kursi1 + 1 << '\t';
                    kursi1++;
                }
            }
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
        cout << "Pilih Nomor Posisi kursi : ";
        cin >> kursi;
        cout << "-------------------------------------------" << endl;
        cout << endl;
    } else {
        kursi = -1; // Tidak perlu memilih kursi untuk tribun reguler
    }
}

void pilihTribun(int &tribun) {
    cout << "===========SILAHKAN PILIH TRIBUN===========" << endl;

    for (int i = 0; i < JUMLAH_TRIBUN; ++i) {
        cout << i + 1 << ". " << daftarTribun[i].nama << " : RP " << daftarTribun[i].harga << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi Tribun : ";
    cin >> tribun;
    cout << "-------------------------------------------" << endl;

    if (tribun < 1 || tribun > JUMLAH_TRIBUN) {
        cout << "Nomor Tribun Tidak Valid" << endl;
    }
}

void pilihMetodePembayaran(int &metodebayar, string &metodeBayarDetail) {
    cout << "=========== PILIH METODE PEMBAYARAN ===========" << endl;
    cout << "1. Cash" << endl;
    cout << "2. Transfer" << endl;
    cout << "3. e-Wallet" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi Metode Pembayaran : ";
    cin >> metodebayar;
    cout << "---------------------------------------------" << endl;

    switch (metodebayar) {
        case 2:
            pilihBank(metodeBayarDetail);
            break;
        case 3:
            pilihEWallet(metodeBayarDetail);
            break;
        case 1:
            metodeBayarDetail = "Cash (Silahkan bayar di tempat)";
            break;
        default:
            cout << "Metode Pembayaran Tidak Valid" << endl;
            metodeBayarDetail = "Tidak Valid";
            break;
    }
}

void pilihBank(string &bankDetail) {
    int bank;
    cout << "=========== PILIH BANK ===========" << endl;
    cout << "1. BNI" << endl;
    cout << "2. BRI" << endl;
    cout << "3. BCA" << endl;
    cout << "----------------------------------" << endl;
    cout << "Pilih Nomor Posisi Bank : ";
    cin >> bank;
    cout << "----------------------------------" << endl;

    switch (bank) {
        case 1:
            bankDetail = "Transfer (BNI)";
            break;
        case 2:
            bankDetail = "Transfer (BRI)";
            break;
        case 3:
            bankDetail = "Transfer (BCA)";
            break;
        default:
            bankDetail = "Transfer (Tidak Valid)";
            break;
    }
}

void pilihEWallet(string &eWalletDetail) {
    int eWallet;
    cout << "=========== PILIH LAYANAN e-WALLET ===========" << endl;
    cout << "1. Gopay" << endl;
    cout << "2. Dana" << endl;
    cout << "3. Akulaku" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi e-Wallet : ";
    cin >> eWallet;
    cout << "---------------------------------------------" << endl;

    switch (eWallet) {
        case 1:
            eWalletDetail = "e-Wallet (Gopay)";
            break;
        case 2:
            eWalletDetail = "e-Wallet (Dana)";
            break;
        case 3:
            eWalletDetail = "e-Wallet (Akulaku)";
            break;
        default:
            eWalletDetail = "e-Wallet (Tidak Valid)";
            break;
    }
}

int main() {
    int umur, jadwal, tribun, zona, print, metodebayar, jumlahTiket, kursi;
    string nama, metodeBayarDetail;

    char pesanLagi;

    do {
        system("cls");
        cout << "=====PEMBELIAN TIKET =====" << endl;
        cout << "-----------------------------------------------" << endl;
        inputNama(nama);
        inputUmur(umur);

        if (umur <= 8) {
            cout << "MAAF ANDA TIDAK BISA MEMBELI TIKET DIKARENAKAN MASIH DIBAWAH UMUR\n";
        } else {
            cout << "-----------------------------------------------" << endl;
            cout << "===============PILIH PERTANDINGAN===============" << endl;
            cout << "1. MAN. CITY VS BAYERN MUNCHEN  :  15.30PM" << endl;
            cout << "2. REAL MADRID VS MAN. UNITED  :  19.45PM" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "SILAHKAN PILIH JADWAL PERTANDINGAN : ";
            cin >> jadwal;
            cout << "-----------------------------------------------" << endl;

            if ((jadwal == 1) || (jadwal == 2)) {
                cout << (jadwal == 1 ? "========MAN. CITY VS BAYERN MUNCHEN========" : "========REAL MADRID VS MAN. UNITED========") << endl;
                pilihTribun(tribun);
                cout << "Masukkan Jumlah Tiket: ";
                cin >> jumlahTiket;
                pilihZona(tribun, zona, kursi);
                pilihMetodePembayaran(metodebayar, metodeBayarDetail);

                cout << "-------------------------------------------\n";

                cout << "=======APAKAH ANDA INGIN PRINT TIKET?=======" << endl;
                cout << "1.YA\n";
                cout << "2.TIDAK\n";
                cout << "-------------------------------------------\n";
                cin >> print;
                cout << "-------------------------------------------\n";

                printTicket(nama, umur, tribun, zona, metodebayar, print, jumlahTiket, kursi, metodeBayarDetail);
            } else {
                cout << "MAAF TIDAK ADA JADWAL DI WAKTU TERSEBUT\n";
            }
        }

        cout << "Apakah Anda ingin memesan tiket lagi? (y/n): ";
        cin >> pesanLagi;

    } while (pesanLagi == 'y' || pesanLagi == 'Y');
    system("cls");

    return 0;
}
