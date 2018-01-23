//Nama : Mathias Novianto
//NIM : 13516021
//Deskripsi program : membuat magic square yang jumlah bilangan dalam satu baris, kolom, dan diagonal akan menghasilkan hasil yang sama yaitu n*(n*n+1)/2
//Tanggal : 3 September 2017
//Tugas wawancara KRPAI

#include <iostream>
#include <cstring>
using namespace std;

void oddSquare(int n){
    int magicSquare[n][n];
    int i,j;
    memset(magicSquare, 0, sizeof(magicSquare));
    i = n/2; //inisialisasi posisi nomor pertama
    j = n-1;
    int num = 1;
    while(num<=n*n){
        if(i==-1 && j==n){//kalau di ujung atas kanan, sudah keluar dari batas magicSquare
            j=n-2;
            i=0;
        }
        else{
            if(j==n){//kalo udah lewat dari ujung kanan, kembali ke ujung kiri
                j=0;
            }
            if(i<0){//kalo udah lewat dari ujung atas, kembali ke ujung bawah
                i=n-1;
            }
        }
        if(magicSquare[i][j]){//kalau udah ada isi arraynya
            j=j-2;
            i++;
            continue;//kembali ke awal loop
        }
        else{
            magicSquare[i][j]=num;
            num++;
        }
        j++;//kalau kolom, lanjut ke kanan (increment)
        i--;//kalau baris, lanjut ke atas (decrement)
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<magicSquare[i][j];
            if(magicSquare[i][j]<10){//diatur jumlah spasinya supaya lebih rapi
                cout<<"   ";
            }
            else if(magicSquare[i][j]>9 && magicSquare[i][j]<100){//>=10
                cout<<"  ";
            }
            else{//>99
                cout<<' ';
            }
        }
        cout<<endl;
    }
}

void doublyEven(int n){
    int i,j;
    int magicSquare[n][n];
	int miniSqrNum = n/4; //ukuran kotak kecil
	int num = 1; 	      //counter 1 sampai N*N
	int invNum = n*n;     //counter N*N sampai 1
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		   if(j>=miniSqrNum && j<n-miniSqrNum){
                if(i>=miniSqrNum && i<n-miniSqrNum){
                    magicSquare[i][j] = num;    //kotak tengah
                }
                else{
                    magicSquare[i][j] = invNum; //kotak atas dan bawah
                }
            }
		   else if(i<miniSqrNum || i>=n-miniSqrNum){
                magicSquare[i][j]=num;	         //empat kotak di dekat titik sudut
		   }
		   else{
                magicSquare[i][j] = invNum;  	//kotak kiri dan kanan
		   }
		   num++;
		   invNum--;
		}

	}
	for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<magicSquare[i][j];
            if(magicSquare[i][j]<10){//diatur jumlah spasinya supaya lebih rapi
                cout<<"   ";
            }
            else if(magicSquare[i][j]>9 && magicSquare[i][j]<100){//>=10
                cout<<"  ";
            }
            else{//>99
                cout<<' ';
            }
        }
        cout<<endl;
    }
}
void singlyEven(int n){
    int magicSquare[n][n];
    memset(magicSquare, 0, sizeof(magicSquare));
    int i,j,k,temp;
    int kol,baris;
    //inisialisasi
    k = n / 2;
    kol = (k-1)/2;
    baris = 0;
    magicSquare[baris][kol] = 1;
    //Kotak A (kiri atas)
    for(i = 2; i <= k*k; i++){
        if((i-1)%k == 0 ){//Bilangan yang kelipatan dari k
            baris++;
        }
        else{
            // kalo baris = 0, maka baris = n-1, or baris = baris - 1
            baris--;
            baris = (baris+k)%k;
            // if kol = n, then kol = 0, or kol = kol + 1
            kol++;
            kol %= k;
        }
        magicSquare[baris][kol] = i;
    }

    //Isi kotak B,C,D berdasarkan kotak A
    for(baris = 0;baris <k; baris++){
        for(kol = 0;kol <k; kol++){
            magicSquare[baris+k][kol+k] = magicSquare[baris][kol] + k*k; //kotak D
            magicSquare[baris][kol+k] = magicSquare[baris][kol] + 2*k*k; //kotak B
            magicSquare[baris+k][kol] = magicSquare[baris][kol] + 3*k*k; //kotak C
        }
    }

    //Tukar di kotak A dan C
    for(baris = 0;baris <k;baris++){
        if(baris == k / 2){//kalau di baris tengah
            for(kol = k / 2; kol <k - 1; kol++){
                temp = magicSquare[baris][kol];
                magicSquare[baris][kol] = magicSquare[baris + k][kol];
                magicSquare[baris + k][kol] = temp;
            }
        }
        else{//selain di baris tengah
            for(kol = 0;kol <k / 2;kol++){
                temp = magicSquare[baris][kol];
                magicSquare[baris][kol] = magicSquare[baris + k][kol];
                magicSquare[baris + k][kol] = temp;
            }
        }
    }
    // Tukar kotak B dan D
    for(baris = 0; baris <k;baris++){
        for(i = 0;i <(k - 1)/2 - 1;i++){
            temp = magicSquare[baris][k+ k/2 - i];
            magicSquare[baris][k+ k /2 -i] = magicSquare[baris + k][k+k/2 -i];
            magicSquare[baris + k][k+k/2 -i] = temp;
        }
    }
    //Tulis hasilnya ke layar
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<magicSquare[i][j];
            if(magicSquare[i][j]<10){//diatur jumlah spasinya supaya lebih rapi
                cout<<"   ";
            }
            else if(magicSquare[i][j]>9 && magicSquare[i][j]<100){//>=10
                cout<<"  ";
            }
            else{//>99
                cout<<' ';
            }
        }
        cout<<endl;
    }
}

int main(){
    int squareSize;
    cin>>squareSize;
    if(squareSize==2){
        cout<<"Tidak ada magic square yang dapat memenuhi"<<endl;
    }
    else if(squareSize%2==1){
        oddSquare(squareSize);
    }
    else if(squareSize%4==0){//squareSize%2==0 (genap)
        doublyEven(squareSize);
    }
    else{//squareSize%4<>0 tapi squareSize%2==0;
        singlyEven(squareSize);
    }
    return 0;
}

