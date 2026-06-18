# Studi Kasus: Implementasi Algoritma _Backtracking_ pada Persoalan _Generate Parentheses_ (Pembangkitan Tanda Kurung Valid)

## 1. Deskripsi Masalah

Dalam ilmu komputer dan matematika diskret, persoalan _Generate Parentheses_ merupakan salah satu permasalahan klasik kombinatorik. Diberikan sebuah bilangan bulat positif $N$ yang merepresentasikan jumlah pasangan tanda kurung, sistem dituntut untuk membangkitkan (mencari) seluruh kombinasi susunan tanda kurung kurawal `(` dan `)` sedemikian rupa sehingga seluruh susunan tersebut bersifat valid atau _well-formed_.

Sebuah susunan tanda kurung dikatakan valid apabila:

1. Setiap kurung buka `(` memiliki pasangan kurung tutup `)`.
2. Kurung tutup `)` tidak boleh mendahului kurung buka `(`. Dengan kata lain, pada setiap tahap pembacaan dari kiri ke kanan, jumlah kurung tutup tidak pernah melebihi jumlah kurung buka.

**Contoh:**
Untuk $N = 3$, terdapat 5 kombinasi valid, yaitu:

- `((()))`
- `(()())`
- `(())()`
- `()(())`
- `()()()`

## 2. Pendekatan Penyelesaian: Algoritma _Backtracking_

Penyelesaian yang optimal untuk mencari kombinasi permasalahan ruang pencarian (_search space_) seperti ini adalah menggunakan algoritma **_Backtracking_ (Runut Balik)**. Algoritma ini secara sistematis mengeksplorasi ruang pencarian dengan membangun kandidat solusi secara inkremental, dan akan segera menghentikan eksplorasi (_pruning_) pada suatu cabang jika terdeteksi bahwa jalur tersebut tidak akan menghasilkan solusi yang valid.

### 2.1. Parameter Rekursi dan _State_

Dalam implementasi pada berkas `main.cpp`, fungsi _backtracking_ direpresentasikan oleh subprogram `generateParenthesis`. Status dari pencarian (_state_) direpresentasikan oleh beberapa parameter:

- `saat_ini`: String yang menyimpan kandidat kombinasi kurung yang sedang dirakit.
- `buka`: Representasi integer yang menghitung jumlah kurung buka `(` yang telah ditempatkan.
- `tutup`: Representasi integer yang menghitung jumlah kurung tutup `)` yang telah ditempatkan.

### 2.2. Fungsi Pembatas (_Bounding Function_ / _Constraints_)

Eksplorasi _backtracking_ dibatasi oleh aturan berikut agar terhindar dari kombinasi tidak valid:

1. **Penambahan Kurung Buka:** Kurung buka dapat ditambahkan selama jumlahnya masih kurang dari batas maksimum pasangan kurung yang diizinkan (`buka < N`).
2. **Penambahan Kurung Tutup:** Kurung tutup **hanya** dapat ditambahkan apabila jumlah kurung tutup saat ini lebih kecil daripada jumlah kurung buka yang telah dirangkai (`tutup < buka`). Ini merupakan mekanisme _pruning_ utama untuk menghindari cacat sintaksis seperti `())`.

### 2.3. Kondisi Berhenti (_Base Case_)

Rekursi akan berhenti dan mencatat hasil apabila panjang string kombinasi telah mencapai dua kali lipat jumlah pasangan yang diberikan, yaitu saat panjang `saat_ini == 2 * N`. Pada titik ini, dapat dipastikan bahwa string tersebut adalah sebuah susunan tanda kurung yang valid.

## 3. Mekanisme Proses _Backtracking_ (Runut Balik)

Bagian krusial dari implementasi ini berada pada proses runut balik (_undo step_). Saat string `saat_ini` ditambahkan sebuah karakter (sebagai contoh karakter `(`), fungsi akan melakukan pemanggilan rekursif untuk mengeksplorasi cabang tersebut.

Setelah eksplorasi cabang tersebut selesai (mencapai _base case_ atau tidak memenuhi syarat), fungsi akan melakukan _backtrack_ dengan membuang kembali karakter terakhir dari string (melalui metode `pop_back()`). Tindakan runut balik ini bertujuan untuk membersihkan _state_ string agar dapat digunakan untuk mengeksplorasi kombinasi kandidat yang lain pada cabang keputusan sebelumnya.

## 4. Analisis Kompleksitas Algoritma

### 4.1. Kompleksitas Waktu (_Time Complexity_)

Jumlah total kombinasi tanda kurung valid untuk suatu bilangan $N$ direpresentasikan oleh Deret Catalan ke-$n$ (Bilangan Catalan), yang dirumuskan secara matematis sebagai:
$$C_n = \frac{1}{n+1} \binom{2n}{n}$$

Oleh karena itu, kompleksitas waktu asimtotik dari pendekatan ini berbanding lurus dengan jumlah Bilangan Catalan ke-$n$, yaitu terikat secara asimtotik pada batasan **$O(\frac{4^n}{\sqrt{n}})$**. Setiap kombinasi valid memerlukan operasi iterasi proporsional terhadap panjang kombinasi string tersebut.

### 4.2. Kompleksitas Ruang (_Space Complexity_)

Kompleksitas memori atau ruang di luar penyimpanan hasil _array_ bergantung pada kedalaman maksimum dari tumpukan pemanggilan rekursif (_Call Stack_). Mengingat kombinasi terpanjang adalah sejumlah $2N$, batas kedalaman struktur rekursif tidak akan melampaui $2N$. Oleh karena itu, kompleksitas ruang adalah proporsional linear terhadap variabel $N$, yakni **$O(N)$**.

---

**Kesimpulan:**
Penggunaan _Backtracking_ terbukti sangat efektif untuk persoalan _Generate Parentheses_. Implementasi kode di atas menerapkan konsep rekursif, pengkondisian sintaks yang ketat, serta mekanisme pemulihan status pencarian yang benar, sehingga memberikan kompleksitas komputasional yang efisien di batasan teoretis untuk pencarian ruang secara _exhaustive_.
