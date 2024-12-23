#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    float nilai;
};

void tambahMahasiswa(Mahasiswa mahasiswa[], int &count)
{
    cout << "Masukkan NIM: ";
    cin >> mahasiswa[count].nim;
    cout << "Masukkan Nama: ";
    cin.ignore(); // Membersihkan buffer
    getline(cin, mahasiswa[count].nama);
    cout << "Masukkan Nilai: ";
    cin >> mahasiswa[count].nilai;
    count++;
    cout << "Data mahasiswa berhasil ditambahkan!" << endl;
}

void tampilkanMahasiswa(const Mahasiswa mahasiswa[], int count)
{
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < count; i++)
    {
        cout << "NIM: " << mahasiswa[i].nim << ", Nama: " << mahasiswa[i].nama << ", Nilai: " << mahasiswa[i].nilai << endl;
    }
}

void cariMahasiswa(const Mahasiswa mahasiswa[], int count)
{
    string nimCari;
    cout << "Masukkan NIM yang dicari: ";
    cin >> nimCari;

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (mahasiswa[i].nim == nimCari)
        {
            cout << "Data Ditemukan: NIM: " << mahasiswa[i].nim << ", Nama: " << mahasiswa[i].nama << ", Nilai: " << mahasiswa[i].nilai << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Data mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }
}

float hitungRataRata(const Mahasiswa mahasiswa[], int count)
{
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += mahasiswa[i].nilai;
    }
    return (count > 0) ? (total / count) : 0;
}

int main()
{
    const int MAX_MAHASISWA = 100;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int count = 0;
    char pilihan;

    do
    {
        cout << "\nManajemen Data Mahasiswa IF06\n"
             << endl;
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Hitung Rata-rata Nilai\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            if (count < MAX_MAHASISWA)
            {
                tambahMahasiswa(mahasiswa, count);
            }
            else
            {
                cout << "Data mahasiswa sudah penuh!" << endl;
            }
            break;
        case '2':
            tampilkanMahasiswa(mahasiswa, count);
            break;
        case '3':
            cariMahasiswa(mahasiswa, count);
            break;
        case '4':
            cout << "Rata-rata Nilai: " << hitungRataRata(mahasiswa, count) << endl;
            break;
        case '5':
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
        }
    } while (pilihan != '5');

    return 0;
}