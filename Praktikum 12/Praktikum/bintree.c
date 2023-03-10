// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 20 November 2022
// Topik pra-praktikum : ADT Binary Tree
// Deskripsi : Implementasi ADT Binary Tree

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    /* KAMUS */
    BinTree tree;

    /* ALGORITMA */
    tree = (Address) malloc(sizeof(TreeNode));
    if (tree != NULL) {
        ROOT(tree) = root;
        LEFT(tree) = left_tree;
        RIGHT(tree) = right_tree;
    }
    return tree;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    /* KAMUS */
    /* ALGORITMA */
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
    /* KAMUS */
    Address tree;

    /* ALGORITMA */
    tree = (Address) malloc(sizeof(TreeNode));
    if (tree != NULL) {
        ROOT(tree) = val;
        LEFT(tree) = NULL;
        RIGHT(tree) = NULL;
    }
    return tree;
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    /* KAMUS */
    /* ALGORITMA */
    free(p);
}

boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (p == NULL);
}

boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL);
}

boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
}

boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
}

boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL);
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    /* KAMUS */
    /* ALGORITMA */
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    /* KAMUS */
    /* ALGORITMA */
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    /* KAMUS */
    /* ALGORITMA */
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeLevel(BinTree p, int h, int l)
{
    /* KAMUS */
    int N;

    /* ALGORITMA */
    if (!isTreeEmpty(p)) {
        N = h * l;
        while (N > 0) {
            printf(" ");
            N--;
        }
        printf("%d\n", ROOT(p));
        printTreeLevel(LEFT(p), h, l + 1);
        printTreeLevel(RIGHT(p), h, l + 1);
    }
}

void printTree(BinTree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    /* KAMUS */
    /* ALGORITMA */
    printTreeLevel(p, h, 0);
}

int rob1(BinTree root)
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
{
	/* KAMUS LOKAL */
    int val1, val2;
	
    /* ALGORITMA */
	if (isTreeEmpty(root)) {
		return 0;
	} else if (isOneElmt(root)) {
		return ROOT(root);
	} else {
		val1 = ROOT(root) + rob1(LEFT(root));
		val2 = ROOT(root) + rob1(RIGHT(root));
		if (val1 > val2) {
			return val1;
		} else {
			return val2;
		}
	}
}

int rob2(BinTree root) {
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
    /* KAMUS LOKAL */
	int val1, val2;
	
    /* ALGORITMA */
	if (isTreeEmpty(root)) {
		return 0;
	} else if (isOneElmt(root)) {
		return ROOT(root);
	} else {
		val1 = ROOT(root);
		if (isUnerLeft(root)) {
			val1 += rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root)));
		} else if (isUnerRight(root)) {
			val1 += rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root)));
		} else {
			val1 += rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root))) + rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root)));
		}
		val2 = rob2(LEFT(root)) + rob2(RIGHT(root));
		if (val1 > val2) {
			return val1;
		} else {
			return val2;
		}
	}
}