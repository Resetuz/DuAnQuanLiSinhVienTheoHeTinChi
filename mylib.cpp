#include"mylib.h"




void taoNutHCN(int x, int y , int chieuDai, int chieuRong,const char*s){
	setfillstyle(1,15);
	setbkcolor(15);
	bar(x-chieuDai/2,y-chieuRong/2-10,x+chieuDai/2,y+chieuRong/2-10);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy(x,y-5,s);
}

//void inThongTin(int x, int y , int chieuDai, int chieuRong,const char*s){
//	setfillstyle(1,15);
//	setbkcolor(15);
//	bar(x-chieuDai/2,y-chieuRong/2-10,x+chieuDai/2,y+chieuRong/2-10);
//	settextstyle(2,0,5);
//	settextjustify(1,1);
//	outtextxy(x,y-5,s);
//}

void inDamNutHCN(int x, int y , int chieuDai, int chieuRong,const char*s,int mau){
	setfillstyle(1,mau);
	setbkcolor(mau);
	bar(x-chieuDai/2,y-chieuRong/2-10,x+chieuDai/2,y+chieuRong/2-10);
	settextstyle(10,0,2);
	settextjustify(1,1);
	outtextxy(x,y-5,s);
}

void inBangThongBao(const char*s1,const char*s2,const char*s3,const char*s4,const char*s5){
	int x=xThongBao;
	int y=yThongBao;
	inDamNutHCN(x,y,280,40,"THONG BAO!",12);
	y+=khoangCachDong;
	taoNutHCN(x,y,280,40,s1);
	y+=khoangCachDong;
	taoNutHCN(x,y,280,40,s2);
	y+=khoangCachDong;
	taoNutHCN(x,y,280,40,s3);
	y+=khoangCachDong;
	taoNutHCN(x,y,280,40,s4);
	y+=khoangCachDong;
	taoNutHCN(x,y,280,40,s5);
}

void daoChieu(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
 
void doiSosangChuoi(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     daoChieu(s);
 }
int soSanh2Chuoi(char s1[], char s2[]) {
	int kt = 0;
	int chieuDai = strlen(s1);
	if (strlen(s1) > strlen(s2)) {
		kt = 1;
		chieuDai = strlen(s2);
	}
	if(strlen(s1) < strlen(s2)) {
		kt = -1;
		chieuDai = strlen(s1);
	}
	for (int i = 0; i < chieuDai; i++) {
		if (s1[i] < s2[i]) {
			return -1;
		}
		if(s1[i] > s2[i]) {
			return 1;
		}
	}
	return kt;
}
 
string ghepSoTrang(int trangHienTai, int tongSoTrang){
 	char s[5];
	string s1="";
	int count=0;
	doiSosangChuoi(trangHienTai,s);
	for(int i=0;i<strlen(s);i++){
		s1+=s[i];
	}
	s1+='/';
	count++;
	doiSosangChuoi(tongSoTrang,s);
	for(int i=0;i<strlen(s);i++){
		s1+=s[i];
	}
//	s1[count]='\0';
	return s1;
 }
 
void thaoTacNhap(int x,int y,int max, char s[], int &kt){
	settextstyle(2, 0, 5);
	settextjustify(0,1);
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
		//	cout << (int)c[0]<<" "<<textwidth(c)<<endl;
			if (c[0] == 8 && i > 0) {
				x-=textwidth(&s[i-1]);
				s[i-1]='\0';
                i--;
                outtextxy(x, y ,"   ");
            }
			if(i==max){
				continue;
			}
			if(c[0]==75&&kt>1){
            	s[i] = '\0';
            	kt--;
            	break;
			}
			if(c[0]==75&&kt==1){
				s[i] = '\0';
            	kt=4;
            	break;
			}

			if (c[0]==77&&kt<4) {
				s[i] = '\0';
				kt++;
				break;
			}
			if(c[0]==77&&kt==4)	{
				s[i] = '\0';
            	kt=1;
            	break;
			}
			if (c[0] == 13&&i>0 ) {
				if(s[i-1]==' '){
					s[i-1] = '\0';
				}else
				s[i] = '\0';
				kt=5;
				break;
			}
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=5;
				break;
			}
			if (c[0] >= 48 && c[0] <= 57) {
				s[i] = c[0];
				s[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0]==' ') {
				if(i>0||s[i-1]!=' '&&i>0){
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
				}
			}
			if (c[0] >= 'A' && c[0] <= 'Z') {
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
            delay(100);
		} else{
			settextstyle(4, 0, 1);
			outtextxy(x+3, y , "|");
			delay(500);
			outtextxy(x+3, y , " ");
			delay(200);
		}
	}
	settextjustify(1,1);
}

