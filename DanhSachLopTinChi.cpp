#include"DanhSachLopTinChi.h"
const int DKA[7]={0,350,450,700,1050,1200,1340};
const int DKB[3]={60,120,687};
int maLopTuDong=0;
char namHocHienTai[]="2019-2020";
int hocKiHienTai=1;
int xLTC[10]={0,300,400,500,600,960,1060,1160,1260,1351};
int yLTC[3]={0,100,687};
string tenNutLTC[10]={"NAM HOC",
	"THEM",
	"XOA",
	"HIEU CHINH",
	"THOAT",
	"<",
	">",
	"HK 1",
	"HK 2",
	"HK 3"	
};
string tenDeMucLTC[8]={"STT",
	"MA LTC",
	"MA MH",
	"TEN MON HOC",
	"NHOM",
	"SV MIN",
	"SV MAX",
	"TT"
};

string tenNutDK[6]={"NHAP MSSV",
	"DK LTC",
	"HUY DK",
	"THOAT",
	"<",
	">"
};

string tenDeMucDaDK[8]={"STT",
	"MA LTC",
	"MA MH",
	"TEN MON HOC",
	"NHOM",
	"HOC KI",
	"NK",
	"TT"
};

string tenDeMucDK[8]={"STT",
	"MA LTC",
	"MA MH",
	"TEN MON HOC",
	"NHOM",
	"DA DK",
	"CL",
	"TT"
};

string tenNutTK[8]={"MA LOP",
	"BANG TRUNG BINH",
	"BANG THONG KE",
	"THOAT",
	"<",
	">",
	"^",
	"v"	
};
string tenDeMucTKTB[5]={"STT",
	"MA SV",
	"HO",
	"TEN",
	"DIEM TB",
};

void tang1NamHoc(char namHoc[]){
	char s[5];
	int x;
	for(int i=0;i<4;i++){
		namHoc[i]=namHoc[i+5];
		s[i]=namHoc[i+5];
	}
	s[4]='\0';
	doiKiTuSangSo(s,x);
	x++;
	doiSosangChuoi(x,s);
	for(int i=0;i<4;i++){
		namHoc[i+5]=s[i];
	}
}
void capNhatNamHoc_HocKi(DSLTC &dsLop){
	for(int i=0;i<dsLop.n;i++){
		if(dsLop.lop[i]->coDiem==1){
		if(soSanh2Chuoi(namHocHienTai,dsLop.lop[i]->nienKhoa)<0){
			for(int j=0;j<strlen(dsLop.lop[i]->nienKhoa);j++){
				namHocHienTai[j]=dsLop.lop[i]->nienKhoa[j];
				namHocHienTai[j+1]='\0';
				continue;
			}
			if(dsLop.lop[i]->hocKi==3){
				tang1NamHoc(namHocHienTai);
				hocKiHienTai=1;
				continue;
			}
			if(hocKiHienTai<=dsLop.lop[i]->hocKi){
				hocKiHienTai=dsLop.lop[i]->hocKi+1;
			}
		}
		else if(soSanh2Chuoi(namHocHienTai,dsLop.lop[i]->nienKhoa)==0){
			if(dsLop.lop[i]->hocKi==3){
				tang1NamHoc(namHocHienTai);
				hocKiHienTai=1;
				continue;
			}
			if(hocKiHienTai<=dsLop.lop[i]->hocKi){
				hocKiHienTai=dsLop.lop[i]->hocKi+1;
			}
		}
	}
	}

}

bool empty(DSLTC& dsLop) {
	if(dsLop.n==0)
		return 1;
	else
		return 0;
}


bool full(DSLTC& dsLop) {
	if(dsLop.n==MAXLOP)
		return 1;
	else
		return 0;
}


// Them bo nho cho lop tin chi
bool themBoNho(DSLTC& dsLop) {
	if (full(dsLop)) {
		return false;
	}
	for(int i=0;i<dsLop.n;i++){
	dsLop.lop[i]= new LTC;
	KhoiTaoDK(dsLop.lop[i]->lopDK);
	}
	return true;
}
bool them1BoNho(DSLTC& dsLop) {
	if (full(dsLop)) {
		return false;
	}
	dsLop.lop[dsLop.n]= new LTC;
	KhoiTaoDK(dsLop.lop[dsLop.n]->lopDK);
	dsLop.n++;
	return true;
}
void xoaBoNhoTKL(TKL & lop){
	if(lop.n==0){
		return;
	}
	for(int i=0;i<lop.n;i++){
		delete lop.diem[i];
		delete lop.slTC[i];
	}
	lop.n=0;
}

void xoaBoNho(DSLTC& dsLop) {
	if (empty(dsLop)) {
		return ;
	}
	for(int i=0;i<dsLop.n;i++){
		giaiPhongVungNhoDK(dsLop.lop[i]->lopDK);
		delete dsLop.lop[i];
	}
	dsLop.n=0;
}
void xoa1BoNho(DSLTC& dsLop,int i){
	if (empty(dsLop)) {
		return ;
	}
	for(int j=i;j<dsLop.n-1;j++){
		dsLop.lop[j]=dsLop.lop[j+1];
	}
	giaiPhongVungNhoDK(dsLop.lop[dsLop.n-1]->lopDK);
	delete dsLop.lop[dsLop.n-1];
	dsLop.n--;
}
void xoa1BoNhoTheoMaLTC(DSLTC& dsLop,int maLTC){
	if (empty(dsLop)) {
		return ;
	}
	for(int i=0;i<dsLop.n;i++){
		if(dsLop.lop[i]->maLopTC==maLTC){
			xoa1BoNho(dsLop,i);
			return;
		}
	}
}

 //doc du lieu
string chuyenMaLopSangTenFile(int maLTC){
	string s;
	char s1[10];
	s[0]='\0';
	doiSosangChuoi(maLTC,s1);
	for(int i=0;i<strlen(s1);i++){
		s+=s1[i];
	}
	s="Data\\"+s+".txt";
	return s;
}
int docSinhVienDK(string tenFileLop,DSDK& lopDK,bool &coDiem){
	ifstream fileIn;
	int n=0;
	int kt=0;
	int i=0;
	fileIn.open(tenFileLop,ios::in);
	fileIn>>n;
	for(int i=0;i<n;i++){
		NodeDK *sv=new NodeDK;
		fileIn.ignore();
		fileIn.getline(sv->data.maSVdk,16);
		fileIn>>sv->data.diemSV;
		fileIn>>sv->data.huyDangKi;
//		if(sv->data.huyDangKi==0){
//			i++;
//		}
		if(sv->data.diemSV!=-1){
			kt++;
		}
		themVaoCuoiDK(lopDK,sv);
	}
	if(kt>0){
		coDiem=1;
	}else {
		coDiem =0;
	}
	fileIn.close();
	return n;
}

void ghiSinhVienDK(string tenFileLop,DSDK& lopDK,int n){
	ofstream fileOut;
	NodeDK *sv=lopDK.head;
	fileOut.open(tenFileLop,ios::out);
	fileOut<<n<<endl;
	int kt =0 ;
     while(n>0){	
		if(sv==NULL){
			return;
		}
		if(sv->data.huyDangKi==1){
			sv=sv->next;
			continue;
		}
		fileOut<<sv->data.maSVdk<<endl;
		fileOut<<sv->data.diemSV<<endl;
		fileOut<<sv->data.huyDangKi<<endl;
		n--;
		sv=sv->next;
	}
	fileOut.close();
}

void docFileLTC(DSLTC&dsLop) {
	ifstream fileIn;
	int max =0;
	string tenFileLop;
	fileIn.open("DanhSachLopTinChi.txt", ios::in);
		fileIn >> dsLop.n;
		if (themBoNho(dsLop)) {
			for (int i = 0; i < dsLop.n; i++) {
				LTC tmp;
				fileIn >> tmp.maLopTC;
				fileIn.ignore();  // xoa ky tu dau tien trong bo nho dem
				fileIn.getline(tmp.maMH, 11);
				fileIn.getline(tmp.nienKhoa,10);
				fileIn >> tmp.hocKi;
				fileIn >> tmp.nhom;
				fileIn >> tmp.svMin;
				fileIn >> tmp.svMax;
				fileIn >> tmp.huyLop;
				KhoiTaoDK(tmp.lopDK);
				tenFileLop=chuyenMaLopSangTenFile(tmp.maLopTC);
				tmp.slSV=docSinhVienDK(tenFileLop,tmp.lopDK,tmp.coDiem);
				if(max<tmp.maLopTC){
					max=tmp.maLopTC;
				}
				*dsLop.lop[i] = tmp;
			}
			maLopTuDong=max;
		}
	fileIn.close();
}

//ghi du lieu 

void ghiFileLTC( DSLTC& dsLop) {
	ofstream fileOut;
	string tenFileLop;
	fileOut.open("DanhSachLopTinChi.txt", ios::out);
	fileOut << dsLop.n << endl;
	for (int i = 0; i < dsLop.n; i++) {
		fileOut << dsLop.lop[i]->maLopTC << endl;
		fileOut << dsLop.lop[i]->maMH << endl;
		fileOut << dsLop.lop[i]->nienKhoa << endl;
		fileOut << dsLop.lop[i]->hocKi << endl;
		fileOut << dsLop.lop[i]->nhom << endl;
		fileOut << dsLop.lop[i]->svMin << endl;
		fileOut << dsLop.lop[i]->svMax << endl;
		fileOut << dsLop.lop[i]->huyLop << endl;
		tenFileLop=chuyenMaLopSangTenFile(dsLop.lop[i]->maLopTC);
		ghiSinhVienDK(tenFileLop,dsLop.lop[i]->lopDK,dsLop.lop[i]->slSV);
	}
	fileOut.close();
}

//========================================================
//  XU LI DO HOA
//========================================================
//MAN HINH LTC
void taoCacNutLenh_LTC(){
	int y= yLTC[1]/2;
	taoNutHCN((xLTC[9]-xLTC[8])/2+xLTC[8],y*2-10,80,30,tenNutLTC[9].c_str());
	taoNutHCN((xLTC[8]-xLTC[7])/2+xLTC[7],y*2-10,80,30,tenNutLTC[8].c_str());
	taoNutHCN((xLTC[7]-xLTC[6])/2+xLTC[6],y*2-10,80,30,tenNutLTC[7].c_str());
	for(int i=0;i<5;i++){
		taoNutHCN((xLTC[1]-xLTC[0])/2,y,200,40,tenNutLTC[i].c_str());
		y+=khoangCachNut;
	}
}

void taoBangLTC(){
	int y=yLTC[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=11){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
		line(xLTC[1],y,xLTC[9],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[1],y,xLTC[9],y);
	setbkcolor(mauBang1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	for(int i=0;i<8;i++){
		outtextxy((xLTC[i+2]-xLTC[i+1])/2+xLTC[i+1],yLTC[1]+20,tenDeMucLTC[i].c_str());
	}
	for(int i=1;i<10;i++){
		line(xLTC[i],yLTC[1],xLTC[i],y);
	}
	
	y+=khoangCachDong;
	taoNutHCN(xLTC[1]+50,y,40,40,tenNutLTC[5].c_str());
	taoNutHCN(xLTC[9]-50,y,40,40,tenNutLTC[6].c_str());
}

void diChuyenChuotLTC(int x,int y,int& xCu,int &yCu,int &vt,int hocKi){
	int xSS=(xLTC[1]-xLTC[0])/2;
	int ySS= yLTC[1]/2;
	for(int i=0;i<5;i++){
		if(x<=xSS+100&&x>=xSS-100&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xSS,ySS+khoangCachNut*i,200,40,tenNutLTC[i].c_str(),4);
				if(vt!=-1){
					if(vt<5){
						taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
					} 
					if(vt>=5&&vt<7){
						taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
					}
					if(vt>=7&&vt!=6+hocKi){
						taoNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str());
					}
				}
				xCu=xSS;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
	}
	if(x<=xLTC[1]+50+20&&x>=xLTC[1]+50-20&&y>=yLTC[1]+12*khoangCachDong-30&&y<=yLTC[1]+12*khoangCachDong+10){
		if(vt==5){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+12*khoangCachDong,40,40,tenNutLTC[5].c_str(),4);
		if(vt!=-1){
			if(vt<5){
					taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				} 
			if(vt>=5&&vt<7){
				taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
				}
			if(vt>=7&&vt!=6+hocKi){
				taoNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str());
			}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+12*khoangCachDong;
		vt=5;
		return;	
	}
	if(x<=xLTC[9]-50+20&&x>=xLTC[9]-50-20&&y>=yLTC[1]+12*khoangCachDong-30&&y<=yLTC[1]+12*khoangCachDong+10){
		if(vt==6){
			return;
		}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+12*khoangCachDong,40,40,tenNutLTC[6].c_str(),4);
		if(vt!=-1){
			if(vt<5){
					taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				} 
			if(vt>=5&&vt<7){
				taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
				}
			if(vt>=7&&vt!=6+hocKi){
				taoNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str());
			}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+12*khoangCachDong;
		vt=6;
		return;	
	}
	for(int i=7;i<10;i++){
		if(x<=(xLTC[i]-xLTC[i-1])/2+xLTC[i-1]+40&&x>=(xLTC[i]-xLTC[i-1])/2+xLTC[i-1]-40&&y>=yLTC[1]-35&&y<=yLTC[1]-5){
			if(vt==i||hocKi+6==i){
				return;
			}
			inDamNutHCN((xLTC[i]-xLTC[i-1])/2+xLTC[i-1],yLTC[1]-10,80,30,tenNutLTC[i].c_str(),4);
			if(vt!=-1){
				if(vt<5){
					taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				} 
				if(vt>=5&&vt<7){
					taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
				}	
				if(vt>=7&&vt!=6+hocKi){
					taoNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str());
				}
			}
			xCu=(xLTC[i]-xLTC[i-1])/2+xLTC[i-1];
			yCu=yLTC[1]-10;
			vt=i;
			return;	
		}
	}
	if(vt!=-1){
		if(vt<5){
			taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
		} 
		if(vt>=5&&vt<7){
			taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
			}
		if(vt>=7){
			if(vt!=6+hocKi)
				taoNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str());
		}
		vt=-1;
	}
}

void nhapNienKhoa(int x1, int y1, char namHoc1[]) {
	int i = 0;
	int xNhap = x1+130;
	setfillstyle(1, 15);
	setbkcolor(15);
	settextjustify(0,1);
	settextstyle(10, 0, 2);
	bar(x1 + 120, y1 - 30, x1 + 300, y1 + 10);
	y1-=10;
	outtextxy(xNhap, y1, "-NK:");
	xNhap += textwidth("-NK: ");
	while (true) {
		settextjustify(0,1);
		settextstyle(2, 0, 5);
		if (kbhit()) {
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 8 && i > 0) {
				if (i == 5) {
					xNhap -= textwidth(&namHoc1[i-1]);
					namHoc1[i-1]='\0';
					i--;
					outtextxy(xNhap, y1, "   ");
				}
				xNhap -= textwidth(&namHoc1[i-1]);
				namHoc1[i-1]='\0';
				i--;
				outtextxy(xNhap, y1, "   ");
			}

			if (c[0] == 13 && i == 9) {
				namHoc1[i] = '\0';
				setfillstyle(1, 1);
				bar(x1 + 120, y1 - 20, x1 + 300, y1 + 20);
				break;
			}
			if (c[0] >= '0' && c[0] <= '9') {
				if (i == 9) {
					continue;
				}
				namHoc1[i] = c[0];
				namHoc1[i+1] = '\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap += textwidth(&c[0]);
				i++;
			}
			if (i == 4) {
				namHoc1[i] = '-';
				namHoc1[i+1] = '\0';
				outtextxy(xNhap, y1, "-");
				xNhap += textwidth("-");
				i++;
			}
		}
		else {
			settextstyle(4, 0, 1);
			outtextxy(xNhap+3, y1 , "|");
			delay(500);
			outtextxy(xNhap+3, y1 , " ");
			delay(200);
		}
	}
}

void xuat1LTC(DSMH_AVL root,LTC x,int y, int stt,int mau){
	char s[10];
	char tenMH1[51];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(xLTC[1]+5,y-15,xLTC[2]-5,y+15);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
	bar(xLTC[2]+5,y-15,xLTC[3]-5,y+15);
	doiSosangChuoi(x.maLopTC,s);
	outtextxy((xLTC[3]-xLTC[2])/2+xLTC[2],y,s);
	bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
	outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x.maMH);
	timKiemTenMH(root,x.maMH,tenMH1);
	settextjustify(0,1);
	bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
	outtextxy(xLTC[4]+20,y,tenMH1);
	settextjustify(1,1);
	doiSosangChuoi(x.nhom,s);
	bar(xLTC[5]+5,y-15,xLTC[6]-5,y+15);
	outtextxy((xLTC[6]-xLTC[5])/2+xLTC[5],y,s);
	doiSosangChuoi(x.svMin,s);
	bar(xLTC[6]+5,y-15,xLTC[7]-5,y+15);
	outtextxy((xLTC[7]-xLTC[6])/2+xLTC[6],y,s);
	doiSosangChuoi(x.svMax,s);
	bar(xLTC[7]+5,y-15,xLTC[8]-5,y+15);
	outtextxy((xLTC[8]-xLTC[7])/2+xLTC[7],y,s);
	if(x.coDiem==1){
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"Hoan Thanh");
		return;
	}
	if(x.huyLop==0){
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"Hoat Dong");
	} else{
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"thieu SV");
	}
}

void locLTCtheoNienKhoa_HocKi(char namHoc1[],int hocKi1,DSLTC dsLop,DSLTC& dsLop1){
	dsLop1.n=0;
	for(int i=0;i<dsLop.n;i++){
		if((soSanh2Chuoi(namHoc1,dsLop.lop[i]->nienKhoa)==0&&hocKi1==dsLop.lop[i]->hocKi)){
			dsLop1.n++;
			dsLop1.lop[dsLop1.n-1]=dsLop.lop[i];
		}
	}
}

void xuatLTC(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang){
	if(trangHienTai==0){
		return;
	}
	string s1=ghepSoTrang(trangHienTai,tongSoTrang);
	setbkcolor(1);
	settextstyle(4,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+12*khoangCachDong,s1.c_str());
	int stt=(trangHienTai-1)*10+1;
	int y=yLTC[1]+khoangCachDong+khoangCachDong/2;
	int dem=1;
	while(dem<=10&&stt<=dsLop.n){
		if(dem%2==0){
			xuat1LTC(root,*dsLop.lop[stt-1],y,stt,mauBang1);
		}else{
			xuat1LTC(root,*dsLop.lop[stt-1],y,stt,mauBang2);
		}	
		y+=khoangCachDong;
		stt++;
		dem++;
	}
}
void thaoTacNhapMaMHLTC(int x,int y,int max, char s[], int &kt){
	setbkcolor(mauBang3);
	setfillstyle(1,mauBang3);
	settextstyle(2, 0, 5);
	settextjustify(0,1);
	bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
	int i = strlen(s);
	outtextxy(x, y ,s);
	x+=textwidth(s);
	while (true) {
		settextstyle(2, 0, 5);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				kt=0;
				return;
			}
			if(c[0]==59){
				kt=5;
				return;
			}
			if(c[0]==75){
				if(kt>1){
            		s[i] = '\0';
            		kt--;
            		break;
            	} 
            	if(kt==1){
            		s[i] = '\0';
            		kt=4;
            		break;	
				}
			}
			if (c[0]==77) {
				if(kt<4){
					s[i] = '\0';
					kt++;
					break;
				}
				if(kt==4){
					s[i] = '\0';
            		kt=4;
            		break;
				}
			}
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=6;
				break;
			}
			if (c[0] == 8 && i > 0) {
				x-=textwidth(&s[i-1]);
				s[i-1]='\0';
                i--;
                outtextxy(x, y ,"   ");
            }
			if(i==max){
				continue;
			}
			
			if (c[0] >= '0' && c[0] <= '9') {
				s[i] = c[0];
				s[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] =='-' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}
            delay(1);
		}else{
			settextstyle(4, 0, 1);
			outtextxy(x+3, y , "|");
			delay(500);
			outtextxy(x+3, y , " ");
			delay(200);
		}
	}
	settextjustify(1,1);
}



