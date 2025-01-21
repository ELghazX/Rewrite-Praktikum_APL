#include <iostream>
using namespace std;

//username = Muhammad Ghazali (Case Sensitive)
//nim = 2309106041

struct tanggalrilis{
    int hari, bulan, tahun;
};
struct infogame{
    string developer;
    tanggalrilis rilis;
};
struct game{
    string nama;
    infogame info; 
}; game g [20];

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
        cout << "5. Info Game"<<endl;
        cout << "0. Keluar"<<endl;
}

int n = 8;
int nomor;
void Lihat_Game(int n) {
  if (n == 0) {
    cout << 1 << ". " << g[n].nama << endl;
    return;
  } else {
    Lihat_Game(n - 1);
    cout << n+1 << ". " << g[n].nama << endl;
  }
}
void Tambah_Game(){
    n++;
    cout << "Masukkan game baru : "; getline(cin,g[n].nama);
    cout << "Masukkan developer game : "; getline(cin,g[n].info.developer);
    cout << "Masukkan tanggal rilis game!"<<endl;
    while(true){
        cout << "Tanggal: "; cin >> g[n].info.rilis.hari;
        cout << "Bulan: "; cin >> g[n].info.rilis.bulan;
        cout << "Tahun: "; cin >> g[n].info.rilis.tahun;
        if(g[n].info.rilis.hari&&g[n].info.rilis.bulan&&g[n].info.rilis.tahun&&g[n].info.rilis.hari>0 && g[n].info.rilis.hari<32 && g[n].info.rilis.bulan>0 && g[n].info.rilis.bulan<13 && g[n].info.rilis.tahun>2022 && g[n].info.rilis.tahun<2025){
            break;
        }else{
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Tanggal rilis tidak valid" << endl;
        }
    }
    cin.ignore(100, '\n');
    system("cls");
    cout << "Game berhasil ditambahkan" << endl;
}
void Ganti_Game(){
    cout << "Masukkan nomor game yang ingin diganti : "; 
    while(!(cin>>nomor) || nomor<1 || nomor>n+1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Masukkan nomor game yang benar : ";
    }
    system("cls");
    cin.ignore(100, '\n');
    cout << "Masukkan nama game : "; getline(cin,g[nomor-1].nama);
    cout << "Masukkan developer game : "; getline(cin,g[nomor-1].info.developer);
    cout << "Masukkan tanggal rilis game! "<<endl;
    while(true){
        cout << "Tanggal: "; cin >> g[nomor-1].info.rilis.hari;
        cout << "Bulan: "; cin >> g[nomor-1].info.rilis.bulan;
        cout << "Tahun: "; cin >> g[nomor-1].info.rilis.tahun;
        if(g[nomor-1].info.rilis.hari &&g[nomor-1].info.rilis.bulan &&g[nomor-1].info.rilis.tahun&& g[nomor-1].info.rilis.hari>0 && g[nomor-1].info.rilis.hari<32 && g[nomor-1].info.rilis.bulan>0 && g[nomor-1].info.rilis.bulan<13 && g[nomor-1].info.rilis.tahun>2022 && g[nomor-1].info.rilis.tahun<2025){
            break;
        }else{
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Tanggal rilis tidak valid" << endl;
        }
    }
    cout << "Game berhasil diganti" << endl;
}
void Hapus_Game(){
    cout << "Masukkan nomor game yang ingin dihapus : ";
    while(!(cin>>nomor) || nomor<1 || nomor>n+1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Masukkan nomor game yang benar : ";
    }
    system("cls");  
    cin.ignore(100, '\n');
    for(int i=nomor-1; i<=n; i++){
        g[i].nama = g[i+1].nama;
        g[i].info.developer = g[i+1].info.developer;
        g[i].info.rilis.hari = g[i+1].info.rilis.hari;
        g[i].info.rilis.bulan = g[i+1].info.rilis.bulan;
        g[i].info.rilis.tahun = g[i+1].info.rilis.tahun;
    }
    n--;   
    cout << "Game berhasil dihapus" << endl;
}
void Info_Game(){
    cout << "Masukkan nomor game yang ingin dilihat : ";
    while(!(cin>>nomor) || nomor<1 || nomor>n+1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Masukkan nomor game yang benar : ";
    }
    system("cls");
    cout << "Nama Game : " << g[nomor-1].nama << endl;
    cout << "Developer : " << g[nomor-1].info.developer << endl;
    cout << "Tanggal Rilis : " << g[nomor-1].info.rilis.hari << "-" << g[nomor-1].info.rilis.bulan << "-" << g[nomor-1].info.rilis.tahun << endl;
}

int main(){    
    char menu;
    int gagal=0;
    string nama[20]= {"Final Fantasy VII Rebirth","Alan Wake 2","Marvel's Spiderman 2","Starfield",
                      "The Legend of Zelda: Breath of the Wild 2","Atomic Heart","Forspoken","Tekken 8",
                      "Yakuza: Infinite Wealth"};
    string developer[20] = {"Square Enix","Remedy Entertainment","Insomniac Games","Bethesda Softworks",
                            "Nintendo EPD","Mundfish","Luminous Productions","Bandai Namco Entertainment",
                            "Ryu Ga Gotoku Studio"};
    int hari[20] = {29, 27, 20, 6, 12, 21, 24, 26, 25};
    int bulan[20] = {2, 10, 10, 9, 5, 2, 1, 1, 1};
    int tahun[20] = {2024, 2023, 2023, 2023, 2023, 2023, 2023, 2024, 2024};

    for (int i = 0; i <= n; i++){
        g[i].nama = nama[i];
        g[i].info.developer = developer[i];
        g[i].info.rilis.hari = hari[i];
        g[i].info.rilis.bulan = bulan[i];
        g[i].info.rilis.tahun = tahun[i];
    }
     
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
                Lihat_Game(n);
                break;
            case '2':
                Tambah_Game();
                break;
            case '3':
                cout << "============================"<<endl;
                Lihat_Game(n);
                Ganti_Game();
                break;
            case '4':
                cout << "============================"<<endl;
                Lihat_Game(n);
                Hapus_Game();
                break;
            case '5':
                Lihat_Game(n);
                Info_Game();
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
    }
    return 0;
}

