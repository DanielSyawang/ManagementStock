
#include <iostream>
#include <string>
#include <map>
#include <conio.h>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
  // varibel untuk login, daftar, ganti password

  //string
  string password[100], nama[100],input_nama, input_password,input_password_lama,input_password_baru;

  //boolean
  bool login_sukses = false,loginroleuser = false,loginroleadmin = false,nama_sama = false, nama_valid = false, umur_valid = false;

  //integer
  int pilih, menu, anggota = 0, i = 0, umur[100],input_umur,nomor_barang,total_barang;

  //char
  char input, pilihan, logout;

  // array untuk stock lip cream
  int stockslc[9][2] = {  {50, 1},
                          {50, 2},
                          {50, 3},
                          {50, 4},
                          {50, 5},
                          {50, 6},
                          {50, 7},
                          {50, 8},
                          {50, 9},
                          };
  int stocks2 [12][2] = { {50, 1},
                          {50, 2},
                          {50, 3},
                          {50, 4},
                          {50, 5},
                          {50, 6},
                          {50, 7},
                          {50, 8},
                          {50, 9},
                          {50, 10},
                          {50, 11},
                          {50, 12},
                          };
 int stocks3 [6][2] =  {  {50, 1},
                          {50, 2},
                          {50, 3},
                          {50, 4},
                          {50, 5},
                          {50, 6},
                          };
 int stocks4 [20][2] = {  {50, 1},
                          {50, 2},
                          {50, 3},
                          {50, 4},
                          {50, 5},
                          {50, 6},
                          {50, 7},
                          {50, 8},
                          {50, 9},
                          {50, 10},
                          {50, 11},
                          {50, 12},
                          {50, 13},
                          {50, 14},
                          {50, 15},
                          {50, 16},
                          {50, 17},
                          {50, 18},
                          {50, 19},
                          {50, 20}
                          };
 int stocks5 [7][2] = {   {50, 1},
                          {50, 2},
                          {50, 3},
                          {50, 4},
                          {50, 5},
                          {50, 6},
                          {50, 7}
                          };


  // variabel pengatur login
  int loginke = 1;

  // variabel untuk menu user setelah login berhasil
  int kategori, harga, jmlh_barang, tot[100],totse[100], x = 1;
  string item, yesno;

  // variabel menyimpan total uand dan jumlah barang menyimpan hasil pembelian
  int total_pembelian = 0, jmlh_barang_total[100];

  // variabel menyimpan data hasil pembelian ke user
    map<string,pair<int, int>> data_pesanan;
    int total;

  // varibel untuk diskon
    string kodediskon, mau;
    int hargadiskonflashsale, hargadiskonultah;
    bool ulangtahun = false;

  // variabel untuk log in admin
    int pilkategori, no_barang, sebanyak;


