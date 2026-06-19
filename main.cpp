#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Fungsi rekursif utama untuk algoritma Backtracking.
 * @param hasil     Vektor untuk menyimpan semua kombinasi valid (dikirim by reference).
 * @param saat_ini  String yang sedang dirakit secara bertahap (dikirim by reference).
 * @param buka      Jumlah kurung buka '(' yang sudah dipasang saat ini.
 * @param tutup     Jumlah kurung tutup ')' yang sudah dipasang saat ini.
 * @param N         Jumlah maksimal pasang kurung.
 */
void generateParenthesis(vector<string> &hasil, string &saat_ini, int symbolBuka, int symbolTutup, int jumlahPasang)
{
    // KONDISI BERHENTI (Base Case)
    // Jika panjang string sudah mencapai 2 * N, kombinasi selesai dan valid.
    if (saat_ini.length() == 2 * jumlahPasang)
    {
        hasil.push_back(saat_ini);
        return;
    }

    // ATURAN KURUNG BUKA
    // Kita bisa terus menambah kurung buka selama jumlahnya belum mencapai N.
    if (symbolBuka < jumlahPasang)
    {
        saat_ini.push_back('('); // Lakukan aksi: pasang kurung buka

        // Eksplorasi jalur ini lebih dalam
        generateParenthesis(hasil, saat_ini, symbolBuka + 1, symbolTutup, jumlahPasang);

        saat_ini.pop_back(); // BACKTRACKING: cabut kembali kurung buka untuk coba kombinasi lain
    }

    // ATURAN KURUNG TUTUP
    // Kita HANYA boleh menambah kurung tutup jika jumlahnya lebih sedikit dari kurung buka.
    // Ini mencegah string invalid seperti "())" di tengah jalan.
    if (symbolTutup < symbolBuka)
    {
        saat_ini.push_back(')'); // Lakukan aksi: pasang kurung tutup

        // Eksplorasi jalur ini lebih dalam
        generateParenthesis(hasil, saat_ini, symbolBuka, symbolTutup + 1, jumlahPasang);

        saat_ini.pop_back(); // BACKTRACKING: cabut kembali kurung tutup untuk coba kombinasi lain
    }
}

int main()
{
    int jumlahPasang;
    cout << "<<= Pengecekan Tanda Kurung '()' Kurung Valid =>>" << endl;
    cout << "Masukkan jumlah pasang kurung (N): ";
    cin >> jumlahPasang;

    vector<string> hasil;
    string saat_ini = "";

    // Panggil fungsi rekursif dengan nilai awal buka=0 dan tutup=0
    generateParenthesis(hasil, saat_ini, 0, 0, jumlahPasang);

    cout << "\nHasil kombinasi untuk N = " << jumlahPasang << " (" << hasil.size() << " kombinasi):" << endl;
    for (int i = 0; i < hasil.size(); i++)
    {
        cout << i + 1 << ". " << hasil[i] << endl;
    }

    system("pause");
    return 0;
}