#include <iostream> // digunakan untuk simple input dan output
#include <fstream> // Digunakan untuk membuat, menulis, dan membaca file
#include <iomanip> // digunakan untuk mengatur karakter yang akan digunakan untuk mengisi spasi dalam tampilan rata kanan
#include <conio.h> // Digunakan untuk menampilkan getch
#include <string> // digunakan untuk input string array

using namespace std;

class item{
// Data members
private:
    int code, stock, kode_pinjaman, kode_pinjam, pinjam, balik, jml, lp, tanggal_terbit;
    char name[15];
    char buku[15];
    char judul[15];
    char nama_peminjam[15];
    char kelas[15];
    char status[15];
    char penerbit[15];

// member function
public:
    void put_item(void); // nilai parameter diisi void jika fungsi tersebut tidak memiliki parameter
    void get_item(void);
    void put_pinjam(void);
    void get_pinjam(void);
    void put_balik(void);
    void get_balik(void);
    int get_code (void){
        return code;
    };
    int get_nama (void){
        return kode_pinjaman;
    };
    int update_jumlah(int num){
        stock = stock-num;
        return stock;
    }

    void inputCode(){
    while (!(cin >> code))
        {
            system("color 4");
            cout << " ERROR";
            cin.clear();
            cin.ignore(132, '\n');
        }
    }
    void inputPinjam(){
    while (!(cin >> kode_pinjaman))
        {
            system("color 4");
            cout << " ERROR";
            cin.clear();
            cin.ignore(225, '\n');
        }
    }
};

// Member function class item di luar class
void item::get_item(void){ // tanda :: digunakan untuk membedakan fungsi tersebut berasa dari kelas atau namespace yang mana / digunakan untuk memanggil fungsi dari namespace atau kelas yang berbeda
    system("cls");
    cout << endl;
    cout << "==================================================" << endl;
    cout << "       Selamat Datang di E-Perpus Esemkita       |" << endl;
    cout << "==================================================" << endl;
    cout << " Masukkan Kode Buku      : ";
    inputCode();
    cout << " Masukkan Judul Buku     : "; cin >> buku;
    cout << " Masukkan Nama Pengarang : "; cin >> name;
    cout << " Masukkan Penerbit       : "; cin >> penerbit;
    cout << " Masukkan Tanggal Terbit : "; cin >> tanggal_terbit;
    cout << " Masukkan Jumlah Buku    : "; cin >> stock;
    cout << "==================================================" << endl;
        
}

void item::put_item(void){
    cout<<setw(6)<<code<<setw(15)<<buku<<setw(15)<<name<<setw(15)<<penerbit<<setw(14)<<tanggal_terbit<<setw(12)<<stock<<endl; //Setup dengan lebar field membutuhkan library iomanip
}

void item::get_pinjam(void){
    system("cls");
    cout << endl;
    cout << "==================================================" << endl;
    cout << "|      Selamat Datang di E-Perpus Esemkita       |" << endl;
    cout << "==================================================" << endl;
    cout << " Masukkan Kode Buku         : ";
    inputCode();
    cout << " Kode Pinjam Buku           : ";
    inputPinjam();
    cout << " Masukkan Judul Buku        : "; cin >> buku;
    cout << " Nama Peminjam Buku         : "; cin >> nama_peminjam;
    cout << " Kelas                      : "; cin >> kelas;
    cout << " Tanggal Pinjam (DDMMYYYY)  : "; cin >> pinjam;
    cout << " Tanggal Balik (DDMMYYYY)   : "; cin >> balik;

    lp = (balik-pinjam)/1000000;

    cout << " Lama Pinjaman              : " << lp << " hari" << endl;
    cout << " Banyak buku yang di pinjam : "; cin >> jml;
    cout << " Status                     : "; cin >> status;
    cout << "==================================================" << endl;
    cout << endl;
    
}

void item::put_pinjam(void){
    cout<<setw(6)<<code<<setw(12)<<kode_pinjaman<<setw(12)
    <<buku<<setw(20)<<nama_peminjam<<setw(15)<<kelas<<setw(18)<<pinjam<<setw(15)<<balik<<setw(14)<<lp<<setw(10)<<jml<<setw(16)<<status<<endl; //setup dengan lebar field membutuhkan library iomanip
}

// Fuction Prototype
void addRecord(void);
void showAll(void);
void showRecord(void);
void peminjaman(void);
void pengembalian(void);
void lihatBuku(void);
void deleteRecord(void);
void modifRecord(void);

// Global Declaration
item it;        // Membuat object item
fstream file;   // Membuat object fstream