void thaoTacNhapMa(int x,int y,int max, char s[], int &kt){
	settextstyle(2, 0, 5);
	settextjustify(0,1);
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
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=5;
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
			if (c[0] == '-') {
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
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				s[i] = c[0];
				s[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}
            delay(100);
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

void doiKiTuSangSo(char s[],int &x){
	if(s[0]=='\0'){
		return;
	}
	int i=strlen(s)-1;
	int dem=1;
	x=0;
	for(i;i>=0;i--){
		x+=(s[i]-'0')*dem;
		dem=dem*10;
	}
}

void thaoTacNhapSo(int x,int y,int &so,int &kt ){
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
			cout << textwidth(s)<<"==="<<textwidth(&c[0])<<endl;
			if(c[0]==27){
				kt=0;
				return;
			}
			if(c[0]==75&&kt>1){
            	s[i] = '\0';
            	kt--;
            	break;
			}
			if(c[0]==75&&kt==1){
				s[i] = '\0';
            	kt=4;
            	break;
			}

			if (c[0]==77&&kt<4) {
				s[i] = '\0';
				kt++;
				break;
			}
			if(c[0]==77&&kt==4){
				s[i] = '\0';
            	kt=1;
            	break;
			}
			if (c[0] == 8 && i > 0) {
				x-=textwidth(&s[i-1]);
				s[i-1]='\0';
                i--;
                outtextxy(x, y ,"   ");
            }
			if(i==10){
				continue;
			}
			
			if (c[0] == 13&&i>0 ) {
				s[i] = '\0';
				kt=5;
				break;
			}
			if (c[0] >= '0' && c[0] <= '9' ) {
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

void layViTriChuotTrenBang(int x,int y,int xSS,int ySS, int &vt){

	int chieuDai=xBang;
	int chieuRong=khoangCachDong;
	for(int i=1;i<11;i++){
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

void chonNutDongY_Huy(int x,int y, int&xCu, int& yCu, int &vt){
	int xSS=xThongBao;
	int ySS=yThongBao+7*khoangCachDong;
	if(x<=xSS+140&&x>=xSS-140&&y>=ySS-khoangCachDong-30&&y<=ySS-khoangCachDong+10){
		if(vt!=0){
			inDamNutHCN(xSS,ySS-khoangCachDong,280,40,"DONG Y",4);
		}
		if(vt==1){
			inDamNutHCN(xCu,yCu,280,40,"HUY",12);
		}
		xCu=xSS;
		yCu=ySS-khoangCachDong;
		vt=0;
		return;
	}
	if(x<=xSS+140&&x>=xSS-140&&y>=ySS-30&&y<=ySS+10){
		if(vt!=1){
			inDamNutHCN(xSS,ySS,280,40,"HUY",4);
		}
		if(vt==0){
			inDamNutHCN(xCu,yCu,280,40,"DONG Y",10);
		}
		xCu=xSS;
		yCu=ySS;
		vt=1;
		return;
	}
	if(vt==0){
		inDamNutHCN(xCu,yCu,280,40,"DONG Y",10);
		vt=-1;
		return;
	}
	if(vt==1){
		inDamNutHCN(xCu,yCu,280,40,"HUY",12);
		vt=-1;
		return;
	}
}

void xoaNutDongY_Huy(){
	int x=xThongBao;
	int y=yThongBao+6*khoangCachDong;
	inDamNutHCN(x,y,280,40,"",1);
	y+=khoangCachDong;
	inDamNutHCN(x,y,280,40,"",1);
}

