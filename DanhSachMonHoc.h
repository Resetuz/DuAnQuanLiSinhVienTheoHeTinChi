#pragma once
#include"mylib.h"


#define MAX 300


extern int toaDoX[7];
extern int toaDoY[3];



struct MonHoc {
	char maMH[11];
	char tenMH[51];
	int STCLT;
	int STCTH;
	int slLop=0;
};

typedef struct MonHoc MH;

struct DanhSachMonHoc {
	MH monHoc;
	int height;
	struct DanhSachMonHoc *left,*right;
};

typedef struct DanhSachMonHoc* DSMH_AVL;

struct MangMonHoc{
	int n=0;
	MH *node[MAX];
};

typedef struct MangMonHoc MANGMH;

/*============================================================
	CAC THU TUC VA HAM XU LY CAC HOAT DONG NEN
============================================================= */

void Posorder_GiaiPhongVungNho(DSMH_AVL& p);

void Initialize(DSMH_AVL& root);

int max(int a, int b);

DSMH_AVL newNode(MH& x);

int height(DSMH_AVL p);

DSMH_AVL Rotate_Left(DSMH_AVL root);

DSMH_AVL Rotate_Right(DSMH_AVL ya);



int getBalance(DSMH_AVL p);

DSMH_AVL Insert(DSMH_AVL node, MH x);

DSMH_AVL minValueNode(DSMH_AVL node);

DSMH_AVL Remove(DSMH_AVL &root, char x[]);

void docFile1( DSMH_AVL& root);

void ghiFileMH( DSMH_AVL& root,int n);

void Preorder(DSMH_AVL root,MANGMH &mang);

void timKiemTenMH(DSMH_AVL& root,char maMH1[],char *tenMH1);

void tangGiamLopTC_MH(DSMH_AVL& root,char maMH1[],bool kt);


/*============================================================
	CAC THU TUC VA HAM XU LY CAC HOAT DONG TREN MAN HINH
============================================================= */

void taoCacNutLenh();

void taoBang();

void diChuyenChuot(int x,int y,int& xCu,int &yCu,int &vt);

void xuat1MonHoc(MH x,int y,int stt,int mau);

void xuatMonHocTheoTrang(int trangHienTai, int tongSoTrang, MANGMH mang);

void inDamDong(int y, int mau);

bool kiemTraTrungMH(char maMH[],DSMH_AVL &root);



int nhap1MonHoc(int &trangHienTai,int &tongSoTrang,MANGMH &mang,DSMH_AVL &root);


void nhapMonHoc(int &trangHienTai,int &tongSoTrang,MANGMH &mang,DSMH_AVL &root);



int chonMonHoc(int vt, int &vtCu, int &trangHienTai,MANGMH &mang);


void thaoTacXoa(int &stt, MANGMH & mang,DSMH_AVL &root);

void hieuChinh1MonHoc(int &stt, int trangHienTai,int tongSoTrang,MANGMH &mang,DSMH_AVL &root);

void manHinhMonHoc(DSMH_AVL root);


