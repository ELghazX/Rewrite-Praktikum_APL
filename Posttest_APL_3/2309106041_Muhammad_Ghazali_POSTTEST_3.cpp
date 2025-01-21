#include <iostream>
#include <stdlib.h>
using namespace std;

//username = Muhammad Ghazali (Case Sensitive)
//nim = 2309106041

bool login(){
    string username, password;
    cout << "Masukkan username : "; getline(cin,username); 
    cout << "Masukkan password : "; getline(cin,password); 
    if(username == "Muhammad Ghazali" && password == "2309106041"){
        return true;
    }else{
        return false;
    }
}

string showmenu(){
    string showmenu;
    showmenu = "List Game AAA 2023-2024\n1. Login\n0. Keluar\n";
    return showmenu;
}

void showopsi(){
        cout << "============================"<<endl;
        cout <<endl<< "1. Lihat Game"<<endl;
        cout << "2. Tambah Game"<<endl;
        cout << "3. Ganti Game"<<endl;
        cout << "4. Hapus Game"<<endl;
        cout << "0. Keluar"<<endl;
}
// rekursif
void Lihat_Game(int n, string nama[]) {
  if (n == 0) {
    cout << 1 << ". " << nama[0] << endl;
    return;
  } else {
    Lihat_Game(n - 1, nama);
    cout << n+1 << ". " << nama[n] << endl;
  }
}

int main(){
    
    char menu;
    int gagal=0;
    int nomor;
    string nama[100]= {"Final Fantasy VII Rebirth","Alan Wake 2","Marvel's Spiderman 2","The Elder Scrolls VI",
                        "The Legend of Zelda: Breath of the Wild 2","God of War: Ragnarok","Forspoken","Tekken 8",
                        "Yakuza: Infinite Wealth"};
    system("cls");
    while (gagal<3){
        cout<<showmenu();
        cout << "Pilih : "; cin >> menu; cin.ignore(100, '\n');system("cls");

        if(menu == '0'){
            cout << "Terima kasih" << endl;
            return 0;
        }else if(menu == '1'){
            bool akun = login();
            if(akun){
                system("cls");
                cout << "Login berhasil" << endl;
                break;
            }else{
                system("cls");
                cout << "Login gagal" << endl;
                gagal++;
                cout << "Gagal " << gagal << " kali" << endl;
            }
        }else{
            system("cls");
            cout << "Menu tidak valid" << endl;
        }
    }
    if(gagal == 3){
        system("cls");
        cout << "Percobaan habis keluar dari program" << endl;
        return 0;
    }

    int isi = 8;
    cout <<endl << "Daftar Game AAA" << endl;
    while(true){
        showopsi();
        cout << "Pilih : "; cin >> menu; cin.ignore(100, '\n'); system("cls");
        switch(menu){
            case '0':
                cout << "Terima kasih" << endl;
                return 0;
            case '1':
                cout << "============================"<<endl;
                Lihat_Game(isi, nama);
                break;
            case '2':
                isi++;
                cout << "Masukkan game baru : "; getline(cin,nama[isi]);
                cout << "Game berhasil ditambahkan" << endl;
                break;
            case '3':
                cout << "============================"<<endl;
                Lihat_Game(isi, nama);
                cout << "Masukkan nomor game yang ingin diganti : "; 
                while(!(cin>>nomor) || nomor<1 || nomor>isi+1){
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Masukkan nomor game yang benar : ";
                }
                system("cls");
                cin.ignore(100, '\n');
                cout << "Masukkan nama game : "; getline(cin,nama[nomor-1]);
                cout << "Game berhasil diganti" << endl;
                break;
            case '4':
                cout << "============================"<<endl;
                Lihat_Game(isi, nama);
                cout << "Masukkan nomor game yang ingin dihapus : ";
                while(!(cin>>nomor) || nomor<1 || nomor>isi+1){
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Masukkan nomor game yang benar : ";
                }
                system("cls");  
                cin.ignore(100, '\n');
                for(int i=nomor-1; i<=isi; i++){
                    nama[i] = nama[i+1];
                }
                isi--;
                
                cout << "Game berhasil dihapus" << endl;
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
    }
    return 0;
}