void inDamDongLTC(int y, int mau){
	setfillstyle(1,mau);
	bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
	line(xLTC[1],y,xLTC[9],y);
	line(xLTC[1],y+khoangCachDong,xLTC[9],y+khoangCachDong);
	for(int i=1;i<10;i++){
		line(xLTC[i],y,xLTC[i],y+khoangCachDong);
	}
}
int chonMaMonHoc(int vt, int &vtCu, int &trangHienTai,MANGMH &mang){
	if(vt+(trangHienTai-1)*10>mang.n){
		return 0;
	}
	if(vt==vtCu){
		if(ismouseclick(WM_LBUTTONDBLCLK)){
		inDamDong(toaDoY[1]+vt*khoangCachDong,10);
		xuat1MonHoc(*mang.node[vt+(trangHienTai-1)*10-1],toaDoY[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
		clearmouseclick(WM_LBUTTONDBLCLK);
		return vt+(trangHienTai-1)*10;
		} else return 0;
	}
	if(vt==0){
		if(vtCu!=-1){
			inDamDong(toaDoY[1]+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
			xuat1MonHoc(*mang.node[vtCu+(trangHienTai-1)*10-1],toaDoY[1]+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*10,(vtCu%2==0)?mauBang1:mauBang2);
			vtCu=-1;
		}
		return 0;
	}
	
	inDamDong(toaDoY[1]+vt*khoangCachDong,12);
	xuat1MonHoc(*mang.node[vt+(trangHienTai-1)*10-1],toaDoY[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,12);
	if(vtCu!=-1){
		inDamDong(toaDoY[1]+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
		xuat1MonHoc(*mang.node[vtCu+(trangHienTai-1)*10-1],toaDoY[1]+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*10,(vtCu%2==0)?mauBang1:mauBang2);
	}	
	vtCu=vt;
	if(ismouseclick(WM_LBUTTONDBLCLK)){
			inDamDong(toaDoY[1]+vt*khoangCachDong,10);
			xuat1MonHoc(*mang.node[vt+(trangHienTai-1)*10-1],toaDoY[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
			clearmouseclick(WM_LBUTTONDBLCLK);
		return vt+(trangHienTai-1)*10;
	}
	return 0;
}

void chonMaMH(MANGMH mang,char maMH[],int hocKi){
	int xChuot=0;
	int yChuot=0;
	int xCu=0;
	int yCu=0;
	int vt=-1;
	int vtBang=-1;
	int vtBang1=0;
	int stt =0;
	int tongSoTrang=mang.n/10;
	int trangHienTai=0;
	if(tongSoTrang>0){
		trangHienTai=1;
	}
	if(mang.n%10!=0){
		tongSoTrang=tongSoTrang+1;
	}
	//taoCacNutLenh();
	taoBang();
	xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
	inBangThongBao("-Nhay dup trai","de chon mon hoc.","-Nhan ESC","de thoat.","");
	while(true){
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				return;
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			diChuyenChuotLTC(xChuot,yChuot,xCu,yCu,vt,hocKi);
			layViTriChuotTrenBang(xChuot,yChuot,(toaDoX[6]-toaDoX[1])/2+toaDoX[1],toaDoY[1],vtBang1);
		}
		if(stt==0){
			stt=chonMaMonHoc(vtBang1,vtBang,trangHienTai,mang);
		}
		if(stt!=0){
			for(int i=0;i<strlen(mang.node[stt-1]->maMH);i++){
				maMH[i]=mang.node[stt-1]->maMH[i];
			}
			maMH[strlen(mang.node[stt-1]->maMH)]='\0';
			return;
		}
		if(ismouseclick(WM_LBUTTONDBLCLK)){
			clearmouseclick(WM_LBUTTONDBLCLK);
				continue;
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==6&&trangHienTai<tongSoTrang&&stt==0){
				trangHienTai++;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==5&&trangHienTai>1&&stt==0){
				trangHienTai--;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				stt=0;
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(100);
	}
}
void thaoTacNhapSoLTC(int x,int y,int &so,int &kt ){
	settextstyle(2, 0, 5);
	settextjustify(0,1);
	char s[10];
	int i=0;
	if(so!=-1){
		doiSosangChuoi(so,s);
		i = strlen(s);
		outtextxy(x, y ,s);
		x+=textwidth(s);
	}


	while (true) {
		settextstyle(2, 0, 5);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				kt=0;
				return;
			}
			if(c[0]==75){
				if(kt>1){
            		s[i] = '\0';
            		kt--;
            		break;
				}
            	if(kt==1){
					s[i] = '\0';
            		kt=4;
            		break;
				}
			}
			
			if (c[0]==77) {
				if(kt<4){
            		s[i] = '\0';
            		kt++;
            		break;
				}
            	if(kt==4){
					s[i] = '\0';
            		kt=1;
            		break;
				}
			}
			
			if (c[0] == 8 && i > 0) {
				x-=textwidth(&s[i-1]);;
				s[i-1]='\0';
                i--;
                outtextxy(x, y ,"   ");
            }
			if(i==10){
				continue;
			}
			
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=6;
				break;
			}
			if (c[0] >= '1' && c[0] <= '9' ||c[0]=='0'&&i>0) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			delay(100);
		} else{
			settextstyle(4, 0, 1);
			outtextxy(x+3, y , "|");
			delay(500);
			outtextxy(x+3, y , " ");
			delay(200);
		}
	}
	doiKiTuSangSo(s,so);
}
bool kiemTraTrungLTC(DSLTC&dsLop1,LTC &x,int y){
	for(int i=0;i<dsLop1.n-1;i++){
		if(soSanh2Chuoi(x.maMH,dsLop1.lop[i]->maMH)==0&&x.nhom==dsLop1.lop[i]->nhom){
			bar(xLTC[7]+5,y-15,xLTC[8]-5,y+15);
			return 1;
		}
	}
	return 0;
}

int nhap1LTC(char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang){
	int y=yLTC[1]+khoangCachDong+khoangCachDong/2;
	int kt=1;
	LTC x;
	char tenMH1[51];
	tenMH1[0]='\0';
	char maMHCu[11];
	maMHCu[0]='\0';
	if(dsLop1.n+1>tongSoTrang*10){
		tongSoTrang++;
	}
	trangHienTai=tongSoTrang;
	taoBangLTC();
	xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
	if(them1BoNho(dsLop)){
		maLopTuDong++;
		x.maLopTC=maLopTuDong;
		x.maMH[0]='\0';
		for(int i=0;i<strlen(namHoc);i++){
			x.nienKhoa[i]=namHoc[i];
		}
		x.nienKhoa[strlen(namHoc)]='\0';
		x.hocKi=hocKi;
		x.nhom=-1;
		x.svMin=-1;
		x.svMax=-1;
		KhoiTaoDK(x.lopDK);
		dsLop1.n++;
		dsLop1.lop[dsLop1.n-1]=dsLop.lop[dsLop.n-1];
		int stt=dsLop1.n;
		char s[10];
		y+=((dsLop1.n-1)%10)*khoangCachDong;
		setbkcolor(mauBang3);
		inDamDongLTC(y-khoangCachDong/2,mauBang3);
		doiSosangChuoi(stt,s);
		settextstyle(2,0,5);
		settextjustify(1,1);
		outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
		doiSosangChuoi(x.maLopTC,s);
		outtextxy((xLTC[3]-xLTC[2])/2+xLTC[2],y,s);
		while(kt!=7){
			switch(kt){
				case 0:{
					xoa1BoNho(dsLop,dsLop.n-1);
					dsLop1.n--;
					return 0;
				};
				case 1:{
					inBangThongBao("-Nhan F1 de","tra ma MH.","-Nhan ESC","de huy nhap.","");
					for(int i=0;i<strlen(x.maMH);i++){
						maMHCu[i]=x.maMH[i];
					}
					maMHCu[strlen(x.maMH)]='\0';
					thaoTacNhapMaMHLTC(xLTC[3]+20,y,10,x.maMH,kt);
					if(x.maMH[0]!='\0'&&kt!=5){
						if(soSanh2Chuoi(x.maMH,maMHCu)!=0){
							tangGiamLopTC_MH(root,maMHCu,0);
							tangGiamLopTC_MH(root,x.maMH,1);
						}
						timKiemTenMH(root,x.maMH,tenMH1);
						if(tenMH1[0]=='\0'){
							inBangThongBao("-Mon Hoc nay","khong","ton tai.","","");
							delay(2000);
							inBangThongBao("","","","","");
							x.maMH[0]='\0';
							kt=1;
						} else{
							bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
							outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x.maMH);
							settextjustify(0,1);
							bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
							outtextxy(xLTC[4]+20,y,tenMH1);
							settextjustify(1,1);
						}
					}
					break;
				}
				case 2:{
					thaoTacNhapSoLTC((xLTC[6]-xLTC[5])/2+xLTC[5]-10,y,x.nhom,kt);
					break;
				}
				case 3:{
					setbkcolor(mauBang3);
					settextjustify(1,1);
					setfillstyle(1,mauBang3);
					thaoTacNhapSoLTC((xLTC[7]-xLTC[6])/2+xLTC[6]-10,y,x.svMin,kt);
					if(x.svMin<0&&x.svMin!=-1){
						inBangThongBao("-SV MIN","khong the","be hon","0.","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=4;
					}
					break;
				}
				case 4:{
					setbkcolor(mauBang3);
					thaoTacNhapSoLTC((xLTC[8]-xLTC[7])/2+xLTC[7]-10,y,x.svMax,kt);
					if(x.svMax<=x.svMin&&x.svMax!=-1){
						inBangThongBao("-SV MAX","khong the","be hon","SV MIN.","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=4;
					}
					break;
				}
				case 5:{
					chonMaMH(mang,x.maMH,hocKi);
					if(soSanh2Chuoi(x.maMH,maMHCu)!=0){
						tangGiamLopTC_MH(root,maMHCu,0);
						tangGiamLopTC_MH(root,x.maMH,1);
					}
					taoBangLTC();
					xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
					setbkcolor(mauBang3);
					inDamDongLTC(y-khoangCachDong/2,mauBang3);
					doiSosangChuoi(stt,s);
					settextstyle(2,0,5);
					settextjustify(1,1);
					outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
					doiSosangChuoi(x.maLopTC,s);
					outtextxy((xLTC[3]-xLTC[2])/2+xLTC[2],y,s);
					bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
					outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x.maMH);
					timKiemTenMH(root,x.maMH,tenMH1);
					settextjustify(0,1);
					bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
					outtextxy(xLTC[4]+20,y,tenMH1);
					settextjustify(1,1);
					kt=6;
					break;
				}
				case 6:{
					if(x.maMH[0]=='\0'){
						kt=1;
					} else
					if(x.nhom==-1){
						kt=2;
					} else if(kiemTraTrungLTC(dsLop1,x, y)) {
						inBangThongBao("-Lop Tin Chi","da","ton tai.","","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=1;
					} else
					if(x.svMin==-1){
						kt=3;
					} else
					if(x.svMax==-1){
						kt=4;
					} else{
						kt=7;
					}
					break;
				}
			}
		}
		*dsLop.lop[dsLop.n-1]=x;
		return 1;
	}
}

void nhapLTC(char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang){
	int n=1;
	while(n==1){
		n=nhap1LTC(namHoc,hocKi,trangHienTai,tongSoTrang,dsLop,dsLop1,root,mang);
		if(dsLop1.n==0){
			tongSoTrang=0;
			trangHienTai=tongSoTrang;
			taoBangLTC();
			xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
			continue;
		}
		if(dsLop1.n%10==0){
			tongSoTrang=dsLop1.n/10;
		}else{
			tongSoTrang=dsLop1.n/10+1;
		}
		trangHienTai=tongSoTrang;
		taoBangLTC();
		xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
	}
}



int chonLTC(int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root){
	if(vt+(trangHienTai-1)*10>dsLop1.n||dsLop1.n==0){
		return 0;
	}
	if(vt==vtCu&&vt!=0){
		if(ismouseclick(WM_LBUTTONDOWN)){
		inDamDongLTC(yLTC[1]+vt*khoangCachDong,10);
		xuat1LTC(root,*dsLop1.lop[vt+(trangHienTai-1)*10-1],yLTC[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
		inBangThongBao("Bam XOA de xoa.","Bam HIEU CHINH","de hieu chinh","-Bam THOAT de","thoat che do.");
		clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*10;
		} else return 0;
	}
	if(vt==0){
		if(vtCu!=-1){
			inDamDongLTC(yLTC[1]+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
			xuat1LTC(root,*dsLop1.lop[vtCu+(trangHienTai-1)*10-1],yLTC[1]+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*10,(vtCu%2==0)?mauBang1:mauBang2);
			vtCu=-1;
		}
		return 0;
	}
	
	inDamDongLTC(yLTC[1]+vt*khoangCachDong,12);
	xuat1LTC(root,*dsLop1.lop[vt+(trangHienTai-1)*10-1],yLTC[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,12);
	if(vtCu!=-1){
		inDamDongLTC(yLTC[1]+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
		xuat1LTC(root,*dsLop1.lop[vtCu+(trangHienTai-1)*10-1],yLTC[1]+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*10,(vtCu%2==0)?mauBang1:mauBang2);
	}	
	vtCu=vt;
	if(ismouseclick(WM_LBUTTONDOWN)){
			inDamDongLTC(yLTC[1]+vt*khoangCachDong,10);
			xuat1LTC(root,*dsLop1.lop[vt+(trangHienTai-1)*10-1],yLTC[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
			inBangThongBao("Bam XOA de xoa.","Bam HIEU CHINH","de hieu chinh","-Bam THOAT de","thoat che do.");
			clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*10;
	}
	return 0;
}

void thaoTacXoaLTC(int &stt, DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root){
	int x= xThongBao;
	int y=yThongBao+6*khoangCachDong;
	int vt=-1;
	int xCu=-1;
	int yCu=-1;
	int xChuot=-1;
	int yChuot=-1;
	inBangThongBao("-Ban chac chan","xoa lop TC", "nay?","","");
	inDamNutHCN(x,y,280,40,"DONG Y",10);
	y+=khoangCachDong;
	inDamNutHCN(x,y,280,40,"HUY",12);
	while(true){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			chonNutDongY_Huy(xChuot,yChuot,xCu,yCu,vt);
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				if(dsLop1.lop[stt-1]->coDiem==1){
					inBangThongBao("-Lop tin chi","da co diem.","-Khong the xoa","","");
					delay(2000);
					inBangThongBao("","","","","");
					stt=0;
					clearmouseclick(WM_LBUTTONDOWN);
					break;
				}
				xoa1BoNhoTheoMaLTC(dsLop,dsLop1.lop[stt-1]->maLopTC);
				tangGiamLopTC_MH(root,dsLop1.lop[stt-1]->maMH,0);
				for(int i=stt-1;i<dsLop1.n-1;i++){
					dsLop1.lop[i]=dsLop1.lop[i+1];
				}
				dsLop1.n--;
				//xoa1BoNho(dsLop1,stt-1);
				stt=0;
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
			if(vt==1){
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
		}
		delay(100);
	}
}
void hieuChinh1LTC(int stt,char namHoc[],int hocKi, int &trangHienTai,int &tongSoTrang,DSLTC &dsLop,DSLTC&dsLop1,DSMH_AVL &root, MANGMH mang){
	if(dsLop1.lop[stt-1]->coDiem==1){
		inBangThongBao("-Lop da co diem","khong the","hieu chinh.","","");
		delay(2000);
		inBangThongBao("","","","","");
		return;
	}
	int y=yLTC[1]+khoangCachDong+khoangCachDong/2;
	int kt=1;
	LTC *x=dsLop1.lop[stt-1];
	char tenMH1[51];
	tenMH1[0]='\0';
	char maMHCu[11];
	maMHCu[0]='\0';
	for(int i=0;i<strlen(x->maMH);i++){
		maMHCu[i]=x->maMH[i];
	}
	maMHCu[strlen(x->maMH)]='\0';
	y+=((stt-1)%10)*khoangCachDong;
	setbkcolor(mauBang3);
	inDamDongLTC(y-khoangCachDong/2,mauBang3);
	xuat1LTC(root,*x,y,stt,mauBang3);
//	char s[10];
		while(kt!=7){
			switch(kt){
				case 0:{
					taoBangLTC();
					xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
					return;
				};
				case 1:{
					inBangThongBao("-Nhan F1 de","tra ma MH.","-Nhan ESC","de huy nhap.","");
					thaoTacNhapMaMHLTC(xLTC[3]+20,y,10,x->maMH,kt);
					if(x->maMH[0]!='\0'){
						if(soSanh2Chuoi(x->maMH,maMHCu)!=0){
							tangGiamLopTC_MH(root,maMHCu,0);
							tangGiamLopTC_MH(root,x->maMH,1);
						}
						timKiemTenMH(root,x->maMH,tenMH1);
						if(tenMH1[0]=='\0'){
							inBangThongBao("-Mon Hoc nay","khong","ton tai.","","");
							delay(2000);
							inBangThongBao("","","","","");
							x->maMH[0]='\0';
							kt=1;
						} else{
							bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
							outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x->maMH);
							settextjustify(0,1);
							bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
							outtextxy(xLTC[4]+20,y,tenMH1);
							settextjustify(1,1);
						}
					}
					break;
				}
				case 2:{
					bar(xLTC[5]+5,y-15,xLTC[6]-5,y+15);
					thaoTacNhapSoLTC((xLTC[6]-xLTC[5])/2+xLTC[5]-10,y,x->nhom,kt);
					break;
				}
				case 3:{
					bar(xLTC[6]+5,y-15,xLTC[7]-5,y+15);
					thaoTacNhapSoLTC((xLTC[7]-xLTC[6])/2+xLTC[6]-10,y,x->svMin,kt);
					break;
				}
				case 4:{
					setbkcolor(mauBang3);
					//setfillstyle(1,mauBang3);
					thaoTacNhapSoLTC((xLTC[8]-xLTC[7])/2+xLTC[7]-10,y,x->svMax,kt);
					if(x->svMax<=x->svMin&&x->svMax!=-1){
						inBangThongBao("-SV MAX","khong the","be hon","SV MIN.","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=4;
					}
					break;
				}
				case 5:{
					chonMaMH(mang,x->maMH,hocKi);
					if(soSanh2Chuoi(x->maMH,maMHCu)!=0){
						tangGiamLopTC_MH(root,maMHCu,0);
						tangGiamLopTC_MH(root,x->maMH,1);
					}
					taoBangLTC();
					xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
					setbkcolor(mauBang3);
					inDamDongLTC(y-khoangCachDong/2,mauBang3);
					xuat1LTC(root,*x,y,stt,mauBang3);
					kt=2;
					break;
				}
				case 6:{
					if(x->maMH[0]=='\0'){
						kt=1;
					} else
					if(x->nhom==-1){
						kt=2;
					} else
					if(x->svMin==-1){
						kt=3;
					} else
					if(x->svMax==-1){
						kt=4;
					} else if(kiemTraTrungLTC(dsLop1,*x, y)) {
						inBangThongBao("-Lop Tin Chi","da","ton tai.","","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=1;
					} else{
						kt=0;
					}
					break;
				}
			}
		}
		return ;
}
void kiemTraLTC(DSLTC &dsLop){
	for(int i=0;i<dsLop.n;i++){
		if(dsLop.lop[i]->slSV<dsLop.lop[i]->svMin){
			dsLop.lop[i]->huyLop=1;
		}
	}
}

void manHinhLopTinChi(DSMH_AVL root,DSLTC &dsLop){
	capNhatNamHoc_HocKi(dsLop);
	DSLTC dsLop1;
	MANGMH mang;
	bool kiemTraChoPhep=1;
	int xChuot=0;
	int yChuot=0;
	int xCu=-1;
	int yCu=-1;
	int vt=-1;
	int hocKi=0;
	int vtBang=-1;
	int vtBang1=0;
	int stt=0;
	char namHoc[10];
	namHoc[0]='\0';
	int tongSoTrang=0;
	int trangHienTai=0;
	Preorder(root,mang);
	setbkcolor(1);
	cleardevice();
	settextstyle(4,0,4);
	settextjustify(1,1);
	outtextxy((getmaxx()-xLTC[1])/2+xLTC[1],42," DANH SACH LOP TIN CHI");
	taoCacNutLenh_LTC();
	taoBangLTC();
	inBangThongBao("-Ban dang lam","viec voi","danh sach","lop tin chi.","^-^");
	
	while(true){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			diChuyenChuotLTC(xChuot,yChuot,xCu,yCu,vt,hocKi);
			layViTriChuotTrenBang(xChuot,yChuot,(xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1],vtBang1);
		}
		if(stt==0&&namHoc[0]!='\0'&&kiemTraChoPhep){
			stt=chonLTC(vtBang1,vtBang,trangHienTai,dsLop1,root);
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				inDamNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str(),10);
				nhapNienKhoa((xLTC[1]-xLTC[0])/2,yLTC[1]/2,namHoc);
				if(hocKi!=0){
					for(int i=7;i<10;i++){
						if(hocKi==i-6){
							taoNutHCN((xLTC[i]-xLTC[i-1])/2+xLTC[i-1],yLTC[1]-10,80,30,tenNutLTC[i].c_str());
							break;
						}
					}
				}
				setbkcolor(1);
				settextstyle(4,0,2);
				settextjustify(1,1);
				outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1], 70, namHoc);
				if(soSanh2Chuoi(namHoc,namHocHienTai)<0){
					inBangThongBao("-Nam hoc da","ket thuc.","-Chi co the xem.","","");
					kiemTraChoPhep=0;
					hocKiHienTai=4;
				}else if(soSanh2Chuoi(namHoc,namHocHienTai)==0){
					hocKi=hocKiHienTai;
					kiemTraChoPhep=1;
				}else {
					kiemTraChoPhep=1;
					hocKi=1;
				}
				for(int i=7;i<10;i++){
					if(hocKi==i-6){
						inDamNutHCN((xLTC[i]-xLTC[i-1])/2+xLTC[i-1],yLTC[1]-10,80,30,tenNutLTC[i].c_str(),10);
						break;
					}
				}
				locLTCtheoNienKhoa_HocKi(namHoc,hocKi,dsLop,dsLop1);
				kiemTraLTC(dsLop1);
				if(dsLop1.n>0){
					trangHienTai=1;
					tongSoTrang=dsLop1.n/10;
					if(dsLop1.n%10!=0){
						tongSoTrang+=1;
					}
				}
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				vt=-1;
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(kiemTraChoPhep==1){
			if(vt==1&&namHoc[0]!='\0'){
				inDamNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str(),10);
				nhapLTC(namHoc,hocKi,trangHienTai,tongSoTrang,dsLop,dsLop1,root,mang);
				taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				vt=-1;
				clearmouseclick(WM_LBUTTONDOWN);
				inBangThongBao("-Ban dang lam","viec voi","danh sach","lop tin chi.","^-^");
				continue;
			}
			if(vt==2&&stt!=0){
				inDamNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str(),10);
				if(dsLop1.lop[stt-1]->lopDK.head!=NULL){
					inBangThongBao("-Ban khong","the XOA lop.","-Lop da co","sinh vien","dang ki.");
					delay(2000);
					inBangThongBao("","","","","");
					stt=0;
				}
				else{
					clearmouseclick(WM_LBUTTONDOWN);
					thaoTacXoaLTC(stt,dsLop,dsLop1,root);
					xoaNutDongY_Huy();
					if(stt==0){
						taoBangLTC();
						xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
						vtBang=-1;
					}else{
						inDamDongLTC(yLTC[1]+vtBang*khoangCachDong,(vtBang%2==0)?mauBang1:mauBang2);
						xuat1LTC(root,*dsLop1.lop[vtBang+(trangHienTai-1)*10-1],yLTC[1]+vtBang*khoangCachDong+khoangCachDong/2,vtBang+(trangHienTai-1)*10,(vtBang%2==0)?mauBang1:mauBang2);
						vtBang=-1;
						stt=0;
					}
				
				}
				taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				vt=-1;
				inBangThongBao("-Ban dang lam","viec voi","danh sach","lop tin chi.","^-^");
				continue;
			}
			if(vt==3&&stt!=0){
				inDamNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str(),10);
				hieuChinh1LTC(stt,namHoc,hocKi,trangHienTai,tongSoTrang,dsLop,dsLop1,root,mang);
				taoNutHCN(xCu,yCu,200,40,tenNutLTC[vt].c_str());
				vt=-1;
				vtBang=-1;
				stt=0;
				inBangThongBao("-Ban dang lam","viec voi","danh sach","lop tin chi.","^-^");
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			}
			if(vt==4){
				if(stt!=0){
					inDamDongLTC(yLTC[1]+vtBang*khoangCachDong,(vtBang%2==0)?mauBang1:mauBang2);
					xuat1LTC(root,*dsLop1.lop[vtBang+(trangHienTai-1)*10-1],yLTC[1]+vtBang*khoangCachDong+khoangCachDong/2,vtBang+(trangHienTai-1)*10,(vtBang%2==0)?mauBang1:mauBang2);
					stt=0;
					vt=-1;
					inBangThongBao("-Ban dang lam","viec voi","danh sach","lop tin chi.","^-^");
					clearmouseclick(WM_LBUTTONDOWN);
					continue;
				}
				ghiFileLTC(dsLop);
				ghiFileMH(root,mang.n);
				clearmouseclick(WM_LBUTTONDOWN);
				return;
			}
			if(vt==5&&trangHienTai>1&&stt==0){
				trangHienTai--;
				taoBangLTC();
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==6&&trangHienTai<tongSoTrang&&stt==0){
				trangHienTai++;
				taoBangLTC();
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==7&&namHoc[0]!='\0'){
				if(hocKi==1){
					continue;
				}
				if(hocKi==2){
					taoNutHCN((xLTC[8]-xLTC[7])/2+xLTC[7],yLTC[1]-10,80,30,tenNutLTC[8].c_str());
				} else {
					taoNutHCN((xLTC[9]-xLTC[8])/2+xLTC[8],yLTC[1]-10,80,30,tenNutLTC[9].c_str());
				}
				hocKi=1;
				if(hocKi>=hocKiHienTai){
					kiemTraChoPhep=1;
					inBangThongBao("-Click THEM","de mo lop","moi.","","");
				}else{
					kiemTraChoPhep=0;
				}
				if(kiemTraChoPhep==0){
					inBangThongBao("-Hoc ki da","ket thuc.","-Chi co the xem.","","");
				}
				inDamNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str(),10);
				locLTCtheoNienKhoa_HocKi(namHoc,hocKi,dsLop,dsLop1);
				kiemTraLTC(dsLop1);
				if(dsLop1.n>0){
					trangHienTai=1;
					tongSoTrang=dsLop1.n/10;
					if(dsLop1.n%10!=0){
						tongSoTrang+=1;
					}
				}else{
					trangHienTai=tongSoTrang=1;
				}
				taoBangLTC();
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==8&&namHoc[0]!='\0'){
				if(hocKi==2){
					continue;
				}
				if(hocKi==1){
					taoNutHCN((xLTC[7]-xLTC[6])/2+xLTC[6],yLTC[1]-10,80,30,tenNutLTC[7].c_str());
				} else {
					taoNutHCN((xLTC[9]-xLTC[8])/2+xLTC[8],yLTC[1]-10,80,30,tenNutLTC[9].c_str());
				}
				hocKi=2;
				if(hocKi>=hocKiHienTai){
					kiemTraChoPhep=1;
					inBangThongBao("-Click THEM","de mo lop","moi.","","");
				}else{
					kiemTraChoPhep=0;
				}
				if(kiemTraChoPhep==0){
					inBangThongBao("-Hoc ki da","ket thuc.","-Chi co the xem.","","");
				}
				inDamNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str(),10);
				locLTCtheoNienKhoa_HocKi(namHoc,hocKi,dsLop,dsLop1);
				kiemTraLTC(dsLop1);
				if(dsLop1.n>0){
					trangHienTai=1;
					tongSoTrang=dsLop1.n/10;
					if(dsLop1.n%10!=0){
						tongSoTrang+=1;
					}
				}else{
					trangHienTai=tongSoTrang=1;
				}
				taoBangLTC();
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==9&&namHoc[0]!='\0'){
				if(hocKi==3){
					continue;
				}
				if(hocKi==1){
					taoNutHCN((xLTC[7]-xLTC[6])/2+xLTC[6],yLTC[1]-10,80,30,tenNutLTC[7].c_str());
				} else {
					taoNutHCN((xLTC[8]-xLTC[7])/2+xLTC[7],yLTC[1]-10,80,30,tenNutLTC[8].c_str());
				}
				hocKi=3;
				if(hocKi>=hocKiHienTai){
					kiemTraChoPhep=1;
					inBangThongBao("-Click THEM","de mo lop","moi.","","");
				}else{
					kiemTraChoPhep=0;
				}
				if(kiemTraChoPhep==0){
					inBangThongBao("-Hoc ki da","ket thuc.","-Chi co the xem.","","");
				}
				inDamNutHCN(xCu,yCu,80,30,tenNutLTC[vt].c_str(),10);
				locLTCtheoNienKhoa_HocKi(namHoc,hocKi,dsLop,dsLop1);
				kiemTraLTC(dsLop1);
				if(dsLop1.n>0){
					trangHienTai=1;
					tongSoTrang=dsLop1.n/10;
					if(dsLop1.n%10!=0){
						tongSoTrang+=1;
					}
				}else{
					trangHienTai=tongSoTrang=1;
				}
				taoBangLTC();
				xuatLTC(root,dsLop1,trangHienTai,tongSoTrang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(100);
	}
}
//tong cong 20  ca ham` va thu tuc
//END MAN HINH LTC
//=========================================================================


void inThongTinSinhVien(Node *sv){
	int y=10;
	int x=(xLTC[9]-xLTC[1])/6;
	string s;
	s[0]='\0';
	setbkcolor(mauBang2);
	setfillstyle(1,mauBang2);
	settextstyle(3,0,4);
	settextjustify(1,1);
	setlinestyle(0,0,2);
	bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
	line(xLTC[1],y,xLTC[9],y);
	line(xLTC[1],y,xLTC[1],y+khoangCachDong);
	line(xLTC[9],y,xLTC[9],y+khoangCachDong);
	line(xLTC[1],y+khoangCachDong,xLTC[9],y+khoangCachDong);
	settextstyle(10,0,2);
	settextjustify(0,1);
	outtextxy(xLTC[1]+10,y+khoangCachDong/2,"Ma SV: ");
	outtextxy(xLTC[1]+10+x,y+khoangCachDong/2,"Ho va ten: ");
	outtextxy(xLTC[1]+10+3*x,y+khoangCachDong/2,"GT: ");
	outtextxy(xLTC[1]+10+4*x,y+khoangCachDong/2,"SDT: ");
	outtextxy(xLTC[1]+10+5*x,y+khoangCachDong/2,"Lop: ");
	settextstyle(2,0,5);
	outtextxy(xLTC[1]+90,y+khoangCachDong/2,sv->data.MaSV.c_str());
	s+=sv->data.Ho+" "+sv->data.Ten;
	outtextxy(xLTC[1]+140+x,y+khoangCachDong/2,s.c_str());
	outtextxy(xLTC[1]+50+3*x,y+khoangCachDong/2,sv->data.Phai.c_str());
	outtextxy(xLTC[1]+60+4*x,y+khoangCachDong/2,sv->data.SoDT.c_str());
	outtextxy(xLTC[1]+60+5*x,y+khoangCachDong/2,sv->data.MaLop.c_str());
}

void taoCacNutLenhDK(){
	int y= yLTC[1]/2;
	for(int i=0;i<4;i++){
		taoNutHCN((xLTC[1]-xLTC[0])/2,y,200,40,tenNutDK[i].c_str());
		y+=khoangCachNut;
	}
}
void taoBangDK(){
	int y=yLTC[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=6){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
		line(xLTC[1],y,xLTC[9],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[1],y,xLTC[9],y);
	setbkcolor(mauBang1);
	settextstyle(0,0,2);
	settextjustify(1,1);
		for(int i=0;i<8;i++){
			outtextxy((xLTC[i+2]-xLTC[i+1])/2+xLTC[i+1],yLTC[1]+20,tenDeMucDK[i].c_str());
		}
	for(int i=1;i<10;i++){
		line(xLTC[i],yLTC[1],xLTC[i],y);
	}
	
	y+=khoangCachDong;
	taoNutHCN(xLTC[1]+50,y-10,30,30,tenNutDK[4].c_str());
	taoNutHCN(xLTC[9]-50,y-10,30,30,tenNutDK[5].c_str());
}
void taoBangDaDK(){
	int y=yLTC[1]+7*khoangCachDong;
	int dem=1;
	while(dem<=6){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
		line(xLTC[1],y,xLTC[9],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[1],y,xLTC[9],y);
	setbkcolor(mauBang1);
	settextstyle(0,0,2);
	settextjustify(1,1);
	for(int i=0;i<8;i++){
		outtextxy((xLTC[i+2]-xLTC[i+1])/2+xLTC[i+1],yLTC[1]+7*khoangCachDong+20,tenDeMucDaDK[i].c_str());
	}
	for(int i=1;i<10;i++){
		line(xLTC[i],yLTC[1]+7*khoangCachDong,xLTC[i],y);
	}
	
	y+=khoangCachDong;
	taoNutHCN(xLTC[1]+50,y-10,30,30,tenNutDK[4].c_str());
	taoNutHCN(xLTC[9]-50,y-10,30,30,tenNutDK[5].c_str());
}
void diChuyenChuotDK(int x,int y,int& xCu,int &yCu,int &vt){
	int xSS=(xLTC[1]-xLTC[0])/2;
	int ySS= yLTC[1]/2;
	for(int i=0;i<4;i++){
		if(x<=xSS+100&&x>=xSS-100&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xSS,ySS+khoangCachNut*i,200,40,tenNutDK[i].c_str(),4);
				if(vt!=-1){
					if(vt<4){
						taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
					} 
					if(vt>=4&&vt<=5){
						taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
					}
					if(vt>5){
						taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
					}
				}
				xCu=xSS;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
	}
	if(x<=xLTC[1]+50+15&&x>=xLTC[1]+50-15&&y>=yLTC[1]+7*khoangCachDong-35&&y<=yLTC[1]+7*khoangCachDong-5){
		if(vt==4){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+7*khoangCachDong-10,30,30,tenNutDK[4].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
				}
			if(vt>5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
			}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+7*khoangCachDong-10;
		vt=4;
		return;	
	}
	if(x<=xLTC[9]-50+15&&x>=xLTC[9]-50-15&&y>=yLTC[1]+7*khoangCachDong-35&&y<=yLTC[1]+7*khoangCachDong-5){
		if(vt==5){
			return;
			}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+7*khoangCachDong-10,30,30,tenNutDK[5].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
				}
			if(vt>5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
			}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+7*khoangCachDong-10;
		vt=5;
		return;		
	}
	if(x<=xLTC[1]+50+15&&x>=xLTC[1]+50-15&&y>=yLTC[1]+14*khoangCachDong-35&&y<=yLTC[1]+14*khoangCachDong-5){
		if(vt==6){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+14*khoangCachDong-10,30,30,tenNutDK[4].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
				}
			if(vt>5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
			}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+14*khoangCachDong-10;
		vt=6;
		return;	
	}
	if(x<=xLTC[9]-50+15&&x>=xLTC[9]-50-15&&y>=yLTC[1]+14*khoangCachDong-35&&y<=yLTC[1]+14*khoangCachDong-5){
		if(vt==7){
			return;
			}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+14*khoangCachDong-10,30,30,tenNutDK[5].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
				}
			if(vt>5){
				taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
			}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+14*khoangCachDong-10;
		vt=7;
		return;		
	}
	if(vt!=-1){
		if(vt<4){
			taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
		} 
		if(vt>=4&&vt<=5){
			taoNutHCN(xCu,yCu,30,30,tenNutDK[vt].c_str());
			}
		if(vt>5){
			taoNutHCN(xCu,yCu,30,30,tenNutDK[vt-2].c_str());
		}
		vt=-1;
	}
}
void nhapSVDK(int x1, int y1, char maSV[]) {
	int i = 0;
	int xNhap = x1+130;
	setfillstyle(1, 1);
	bar(xLTC[1]-5,5,xLTC[9]+5,5+khoangCachDong*2+12);
	setfillstyle(1, 15);
	setbkcolor(15);
	settextjustify(0,1);
	settextstyle(10, 0, 2);
	bar(x1 + 120, y1 - 30, x1 + 300, y1 + 10);
	y1-=10;
	outtextxy(xNhap, y1, "-MSSV:");
	xNhap += textwidth("-MSSV:");
	settextstyle(2, 0, 5);
	while (true) {
		settextjustify(0,1);
		settextstyle(2, 0, 5);
		if (kbhit()) {
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				maSV[0]='\0';
				break;
			}
			if (c[0] == 8 && i > 0) {
				if (i == 5) {
					xNhap -= textwidth(&maSV[i-1]);
					maSV[i-1]='\0';
					i--;
					outtextxy(xNhap, y1, "   ");
				}
				xNhap -= textwidth(&maSV[i-1]);
				maSV[i-1]='\0';
				i--;
				outtextxy(xNhap, y1, "   ");
			}

			if (c[0] == 13 && i >0) {
				maSV[i] = '\0';
				setfillstyle(1, 1);
				bar(x1 + 120, y1 - 20, x1 + 300, y1 + 20);
				break;
			}
			if (c[0] >= '0' && c[0] <= '9') {
				if (i == 15) {
					continue;
				}
				maSV[i] = c[0];
				maSV[i+1] = '\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap += textwidth(&c[0]);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				if (i == 15) {
					continue;
				}
				maSV[i] = c[0];
				maSV[i+1]='\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				if (i == 15) {
					continue;
				}
				c[0]-=('a'-'A');
				maSV[i] = c[0];
				maSV[i+1]='\0';
				outtextxy(xNhap, y1 , &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
		}
		else {
			settextstyle(4, 0, 1);
			outtextxy(xNhap+3, y1 , "|");
			delay(500);
			outtextxy(xNhap+3, y1 , " ");
			delay(200);
		}
		delay(1);
	}
}

void locLTCDaDK(DSLTC&dsLop,DSLTC &dsLop1,Node*info){
	char maSV[20];
	maSV[0]='\0';
	chuyen(info->data.MaSV,maSV);
	info->data.slDK=0;
	dsLop1.n=0;
	for(int i=0;i<dsLop.n;i++){
		NodeDK*p=dsLop.lop[i]->lopDK.head;
		if(p==NULL){
			continue;
		}
		while(p!=NULL){
			if(soSanh2Chuoi(p->data.maSVdk,maSV)==0){
				dsLop1.n++;
				dsLop1.lop[dsLop1.n-1]=dsLop.lop[i];
				info->data.slDK++;
				break;
			}
			p=p->next;
		}
	}
}

void xuat1LTCDaDK(char maSVdk[],DSMH_AVL root,LTC x,int y, int stt,int mau){
	char s[10];
	char tenMH1[51];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(xLTC[1]+5,y-15,xLTC[2]-5,y+15);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
	bar(xLTC[2]+5,y-15,xLTC[3]-5,y+15);
	doiSosangChuoi(x.maLopTC,s);
	outtextxy((xLTC[3]-xLTC[2])/2+xLTC[2],y,s);
	//settextjustify(0,1);
	bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
	outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x.maMH);
	timKiemTenMH(root,x.maMH,tenMH1);
	settextjustify(0,1);
	bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
	outtextxy(xLTC[4]+20,y,tenMH1);
	settextjustify(1,1);
	doiSosangChuoi(x.nhom,s);
	bar(xLTC[5]+5,y-15,xLTC[6]-5,y+15);
	outtextxy((xLTC[6]-xLTC[5])/2+xLTC[5],y,s);
	doiSosangChuoi(x.hocKi,s);
	bar(xLTC[6]+5,y-15,xLTC[7]-5,y+15);
	outtextxy((xLTC[7]-xLTC[6])/2+xLTC[6],y,s);
	//doiSosangChuoi(x.svMax,s);
	bar(xLTC[7]+5,y-15,xLTC[8]-5,y+15);
	outtextxy((xLTC[8]-xLTC[7])/2+xLTC[7],y,x.nienKhoa);
	if(x.coDiem==1){
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"Hoan Thanh");
	}else if(x.huyLop==0){
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"Hoat Dong");
	} else{
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"thieu SV");
	}
}
void xuatLTCDaDK(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang,int *chon,char maSVdk[]){
	string s1=ghepSoTrang(trangHienTai,tongSoTrang);
	setbkcolor(1);
	settextstyle(4,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+27*khoangCachDong/2,s1.c_str());
	int stt=(trangHienTai-1)*5+1;
	int y=yLTC[1]+8*khoangCachDong+khoangCachDong/2;
	int dem=1;
	while(dem<=5&&stt<=dsLop.n){
		if(chon!=NULL){
		if(*(chon+stt-1)==1){
			inDamDongLTC(y-khoangCachDong/2,mauBang3);
			xuat1LTCDaDK(maSVdk,root,*dsLop.lop[stt-1],y,stt,mauBang3);
			y+=khoangCachDong;
			stt++;
			dem++;
			continue;
		}}
		if(dem%2==0){
			xuat1LTCDaDK(maSVdk,root,*dsLop.lop[stt-1],y,stt,mauBang1);
		}else{
			xuat1LTCDaDK(maSVdk,root,*dsLop.lop[stt-1],y,stt,mauBang2);
		}	
		y+=khoangCachDong;
		stt++;
		dem++;
	}
}

int chonLTCDaDK(char maSVdk[],int chon[],int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root){
	if(vt+(trangHienTai-1)*5>dsLop1.n||dsLop1.n==0){
		return 0;
	}
	int y=yLTC[1]+7*khoangCachDong;
	if(vt==vtCu){
		if(ismouseclick(WM_LBUTTONDOWN)){
		if(chon[vt+(trangHienTai-1)*5-1]!=1){
			inDamDongLTC(y+vt*khoangCachDong,mauBang3);
			xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,mauBang3);
		}else{
			inDamDongLTC(y+vt*khoangCachDong,(vt%2==0)?mauBang1:mauBang2);
			xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,(vt%2==0)?mauBang1:mauBang2);
		}
		inBangThongBao("Click HUY LTC.","de huy","dang ki","-Bam THOAT de","thoat che do.");
		clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*5;
		} else return 0;
	}
	if(vt==0){
		if(vtCu!=-1&&chon[vtCu+(trangHienTai-1)*5-1]!=1){
			inDamDongLTC(y+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
			xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vtCu+(trangHienTai-1)*5-1],y+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*5,(vtCu%2==0)?mauBang1:mauBang2);
			vtCu=-1;
		}
		return 0;
	}
	if(chon[vt+(trangHienTai-1)*5-1]!=1){
		inDamDongLTC(y+vt*khoangCachDong,12);
		xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,12);
	}
	if(vtCu!=-1&&chon[vtCu+(trangHienTai-1)*5-1]!=1){
		inDamDongLTC(y+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
		xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vtCu+(trangHienTai-1)*5-1],y+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*5,(vtCu%2==0)?mauBang1:mauBang2);
	}	
	vtCu=vt;
	if(ismouseclick(WM_LBUTTONDOWN)){
			inDamDongLTC(y+vt*khoangCachDong,10);
			xuat1LTCDaDK(maSVdk,root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,10);
			//inBangThongBao("Bam XOA de xoa.","Bam HIEU CHINH","de hieu chinh","-Bam THOAT de","thoat che do.");
			clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*5;
	}
	return 0;
}
void xuatNienKhoa(int x,int y,char namHoc[]){
	string s; s[0]='\0';
	for(int i=0;i<strlen(namHoc);i++){
		s+=namHoc[i];
	}
	inDamNutHCN(x,y,180,40,s.c_str(),mauBang3);
}

