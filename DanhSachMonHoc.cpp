#include"DanhSachMonHoc.h"
string tenNut[6]={"THEM",
	"XOA",
	"HIEU CHINH",
	"THOAT",
	"<",
	">"
};

string tenDeMuc[]={"STT",
	"MA MH",
	"TEN MON HOC",
	"STCLT",
	"STCTH"
};

int toaDoX[7]={0,300,400,500,1060,1210,1351};
int toaDoY[3]={0,100,687};

/*============================================================
	CAC THU TUC VA HAM XU LY CAC HOAT DONG NEN
============================================================= */

void Posorder_GiaiPhongVungNho(DSMH_AVL& p)
{  if(p != NULL)    
   {  Posorder_GiaiPhongVungNho(p->left);
      Posorder_GiaiPhongVungNho(p->right);
      delete p;
   }
}


void Initialize(DSMH_AVL& root) {
	root = NULL;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

DSMH_AVL newNode(MH& x) {
	DSMH_AVL node = new DanhSachMonHoc;
	node->monHoc = x;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

int height(DSMH_AVL p) {
	if (p == NULL) {
		return 0;
	}
	return p->height;
}


DSMH_AVL Rotate_Left(DSMH_AVL root) {
	DSMH_AVL p=NULL;
	if (root == NULL) {
		cout << "Khong the xoay trai vi cay bi rong" << endl;
	}
	else {
		if (root->right == NULL) {
			cout << "Khong the xoay trai vi khong co nut con ben phai" << endl;
		}
		else {
			p = root->right;
			root->right = p->left;
			p->left = root;
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	p->height = max(height(p->left), height(p->right)) + 1;
	return p;
}

DSMH_AVL Rotate_Right(DSMH_AVL ya) {
	DSMH_AVL s=NULL;
	if (ya == NULL) {
		cout << "Khong the xoay phai vi cay rong" << endl;
	}
	else {
		if (ya->left == NULL) {
			cout << "Khong the xoay phai vi khong co nut con ben trai" << endl;
		}
		else {
			s = ya->left;
			ya->left = s->right;
			s->right = ya;
		}
	}
	ya->height = max(height(ya->left), height(ya->right)) + 1;
	s->height = max(height(s->left), height(s->right)) + 1;
	return s;
}

int getBalance(DSMH_AVL p) {
	if (p == NULL) {
		return 0;
	}
	return height(p->left) - height(p->right);
}

DSMH_AVL Insert(DSMH_AVL node, MH x) {
	if (node == NULL) {
		return newNode(x);
	}
	if (soSanh2Chuoi(x.maMH, node->monHoc.maMH) < 0) {
		node->left = Insert(node->left, x);
	}
	else if (soSanh2Chuoi(x.maMH, node->monHoc.maMH) > 0) {
		node->right = Insert(node->right, x);
	}
	else {
		return node;
	}
	node->height = 1 + max(height(node->left),height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && soSanh2Chuoi(x.maMH, node->left->monHoc.maMH) < 0) {
		return Rotate_Right(node);
	}
	if (balance < -1 && soSanh2Chuoi(x.maMH, node->right->monHoc.maMH) > 0) {
		return Rotate_Left(node);
	}
	if (balance > 1 && soSanh2Chuoi(x.maMH, node->left->monHoc.maMH) >0) {
		node->left = Rotate_Left(node->left);
		return Rotate_Right(node);
	}
	if (balance < -1 && soSanh2Chuoi(x.maMH, node->right->monHoc.maMH) < 0) {
		node->right = Rotate_Right(node->right);
		return Rotate_Left(node);
	}

	return node;
}
// tim node co gia tri key nho nhat
DSMH_AVL minValueNode(DSMH_AVL node) {
	DSMH_AVL current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
DSMH_AVL Remove(DSMH_AVL &root, char x[]) {
	if (root == NULL)
		return root;
	if (soSanh2Chuoi(x, root->monHoc.maMH) < 0)
		root->left = Remove(root->left, x);
	else if (soSanh2Chuoi(x, root->monHoc.maMH) > 0)
		root->right = Remove(root->right, x);
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			DSMH_AVL temp = root->left;
			if (root->left == 0) {
				temp = root->right;
			}
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else {
				*root = *temp;// sao chep noi dung cua temp sang root
			}
			free(temp);
		}
		else {
			// truong hop co 2 node con
			DSMH_AVL temp = minValueNode(root->right);// tim node con the mang nho nhat ben phai
			root->monHoc = temp->monHoc; // doi info cua hai node
			root->right = Remove(root->right, temp->monHoc.maMH); // xoa nut con the mang
		}
	}
	if (root == NULL) {
		return root;
	}

	// cap nhat lai chieu cao
	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left)>=0) {
		return Rotate_Right(root);
	}
	if (balance >1 && getBalance(root->left)<0) {
		root->left = Rotate_Left(root->left);
		return Rotate_Right(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0) {
		return Rotate_Left(root);
	}
	if (balance < -1 && getBalance(root->right)>0) {
		root->right = Rotate_Right(root->right);
		return Rotate_Left(root);
	}

	return root;

}

void docFile1( DSMH_AVL& root) {
	int kt = 1;
	int n;
	ifstream fileIn;
	DSMH_AVL p;
	MonHoc x;
	fileIn.open("DanhSachMonHoc.txt", ios::in);
	fileIn >> n;
	for (int i = 0; i <n;i++) {
		fileIn.ignore();
		fileIn.getline(x.maMH, 11);
		fileIn.getline(x.tenMH, 51);
		fileIn >> x.STCLT;
		fileIn >> x.STCTH;
		fileIn >> x.slLop;
		root=Insert(root, x);
	}
	fileIn.close();
}

void ghiFileMH( DSMH_AVL& root,int n) {
	ofstream fileOut;
	const int STACKSIZE = 500;
   	DSMH_AVL Stack[STACKSIZE];
   	int sp=  -1;	// Khoi tao Stack rong
   	DSMH_AVL p=root;
	fileOut.open("DanhSachMonHoc.txt", ios::out);
	fileOut<<n<<endl;
  	 while (p!=NULL )
   	{      
		fileOut<<p->monHoc.maMH<<endl;
		fileOut<<p->monHoc.tenMH<<endl;
		fileOut<<p->monHoc.STCLT<<endl;
		fileOut<<p->monHoc.STCTH<<endl;
		fileOut<<p->monHoc.slLop<<endl;
      if (p->right != NULL)
			Stack[++sp]= p->right;
      if (p->left != NULL)
			p=p->left;
      else  if (sp==-1)
		    break;
	        else	p=Stack[sp--];
   	}
   	fileOut.close();
}

void Preorder(DSMH_AVL root,MANGMH &mang) // duyet cay kieu NLR dua du lieu sang mang mon hoc
{
	int i=0;
	if (root != NULL)
	{
		mang.n++;
		if(mang.n==1){
			mang.node[mang.n-1]=&root->monHoc;
		}else
			for(i=mang.n-2;i>=0;i--){
				if(soSanh2Chuoi(root->monHoc.tenMH,mang.node[i]->tenMH)<0){
					mang.node[i+1]=mang.node[i];
				}else{
					break;
				}
			}
		mang.node[i+1]=&root->monHoc;
		Preorder(root->left,mang);
		Preorder(root->right,mang);
	}
}

void timKiemTenMH(DSMH_AVL& root,char maMH1[],char tenMH1[]){
	DSMH_AVL p;
	p=root;
	tenMH1[0]='\0';
	while(p!=NULL){
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==0){
			for(int i=0;i<strlen(p->monHoc.tenMH);i++){
				tenMH1[i]=p->monHoc.tenMH[i];
				tenMH1[i+1]='\0';
			}
			return;
		}
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==-1){
			p=p->left;
			continue;
		}
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==1){
			p=p->right;
			continue;
		}
	}
}
void tangGiamLopTC_MH(DSMH_AVL& root,char maMH1[],bool kt){
	DSMH_AVL p;
	p=root;
	if(p==NULL){
		return;
	}
	while(p!=NULL){
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==0){
			if(kt==0){
				p->monHoc.slLop--;
			}else{
				p->monHoc.slLop++;
			}
			return;
		}
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==-1){
			p=p->left;
			continue;
		}
		if(soSanh2Chuoi(maMH1,p->monHoc.maMH)==1){
			p=p->right;
			continue;
		}
	}
}

