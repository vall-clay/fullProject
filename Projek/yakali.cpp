#include <iostream>
#include <string>

using namespace std;

// Variabel untuk menyimpan data akun
float balance = 1000000.0;
string pin = "1234";

// Function untuk login
bool login()
{
    string inputPin;
    cout << "Masukkan PIN Anda: ";
    cin >> inputPin;

    if (inputPin == pin)
    {
        cout << "Selamat datang, Anda berhasil login!" << endl;
        return true;
    }
    else
    {
        cout << "PIN anda salah. Silahkan coba lagi." << endl;
        return false;
    }
}

// Function untuk cek saldo
void checkBalance()
{
    cout << "Saldo Anda: " << balance << endl;
}

// Function untuk melakukan penarikan
void withdraw()
{
    double amount;
    cout << "Masukkan nominal yang ingin ditarik: RP ";
    cin >> amount;

    if (amount > balance)
    {
        cout << "Saldo Anda tidak cukup untuk melakukan penarikan." << endl;
    }
    else if (amount <= 0)
    {
        cout << "Nominal yang ditarik harus lebih besar dari 0." << endl;
    }
    else
    {
        balance -= amount;
        cout << "Penarikan saldo berhasil. Saldo Anda tersisa: " << balance << endl;
    }
}

// Function untuk melakukan setor tunai
void deposit()
{
    double amount;
    cout << "Masukkan nominal yang ingin disetor: RP ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Nominal yang disetor harus lebih besar dari 0." << endl;
    }
    else
    {
        balance += amount;
        cout << "Setor tunai berhasil. Saldo Anda sekarang: " << balance << endl;
    }
}

// Function untuk menampilkan menu ATM
void showMenu()
{
    cout << "--- ATM MENU ---" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Setor Tunai" << endl;
    cout << "4. Keluar" << endl;
}

int main()
{
    cout << "Selamat datang di ATM Bank Hamiaso" << endl;

    // Looping untuk login hingga berhasil
    while (!login())
        ;

    int choice;
    do
    {
        showMenu();
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            deposit();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan ATM Bank Hamiaso" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia. Silakan pilih opsi lainnya." << endl;
        }
    } while (choice != 4);

    return 0;
}
