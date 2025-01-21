#include <iostream>
using namespace std;

//username = Muhammad Ghazali (Case Sensitive)
//nim = 2309106041


char kapital(char ke){
    if(ke >= 'a' && ke <= 'z'){
        return ke = ke - 32;
    }else{
        return ke;
    }
}

void konversirupiah(float &nilaiawal, char ke, float &nilaiakhir, string &uangakhir){
    switch (ke){
        case 'D':
            nilaiakhir = nilaiawal / 15734.80;
            uangakhir = "Dollar";
            break;
        case 'E':
            nilaiakhir = nilaiawal / 17019.77;
            uangakhir = "Euro";
            break;
        case 'Y':
            nilaiakhir = nilaiawal / 104.61;
            uangakhir = "Yen";
            break;
        default:
            cout << "Konversi tidak valid" << endl;
            nilaiawal = 0;
    }
    
}
void konversidollar(float &nilaiawal, char ke, float &nilaiakhir, string &uangakhir ){
    switch (ke){
        case 'R':
            nilaiakhir = nilaiawal / 0.000064;
            uangakhir = "Rupiah";   
            break;
        case 'E':
            nilaiakhir = nilaiawal / 1.08;
            uangakhir = "Euro";  
            break;
        case 'Y':
            nilaiakhir = nilaiawal / 0.0066;
            uangakhir = "Yen";
            break;
        default:
            cout << "Konversi tidak valid" << endl;
            nilaiawal = 0;
    }
}
void konversieuro(float &nilaiawal, char ke, float &nilaiakhir, string &uangakhir){
    switch (ke){
        case 'R':
            nilaiakhir = nilaiawal / 0.000059;
            uangakhir = "Rupiah";
            break;
        case 'D':
            nilaiakhir = nilaiawal / 0.92;
            uangakhir = "Dollar";
            break;
        case 'Y':
            nilaiakhir = nilaiawal / 0.0061;
            uangakhir = "Yen";
            break;
        default:
            cout << "Konversi tidak valid" << endl;
            nilaiawal = 0;

    }
}
void konversiyen(float &nilaiawal, char ke, float &nilaiakhir, string &uangakhir){
    switch (ke){
        case 'R':
            nilaiakhir = nilaiawal / 0.0096;
            uangakhir = "Rupiah";   
            break;
        case 'D':
            nilaiakhir = nilaiawal / 150.09;
            uangakhir = "Dollar"; 
            break;
        case 'E':
            nilaiakhir = nilaiawal / 0.0061;
            uangakhir = "Euro";
            break;
        default:
            cout << "Konversi tidak valid" << endl;
            nilaiawal = 0;
    }
}

bool login(){
    string username, nim;
    cout << "Username: ";
    getline(cin, username);
    cout << "Nim: ";
    getline(cin, nim);
   
    if (username == "Muhammad Ghazali" && nim == "2309106041") {
        return true;
    } else {
        return false;
    }
}

int main(){
    string uangawal, uangakhir;
    char dari, ke;
    float nilaiawal = 0, nilaiakhir = 0;
    char menu;
    int gagal = 0;
    
    cout <<endl << "[==Duid Converter==]" <<endl<< endl;
    while(gagal < 3){
        cout << "Pilih menu: "<<endl;
        cout << "1. Login" << endl << "0. Exit" << endl;
        cout << "Pilih: "; cin>>menu;cin.ignore(100, '\n');
        if(menu == '1'){
            bool akun = login();
            if(akun){
                cout << "Login berhasil. . . ." << endl;
                break;
            } else {
                cout << "Login gagal" << endl;
                gagal++;
                cout << "gagal " << gagal << " kali\n\n ";
            }
        }else if(menu == '0'){
            cout << "Terima kasih" << endl;
            return 0;
        }else {
            cout << "Menu tidak valid" << endl;
        }     
    }
    if (gagal == 3){
        cout << "Salah mulu...\nkeluar dari program..." << endl;
        return 0;
    }

    while(true){
        cout << endl <<"Pilih Konversi"<<endl;
        cout << "1. dari Rupiah" << endl;
        cout << "2. dari Dollar" << endl;
        cout << "3. dari Euro" << endl;
        cout << "4. dari Yen" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih: "; cin >> dari; cin.ignore(100, '\n');
        switch(dari){
            case '1':
                uangawal = "Rupiah";
                cout << "Masukkan nilai Rupiah: ";
                while (!(cin>>nilaiawal)){
                    cout << "Input dengan angka!" << endl<< "Masukkan nilai Rupiah: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cout << "Rupiah ke? (D, E, Y): "; cin >>  ke; cin.ignore(100, '\n');
                ke = kapital(ke);
                konversirupiah(nilaiawal, ke, nilaiakhir, uangakhir);
                break;
            case '2':
                uangawal = "Dollar";
                cout << "Masukkan nilai Dollar: ";
                while(!(cin>>nilaiawal)){
                    cout << "Input dengan angka!" << endl<< "Masukkan nilai Dollar: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cout << "Dollar ke? (R, E, Y): "; cin >> ke ; cin.ignore(100, '\n');
                ke = kapital(ke);
                konversidollar(nilaiawal, ke, nilaiakhir, uangakhir);
                break;
            case '3':
                uangawal = "Euro";
                cout << "Masukkan nilai Euro: ";
                while(!(cin>>nilaiawal)){
                    cout << "Input dengan angka!" << endl<< "Masukkan nilai Euro: ";
                    cin.clear();
                    cin.ignore(100, '\n');  
                }
                cout << "Dollar ke? (R, D, Y): "; cin >>  ke; cin.ignore(100, '\n');
                ke = kapital(ke);
                konversieuro(nilaiawal, ke, nilaiakhir, uangakhir);
                break;
            case '4':
                uangawal = "Yen";
                cout << "Masukkan nilai Yen: ";
                while(!(cin>>nilaiawal)){
                    cout << "Input dengan angka!" << endl<< "Masukkan nilai Yen: ";
                    cin.clear();
                    cin.ignore(100, '\n');     
                }
                cout << "Dollar ke? (R, D, E): "; cin >>  ke; cin.ignore(100, '\n');
                ke = kapital(ke);
                konversiyen(nilaiawal, ke, nilaiakhir, uangakhir);
                break;
            case '0':
                cout << "Terima kasih" << endl;
                return 0;
                break;
            default:
                cout << "Menu tidak valid" << endl<<endl;
        }
        cout <<endl<< nilaiawal << " "<< uangawal << " = " << nilaiakhir << " "<<uangakhir << endl;
        nilaiakhir = 0;
        uangakhir = "";     
    }
    return 0;
}