/*============================================================
	CAC THU TUC VA HAM XU LY CAC HOAT DONG TREN MAN HINH
============================================================= */



void taoCacNutLenh(){
	int y= toaDoY[1]/2;
	for(int i=0;i<4;i++){
		taoNutHCN((toaDoX[1]-toaDoX[0])/2,y,200,40,tenNut[i].c_str());
		y+=khoangCachNut;
	}
}

void taoBang(){
	int y=toaDoY[1];
	int dem=1;
	setlinestyle(0,0,2);
	while(dem<=11){
		if(dem%2!=0){
			setfillstyle(1,mauBang1);
		}else{
		setfillstyle(1,mauBang2);
		}
		bar(toaDoX[1],y,toaDoX[6],y+khoangCachDong);
		line(toaDoX[1],y,toaDoX[6],y);
		y+=khoangCachDong;
		dem++;
	}
	line(toaDoX[1],y,toaDoX[6],y);
	setbkcolor(mauBang1);
	settextstyle(10,0,2);
	settextjustify(1,1);
	for(int i=0;i<5;i++){
		outtextxy((toaDoX[i+2]-toaDoX[i+1])/2+toaDoX[i+1],toaDoY[1]+20,tenDeMuc[i].c_str());
	}
	for(int i=1;i<7;i++){
		line(toaDoX[i],toaDoY[1],toaDoX[i],y);
	}
	y+=khoangCachDong;
	taoNutHCN(toaDoX[1]+50,y,40,40,tenNut[4].c_str());
	taoNutHCN(toaDoX[6]-50,y,40,40,tenNut[5].c_str());
}