int chonHocKi(int x,int y){
	string HK[3]={"HK 1","HK 2","HK 3"};
	int i=0;
	inDamNutHCN(x,y,80,40,HK[0].c_str(),12);
	taoNutHCN(x+80,y,80,40,HK[1].c_str());
	taoNutHCN(x+160,y,80,40,HK[2].c_str());
	while(true){
		if (kbhit()) {
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 13 ) {
				
				inDamNutHCN(x+80*i,y,80,40,HK[i].c_str(),mauBang3);
				return i+1;
			}
			if(c[0]==75){
				if(i==0){
					taoNutHCN(x+80*i,y,80,40,HK[i].c_str());
					i=2;
					inDamNutHCN(x+80*i,y,80,40,HK[i].c_str(),12);
				}else{
					taoNutHCN(x+80*i,y,80,40,HK[i].c_str());
					i--;
					inDamNutHCN(x+80*i,y,80,40,HK[i].c_str(),12);
				}	
			}
			if(c[0]==77){
				if(i==2){
					taoNutHCN(x+80*i,y,80,40,HK[i].c_str());
					i=0;
					inDamNutHCN(x+80*i,y,80,40,HK[i].c_str(),12);
				}else{
					taoNutHCN(x+80*i,y,80,40,HK[i].c_str());
					i++;
					inDamNutHCN(x+80*i,y,80,40,HK[i].c_str(),12);
				}	
			}
		}
		delay(100);
	}
}

