#pragma once
#include"mylib.h"
#include"DanhSachSinhVien.h"

#define SISOLOP 150

struct DangKi
{
	char maSVdk[16] ;
	float diemSV=-1;
	int huyDangKi=0;
};
typedef struct DangKi DangKi ;
struct NodeDK
{
	DangKi data;
	NodeDK *next;
};
typedef struct NodeDK NodeDK ;
struct DanhSachDangKi
{
	NodeDK *head;//quan li node dau
	NodeDK *tail;//quan li node cuoi
};
typedef struct DanhSachDangKi DSDK ;


void KhoiTaoDK(DSDK &listDK);
NodeDK *KhoiTaoNodeDK();
void themSVDK(DSDK &listDK,NodeDK *p);
void themVaoCuoiDK (DSDK &listDK , NodeDK *p);
void themVaoDauDK (DSDK &listDK , NodeDK *p);
void XoaDauDK(DSDK &listDK);
void XoaCuoiDK(DSDK &listDK);
void XoaKhoaK(DSDK &listDK, char MaSVdk[]);
void giaiPhongVungNhoDK(DSDK &listDK);
void Doc_fileDK_1_SV(ifstream &fileIn , DangKi &dk);
Node* timThongTin1SV (char maSVdk[] , DanhSach list );



