#pragma once
#include"mylib.h"


struct SinhVien
{
	string MaSV;
	string Ho ,Ten ;
	string Phai   ;
	string SoDT;
	string MaLop;
	int slDK=0;
};
typedef struct SinhVien SinhVien;

struct Node{
	SinhVien data;
	Node *next;
};

typedef struct Node Node;

struct DanhSach
{
	Node *head;//quan li node dau
	Node *tail;//quan li node cuoi
};
typedef struct DanhSach DanhSach ;


void KhoiTao(DanhSach &list);

Node *KhoiTaoNode(SinhVien sv);

void themVaoCuoi (DanhSach &list , Node *p);

void chuyen(string s , char *temp);

void chuyensangString(string &s , char *temp);


void Doc_file_1_SV(ifstream &fileIn , SinhVien &sv);

void Doc_FILE_DSSV( DanhSach &list );

void themVaoDau (DanhSach &list , Node *p);

//void themVaoBatKi (DanhSach &list , Node *p , int vt);

void xoaBang (int ytemp);

void XuatDS(DanhSach &list, char *maLOP , int Trang , int soTrang );

void xoaToDamButton(int &xLight , int &yLight , const char *sButton,int &chuyen );

void XoaDau(DanhSach &list);

void XoaCuoi(DanhSach &list);

void giaiPhongVungNho(DanhSach &list);

void GHI_FILE_DSSV(DanhSach &list);

bool checkNode(DanhSach list , int &dem,char *maLOP );

void sapXepAlphaB(DanhSach &list);

void chuyenMaLop (char *maLop , char *maLoptemp);

bool checkMaSV(char *maSV , DanhSach list);

void thaoTacNhapMaLop( char *temp ,int x ,int y,int &i );

void thaoTacNhapMSSV(int x,int y,int max, char *temp , int &slot);
 
void thaoTacNhapBoChuSoXoaCach(int x,int y,int max, char *temp , int &slot);

void thaoTacNhapKoSoKoCach(int x,int y,int max, char *temp ,int&slot);

void thaoTacNhapChiSo(int x,int y,int max, char *temp ,int &slot);

void xoaBatKi(DanhSach &list , int vt , int &Trang , int &soTrang , char *maLop);

void xoaSinhVien(DanhSach &list , int vt , int &Trang , int &soTrang , char *maLop);

void toDamDSSV(int x1,int &x2 ,int y1, int &y2,const char *& s, const char* s1 );

void chuyenThongTinClick( SinhVien hieuChinh , char *maSV ,char *HoSV,char *TenSV,char *SDT);

void toDamSV(SinhVien &k, DanhSach list ,int &STT ,int STTinput,int Trang,char *maLop);

void toDamClickSV(SinhVien &k, DanhSach list ,int STT , int &keep , int Trang,char *maLop);

void xoaToDS(int &STT ,DanhSach list, SinhVien k , int Trang ,int &xoaToMau);

void inDamGioiTinh(int xtemp  ,int xtemp2,int STT , const char *gioiTinh , int mau);

void setGioiTinh(int &sex , int STTx , int &slot);

void endsex(int sex, int STTx , int &slot);

void inHangTieuDe(int ytemp1);

void giaoDienDSSV( int xTrangT , int xTrangS,int yTrang, int x1 ,int y1, int kc );

void viTriChuot (int &STT , int x , int y , int y1 , int kcSV);

void toMauHangThem(int STT , int mau , int y , int kc);

void ThemSV(DanhSach &list  ,char maLOPtemp[] , char maSV[] ,char hoSV[] ,char tenSV[] , char SDTSV[] , int sex);

void keBangDSSV();

void manHinhDSSV(DanhSach &list);