int main()
{
    int option;
    string pilihan [] = {" 1. Tambah Stok Buku Baru\t\t\t |\n", " 2. Lihat Semua Data Buku\t\t\t |\n", " 3. Cari Data Buku\t\t\t\t |\n", " 4. Peminjaman Buku\t\t\t\t |\n", " 5. Pengembalian Buku\t\t\t\t |\n", " 6. Laporan E-Perpus\t\t\t         |\n", " 7. Hapus Data Buku\t\t\t\t |\n", " 8. Ubah Data Buku\t\t\t         |\n", " 9. Keluar\t\t\t\t\t |"};
    int lp;
	char yn, ch;
	
	// Membuat username dan password
	login:
	string user = "";
	string pass = "";

    system("cls");
    cout << "      ==================================================" << endl;
    cout << "      |  SELAMAT DATANG DI APLIKASI E-PERPUS ESEMKITA  |" << endl;
    cout << "      |                by : Kelompok 1                 |" << endl;
    cout << "      ==================================================" << endl;
    cout << endl;
    cout << "============================================================" << endl;
	cout << "|                 Program Aplikasi E-Perpus                |" << endl;
    cout << "============================================================" << endl;
    cout << endl;
	cout << " Username : "; cin >> user;
	cout << " Password : ";

	ch = _getch();
    while(ch != 13){ // Character 13 is enter
    pass.push_back(ch);
    cout << '*';
    ch = _getch();
    }
    cout<<endl;

	if (user == "Kipli" && pass == "123") {
		cout << "\n\n Anda berhasil login. \n" << endl;
        cout << " Klik enter untuk lanjut" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	} else if (user == "Nijam" && pass == "123") {
		cout << "\n\n Anda berhasil login. \n" << endl;
        cout << " Klik enter untuk lanjut" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	} else if (user == "Ayu" && pass == "123") {
		cout << "\n\n Anda berhasil login. \n" << endl;
        cout << " Klik enter untuk lanjut" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	} else if (user == "Senja" && pass == "123") {
		cout << "\n\n Anda berhasil login. \n" << endl;
        cout << " Klik enter untuk lanjut" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	}else {
		cout << " Password Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}

    while(1){
        system ("cls");
        mulaimenu:
        cout << "==================================================" << endl;
        cout << "|             Menu E-Perpus Esemkita             |" << endl;
        cout << "==================================================" << endl;
        for (string b : pilihan){
            cout << "|" << b << "\n";
        }
        cout << "==================================================" << endl;
        cout << " Masukkan Nomor Opsi : "; cin>>option;

        switch(option){
            case 1:{
                addRecord();
                cout << endl;
                cout << endl;
                cout << " Data berhasil disimpan" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 2:{
                system("cls");
                cout << endl;
                cout << "==================================================================================" << endl;
                cout << "|" <<setw(6)<<"Kode"<<setw(15)<<"Judul"<<setw(15)<<"Pengarang"<<setw(15)<<"Penerbit"<<setw(14)<<"   Tanggal Terbit"<<setw(10)<<"    Jumlah"<<"  |"<< endl;
                cout << "==================================================================================" << endl;
                showAll();
                cout << "==================================================================================" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 3:{
                system("cls");
                showRecord();
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 4:{
                peminjaman();
                cout << endl;
                cout << " Data berhasil disimpan" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 5:{
                system("cls");
                cout << endl;
                cout << " Tulis kembali buku yang anda kembalikan" << endl;
                pengembalian();
                addRecord();
                cout << endl;
                cout << " Data berhasil disimpan" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
                }
            case 6:{
                system("cls");
                cout << "============================================================================================================================================" << endl;
                cout<<setw(6)<<"Kode Buku"<<setw(8)<<"    Kode Pinjam"<<setw(11)<<"  Judul Buku"<<setw(15)<<"    Nama Peminjam"<<setw(12)<<"Kelas"<<setw(10)<<"    Tanggal Pinjam"<<setw(10)<<"    Tanggal Balik"<<setw(12)<<"    Waktu"<<setw(6)<<"    Jumlah"<<setw(15)<<"Status"<<endl;
                cout << "============================================================================================================================================" << endl;
                lihatBuku();
                cout << "============================================================================================================================================" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 7:{
                system("cls");
                deleteRecord();
                cout << endl;
                cout << endl;
                cout << " Data berhasil disimpan" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 8:{
                system("cls");
                modifRecord();
                cout << endl;
                cout << endl;
                cout << " Data berhasil disimpan" << endl;
                cout<<" Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 9:{
                cout << endl;
                cout << " -- Terima Kasih Atas Kunjungan Anda --" << endl;
                cout<<" -- Program Aplikasi E-Perpus dengan menggunakan Visual Studio Code  --\n";
                exit(0);
            }
            default:{
                cout<<" Opsi yang anda cari tidak ditemukan" << endl;
                break;
            }
        }
    }
    return 0;
}

void addRecord(){
    char ch = 'y';
    
    file.open("stock.dat",ios::app|ios::binary); // ios::in digunakan untuk menunjukkan bahwa stream yang digunakan untuk membaca data dari file. dan kegunaan ios::binary digunakan untuk menunjukkan bahwa mode file yang digunakan adalah binary mode.
    while(ch=='y'||ch=='Y'){
        it.get_item();
        //write object into file
        file.write((char*)&it, sizeof(it)); // digunakan untuk menulis data ke dalam sebuah file dalam mode binary, operator & digunakan untuk mendapatkan alamat dari memori dari object it. Kemudian, tipe data char* digunakan untuk mengkonversi alamat memori object it ke dalam bentuk pointer ke tipe data char (byte), sehingga data dapat ditulis ke dalam file sebagai data binary mentah. Selanjutnya, sizeof(it) digunakan untuk menentukan ukuran data yang akan ditulis ke dalam file, sehingga dapa menjaminbahwa data yang ditulis ke dalam file adalah seukuran variable it.
        cout<<" Tambah Buku lagi ... (y/klik huruf random untuk sudah)?";
        cin>>ch;
    }
    file.close();

    // file.open digunakan untuk membuka file dengan mode ditentukan
    // file.close digunakan untuk menutup file yang telah dibuka.
}

void showAll(){
    file.open("stock.dat", ios::in|ios::binary);
    if(!file)
    {
        cout <<" File tidak ditemukan";
        exit(0);
    }else{
        file.read((char*)&it, sizeof(it));
        while (!file.eof()){ // digunakan untuk memeriksa apakah kita telah mencapai akhir dari file atau tidak.
            it.put_item();
            file.read((char*)&it, sizeof(it));
        }
    }
    file.close();
}

void showRecord(void){
    int no, flag = 0;

    file.open("stock.dat", ios::in|ios::binary);
    if (!file){ //Jika file tidak bisa dibuka
        cout<<" File tidak ditemukan";
        exit(0);
    }else{
        cout << "==================================================================================" << endl;
        cout << "|                      Selamat Datang di E-Perpus Esemkita                       |" << endl;
        cout << "==================================================================================" << endl;
        cout << "| Masukkan code yang dicari: "; cin>>no;
        cout << "==================================================================================" << endl;
        cout << endl;
        // Baca record dari file dan dimasukkan ke object
        while(!file.eof()){ // Ketika akhir dari file
            if(no==it.get_code()){
                flag=1;
                cout << "==================================================================================" << endl;
                cout << "|                            Data Buku yang Dicari                               |" << endl;
                cout << "==================================================================================" << endl;
                cout << "|" <<setw(6)<<"Kode"<<setw(15)<<"Judul"<<setw(15)<<"Pengarang"<<setw(15)<<"Penerbit"<<setw(14)<<"   Tanggal Terbit"<<setw(10)<<"    Jumlah"<<"  |"<< endl;
                cout << "==================================================================================" << endl;
                it.put_item();
                cout << "==================================================================================" << endl;
                break;
            }
            file.read((char*)&it, sizeof(it));
        }
        if (flag==0){
            cout<<" Kode yang anda masukkan tidak ditemukan ....\n";
        }
    }
    file.close();
}

void peminjaman() {
    int no, num;
    char ch = 'y';
    
    while(ch=='y'||ch=='Y') {
        file.open("jml.dat",ios::app|ios::binary);
        it.get_pinjam();
        file.write((char*)&it, sizeof(it));
        file.close();

        cout<<" Masukkan kode buku : "; cin>>no;
        cout<<" Masukkan ulang jumlah buku yang dipinjam : "; cin>>num;
        file.open("stock.dat", ios::in|ios::out|ios::binary);
        if(!file){
            cout<<" File tidak ditemukan";
            exit(0);
        }
        while(file.read((char*)&it, sizeof(it))){
            if(it.get_code()==no){
                it.update_jumlah(num);
                int pos = sizeof(it);
                file.seekp(-pos, ios::cur); // digunakaan untuk memindahkan posisi penulisan pada file, seekp adalah singkatan dari seek put yang artinya memindahkan posisi penulisan
                file.write((char*)&it, sizeof(it)); // digunakan untuk menulis data pada file, berfungsi menerima dua argumen, yaitu pointer ke data akan ditulis dan jumlah byte yang akan ditulis
            }
        }
        cout<<" Tambah Peminjaman lagi ... (y/klik huruf random untuk sudah)?";
        cin>>ch;
    }
    file.close();
}

void pengembalian() {
    int no;
    char ch = 'y';

    while(ch=='y'||ch=='Y'){
        cout << endl;
        cout << "==================================================" << endl;
        cout << "|      Selamat Datang di E-Perpus Esemkita       |" << endl;
        cout << "==================================================" << endl;
        cout << " Apakah anda ingin mengembalikan buku?" << endl;
        cout << " Menghapus laporan jika mengembalikan buku" << endl;
        cout << endl;
        cout << " Masukkan kode pinjam untuk dikembalikan : "  ;
        cin>>no;
        ofstream file2;  //stream object
        //open new.dat file for write operation
        file2.open("new.dat",ios::binary);
        file.open("jml.dat", ios::in|ios::binary);
        if(!file)    //if open file fails
        {
            cout<<" File tidak ditemukan";
            exit(0);
        }else{
            //read record form stock.dat file into object
            file.read((char*)&it, sizeof(it));
            while(!file.eof()){
                if(no != it.get_nama()){
                    file2.write((char*)&it, sizeof(it));
                }
                file.read((char*)&it, sizeof(it));
            }
        }
        addRecord();
        // cout << endl;
        // cout << " Tulis kembali buku yang anda kembalikan" << endl;
        // file.open("stock.dat",ios::app|ios::binary);
        // it.get_item();
        // //write object into file
        // file.write((char*)&it, sizeof(it));
        // file.close();

        cout<<" Tambah Pengembalian lagi ... (y/klik huruf random untuk sudah)?";
        cin>>ch;
        file2.close();
        file.close();
        remove("jml.dat");
        rename("new.dat","jml.dat");
    }
    cout << " Data berhasil disimpan" << endl;
    cout<<" Tekan sembarang untuk kembali ke menu ...";
    getch();
}

void deleteRecord(void){
    int no;
    char ch = 'y';

    while(ch=='y'||ch=='Y') {
        cout << endl;
        cout << "==================================================" << endl;
        cout << "|      Selamat Datang di E-Perpus Esemkita       |" << endl;
        cout << "==================================================" << endl;
        cout << " Masukkan kode buku untuk dihapus: "  ;
        cin>>no;
        ofstream file2;  //stream object
        //open new.dat file for write operation
        file2.open("new.dat",ios::binary);
        file.open("stock.dat", ios::in|ios::binary); // io::out digunakan untuk memberi tahu program bahwa kita ingin menulis ke dalam file tersebut
        if(!file)    //if open file fails
        {
            cout<<" File tidak ditemukan";
            exit(0);
        }else{
            //read record form stock.dat file into object
            file.read((char*)&it, sizeof(it));
            while(!file.eof()){
                if(no != it.get_code()){
                    file2.write((char*)&it, sizeof(it));
                }
                file.read((char*)&it, sizeof(it));
            }
        }
        cout<<" Tambah Buku Yang Dihapus lagi ... (y/klik huruf random untuk sudah)?";
        cin>>ch;
        file2.close();
        file.close();
        remove("stock.dat");
        rename("new.dat","stock.dat");
    }
}

void lihatBuku(){
    file.open("jml.dat", ios::in|ios::binary);
    if(!file)
    {
        cout <<" File tidak ditemukan";
        exit(0);
    }else{
        file.read((char*)&it, sizeof(it));
        while (!file.eof()){
            it.put_pinjam();
            file.read((char*)&it, sizeof(it));
        }
    }
    file.close();
}

void modifRecord(void){
    int pil;
    int no, num, angka;
    char ch = 'y';

    while(ch=='y'||ch=='Y') {
        cout << "==================================================" << endl;
        cout << "|      Selamat Datang di E-Perpus Esemkita       |" << endl;
        cout << "==================================================" << endl;
        cout << " Edit Data Buku" << endl;
        cout << " Masukkan kode buku untuk dirubah: "; cin>>no;
        cout << " Masukkan Jumlah buku yang akan di keluarkan: "; cin>>num;
        file.open("stock.dat", ios::in|ios::out|ios::binary);
        if(!file){
            cout<<" File tidak ditemukan";
            exit(0);
        }
        while(file.read((char*)&it, sizeof(it))){
            if(it.get_code()==no){
                it.update_jumlah(num);
                int pos = sizeof(it);
                file.seekp(-pos, ios::cur);
                file.write((char*)&it, sizeof(it));
            }
        }
        cout<<" Tambah Edit Buku lagi ... (y/klik huruf random untuk sudah)?";
        cin>>ch;
    }
    file.close();
    
}