void xuat1LTCDK(DSMH_AVL root,LTC x,int y, int stt,int mau){
	char s[10];
	char tenMH1[51];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(xLTC[1]+5,y-15,xLTC[2]-5,y+15);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
	bar(xLTC[2]+5,y-15,xLTC[3]-5,y+15);
	doiSosangChuoi(x.maLopTC,s);
	outtextxy((xLTC[3]-xLTC[2])/2+xLTC[2],y,s);
	//settextjustify(0,1);
	bar(xLTC[3]+5,y-15,xLTC[4]-5,y+15);
	outtextxy((xLTC[4]-xLTC[3])/2+xLTC[3],y,x.maMH);
	timKiemTenMH(root,x.maMH,tenMH1);
	settextjustify(0,1);
	bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
	outtextxy(xLTC[4]+20,y,tenMH1);
	settextjustify(1,1);
	doiSosangChuoi(x.nhom,s);
	bar(xLTC[5]+5,y-15,xLTC[6]-5,y+15);
	outtextxy((xLTC[6]-xLTC[5])/2+xLTC[5],y,s);
	doiSosangChuoi(x.slSV,s);
	bar(xLTC[6]+5,y-15,xLTC[7]-5,y+15);
	outtextxy((xLTC[7]-xLTC[6])/2+xLTC[6],y,s);
	doiSosangChuoi(x.svMax-x.slSV,s);
	bar(xLTC[7]+5,y-15,xLTC[8]-5,y+15);
	outtextxy((xLTC[8]-xLTC[7])/2+xLTC[7],y,s);
	 if(x.huyLop==0){
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"Hoat Dong");
	} else{
		bar(xLTC[8]+5,y-15,xLTC[9]-5,y+15);
		outtextxy((xLTC[9]-xLTC[8])/2+xLTC[8],y,"thieu SV");
	}
}
void xuatLTCDK(DSMH_AVL root, DSLTC dsLop,int trangHienTai,int tongSoTrang,int *chon){
	string s1=ghepSoTrang(trangHienTai,tongSoTrang);
	setbkcolor(1);
	settextstyle(4,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+13*khoangCachDong/2,s1.c_str());
	int stt=(trangHienTai-1)*5+1;
	int y=yLTC[1]+khoangCachDong/2+khoangCachDong;
	int dem=1;
	while(dem<=5&&stt<=dsLop.n){
		if(chon!=NULL){
		if(*(chon+stt-1)==1){
			inDamDongLTC(y-khoangCachDong/2,mauBang3);
			xuat1LTCDK(root,*dsLop.lop[stt-1],y,stt,mauBang3);
			y+=khoangCachDong;
			stt++;
			dem++;
			continue;
		}}
		if(dem%2==0){
			xuat1LTCDK(root,*dsLop.lop[stt-1],y,stt,mauBang1);
		}else{
			xuat1LTCDK(root,*dsLop.lop[stt-1],y,stt,mauBang2);
		}	
		y+=khoangCachDong;
		stt++;
		dem++;
	}
}
int chonLTCDK(int chon[],int vt, int &vtCu, int &trangHienTai,DSLTC &dsLop1,DSMH_AVL root,int &soTCdk){
	if(vt+(trangHienTai-1)*5>dsLop1.n||dsLop1.n==0){
		return 0;
	}
	int y=yLTC[1];
	int soTC=0;
	if(vt+(trangHienTai-1)*5-1>=0){
		soTC=timSLTC(dsLop1.lop[vt+(trangHienTai-1)*5-1]->maMH,root);
	}		
	if(vt==vtCu){
		if(ismouseclick(WM_LBUTTONDOWN)){
		if(chon[vt+(trangHienTai-1)*5-1]!=1){
			if(soTCdk+soTC<=21){
				soTCdk+=soTC;
				inDamDongLTC(y+vt*khoangCachDong,mauBang3);
				xuat1LTCDK(root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,mauBang3);
			}else{
				inBangThongBao("-Ban khong the","dang ki","qua 21","tin chi","trong hoc ki.");
				delay(2000);
				inBangThongBao("Click DK LTC.","de","dang ki","-Bam THOAT de","thoat che do.");
				return 0;
			}
		}else{
			soTCdk-=soTC;
			inDamDongLTC(y+vt*khoangCachDong,(vt%2==0)?mauBang1:mauBang2);
			xuat1LTCDK(root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,(vt%2==0)?mauBang1:mauBang2);
		}
		inBangThongBao("Click DK LTC.","de","dang ki","-Bam THOAT de","thoat che do.");
		clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*5;
		} else return 0;
	}
	if(vt==0){
		if(vtCu!=-1&&chon[vtCu+(trangHienTai-1)*5-1]!=1){
			inDamDongLTC(y+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
			xuat1LTCDK(root,*dsLop1.lop[vtCu+(trangHienTai-1)*5-1],y+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*5,(vtCu%2==0)?mauBang1:mauBang2);
			vtCu=-1;
		}
		return 0;
	}
	if(chon[vt+(trangHienTai-1)*5-1]!=1){
		inDamDongLTC(y+vt*khoangCachDong,12);
		xuat1LTCDK(root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,12);
	}
	if(vtCu!=-1&&chon[vtCu+(trangHienTai-1)*5-1]!=1){
		inDamDongLTC(y+vtCu*khoangCachDong,(vtCu%2==0)?mauBang1:mauBang2);
		xuat1LTCDK(root,*dsLop1.lop[vtCu+(trangHienTai-1)*5-1],y+vtCu*khoangCachDong+khoangCachDong/2,vtCu+(trangHienTai-1)*5,(vtCu%2==0)?mauBang1:mauBang2);
	}	
	vtCu=vt;
	if(ismouseclick(WM_LBUTTONDOWN)){
		if(soTCdk+soTC<=21){
			soTCdk+=soTC;
			inDamDongLTC(y+vt*khoangCachDong,10);
			xuat1LTCDK(root,*dsLop1.lop[vt+(trangHienTai-1)*5-1],y+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*5,10);
			clearmouseclick(WM_LBUTTONDOWN);
			return vt+(trangHienTai-1)*5;
		}else{
			inBangThongBao("-Ban khong the","dang ki","qua 21","tin chi","trong hoc ki.");
			delay(2000);
			inBangThongBao("Click DK LTC.","de","dang ki","-Bam THOAT de","thoat che do.");
			return 0;
		}
	}
	return 0;
}
bool kiemTraDaChon(int chon[],int &n){
	for(int i=0;i<n;i++){
		if(chon[i]==1){
			return 1;
		}
	}
	return 0;
}

void thucHienDK(int *chon,DSLTC&dsLop2,DSLTC&dsLop1,NodeDK *sv,Node *info){
	for(int i=0;i<dsLop2.n;i++){
		// check lop da dang ki roi
		for(int j=0;j<dsLop1.n;j++){
			if(*(chon+i)==1){
				if(dsLop2.lop[i]->maLopTC==dsLop1.lop[j]->maLopTC){
					inBangThongBao("-Ban da DK","mon hoc",dsLop2.lop[i]->maMH,"roi.","");
					delay(2000);
					inBangThongBao("","","","","");
					*(chon+i)=0;
					break;
				}
				if(soSanh2Chuoi(dsLop2.lop[i]->maMH,dsLop1.lop[j]->maMH)==0){
					if(soSanh2Chuoi(dsLop2.lop[i]->nienKhoa,dsLop1.lop[j]->nienKhoa)==0&&dsLop2.lop[i]->hocKi==dsLop1.lop[j]->hocKi){
						inBangThongBao("-Ban da DK","mon hoc",dsLop2.lop[i]->maMH,"trong hoc ki","nay roi.");
						delay(2000);
						inBangThongBao("","","","","");
						*(chon+i)=0;
						break;
					}
				}
			}
		}
		// check lop full thi khong cho dang ki 
		if(dsLop2.lop[i]->slSV ==dsLop2.lop[i]->svMax){
			inBangThongBao("-Lop mon hoc",dsLop2.lop[i]->maMH,"day roi.","","");
			delay(2000);
			inBangThongBao("","","","","");
			*(chon+i)=0;
			continue;
		}
		// them sinh vien vao nhung lop da~ chon 	
		if(*(chon+i)==1){
			info->data.slDK++;
			// check co node dang ki tronbg lop do chua
			if(dsLop2.lop[i]->lopDK.head!=NULL){
				NodeDK *q=dsLop2.lop[i]->lopDK.head;	
				while(q!=NULL){
					if(soSanh2Chuoi(q->data.maSVdk,sv->data.maSVdk)==0){
						q->data.huyDangKi=0;
						dsLop2.lop[i]->slSV++;
						if(dsLop2.lop[i]->slSV>=dsLop2.lop[i]->svMin){
							dsLop2.lop[i]->huyLop=0;
						}
						dsLop1.n++;
						dsLop1.lop[dsLop1.n-1]=dsLop2.lop[i];
						*(chon+i)=0;
						return;
					}
					q=q->next;
				}
			}
			// them moi
			NodeDK *sv1=KhoiTaoNodeDK();
			*sv1=*sv;
			themSVDK(dsLop2.lop[i]->lopDK,sv1);
			dsLop2.lop[i]->slSV++;
			if(dsLop2.lop[i]->slSV==dsLop2.lop[i]->svMin){
				dsLop2.lop[i]->huyLop=0;
			}
			dsLop1.n++;
			dsLop1.lop[dsLop1.n-1]=dsLop2.lop[i];
			*(chon+i)=0;
		}
	}
}


void locLTCtheoNienKhoa_HocKi_2(char namHoc1[],int hocKi1,DSLTC dsLop,DSLTC& dsLop1){
	dsLop1.n=0;
	for(int i=0;i<dsLop.n;i++){
		if((soSanh2Chuoi(namHoc1,dsLop.lop[i]->nienKhoa)==0&&hocKi1==dsLop.lop[i]->hocKi)){
				dsLop1.n++;
				dsLop1.lop[dsLop1.n-1]=dsLop.lop[i];
		}
	}
}
void thucHienHuyLTCDaDK(DSLTC &dsLop1,char maSV[],int *chon,Node*info){
	for(int i=0;i<dsLop1.n;i++){
		if(*(chon+i)==1){
			*(chon+i)=0;
			if(dsLop1.lop[i]->coDiem==1){
				inBangThongBao("-Lop mon hoc",dsLop1.lop[i]->maMH,"da hoan thanh.","-Khong the huy.","");
				delay(2000);
				inBangThongBao("","","","","");
				continue;
			}
			NodeDK*p=dsLop1.lop[i]->lopDK.head;
			while(p!=NULL){
				if(soSanh2Chuoi(p->data.maSVdk,maSV)==0){
					if(p->data.huyDangKi==1){
					inBangThongBao("-Ban da huy","lop mon hoc",dsLop1.lop[i]->maMH,"","");
					delay(2000);
					inBangThongBao("","","","","");
					break;
					}
					info->data.slDK--;
					p->data.huyDangKi=1;
					dsLop1.lop[i]->slSV-=1;
					if(dsLop1.lop[i]->slSV<dsLop1.lop[i]->svMin){
							dsLop1.lop[i]->huyLop=1;
					}
					dsLop1.lop[i]=NULL;
					break;
				}
				p=p->next;
			}
		}
	}	
	int count=0;
	for(int i=0;i<dsLop1.n;i++){
		if(dsLop1.lop[i]==NULL){
			continue;
		}
		dsLop1.lop[count]=dsLop1.lop[i];
		count++;
	}
	dsLop1.n=count;
}
void thaoTacHuyDK(DSLTC &dsLop1,char maSV[],int *chon,Node*info){
	int x= xThongBao;
	int y=yThongBao+6*khoangCachDong;
	int vt=-1;
	int xCu=-1;
	int yCu=-1;
	int xChuot=-1;
	int yChuot=-1;
	inBangThongBao("-Ban chac chan","huy dang ki", "nhung LTC","nay?","");
	inDamNutHCN(x,y,280,40,"DONG Y",10);
	y+=khoangCachDong;
	inDamNutHCN(x,y,280,40,"HUY",12);
	while(true){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			chonNutDongY_Huy(xChuot,yChuot,xCu,yCu,vt);
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				thucHienHuyLTCDaDK(dsLop1,maSV,chon,info);
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
			if(vt==1){
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
		}
		delay(100);
	}
}
void layViTriChuotTrenBangDK(int x,int y,int xSS,int ySS, int &vt){

	int chieuDai=xBang;
	int chieuRong=khoangCachDong;
	for(int i=1;i<=5;i++){
		if(x<=xSS+chieuDai/2&&x>=xSS-chieuDai/2&&y>=ySS+khoangCachDong*i&&y<=ySS+khoangCachDong*i+chieuRong){
			if(vt%10==i){
				return;
			}else{
				vt=i;
				return;
			}	
		}
	}
	vt=0;
}
void chonNienKhoa_HocKi(char namHoc[],int &hocKi){
	nhapNienKhoa(180,85,namHoc);
	while(soSanh2Chuoi(namHoc,namHocHienTai)<0){
		inBangThongBao("-Nam hoc vua chon","da ket thuc.","-Hay chon lai.","","");
		delay(2000);
		inBangThongBao("","","","","");
		namHoc[0]='\0';
		nhapNienKhoa(180,85,namHoc);
	}
	xuatNienKhoa(390,85,namHoc);
	hocKi=chonHocKi(620,85);
	if(soSanh2Chuoi(namHoc,namHocHienTai)==0){
		while(hocKi<hocKiHienTai){
			inBangThongBao("-Hoc ki vua chon","da ket thuc.","-Hay chon lai.","","");
			delay(2000);
			inBangThongBao("","","","","");
			hocKi=chonHocKi(620,85);
		}
	}
}

int tinhSoLuongTCHienTai(DSMH_AVL root,DSLTC& dsLop1,char namHoc[],int hocKi){
	int sltc=0;
	int sltcMax=21;
	for(int i=0;i<dsLop1.n;i++){
		if(soSanh2Chuoi(dsLop1.lop[i]->nienKhoa,namHoc)==0&&dsLop1.lop[i]->hocKi==hocKi){
			sltc+=timSLTC(dsLop1.lop[i]->maMH,root);
		}
	}
	string s=ghepSoTrang(sltc,sltcMax);
	string s1="SLTC hoc ki hien tai: "+s;
	inDamNutHCN(1100,85,350,40,s1.c_str(),mauBang3);
	return sltc;
}

void manHinhDangKi(DSMH_AVL root,DSLTC & dsLop,DanhSach&list){
	capNhatNamHoc_HocKi(dsLop);
	Node*info;
	DSLTC dsLop1;
	DSLTC dsLop2;
	int xChuot=0;
	int yChuot=0;
	int xCu=-1;
	int yCu=-1;
	int vt=-1;
	int hocKi=-1;
	int vtBang_1=-1;
	int vtBang_2=-1;
	int vtBang1=0;
	int vtBang2=0;
	int stt=0;
	int *chon=NULL;
	int *chon1=NULL;
	int *chon2=NULL;
	int trangThai=0;
	char namHoc[10];
	namHoc[0]='\0';
	NodeDK *sv=KhoiTaoNodeDK();
	int tongSoTrang1=0;
	int trangHienTai1=0;
	int tongSoTrang2=0;
	int trangHienTai2=0;
	int soLuongTinChi=0;
	int soLuongTinChi1=0;
	setbkcolor(1);
	cleardevice();
	settextstyle(4,0,4);
	settextjustify(1,1);
	outtextxy((getmaxx()-xLTC[1])/2+xLTC[1],42,"DANG KI LOP TIN CHI");
	inBangThongBao("Dang ki","mon hoc moi","","","");
	taoCacNutLenhDK();
	taoBangDK();
	taoBangDaDK();
	while(true){
		if(kbhit()){
			char nhiemVuChongBug=getch();
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			diChuyenChuotDK(xChuot,yChuot,xCu,yCu,vt);
			layViTriChuotTrenBangDK(xChuot,yChuot,(xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1],vtBang1);
			layViTriChuotTrenBangDK(xChuot,yChuot,(xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+7*khoangCachDong,vtBang2);
		}
		if(stt==0&&sv->data.maSVdk[0]!='\0'){
			if(trangThai==1||trangThai==2){
				stt=chonLTCDaDK(sv->data.maSVdk,chon,vtBang2,vtBang_2,trangHienTai2,dsLop1,root);
				if(stt!=0&&trangThai==1){
					trangThai=2;
				}
				if(stt!=0){
					if(*(chon+stt-1)==0){
						*(chon+stt-1)=1;
					}else{
						*(chon+stt-1)=0;
					}
					stt=0;
				}
					
			}
			if(trangThai==1||trangThai==3){
				stt=chonLTCDK(chon1,vtBang1,vtBang_1,trangHienTai1,dsLop2,root,soLuongTinChi1);
				if(stt!=0&&trangThai==1){
					trangThai=3;
				}
				if(stt!=0){
					if(*(chon1+stt-1)==0){
						*(chon1+stt-1)=1;
					}else{
						*(chon1+stt-1)=0;
					}
					stt=0;
				}
			}
			switch(trangThai){
				case 2:{
						if(!kiemTraDaChon(chon,dsLop1.n)){
							trangThai=1;
						}
						break;
					}
					case 3:{
						if(!kiemTraDaChon(chon1,dsLop2.n)){
							trangThai=1;
						}
						break;
					}
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				inDamNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str(),10);
				taoBangDaDK();
				taoBangDK();
				nhapSVDK(xCu,yCu,sv->data.maSVdk);
				inBangThongBao("-Click de chon/bo chon","lop tin chi.","-DK LTC: dang ki","-HUY DK:huy dang ki","-THOAT: quay lai.");
				info=timThongTin1SV(sv->data.maSVdk,list);
				while(info==NULL){
					inBangThongBao("-Khong tim thay","thong tin","sinh vien","-Nhap lai","ma sinh vien.");
					delay(2000);
					inBangThongBao("","","","","");
					nhapSVDK(xCu,yCu,sv->data.maSVdk);
					info=timThongTin1SV(sv->data.maSVdk,list);
					continue;
				}
				dsLop2.n=0;
				inThongTinSinhVien(info);
				locLTCDaDK(dsLop,dsLop1,info);
				if(dsLop1.n==0){
					trangThai=1;
					setbkcolor(1);
					settextstyle(4,0,2);
					settextjustify(1,1);
					outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+27*khoangCachDong/2,"0/0");
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
					clearmouseclick(WM_LBUTTONDOWN);
					continue;
				}
				chon2=chon;
				chon=new int[dsLop1.n];
				if(chon2!=NULL)
					delete[]chon2;
				for(int i=0;i<dsLop1.n;i++){
					*(chon+i)=0;
				}
				if(dsLop1.n%5==0){
					tongSoTrang2=dsLop1.n/5;
				}else{
					tongSoTrang2=dsLop1.n/5+1;
				}
				trangHienTai2=1;
				xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
				trangThai=1;
				taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==1&&sv->data.maSVdk[0]!='\0'&&trangThai!=2){
				if(trangThai==3){
					thucHienDK(chon1,dsLop2,dsLop1,sv,info);
					soLuongTinChi=tinhSoLuongTCHienTai(root,dsLop1,namHoc,hocKi);
					soLuongTinChi1=soLuongTinChi;
					trangThai=1;
					if(dsLop1.n%5==0){
						tongSoTrang2=dsLop1.n/5;
					}else{
						tongSoTrang2=dsLop1.n/5+1;
					}
					inBangThongBao("-Click de chon/bo chon","lop tin chi.","-DK LTC: dang ki","-HUY DK:huy dang ki","-THOAT: quay lai.");
					trangHienTai2=tongSoTrang2;
					taoBangDK();
					xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
					chon2=chon;
					chon=new int[dsLop1.n];
					if(chon2!=NULL)
						delete[]chon2;
					for(int i=0;i<dsLop1.n;i++){
						*(chon+i)=0;
					}
					taoBangDaDK();
					xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
					setfillstyle(1, 1);
					clearmouseclick(WM_LBUTTONDOWN);
					continue;
				}
				inDamNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str(),10);
				chonNienKhoa_HocKi(namHoc,hocKi);
				soLuongTinChi=tinhSoLuongTCHienTai(root,dsLop1,namHoc,hocKi);
				soLuongTinChi1=soLuongTinChi;
				locLTCtheoNienKhoa_HocKi_2(namHoc,hocKi,dsLop,dsLop2);
				if(dsLop2.n==0){
					setbkcolor(1);
					settextstyle(4,0,2);
					settextjustify(1,1);
					outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+13*khoangCachDong/2,"0/0");
					taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
					clearmouseclick(WM_LBUTTONDOWN);
					continue;
				}
				chon2=chon1;
				chon1=new int[dsLop2.n];
				if(chon2!=NULL)
					delete[]chon2;
				for(int i=0;i<dsLop2.n;i++){
					*(chon1+i)=0;
				}
				if(dsLop2.n%5==0){
					tongSoTrang1=dsLop2.n/5;
				}else{
					tongSoTrang1=dsLop2.n/5+1;
				}
				trangHienTai1=1;
				taoBangDK();
				xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
				taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==2&&trangThai==2){
				inDamNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str(),10);
				clearmouseclick(WM_LBUTTONDOWN);
				thaoTacHuyDK(dsLop1,sv->data.maSVdk,chon,info);
				if(namHoc[0]!='\0'){
					soLuongTinChi=tinhSoLuongTCHienTai(root,dsLop1,namHoc,hocKi);
					soLuongTinChi1=soLuongTinChi;
				}
				xoaNutDongY_Huy();
				chon2=chon;
				chon=new int[dsLop1.n];
				if(chon2!=NULL)
					delete[]chon2;
				for(int i=0;i<dsLop1.n;i++){
					*(chon+i)=0;
				}
				if(dsLop1.n%5==0){
					tongSoTrang2=dsLop1.n/5;
				}else{
					tongSoTrang2=dsLop1.n/5+1;
				}
				if(trangHienTai2>tongSoTrang2){
					trangHienTai2=tongSoTrang2;
				}
				taoBangDaDK();
				xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
				if(dsLop2.n!=0){
					taoBangDK();
					xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
				}
				trangThai=1;
				taoNutHCN(xCu,yCu,200,40,tenNutDK[vt].c_str());
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==3){
				switch(trangThai){
				case 0:{if(sv->data.maSVdk[0]!='\0'){
					delete []chon;
					delete []chon1;
					delete[]chon2;}
					ghiFileLTC(dsLop);
					GHI_FILE_DSSV(list);
					clearmouseclick(WM_LBUTTONDOWN);
					return;
				}
				case 1:{	// Bo chon sinh vien , chon lai sinh vien moi
					setfillstyle(1, 1);
					bar(xLTC[1]-5,5,xLTC[9]+5,yLTC[1]-5);
					taoBangDaDK();
					taoBangDK();
					dsLop1.n=0;
					dsLop2.n=0;
					trangThai=0;
					clearmouseclick(WM_LBUTTONDOWN);
					inBangThongBao("Dang ki","mon hoc moi","","","");
					break;
				}
				case 2:{	// bo chon lop da dang ki , chon lai lop moi
					trangThai=1;
					for(int i=0;i<dsLop1.n;i++){
						*(chon+i)=0;
					}
					taoBangDaDK();
					xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
					//inBangThongBao("-Click de","chon/bo chon","lop tin chi.","-Click THOAT","de quay lai.");
					inBangThongBao("-Click de chon/bo chon","lop tin chi.","-DK LTC: dang ki","-HUY DK:huy dang ki","-THOAT: quay lai.");
					clearmouseclick(WM_LBUTTONDOWN);
					break;
				}
				case 3:{	// huy bo buoc dang ki tro ve buoc xem thong tin 
					setfillstyle(1, 1);
					trangThai=1;
					for(int i=0;i<dsLop2.n;i++){
						*(chon1+i)=0;
					}
					taoBangDK();
					xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
					inBangThongBao("-Click de chon/bo chon","lop tin chi.","-DK LTC: dang ki","-HUY DK:huy dang ki","-THOAT: quay lai.");
					clearmouseclick(WM_LBUTTONDOWN);
					break;
				}
				
				}
				clearmouseclick(WM_LBUTTONDOWN);//8 9 10 11 12
				continue;
			}
			if(vt==4&&trangHienTai1>1){
				vtBang_1=-1;
				trangHienTai1--;
				taoBangDK();
				xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==5&&trangHienTai1<tongSoTrang1){
				vtBang_1=-1;
				trangHienTai1++;
				taoBangDK();
				xuatLTCDK(root,dsLop2,trangHienTai1,tongSoTrang1,chon1);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==6&&trangHienTai2>1){
				vtBang_2=-1;
				trangHienTai2--;
				taoBangDaDK();
				xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==7&&trangHienTai2<tongSoTrang2){
				vtBang_2=-1;
				trangHienTai2++;
				taoBangDaDK();
				xuatLTCDaDK(root,dsLop1,trangHienTai2,tongSoTrang2,chon,sv->data.maSVdk);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(100);
	}
}
//===================================================================================
//===================================================================================
//===================================================================================