void diChuyenChuot(int x,int y,int& xCu,int &yCu,int &vt){
	int xSS=(toaDoX[1]-toaDoX[0])/2;
	int ySS= toaDoY[1]/2;
	for(int i=0;i<4;i++){
		if(x<=xSS+100&&x>=xSS-100&&y>=ySS+khoangCachNut*i-30&&y<=ySS+khoangCachNut*i+10){
			if(vt==i){
				return;
			}
				inDamNutHCN(xSS,ySS+khoangCachNut*i,200,40,tenNut[i].c_str(),4);
				if(vt!=-1){
					if(vt<4){
						taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
					} else {
						taoNutHCN(xCu,yCu,40,40,tenNut[vt].c_str());
					}
				}
				xCu=xSS;
				yCu=ySS+khoangCachNut*i;
				vt=i;
			return;	
		}
	}
	if(x<=toaDoX[1]+50+20&&x>=toaDoX[1]+50-20&&y>=toaDoY[1]+12*khoangCachDong-30&&y<=toaDoY[1]+12*khoangCachDong+10){
		if(vt==4){
			return;
			}
		inDamNutHCN(toaDoX[1]+50,toaDoY[1]+12*khoangCachDong,40,40,tenNut[4].c_str(),4);
		if(vt!=-1){
			if(vt<4){
				taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
			} else {
				taoNutHCN(xCu,yCu,40,40,tenNut[vt].c_str());
			}
		}
		xCu=toaDoX[1]+50;
		yCu=toaDoY[1]+12*khoangCachDong;
		vt=4;
		return;	
	}
	if(x<=toaDoX[6]-50+20&&x>=toaDoX[6]-50-20&&y>=toaDoY[1]+12*khoangCachDong-30&&y<=toaDoY[1]+12*khoangCachDong+10){
		if(vt==5){
			return;
		}
		inDamNutHCN(toaDoX[6]-50,toaDoY[1]+12*khoangCachDong,40,40,tenNut[5].c_str(),4);
		if(vt!=-1){
			if(vt<4){
				taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
			} else {
				taoNutHCN(xCu,yCu,40,40,tenNut[vt].c_str());
				}
		}
		xCu=toaDoX[6]-50;
		yCu=toaDoY[1]+12*khoangCachDong;
		vt=5;
		return;	
	}
	if(vt!=-1){
		if(vt<4){
			taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
		} else {
			taoNutHCN(xCu,yCu,40,40,tenNut[vt].c_str());
		}
		vt=-1;
	}
}

