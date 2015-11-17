#include <stdio.h>
const int max=3;
const int maxtoko=2;
typedef char string[30];
typedef struct
{
	string warna;
	int beli,jual,stock;
}baju;

typedef struct
{
	string namatoko;
	baju r[3];
	int totalhargajual,totalhargabeli,keuntungan;
}toko;


void bacaSatuBaju (baju *a)
{
	printf ("Masukkan Warna : ");scanf("%s",a->warna);
	printf ("Masukkan Harga Beli : ");scanf("%d",&a->beli);
	printf ("Masukkan Harga Jual : ");scanf("%d",&a->jual);
	printf ("Masukkan Stock : ");scanf("%d",&a->stock);
}

void bacaArrayBaju (baju a[])
{
	for (int i=0;i<max;i++)
	{
	printf("Masukkan Baju ke %d\n",i+1);
	bacaSatuBaju(&a[i]);
	}
}
void tulisSatuBaju (baju a)
{
	printf ("Nama : %s ; Beli : %d ; Jual : %d ; Stock : %d \n",a.warna,a.beli,a.jual,a.stock);
}

void tulisArrayBaju (baju a[])
{
	for (int i=0;i<max;i++)
	{
		printf("==================== DATA BAJU KE %d ==================== \n",i+1);
		tulisSatuBaju(a[i]);
	}
}

void bacaSatuToko (toko *t)
{
	printf("Masukkan Nama Toko : ");scanf("%s",t->namatoko);
	bacaArrayBaju(t->r);
}

void bacaArrayToko (toko t[])
{
	for (int i=0;i<maxtoko;i++)
	{
		printf("\nToko Ke %d\n",i+1);
		bacaSatuToko(&t[i]);
	}
}

int hitungTotalHargaJual(baju a[])
{
	int total=0;
	for (int i=0;i<max;i++)
	{
		total=total+(a[i].jual*a[i].stock);
	}
	return total;
}

int hitungTotalHargaBeli(baju a[])
{
	int temp1=0;
	for (int i=0;i<max;i++)
	{
		temp1=temp1+(a[i].beli*a[i].stock);
	}
	return temp1;
}

int hitungKeuntungan(int totalJual, int totalBeli)
{
	int untung;
	untung=totalJual-totalBeli;
	return untung;
}

void updateDataToko (toko t[])
{
	int temp;temp=0;
	for (int i=1;i<=maxtoko;i++)
	{
	t[i].totalhargajual=hitungTotalHargaJual(t[i].r);
	t[i].totalhargabeli=hitungTotalHargaBeli(t[i].r);
	t[i].keuntungan=hitungKeuntungan(t[i].totalhargajual,t[i].totalhargabeli);
	}
}

void tulisSatuToko (toko t)
{
	printf("%s\n",t.namatoko);
	tulisArrayBaju (t.r);
	printf("Total Jual : %d\n",hitungTotalHargaJual (t.r));
	printf("Total Beli : %d\n",hitungTotalHargaBeli (t.r));
	printf("Total Keuntungan : %d\n\n",hitungKeuntungan(hitungTotalHargaJual(t.r),hitungTotalHargaBeli(t.r)));
}

void tulisArrayToko (toko t[])
{
	for (int i=0;i<maxtoko;i++)
	{
		printf ("==================== TOKO KE %d ==================== \n",i+1);
		tulisSatuToko(t[i]);
	}
}
main()

{
	toko cabang [maxtoko];
	bacaArrayToko (cabang);
	updateDataToko (cabang);
	tulisArrayToko (cabang);
}