void chuyenFloatSangChar(float n,char s[]){
	int count =0;
	int i=0;
	while(count<2){
		n=n*10;
		count++;
	}
	int n1=(int)n;
	do {       /* generate digits in reverse order */
	if(i==count){
		s[i++]='.';
	}
         s[i++] = n1 % 10 + '0';   /* get next digit */
     } while (( n1 /= 10) > 0);
     s[i] = '\0';
    daoChieu(s);
}
void nhapMaLopTK(int x1, int y1,int max, char s[]) {
	int i = 0;
	int xNhap = x1+130;
	setfillstyle(1, 15);
	setbkcolor(15);
	settextjustify(0,1);
	settextstyle(10, 0, 2);
	bar(x1 + 120, y1 - 30, x1 + 300, y1 + 10);
	y1-=10;
	outtextxy(xNhap, y1, "-ML:");
	xNhap += textwidth("-ML:");
	while (true) {
		settextjustify(0,1);
		settextstyle(2, 0, 5);
		if (kbhit()) {
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
			//	kt=0;
				return;
			}
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
			//	kt=6;
				break;
			}
			if (c[0] == 8 && i > 0) {
				xNhap-=textwidth(&s[i-1]);
				s[i-1]='\0';
                i--;
                outtextxy(xNhap, y1 ,"   ");
            }
			if(i==max){
				continue;
			}
			
			if (c[0] >= '0' && c[0] <= '9') {
				s[i] = c[0];
				s[i+1]='\0';
				
				outtextxy(xNhap, y1, &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
			if (c[0] =='-' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(xNhap, y1 , &c[0]);
				xNhap+=textwidth(c);
				i++;
			}
            delay(1);
		}
		else {
			settextstyle(4, 0, 1);
			outtextxy(xNhap+3, y1 , "|");
			delay(500);
			outtextxy(xNhap+3, y1 , " ");
			delay(200);
		}
	}
	setfillstyle(1, 1);
	bar(x1 + 120, y1 - 20, x1 + 300, y1 + 20);
}
void taoCacNutLenhTK(){
	int y= yLTC[1]/2;
	for(int i=0;i<4;i++){
		taoNutHCN((xLTC[1]-xLTC[0])/2,y,200,40,tenNutTK[i].c_str());
		y+=khoangCachNut;
	}
}
void taoBangTK(){
	int y=yLTC[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=11){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[1],y,xLTC[9],y+khoangCachDong);
		line(xLTC[1],y,xLTC[9],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[1],y,xLTC[9],y);
	setbkcolor(mauBang1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],yLTC[1]+20,tenDeMucTKTB[0].c_str());
	outtextxy((xLTC[4]-xLTC[2])/2+xLTC[2],yLTC[1]+20,tenDeMucTKTB[1].c_str());
	outtextxy((xLTC[5]-xLTC[4])/2+xLTC[4],yLTC[1]+20,tenDeMucTKTB[2].c_str());
	outtextxy((xLTC[7]-xLTC[5])/2+xLTC[5],yLTC[1]+20,tenDeMucTKTB[3].c_str());
	outtextxy((xLTC[9]-xLTC[7])/2+xLTC[7],yLTC[1]+20,tenDeMucTKTB[4].c_str());
	line(xLTC[1],yLTC[1],xLTC[1],y);
	line(xLTC[2],yLTC[1],xLTC[2],y);
	line(xLTC[4],yLTC[1],xLTC[4],y);
	line(xLTC[5],yLTC[1],xLTC[5],y);
	line(xLTC[7],yLTC[1],xLTC[7],y);
	line(xLTC[9],yLTC[1],xLTC[9],y);
	
	y+=khoangCachDong;
	taoNutHCN(xLTC[1]+50,y-10,30,30,tenNutTK[4].c_str());
	taoNutHCN(xLTC[9]-50,y-10,30,30,tenNutTK[5].c_str());
	setbkcolor(1);
	setfillstyle(1,1);
	y-=10;
	bar(xLTC[2],y-25,xLTC[8],y+5);
}
void diChuyenChuotTK(int x,int y,int& xCu,int &yCu,int &vt){
	int xSS=(xLTC[1]-xLTC[0])/2;
	int ySS= yLTC[1]/2;
	for(int i=0;i<4;i++){
		if(x<=xSS+100&&x>=xSS-100&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xSS,ySS+khoangCachNut*i,200,40,tenNutTK[i].c_str(),4);
				if(vt!=-1){
					if(vt<4){
						taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
					} 
					if(vt>=4&&vt<=5){
						taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
					}
				}
				xCu=xSS;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
	}
	if(x<=xLTC[1]+50+15&&x>=xLTC[1]+50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==4){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[4].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=4;
		return;	
	}
	if(x<=xLTC[9]-50+15&&x>=xLTC[9]-50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==5){
			return;
			}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[5].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=5;
		return;		
	}
	if(vt!=-1){
		if(vt<4){
			taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
		} 
		if(vt>=4&&vt<=5){
			taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
			}
		vt=-1;
	}
}
void xuat1SVTKTB(SinhVien* x,float diem,int y, int stt,int mau){
	char s[10];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(xLTC[1]+5,y-15,xLTC[2]-5,y+15);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
	bar(xLTC[2]+5,y-15,xLTC[4]-5,y+15);
	outtextxy((xLTC[4]-xLTC[2])/2+xLTC[2],y,x->MaSV.c_str());
	bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
	outtextxy((xLTC[5]-xLTC[4])/2+xLTC[4],y,x->Ho.c_str());
	bar(xLTC[5]+5,y-15,xLTC[7]-5,y+15);
	outtextxy((xLTC[7]-xLTC[5])/2+xLTC[5],y,x->Ten.c_str());
	chuyenFloatSangChar(diem,s);
	bar(xLTC[7]+5,y-15,xLTC[9]-5,y+15);
	outtextxy((xLTC[9]-xLTC[7])/2+xLTC[7],y,s);
}



void xuatTKTB(TKL& lop,int trangHienTai,int tongSoTrang){
	string s1=ghepSoTrang(trangHienTai,tongSoTrang);
	setbkcolor(1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]+12*khoangCachDong-10,s1.c_str());
	int stt=(trangHienTai-1)*10+1;
	int y=yLTC[1]+khoangCachDong+khoangCachDong/2;
	int dem=1;
	while(dem<=10&&stt<=lop.n){
			float diemTB=0;
			if(*lop.diem[stt-1]!=0){
				diemTB=*lop.diem[stt-1]/(float)*lop.slTC[stt-1];
			}
		if(dem%2==0){
			xuat1SVTKTB(lop.sv[stt-1],diemTB,y,stt,mauBang1);
		}else{
			xuat1SVTKTB(lop.sv[stt-1],diemTB,y,stt,mauBang2);
		}	
		y+=khoangCachDong;
		stt++;
		dem++;
	}
}
void themSVVaoLopTK(TKL&lop,SinhVien& sv1){
	lop.n++;
	lop.diem[lop.n-1]=new float;
	lop.slTC[lop.n-1]=new int;
	*lop.diem[lop.n-1]=0;
	*lop.slTC[lop.n-1]=0;
	lop.sv[lop.n-1]=&sv1;
}

void timSVTheoMaLopTK(char maLop[],TKL &lop,DanhSach& list){
	char temp[50]; 
	Node*t = list.head;
	if(t==NULL){
		return;
	}
	while(t!=NULL)
		{
			chuyen(t->data.MaLop , temp);
			if (strcmp(maLop ,temp) == 0&&t->data.MaSV!=" ")
			{
				themSVVaoLopTK(lop,t->data);
			}
			t=t->next;
		}
}


int timSLTC(char maMH[],DSMH_AVL root){
	DSMH_AVL p=root;
	if(p==NULL){
			return 0;
		}
	while(soSanh2Chuoi(maMH,p->monHoc.maMH)!=0){
		if(p==NULL){
			return 0;
		}
		if(soSanh2Chuoi(maMH,p->monHoc.maMH)<0){
			p=p->left;
			continue;
		}
		if(soSanh2Chuoi(maMH,p->monHoc.maMH)>0){
			p=p->right;
			continue;
		}
	} 
	return	( p->monHoc.STCLT+p->monHoc.STCTH);
}

void tinhDiemTB(DSMH_AVL root,DSLTC & dsLop,TKL &lop){
	for(int i=0;i<lop.n;i++){
		for(int j=0;j<dsLop.n;j++){
			if(dsLop.lop[j]->coDiem==1){
				int sltc1=0;
				NodeDK*p=dsLop.lop[j]->lopDK.head;
				if(p==NULL){
					break;
				}
				while(p!=NULL){
					char temp[50];
					chuyen(lop.sv[i]->MaSV , temp);
					if(soSanh2Chuoi(p->data.maSVdk,temp)==0){
						sltc1=timSLTC(dsLop.lop[j]->maMH,root);
						*lop.diem[i]=*lop.diem[i]+p->data.diemSV*(float)sltc1;
						*lop.slTC[i]+=sltc1;
						break;
					}
					p=p->next;
				}
			}
		}	
	}
}
//=======================================
void taoBangTK_MaMH(){
	int y=yLTC[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=11){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[5],y,xLTC[9],y+khoangCachDong);
		line(xLTC[5],y,xLTC[9],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[5],y,xLTC[9],y);
	line(xLTC[5],yLTC[1],xLTC[5],y);
	line(xLTC[6],yLTC[1],xLTC[6],y);
	line(xLTC[7],yLTC[1],xLTC[7],y);
	line(xLTC[8],yLTC[1],xLTC[8],y);
	line(xLTC[9],yLTC[1],xLTC[9],y);
}
void taoBangTK_2(){
	int y=yLTC[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=11){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(xLTC[1],y,xLTC[5],y+khoangCachDong);
		line(xLTC[1],y,xLTC[5],y);
		y+=khoangCachDong;
		dem++;
	}
	line(xLTC[1],y,xLTC[9],y);
	setbkcolor(mauBang1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],yLTC[1]+20,tenDeMucTKTB[0].c_str());
	outtextxy((xLTC[4]-xLTC[2])/2+xLTC[2],yLTC[1]+20,tenDeMucTKTB[1].c_str());
	outtextxy((xLTC[5]-xLTC[4])/2+xLTC[4],yLTC[1]+20,(tenDeMucTKTB[2]+' '+tenDeMucTKTB[3]).c_str());
	line(xLTC[1],yLTC[1],xLTC[1],y);
	line(xLTC[2],yLTC[1],xLTC[2],y);
	line(xLTC[4],yLTC[1],xLTC[4],y);
	line(xLTC[5],yLTC[1],xLTC[5],y);
	line(xLTC[7],yLTC[1],xLTC[7],y);
	line(xLTC[9],yLTC[1],xLTC[9],y);
	taoBangTK_MaMH();
	y+=khoangCachDong;
	setbkcolor(1);
	setfillstyle(1,1);
	y-=10;
	bar(xLTC[2],y-25,xLTC[8],y+5);
	y+=10;
	taoNutHCN(xLTC[5]+50,y-10,30,30,tenNutTK[4].c_str());
	taoNutHCN(xLTC[9]-50,y-10,30,30,tenNutTK[5].c_str());
	taoNutHCN(xLTC[1]+50,y-10,30,30,tenNutTK[6].c_str());
	taoNutHCN(xLTC[5]-50,y-10,30,30,tenNutTK[7].c_str());
}
void diChuyenChuotTK_2(int x,int y,int& xCu,int &yCu,int &vt){
	int xSS=(xLTC[1]-xLTC[0])/2;
	int ySS= yLTC[1]/2;
	for(int i=0;i<4;i++){
		if(x<=xSS+100&&x>=xSS-100&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xSS,ySS+khoangCachNut*i,200,40,tenNutTK[i].c_str(),4);
				if(vt!=-1){
					if(vt<4){
						taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
					} 
					if(vt>=4&&vt<=7){
						taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
					}
				}
				xCu=xSS;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
	}
	if(x<=xLTC[5]+50+15&&x>=xLTC[5]+50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==4){
			return;
			}
		inDamNutHCN(xLTC[5]+50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[4].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=7){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[5]+50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=4;
		return;	
	}
	if(x<=xLTC[9]-50+15&&x>=xLTC[9]-50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==5){
			return;
			}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[5].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=5;
		return;		
	}
	if(x<=xLTC[1]+50+15&&x>=xLTC[1]+50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==6){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[6].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=7){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=6;
		return;	
	}
	if(x<=xLTC[5]-50+15&&x>=xLTC[5]-50-15&&y>=yLTC[1]+12*khoangCachDong-35&&y<=yLTC[1]+12*khoangCachDong-5){
		if(vt==7){
			return;
			}
		inDamNutHCN(xLTC[5]-50,yLTC[1]+12*khoangCachDong-10,30,30,tenNutTK[7].c_str(),4);
		if(vt!=-1){
			if(vt<4){
					taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
				} 
			if(vt>=4&&vt<=5){
				taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
				}
		}
		xCu=xLTC[5]-50;
		yCu=yLTC[1]+12*khoangCachDong-10;
		vt=7;
		return;		
	}
	if(vt!=-1){
		if(vt<4){
			taoNutHCN(xCu,yCu,200,40,tenNutTK[vt].c_str());
		} 
		if(vt>=4&&vt<=7){
			taoNutHCN(xCu,yCu,30,30,tenNutTK[vt].c_str());
			}
		vt=-1;
	}
}

void duyetLopCoDiemVaSV(DSLTC dsLop,DSLTC &dsLop1,SinhVien* sv[],int n){
	for(int i=0;i<dsLop.n;i++){
		if(dsLop.lop[i]->coDiem==1){
			bool kt=0;
			NodeDK *q=dsLop.lop[i]->lopDK.head;
			if(q==NULL){
				continue;
			}
			while(q!=NULL){
				for(int j=0;j<n;j++){
					char temp[50];
					chuyen(sv[j]->MaSV,temp);
					if(soSanh2Chuoi(temp,q->data.maSVdk)==0){
						dsLop1.n++;
						dsLop1.lop[dsLop1.n-1]=dsLop.lop[i];
						kt=1;
						break;
					}
				}
				if(kt){
					break;
				}else{
					q=q->next;
				}
			}
		}
	}
}
int demSoLopKhongTrung(DSLTC dsLop1,int * kiemTra){
	int n=0;
	for(int i=0;i<dsLop1.n;i++){
		bool kt=0;
		for(int j=i-1;j>=0;j--){
			if(soSanh2Chuoi(dsLop1.lop[i]->maMH,dsLop1.lop[j]->maMH)==0){
				kt=1;
				*(kiemTra+i)=1;
				break;
			}
		}
		if(!kt){
			n++;
		}
	}
	return n;
}
float timDiemTK(char maSV[],LTC lop1){
	NodeDK *p=lop1.lopDK.head;
	if(p==NULL){
		return -1;
	}
	while(p!=NULL){
		if(soSanh2Chuoi(p->data.maSVdk,maSV)==0){
			return p->data.diemSV;
		}
		p=p->next;
	}
	return -1;
}

