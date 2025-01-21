#include <iostream>
using namespace std;

//username = Muhammad Ghazali 
//nim = 2309106041

string kapital(string input) {
  bool isPreviousCharSpace = true;
  for (int i = 0; i < input.length(); i++) {
    if (isPreviousCharSpace) {
      input[i] = toupper(input[i]);
    }
    isPreviousCharSpace = isspace(input[i]);
  }

  return input;
}

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

//bubble sort huruf ascending
void bubbleSortHurufAscending(game g[], int n) {
    bool swapped;

    for (int i = 0; i < n; ++i) {
        swapped = false;
        for (int j = 0; j < n - i; ++j) {
            if (g[j].nama > g[j + 1].nama) {
            swap(g[j], g[j + 1]);
            swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
//bubble sort descending angka
bool terbaru(tanggalrilis a, tanggalrilis b) {
    if (a.tahun != b.tahun)
        return a.tahun > b.tahun;
    if (a.bulan != b.bulan)
        return a.bulan > b.bulan;
    return a.hari > b.hari;
}

void insertionSortDescendingAngka(game g[], int n) {
  for (int i = 1; i < n; ++i) {
    game key = g[i];
    int j = i - 1;

    while (j >= 0 && ! terbaru(g[j].info.rilis, key.info.rilis)) {
      g[j + 1] = g[j];
      j--;
    }
    g[j + 1] = key;
  }
}

//merge sort descending huruf (developer)
void merge(game g[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    game Left[n1], Right[n2];


    for (int i = 0; i < n1; i++)
        Left[i] = g[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = g[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i].info.developer >= Right[j].info.developer) { // Ubah tanda > menjadi < untuk ascending
            g[k] = Left[i];
            i++;
        } else {
            g[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        g[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        g[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(game g[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(g, left, mid);
    mergeSort(g, mid + 1, right);
    merge(g, left, mid, right);
}


bool login(){
    string username, password;
    cout << "Masukkan username : "; getline(cin,username); username = kapital(username);
    cout << "Masukkan password : "; getline(cin,password); 
    if(username == "Muhammad Ghazali" && password == "2309106041"){
        return true;
    }else{
        return false;
    }
}

//Interpolation search ascending Judul game yang disort acending
bool InterpolationSearch(game g[], string& target, bool& ketemu, int n){
  int low = 0;
  int high = n;
  while(low<=high&&target>= g[low].nama && target <= g[high].nama && ketemu == false){
    int pos = low + ((target.compare(g[low].nama) * (high - low)) / g[high].nama.compare(g[low].nama));
    if(g[pos].nama == target){
      ketemu = true;
    }
    if(g[pos].nama < target){
      low = pos + 1;
    }else{
      high = pos - 1;
    }
  } return ketemu;
}
void CariGame(game g[],string cari, int n){
  bool ketemu = false;
  InterpolationSearch(g, cari, ketemu, n);
  if(ketemu){
      system("cls");
      cout << "Game " << cari << " ditemukan." << endl<<endl;     
      for(int i = 0; i <= n; i++){
        if(g[i].nama == cari){
          cout << "Nama Game: " << g[i].nama<< endl;
          cout << "Developer: " << g[i].info.developer << endl;
          cout << "Tanggal Rilis: " << g[i].info.rilis.hari<<"-"<<g[i].info.rilis.bulan<<"-"<<g[i].info.rilis.tahun <<endl;
          cout << endl;
        }
      } 
  }else{
    system("cls");
    cout << "Game dengan nama " << cari << " tidak ditemukan." << endl;
  }
}

int binarySearchDescending(game g[],string& target, int n) {
    int low = 0;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
            
        if (g[mid].info.developer == target) {
            return mid; 
        } else if (g[mid].info.developer < target) {
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }

    return -1; 
}
void CariDeveloper(game g[], string cari, int n){
    int hasil = binarySearchDescending(g, cari, n);
    if(hasil != -1){
        system("cls");
        cout << "Developer " << cari << " ditemukan." << endl<<endl;     
        for(int i = 0; i <= n; i++){
            if(g[i].info.developer == cari){
                cout << "Nama Game: " << g[i].nama<< endl;
                cout << "Developer: " << g[i].info.developer << endl;
                cout << "Tanggal Rilis: " << g[i].info.rilis.hari<<"-"<<g[i].info.rilis.bulan<<"-"<<g[i].info.rilis.tahun <<endl;
                cout << endl;
            }
        } 
    }else{
        system("cls");
        cout << "Developer dengan nama " << cari << " tidak ditemukan." << endl;
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
    cout << "2. Lihat Developer"<<endl;
    cout << "3. Lihat Game Terbaru"<<endl;
    cout << "4. Tambah Game"<<endl;
    cout << "5. Ganti Game"<<endl;
    cout << "6. Hapus Game"<<endl;
    cout << "7. Info Game"<<endl;   
    cout << "8. Cari Judul Game"<<endl;
    cout << "9. Cari Developer"<<endl;
    cout << "0. Keluar"<<endl;
}


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

void Lihat_Game_Terbaru(int n) {
    cout << "Game terbaru sesuai jadwal rilis : \n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << g[i].nama << " | " << g[i].info.rilis.hari<<"-"<<g[i].info.rilis.bulan<<"-"<<g[i].info.rilis.tahun <<endl;
    }
}

void Lihat_Developer(int n) {
    
    cout << "List Developer beserta game nya (Z-A) : \n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << g[i].info.developer << " | " << g[i].nama << endl;
    }
}
void Tambah_Game(int &n){ //parameter address of
    n++;
    cout << "Masukkan game baru : "; getline(cin,g[n].nama); g[n].nama = kapital(g[n].nama);
    cout << "Masukkan developer game : "; getline(cin,g[n].info.developer); g[n].info.developer = kapital(g[n].info.developer);
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
void Ganti_Game(int *n){ //parameter dereference
    cout << "Masukkan nomor game yang ingin diganti : "; 
    while(!(cin>>nomor) || nomor<1 || nomor>*n+1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Masukkan nomor game yang benar : ";
    }
    system("cls");
    cin.ignore(100, '\n');
    cout << "Masukkan nama game : "; getline(cin,g[nomor-1].nama); g[nomor-1].nama = kapital(g[nomor-1].nama);
    cout << "Masukkan developer game : "; getline(cin,g[nomor-1].info.developer); g[nomor-1].info.developer = kapital(g[nomor-1].info.developer);
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
void Hapus_Game(int &n){ //parameter address of
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
    n=n-1;  
    cout << "Game berhasil dihapus" << endl;
}
void Info_Game(int *n){ //parameter dereference
    cout << "Masukkan nomor game yang ingin dilihat : ";
    while(!(cin>>nomor) || nomor<1 || nomor>*n+1){
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
    int n = 9;
    char menu;
    int gagal=0;
    string cari;
    string nama[20]= {"Final Fantasy VII Rebirth","Alan Wake 2","Marvel's Spiderman 2","Starfield",
                      "The Legend of Zelda: Breath of the Wild 2","Atomic Heart","Forspoken","Tekken 8",
                      "Yakuza: Infinite Wealth","The Legend of Zelda: Tears of the Kingdom"};

    string developer[20] = {"Square Enix","Remedy Entertainment","Insomniac Games","Bethesda Softworks",
                            "Nintendo EPD","Mundfish","Luminous Productions","Bandai Namco Entertainment",
                            "Ryu Ga Gotoku Studio","Nintendo EPD"};
    int hari[20] = {29, 27, 20, 6, 12, 21, 24, 26, 25,12};
    int bulan[20] = {2, 10, 10, 9, 5, 2, 1, 1, 1, 5};
    int tahun[20] = {2024, 2023, 2023, 2023, 2023, 2023, 2023, 2024, 2024, 2023};
   

    for (int i = 0; i <= n; i++){
        g[i].nama = nama[i];
        g[i].info.developer = developer[i];
        g[i].info.rilis.hari = hari[i];
        g[i].info.rilis.bulan = bulan[i];
        g[i].info.rilis.tahun = tahun[i];
    }
    
    int *ptrgagal = &gagal; // pointer ke variabel gagal
    system("cls");
    while (*ptrgagal<3){
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
    if(*ptrgagal == 3){
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
                bubbleSortHurufAscending(g, n);
                Lihat_Game(n);
                break;
            case '2':
                mergeSort(g, 0, n);
                Lihat_Developer(n);
                break;
            case '3':
                insertionSortDescendingAngka(g, n);
                Lihat_Game_Terbaru(n);
                break;
            case '4':
                Tambah_Game(n);
                break;
            case '5':
                cout << "============================"<<endl;
                Lihat_Game(n);
                Ganti_Game(&n);
                break;
            case '6':
                cout << "============================"<<endl;
                Lihat_Game(n);
                Hapus_Game(n);
                break;
            case '7':
                Lihat_Game( n);
                Info_Game(&n);
                break;
            case '8':
                bubbleSortHurufAscending(g, n);
                cout << "Masukkan judul game yang ingin dicari : "; getline(cin,cari); cari = kapital(cari);
                CariGame(g, cari, n);
                break;
            case '9':
                mergeSort(g, 0, n);
                cout << "Masukkan developer game yang ingin dicari: "; getline(cin,cari); cari = kapital(cari);
                CariDeveloper(g, cari, n);
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
    }
    return 0;
}
