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
void generateParenthesis(vector<string> &hasil, string &saat_ini, int buka, int tutup, int N)
{
    // 1. KONDISI BERHENTI (Base Case)
    // Jika panjang string sudah mencapai 2 * N, kombinasi selesai dan valid.
    if (saat_ini.length() == 2 * N)
    {
        hasil.push_back(saat_ini);
        return;
    }

    // 2. ATURAN KURUNG BUKA
    // Kita bisa terus menambah kurung buka selama jumlahnya belum mencapai N.
    if (buka < N)
    {
        saat_ini.push_back('('); // Lakukan aksi: pasang kurung buka

        // Eksplorasi jalur ini lebih dalam
        generateParenthesis(hasil, saat_ini, buka + 1, tutup, N);

        saat_ini.pop_back(); // BACKTRACKING: cabut kembali kurung buka untuk coba kombinasi lain
    }

    // 3. ATURAN KURUNG TUTUP
    // Kita HANYA boleh menambah kurung tutup jika jumlahnya lebih sedikit dari kurung buka.
    // Ini mencegah string invalid seperti "())" di tengah jalan.
    if (tutup < buka)
    {
        saat_ini.push_back(')'); // Lakukan aksi: pasang kurung tutup

        // Eksplorasi jalur ini lebih dalam
        generateParenthesis(hasil, saat_ini, buka, tutup + 1, N);

        saat_ini.pop_back(); // BACKTRACKING: cabut kembali kurung tutup untuk coba kombinasi lain
    }
}

int main()
{
    int N;
    cout << "=== Pengecekan Tanda Kurung '()' Kurung Valid ===" << endl;
    cout << "Masukkan jumlah pasang kurung (N): ";
    cin >> N;

    vector<string> hasil;
    string saat_ini = "";

    // Panggil fungsi rekursif dengan nilai awal buka=0 dan tutup=0
    generateParenthesis(hasil, saat_ini, 0, 0, N);

    cout << "\nHasil kombinasi untuk N = " << N << " (" << hasil.size() << " kombinasi):" << endl;
    for (int i = 0; i < hasil.size(); i++)
    {
        cout << i + 1 << ". " << hasil[i] << endl;
    }

    return 0;
}