void timDiemCua1SV(char maSV[],float diem[],DSLTC dsLop1,int *kiemTra){
	int t=0;
	float max=-1;
	for(int i=0;i<dsLop1.n;i++){
		if(*(kiemTra+i)==0){
			max=timDiemTK(maSV,*dsLop1.lop[i]);
			float max1=-1;
			for(int j=i+1;j<dsLop1.n;j++){
				if(soSanh2Chuoi(dsLop1.lop[i]->maMH,dsLop1.lop[j]->maMH)==0){
					max1=timDiemTK(maSV,*dsLop1.lop[j]);
				}
				if(max1>max){
					max=max1;
				}
			}
			diem[t]=max;
			t++;
		}
	}
}
void xuatDiem1SV(float diem[],int mau,int y,int stt2,int& n){
//	setbkcolor(mauBang1);
//	settextstyle(0,0,2);
//	settextjustify(1,1);
	char s[5];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	int count=0;
	while(count<4&&stt2<=n){
		if(diem[stt2-1]==-1){
			bar(xLTC[5+count]+3,y-17,xLTC[6+count]-3,y+17);
			outtextxy((xLTC[6+count]-xLTC[5+count])/2+xLTC[5+count],y,"-");
			count++;
			stt2++;
			continue;
		}
		chuyenFloatSangChar(diem[stt2-1],s);
		bar(xLTC[5+count]+3,y-17,xLTC[6+count]-3,y+17);
		outtextxy((xLTC[6+count]-xLTC[5+count])/2+xLTC[5+count],y,s);
		count++;
		stt2++;
	}
}
void xuatDiem(DSLTC &dsLop1,int *kiemTra,float bangDiem[][100],int trangHienTai1,int trangHienTai2,int tongSoTrang2,int n,int &soMon){
	int count =0;
	int stt1=(trangHienTai1-1)*10+1;
	int stt2=(trangHienTai2-1)*4+1;
	int y=yLTC[1]+khoangCachDong/2;
	int i;
	string s1=ghepSoTrang(trangHienTai2,tongSoTrang2);
	setbkcolor(1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[9]-xLTC[5])/2+xLTC[5],yLTC[1]+12*khoangCachDong-10,s1.c_str());
	for(i=0;i<dsLop1.n;i++){
		if(*(kiemTra+i)==0){
			count ++;
		}
		if(count == stt2){
			count =0;
			break;
		}
	}
	setbkcolor(mauBang1);
	setfillstyle(1,mauBang1);
	settextstyle(2,0,5);
	settextjustify(1,1);
	for(i;i<dsLop1.n;i++){
		if(*(kiemTra+i)==0){
			bar(xLTC[5+count]+3,y-17,xLTC[6+count]-3,y+17);
			outtextxy((xLTC[6+count]-xLTC[5+count])/2+xLTC[5+count],y,dsLop1.lop[i]->maMH);
			count ++;
			if(count==4){
				break;
			}
		}
	}
	y+=khoangCachDong;
	int dem=1;
	while(dem<=10&&stt1<=n){
		if(dem%2==0){
			xuatDiem1SV(bangDiem[stt1-1],mauBang1,y,stt2,soMon);
		}else{
		xuatDiem1SV(bangDiem[stt1-1],mauBang2,y,stt2,soMon);
		}
		y+=khoangCachDong;
		stt1++;
		dem++;
	}
}
void xuat1SVTKTK(SinhVien* x,int y, int stt,int mau){
	char s[10];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(xLTC[1]+5,y-15,xLTC[2]-5,y+15);
	outtextxy((xLTC[2]-xLTC[1])/2+xLTC[1],y,s);
	bar(xLTC[2]+5,y-15,xLTC[4]-5,y+15);
	outtextxy((xLTC[4]-xLTC[2])/2+xLTC[2],y,x->MaSV.c_str());
	string hoTen=x->Ho+' '+x->Ten;
	settextjustify(0,1);
	bar(xLTC[4]+5,y-15,xLTC[5]-5,y+15);
	outtextxy(xLTC[4]+20,y,hoTen.c_str());
	settextjustify(1,1);
}
void xuatTKTK(TKL &lop,DSLTC &dsLop1,int *kiemTra,float bangDiem[][100],int &soMon,int trangHienTai1,int tongSoTrang1,int trangHienTai2,int tongSoTrang2)
{
	string s1=ghepSoTrang(trangHienTai1,tongSoTrang1);
	setbkcolor(1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy((xLTC[5]-xLTC[1])/2+xLTC[1],yLTC[1]+12*khoangCachDong-10,s1.c_str());
	int stt1=(trangHienTai1-1)*10+1;
	int y=yLTC[1]+khoangCachDong+khoangCachDong/2;
	int dem=1;
	while(dem<=10&&stt1<=lop.n){
		if(dem%2==0){
			xuat1SVTKTK(lop.sv[stt1-1],y,stt1,mauBang1);
		}else{
		xuat1SVTKTK(lop.sv[stt1-1],y,stt1,mauBang2);
		}
		y+=khoangCachDong;
		stt1++;
		dem++;
	}
	xuatDiem(dsLop1,kiemTra,bangDiem,trangHienTai1,trangHienTai2,tongSoTrang2,lop.n,soMon);
}

void manHinhThongKe(DSMH_AVL root,DSLTC & dsLop,DanhSach& list){
	TKL lop;
	DSLTC dsLop1;
	float bangDiem[100][100];
	int soMon=0;
	int *kiemTra=NULL;	
	int *kiemTra1=NULL;
	int xChuot=0;
	int yChuot=0;
	int xCu=-1;
	int yCu=-1;
	int vt=-1;
	int tongSoTrang1=0;
	int trangHienTai1=0;
	int tongSoTrang2=0;
	int trangHienTai2=0;
	bool diChuot=0;
	char maLop[20];
	char s[10];
	maLop[0]='\0';
	setbkcolor(1);
	cleardevice();
	settextstyle(4,0,4);
	settextjustify(1,1);
	outtextxy((getmaxx()-xLTC[1])/2+xLTC[1],42,"THONG KE");
	taoCacNutLenhTK();
	inBangThongBao("-Ban dang xem","thong ke.","-Click MA LOP","de nhap","ma lop.");
	while(true){
		if(kbhit()){
			char nhiemVuChongBug=getch();
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			if(diChuot==0){
				diChuyenChuotTK(xChuot,yChuot,xCu,yCu,vt);
			}else{
				diChuyenChuotTK_2(xChuot,yChuot,xCu,yCu,vt);
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				nhapMaLopTK(xLTC[1]/2,yLTC[1]/2,15,maLop);
				if(maLop[0]!='\0'){
					string lop="Lop: ";
					for(int i=0;i<strlen(maLop);i++){
						lop+=maLop[i];
					}
					inDamNutHCN((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]-20,300,40,lop.c_str(),1);
				}
				//Xu ly diem trung binh
				timSVTheoMaLopTK(maLop,lop,list);
				while(lop.n==0){
					inBangThongBao("-Lop",maLop,"khong co","sinh vien.","");
					delay(2000);
					inBangThongBao("","","","","");
					nhapMaLopTK(xLTC[1]/2,yLTC[1]/2,15,maLop);
					if(maLop[0]!='\0'){
						string lop="Lop: ";
						for(int i=0;i<strlen(maLop);i++){
							lop+=maLop[i];
						}
						inDamNutHCN((xLTC[9]-xLTC[1])/2+xLTC[1],yLTC[1]-20,300,40,lop.c_str(),1);
					}
					timSVTheoMaLopTK(maLop,lop,list);
					clearmouseclick(WM_LBUTTONDOWN);
					continue;
				}
				if(lop.n%10==0){
					tongSoTrang1=lop.n/10;
				}else{
					tongSoTrang1=lop.n/10+1;
				}
				trangHienTai1=1;
				// Xu ly diem tong ket
				duyetLopCoDiemVaSV(dsLop,dsLop1,lop.sv,lop.n);
				kiemTra1=kiemTra;
				kiemTra=new int[dsLop1.n];
				if(kiemTra1!=NULL){
					delete [] kiemTra;
				}
				for(int i=0;i<dsLop1.n;i++){
					*(kiemTra+i)=0;
				}
				soMon=demSoLopKhongTrung(dsLop1,kiemTra);
				for(int i=0;i<lop.n;i++){
					for(int j=0;j<soMon;j++){
						bangDiem[i][j]=-1;
					}
				}
				for(int i=0;i<lop.n;i++){
					char temp[16];
					chuyen(lop.sv[i]->MaSV,temp);
					timDiemCua1SV(temp,bangDiem[i],dsLop1,kiemTra);
				}
				if(soMon%4==0){
					tongSoTrang2=soMon/4;
				}else{
					tongSoTrang2=soMon/4+1;
				}
				trangHienTai2=1;
				tinhDiemTB(root,dsLop,lop);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==1&&maLop[0]!='\0'){
				inBangThongBao("-Ban dang xem","bang diem","trung binh","ket thuc","khoa hoc.");
				diChuot=0;
				taoBangTK();
				xuatTKTB(lop,trangHienTai1,tongSoTrang1);	
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==2&&maLop[0]!='\0'){
				inBangThongBao("-Ban dang xem","bang diem","tong ket cac mon","cua sinh vien.","");
				diChuot=1;
				taoBangTK_2();
				xuatTKTK(lop,dsLop1,kiemTra,bangDiem,soMon,trangHienTai1,tongSoTrang1,trangHienTai2,tongSoTrang2);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==3){
				xoaBoNhoTKL(lop);
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
			if(vt==4){
				if(diChuot==0){
					if(trangHienTai1>1){
						trangHienTai1--;
						taoBangTK();
					xuatTKTB(lop,trangHienTai1,tongSoTrang1);
					}	
				}else{
					if(trangHienTai2>1){
						trangHienTai2--;
						taoBangTK_MaMH();
						xuatDiem(dsLop1,kiemTra,bangDiem,trangHienTai1,trangHienTai2,tongSoTrang2,lop.n,soMon);
					}
				}
				clearmouseclick(WM_LBUTTONDOWN);
					continue;
			}
			if(vt==5){
				if(diChuot==0){
					if(trangHienTai1<tongSoTrang1){
						trangHienTai1++;
						taoBangTK();
					xuatTKTB(lop,trangHienTai1,tongSoTrang1);
					}
				}else{
					if(trangHienTai2<tongSoTrang2){
						trangHienTai2++;
						taoBangTK_MaMH();
						xuatDiem(dsLop1,kiemTra,bangDiem,trangHienTai1,trangHienTai2,tongSoTrang2,lop.n,soMon);
					}
				}
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==6){
				if(trangHienTai1>1){
					trangHienTai1--;
					taoBangTK_2();
					xuatTKTK(lop,dsLop1,kiemTra,bangDiem,soMon,trangHienTai1,tongSoTrang1,trangHienTai2,tongSoTrang2);
				}
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==7){
				if(trangHienTai1<tongSoTrang1){
					trangHienTai1++;
					taoBangTK_2();
					xuatTKTK(lop,dsLop1,kiemTra,bangDiem,soMon,trangHienTai1,tongSoTrang1,trangHienTai2,tongSoTrang2);
				}
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
		}
		delay(100);
	}
}
////===============================
////MAN HINH NHAP DIEM
void xoaBangNhapDiem(int ytemp)
{
	for(int i = 1 ; i <= 10 ; i++)// xoa Bang Danh Sach
	{
								
		if (i % 2 == 0 )
			{
				setfillstyle(1,9);
				setbkcolor(9);
				bar (DKA[1] + 1,ytemp +(i - 1)*40 + 1 ,DKA[6] - 1, ytemp + 40*i- 1);
				
			}
		else 
			{
				setfillstyle(1,15);
    			setbkcolor(15);
				bar (DKA[1] + 1,ytemp +(i - 1)*40 + 1 ,DKA[6] - 1, ytemp + 40*i- 1);	
			}
		}
	for(int i=1;i<7;i++){
		line(DKA[i],DKB[1],DKA[i],DKB[2]-127);
	}
	int DKB1=DKB[1];
	while(DKB1<=DKB[2]-100+1){
		line(DKA[1],DKB1,DKA[6],DKB1);
		DKB1+=40;
	}
}
void giaoDienNhapDiem(int xTrangT , int xTrangS,int yTrang, int x1 ,int y1, int kc )
{
	settextjustify(0,2);
  	settextstyle(10,0,2);
    setfillstyle(1,15);
    setbkcolor(15);
	bar(xTrangT-100,yTrang-20,xTrangT +100, yTrang +20);
	outtextxy(((xTrangT)*2-textwidth("TRANG TRUOC"))/2,yTrang-10,"TRANG TRUOC");
	bar(xTrangS-100,yTrang-20,xTrangS +100, yTrang +20);
	outtextxy(((xTrangS)*2-textwidth("TRANG SAU"))/2,yTrang-10,"TRANG SAU");
	bar(x1-100,y1-kc*2-20,x1+100,y1-kc*2+20);
	outtextxy((x1*2-textwidth("LOP TIN CHI"))/2,y1-kc*2-10,"LOP TIN CHI");
	bar(x1-100,y1-kc-20,x1+100,y1-kc+20);
	outtextxy((x1*2-textwidth("XEM DIEM"))/2,y1-kc-10,"XEM DIEM");
    bar(x1-100,y1-20,x1+100,y1+20);
    outtextxy((x1*2-textwidth("NHAP/SUA DIEM"))/2,y1-10,"NHAP/SUA DIEM");
	y1+=kc;
	bar(x1-100,y1-20,x1+100,y1+20);
	outtextxy((x1*2-textwidth("DSSV DANG KI"))/2,y1-10,"DSSV DANG KI");
	y1+=kc;
	bar(x1-100,y1-20,x1+100,y1+20);
	outtextxy((x1*2-textwidth("THOAT"))/2,y1-10,"THOAT");
}
void inHangTieuDeNhapDiem(int ytemp1,const char *s1 ,const char *s2,const char *s3,const char *s4,const char *s5)
{
	settextjustify(0,2);
	setfillstyle(1,9);
	setbkcolor(9);
	bar (DKA[1] + 1,ytemp1 + 1 ,DKA[2] - 1, ytemp1 + 40- 1);
	bar (DKA[2] + 1,ytemp1 + 1 ,DKA[3] - 1, ytemp1 + 40- 1);
	bar (DKA[3] + 1,ytemp1 + 1 ,DKA[4] - 1, ytemp1 + 40- 1);
	bar (DKA[4] + 1,ytemp1 + 1 ,DKA[5] - 1, ytemp1 + 40- 1);
	bar (DKA[5] + 1,ytemp1 + 1 ,DKA[6] - 1, ytemp1 + 40- 1);
	settextstyle(10,0,2);
	setbkcolor(9);
	outtextxy((DKA[2]-DKA[1] - textwidth(s1))/2 + DKA[1],120 + 8,s1);
	outtextxy((DKA[3]-DKA[2] - textwidth(s2))/2 + DKA[2],120 + 8,s2);
	outtextxy((DKA[4]-DKA[3] - textwidth(s3))/2 + DKA[3],120 + 8,s3);
	outtextxy((DKA[5]-DKA[4] - textwidth(s4))/2 + DKA[4],120 + 8,s4);
	outtextxy((DKA[6]-DKA[5] - textwidth(s5))/2 + DKA[5],120 + 8,s5);
}
void thaoTacNhapDiem(float &diem ,int x,int y)
{
	settextjustify(0,2);
	settextstyle(2, 0, 5);
	setbkcolor (10);
	int i = 0;
	char temp [6];
	if(diem != -1)
	{
		chuyenFloatSangChar( diem , temp);
		outtextxy(x,y,temp);
	}
	
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
 	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		inBangThongBao("Nhan ESC De Huy Qua","Trinh Nhap/Sua Diem.","Nhan ENTER De Luu Diem","(0,0 <= Diem <= 10,0)","");
		settextjustify(0,2);
		settextstyle(2, 0, 5);
		setfillstyle(1,10);
		setbkcolor(10);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				break;
			}
			if (c[0] == 13)
			{
				temp[i] = '\0';
				if (i == 0)
				{
					diem = -1 ;
					break ;
				}
				if (temp[i-1] != '.')
				{
					diem = atof(temp);
					if (diem >= 0 && diem <= 10)
					{
						break ;
					}
					else
					{
						inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
						delay(2000);
						settextjustify(0,2);
						setbkcolor(10);
						continue ;
					}
				}
				else 
				{
					inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
					delay(2000);
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
			}
			
			if (c[0] == 8 && i > 0) {
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"     ");
            }
			if(i==5)
			{
				continue;
			}
			if (c[0] == '.' && i >0)
			{
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if ((c[0] >= '0' && c[0] <= '9' )) {		
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			
		} else{
			settextstyle(2, 0, 5);
			outtextxy(x, y , "|");
			delay(500);
			outtextxy(x, y , "  ");
			delay(200);
		}
	}
}
void keBangDiem()
{
	int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ;
	setfillstyle(1,1);
	setbkcolor(1);
	bar(xLTC[1] - 2,yLTC[1] -2,xLTC[9],yLTC[1]*13);
	setcolor(0);
	setlinestyle(0,0,2);
	for(int i=1;i<7;i++){
		line(DKA[i],DKB[1],DKA[i],DKB[2]-127);
	}
	int DKB1=DKB[1];
	while(DKB1<=DKB[2]-100+1){
		line(DKA[1],DKB1,DKA[6],DKB1);
		DKB1+=40;
	}
	settextjustify(0,2);
  	settextstyle(10,0,2);
    setfillstyle(1,15);
    setbkcolor(15);
	bar(xTrangT-100,yTrang-20,xTrangT +100, yTrang +20);
	outtextxy(((xTrangT)*2-textwidth("TRANG TRUOC"))/2,yTrang-10,"TRANG TRUOC");
	bar(xTrangS-100,yTrang-20,xTrangS +100, yTrang +20);
	outtextxy(((xTrangS)*2-textwidth("TRANG SAU"))/2,yTrang-10,"TRANG SAU");
}



void keHangNhap(int y1 , int kc)
{
	settextstyle(2,0,5);
	setfillstyle(1,15);
	setbkcolor(15);
	int kt1 = 180;
	int kcIn = 20;
	bar(DKA[1] ,y1-kc-17,DKA[1]+ kt1 ,y1-kc+17);
	outtextxy(DKA[1] + 5 , y1 -kc -8 ,"NIEN KHOA : ");
	bar(DKA[1] + kt1 + kcIn , y1-kc-17 , DKA[1] + kt1 + kcIn + 115 ,y1-kc+17);
	outtextxy(DKA[1] + kt1 + kcIn + 5 , y1-kc-8 , "HOC KI : ");
	bar(DKA[1] + kt1 + kcIn*2 + 115 ,y1-kc-17 ,DKA[1] + kt1 + kcIn*2 + 200 + 115,y1-kc+17);
	outtextxy(DKA[1] + kt1 + kcIn*2 + 115 +5, y1-kc - 8 ,"MA MON HOC : ");
	bar (DKA[1] + kt1 + kcIn*3 + 200 + 115,y1-kc-17,DKA[1] + kt1 + kcIn*2 + + 200 + 115+100,y1-kc+17);
	outtextxy (DKA[1] + kt1 + kcIn*3 + 200 + 115+5,y1-kc-8 ,"NHOM : ");
}
void nhapNienKhoaDiem(int x1, int y1, char namHoc1[] ,int &select) {
	int i = 0;
	while(namHoc1[i]!='\0')
	{
		i++;
	}
	settextjustify(0,2);
	settextstyle(2, 0, 5);
	int xNhap = x1 +textwidth("NIEN KHOA : ") + textwidth(namHoc1);
	setfillstyle(1, 15);
	setbkcolor(15);
	while (true) {
		settextstyle(2, 0, 5);
		if (kbhit()) {
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 75)
			{
				select= 4;
				namHoc1[i] = '\0';
				break;
			}
			if (c[0] == 77)
			{
				select++;
				namHoc1[i] = '\0';
				break;
			}
			if (c[0] == 27)
			{
				namHoc1[i] = '\0';
				select =  7 ;
				break;
			}
			if (c[0] == 8 && i > 0) {
				if (i == 5) {
					i--;
					xNhap -= textwidth(&namHoc1[i]);
					namHoc1[i]='\0';
					outtextxy(xNhap, y1, "   ");
				}
				i--;
				xNhap -= textwidth(&namHoc1[i]);
				namHoc1[i]='\0';
				outtextxy(xNhap, y1, "   ");
			}

			if (c[0] == 13 && i>0) {
				namHoc1[i] = '\0';
				select = 5;
				break;
			}
			if (c[0] >= '0' && c[0] <= '9') {
				if (i == 9) {
					continue;
				}
				namHoc1[i] = c[0];
				namHoc1[i+1] = '\0';
				outtextxy(xNhap, y1, &c[0]);
				xNhap += textwidth(&c[0]);
				i++;
			}
			if (i == 4) {
				namHoc1[i] = '-';
				namHoc1[i+1] = '\0';
				outtextxy(xNhap, y1, "-");
				xNhap += textwidth("-");
				i++;
			}
		}
		else {
			outtextxy(xNhap, y1 , "|");	
			delay(500);
			outtextxy(xNhap, y1 , "  ");
			delay(200);
		}
	}
}

void inDamNutHCNhocki(int x, int y , int chieuDai, int chieuRong,const char*s,int mau){
		settextstyle(2,0,5);
		setfillstyle(1,mau);
		setbkcolor(mau);
		bar(x,y-chieuRong/2,x+chieuDai,y+chieuRong/2);
		outtextxy((chieuDai + textwidth(s))/2+x-10,y-8,s);
}
void inDamNutHCNDiem(int x, int y , int chieuDai, int chieuRong,const char*s,int mau){
		settextstyle(3,0,3);
		settextjustify(0,2);
		setfillstyle(1,mau);
		setbkcolor(mau);
		bar(x,y-chieuRong/2,x+chieuDai,y+chieuRong/2);
		outtextxy((chieuDai - textwidth(s))/2+x-10,y-10,s);
}
void chonHocKiDiem(int hocKi ,int x , int y)
{
	settextstyle(2,0,5);
	if (hocKi == 1)
	{
		inDamNutHCNhocki(x,y,20,34,"1",4);
		inDamNutHCNhocki(x+20,y,20,34 ,"2",15);
		inDamNutHCNhocki(x+40,y,20,34,"3",15);
	}
	else if(hocKi == 2)
	{
		inDamNutHCNhocki(x,y,20,34,"1",15);
		inDamNutHCNhocki(x+20,y,20,34 ,"2",4);
		inDamNutHCNhocki(x+40,y,20,34,"3",15);
	}
	else 
	{
		inDamNutHCNhocki(x,y,20,34,"1",15);
		inDamNutHCNhocki(x+20,y,20,34 ,"2",15);
		inDamNutHCNhocki(x+40,y,20,34,"3",4);
	}
}

void setHocKi(int x , int y , int &hocKi ,int &select)
{
	settextjustify(0,2);
	chonHocKiDiem(hocKi,x,y);
	while (true)
	{
		settextjustify(0,2);
		if(kbhit())
		{
			char c = getch();
			if (!c) 
				{
					c = getch();
				}
		if (c ==75)
		{
			if (hocKi == 1)
			{
				hocKi=3 ;
				chonHocKiDiem(hocKi,x,y);
			}
			else 
			{
				hocKi--;
				chonHocKiDiem(hocKi,x,y);
			}
		}
		if (c == 77)
		{
			if(hocKi == 3)
			{
				hocKi=1 ;
				chonHocKiDiem(hocKi,x,y);
			}
			else 
			{
				hocKi++;
				chonHocKiDiem(hocKi,x,y);
			}
		}
		if (c == 27)
		{
			select = 7 ; 
			break;
		}
		if (c == 13)
			{
			char hocKistr[2] ;
			itoa(hocKi,hocKistr,10);
			inDamNutHCNhocki(x , y ,62 ,34,hocKistr,10);
			break;
			}
		}
	}
}

void nextHocKi(int x , int y ,int &select,int hocKi)
{
	while (true)
			{
				if(kbhit())
				{
					char c = getch();
					if(!c)
					{
						c = getch();
					}
					if (c==27)
					{
						select = 7 ;
						break ;
					}
					if (c == 75)
					{
						char hocKistr[2] ;
						itoa(hocKi,hocKistr,10);
						inDamNutHCNhocki(x , y ,62 ,34,hocKistr,15);
						select--;
						break;
					}
					if (c==77)
					{
						char hocKistr[2] ;
						itoa(hocKi,hocKistr,10);
						inDamNutHCNhocki(x , y ,62 ,34,hocKistr,15);
						select++ ;
						break;
					}
					if (c == 13)
					{
						char hocKistr[2] ;
						itoa(hocKi,hocKistr,10);
						inDamNutHCNhocki(x , y ,62 ,34,hocKistr,15);
						select = 5;
						break;
					}
				}
			}
}

void thaoTacNhapSoNhom(int x,int y,int &so,int &kt ){
	settextstyle(2, 0, 5);
	char s[10];
	int i=0;
	if(so!=-1){
		itoa(so,s,10);
		i = strlen(s);
		x+=textwidth(s);
	}


	while (true) {
		settextstyle(2, 0, 5);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				kt=7;
				break;
			}
			if(c[0]==75){
				s[i] = '\0';
            	kt--;
            	break;
			}

			if(c[0]==77){
				s[i] = '\0';
            	kt=1;
            	break;
			}
			if (c[0] == 8 && i > 0) {
                i--;
                x-=textwidth(&s[i]);
                outtextxy(x, y ,"   ");
            }
            if (c[0] == 13) {
				s[i] = '\0';
				kt= 5;
				break;
			}
			if(i==1){
				s[i] ='\0';
				continue;
			}
			if (c[0] >= '1' && c[0] <= '9' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			delay(100);
		} else{
			outtextxy(x+3, y , "|");
			delay(500);
			outtextxy(x+3, y , " ");
			delay(200);
		}
	}
	doiKiTuSangSo(s,so);
}

