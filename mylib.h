
#include <conio.h>
#include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include<iostream>
#include<fstream>
#include<fstream> 
//#include<cstring>

#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;
#define mauBang1 9
#define mauBang2 15
#define mauBang3 10
#define xThongBao 150
#define yThongBao 350
#define xBang 1051
#define khoangCachNut 60 
#define khoangCachDong 40

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::getline;
using std :: ios_base ;

void taoNutHCN(int x, int y , int chieuDai, int chieuRong,const char*s);

//void inThongTin(int x, int y , int chieuDai, int chieuRong,const char*s);

void inDamNutHCN(int x, int y , int chieuDai, int chieuRong,const char*s,int mau);

void inBangThongBao(const char*s1,const char*s2,const char*s3,const char*s4,const char*s5);

void daoChieu(char s[]);

void doiSosangChuoi(int n, char s[]);

int soSanh2Chuoi(char s1[], char s2[]);

string ghepSoTrang(int trangHienTai, int tongSoTrang);

void thaoTacNhap(int x,int y,int max, char s[],int &kt);

void thaoTacNhapMa(int x,int y,int max, char s[], int &kt);

void doiKiTuSangSo(char s[],int &x);

void thaoTacNhapSo(int x,int y,int &so ,int &kt);

void layViTriChuotTrenBang(int x,int y,int xSS,int ySS, int &vt);

void chonNutDongY_Huy(int x,int y, int&xCu, int& yCu, int &vt);

void xoaNutDongY_Huy();

