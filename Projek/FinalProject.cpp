#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int nominalDenda, jenisPelanggaran, totalDenda = 0;
    string tanggal, nama, nomorKendaraan, again, contactPerson;
    vector<int> jenisPelanggaranList; // Menyimpan jenis pelanggaran
    vector<int> nominalDendaList;     // Menyimpan nominal denda

    cout << "--   SELAMAT DATANG DI PROGRAM TILANG INDONESIA   --" << endl
         << endl;
    cout << "SILAHKAN MASUKKAN DATA ANDA ^-^" << endl
         << endl;
    cout << "Nama pelanggar lalu lintas                     : ";
    getline(cin, nama);
    cout << "Nomor kendaraan pelanggar lalu lintas          : ";
    getline(cin, nomorKendaraan);
    cout << "Masukkan Tanggal (DD/MM/YY) hanya angka        : ";
    cin >> tanggal;
    cout << "Masukkan kontak yang dapat dihubungi(WA/Gmail) : ";
    cin >> contactPerson;
    cout << endl
         << endl;

    // TEKNIK PERULANGAN-
    do
    {

        bool validInput = false; // Flag untuk mengecek validitas input

        while (!validInput) // Loop sampai input valid
        {
            // Menampilkan menu pilihan jenis pelanggaran
            cout << "Jenis pelanggaran lalu lintas           " << endl;
            cout << "1. Tidak memakai helm" << endl;
            cout << "2. Menerobos lampu lalu lintas" << endl;
            cout << "3. Berkendara tanpa surat kelengkapan" << endl;
            cout << "4. Berkendara dengan kecepatan tinggi" << endl;
            cout << "5. Berkendara melawan arus" << endl;

            cout << "Jenis pelanggaran yang dilakukan       : ";
            cin >> jenisPelanggaran;

            // Validasi jenis pelanggaran
            // TEKNIK PERCABANGAN-
            switch (jenisPelanggaran)
            {
            case 1:
                nominalDenda = 250000;
                cout << "Nominal denda tidak memakai helm adalah Rp." << nominalDenda << endl;
                validInput = true;
                break;
            case 2:
                nominalDenda = 500000;
                cout << "Nominal denda menerobos lampu lalu lintas adalah Rp." << nominalDenda << endl;
                validInput = true;
                break;
            case 3:
                nominalDenda = 250000;
                cout << "Nominal denda berkendara tanpa surat kelengkapan adalah Rp." << nominalDenda << endl;
                validInput = true;
                break;
            case 4:
                nominalDenda = 500000;
                cout << "Nominal denda berkendara dengan kecepatan tinggi adalah Rp." << nominalDenda << endl;
                validInput = true;
                break;
            case 5:
                nominalDenda = 250000;
                cout << "Nominal denda berkendara melawan arus adalah Rp." << nominalDenda << endl;
                validInput = true;
                break;
            default:
                cout << "Pelanggaran tidak terdaftar di sistem, silahkan input ulang" << endl;
            }

            // TEKNIK PERCABANGAN-
        }

        // OPERATOR PENUGASAN
        totalDenda += nominalDenda; // Menambahkan nominal denda ke total denda
        // OPERATOR PENUGASAN

        jenisPelanggaranList.push_back(jenisPelanggaran); // Menyimpan jenis pelanggaran
        nominalDendaList.push_back(nominalDenda);

        cout << "Pelanggaran yang dilakukan oleh pengendara dengan nomor kendaraan : " << nomorKendaraan
             << ", dengan jenis pelanggaran:" << jenisPelanggaran << endl
             << "harus membayar senilai : RP." << nominalDenda << endl;

        cout << "Ada pelanggaran lain? (Y/N)  : ";
        cin >> again;

    } while (again == "Y" || again == "y");
    // TEKNIK PERULANGAN-

    // Menampilkan hasil
    cout << "======================================================================" << endl;
    cout << "||                                                                  ||" << endl;
    cout << "||                        Struct Tilang Elektronik                  ||" << endl;
    cout << "||                                                                  ||" << endl;
    cout << "======================================================================" << endl;
    cout << endl
         << endl;
    cout << "Nama pelanggar                      : " << nama << endl
         << endl;
    cout << "Nomor kendaraan                     : " << nomorKendaraan << endl
         << endl;
    cout << "Tanggal pelanggaran                 : " << tanggal << endl
         << endl;
    cout << "Kontak person                       : " << contactPerson << endl
         << endl;
    cout << "Daftar pelanggaran yang dilakukan   : " << endl;

    for (size_t i = 0; i < jenisPelanggaranList.size(); ++i)
    {
        // OPERATOR ARITMATIKA
        cout << "Pelanggaran " << (i + 1) << ": ";
        // OPERATOR ARITMATIKA
        // Menampilkan detail pelanggaran
        switch (jenisPelanggaranList[i])
        {
        case 1:
            cout << "Tidak memakai helm, Denda: Rp." << nominalDendaList[i] << endl;
            break;
        case 2:
            cout << "Menerobos lampu lalu lintas, Denda: Rp." << nominalDendaList[i] << endl;
            break;
        case 3:
            cout << "Berkendara tanpa surat kelengkapan, Denda: Rp." << nominalDendaList[i] << endl;
            break;
        case 4:
            cout << "Berkendara dengan kecepatan tinggi, Denda: Rp." << nominalDendaList[i] << endl;
            break;
        case 5:
            cout << "Berkendara melawan arus, Denda: Rp." << nominalDendaList[i] << endl;
            break;
        }
    }

    cout << "Total denda yang harus dibayar: Rp." << totalDenda << endl;

    // Menu tambahan
    int menuOption;
    bool isStrukDeleted = false;
    do
    {
        if (isStrukDeleted)
        {
            break;
        }
        cout << endl
             << endl;
        cout << "Menu tambahan: " << endl;
        cout << "1. Update pelanggar" << endl;
        cout << "2. Hapus struct yang telah dicetak" << endl;
        cout << "3. Selesai" << endl;
        cout << "Pilih opsi: ";
        cin >> menuOption;

        switch (menuOption)
        {
        case 1:
            // Fitur update pelanggar
            cout << "Menambahkan pelanggaran baru." << endl
                 << endl;
            cout << "Masukkan jenis pelanggaran (1-5) " << endl;
            cout << "Jenis pelanggaran lalu lintas          : " << endl;
            cout << "1. Tidak memakai helm" << endl;
            cout << "2. Menerobos lampu lalu lintas" << endl;
            cout << "3. Berkendara tanpa surat kelengkapan" << endl;
            cout << "4. Berkendara dengan kecepatan tinggi" << endl;
            cout << "5. Berkendara melawan arus" << endl;
            cout << "Jenis pelanggaran yang dilakukan       : ";
            cin >> jenisPelanggaran;

            // Validasi jenis pelanggaran
            switch (jenisPelanggaran)
            {
            case 1:
                nominalDenda = 250000;
                break;
            case 2:
                nominalDenda = 500000;
                break;
            case 3:
                nominalDenda = 250000;
                break;
            case 4:
                nominalDenda = 500000;
                break;
            case 5:
                nominalDenda = 250000;
                break;
            default:
                cout << "Pelanggaran tidak terdaftar di sistem." << endl;
                continue; // Kembali ke menu
            }

            totalDenda += nominalDenda;                       // Menambahkan nominal denda ke total denda
            jenisPelanggaranList.push_back(jenisPelanggaran); // Menyimpan jenis pelanggaran
            nominalDendaList.push_back(nominalDenda);

            cout << "Pelanggaran baru ditambahkan." << endl;
            break;

        case 2:
            cout << "Struk telah dihapus, Terima kasih! Program selesai." << endl;
            isStrukDeleted = true;
            break;

        case 3:
            cout << "Terima kasih! Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            continue;
        }

        // Mencetak ulang struk setelah upgrade
        if (!isStrukDeleted)
        {

            cout << "======================================================================" << endl;
            cout << "||                                                                  ||" << endl;
            cout << "||                        Struct Tilang Elektronik                  ||" << endl;
            cout << "||                                                                  ||" << endl;
            cout << "======================================================================" << endl;
            cout << endl
                 << endl;
            cout << "Nama pelanggar                      : " << nama << endl
                 << endl;
            cout << "Nomor kendaraan                     : " << nomorKendaraan << endl
                 << endl;
            cout << "Tanggal pelanggaran                 : " << tanggal << endl
                 << endl;
            cout << "Kontak person                       : " << contactPerson << endl
                 << endl;
            cout << "Daftar pelanggaran yang dilakukan   : " << endl;

            for (size_t i = 0; i < jenisPelanggaranList.size(); ++i)
            {
                switch (jenisPelanggaranList[i])
                {
                case 1:
                    cout << "Pelanggaran " << (i + 1) << ": Tidak memakai helm, Denda: Rp." << nominalDendaList[i] << endl;
                    break;
                case 2:
                    cout << "Pelanggaran " << (i + 1) << ": Menerobos lampu lalu lintas, Denda: Rp." << nominalDendaList[i] << endl;
                    break;
                case 3:
                    cout << "Pelanggaran " << (i + 1) << ": Berkendara tanpa surat kelengkapan, Denda: Rp." << nominalDendaList[i] << endl;
                    break;
                case 4:
                    cout << "Pelanggaran " << (i + 1) << ": Berkendara dengan kecepatan tinggi, Denda: Rp." << nominalDendaList[i] << endl;
                    break;
                case 5:
                    cout << "Pelanggaran " << (i + 1) << ": Berkendara melawan arus, Denda: Rp." << nominalDendaList[i] << endl;
                    break;
                }
            }

            cout << "Total denda yang harus dibayar: Rp." << totalDenda << endl;
        }

    } while (menuOption != 3);

    return 0;
}