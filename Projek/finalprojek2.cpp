#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Pelanggaran
{
    string nama;
    string nomorKendaraan;
    string tanggal;
    int jenisPelanggaran;
    int nominalDenda;
};

void saveToFile(const vector<Pelanggaran> &pelanggaranList)
{
    ofstream outFile("pelanggaran.txt");
    for (const auto &pelanggaran : pelanggaranList)
    {
        outFile << pelanggaran.nama << ","
                << pelanggaran.nomorKendaraan << ","
                << pelanggaran.tanggal << ","
                << pelanggaran.jenisPelanggaran << ","
                << pelanggaran.nominalDenda << endl;
    }
    outFile.close();
}

void readFromFile(vector<Pelanggaran> &pelanggaranList)
{
    ifstream inFile("pelanggaran.txt");
    Pelanggaran pelanggaran;
    string line;
    while (getline(inFile, line))
    {
        size_t pos = 0;
        int index = 0;
        while ((pos = line.find(',')) != string::npos)
        {
            string token = line.substr(0, pos);
            switch (index)
            {
            case 0:
                pelanggaran.nama = token;
                break;
            case 1:
                pelanggaran.nomorKendaraan = token;
                break;
            case 2:
                pelanggaran.tanggal = token;
                break;
            case 3:
                pelanggaran.jenisPelanggaran = stoi(token);
                break;
            case 4:
                pelanggaran.nominalDenda = stoi(token);
                break;
            }
            line.erase(0, pos + 1);
            index++;
        }
        pelanggaranList.push_back(pelanggaran);
    }
    inFile.close();
}

void updatePelanggaran(vector<Pelanggaran> &pelanggaranList, int index, const Pelanggaran &updatedPelanggaran)
{
    if (index >= 0 && index < pelanggaranList.size())
    {
        pelanggaranList[index] = updatedPelanggaran;
    }
}

void deletePelanggaran(vector<Pelanggaran> &pelanggaranList, int index)
{
    if (index >= 0 && index < pelanggaranList.size())
    {
        pelanggaranList.erase(pelanggaranList.begin() + index);
    }
}

int main()
{
    int nominalDenda, jenisPelanggaran, totalDenda = 0;
    string tanggal, nama, nomorKendaraan, again;
    vector<Pelanggaran> pelanggaranList;

    readFromFile(pelanggaranList); // Membaca data dari file

    cout << "Selamat datang di program tilang elektronik" << endl;
    cout << "Silakan masukkan data Anda " << endl;
    cout << "Nama pelanggar lalu lintas             : ";
    getline(cin, nama);
    cout << "Nomor kendaraan pelanggar lalu lintas  : ";
    getline(cin, nomorKendaraan);
    cout << "Masukkan Tanggal (DD/MM/YY) hanya angka: ";
    cin >> tanggal;
    cout << endl
         << endl;

    do
    {
        bool validInput = false;

        while (!validInput)
        {
            cout << "Jenis pelanggaran lalu lintas          : " << endl;
            cout << "1. Tidak memakai helm" << endl;
            cout << "2. Menerobos lampu lalu lintas" << endl;
            cout << "3. Berkendara tanpa surat kelengkapan" << endl;
            cout << "4. Berkendara dengan kecepatan tinggi" << endl;
            cout << "5. Berkendara melawan arus" << endl;

            cout << "Jenis pelanggaran yang dilakukan       : ";
            cin >> jenisPelanggaran;

            switch (jenisPelanggaran)
            {
            case 1:
                nominalDenda = 100000;
                validInput = true;
                break;
            case 2:
                nominalDenda = 500000;
                validInput = true;
                break;
            case 3:
                nominalDenda = 500000;
                validInput = true;
                break;
            case 4:
                nominalDenda = 500000;
                validInput = true;
                break;
            case 5:
                nominalDenda = 500000;
                validInput = true;
                break;
            default:
                cout << "Pelanggaran tidak terdaftar di sistem, silahkan input ulang" << endl;
            }
        }

        Pelanggaran pelanggaran = {nama, nomorKendaraan, tanggal, jenisPelanggaran, nominalDenda};
        pelanggaranList.push_back(pelanggaran); // Menyimpan pelanggaran ke dalam list
        totalDenda += nominalDenda;             // Menambahkan nominal denda ke total denda

        cout << "Pelanggaran yang dilakukan oleh pengendara dengan nomor kendaraan : " << nomorKendaraan
             << ", dengan jenis pelanggaran: " << jenisPelanggaran << endl
             << " harus membayar senilai : RP." << nominalDenda << endl;

        cout << "Ada pelanggaran lain? (Y/N)  : ";
        cin >> again;

    } while (again == "Y" || again == "y");

    // Menyimpan data ke file setelah selesai
    saveToFile(pelanggaranList);

    // Menampilkan hasil
    cout << "======================================================================" << endl;
    cout << "                         Struct Tilang Elektronik                     " << endl;
    cout << "======================================================================" << endl;
    cout << endl
         << endl;
    cout << "Nama pelanggar: " << nama << endl
         << endl;
    cout << "Nomor kendaraan: " << nomorKendaraan << endl
         << endl;
    cout << "Tanggal pelanggaran: " << tanggal << endl
         << endl;
    cout << "Daftar pelanggaran yang dilakukan: " << endl;

    for (size_t i = 0; i < pelanggaranList.size(); ++i)
    {
        cout << "Pelanggaran " << (i + 1) << ": ";
        switch (pelanggaranList[i].jenisPelanggaran)
        {
        case 1:
            cout << "Tidak memakai helm, Denda: Rp." << pelanggaranList[i].nominalDenda << endl;
            break;
        case 2:
            cout << "Menerobos lampu lalu lintas, Denda: Rp." << pelanggaranList[i].nominalDenda << endl;
            break;
        case 3:
            cout << "Berkendara tanpa surat kelengkapan, Denda: Rp." << pelanggaranList[i].nominalDenda << endl;
            break;
        case 4:
            cout << "Berkendara dengan kecepatan tinggi, Denda: Rp." << pelanggaranList[i].nominalDenda << endl;
            break;
        case 5:
            cout << "Berkendara melawan arus, Denda: Rp." << pelanggaranList[i].nominalDenda << endl;
            break;
        }
    }

    cout << "Total denda yang harus dibayar: Rp." << totalDenda << endl;
    return 0;
}