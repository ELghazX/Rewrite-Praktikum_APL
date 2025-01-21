#include <iostream>
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

void Lihat_Game(int n, string nama[]){
    cout << "====================================";
    cout << endl << "Daftar Game" << endl;
    for(int i=0; i<=n; i++){
        cout << i+1 << ". " << nama[i] << endl;
    }
    cout << "====================================" << endl;
}

int main(){
    char menu;
    int gagal=0;
    int nomor;
    string nama[100]= {"Final Fantasy VII Rebirth","Alan Wake 2","Marvel's Spiderman 2","The Elder Scrolls VI",
                        "The Legend of Zelda: Breath of the Wild 2","God of War: Ragnarok","Forspoken","Tekken 8",
                        "Yakuza: Infinite Wealth"};
    while (gagal<3){
    cout << endl<<"List Game AAA 2023-2024"<<endl;
    cout<< "Pilih Menu : " << endl;
    cout << "1. Login" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih : "; cin >> menu; cin.ignore(100, '\n');

        if(menu == '0'){
            cout << "Terima kasih" << endl;
            return 0;
        }else if(menu == '1'){
            bool akun = login();
            if(akun){
                cout << "Login berhasil" << endl;
                break;
            }else{
                cout << "Login gagal" << endl;
                gagal++;
                cout << "Gagal " << gagal << " kali" << endl;
            }
        }else{
            cout << "Menu tidak valid" << endl;
        }
    }
    if(gagal == 3){
        cout << "Salah mulu... keluar dari program" << endl;
        return 0;
    }

    int isi = 8;
    cout <<endl << "Daftar Game AAA" << endl;
    while(true){
        cout <<endl<< "1. Lihat Game"<<endl;
        cout << "2. Tambah Game"<<endl;
        cout << "3. Ganti Game"<<endl;
        cout << "4. Hapus Game"<<endl;
        cout << "0. Keluar"<<endl;
        cout << "Pilih : "; cin >> menu; cin.ignore(100, '\n');
        switch(menu){
            case '0':
                cout << "Terima kasih" << endl;
                return 0;
            case '1':
                Lihat_Game(isi, nama);
                break;
            case '2':
                isi++;
                cout << "Masukkan game baru : "; getline(cin,nama[isi]);
                cout << "Game berhasil ditambahkan" << endl;
                break;
            case '3':
                Lihat_Game(isi, nama);
                cout << "Masukkan nomor game yang ingin diganti : "; 
                while(!(cin>>nomor) || nomor<1 || nomor>isi+1){
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Masukkan nomor game yang benar : ";
                }
                cin.ignore(100, '\n');
                cout << "Masukkan nama game : "; getline(cin,nama[nomor-1]);
                cout << "Game berhasil diganti" << endl;
                break;
            case '4':
                Lihat_Game(isi, nama);
                cout << "Masukkan nomor game yang ingin dihapus : ";
                while(!(cin>>nomor) || nomor<1 || nomor>isi+1){
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Masukkan nomor game yang benar : ";
                }
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