menuawal:

  do {
    //tampilan menu utama
    system("cls");
    cout << "----------- Toko Daniel S.----------" << endl;
    cout << "------------------------------------" << endl;
    cout << "|     1.Login                      |" << endl;
    cout << "|     2.Register                   |" << endl;
    cout << "|     3.Forget password            |" << endl;
    cout << "|     4.Exit                       |" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    while (cout << "Masukan pilihan antara 1-4        = " && !(cin >> pilih)) {
            //menghapus apapun yang diinput di variabel pilih
            cin.clear();
            //menghapus buffer input, buffer input adalah nilai hasil input pada memori pada input sebelumya
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input salah, mohon masukan angka saja dari 1-4"<<endl;

        }
    switch (pilih) {
      // Case 1: Login

    case 1: {
    system("cls");
      i = 1;
      cout << "------------------------------------------" << endl;
      cout << "--------- Silahkan Log In disini ---------" << endl;
      cout << "------------------------------------------" << endl;
      cout << endl;

      // Validasi login
      while (!login_sukses) {
        cout << "Masukkan nama            = ";
        cin >> input_nama;

        // Validasi nama
        if (input_nama.length() > 10) {
          cout << "Nama maksimal 10 karakter." << endl;
          continue;
        }

        cout << "Masukkan password        = ";
        cin >> input_password;

        // Validasi password
        if (input_password.length() < 8) {
          cout << "Password minimal 8 karakter." << endl;
          continue;
        }

        if (input_password.length() > 16) {
          cout << "Password maksimal 16 karakter." << endl;
          continue;
        }

        // Cek apakah nama dan password cocok
        for (int i = 0; i <= anggota; i++) {
        if (input_nama == "admin" && input_password == "admin123") {
        // Login admin
          login_sukses = true;
          loginroleadmin = true;
          goto loginadmin;
          break;

        // login pengguna
        }else if (input_nama == nama[i] && input_password == password[i]) {
            login_sukses = true;
            loginroleuser = true;
            goto loginuser;
            break;
        }else{
            cout<<"gagal"<<endl;
        }}

        // Jika login berhasil, berhenti mengulangi do
        if (login_sukses) {
          break;
        }

        // Jika login gagal, kembali ke menu awal do
        cout << "Nama atau password salah." << endl;
        getch();
        goto menuawal;
      }
    // bagian setelah login
    if(login_sukses == true ){

    // login pengguna
    if(loginroleuser == true){

    loginuser:
    system("cls");

    // Proses login pengguna
    menuawaluser:
    system("cls");

    do {
    //tampilan menu pengguna/user
    system("cls");
    cout << "Selamat datang " << input_nama << " ^_^ "<<endl;
    cout<<"Silahkan pilih kategori 1-5, 6 untuk logout"<<endl;
    cout << "===============================================================" <<endl;
    cout << "===========      KATEGORI BARANG YANG TERSEDIA       ==========" <<endl;
    cout << "== 1. Lip Cream                                      ==========" <<endl;
    cout << "== 2. Eyeliner                                       ==========" <<endl;
    cout << "== 3. Foundation                                     ==========" <<endl;
    cout << "== 4. Face Wash                                      ==========" <<endl;
    cout << "== 5. Lip Tint                                       ==========" <<endl;
    cout << "== 6. Logout akun                                    ==========" <<endl;
    cout << "===============================================================" <<endl<<endl<<endl;

    cout << "Masukkan No. Kategori : "; cin >> kategori;
        if( kategori > 6 || kategori < 1 ){
        cout<<" Mohon kategori 1-6 "<<endl;
        getch();
        goto menuawaluser;
    }
    //memilih kategori
    switch (kategori)
    {
        case 1: //lipcream
            case1:
            system("cls");
            cout << " ============================================================|=======|" <<endl;
            cout << "| No.|       LIST BARANG LIP CREAM         |     HARGA       | Stock |" <<endl;
            cout << " ============================================================|=======|" <<endl;
            cout << "| 1. | Dazzle Me Mousse Lip Cream          |    Rp. 25.000   |   ";
            cout << stockslc[0][0] <<  endl;
            cout << "| 2. | Pink Flash Lip Cream                |    Rp. 19.000   |   ";
            cout << stockslc[1][0] <<  endl;
            cout << "| 3. | Wardah Lip Cream                    |    Rp. 45.000   |   ";
            cout << stockslc[2][0] <<  endl;
            cout << "| 4. | Implora Lip Cream                   |    Rp. 20.000   |   ";
            cout << stockslc[3][0] <<  endl;
            cout << "| 5. | Hanasui Lip Cream                   |    Rp. 25.000   |   ";
            cout << stockslc[4][0] <<  endl;
            cout << "| 6. | Hanasui Boba Lip Cream              |    Rp. 25.000   |   ";
            cout << stockslc[5][0] <<  endl;
            cout << "| 7. | OMG Lip Cream                       |    Rp. 20.000   |   ";
            cout << stockslc[6][0] <<  endl;
            cout << "| 8. | Brasov Lip Cream                    |    Rp. 24.000   |   ";
            cout << stockslc[7][0] <<  endl;
            cout << "| 9. | Madame Gie Lip Cream                |    Rp. 20.000   |   ";
            cout << stockslc[8][0] <<  endl;
            cout << " ============================================================|" <<endl << endl;

            cout << "Masukkan Nomor Barang : "; cin >> no_barang ;
            if (no_barang == 1){
                item = "dazzle me mouse lip cream";
                harga = 25000;
            }else if (no_barang == 2){
                item = "Pink Flash lip cream";
                harga = 19000;
            }else if (no_barang == 3){
                item = "Wardah cream";
                harga = 45000;
            }else if (no_barang == 4){
                item = "Implora Lip cream";
                harga = 20000;
            }else if (no_barang == 5){
                item = "Hanasui lip cream";
                harga = 25000;
            }else if (no_barang == 6){
                item = "Hanasui Boba lip cream";
                harga = 25000;
            }else if (no_barang == 7){
                item = "OMG lip cream";
                harga = 20000;
            }else if (no_barang == 8){
                item = "Brasov lip cream";
                harga = 24000;
            }else if (no_barang == 9){
                item = "Madame Gie lip cream";
                harga = 20000;
            }else {
                cout << "Pilihan Barang Tidak Tersedia";
                getch();
                goto case1;
            }

        // Untuk memasukan banyak barang
            cout << "Jumlah barang : "; cin >> jmlh_barang;

        // Untuk membuat total belanja sementara
            totse[x] = jmlh_barang * harga ;

        // Diskon flashsale
            cout << "Masukkan kode diskon : ";
            cin >> kodediskon;

            if (kodediskon == "FlashSale1212") {
                hargadiskonflashsale = totse[x] * 0.2;
                totse[x] = totse[x] - hargadiskonflashsale;
            }
        // Diskon Ultah
            cout << "Apakah hari ini ulang tahun Anda? (1 untuk ya, 0 untuk tidak): ";
            cin >> ulangtahun;

                if (ulangtahun) {
                    cout << "Selamat ulang tahun! Anda mendapatkan diskon tambahan." << endl;
                    hargadiskonultah = totse[x] * 0.1;
                    totse[x] = totse[x] - hargadiskonultah;
                }

        // tampilan total belanja sementara
            cout << "Total belanja setelah diskon: Rp " << totse[x] << endl;

        // Mengatur urutan array, karena array dimulai dari 0
            no_barang = no_barang - 1;

            // Untuk mengeek apakah nomor barang valid
            if (no_barang >=  0 && no_barang < 9) {

            // untuk cek apakah stock mencukupi
                // jika stock mencukupi
                if (jmlh_barang <= stockslc[no_barang][0]) {
                    cout << "anda memesan "<< item << " sebanyak "<<jmlh_barang << " pcs" << " = Rp. " << totse[x] <<endl;
                // Kurangi stock
                 stockslc[no_barang][0] -= jmlh_barang;
                // jika stock tidak cukup
                }else {
                    cout << "Stock barang " << stockslc[no_barang][1] << " tidak mencukupi. Stock tersisa: " << stockslc[no_barang][0] << endl;
                    cout << "Mohon beli dengan stock yang tersisa"<<endl;
                }
                tot[x] += totse[x];
                jmlh_barang_total[x] += jmlh_barang;

            }else {
                cout << "Produk tidak ditemukan." << endl;
            }

                cout<<"apakah masih ingin berbelanja? (Y/N) : " ; cin >> yesno;
                cout<<endl;
            break;

        case 2:
            //eyeliner
            case2:
            system("cls");
            cout << " =====================================================================|" <<endl;
            cout << "| No.|        LIST BARANG EYELINER          |      HARGA      | Stock |" <<endl;
            cout << " =====================================================================|" <<endl;
            cout << "| 1. | Dazzle Me                            |    Rp. 34.000   |   ";
            cout << stocks2[0][0] <<  endl;
            cout << "| 2. | Pink Flash                           |    Rp. 19.000   |   ";
            cout << stocks2[1][0] <<  endl;
            cout << "| 3. | Xiuxiu                               |    Rp. 22.000   |   ";
            cout << stocks2[2][0] <<  endl;
            cout << "| 4. | Implora                              |    Rp. 21.000   |   ";
            cout << stocks2[3][0] <<  endl;
            cout << "| 5. | Darling                              |    Rp. 22.000   |   ";
            cout << stocks2[4][0] <<  endl;
            cout << "| 6. | Duyung                               |    Rp. 22.000   |   ";
            cout << stocks2[5][0] <<  endl;
            cout << "| 7. | Y.O.U                                |    Rp. 45.000   |   ";
            cout << stocks2[6][0] <<  endl;
            cout << "| 8. | Daun                                 |    Rp. 18.000   |   ";
            cout << stocks2[7][0] <<  endl;
            cout << "| 9. | Madame                               |    Rp. 27.000   |   ";
            cout << stocks2[8][0] <<  endl;
            cout << "| 10.| Lameila                              |    Rp. 15.000   |   ";
            cout << stocks2[9][0] <<  endl;
            cout << "| 11.| Pixy                                 |    Rp. 28.000   |   ";
            cout << stocks2[10][0] <<  endl;
            cout << "| 12.| Brasov                               |    Rp. 21.000   |   ";
            cout << stocks2[11][0] <<  endl;
            cout << " ==============================================================" <<endl<<endl;

            cout << "Masukkan Nomor Barang : "; cin >> no_barang;

            if (no_barang == 1){
                item = "dazzle me";
                harga = 34000;
            }else if (no_barang == 2){
                item = "Pink Flash";
                harga = 19000;
            }else if (no_barang == 3){
                item = "Xiuxiu";
                harga = 22000;
            }else if (no_barang == 4){
                item = "Implora";
                harga = 21000;
            }else if (no_barang == 5){
                item = "Darling";
                harga = 22000;
            }else if (no_barang == 6){
                item = "Duyung";
                harga = 22000;
            }else if (no_barang == 7){
                item = "Y.O.U";
                harga = 45000;
            }else if (no_barang == 8){
                item = "Daun";
                harga = 18000;
            }else if (no_barang == 9){
                item = "Madame Gie";
                harga = 27000;
            }else if (no_barang == 10){
                item = "Lameila";
                harga = 15000;
            }else if (no_barang == 11){
                item = "Pixy";
                harga = 28000;
            }else if (no_barang == 12){
                item = "Brasov";
                harga = 21000;
            }else {
                cout << "Pilihan Barang Tidak Tersedia";
                getch();
                goto case2;
            }

            // Untuk memasukan banyak barang
                cout << "Jumlah barang : "; cin >> jmlh_barang;

            // Untuk membuat total belanja sementara
                totse[x] = jmlh_barang * harga ;

            // Diskon flashsale
                cout << "Masukkan kode diskon : ";
                cin >> kodediskon;

                if (kodediskon == "FlashSale1212") {
                    hargadiskonflashsale = totse[x] * 0.2;
                    totse[x] = totse[x] - hargadiskonflashsale;
                }
            // Diskon Ultah
                cout << "Apakah hari ini ulang tahun Anda? (1 untuk ya, 0 untuk tidak): ";
                cin >> ulangtahun;

                if (ulangtahun) {
                    cout << "Selamat ulang tahun! Anda mendapatkan diskon tambahan." << endl;
                    hargadiskonultah = totse[x] * 0.1;
                    totse[x] = totse[x] - hargadiskonultah;
                }

            // tampilan total belanja sementara
                cout << "Total belanja setelah diskon: Rp " << totse[x] << endl;

            // Mengatur urutan array, karena array dimulai dari 0
                no_barang = no_barang - 1;

            // Untuk mengeek apakah nomor barang valid
            if (no_barang >=  0 && no_barang < 12) {

            // untuk cek apakah stock mencukupi
                // jika stock mencukupi
                if (jmlh_barang <= stocks2[no_barang][0]) {
                    cout << "anda memesan "<< item << " sebanyak "<<jmlh_barang << ", " << " = Rp. " << totse[x] <<endl;
                // Kurangi stock
                stocks2[no_barang][0] -= jmlh_barang;

                // jika stock mencukupi
                } else {
                    cout << "Stock barang " << stocks2[no_barang][1] << " tidak mencukupi. Stock tersisa: " << stocks2[no_barang][0] << endl;
                    cout<< "Mohon beli dengan stock yang tersisa"<<endl;
                }
                    tot[x] += totse[x];
                    jmlh_barang_total[x] += jmlh_barang;

            }else {
                cout << "Produk tidak ditemukan." << endl;
            }
                cout<<"apakah masih ingin berbelanja? (Y/N) : " ; cin >> yesno;
                cout <<endl;
            break;

        case 3: //foundation
            case3:
            system("cls");
            cout << " ==============================================================" <<endl;
            cout << "| No.|   LIST BARANG FOUNDATION    |    HARGA        | Stocks =" <<endl;
            cout << " ==============================================================" <<endl;
            cout << "| 1. | Wardah                      |    Rp. 19.000   |    ";
            cout << stocks3[0][0] <<  endl;
            cout << "| 2. | Viva                        |    Rp. 9.000    |    ";
            cout << stocks3[1][0] <<  endl;
            cout << "| 3. | Pixy                        |    Rp. 37.000   |    ";
            cout << stocks3[2][0] <<  endl;
            cout << "| 4. | Sari Ayu                    |    Rp. 14.000   |    ";
            cout << stocks3[3][0] <<  endl;
            cout << "| 5. | Maybelline Fit Me           |    Rp. 25.000   |    ";
            cout << stocks3[4][0] <<  endl;
            cout << "| 6. | OMG                         |    Rp. 21.000   |    ";
            cout << stocks3[5][0] <<  endl;
            cout << " =====================================================" <<endl<<endl;

        cout << "Masukkan Nomor Barang : "; cin >> no_barang;

         if (no_barang == 1){
                item = "Wardah";
                harga = 19000;
            }else if (no_barang == 2){
                item = "Viva";
                harga = 9000;
            }else if (no_barang == 3){
                item = "Pixy";
                harga = 37000;
            }else if (no_barang == 4){
                item = "Sari Ayu";
                harga = 14000;
            }else if (no_barang == 5){
                item = "Masukkan Fit Me";
                harga = 25000;
            }else if (no_barang == 6){
                item = "OMG";
                harga = 21000;
            } else {
                cout << "Pilihan Barang Tidak Tersedia";
                getch();
                goto case3;
            }

        // Untuk memasukan banyak barang
            cout << "Jumlah barang : "; cin >> jmlh_barang;

        // Untuk membuat total belanja sementara
            totse[x] = jmlh_barang * harga ;

        // Diskon flashsale
            cout << "Masukkan kode diskon : ";
            cin >> kodediskon;

            if (kodediskon == "FlashSale1212") {
                hargadiskonflashsale = totse[x] * 0.2;
                totse[x] = totse[x] - hargadiskonflashsale;
            }
        // Diskon Ultah
            cout << "Apakah hari ini ulang tahun Anda? (1 untuk ya, 0 untuk tidak): ";
            cin >> ulangtahun;

                if (ulangtahun) {
                    cout << "Selamat ulang tahun! Anda mendapatkan diskon tambahan." << endl;
                    hargadiskonultah = totse[x] * 0.1;
                    totse[x] = totse[x] - hargadiskonultah;
                }

        // tampilan total belanja sementara
            cout << "Total belanja setelah diskon: Rp " << totse[x] << endl;

        // Mengatur urutan array, karena array dimulai dari 0
            no_barang = no_barang - 1;

        // Untuk mengeek apakah nomor barang valid
            if (no_barang >=  0 && no_barang < 6) {

            // untuk cek apakah stock mencukupi
                // jika stock mencukupi
                if (jmlh_barang <= stocks3[no_barang][0]) {
                    cout << "anda memesan "<< item << " sebanyak "<<jmlh_barang << " pcs" << " = Rp. " << totse[x] <<endl;
                // Kurangi stock
                 stocks3[no_barang][0] -= jmlh_barang;
                // jika stock tidak cukup
                }else {
                    cout << "Stock barang " << stocks3[no_barang][1] << " tidak mencukupi. Stock tersisa: " << stocks3[no_barang][0] << endl;
                    cout << "Mohon beli dengan stock yang tersisa"<<endl;
                }
                tot[x] += totse[x];
                jmlh_barang_total[x] += jmlh_barang;
        //ptoduk barang tidak valid
            }else {
                cout << "Produk tidak ditemukan." << endl;
            }
                cout<<"apakah masih ingin berbelanja? (Y/N) : " ; cin >> yesno;
                cout<<endl;
            break;

        case 4: //face wash
            case4:
            system("cls");
            cout << " ============================================================" <<endl;
            cout << "| No.|    LIST BARANG FACE WASH    |     HARGA     | Stocks =" <<endl;
            cout << " ============================================================" <<endl;
            cout << "| 1. | Y.O.U                       |  Rp. 19.000   |    ";
            cout << stocks4[0][0] <<  endl;
            cout << "| 2. | Garnier                     |  Rp. 9.000    |    ";
            cout << stocks4[1][0] <<  endl;
            cout << "| 3. | Ponds                       |  Rp. 37.000   |    ";
            cout << stocks4[2][0] <<  endl;
            cout << "| 4. | Pixy                        |  Rp. 14.000   |    ";
            cout << stocks4[3][0] <<  endl;
            cout << "| 5. | Emina Bright Stuff          |  Rp. 18.000   |    ";
            cout << stocks4[4][0] <<  endl;
            cout << "| 6. | Emina Miss Pimple           |  Rp. 21.000   |    ";
            cout << stocks4[5][0] <<  endl;
            cout << "| 7. | Emina Bright Stuff Acne     |  Rp. 19.000   |    ";
            cout << stocks4[6][0] <<  endl;
            cout << "| 8. | Pigeon                      |  Rp. 9.000    |    ";
            cout << stocks4[7][0] <<  endl;
            cout << "| 9. | OMG                         |  Rp. 37.000   |    ";
            cout << stocks4[8][0] <<  endl;
            cout << "| 10.| Wardah                      |  Rp. 14.000   |    ";
            cout << stocks4[9][0] <<  endl;
            cout << "| 11.| Fair and Lovely             |  Rp. 25.000   |    ";
            cout << stocks4[10][0] <<  endl;
            cout << "| 12.| Sari Ayu                    |  Rp. 19.000   |    ";
            cout << stocks4[11][0] <<  endl;
            cout << "| 13.| Citra                       |  Rp. 9.000    |    ";
            cout << stocks4[12][0] <<  endl;
            cout << "| 14.| Acnes                       |  Rp. 37.000   |    ";
            cout << stocks4[13][0] <<  endl;
            cout << "| 15.| Himalaya                    |  Rp. 14.000   |    ";
            cout << stocks4[14][0] <<  endl;
            cout << "| 16.| Hadalabo                    |  Rp. 25.000   |    ";
            cout << stocks4[15][0] <<  endl;
            cout << "| 17.| Clean and Clear             |  Rp. 25.000   |    ";
            cout << stocks4[16][0] <<  endl;
            cout << "| 18.| Safi                        |  Rp. 25.000   |    ";
            cout << stocks4[17][0] <<  endl;
            cout << "| 19.| Biore                       |  Rp. 25.000   |    ";
            cout << stocks4[18][0] <<  endl;
            cout << "| 20.| Garnier Men                 |  Rp. 25.000   |    ";
            cout << stocks4[19][0] <<  endl;
            cout << " ===================================================" <<endl;

            cout << "Masukkan Nomor Barang : "; cin >> no_barang;

            if (no_barang == 1){
                item = "Y.O.U";
                harga = 19000 ;
            }else if (no_barang == 2){
                item = "Garnier";
                harga = 9000 ;
            }else if (no_barang == 3){
                item = "Ponds";
                harga = 37000 ;
            }else if (no_barang == 4){
                item = "Pixy";
                harga = 14000 ;
            }else if (no_barang == 5){
                item = "Emina Bright Stuff ";
                harga = 18000 ;
            }else if (no_barang == 6){
                item = "Emina Miss Pimple ";
                harga = 21000 ;
            }else if (no_barang == 7){
                item = "Emina Bright Stuff Acne";
                harga = 19000 ;
            }else if (no_barang == 8){
                item = "Pigeon ";
                harga = 9000;
            }else if (no_barang == 9){
                item = "OMG";
                harga = 37000;
            }else if (no_barang == 10){
                item = "Wardah ";
                harga = 14000;
            }else if (no_barang == 11){
                item = "Fair and Lovely ";
                harga = 25000;
            }else if (no_barang == 12){
                item = "Sari Ayu";
                harga = 19000;
            }else if (no_barang == 13){
                item = "Citra";
                harga = 9000;
            }else if (no_barang ==14){
                item = "Acnes ";
                harga = 37000;
            }else if (no_barang == 15){
                item = "Himalaya ";
                harga = 14000;
            }else if (no_barang == 16){
                item = "Hadalabo ";
                harga = 25000 ;
            }else if (no_barang == 17){
                item = "Clean and Clear";
                harga = 25000;
            }else if (no_barang == 18){
                item = "Safi";
                harga = 25000;
            }else if (no_barang == 19){
                item = "Biore";
                harga = 25000;
            }else if (no_barang == 20){
                item = "Garnier Men";
                harga = 25000;
            }else {
                cout << "Pilihan Barang Tidak Tersedia";
                getch();
                goto case4;
            }

         // Untuk memasukan banyak barang
            cout << "Jumlah barang : "; cin >> jmlh_barang;

        // Untuk membuat total belanja sementara
            totse[x] = jmlh_barang * harga ;

        // Diskon flashsale
            cout << "Masukkan kode diskon : ";
            cin >> kodediskon;

            if (kodediskon == "FlashSale1212") {
                hargadiskonflashsale = totse[x] * 0.2;
                totse[x] = totse[x] - hargadiskonflashsale;
            }
        // Diskon Ultah
            cout << "Apakah hari ini ulang tahun Anda? (1 untuk ya, 0 untuk tidak): ";
            cin >> ulangtahun;

                if (ulangtahun) {
                    cout << "Selamat ulang tahun! Anda mendapatkan diskon tambahan." << endl;
                    hargadiskonultah = totse[x] * 0.1;
                    totse[x] = totse[x] - hargadiskonultah;
                }

        // tampilan total belanja sementara
            cout << "Total belanja setelah diskon: Rp " << totse[x] << endl;

        // Mengatur urutan array, karena array dimulai dari 0
            no_barang = no_barang - 1;

            // Untuk mengeek apakah nomor barang valid
            if (no_barang >=  0 && no_barang < 20) {

            // untuk cek apakah stock mencukupi
                // jika stock mencukupi
                if (jmlh_barang <= stocks4[no_barang][0]) {
                    cout << "anda memesan "<< item << " sebanyak "<<jmlh_barang << " pcs" << " = Rp. " << totse[x] <<endl;
                // Kurangi stock
                 stocks4[no_barang][0] -= jmlh_barang;
                // jika stock tidak cukup
                }else {
                    cout << "Stock barang " << stocks4[no_barang][1] << " tidak mencukupi. Stock tersisa: " << stocks4[no_barang][0] << endl;
                    cout << "Mohon beli dengan stock yang tersisa"<<endl;
                }
                tot[x] += totse[x];
                jmlh_barang_total[x] += jmlh_barang;

            }else {
                cout << "Produk tidak ditemukan." << endl;
            }
                cout<<"apakah masih ingin berbelanja? (Y/N) : " ; cin >> yesno;
                cout<<endl;
            break;
        case 5: //liptint
            case5:
            system("cls");

            cout << " ============================================================|=======|" <<endl;
            cout << "| No.|       LIST BARANG LIP TINT          |     HARGA       | Stock |" <<endl;
            cout << " ============================================================|=======|" <<endl;
            cout << "| 1. | Implora                             |    Rp. 18.000   |   ";
            cout << stocks5[0][0] <<  endl;
            cout << "| 2. | Implora Jelly Tint                  |    Rp. 20.000   |   ";
            cout << stocks5[1][0] <<  endl;
            cout << "| 3. | Hanasui                             |    Rp. 20.000   |   ";
            cout << stocks5[2][0] <<  endl;
            cout << "| 4. | Dazzle Me Mini                      |    Rp. 20.000   |   ";
            cout << stocks5[3][0] <<  endl;
            cout << "| 5. | Pixy                                |    Rp. 35.000   |   ";
            cout << stocks5[4][0] <<  endl;
            cout << "| 6. | Brasov                              |    Rp. 20.000   |   ";
            cout << stocks5[5][0] <<  endl;
            cout << "| 7. | OMG                                 |    Rp. 20.000   |   ";
            cout << stocks5[6][0] <<  endl;
            cout << " ============================================================|" <<endl << endl;

            cout << "Masukkan Nomor Barang : "; cin >> no_barang ;
            if (no_barang == 1){
                item = "Implora";
                harga = 18000;
            }else if (no_barang == 2){
                item = "Implora Jelly Tint";
                harga = 20000;
            }else if (no_barang == 3){
                item = "Hanasui";
                harga = 20000;
            }else if (no_barang == 4){
                item = "Dazzle Me Mini";
                harga = 20000;
            }else if (no_barang == 5){
                item = "Pixy";
                harga = 35000;
            }else if (no_barang == 6){
                item = "Brasov";
                harga = 20000;
            }else if (no_barang == 7){
                item = "OMG";
                harga = 20000;
            }else {
                cout << "Pilihan Barang Tidak Tersedia";
                getch();
                goto case5;
            }

         // Untuk memasukan banyak barang
            cout << "Jumlah barang : "; cin >> jmlh_barang;

        // Untuk membuat total belanja sementara
            totse[x] = jmlh_barang * harga ;

        // Diskon flashsale
            cout << "Masukkan kode diskon : ";
            cin >> kodediskon;

            if (kodediskon == "FlashSale1212") {
                hargadiskonflashsale = totse[x] * 0.2;
                totse[x] = totse[x] - hargadiskonflashsale;
            }
        // Diskon Ultah
            cout << "Apakah hari ini ulang tahun Anda? (1 untuk ya, 0 untuk tidak): ";
            cin >> ulangtahun;

                if (ulangtahun) {
                    cout << "Selamat ulang tahun! Anda mendapatkan diskon tambahan." << endl;
                    hargadiskonultah = totse[x] * 0.1;
                    totse[x] = totse[x] - hargadiskonultah;
                }

        // tampilan total belanja sementara
            cout << "Total belanja setelah diskon: Rp " << totse[x] << endl;

        // Mengatur urutan array, karena array dimulai dari 0
            no_barang = no_barang - 1;

            // Untuk mengeek apakah nomor barang valid
            if (no_barang >=  0 && no_barang < 7) {

            // untuk cek apakah stock mencukupi
                // jika stock mencukupi
                if (jmlh_barang <= stocks5[no_barang][0]) {
                    cout << "anda memesan "<< item << " sebanyak "<<jmlh_barang << " pcs" << " = Rp. " << totse[x] <<endl;
                // Kurangi stock
                 stocks5[no_barang][0] -= jmlh_barang;
                // jika stock tidak cukup
                }else {
                    cout << "Stock barang " << stocks5[no_barang][1] << " tidak mencukupi. Stock tersisa: " << stocks5[no_barang][0] << endl;
                    cout << "Mohon beli dengan stock yang tersisa"<<endl;
                }
                tot[x] += totse[x];
                jmlh_barang_total[x] += jmlh_barang;

            }else {
                cout << "Produk tidak ditemukan." << endl;
            }
                cout<<"apakah masih ingin berbelanja? (Y/N) : " ; cin >> yesno;
                cout<<endl;
            break;

    }
        // Tambahkan data pesanan ke map
            data_pesanan[input_nama].first = jmlh_barang_total[x];
            data_pesanan[input_nama].second = tot[x] ;

        // Jika pengguna memilih n
        if( yesno == "n" || yesno == "N"){
            cout << "Jumlah barang Pesanan Kosmetik   = " << jmlh_barang_total[x] <<endl;
            cout << "Total Pesanan Kosmetik           = " << tot[x] <<endl;
            cout << "Terimakasih telah berbelanja di toko kami! <3 "<<endl;
            loginke++;
        // Reset semua variabel
        // Set data login selanjutnya
            input_nama = "";
            yesno = "";
            jmlh_barang = 0;
            x = 0;
            totse[x] = 0;
        //logout
            getch();
            login_sukses = false;
            loginroleuser = false;
            if(login_sukses == false){
                goto menuawal;
            }
                x++;
            }

        if( kategori == 6){
            cout<<"Terima Kasih sudah menggunakan aplikasi kami"<<endl;
            // Reset semua variabel agar jika pengguna berikutnya login tidak mengikuti belanjaan pengguna sebelumnya
            for (int i = 0; i <= x; i++) {
                tot[i] == 0;
                totse == 0;
                jmlh_barang == 0;
            }
                login_sukses = false;
                loginroleuser = false;
            if(login_sukses == false){
                getch();
                goto menuawal;
            }
        }
    } while (kategori != 6 );
    }

    // login admin
    else if(loginroleadmin == true){

    loginadmin:
    system("cls");
    // Proses login admin
    cout << "Selamat datang Admin" << endl;

    // tampilan  menu admin
    cout << "-----------------------------------" << endl;
    cout << "|           Menu Admin            |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "| 1. Menambah stock barang        |" << endl;
    cout << "| 2. Membuat akun                 |" << endl;
    cout << "| 3. Daftar hasil penjualan       |" << endl;
    cout << "| 4. Logout                       |" << endl;
    cout << "-----------------------------------" << endl;

    //memilih menu
    cout << "Silahkan masukkan pilihan Anda     = ";
    cin >> menu;

    switch (menu) {
    case 1: {
    nambahstock:
    system("cls");
    // Tambah barang
        cout << "Kategori apa yang ingin ditambah stocknya? (1. Lip Cream, 2. Eyeliner, 3. Foundation, 4. Face Wash, 5. Lip Tint.)" << endl;
        cout << "Kategori                   = ";
        cin >> pilkategori;

    bagkategori:
    if (pilkategori == 1) {
        cout << "Barang ke berapa           = "; cin >> no_barang;
        // Cek apakah nomor barang valid
        if (no_barang > 0 && no_barang <= stockslc[no_barang - 1][1]) {
            cout << "Sebanyak                   = "; cin >> sebanyak;
            // Tambah stock
            stockslc[no_barang - 1][0] += sebanyak;
            cout << "Stock barang nomor         = " << stockslc[no_barang - 1][1] << ", bertambah menjadi   = "<< stockslc[no_barang - 1][0] << endl;
                } else {
            cout << "Produk tidak ditemukan." << endl;
            goto bagkategori;
            }
        }

        else if (pilkategori == 2) {
            cout << "Barang ke berapa           = "; cin >> no_barang;
            // Cek apakah nomor barang valid
            if (no_barang > 0 && no_barang <= stocks2[no_barang - 1][1]) {
            cout << "Sebanyak                   = "; cin >> sebanyak;
            // Tambah stock
            stocks2[no_barang - 1][0] += sebanyak;
            cout << "Stock barang nomor         = " << stocks2[no_barang - 1][1] << ", bertambah menjadi   = "<< stocks2[no_barang - 1][0] << endl;
                } else {
            cout << "Produk tidak ditemukan." << endl;
            goto bagkategori;
            }
        }
    else if (pilkategori == 3) {
            cout << "Barang ke berapa           = "; cin >> no_barang;
            // Cek apakah nomor barang valid
            if (no_barang > 0 && no_barang <= stocks3[no_barang - 1][1]) {
            cout << "Sebanyak                   = "; cin >> sebanyak;
            // Tambah stock
            stocks3[no_barang - 1][0] += sebanyak;
            cout << "Stock barang nomor         = " << stocks3[no_barang - 1][1] << ", bertambah menjadi   = "<< stocks3[no_barang - 1][0] << endl;
                } else {
            cout << "Produk tidak ditemukan." << endl;
            goto bagkategori;
            }
    }
    else if (pilkategori == 4) {
            cout << "Barang ke berapa           = "; cin >> no_barang;
            // Cek apakah nomor barang valid
            if (no_barang > 0 && no_barang <= stocks4[no_barang - 1][1]) {
            cout << "Sebanyak                   = "; cin >> sebanyak;
            // Tambah stock
            stocks4[no_barang - 1][0] += sebanyak;
            cout << "Stock barang nomor         = " << stocks4[no_barang - 1][1] << ", bertambah menjadi   = "<< stocks4[no_barang - 1][0] << endl;
                } else {
            cout << "Produk tidak ditemukan." << endl;
            goto bagkategori;
            }
    }
    else if (pilkategori == 5) {
            cout << "Barang ke berapa           = "; cin >> no_barang;
            // Cek apakah nomor barang valid
            if (no_barang > 0 && no_barang <= stocks5[no_barang - 1][1]) {
            cout << "Sebanyak                   = "; cin >> sebanyak;
            // Tambah stock
            stocks5[no_barang - 1][0] += sebanyak;
            cout << "Stock barang nomor         = " << stocks5[no_barang - 1][1] << ", bertambah menjadi   = "<< stocks5[no_barang - 1][0] << endl;
                } else {
            cout << "Produk tidak ditemukan." << endl;
            goto bagkategori;
            }
    }
    else {
            cout<<"Mohon masukan pilihan antara 1-5 "<<endl;
            getch();
            goto  nambahstock;
    }
        getch();
        goto loginadmin;
        break;
    }
    case 2: {
      system("cls");
        cout << "-----------------------------------" << endl;
        cout << "-----------Register----------------" << endl;
        cout << "-----------------------------------" << endl;

        registerformadmin:
        // Validasi nama
        if (nama_sama == false) {
            cout << "Masukkan nama            = ";
            cin >> input_nama;

            if (input_nama.length() > 10) {
                cout << "Nama maksimal 10 karakter." << endl;
                goto registerformadmin;
            continue;
            }

        // Validasi nama yang sama
            nama_sama = false;
            for (int j = 0; j <= anggota; j++) {
                if (input_nama == nama[j]) {
                    cout << "Nama sudah terdaftar." << endl;
                    goto registerformadmin;
                    nama_sama = true;
                break;
                }
            }
        }
        //memasukan umur
        inputumurad:
        while (cout << "Masukan umur anda        = " && !(cin >> input_umur)) {
            //menghapus apapun yang diinput di variabel input_umur
            cin.clear();
            //menghapus buffer input, buffer input adalah nilai hasil input pada memori pada input sebelumya
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan hanya angka saja"<<endl;
        }
        // umur harus minimal 17 tahun
        if (input_umur < 17  || input_umur > 121) {
          cout << "Umur minimal 17 tahun." << endl;
          getch();
          goto inputumurad;
          continue;
        }

        passwordad:
        // Validasi password
        cout << "Masukkan password        = ";
        cin >> input_password;

        if (input_password.length() < 8) {
            cout << "Password minimal 8 karakter." << endl;
            goto passwordad;
            break;
        }
        if (input_password.length() > 16) {
          cout << "Password maksimal 16 karakter." << endl;
          goto passwordad;
          break;
        }

        // Simpan data ke array
        nama[anggota] = input_nama;
        password[anggota] = input_password;
        umur[anggota] = input_umur;
        anggota++;
        cout<<"Selamat, akun berhasil didaftarkan"<<endl;
        getch();
        goto loginadmin;
        break;
    }

    case 3: {
    // Tampilkan hasil pemesanan
        cout << "========================================================="<<endl;
        cout << "|      Nama User     | Jumlah Barang |   Total Belanjaan  |"<<endl;
        cout << "========================================================="<<endl;

        for (auto it = data_pesanan.begin(); it != data_pesanan.end(); it++) {
            cout <<"|"<<setiosflags(ios::left)<<setw(18)<< it->first <<"|";
            cout <<setiosflags(ios::left)<<setw(17)<< it->second.first <<"|";
            cout <<setiosflags(ios::left)<<setw(19)<<"Rp. "<< it->second.second <<"|"<<endl;
        }
            getch();
            goto loginadmin;
            break;
    }
    case 4: {
    // Logout
        cout <<"Apakah anda mau logout jika iya y jika tidak n"<<endl;
        cin>>logout;

        if(!logout){
            system("cls");
            cout << "Logout dibatalkan!"<< endl<<endl;
            goto loginadmin;
        } cout <<endl;

            switch(logout){
                case 'y':
                system("cls");
                cout << "Berhasil logout!"<< endl<<endl;

                login_sukses = false;
                loginroleadmin = false;

                    if(login_sukses == false){
                        goto menuawal;}
                        break;

                case 'n':
                system("cls");
                cout << "Logout dibatalkan!"<< endl<<endl;
                    goto loginadmin;
                    break;

                default:
                system("cls");
                cout << "Jawaban Tidak Valid"<<endl;
                cout << "Logout dibatalkan!"<< endl<<endl;
                goto loginadmin;
                break;
            }
    }
        default: {
            cout << "Pilihan tidak valid." << endl;
            getch();
            goto loginadmin;
            break;
        }
      }
     }
    } break;

    }

    case 2: {
       system("cls");
        cout << "-----------------------------------" << endl;
        cout << "-----------Register----------------" << endl;
        cout << "-----------------------------------" << endl;

        registerform:
        // Validasi nama
        if (nama_sama == false) {
          cout << "Masukkan nama            = ";
          cin >> input_nama;

          if (input_nama.length() > 10) {
            cout << "Nama maksimal 10 karakter." << endl;
            goto registerform;
            continue;
          }

        // Validasi nama yang sama
          nama_sama = false;
          for (int j = 0; j <= anggota; j++) {
            if (input_nama == nama[j]) {
              cout << "Nama sudah terdaftar." << endl;
               goto registerform;
              nama_sama = true;

              break;
            }
          }
        }
        inputumurut:
        while (cout << "Masukan umur anda        = " && !(cin >> input_umur)) {
            //menghapus apapun yang diinput di variabel input_umur
            cin.clear();
            //menghapus buffer input, buffer input adalah nilai hasil input pada memori pada input sebelumya
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan hanya angka saja"<<endl;
            }

        // umur harus minimal 17 tahun
        if (input_umur < 17 || input_umur > 130) {
          cout << "Umur minimal 17 tahun." << endl;
          getch();
          goto inputumurut;
          continue;
        }
        passwordut:
        // Validasi password
        cout << "Masukkan password        = ";
        cin >> input_password;

        if (input_password.length() < 8) {
          cout << "Password minimal 8 karakter." << endl;
          goto passwordut;
          break;
        }

        if (input_password.length() > 16) {
          cout << "Password maksimal 16 karakter." << endl;
          goto passwordut;
          break;
        }

        // Simpan data ke array
        nama[anggota] = input_nama;
        password[anggota] = input_password;
        umur[anggota] = input_umur;
        anggota++;
        cout<<"Selamat, akun berhasil didaftarkan"<<endl;
        getch();
        break;
      }



    case 3: {
    system("cls");
      cout << "------------------------------------" << endl;
      cout << "-----------Change Password---------" << endl;
      cout << "------------------------------------" << endl;

      inputnama:
      cout << "Masukkan nama            = "; cin >> input_nama;

      // Validasi nama
        while (!nama_valid) {
            if (input_nama.length() > 10) {
                cout << "Nama maksimal 10 karakter." << endl;
                goto inputnama;
            break;
            }
    // Validasi nama yang ada di array
        for (int i = 0; i < anggota; i++) {
            if (input_nama == nama[i]) {
                nama_valid = true;
            break;
                }
            }

        if (!nama_valid) {
            cout << "Nama tidak terdaftar." << endl;
            cout << "Apakah ingin mengulangi? (y/n) ";
            cin >> pilihan;

            if (pilihan == 'n' || pilihan =='N') {
                goto menuawal;

            } else if (pilihan == 'y' || pilihan == 'Y') {
                goto inputnama;

            }else {
                cout<<"tolong masukan pilihan yang benar"<<endl;
            }
        }
    }
        //validasi umur pada array
        inputumur:
        while (cout << "Masukan umur anda        = " && !(cin >> input_umur)) {
            //menghapus apapun yang diinput di variabel input_umur
            cin.clear();
            //menghapus buffer input, buffer input adalah nilai hasil input pada memori pada input sebelumya
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan hanya angka saja"<<endl;
        }
        for (int i = 0; i < anggota; i++) {
        // Validasi umur yang ada di array
            if (input_umur == umur[i]) {
                umur_valid = true;
                break;
            }
        }

        if(!umur_valid){
            cout << "Umur salah " << endl;
            goto inputumur;
        }


        // Validasi password
        for (int i = 0; i < anggota; i++) {

        // Cek apakah nama, ummur dan password lama cocok
            if (input_nama == nama[i] && input_umur == umur[i]) {

        // nama dan umur cocok, lanjutkan ke proses selanjutnya, Hapus password lama
                password[i] = "";

        // Validasi password baru
                cout << "Masukkan password        = "; cin >> input_password_baru;

        // Cek apakah password baru sama dengan password lama
                if (password[i] == input_password_baru) {
                    cout << "Password baru tidak boleh sama dengan password lama." << endl;
                    continue;
                }

        // Ganti password
                password[i] = input_password_baru;
                cout << "Password berhasil diganti." << endl;
                break;
            }
        }

            getch();

    }

    case 4: {
    system("cls");
        cout << "Terima Kasih sudah menggunakan aplikasi kami" << endl;
        break;
    }
    default: {
        cout << "Pelanggan yang terhormat, mohon masukan pilihan yang benar diantara 1-4" << endl;
        getch();
    }
    }

  } while (pilih != 4 );

     return 0;
}
