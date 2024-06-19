// TUGAS BESAR PROGRAM STADION SEPAK BOLA
// IQBAL BAWANI (2311102130)
// RICO ADE PRATAMA (2311102138)
// DHEVA DEWA SEPTIANTONI (2311102324)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int JUMLAH_TRIBUN = 4;

struct Tribun
{
    string nama;
    int harga;
};

// Deklarasi fungsi pilihBank dan pilihEWallet
void pilihBank(string &bankDetail);
void pilihEWallet(string &eWalletDetail);

Tribun daftarTribun[JUMLAH_TRIBUN] = {
    {"TRIBUN BARAT   (VIP)"    , 100000},
    {"TRIBUN UTARA   (REGULER)", 50000},
    {"TRIBUN TIMUR   (REGULER)", 50000},
    {"TRIBUN SELATAN (REGULER)", 50000}};

// Fungsi untuk menerima input nama dari pengguna
void inputNama(string &nama)
{
    cout << "MASUKAN NAMA : ";
    cin.ignore();       // Mengabaikan newline karakter dari input sebelumnya
    getline(cin, nama); // Menggunakan getline agar bisa menerima spasi
}

// Fungsi untuk menerima input umur dari pengguna
void inputUmur(int &umur)
{
    cout << "MASUKAN UMUR : ";
    cin >> umur;
}

// Fungsi untuk mencetak tiket dengan rincian yang sesuai
void printTicket(string nama, int umur, int tribun, int zona, int metodepembayaran, int print, int jumlahTiket, vector<int> &kursi, string metodeBayarDetail)
{
    int hargaTiket = 0;

    if (print == 1)
    {
        cout << "\n--------------------------------------------------------------------------" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRINT TIKET <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "ATAS NAMA         : " << nama << ", " << umur << " tahun" << endl;

        cout << "POSISI TRIBUN     : " << daftarTribun[tribun - 1].nama;
        hargaTiket = daftarTribun[tribun - 1].harga;
        cout << endl;

        cout << "POSISI ZONA       : " << zona << endl;
        cout << "JUMLAH TIKET      : " << jumlahTiket << endl;
        cout << "POSISI KURSI      : ";
        if (tribun == 1) // Jika tribun adalah VIP
        {
            for (int i = 0; i < jumlahTiket; ++i)
            {
                cout << kursi[i];
                if (i < jumlahTiket - 1)
                    cout << ", ";
            }
        }
        else // Jika tribun adalah Reguler
        {
            cout << "Bebas";
        }
        cout << endl;

        cout << "METODE PEMBAYARAN : " << metodeBayarDetail << endl;

        int totalHarga = hargaTiket * jumlahTiket;
        cout << "TOTAL HARGA TIKET (" << jumlahTiket << " tiket): Rp " << totalHarga << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "TERIMA KASIH TELAH MEMBELI TIKET INI !!" << endl;
        cout << "AYOO DUKUNG TIM KESAYANGANMU !!" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "ANDA TIDAK MENGEPRINT TIKET\n";
    }
}

// Fungsi untuk memilih zona penonton
void pilihZona(int tribun, int &zona, vector<int> &kursi, int jumlahTiket)
{
    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>> SILAHKAN PILIH ZONA <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 1; i <= 4; ++i)
    {
        cout << i << ". ZONA " << i << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi Zona : ";
    cin >> zona;
    cout << "--------------------------------------------------------------------------" << endl;

    if (tribun == 1 && zona <= 4) {
        int kursi1 = 0;
        cout << "PILIHAN KURSI VIP : " << endl;
        // Inisialisasi vector kursi dengan jumlahTiket
        kursi.resize(jumlahTiket);
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 15; j++) {
                if (kursi1 < 105) {
                    cout << kursi1 + 1 << '\t';
                    kursi1++;
                }
            }
            cout << endl;
        }
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Pilih Nomor Posisi kursi sebanyak jumlah tiket (" << jumlahTiket << ") Pisahkan dengan spasi : ";
        for (int i = 0; i < jumlahTiket; ++i) {
            cin >> kursi[i]; // Menerima input nomor kursi
        }
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl;
    } else {
        kursi.resize(1); // Inisialisasi kursi untuk tribun reguler
        kursi[0] = -1;   // Penanda bahwa kursi tidak dipilih
    }
}

// Fungsi untuk memilih tribun penonton
void pilihTribun(int &tribun)
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>> SILAHKAN PILIH TRIBUN <<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < JUMLAH_TRIBUN; ++i)
    {
        cout << i + 1 << ". " << daftarTribun[i].nama << " : RP " << daftarTribun[i].harga << endl;
    }

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Pilih Nomor Posisi Tribun : ";
    cin >> tribun;
    cout << "--------------------------------------------------------------------------" << endl;

    if (tribun < 1 || tribun > JUMLAH_TRIBUN)
    {
        cout << "Nomor Tribun Tidak Valid" << endl;
        tribun = -1; // Menandakan tribun tidak valid
    }
}