void diChuyenChuotDiem(int x,int y,int& xCu,int &yCu,int &vt){
	
	int xSS=(xLTC[1]-xLTC[0])/2;
	int ySS= yLTC[1]/2;
	if(x<=xLTC[1]+50+20&&x>=xLTC[1]+50-20&&y>=yLTC[1]+12*khoangCachDong-30&&y<=yLTC[1]+12*khoangCachDong+10){
		if(vt==5){
			return;
			}
		inDamNutHCN(xLTC[1]+50,yLTC[1]+12*khoangCachDong,40,40,tenNutLTC[5].c_str(),4);
		if(vt!=-1){
			if(vt>=5&&vt<7){
				taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
				}
		}
		xCu=xLTC[1]+50;
		yCu=yLTC[1]+12*khoangCachDong;
		vt=5;
		return;	
	}
	if(x<=xLTC[9]-50+20&&x>=xLTC[9]-50-20&&y>=yLTC[1]+12*khoangCachDong-30&&y<=yLTC[1]+12*khoangCachDong+10){
		if(vt==6){
			return;
		}
		inDamNutHCN(xLTC[9]-50,yLTC[1]+12*khoangCachDong,40,40,tenNutLTC[6].c_str(),4);
		if(vt!=-1){ 
			if(vt>=5&&vt<7){
				taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
				}
		}
		xCu=xLTC[9]-50;
		yCu=yLTC[1]+12*khoangCachDong;
		vt=6;
		return;	
	}
	if(vt!=-1){ 
		if(vt>=5&&vt<7){
			taoNutHCN(xCu,yCu,40,40,tenNutLTC[vt].c_str());
			}
		vt=-1;
	}
}

void chonMHDiem(DSMH_AVL root ,char maMH[],int &select)
{
	setfillstyle(1,1);
	setbkcolor(1);
	bar(xLTC[1],yLTC[1],xLTC[9],yLTC[1]*13);
	int xChuot=0;
	int yChuot=0;
	int xCu=0;
	int yCu=0;
	int vt=-1;
	int vtBang=-1;
	int vtBang1=0;
	int stt =0;
	int tongSoTrang;
	int trangHienTai;
	MANGMH mang;
	Preorder(root,mang);
	if (mang.n % 10 == 0) tongSoTrang = (mang.n /10);
	else tongSoTrang = ((mang.n /10) + 1);
	if (tongSoTrang != 0) trangHienTai = 1 ;
	else trangHienTai = 0;
	taoBang();
	xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
	inBangThongBao("-Nhay dup trai","de chon mon hoc.","-Nhan ESC","de thoat.","");
	while(true)
	{
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if(c[0]==27){
				select = 3 ;
				return;
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			diChuyenChuotDiem(xChuot,yChuot,xCu,yCu,vt);
			layViTriChuotTrenBang(xChuot,yChuot,(toaDoX[6]-toaDoX[1])/2+toaDoX[1],toaDoY[1],vtBang1);
		}
		if(stt==0){
			stt=chonMaMonHoc(vtBang1,vtBang,trangHienTai,mang);
		}
		if(stt!=0){
			for(int i=0;i<strlen(mang.node[stt-1]->maMH);i++){
				maMH[i]=mang.node[stt-1]->maMH[i];
			}
			maMH[strlen(mang.node[stt-1]->maMH)]='\0';
			select = 9 ;
			return;
		}
		if(ismouseclick(WM_LBUTTONDBLCLK)){
			clearmouseclick(WM_LBUTTONDBLCLK);
				continue;
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==6&&trangHienTai<tongSoTrang&&stt==0){
				trangHienTai++;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==5&&trangHienTai>1&&stt==0){
				trangHienTai--;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				stt=0;
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(100);
	}
}
void thaoTacNhapMaMHDiem(int x,int y,int max, char s[], int &kt,DSMH_AVL root,bool checkDS){
	settextstyle(2, 0, 5);
	int i = strlen(s);
	int xtemp = x ;
	x+=textwidth(s);
	while (true) {
		inBangThongBao("Bam ESC de huy qua","trinh nhap !!!","Nhan F1 de tra cuu","ma/ten mon hoc !","");
		settextjustify(0,2);
		settextstyle(2,0,5);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0]==59)
			{
				chonMHDiem(root,s,kt);
					settextstyle(2, 0, 5);
					settextjustify(0,2);
					setfillstyle(1,15);
					setbkcolor(15);
				
				if (kt == 9)
				{
					outtextxy(xtemp  , y , s);
					
					if (checkDS == true)
					{
						keBangDSSV();
						xoaBang(160);
						inHangTieuDe(120);
					}
					else 
					{
						keBangDiem();
						inHangTieuDeNhapDiem(120,"STT","MA SO SINH VIEN","HO SINH VIEN","TEN SV","DIEM");
						xoaBangNhapDiem(160);
					}
					kt=3;
					break;
				}
				if (checkDS == true)
					{
						keBangDSSV();
						xoaBang(160);
						inHangTieuDe(120);
					}
					else 
					{
						keBangDiem();
						inHangTieuDeNhapDiem(120,"STT","MA SO SINH VIEN","HO SINH VIEN","TEN SV","DIEM");
						xoaBangNhapDiem(160);
					}
			}
			if(c[0]==27){
				kt=7;
				return;
			}
			if(c[0]==75){
            		s[i] = '\0';
            		kt--;
            		break;
			}
			if (c[0]==77) {
					s[i] = '\0';
					kt++;
					break;
			}
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=5;
				break;
			}
			if (c[0] == 8 && i > 0) {
				x-=textwidth(&s[i-1]);
				s[i-1]='\0';
                i--;
                outtextxy(x, y ,"    ");
            }
			if(i==max){
				continue;
			}
			
			if (c[0] >= '0' && c[0] <= '9') {
				s[i] = c[0];
				s[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(&c[0]);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(&c[0]);
				i++;
			}
            delay(100);
		}else{
			outtextxy(x+3, y , "|");
			delay(500);
			outtextxy(x+3, y , " ");
			delay(200);
		}
	}
}

void xuat1SV(NodeDK *k ,int Y1 , int STTreal ,int mau,DanhSach list)
{
	int STT;
	if (STTreal % 10 != 0) STT = STTreal % 10 ;
	else STT = 10 ;
	settextstyle(2,0,5);
	char tempXuat[50];
	char STTstr[10];
	setfillstyle(1,mau);
	setbkcolor(mau);
	settextjustify(0,2);
	bar (DKA[1] + 1,160 +(STT-1)*40 + 1 ,DKA[2] - 1, 160 + 40*STT- 1);
	bar (DKA[2] + 1,160 +(STT-1)*40 + 1 ,DKA[3] - 1, 160 + 40*STT- 1);
	bar (DKA[3] + 1,160 +(STT-1)*40 + 1 ,DKA[4] - 1, 160 + 40*STT- 1);
	bar (DKA[4] + 1,160 +(STT-1)*40 + 1 ,DKA[5] - 1, 160 + 40*STT- 1);
	bar (DKA[5] + 1,160 +(STT-1)*40 + 1 ,DKA[6] - 1, 160 + 40*STT- 1);
	itoa(STTreal, STTstr ,10);
	outtextxy((DKA[2]-DKA[1] - textwidth(STTstr))/2 +DKA[1],Y1+ STT*40 +8,STTstr);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.MaSV ,tempXuat);
	outtextxy((DKA[3]-DKA[2] - textwidth(tempXuat))/2 + DKA[2],Y1 + STT*40 +8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.Ho ,tempXuat);
	outtextxy(20 + DKA[3],Y1+ STT*40+8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.Ten,tempXuat);
	outtextxy((DKA[5]-DKA[4] - textwidth(tempXuat))/2 + DKA[4],Y1+ STT*40+8,tempXuat);
	if (k->data.diemSV != -1)
	{
		chuyenFloatSangChar(k->data.diemSV, tempXuat);
		outtextxy((DKA[6]-DKA[5] - textwidth(tempXuat))/2 + DKA[5],Y1+ STT*40+8,tempXuat);
	}
//	else outtextxy((DKA[6]-DKA[5] - textwidth("0"))/2 + DKA[5],Y1+ STT*40+8,"0");
	
}
void xuat1SVDSDK(NodeDK *k ,int Y1 , int STTreal ,int mau,DanhSach list)
{
	int A[8]={0,350,410,600,860,1000,1150,1340};
	int STT;
	if (STTreal % 10 != 0) STT = STTreal % 10 ;
	else STT = 10 ;
	settextstyle(2,0,5);
	char tempXuat[50];
	char STTstr[10];
	setfillstyle(1,mau);
	setbkcolor(mau);
	settextjustify(0,2);
	bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
	bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
	bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
	bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
	bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
	bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);
	itoa(STTreal, STTstr ,10);
	outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+STT*40+8,STTstr);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.MaSV ,tempXuat);
	outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1+STT*40+8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.Ho ,tempXuat);
	outtextxy(20 + A[3],Y1+STT*40+8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.Ten,tempXuat);
	outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+STT*40+8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.Phai,tempXuat);
	outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+STT*40+8,tempXuat);
	chuyen(timThongTin1SV( k->data.maSVdk ,list)->data.SoDT,tempXuat);
	outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+STT*40+8,tempXuat);
}

void XuatDSDKLTC(DanhSach list,DSLTC& dsLop , int Trang , int &soTrang ,int f)
{
	int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ;
	int i = (Trang-1)* 10 + 1;
	char TrangStr[10];
	char soTrangStr[10];
	char STTstr[10];
	int dem = 0 ;
	int Y1=160;
	char tempXuat[50];
	settextstyle(2,0,5);
	settextjustify(0,2);
	for ( NodeDK* k = dsLop.lop[f]->lopDK.head ; k !=NULL ; k=k->next)
	{
		if (k->data.huyDangKi == 0)
		{
			dem++ ;
			if (dem >= i && dem <= Trang*10 )
			{
				if (dem %2 != 0)
				{
					xuat1SVDSDK (k ,120 ,dem ,15,list);
				}
				else 
				{
					xuat1SVDSDK (k ,120 ,dem ,9,list);
				}
			}
		}
		}
	if (dem%10 == 0) soTrang =dem/10 ;
	else soTrang =dem/10+1;
	setbkcolor (1);
	settextstyle(3,0,1);
	itoa(Trang , TrangStr ,10);
	itoa (soTrang ,soTrangStr , 10);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2 , yTrang - 10 , TrangStr);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) , yTrang - 10 , "/");	
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) + textwidth("/"),  yTrang - 10 , soTrangStr);
}

void XuatDSLTC(DanhSach list,DSLTC& dsLop , int Trang , int &soTrang ,int f)
{
	xoaBangNhapDiem(160);
	int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ;
	int i = (Trang-1)* 10 + 1;
	char TrangStr[10];
	char soTrangStr[10];
	char STTstr[10];
	int dem = 0 ;
	int Y1=160;
	char tempXuat[50];
	settextstyle(2,0,5);
	settextjustify(0,2);
	for ( NodeDK* k = dsLop.lop[f]->lopDK.head ; k !=NULL ; k=k->next)
	{
			
			if (k->data.huyDangKi == 0)
			{
				dem++ ;
			if (dem >= i && dem <= Trang*10 )
			{
				if (dem %2 != 0)
				{
					xuat1SV (k ,120 ,dem ,15,list);
				}
				else 
				{
					xuat1SV (k ,120 ,dem ,9,list);
				}
			}
			}
			
		}
	if (dem%10 == 0) soTrang =dem/10 ;
	else soTrang =dem/10+1;
	setbkcolor (1);
	settextstyle(3,0,1);
	itoa(Trang , TrangStr ,10);
	itoa (soTrang ,soTrangStr , 10);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2 , yTrang - 10 , TrangStr);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) , yTrang - 10 , "/");	
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) + textwidth("/"), yTrang - 10 , soTrangStr);	
}

void kiemTra(DanhSach &list ,DSLTC& dsLop , char *nienKhoa , int &hocKi , int &nhom , char *maMHtemp , int &f,int &Trang ,int &soTrang,bool checkDS,int &select)
{

	bool check = false ;
	for (int i = 0 ; i < dsLop.n ; i++)
		{
			if (strcmp (dsLop.lop[i]->nienKhoa , nienKhoa) == 0 && hocKi == dsLop.lop[i]->hocKi && nhom == dsLop.lop[i]->nhom && strcmp(dsLop.lop[i]->maMH,maMHtemp) == 0)
			{
				Trang = 1 ; check = true ; f=i ;
				if (dsLop.lop[i]->huyLop == 1 && dsLop.lop[i]->coDiem!=1&& checkDS == false) 
				{
					inBangThongBao("Lop Tin Chi Tren Chua","Hoat Dong !","Vui Long Nhap Lai !","","");
					settextjustify(0,2);
					delay(2000);
					select = 1;
					break;
				}
				 if (checkDS == false && dsLop.lop[i]->huyLop != 1)
					{
						char ma[50];
						itoa(dsLop.lop[i]->maLopTC,ma,10);
						XuatDSLTC(list,dsLop , Trang , soTrang,f);
						settextstyle(10,0,2);
						setfillstyle(1,10);
						setbkcolor(10);
						bar (DKA[4] , 80-20 , DKA[5]+15,80+17);
						outtextxy((DKA[5] - DKA[4] -textwidth("MA LTC : "))/2 +DKA[4] , 80-10 , "MA LTC : ");
						outtextxy((DKA[5] - DKA[4]- textwidth("MA LTC : "))/2 +DKA[4] + textwidth("MA LTC : "), 80-10 , ma);
					}
				if (checkDS == true ) 
				{
					char ma[50];
					itoa(dsLop.lop[i]->maLopTC,ma,10);
					XuatDSDKLTC(list,dsLop , Trang , soTrang,f);
					settextstyle(10,0,2);
						setfillstyle(1,10);
						setbkcolor(10);
						bar (DKA[4] , 80-20 , DKA[5]+15,80+17);
						outtextxy((DKA[5] - DKA[4] -textwidth("MA LTC : "))/2 +DKA[4] , 80-10 , "MA LTC : ");
						outtextxy((DKA[5] - DKA[4]- textwidth("MA LTC : "))/2 +DKA[4] + textwidth("MA LTC : "), 80-10 , ma);
				}
					
				select = 0 ;					
			}
		}
	if (check == false) 
	{
		inBangThongBao("Khong Co Lop Tin" , "Chi Tren !!" , "Vui Long Nhap Lai !","","");
		settextjustify(0,2);
		delay(2000);
		keHangNhap(140,60);
		 nienKhoa[0] = '\0'; hocKi=1 ; maMHtemp[0] = '\0'; nhom = -1 ;
		select = 1;
	}
}


void viTriChuotDK(int &STT , int x , int y , int y1 , int kcSV)
{
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 && y <= y1 + kcSV ) 
		{
			STT = 1 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV  && y <= y1 + 2*kcSV ) 
		{
			STT = 2 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 + kcSV *2 && y <= y1 + 3*kcSV ) 
		{
			STT = 3 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV *3 && y <= y1 + 4*kcSV ) 
		{
			STT = 4 ; 
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 + kcSV*4 && y <= y1 + 5*kcSV ) 
		{
			STT = 5 ; 
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 + kcSV*5 && y <= y1 + 6*kcSV ) 
		{
			STT = 6 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV*6&& y <= y1 + 7*kcSV ) 
		{
			STT = 7 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV*7&& y <= y1 + 8*kcSV ) 
		{
			STT = 8 ;  
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV*8&& y <= y1 + 9*kcSV) 
		{
			STT = 9 ; 
		}
	if (x >= DKA[1] && x <= DKA[6] && y >= y1 +kcSV*9&& y <= y1 + 10*kcSV) 
		{
			STT = 10 ; 
		}
}
void toDamSVDK(NodeDK *iftemp,DSLTC& dsLop, DanhSach list ,int &STT ,int STTinput,int Trang,int f)
{
	if(STTinput==STT)
	{
		return;
	}
	int dem = 0 ;
	int Y1=120;
	
	if(STT!=-1 )
		{
			int STTOut = (Trang-1)* 10 + STT;
				if (STT %2 != 0)
					{
						xuat1SV(iftemp,Y1,STTOut,15,list);
					}
					else 
					{
						xuat1SV(iftemp,Y1,STTOut,9,list);
					}
			inBangThongBao("Click De Chon Sinh Vien"," Can Sua Diem !","","","");
			settextstyle(2,0,5);
			settextjustify(0,2);	
		}
		int STTIn = (Trang-1)* 10 + STTinput ;
				STT = STTinput;
				for (NodeDK* k = dsLop.lop[f]->lopDK.head ; k !=NULL ; k=k->next)
				{
					dem++ ;
					if (dem == STTIn) 
					{
						xuat1SV(k,Y1,STTIn,12,list);
						inBangThongBao("Click De Chon Sinh Vien"," Can Sua Diem !","","","");
						settextstyle(2,0,5);
						settextjustify(0,2);
						iftemp->data = k->data;
					}
					
				}
				
}
void xoaToDSDK(NodeDK *iftemp,DSLTC& dsLop, DanhSach list ,int &STT ,int Trang,int &xoaToMau)
{
	if (xoaToMau == 0)
	{
		xoaToMau = 1 ;
		if (STT != -1)
		{
			char STTstr[10];
			int dem = 0 ;
			int Y1=120;
			char tempXuat[50];
			settextstyle(2,0,5);
			int STTOut = (Trang-1)* 10 + STT;
						if (STT %2 != 0)
					{
						xuat1SV(iftemp,Y1,STTOut,15,list);
					}
					else 
					{
						xuat1SV(iftemp,Y1,STTOut,9,list);
					}
				STT =-1;
			inBangThongBao("","","","","");	
		}
	}
}
void vaoDiem(float diemTemp , DSLTC &dsLop,int f ,int STT)
{
	int dem =0; 
	for(NodeDK*k = dsLop.lop[f]->lopDK.head ; k!=NULL;k=k->next)
		{
		dem++;
		if(dem == STT)
		{
			k->data.diemSV = diemTemp ;
			break;
		}
		}
}


void thaoTacNhapThongTin(int &select ,int yNhap ,int kc , char nienKhoa[] ,char maMH[],int&hocKi ,int nhom ,int &ds , int &Trang , int&soTrang, DanhSach list,DSLTC& dsLop,bool checkDS,DSMH_AVL root)
{
	bool checkHocKi = false ;
	while (select != 0)
	{	
		inBangThongBao("Bam ESC de huy qua","trinh nhap !!!","","","");
		settextjustify(0,2);
		settextstyle(2,0,5);
		switch(select)
		{
			case 1 : 
				{
				     
				nhapNienKhoaDiem(DKA[1]+5,yNhap-kc-8,nienKhoa,select);       
				break ;                                                  
				}
			case 2 :
				{
					setHocKi(DKA[1] + 180 +20+textwidth("HOC KI : ") +5,yNhap-kc,hocKi,select);
					if (select != 7)
					{
		
						nextHocKi(DKA[1] + 180 +20 +textwidth("HOC KI : ") +5,yNhap-kc,select,hocKi);
						checkHocKi = true ; 	
					}
					break;	
				}
			case 4 : 
				{
				thaoTacNhapSoNhom(DKA[1] + 180 +20*3+200+115+textwidth("NHOM : ") + 5 ,yNhap-kc-8,nhom,select );
				break;
				}
			case 3 :
				{	
					thaoTacNhapMaMHDiem(DKA[1] + 180 +20*2+115+textwidth("MA MON HOC :") + 5,yNhap-kc-8,11,maMH, select,root,checkDS);
					break;
				}
			case 5 :                                                                                     
				{                                                                                               
				if (nienKhoa[0] == '\0')
				{
					select = 1;
					inBangThongBao("Nien Khoa Khong Duoc" ,"De Trong !!","","","");
					delay(2000);
					break;
			
				}
				else if (checkHocKi != true)
				{
					inBangThongBao("Chua Chon Hoc Ki" ,"","","","");
					delay(2000);
					select = 2 ;
					break;
				}
				else if (maMH[0] == '\0')	
				{
					inBangThongBao("Chua Nhap Ma Mon Hoc" , "Vui Long Nhap !!!","","","");
					delay(2000);
					select = 3 ;
					break;	
				}
				else if (nhom == -1)
				{
					inBangThongBao("Chua Nhap Nhom Hoc !!","Vui Long Nhap Nhom !!","","","");
					delay(2000);
					select = 4 ;                                                                                   
					break;
				}
				else 
				{
					select = 6 ;
					break;
				}
											
			}
			case 6 :
				{
					
					kiemTra (list ,dsLop ,nienKhoa , hocKi ,nhom , maMH,ds,Trang ,soTrang,checkDS,select);
					break ;
				}
			case 7 : 
			{
				inDamNutHCNDiem(DKA[1],120/2,DKA[6]-DKA[1],110,"",1);
				inBangThongBao("","","","","");
				select = 0 ;
				break ;
			}
		}
	}
	clearmouseclick(WM_LBUTTONDOWN);
}