void xuat1MonHoc(MH x,int y, int stt,int mau){
	char s[5];
	setbkcolor(mau);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	settextjustify(1,1);
	doiSosangChuoi(stt,s);
	bar(toaDoX[1]+5,y-15,toaDoX[2]-5,y+15);
	outtextxy((toaDoX[2]-toaDoX[1])/2+toaDoX[1],y,s);
	bar(toaDoX[2]+5,y-15,toaDoX[3]-5,y+15);
	outtextxy((toaDoX[3]-toaDoX[2])/2+toaDoX[2],y,x.maMH);
	settextjustify(0,1);
	bar(toaDoX[3]+5,y-15,toaDoX[4]-5,y+15);
	outtextxy(toaDoX[3]+20,y,x.tenMH);
	settextjustify(1,1);
	doiSosangChuoi(x.STCLT,s);
	bar(toaDoX[4]+5,y-15,toaDoX[5]-5,y+15);
	outtextxy((toaDoX[5]-toaDoX[4])/2+toaDoX[4],y,s);
	doiSosangChuoi(x.STCTH,s);
	bar(toaDoX[5]+5,y-15,toaDoX[6]-5,y+15);
	outtextxy((toaDoX[6]-toaDoX[5])/2+toaDoX[5],y,s);
	
}

void xuatMonHocTheoTrang(int trangHienTai, int tongSoTrang, MANGMH mang){
	string s1=ghepSoTrang(trangHienTai,tongSoTrang);
	setbkcolor(1);
	settextstyle(4,0,2);
	settextjustify(1,1);
	outtextxy((toaDoX[6]-toaDoX[1])/2+toaDoX[1],toaDoY[1]+12*khoangCachDong,s1.c_str());
	int stt=0;
	stt=(trangHienTai-1)*10+1;
	int dem=1;
	int y=toaDoY[1]+khoangCachDong+khoangCachDong/2;
	while(dem<=10&&stt<=mang.n){
		if(dem%2==0){
			xuat1MonHoc(*mang.node[stt-1],y,stt,mauBang1);
		}else{
			xuat1MonHoc(*mang.node[stt-1],y,stt,mauBang2);
		}
		
		y+=khoangCachDong;
		stt++;
		dem++;
	}
}