// Fungsi untuk memilih metode pembayaran
void pilihMetodePembayaran(int &metodebayar, string &metodeBayarDetail)
{
    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>> PILIH METODE PEMBAYARAN <<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "1. Cash" << endl;
    cout << "2. Transfer" << endl;
    cout << "3. e-Wallet" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Pilih Nomor Metode Pembayaran : ";
    cin >> metodebayar;
    cout << "--------------------------------------------------------------------------" << endl;

    switch (metodebayar)
    {
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

// Fungsi untuk memilih bank jika metode pembayaran adalah transfer
void pilihBank(string &bankDetail)
{
    int bank;
    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>> SILAHKAN PILIH BANK <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "1. BNI" << endl;
    cout << "2. BRI" << endl;
    cout << "3. BCA" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Pilih Nomor Bank : ";
    cin >> bank;
    cout << "--------------------------------------------------------------------------" << endl;

    switch (bank)
    {
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

// Fungsi untuk memilih layanan e-Wallet jika metode pembayaran adalah e-Wallet
void pilihEWallet(string &eWalletDetail)
{
    int eWallet;
    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>> PILIH LAYANAN e-WALLET <<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "1. Gopay" << endl;
    cout << "2. Dana" << endl;
    cout << "3. Akulaku" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Pilih Nomor e-Wallet : ";
    cin >> eWallet;
    cout << "--------------------------------------------------------------------------" << endl;

    switch (eWallet)
    {
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

int main()
{
    string nama;
    int umur, tribun, zona, metodepembayaran, print, jumlahTiket;
    string metodeBayarDetail;
    vector<int> kursi;

    char pesanLagi;

    do
    {
        system("cls");
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "=== SELAMAT DATANG DI PEMBELIAN TIKET SEPAK BOLA BY IQBAL, RICO, DHEVA ===" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>> MASUKKAN DATA USER <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        inputNama(nama);
        inputUmur(umur);

        if (umur <= 8)
        {
            cout << "MAAF ANDA TIDAK BISA MEMBELI TIKET DIKARENAKAN MASIH DIBAWAH UMUR\n";
        }
        else
        {
            cout << "\n--------------------------------------------------------------------------" << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>> PILIH PERTANDINGAN <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "1. MAN. CITY VS BAYERN MUNCHEN  :  15.30 PM" << endl;
            cout << "2. REAL MADRID VS MAN. UNITED   :  19.45 PM" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            int pilih;
            cout << "SILAHKAN PILIH JADWAL PERTANDINGAN : ";
            cin >> pilih;
            cout << "--------------------------------------------------------------------------" << endl;

            switch (pilih)
            {
            case 1:
                cout << "\n--------------------------------------------------------------------------" << endl;
                cout << "<<<<<<<<<<<<<<<<<<<<<< MAN. CITY VS BAYERN MUNCHEN >>>>>>>>>>>>>>>>>>>>>>>" << endl;
                break;
            case 2:
                cout << "\n--------------------------------------------------------------------------" << endl;
                cout << "<<<<<<<<<<<<<<<<<<<<<<< REAL MADRID VS MAN. UNITED >>>>>>>>>>>>>>>>>>>>>>>" << endl;
                break;
            default:
                cout << "\n--------------------------------------------------------------------------" << endl;
                cout << "<<<<<<<<<<<<<<<<<<< JADWAL PERTANDINGAN TIDAK TERSEDIA >>>>>>>>>>>>>>>>>>>" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "Apakah Anda ingin membeli tiket ulang? (y/n): ";
                cin >> pesanLagi;
                if (pesanLagi == 'n' || pesanLagi == 'N') {
                    return 0; // Mengakhiri program jika pengguna memilih 'n'
                }
                continue; // Memulai ulang jika pengguna memilih 'y'
            }

            pilihTribun(tribun);
            if (tribun == -1)
            {
                cout << "Apakah Anda ingin membeli tiket ulang? (y/n): ";
                cin >> pesanLagi;
                if (pesanLagi == 'n' || pesanLagi == 'N') {
                    return 0; // Mengakhiri program jika pengguna memilih 'n'
                }
                continue; // Memulai ulang jika pengguna memilih 'y'
            }

            cout << "\n--------------------------------------------------------------------------" << endl;
            cout << "Masukkan Jumlah Tiket : ";
            cin >> jumlahTiket;
            cout << "--------------------------------------------------------------------------" << endl;

            pilihZona(tribun, zona, kursi, jumlahTiket);
            pilihMetodePembayaran(metodepembayaran, metodeBayarDetail);

            if (metodeBayarDetail == "Tidak Valid")
            {
                cout << "Apakah Anda ingin membeli tiket ulang? (y/n): ";
                cin >> pesanLagi;
                if (pesanLagi == 'n' || pesanLagi == 'N') {
                    return 0; // Mengakhiri program jika pengguna memilih 'n'
                }
                continue; // Memulai ulang jika pengguna memilih 'y'
            }

            cout << "\n--------------------------------------------------------------------------" << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>> APAKAH ANDA INGIN PRINT TIKET? <<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "1. YA" << endl;
            cout << "2. TIDAK" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "Pilih Nomer 1/2? :";
            cin >> print;
            cout << "--------------------------------------------------------------------------" << endl;

            printTicket(nama, umur, tribun, zona, metodepembayaran, print, jumlahTiket, kursi, metodeBayarDetail);
        }

        cout << "\nApakah Anda ingin memesan tiket lagi? (y/n): ";
        cin >> pesanLagi;

    } while (pesanLagi == 'y' || pesanLagi == 'Y');
    system("cls");
}