void nhapDiemList(float &diem ,int x,int y,int &chon)
{
	settextjustify(0,2);
	settextstyle(2, 0, 5);
	setbkcolor (10);
	int i = 0;
	char temp [6];
	if(diem != -1)
	{
		chuyenFloatSangChar( diem , temp);
		outtextxy(x,y,temp);
	}
	
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
 	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		inBangThongBao("Nhan ESC De Huy Qua","Trinh Nhap/Sua Diem.","Nhan ENTER De Luu Diem","(0,0 <= Diem <= 10,0)","");
		settextjustify(0,2);
		settextstyle(2, 0, 5);
		setfillstyle(1,10);
		setbkcolor(10);
		if(kbhit()){
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				chon = 0 ;
				break;
			}
			if (c[0] == 72)
			{
				temp[i] = '\0';
				if (i == 0)
				{
					diem= -1 ;
					chon = 2 ;
					break;
				}
				if (temp[i-1] != '.')
				{
					diem = atof(temp);
					if (diem >= 0 && diem <= 10)
					{
						chon = 2 ;
						break ;
					}
					else
					{
						inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
						delay(2000);
						settextjustify(0,2);
						setbkcolor(10);
						continue ;
					}
				}
				else 
				{
					inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
					delay(2000);
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
			}
			if ((c[0] == 13 || c[0] == 80))
			{
				temp[i] = '\0';
				if (i == 0)
				{
					diem= -1 ;
					chon = 3 ;
						if (c[0] == 13)
						{
							chon = 4;
						}
					break;
				}
				if (temp[i-1] != '.')
				{
					diem = atof(temp);
					if (diem >= 0 && diem <= 10)
					{
						chon = 3 ;
						if (c[0] == 13)
						{
							chon = 4;
						}
						break ;
					}
					else
					{
						inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
						delay(2000);
						settextjustify(0,2);
						setbkcolor(10);
						continue ;
					}
				}
				else 
				{
					inBangThongBao("Nhap Sai Qui Dinh", "(0,0 <= Diem <= 10,0)","","","");
					delay(2000);
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
			}
			
			if (c[0] == 8 && i > 0) {
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"     ");
            }
			if(i==5)
			{
				continue;
			}
			if (c[0] == '.' && i >0)
			{
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if ((c[0] >= '0' && c[0] <= '9' )) {		
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			
		} else{
			settextstyle(2, 0, 5);
			outtextxy(x, y , "|");
			delay(500);
			outtextxy(x, y , "  ");
			delay(200);
		}
	}
}

void thaoTacNhapDiemList(DanhSach list , DSLTC& dsLop,int &Trang ,int soTrang ,int f )
{
	NodeDK *temp = new NodeDK;
	int chon = 1 ;
	int STTmove =1 ;
	float diemTemp;
	int dem ;
	while (chon != 0)
	{
		switch(chon)
		{
			case 1 : 
			{
				dem = 0 ;
				for (NodeDK * k = dsLop.lop[f]->lopDK.head ; k!=NULL ;k=k->next)
				{
					if (k->data.huyDangKi == 0) dem++ ;
					if (dem == STTmove+(Trang-1)*10)
					{
						temp->data = k->data;
					}
				}
//				if (temp->data.diemSV != -1) 
//				{
//					STTmove++ ;
//					chon = 1 ;
//					break;
//				}
					xuat1SV(temp,120,STTmove+(Trang-1)*10,10,list);
	 				diemTemp=temp->data.diemSV;
					setfillstyle(1,10);
					bar (DKA[5] + 1,160 +(STTmove-1)*40 + 1 ,DKA[6] - 1, 160 + 40*STTmove- 1);
					nhapDiemList(diemTemp,(DKA[6]-DKA[5] -textwidth("6.00"))/2 + DKA[5],120+STTmove*40+8,chon);
					if (chon == 0)
					{
						if (STTmove%2 != 0) xuat1SV(temp,120,STTmove+(Trang-1)*10,15,list);
						else xuat1SV(temp,120,STTmove+(Trang-1)*10,9,list);	
					}
				break;	
			}
			case 2 :
			{
				if((diemTemp >= 0 && diemTemp <=10 ) || diemTemp == -1)
				{
					vaoDiem(diemTemp,dsLop,f,STTmove+(Trang-1)*10);
					temp->data.diemSV = diemTemp ;
					if (diemTemp != - 1)
					{
						dsLop.lop[f]->coDiem = 1 ;
					}
				}
				if (Trang == 1 && STTmove == 1)
				{
					chon = 1 ;
					inBangThongBao("Ban Dang O Dau","Danh Sach !!","","","");
					delay(2000);
					break ; 
				}
				if (STTmove+(Trang-1)*10 - 1 > 0)
				{
					if (STTmove %10 == 1)
					{
						Trang-- ;
						xoaBangNhapDiem(160);
						XuatDSLTC(list,dsLop,Trang,soTrang,f);
						STTmove = 10;
						chon = 1 ;
						break ; 
					}
					else 
					{
						if (STTmove%2 != 0) xuat1SV(temp,120,STTmove+(Trang-1)*10,15,list);
						else xuat1SV(temp,120,STTmove+(Trang-1)*10,9,list);	
						STTmove-- ; 
						chon = 1 ;
						break ; 	
					}	
				} 
			}
			case 3 :
			{
				if((diemTemp >= 0 && diemTemp <=10 ) || diemTemp == -1)
				{
					vaoDiem(diemTemp,dsLop,f,STTmove+(Trang-1)*10);
					temp->data.diemSV = diemTemp ;
					if (diemTemp != - 1)
					{
						dsLop.lop[f]->coDiem = 1 ;
					}
				}
				if (Trang == soTrang && STTmove + (Trang - 1)*10 == dsLop.lop[f]->slSV)
				{
					chon = 1 ;
					inBangThongBao("Ban Dang O Cuoi","Danh Sach !!","","","");
					delay(2000);
					break ; 
				}
				if (STTmove+(Trang-1)*10 + 1 <=dsLop.lop[f]->slSV)
				{
					if (STTmove %10 == 0)
					{
						Trang++ ;
						xoaBangNhapDiem(160);
						XuatDSLTC(list,dsLop,Trang,soTrang,f);
						STTmove = 1;
						chon = 1 ;
						break;
					}
					else
					{
						if (STTmove%2 != 0) xuat1SV(temp,120,STTmove+(Trang-1)*10,15,list);
					else xuat1SV(temp,120,STTmove+(Trang-1)*10,9,list);	
					STTmove++ ; 
					
					chon = 1 ;
					break ; 
					}
					
				} 	
			}
			case 4: 
			{
				if((diemTemp >= 0 && diemTemp <=10 ) || diemTemp == -1)
				{
					vaoDiem(diemTemp,dsLop,f,STTmove+(Trang-1)*10);
					temp->data.diemSV = diemTemp ;
					if (diemTemp != - 1)
					{
						dsLop.lop[f]->coDiem = 1 ;
					}
				}
				if (STTmove%2 != 0) xuat1SV(temp,120,STTmove+(Trang-1)*10,15,list);
				else xuat1SV(temp,120,STTmove+(Trang-1)*10,9,list);	
				chon = 0 ; 
				break;
			}
		}
	}
}

void manHinhNhapDiem(DanhSach &list ,DSLTC& dsLop,DSMH_AVL root)
{
	int x,y; 
	int xDK=-1 ; int yDK = -1 ;
	const char *sDK ;
	int x1=150,y1=160;// toa do BUTTON
	int yNhap = 140;
	int kc=60; // khoang cach BUTTON
	setbkcolor(1);
	cleardevice();
	keBangDiem();
	inBangThongBao("","","","","");
	int ytemp1 = 120;
	inHangTieuDeNhapDiem(ytemp1,"STT","MA SO SINH VIEN","HO SINH VIEN","TEN SV","DIEM");
	int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ;
	giaoDienNhapDiem( xTrangT , xTrangS, yTrang,  x1 , y1,  kc );
	xoaBangNhapDiem(160);
	char nienKhoa[10]; nienKhoa[0] = '\0';
	char nienKhoaxem[10]; nienKhoaxem[0] = '\0';
	int hocKi = 1;
	int hocKixem =1 ;
	int nhom  =-1; int nhomXem =-1 ;
	int xoaTo = 0 ;
	int Trang ,soTrang ;
	char maMHtemp[16];maMHtemp[0] = '\0';
	char maMHxem[16];maMHxem[0] = '\0';
	int STTmove ;
	bool checkDS = false ;
	int kcSV = 40 ;
	int f = -1; int dsXem = -1 ;int fDS=-1;
	int STTchange =-1;
	NodeDK* iftemp = new NodeDK;
	int inNote = 0 ;
	int xoaToMau = 0 ;
	while (true)
	{
		settextjustify(0,2);
		if (kbhit())
		{
			char c = getch();
		}
		if (ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			if(x >= x1-100&& y >= y1-20 && x <= x1+100 && y <= y1+20)///MOVEMOUSE NHAP/SUA DIEM
			{
				toDamDSSV(x1 ,xDK,y1,yDK,sDK,"NHAP/SUA DIEM");
				xoaTo = 0;
				if (dsXem!= -1)
				{
					if (inNote ==0)
					{
						inBangThongBao("Ban Dang O Che Do" ,"Xem Diem !" , "Click LOP TIN CHI","De Nhap Thong Tin Lop","Can Nhap/Sua Diem");
						inNote = 1;
					}
					
				}
				 if (f==-1 && dsXem== -1 && checkDS == false)
				{
					if (inNote ==0)
					{
						inBangThongBao("Ban Chua Nhap Thong Tin","LOP TIN CHI !!","Click LOP TIN CHI De","Nhap Thong Tin Lop Can","Nhap/Sua Diem");
						inNote = 1;
					}
					
				}
				if (checkDS == true)
				{
					if (inNote ==0)
					{
						inBangThongBao("Ban Dang O Che Do" ,"Xem Danh Sach Sinh Vien" , "Click LOP TIN CHI","De Nhap Thong Tin Lop","Can Nhap/Sua Diem");
						inNote = 1;
					}
					
				}
			}
			else if (x >= x1-100&& y >= y1-kc*2-20 && x <= x1+100 && y <= y1-kc*2+20)//MOVE LOP TIN CHI
			{
				toDamDSSV(x1 ,xDK,y1-kc*2,yDK,sDK,"LOP TIN CHI");
				xoaTo = 0;
				if (inNote ==0)
					{
						inBangThongBao("Click Vao Day De" ,"Nhap Thong Tin","Lop Tin Chi (LTC)","Can Nhap/Sua Diem !!","");
						inNote = 1;
					}
				
			}
			else if (x >= x1-100&& y >= y1-kc-20 && x <= x1+100 && y <= y1-kc+20)
			{
				toDamDSSV(x1 ,xDK,y1-kc,yDK,sDK,"XEM DIEM");
				xoaTo = 0;
				if (inNote ==0)
					{
						inBangThongBao("Click Vao Day De Xem","Bang Diem Mon Hoc Cua","1 Lop Tin Chi","","");
						inNote = 1;
					}
				
			}
			else if( x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc && y <= y1 +20 +kc)
			{
				toDamDSSV(x1 ,xDK,y1+kc,yDK,sDK,"DSSV DANG KI");
				xoaTo = 0;
				if (inNote ==0)
					{
						inBangThongBao("Click Vao Day De In Ra"," Danh Sach Sinh Vien","Da Dang Ki Lop Tin","Chi","");
						inNote = 1;
					}
				
			}
			else if (x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc*2 && y <= y1 +20 +kc*2)
			{
				toDamDSSV(x1 ,xDK,y1+kc*2,yDK,sDK,"THOAT");
				xoaTo = 0;
				inNote = 0 ;
			}
			else if(x<=xTrangT+100&&x>=xTrangT-100&&y<=yTrang+20&&y>=yTrang-20)//TRANG_TRUOC_BUTTON MOVE
					{	

						toDamDSSV(xTrangT,xDK,yTrang,yDK,sDK ,"TRANG TRUOC");
						xoaTo= 0;
						if (f==-1&&dsXem == -1&&checkDS == false)
			            {
			            	if (inNote ==0)
							{
									inBangThongBao("Ban Chua Nhap","Thong Tin LTC !","Danh Sach","Hien Rong !","");
									inNote = 1;
							}
			            
						}
					}
			else if(x<=xTrangS+100&&x>=xTrangS-100&&y<=yTrang+20&&y>=yTrang-20) // //TRANG_TRUOC_BUTTON MOVE
					{

						toDamDSSV(xTrangS,xDK,yTrang,yDK,sDK ,"TRANG SAU"); 
						xoaTo = 0;
						if (f==-1 && dsXem == -1 &&checkDS == false)
			            {
			            	if (inNote ==0)
							{
									inBangThongBao("Ban Chua Nhap","Thong Tin LTC !","Danh Sach","Hien Rong !","");
									inNote = 1;
							}
			            	
						}
					}
			else if (x >= DKA[1] && x <=DKA[6] && y >= y1 && y <= y1 +kcSV*10 && f!= -1)
			{
				inNote = 0;
						viTriChuotDK(STTmove ,x,y,y1,kcSV);
						xoaToDamButton(xDK,yDK,sDK,xoaTo); 
								xoaToMau = 0;
								if ((Trang -1)*10 + STTmove <= dsLop.lop[f]->slSV)
								{
									toDamSVDK(iftemp,dsLop,list,STTchange,STTmove,Trang,f);
									xoaToMau = 0;
								}
								else 
								{
									xoaToDSDK(iftemp ,dsLop,list,STTchange,Trang,xoaToMau);
								}
			}
			else 
			{
				inNote =0 ;
				xoaToDamButton(xDK,yDK,sDK,xoaTo);
				xoaToDSDK(iftemp ,dsLop,list,STTchange,Trang,xoaToMau);
			}
		}
		////////////=======================END MOVE MOUSE
		//==================================================================
		//=============================================
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if (x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc*2 && y <= y1 +20 +kc*2) //CLICK THOAT
			{
				//continue ;
				ghiFileLTC(dsLop);
				break ;
			}
			if (x>=x1-100&&y>=y1-20&&x<=x1+100&&y<=y1+20 && f != -1)
			{
				thaoTacNhapDiemList(list,dsLop,Trang,soTrang,f);
			}
			if (x >= x1-100&& y >= y1-kc*2-20 && x <= x1+100 && y <= y1-kc*2+20) /// Nhap LOP TIN CHI
			{
				checkDS = false ;
				inHangTieuDeNhapDiem(ytemp1,"STT","MA SO SINH VIEN","HO SINH VIEN","TEN SV","DIEM");
				xoaBangNhapDiem(160);
				settextstyle(4,0,4);
				setbkcolor(1);
				setfillstyle(1,1);
				outtextxy((getmaxx()-textwidth("NHAP/SUA DIEM LOP TIN CHI")-DKA[1])/2+DKA[1],16,"NHAP/SUA DIEM LOP TIN CHI");
				f = -1; dsXem=-1; // stt loptc
				settextjustify(0,2);
				keHangNhap(yNhap,kc);
				int select = 1 ; 
				nienKhoa[0] = '\0';
				maMHtemp[0] = '\0';
				nhom =-1;
				thaoTacNhapThongTin(select ,yNhap,kc,nienKhoa,maMHtemp,hocKi,nhom,f,Trang,soTrang,list,dsLop,checkDS,root);
			}
			if (x >= DKA[1] && x <=DKA[6] && y >= y1 && y <= y1 +kcSV*10 && f!= -1) // CLICK SINH VIEN ( NHAP/SUA)
			{
				viTriChuotDK(STTmove ,x,y,y1,kcSV);
				int demSL = 0;
				for (NodeDK *k = dsLop.lop[f]->lopDK.head ; k!= NULL ; k=k->next)
				{
					if (k->data.huyDangKi == 0)	demSL++;
				}
				if (demSL < (Trang - 1 )*10 + STTmove) continue ;
				xuat1SV(iftemp,120,STTmove+(Trang-1)*10,10,list);
				int doi = 0;
				while (true)
				{
					if(kbhit())
					{
						char c= getch();
					}
					if (ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN,x,y);
						if (x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc*2 && y <= y1 +20 +kc*2)
						{
							break ;
						}
						else if (x >= x1-100&& y >= y1-20 && x <= x1+100 && y <= y1+20 )
						{
							float diemTemp =iftemp->data.diemSV;
							setfillstyle(1,10);
							bar (DKA[5] + 1,160 +(STTmove-1)*40 + 1 ,DKA[6] - 1, 160 + 40*STTmove- 1);
							thaoTacNhapDiem(diemTemp,(DKA[6]-DKA[5] -textwidth("6"))/2 + DKA[5],120+STTmove*40+8);
							if((diemTemp >= 0 && diemTemp <=10) || diemTemp == -1)
							{
								vaoDiem(diemTemp,dsLop,f,STTmove+(Trang-1)*10);
								iftemp->data.diemSV = diemTemp ;
								if (diemTemp != - 1)
								{
									dsLop.lop[f]->coDiem = 1 ;
								}
							}
							xoaToDSDK(iftemp ,dsLop,list,STTchange,Trang,xoaToMau);
							break;
						} 	
					}
					if (ismouseclick(WM_MOUSEMOVE))
					{
						getmouseclick(WM_MOUSEMOVE , x,y);
						if(x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc*2 && y <= y1 +20 +kc*2)
						{
							toDamDSSV(x1,xDK,y1+kc*2,yDK,sDK,"THOAT");
							xoaTo=0;
							doi=0;
							inBangThongBao("Click Vao Day De Bo","Chon Sinh Vien","","","");
						}
						else if (x >= x1-100&& y >= y1-20 && x <= x1+100 && y <= y1+20)
						{
							toDamDSSV(x1,xDK,y1,yDK,sDK,"NHAP/SUA DIEM");
							xoaTo=0;
							doi = 0;
							inBangThongBao("Click Vao Day De","Sua Diem","","","");

						}
						else 
						{
							xoaToDamButton(xDK,yDK,sDK,xoaTo);
							if(doi == 0)
							{
								inBangThongBao("Click NHAP/SUA DIEM De","Sua Diem !","Click THOAT De Bo Chon!","","");
								doi = 1;
							}
						}                                  
							
						
					}
					delay(100);
				}
			}
			if(x<=xTrangT+100&&x>=xTrangT-100&&y<=yTrang+20&&y>=yTrang-20) // CLICK TRANG TRUOC
			{
				if(f==-1 && dsXem == -1 && checkDS!= true) continue;
				int ftemp;
				if (f!= -1)
				{
					 ftemp = f ;
				}
				else if (dsXem != -1)
				{
					  ftemp= dsXem ;
				}
				else 
				{
					ftemp = fDS;
				}
				
				if (Trang == 1)
				    {
				        	inBangThongBao("Ban Dang O","Trang Dau Tien !","","","");
					}
				else 
					{
						Trang--;
						int ytemp = 160;
						xoaBangNhapDiem(ytemp);
						XuatDSLTC(list,dsLop,Trang,soTrang,ftemp);
					}	
				
			}
			if (x<=xTrangS+100&&x>=xTrangS-100&&y<=yTrang+20&&y>=yTrang-20)// CLICK TRANG SAU
			{
				if(f==-1 && dsXem == -1&& checkDS!= true) continue;
				int ftemp ;
				if (f!= -1)
				{
				 ftemp = f ;
				}
				else if (dsXem != -1)
				{
					 ftemp = dsXem ;
				}
				else 
				{
					 ftemp = fDS;
				}
					if (Trang == soTrang)
				    {
				        	inBangThongBao("Ban Dang O","Trang Cuoi Cung !","","","");
					}
					else 
					{
						Trang++;
						int ytemp = 160;
						xoaBangNhapDiem(ytemp);
						XuatDSLTC(list,dsLop,Trang,soTrang,ftemp);
						//inBangThongBao("","","","","");
					}	
				
			}
			if (x >= x1-100&& y >= y1-kc-20 && x <= x1+100 && y <= y1-kc+20)///XEM DIEM
			{
				checkDS = false ;
				inDamNutHCNDiem(DKA[1],60,DKA[6]-DKA[1],110,"",1);
				settextstyle(4,0,4);
				setbkcolor(1);
				setfillstyle(1,1);
				outtextxy((getmaxx()-textwidth("  BANG DIEM LOP TIN CHI  ")-DKA[1])/2+DKA[1],16,"  BANG DIEM LOP TIN CHI  ");
				inHangTieuDeNhapDiem(ytemp1,"STT","MA SO SINH VIEN","HO SINH VIEN","TEN SV","DIEM");
				f = -1; // stt loptc
				dsXem =-1;
				xoaBangNhapDiem(160);
				settextjustify(0,2);
				keHangNhap(yNhap,kc);
				int select = 1 ; 
				nienKhoaxem[0] = '\0';
				maMHxem[0] = '\0';
				nhomXem =-1;
				thaoTacNhapThongTin(select ,yNhap ,kc , nienKhoaxem ,maMHxem,hocKixem ,nhomXem ,dsXem ,Trang ,soTrang, list,dsLop,checkDS,root)	;	
//				if (dsLop != -1)
//				{
//					for (NodeDK *k = dsLop.lop[dsXem])
//				}
//				inBangThongBao()
			}
			if( x >= x1 - 100 && x < x1 +100 && y >= y1 -20 +kc && y <= y1 +20 +kc)//XEM DANH SACH SVDK
			{
				checkDS = true ;
				fDS=-1 ;
				inDamNutHCNDiem(DKA[1],60,DKA[6]-DKA[1],110,"",1);
				settextstyle(4,0,4);
				setbkcolor(1);
				setfillstyle(1,1);
				outtextxy((getmaxx()-textwidth("DANH SACH SINH VIEN DANG KI LTC")-DKA[1])/2+DKA[1],16,"DANH SACH SINH VIEN DANG KI LTC");
				f=-1 ; dsXem=-1;
				keHangNhap(yNhap,kc);
				keBangDSSV();
				inHangTieuDe(120);
				xoaBang(160);
				
				
				char nienKhoaDS[10]; nienKhoaDS[0] = '\0';
				char maMHDS[16];maMHDS[0] = '\0';
				int hocKiDS = 1;
				int nhomDS = -1 ;
				int select =1 ;
				thaoTacNhapThongTin(select ,yNhap ,kc , nienKhoaDS ,maMHDS,hocKiDS ,nhomDS ,fDS ,Trang ,soTrang, list,dsLop,checkDS,root);	
			}
		}
		delay(100);
	}
}


