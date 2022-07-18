#include"tongHop.h"

string tenNutMHC[7]={
	"DANH SACH MON HOC",
	"DANH SACH LOP TIN CHI",
	"DANH SACH SINH VIEN",
	"DANG KI",
	"NHAP DIEM",
	"THONG KE",
	"THOAT"
};
void diChuyenChuotMHC(int xMax,int ySS,int x,int y,int& xCu,int &yCu,int &vt){
	for(int i=0;i<3;i++){
		if(x<=xMax/3+150&&x>=xMax/3-150&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xMax/3,ySS+khoangCachNut*i,300,40,tenNutMHC[i].c_str(),4);
				if(vt!=-1){
					taoNutHCN(xCu,yCu,300,40,tenNutMHC[vt].c_str());
				}
				xCu=xMax/3;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
		if(x<=xMax*2/3+150&&x>=xMax*2/3-150&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i+3){
				return;
			}
				inDamNutHCN(xMax*2/3,ySS+khoangCachNut*i,300,40,tenNutMHC[i+3].c_str(),4);
				if(vt!=-1){
					taoNutHCN(xCu,yCu,300,40,tenNutMHC[vt].c_str());
				}
				xCu=xMax*2/3;
				yCu=ySS+khoangCachNut*i;
				vt=i+3;
			return;	
		}
	}
	if(x<=xMax/2+150&&x>=xMax/2-150&&y>=ySS+khoangCachNut*3-30&&y<=ySS+khoangCachNut*3+10){
			if(vt==6){
				return;
			}
				inDamNutHCN(xMax/2,ySS+khoangCachNut*3,300,40,tenNutMHC[6].c_str(),4);
				if(vt!=-1){
					taoNutHCN(xCu,yCu,300,40,tenNutMHC[vt].c_str());
				}
				xCu=xMax/2;
				yCu=ySS+khoangCachNut*3;
				vt=6;
			return;	
		}
	if(vt!=-1){
		taoNutHCN(xCu,yCu,300,40,tenNutMHC[vt].c_str());
		vt=-1;
	}
}

void manHinhChinh(DSMH_AVL& root,DSLTC&dsLop,DanhSach &list){
	int x=0, y=0;
	int y1=350;
	int xCu=-1;
	int yCu=-1;
	int vt=-1;
	setbkcolor(1);	
	cleardevice();
	settextjustify(1,1)	;		
	setcolor(0);// mau ve
	setfillstyle(1,15); // kieu to va mau to	
    settextstyle(4,0,6);
    outtextxy(getmaxx()/2,64,"QUAN LI DIEM SINH VIEN");
    settextstyle(4,0,3);
    outtextxy(getmaxx()/2,120,"theo he TIN CHI");
    settextstyle(10,0,2);
    outtextxy(getmaxx()/2,170,">>> HOC VIEN CONG NGHE BUU CHINH VIEN THONG <<<");
    outtextxy(getmaxx()/2,220,"Giang Vien: Luu Nguyen Ky Thu.");
    //========================================================
    for(int i=0;i<3;i++){
    	taoNutHCN(getmaxx()/3,y1,300,40,tenNutMHC[i].c_str());
    	taoNutHCN(getmaxx()*2/3,y1,300,40,tenNutMHC[i+3].c_str());
    	y1+=khoangCachNut;
	}
	taoNutHCN(getmaxx()/2,y1,300,40,tenNutMHC[6].c_str());
	while(true) {
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			diChuyenChuotMHC(getmaxx(),350,x,y,xCu,yCu,vt);	
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhMonHoc(root);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==1){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhLopTinChi(root,dsLop);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==2){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhDSSV(list);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==3){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhDangKi(root,dsLop,list);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==4){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhNhapDiem(list,dsLop,root);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==5){
				clearmouseclick(WM_LBUTTONDOWN);
				manHinhThongKe(root,dsLop,list);
				manHinhChinh(root,dsLop,list);
				continue;
			}
			if(vt==6){
				Posorder_GiaiPhongVungNho(root);
				xoaBoNho(dsLop);
				giaiPhongVungNho(list);
				clearmouseclick(WM_LBUTTONDOWN);
				return;
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(100);
	}
}


