#pragma once
#include"mylib.h"
#include"DanhSachMonHoc.h"
#include"DanhSachDangKi.h"
#define MAXLOP 10000


extern string tenFileLTC;
extern int xLTC[10];
extern int yLTC[3];
struct LopTinChi {
	int maLopTC;
	char maMH[11];
	char nienKhoa[10];
	int hocKi;
	int nhom;
	int svMin;
	int svMax;
	bool huyLop=0;
	DSDK lopDK;
	int slSV=0;
	bool coDiem=0;
};
typedef struct LopTinChi LTC;

struct DanhSachLopTinChi {
	int n=0;
	LTC* lop[MAXLOP];
};
typedef struct DanhSachLopTinChi DSLTC;

struct ThongKeLop{
	int n=0;
	float *diem[SISOLOP];
	int *slTC[SISOLOP];
	SinhVien *sv[SISOLOP];
};
typedef struct ThongKeLop TKL;

void tang1NamHoc(char namHoc[]);

void capNhatNamHoc_HocKi(DSLTC &dsLop);

bool empty(DSLTC& dsLop);

bool full(DSLTC& dsLop);

bool themBoNho(DSLTC& dsLop);

bool them1BoNho(DSLTC& dsLop);

void xoaBoNhoTKL(TKL & lop);

void xoaBoNho(DSLTC& dsLop);

void xoa1BoNho(DSLTC& dsLop,int i);

void xoa1BoNhoTheoMaLTC(DSLTC& dsLop,int maLTC);

string chuyenMaLopSangTenFile(int maLTC);

int docSinhVienDK(string tenFileLop,DSDK& lopDK,bool &coDiem);

void ghiSinhVienDK(string tenFileLop,DSDK& lopDK,int n);

void docFileLTC(DSLTC&dsLop);

void ghiFileLTC( DSLTC& dsLop);

//=======================**=======================
//XU LI DO HOA
//=======================**=======================

void taoCacNutLenh_LTC();

void taoBangLTC();

void diChuyenChuotLTC(int x,int y,int& xCu,int &yCu,int &vt);

void nhapNienKhoa(int x1, int y1, char namHoc1[]);

void xuat1LTC(DSMH_AVL root,LTC x,int y, int stt,int mau);

void locLTCtheoNienKhoa_HocKi(char namHoc1[],int hocKi1,DSLTC dsLop,DSLTC& dsLop1);

void xuatLTC(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang);

void thaoTacNhapMaMHLTC(int x,int y,int max, char s[], int &kt);

void inDamDongLTC(int y, int mau);

int chonMaMonHoc(int vt, int &vtCu, int &trangHienTai,MANGMH &mang);

void chonMaMH(MANGMH mang,char maMH[],int hocKi);

void thaoTacNhapSoLTC(int x,int y,int &so,int &kt);

bool kiemTraTrungLTC(DSLTC&dsLop1,LTC &x,int y);

int nhap1LTC(char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang);

void nhapLTC(char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang);

int chonLTC(int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root);

void thaoTacXoaLTC(int &stt, DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root);

void hieuChinh1LTC(int stt,char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang);

void kiemTraLTC(DSLTC &dsLop);

void manHinhLopTinChi(DSMH_AVL root, DSLTC & dsLop);

//====================================================================
int timSLTC(char maMH[],DSMH_AVL root);

void inThongTinSinhVien(Node sv);

void taoCacNutLenhDK();

void taoBangDK();

void taoBangDaDK();

void diChuyenChuotDK(int x,int y,int& xCu,int &yCu,int &vt);

void nhapSVDK(int x1, int y1, char maSV[]);

void xuat1LTCDaDK(char maSVdk[],DSMH_AVL root,LTC x,int y, int stt,int mau);

void xuatLTCDaDK(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang,int *chon,char maSVdk[]);

void locLTCDaDK(DSLTC&dsLop,DSLTC &dsLop1,Node*info);

int chonLTCDaDK(char maSVdk[],int chon[],int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root);

void xuatNienKhoa(int x,int y,char namHoc[]);

int chonHocKi(int x,int y);

void xuat1LTCDK(DSMH_AVL root,LTC x,int y, int stt,int mau);

void xuatLTCDK(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang,int *chon);

int chonLTCDK(int chon[],int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root,int &soTCdk);

bool kiemTraDaChon(int chon[],int &n);

void thucHienDK(int *chon,DSLTC&dsLop2,DSLTC&dsLop1,NodeDK *sv,Node*info);

void locLTCtheoNienKhoa_HocKi_2(char namHoc1[],int hocKi1,DSLTC dsLop,DSLTC& dsLop1);

void thucHienHuyLTCDaDK(DSLTC &dsLop1,char maSV[],int *chon,Node*info);

void thaoTacHuyDK(DSLTC &dsLop1,char maSV[],int *chon,Node*info);

void layViTriChuotTrenBangDK(int x,int y,int xSS,int ySS, int &vt);

void chonNienKhoa_HocKi(char namHoc[],int &hocKi);

int tinhSoLuongTCHienTai(DSMH_AVL root,DSLTC& dsLop1,char namHoc[],int hocKi);

