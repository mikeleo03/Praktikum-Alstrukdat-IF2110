// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 19 September 2022
// Topik pra-praktikum : ADT Array
// Deskripsi : Implementasi ADT Array

#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    /* Kamus Lokal */
    /* Algoritma */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols; 
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    /* Kamus Lokal */
    /* Algoritma */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    /* Kamus Lokal */
    /* Algoritma */
    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    /* Kamus Lokal */
    int i,j ;
    /* Algoritma */
    createMatrix (nRow, nCol, m);
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }

}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* Kamus Lokal */
    int i,j ;
    /* Algoritma */
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j != (COL_EFF(m) - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    /* Kamus Lokal */
    int i,j ;
    Matrix m3;
    /* Algoritma */
    createMatrix (ROW_EFF(m1), COL_EFF(m1), &m3);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    /* Kamus Lokal */
    int i,j ;
    Matrix m3;
    /* Algoritma */
    createMatrix (ROW_EFF(m1), COL_EFF(m1), &m3);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    /* Kamus Lokal */
    Matrix m3;
    int temp = 0;
    int i, j;
    /* Algoritma */
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            for (int k = 0; k < ROW_EFF(m2); k++) {
                temp += (ELMT(m1, i, k) * ELMT(m2, k, j));
            }
            ELMT(m3, i, j) = temp;
            temp = 0;
        }
    }
    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    /* Kamus Lokal */
    Matrix m1;
    int i, j;
    /* Algoritma */
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            m1.mem[i][j] = x * (m.mem[i][j]);
        }
    }
    return m1;
}

void pMultiplyByConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    /* Kamus Lokal */
    int i,j ;
    /* Algoritma */
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m,i,j) = k * ELMT(*m,i,j);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    /* Kamus Lokal */
    int i,j ;
    boolean status;
    /* Algoritma */
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2)) {
        status = true;
        for (i = 0; i < ROW_EFF(m1); i++) {
            for (j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1,i,j) != ELMT(m2,i,j)) {
                    status = false;
                }
            }
        }
        // keluar dari loop
        return status;
    } else {
        return false;
    }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (!isMatrixEqual(m1,m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    /* Kamus Lokal */
    int i,j ;
    boolean status;
    /* Algoritma */
    if (isSquare(m)) {
        status = true;
        for (i = 0; i < ROW_EFF(m); i++) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (ELMT(m,i,j) != ELMT(m,j,i)) {
                    status = false;
                }
            }
        }
        // keluar dari loop
        return status;
    } else {
        return false;
    }
}

boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    /* Kamus Lokal */
    int i,j ;
    boolean status;
    /* Algoritma */
    if (isSquare(m)) {
        status = true;
        for (i = 0; i < ROW_EFF(m); i++) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (i == j) {
                    if (getElmtDiagonal(m, i) != 1)
                        status = false;
                }
                else {
                    if (ELMT(m,i,j) != 0) {
                        status = false;
                    }
                }
            }
        }
        // keluar dari loop
        return status;
    } else {
        return false;
    }
}

boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /* Kamus Lokal */
    int i,j ;
    int count;
    /* Algoritma */
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                count += 1;
            }
        }
    }
    // keluar dari loop
    return ((((float)count) / ((float)countElmt(m)) * 100) <= 5);
}

Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    /* Kamus Lokal */
    /* Algoritma */
    return (multiplyByConst(m, -1));
}

void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    /* Kamus Lokal */
    /* Algoritma */
    pMultiplyByConst(m,-1);
}

float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    /* Kamus Lokal */
    float rasio;
    float det;
    /* Algoritma */
    // ELIMINASI DENGAN METODE GAUSS
    float A[ROW_CAP][ROW_CAP]; // Inisiate matriks baru ((sengaja dibuat berlebihan))
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < ROW_EFF(m); j++) {
            A[i][j] = ELMT(m, i, j);
        }
    }

    // Proses pengurangan row dengan nilai lebih tinggi dengan yang lebih rendah
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = i + 1; j < ROW_EFF(m); j++) {
            // mengambil rasio baris
            if (A[i][i] == 0) {
                rasio = 1; // Zero error handling
            } else {
                rasio = A[j][i] / A[i][i]; // Ngmabil dari membagi elemen depan 2 row
            }

            // Proses pengurangan row dengan nilai lebih tinggi dengan yang lebih rendah, biar
            // terbrntuk matriks eselon (walaupun bukan 1 utama)
            for (int k = 0; k < COL_EFF(m); k++) {
                A[j][k] -= A[i][k] * rasio;
            }
        }
    }

    // Menghitung determinan
    // Idenya, matriks nya segitiga atas, jadi tinggal ngaliin diagonal utamanya
    det = 1;
    for (int i = 0; i < ROW_EFF(m); i++) {
        det *= A[i][i];
    }
    // Negatve zero handling
    if (det == (-0))
        det = 0;

    return det;
}

Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    /* Kamus Lokal */
    int i,j;
    Matrix m1;
    /* Algoritma */
    createMatrix(ROW_EFF(m),COL_EFF(m),&m1);
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(m1,i,j) = ELMT(m,j,i);
        }
    }
    return m1;
}

void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    /* Kamus Lokal */
    int i,j;
    Matrix m1;
    /* Algoritma */
    createMatrix(ROW_EFF(*m),COL_EFF(*m),&m1);
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(m1,i,j) = ELMT(*m,j,i);
        }
    }
    *m = m1;
}