void inDamDong(int y, int mau){
	setfillstyle(1,mau);
	bar(toaDoX[1],y,toaDoX[6],y+khoangCachDong);
	line(toaDoX[1],y,toaDoX[6],y);
	line(toaDoX[1],y+khoangCachDong,toaDoX[6],y+khoangCachDong);
	for(int i=1;i<7;i++){
		line(toaDoX[i],y,toaDoX[i],y+khoangCachDong);
	}
}
bool kiemTraTrungMH(char maMH[],DSMH_AVL &root){
	DSMH_AVL p=root;
	while(p!=NULL){
		if(soSanh2Chuoi(maMH,p->monHoc.maMH)==0){
			return 1;
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
	return 0;
}


int nhap1MonHoc(int &trangHienTai,int &tongSoTrang,MANGMH &mang,DSMH_AVL &root){
	int y=toaDoY[1]+khoangCachDong+khoangCachDong/2;
	int kt=1;
	MH *x=new MH;
	if(mang.n+1>tongSoTrang*10){
		tongSoTrang++;
	}
	trangHienTai=tongSoTrang;
	taoBang();
	xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
		x->maMH[0]='\0';
		x->tenMH[0]='\0';
		x->STCLT=-1;
		x->STCTH=-1;
		int stt=mang.n+1;
		char s[10];
		y+=((mang.n)%10)*khoangCachDong;
		setbkcolor(mauBang3);
		inDamDong(y-khoangCachDong/2,mauBang3);
		doiSosangChuoi(stt,s);
		settextstyle(2,0,5);
		settextjustify(1,1);
		outtextxy((toaDoX[2]-toaDoX[1])/2+toaDoX[1],y,s);
		while(kt!=6){
			setbkcolor(mauBang3);
			switch(kt){
				case 0:{
					taoBang();
					xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
					return 0;
				};
				case 1:{
					thaoTacNhapMa(toaDoX[2]+20,y,10,x->maMH,kt);
					break;
				}
				case 2:{
					thaoTacNhap(toaDoX[3]+20,y,50,x->tenMH,kt);
					break;
				}
				case 3:{
					thaoTacNhapSo((toaDoX[5]-toaDoX[4])/2+toaDoX[4]-10,y,x->STCLT,kt);
					break;
				}
				case 4:{
					thaoTacNhapSo((toaDoX[6]-toaDoX[5])/2+toaDoX[5]-10,y,x->STCTH,kt);
					break;
				}
				case 5:{
					if(x->maMH[0]=='\0'){
						kt=1;
					}else
					if(kiemTraTrungMH(x->maMH,root)){
						inBangThongBao("-Ma mon hoc","da ton tai.","-Hay nhap lai.","","");
						delay(2000);
						inBangThongBao("","","","","");
						kt=1;
					} else
					if(x->tenMH[0]=='\0'){
						kt=2;
					} else
					if(x->STCLT==-1){
						kt=3;
					} else
					if(x->STCTH==-1){
						kt=4;
					} else{
						kt=6;
					}
					break;
				}
			}
		}
		mang.n=0;
		root=Insert(root,*x);
		Preorder(root,mang);
		return 1;
}

void nhapMonHoc(int &trangHienTai,int &tongSoTrang,MANGMH &mang,DSMH_AVL &root){
	int n=1;
	while(n==1){
		n=nhap1MonHoc(trangHienTai,tongSoTrang,mang,root);
		if(mang.n%10==0){
			tongSoTrang=mang.n/10;
		}else{
			tongSoTrang=mang.n/10+1;
		}
		trangHienTai=tongSoTrang;
		taoBang();
		xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
	}
}

int chonMonHoc(int vt, int &vtCu, int &trangHienTai,MANGMH &mang){
	if(vt+(trangHienTai-1)*10>mang.n||mang.n==0){
		return 0;
	}
	if(vt==vtCu){
		if(ismouseclick(WM_LBUTTONDOWN)){
		inDamDong(toaDoY[1]+vt*khoangCachDong,10);
		xuat1MonHoc(*mang.node[vt+(trangHienTai-1)*10-1],toaDoY[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
		inBangThongBao("Bam XOA de xoa.","Bam HIEU CHINH","de hieu chinh","-Bam THOAT de","thoat che do.");
		clearmouseclick(WM_LBUTTONDOWN);
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
	if(ismouseclick(WM_LBUTTONDOWN)){
			inDamDong(toaDoY[1]+vt*khoangCachDong,10);
			xuat1MonHoc(*mang.node[vt+(trangHienTai-1)*10-1],toaDoY[1]+vt*khoangCachDong+khoangCachDong/2,vt+(trangHienTai-1)*10,10);
			inBangThongBao("Bam XOA de xoa.","Bam HIEU CHINH","de hieu chinh","-Bam THOAT de","thoat che do.");
			clearmouseclick(WM_LBUTTONDOWN);
		return vt+(trangHienTai-1)*10;
	}
	return 0;
}




void thaoTacXoa(int &stt, MANGMH & mang,DSMH_AVL &root){
	int x= xThongBao;
	int y=yThongBao+6*khoangCachDong;
	int vt=-1;
	int xCu=-1;
	int yCu=-1;
	int xChuot=-1;
	int yChuot=-1;
	inBangThongBao("-Ban chac chan","xoa mon hoc", "nay?","","");
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
			//	delete1MHtrongMang(mang,stt-1);
				if(mang.node[stt-1]->slLop>0){
					inBangThongBao("-Mon hoc",mang.node[stt-1]->maMH,"da co lop hoc","hoat dong.","");
					delay(2000);
					inBangThongBao("","","","","");
					stt=0;
					clearmouseclick(WM_LBUTTONDOWN);
					break;
				}
				Remove(root,mang.node[stt-1]->maMH);
				mang.n=0;
				Preorder(root,mang);
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
void hieuChinh1MonHoc(int &stt, int trangHienTai,int tongSoTrang,MANGMH &mang,DSMH_AVL &root){
	int y=toaDoY[1]+khoangCachDong+khoangCachDong/2;
	int kt=1;
	MH x=*mang.node[stt-1];
	root=Remove(root,x.maMH);
	y+=((stt-1)%10)*khoangCachDong;
	setbkcolor(mauBang3);
	inDamDong(y-khoangCachDong/2,mauBang3);
	xuat1MonHoc(x,y,stt,mauBang3);
	settextstyle(2,0,5);
	settextjustify(1,1);
	while(kt!=6){
		switch(kt){
			case 0:{
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				kt=6;
				break;
			};
			case 1:{
				bar(toaDoX[2]+5,y-15,toaDoX[3]-5,y+15);
				thaoTacNhapMa(toaDoX[2]+20,y,10,x.maMH,kt);
				break;
			}
			case 2:{
				bar(toaDoX[3]+5,y-15,toaDoX[4]-5,y+15);
				thaoTacNhap(toaDoX[3]+20,y,50,x.tenMH,kt);
				break;
			}
			case 3:{
				bar(toaDoX[4]+5,y-15,toaDoX[5]-5,y+15);
				thaoTacNhapSo((toaDoX[5]-toaDoX[4])/2+toaDoX[4]-10,y,x.STCLT,kt);
				break;
			}
			case 4:{
				bar(toaDoX[5]+5,y-15,toaDoX[6]-5,y+15);
				thaoTacNhapSo((toaDoX[6]-toaDoX[5])/2+toaDoX[5]-10,y,x.STCTH,kt);
				break;
			}
			case 5:{
				if(x.maMH[0]=='\0'){
					kt=1;
				} else
				if(x.tenMH[0]=='\0'){
					kt=2;
				} else
				if(x.STCLT==-1){
					kt=3;
				} else
				if(x.STCTH==-1){
					kt=4;
				} else{
					kt=6;
				}
				break;
			}
		}
	}
	mang.n=0;
	root=Insert(root,x);
	Preorder(root,mang);
	stt=0;
}

void manHinhMonHoc(DSMH_AVL root){
	
	MANGMH mang;
	int xChuot,yChuot;
	int xCu=0;
	int yCu=0;
	int vt=-1;
	int vtBang=-1;
	int vtBang1=0;
	int stt=0;
	Preorder(root,mang);
	int tongSoTrang=mang.n/10;
	int trangHienTai=0;
	if(tongSoTrang>0){
		trangHienTai=1;
	}
	if(mang.n%10!=0){
		tongSoTrang=tongSoTrang+1;
	}
	setbkcolor(1);
	cleardevice();
	settextstyle(4,0,4);
	settextjustify(1,1);
	outtextxy((getmaxx()-toaDoX[1])/2+toaDoX[1],42," DANH SACH MON HOC");
	taoCacNutLenh();
	taoBang();
	xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
	inBangThongBao("-Ban dang lam","viec voi","danh sach","mon hoc.","^-^");
	while(true){
		if(kbhit()){
			char nhiemVuChongBug=getch();
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,xChuot,yChuot);
			diChuyenChuot(xChuot,yChuot,xCu,yCu,vt);
			layViTriChuotTrenBang(xChuot,yChuot,(toaDoX[6]-toaDoX[1])/2+toaDoX[1],toaDoY[1],vtBang1);
		}
		if(stt==0){
			stt=chonMonHoc(vtBang1,vtBang,trangHienTai,mang);
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			if(vt==0&&stt==0){
				inDamNutHCN(xCu,yCu,200,40,tenNut[vt].c_str(),10);
				inBangThongBao("-Ma MH 10 ki tu.","-Ten MH 50 ki tu.","-Nhan ESC de","thoat che do.","");
				nhapMonHoc(trangHienTai,tongSoTrang,mang,root);
				taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
				inBangThongBao("-Ban dang lam","viec voi","danh sach","mon hoc.","^-^");
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==1&&stt!=0){
				inDamNutHCN(xCu,yCu,200,40,tenNut[vt].c_str(),10);
				clearmouseclick(WM_LBUTTONDOWN);
				thaoTacXoa(stt,mang,root);
				//Preorder(root,mang);
				inBangThongBao("-Ban dang lam","viec voi","danh sach","mon hoc.","^-^");
				if(mang.n%10!=0){
					tongSoTrang=mang.n/10+1;
				}else{
					tongSoTrang=mang.n/10;
				}	
				if(trangHienTai>tongSoTrang){
					trangHienTai=tongSoTrang;
				}
				xoaNutDongY_Huy();
				if(stt==0){
					taoBang();
					xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
					vtBang=-1;
				}else{
					inDamDong(toaDoY[1]+vtBang*khoangCachDong,(vtBang%2==0)?mauBang1:mauBang2);
					xuat1MonHoc(*mang.node[vtBang+(trangHienTai-1)*10-1],toaDoY[1]+vtBang*khoangCachDong+khoangCachDong/2,vtBang+(trangHienTai-1)*10,(vtBang%2==0)?mauBang1:mauBang2);
					vtBang=-1;
					stt=0;
				}
				taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
				continue;
			}
			if(vt==2&&stt!=0){
				inDamNutHCN(xCu,yCu,200,40,tenNut[vt].c_str(),10);
				hieuChinh1MonHoc(stt,trangHienTai,tongSoTrang,mang,root);
				taoNutHCN(xCu,yCu,200,40,tenNut[vt].c_str());
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==3){
				if(stt!=0){
					inDamDong(toaDoY[1]+vtBang*khoangCachDong,(vtBang%2==0)?mauBang1:mauBang2);
					xuat1MonHoc(*mang.node[vtBang+(trangHienTai-1)*10-1],toaDoY[1]+vtBang*khoangCachDong+khoangCachDong/2,vtBang+(trangHienTai-1)*10,(vtBang%2==0)?mauBang1:mauBang2);
					vtBang=-1;
					stt=0;
					clearmouseclick(WM_LBUTTONDOWN);
				}else{
					ghiFileMH(root,mang.n);
					clearmouseclick(WM_LBUTTONDOWN);
					return;
				}
			}
			if(vt==5&&trangHienTai<tongSoTrang&&stt==0){
				trangHienTai++;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==4&&trangHienTai>1&&stt==0){
				trangHienTai--;
				taoBang();
				xuatMonHocTheoTrang(trangHienTai,tongSoTrang,mang);
			//	stt=0;
				clearmouseclick(WM_LBUTTONDOWN);
				continue;
			}
			if(vt==-1&&stt!=0){
				clearmouseclick(WM_LBUTTONDOWN);
			}	
			clearmouseclick(WM_LBUTTONDOWN);
		}
	
	
		delay(100);
	}
}