void manHinhDangKi(DSMH_AVL root,DSLTC & dsLop,DanhSach&list);

//===================================================================================
//===================================================================================
//===================================================================================

void chuyenFloatSangChar(float n,char s[]);

void nhapMaLopTK(int x1, int y1,int max, char s[]);

void taoCacNutLenhTK();

void taoBangTK();

void diChuyenChuotTK(int x,int y,int& xCu,int &yCu,int &vt);

void xuat1SVTKTB(SinhVien *x,float diem,int y, int stt,int mau);

void xuatTKTB(TKL& lop,int trangHienTai,int tongSoTrang);

void themSVVaoLopTK(TKL&lop,SinhVien& sv1);

void timSVTheoMaLopTK(char maLop[],TKL &lop,DanhSach& list);

void tinhDiemTB(DSMH_AVL root,DSLTC & dsLop,TKL &lop);

void taoBangTK_MaMH();

void taoBangTK_2();

void diChuyenChuotTK_2(int x,int y,int& xCu,int &yCu,int &vt);

void duyetLopCoDiemVaSV(DSLTC dsLop,DSLTC &dsLop1,SinhVien* sv[],int n);

int demSoLopKhongTrung(DSLTC dsLop1,int * kiemTra);

float timDiemTK(char maSV[],LTC lop1);

void timDiemCua1SV(char maSV[],float diem[],DSLTC dsLop1,int *kiemTra);
void xuatDiem1SV(float diem[],int mau,int y,int stt2,int &n);
void xuatDiem(DSLTC &dsLop1,int *kiemTra,float bangDiem[][100],int trangHienTai1,int trangHienTai2,int tongSoTrang2,int n,int &soMon);
void xuat1SVTKTK(SinhVien* x,int y, int stt,int mau);
void xuatTKTK(TKL &lop,DSLTC &dsLop1,int *kiemTra,float bangDiem[][100],int &soMon,int trangHienTai1,int tongSoTrang1,int trangHienTai2,int tongSoTrang2);

void manHinhThongKe(DSMH_AVL root,DSLTC & dsLop,DanhSach &list);
//===================================================================
//===================================================================
//MAN HINH NHAP DIEM
void xoaBangNhapDiem(int ytemp);
void giaoDienNhapDiem(int xTrangT , int xTrangS,int yTrang, int x1 ,int y1, int kc );
void inHangTieuDeNhapDiem(int ytemp1,const char *s1 ,const char *s2,const char *s3,const char *s4,const char *s5);
void thaoTacNhapDiem(float &diem ,int x,int y);
void keBangDiem();
void keHangNhap(int y1 , int kc);
void nhapNienKhoaDiem(int x1, int y1, char namHoc1[] ,int &select);
void inDamNutHCNhocki(int x, int y , int chieuDai, int chieuRong,const char*s,int mau);
void inDamNutHCNDiem(int x, int y , int chieuDai, int chieuRong,const char*s,int mau);
void chonHocKiDiem(int hocKi ,int x , int y);
void setHocKi(int x , int y , int &hocKi,int &select);
void nextHocKi(int x , int y ,int &select,int hocKi);
void thaoTacNhapSoNhom(int x,int y,int &so,int &kt );
void diChuyenChuotDiem(int x,int y,int& xCu,int &yCu,int &vt);
void chonMHDiem(DSMH_AVL root,char maMH[],int&select);
void thaoTacNhapMaMHDiem(int x,int y,int max, char s[], int &kt,DSMH_AVL root,bool checkDS);
void xuat1SV(NodeDK *k ,int Y1 , int STTreal ,int mau,DanhSach list);
void xuat1SVDSDK(NodeDK *k ,int Y1 , int STTreal ,int mau,DanhSach list);
void XuatDSDKLTC(DanhSach list,DSLTC& dsLop , int Trang , int &soTrang ,int f);
void XuatDSLTC(DanhSach list,DSLTC& dsLop , int Trang , int &soTrang ,int f);
void kiemTra(DanhSach &list ,DSLTC& dsLop , char *nienKhoa , int &hocKi , int &nhom , char *maMHtemp , int &f,int &Trang ,int &soTrang,bool checkDS,int &select);
void viTriChuotDK(int &STT , int x , int y , int y1 , int kcSV);
void toDamSVDK(NodeDK *iftemp,DSLTC& dsLop, DanhSach list ,int &STT ,int STTinput,int Trang,int f);
void xoaToDSDK(NodeDK *iftemp,DSLTC& dsLop, DanhSach list ,int &STT ,int Trang ,int &xoaToMau);
void vaoDiem(float diemTemp , DSLTC &dsLop,int f ,int STT);
void thaoTacNhapThongTin(int &select ,int yNhap ,int kc , char nienKhoa[] ,char maMH[],int&hocKi ,int nhom ,int &ds , int &Trang , int&soTrang, DanhSach list,DSLTC& dsLop,bool checkDS,DSMH_AVL root);
void nhapDiemList(float &diem ,int x,int y,int &chon);
void thaoTacNhapDiemList(DanhSach list , DSLTC& dsLop,int &Trang ,int soTrang ,int f );
void manHinhNhapDiem(DanhSach &list ,DSLTC& dsLop,DSMH_AVL root);
