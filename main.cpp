#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <limits>

using namespace std;

void printColoredParentheses(const string &s);

/**
 * Fungsi rekursif utama untuk algoritma Backtracking.
 * @param hasil Vektor untuk menyimpan semua kombinasi valid.
 * @param saat_ini String yang sedang dirakit.
 * @param symbolBuka Jumlah kurung buka '(' yang sudah dipasang.
 * @param symbolTutup Jumlah kurung tutup ')' yang sudah dipasang.
 * @param jumlahPasang Jumlah maksimal pasang kurung.
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

/**
 * @brief Mencetak string tanda kurung dengan pasangan berwarna.
 * Menggunakan stack untuk mencocokkan pasangan kurung dan memberikan warna yang sama.
 * @param s String kombinasi tanda kurung yang valid.
 */
void printColoredParentheses(const string &s)
{

    // Daftar warna ANSI untuk digunakan secara berurutan Kalau Windows Seperti ini
    // Kalau yang lain saya juga kurang tau
    const vector<string> colors = {
        "\033[91m", // Merah
        "\033[92m", // Hijau
        "\033[93m", // Kuning
        "\033[94m", // Biru
        "\033[95m", // Magenta
        "\033[96m"  // Cyan
    };
    const string resetColor = "\033[0m";

    stack<int> colorStack;
    int colorIndex = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            // Pilih warna, cetak, dan simpan indeks warna ke stack
            int currentColor = colorIndex % colors.size();
            cout << colors[currentColor] << c << resetColor;
            colorStack.push(currentColor);
            colorIndex++;
        }
        else if (c == ')')
        {
            if (!colorStack.empty())
            {
                // Ambil warna dari pasangan kurung bukanya
                int matchingColor = colorStack.top();
                colorStack.pop();
                cout << colors[matchingColor] << c << resetColor;
            }
            else
            {
                // Seharusnya tidak terjadi pada string yang valid
                cout << c;
            }
        }
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
    for (size_t i = 0; i < hasil.size(); i++)
    {
        // cout << i + 1 << ". " << hasil[i] << endl;

        // Kalau Mau Print Warna

        cout << i + 1 << ". ";
        printColoredParentheses(hasil[i]);
        cout << endl;
    }

    cout << "\nTekan Enter untuk keluar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer input
    cin.get();                                           // Menunggu pengguna menekan Enter
    return 0;
}