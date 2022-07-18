#include"DanhSachSinhVien.h"
 int A[8]={0,350,410,600,860,1000,1150,1340};
 int B[3]={60,120,687};
//int n = 0;
void KhoiTao(DanhSach &list)
{
	list.head = NULL;
	list.tail = NULL;
}
Node *KhoiTaoNode(SinhVien sv)
{
	Node *p = new Node; // cap phat vung nho cho Node p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!!\n";
		return NULL;
	}
	p->data = sv; //truyen gia tri sv vao cho data
	p->next = NULL;//chua co lien ket => tro den NULL
	return p; //Tra ve Node p vua khoi tao
}
void themVaoCuoi (DanhSach &list , Node *p)
{
		if (list.head == NULL) // danh sach rong~
		{
			list.head = list.tail = p;// node dau trung` node cuoi = p
		}	
		else 
		{
			list.tail->next = p ;// cho con tro cua tail lien ket voi p
			list.tail = p ;// cap nhat lai tail la p moi them  vao
		}
}
void chuyen(string s , char *temp)
{
	for (int i = 0 ; i < s.length();i++)
	{
	temp[i] = s[i] ;
	}
	temp[s.length()] =0 ;
}
void chuyensangString(string &s , char *temp)
{
	s = "";
	int x = 0 ;
	while (temp[x] != 0)
	{
		s += temp[x];
		x++;
	}
}
void Doc_file_1_SV(ifstream &fileIn , SinhVien &sv)
{
	getline(fileIn , sv.MaSV , ',');
	getline(fileIn , sv.Ho, ',');
	getline(fileIn , sv.Ten, ',');
	getline(fileIn , sv.Phai , ',');
	getline(fileIn , sv.SoDT , ',');
	getline(fileIn , sv.MaLop , ',');
	fileIn >> sv.slDK ;
	fileIn.ignore();
}

void Doc_FILE_DSSV( DanhSach &list )
{
	ifstream fileIn ;
	fileIn.open("DSSV.txt",ios::in);
	while (!fileIn.eof() )
	{
	SinhVien sv ;
	Doc_file_1_SV(fileIn , sv);
	if (sv.MaSV == "") break;
	Node *p = KhoiTaoNode (sv);
	themVaoCuoi(list ,p);
	}
	fileIn.close();
}

void themVaoDau (DanhSach &list , Node *p)
{
		if (list.head == NULL) // danh sach rong~
		{
			list.head = list.tail = p;// node dau trung` node cuoi = p
		}	
		else 
		{
			p->next = list.head;// cho con tro cua Node can them la p lien ket den head
			list.head = p ;// cap nhat lai head la p moi them  vao
		}
}

void xoaBang (int ytemp)
{
	for(int i = 1 ; i <= 10 ; i++)// xoa Bang Danh Sach
	{
								
		if (i % 2 == 0 )
			{
				setfillstyle(1,9);
				setbkcolor(9);
				bar (A[1] + 1,ytemp +(i - 1)*40 + 1 ,A[2] - 1, ytemp + 40*i- 1);
				bar (A[2] + 1,ytemp +(i - 1)*40 + 1 ,A[3] - 1, ytemp + 40*i- 1);
				bar (A[3] + 1,ytemp +(i - 1)*40 + 1 ,A[4] - 1, ytemp + 40*i- 1);
				bar (A[4] + 1,ytemp +(i - 1)*40 + 1 ,A[5] - 1, ytemp + 40*i- 1);
				bar (A[5] + 1,ytemp +(i - 1)*40 + 1 ,A[6] - 1, ytemp + 40*i- 1);
				bar (A[6] + 1,ytemp +(i - 1)*40 + 1 ,A[7] - 1, ytemp + 40*i- 1);
			}
		else 
			{
				setfillstyle(1,15);
    			setbkcolor(15);
				bar (A[1] + 1,ytemp +(i - 1)*40 + 1 ,A[2] - 1, ytemp + 40*i- 1);
				bar (A[2] + 1,ytemp +(i - 1)*40 + 1 ,A[3] - 1, ytemp + 40*i- 1);
				bar (A[3] + 1,ytemp +(i - 1)*40 + 1 ,A[4] - 1, ytemp + 40*i- 1);
				bar (A[4] + 1,ytemp +(i - 1)*40 + 1 ,A[5] - 1, ytemp + 40*i- 1);
				bar (A[5] + 1,ytemp +(i - 1)*40 + 1 ,A[6] - 1, ytemp + 40*i- 1);
				bar (A[6] + 1,ytemp +(i - 1)*40 + 1 ,A[7] - 1, ytemp + 40*i- 1);
			}
		}
	
}

void XuatDS(DanhSach &list, char *maLOP , int Trang , int soTrang )
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
	for (Node *k = list.head ; k != NULL ; k = k->next)
	{
		chuyen(k->data.MaLop ,tempXuat);
		if(strcmp (maLOP, tempXuat) == 0 && k->data.MaSV != " ")
		{
			dem++ ;
			if (dem >= i && dem <= Trang*10 )
			{
				if (dem %2 != 0)
				{
				setbkcolor(15);
				itoa(dem, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+8,STTstr);
				chuyen(k->data.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1+8,tempXuat);
				chuyen(k->data.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+8,tempXuat);
				chuyen(k->data.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+8,tempXuat);
				chuyen(k->data.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+8,tempXuat);
				chuyen(k->data.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+8,tempXuat);
				Y1+=40;
				}
				else 
				{
				setbkcolor(9);
				itoa(dem, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+8,STTstr);
				chuyen(k->data.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1+8,tempXuat);
				chuyen(k->data.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+8,tempXuat);
				chuyen(k->data.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+8,tempXuat);
				chuyen(k->data.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+8,tempXuat);
				chuyen(k->data.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+8,tempXuat);
				Y1+=40;
				}
			}
		}
	}
	setbkcolor (1);
	settextstyle(3,0,1);
	itoa(Trang , TrangStr ,10);
	itoa (soTrang ,soTrangStr , 10);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2 , yTrang - 10 , TrangStr);
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) , yTrang - 10 , "/");	
	outtextxy(860 - textwidth(TrangStr) - textwidth("/") -  textwidth(soTrangStr) /2  + textwidth(TrangStr) + textwidth("/"), yTrang - 10 , soTrangStr);	
}
void xoaToDamButton(int &xLight , int &yLight , const char *sButton,int &chuyen )
{
	if (chuyen == 0)
					{
						chuyen = 1;
					if (xLight != -1 && yLight != -1)
					{
						settextjustify(0,2);
						setbkcolor(15);
						setfillstyle(1,15);
						settextstyle(10,0,2);
						bar(xLight-100,yLight-20,xLight+100,yLight+20);
						outtextxy((xLight*2-textwidth(sButton))/2,yLight-10,sButton);
						inBangThongBao("","","","","");
						xLight =-1 , yLight =-1;
					}
	}
}
void XoaDau(DanhSach &list){
    //tao node p
    Node *p = new Node;
    //gan p bang node pHead dau tien cua danh sach 
    p = list.head;
    //thay doi lai pHead cua danh sach
    list.head = list.head->next;
    //gan node p ban dau tro den NULL
    p->next = NULL;
    //xoa node p
    delete p;
}
void XoaCuoi(DanhSach &list)
{
    //duyet cac phan tu co trong danh sach
    for(Node *k = list.head; k != NULL; k = k ->next)
    {
        //neu duyet den phan tu pTail cuoi trong danh sach
        if(k->next == list.tail)
        {
            //xoa phan tu cuoi
            delete list.tail;
            //tro phan tu truoc phan tu cuoi ve NULL
            k->next = NULL;
            //thay doi lai phan tu cuoi pTail cua danh sach
            list.tail = k;
        }
    }
}
void giaiPhongVungNho(DanhSach &list)
{
	Node *k ;
	{
		while(list.head != NULL)
		{
			k = list.head ;
			list.head = list.head->next ;
			delete k ;
		}
	}
}
void GHI_FILE_DSSV(DanhSach &list)
{
	ofstream fileOut;
	fileOut.open("DSSV.txt",ios::out);
	Node*k = list.head;
	if (k == NULL)
	{
		fileOut.close();
		return ;
	}
	while (k!= NULL)
	{	
		fileOut <<k->data.MaSV << "," << k->data.Ho << "," << k->data.Ten <<"," << k->data.Phai << "," << k->data.SoDT << ","  << k->data.MaLop<< "," << k->data.slDK <<"\n";
		k=k->next;
	}
}
bool checkNode(DanhSach list , int &dem,char *maLOP )
{
	int demtemp = 0 ;
	if (maLOP == NULL) return false ;
	char temp[17];
	for (Node *k = list.head; k!= NULL ; k = k->next)
	                {
	                	chuyen(k->data.MaLop ,temp);
	                //	if (strcmp (maLOP, temp) == 0 && k->data.MaSV == " ")demtemp++;
	                	if(strcmp (maLOP, temp) == 0 && k->data.MaSV != " ") 
	                	{	
	                		dem++;
						}
						if (strcmp (maLOP, temp) == 0 && k->data.MaSV == " ")demtemp++;
						
					}
	if (dem != 0 || demtemp != 0) return true ;
	else return false ;
}

void sapXepAlphaB(DanhSach &list)
{
	char temp1[50] , temp2[50] ; 
	SinhVien temp ;
	for ( Node *k = list.head ; k != NULL ; k=k->next)
	{
		for(Node *j = k->next ; j != NULL ; j=j->next)
		{
			chuyen(k->data.Ten ,temp1);
			chuyen(j->data.Ten ,temp2);
			if (strcmp(temp1 , temp2 ) > 0)
			{
				temp = k->data ;
				k->data = j->data ;
				j->data = temp;
			}
			if (strcmp(temp1 , temp2 ) == 0)
			{
				chuyen(k->data.Ho ,temp1);
				chuyen(j->data.Ho ,temp2);
				if (strcmp(temp1 , temp2 ) > 0)
				{
					temp = k->data ;
					k->data = j->data ;
					j->data = temp ;
				}
			}
		}
	}
}

void chuyenMaLop (char *maLop , char *maLoptemp)
{
	int i = 0 ;
	while (maLop[i] != '\0')
	{
		maLoptemp[i] = maLop[i];
		i++; 
	}
	maLoptemp[i] = '\0';
}

bool checkMaSV(char *maSV , DanhSach list)
{
	if (maSV[0] == '\0') return false ;
	char tempMaSV[16];
	for (Node *k = list.head ; k!= NULL ; k=k->next)
	{
		chuyen(k->data.MaSV , tempMaSV);
		if (strcmp(tempMaSV , maSV) == 0)
		{
			return false ;
		}
	}
	return true ;
}

void thaoTacNhapMaLop( char *temp ,int x ,int y,int &i )
{
	i=0;
	settextstyle(2, 0, 5);
	settextjustify(0,2);
	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		inBangThongBao("Bam ESC de huy qua","trinh nhap !!!","","","");
		settextjustify(0,2);
		settextstyle(2,0,5);
		if(kbhit()){
			settextstyle(2, 0, 5);
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 27)
			{
				while (i != 0)
				{
					i--;
				}
				temp[0] = '\0';
				break;
			}
			if (c[0] == 13)
			{
				temp[i] = '\0';
				break;
			}
			if (c[0] == 8 && i > 0) 
			{
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"    ");
            }
            
			if (i == 16)
			{
				temp[i] = '\0';
				inBangThongBao("So Ki Tu","Toi Da La 16 !","","","");
				delay(1000);
				settextjustify(0,2);
				continue;
			}
			if ((c[0] >= '0' && c[0] <= '9' ) || c[0] =='-') {
				temp[i] = c[0];
				temp[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}

		} else{
			settextstyle(2, 0, 5);
			outtextxy(x+3, y , "|  ");
			delay(500);
			outtextxy(x+3, y , "   ");
			delay(200);
		}
		delay(1);
	}
	clearmouseclick(WM_LBUTTONDOWN);
}

 void thaoTacNhapMSSV(int x,int y,int max, char *temp , int &slot){
 	settextstyle(2, 0, 5);
 	settextjustify(0,2);
 	int i = 0;
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		if(kbhit()){
			settextstyle(2, 0, 5);
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 77 )
            {
            		temp[i] = '\0';
		           	slot = 2 ;
		           	return ;
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				slot=8;
				break;
			}
			if (c[0] == 13)
			{
				temp[i] = '\0';
				slot= 6 ;
				break;
			}
			if (c[0] == 75)
			{
				temp[i] = '\0';
				slot = 5;
				break;
			}
			if (c[0] == 8 && i > 0) 
			{
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"   ");
            }
            
			if (i == max)
			{
				temp[i] = '\0';
					continue;
			}
			if (c[0] >= '0' && c[0] <= '9' ) {
				temp[i] = c[0];
				temp[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}

		} else{
			settextstyle(2, 0, 5);
			outtextxy(x+3, y , "|  ");
			delay(500);
			outtextxy(x+3, y , "   ");
			delay(200);
		}
	}
}

void thaoTacNhapBoChuSoXoaCach(int x,int y,int max, char *temp , int &slot){
	settextstyle(2, 0, 5);
	settextjustify(0,2);
 	int i = 0;
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
 	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		if(kbhit()){
			settextstyle(2, 0, 5);
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 75)
			{
				if(temp[i-1] == ' ') 
				{
					i--;
					temp[i] = '\0' ;
					slot++;
					break;
				}
				else 
				{
					temp[i] = '\0';
					slot--;
					break ;	
				}
			}
				if (c[0] == 77) 
			{
				if(temp[i-1] == ' ') 
				{
					i--;
					temp[i] = '\0' ;
					slot++;
					break;
				}
				else
				{
				temp[i] = '\0';
				slot++;
				}
				break;
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				slot=8;
				break;
			}
			if (c[0] == 13)
				{
					if(temp[i-1] == ' ') 
					{
						i--;
						temp[i] = '\0' ;
						slot = 6;
						break;
					}
				else
				{
				temp[i] = '\0';
				slot = 6;
				break;
				}
				}
			if (c[0] == 8 && i > 0) 
			{
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"    ");
            }
			if (i == max)
			{
				temp[i] = '\0';
				continue;
			}
			if (c[0] == 32 && i!=0 ) 
			{
				if(temp[i-1] == 32)
				{
					temp[i] = '\0';
					continue;
				}
				else 
				{
					temp[i] = c[0];
					temp[i+1]='\0';
					outtextxy(x, y, &c[0]);
					x+=textwidth(c);
					i++;
				}
			}
			if (c[0] >= 'A' && c[0] <= 'Z' && i <= max) {
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' && i<=max) {
				c[0]-=('a'-'A');
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}
		
		} else{
			settextstyle(2, 0, 5);
			outtextxy(x, y , "| ");
			delay(500);
			outtextxy(x, y , "  ");
			delay(200);
		}
	}
}
void thaoTacNhapKoSoKoCach(int x,int y,int max, char *temp ,int&slot)
{
	settextstyle(2, 0, 5);
	settextjustify(0,2);
 	int i = 0;
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
 	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		if(kbhit()){
			settextstyle(2, 0, 5);
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
				if (c[0] == 75)
				{
					temp[i] = '\0';
					slot = 2;
					break;
				}
			if ( c[0] == 77) 
			{
				temp[i] = '\0';
				slot= 4;
				break;
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				slot=8;
				break;
			}
			 if (c[0] == 13)
			 {
			 	temp[i] = '\0';
				slot= 6;
				break;
			 }
			if (c[0] == 8 && i > 0) 
			{
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"    ");
            }
			
			if (i == max)
			{
				temp[i] = '\0';
				if (c[0])
				{
					continue;
				}
			}
			
			if (c[0] >= 'A' && c[0] <= 'Z' ) {
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			if (c[0] >= 'a' && c[0] <= 'z' ) {
				c[0]-=('a'-'A');
				temp[i] = c[0];
				temp[i+1]='\0';
				outtextxy(x, y , &c[0]);
				x+=textwidth(c);
				i++;
			}
		
		} else{
			settextstyle(2, 0, 5);
			outtextxy(x, y , "|");
			delay(500);
			outtextxy(x, y , "   ");
			delay(200);
		}
	}
}
void thaoTacNhapChiSo(int x,int y,int max, char *temp ,int &slot){
 	int i = 0;
 	settextjustify(0,2);
 	settextstyle(2, 0, 5);
 	while (temp[i] != '\0')
 	{
 		i++;
	}
	 x += textwidth(temp);
 	char temp1[2];  temp1[1] = '\0'; 
	while (true) {
		if(kbhit()){
			settextstyle(2, 0, 5);
			char c[2];
			c[1] = '\0';
			c[0] = getch();
			if (!c[0]) {
				c[0] = getch();
			}
			if (c[0] == 75)
			{
				temp[i] = '\0';
				if (i < max)
				{
					inBangThongBao("So Dien Thoai","Phai Du 10 So !","", "","");
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
				else
				{
				slot = 4;
				break;
				}
			}
			if ( c[0] == 77) 
			{
				temp[i] = '\0';
				if (i < max)
				{
					inBangThongBao("So Dien Thoai","Phai Du 10 So !","", "","");
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
				else
				{
				slot = 1;
				break;
				}
			}
			if (c[0] == 27)
			{
				temp[i] = '\0';
				slot=8;
				break;
			}
			if (c[0] == 13&&i>0)
			{
				temp[i] = '\0';
				if (i < max)
				{
					inBangThongBao("So Dien Thoai","Phai Du 10 So !","", "","");
					settextjustify(0,2);
					setbkcolor(10);
					continue ;
				}
				else
				{
				slot = 6;
				break;
				}
			}
			
			if (c[0] == 8 && i > 0) {
				i--;
				temp1[0] = temp[i] ;
				x-=textwidth(temp1);
                outtextxy(x, y ,"     ");
            }
			if(i==max){
				inBangThongBao ("So Dien Thoai","Gioi Han 10 So !" ,"","","");
				settextjustify(0,2);
				setbkcolor(10);
				continue;
			}
			if (c[0] >= '0' && c[0] <= '9'  ) {		
				temp[i] = c[0];
				temp[i+1]='\0';
				
				outtextxy(x, y, &c[0]);
				x+=textwidth(c);
				i++;
			}
			
		} else{
			settextstyle(2, 0, 5);
			outtextxy(x, y , "| ");
			delay(500);
			outtextxy(x, y , "  ");
			delay(200);
		}
	}
}
void xoaBatKi(DanhSach &list , int vt , int &Trang , int &soTrang , char *maLop)
{

	int STTreal = (Trang-1)*10 + vt; 
	int p = 0;
	int dem =0;
	char temp [50];
	SinhVien dataTemp ;
	if(list.head == NULL) return ;
	for (Node *k = list.head; k!= NULL ; k = k->next)
	{
		p++;
		chuyen(k->data.MaLop,temp);
		if (strcmp(temp , maLop) == 0 && k->data.MaSV != " ")
		{
			dem++;
			if(dem == STTreal)
			{
				if (k -> data.slDK != 0)
				{
					inBangThongBao("Sinh Vien Ban Chon Da","Dang Ki Lop Tin Chi","Khong The Xoa !!","","");
					delay(2000);
					return ;
				}
				dataTemp = k->data;
				if(p == 1)
				{
					XoaDau(list);
					return;
				}
				break;
			 } 
		}
	}
	 
	if(list.tail->data.MaSV == dataTemp.MaSV)
	{
		XoaCuoi(list);
		int count =0 ; 
		checkNode(list,count,maLop) ; 
		if(count%10 !=0) 
		{
			soTrang = count /10+1;
			if (Trang > soTrang) Trang = soTrang ;
			
		}
		else 
		{
			soTrang = count/10;
			if (Trang > soTrang) Trang = soTrang ;
		}
		return;
	}
	dem = 0;
	Node* g = new Node;
	for(Node *t = list.head; t != NULL ; t = t->next)
	{	
		dem ++ ;
		if(dem==p)
		{
			g->next = t->next;
			delete t;
			int count =0 ; 
			checkNode(list,count,maLop)  ;
			if(count%10 !=0) 
		  {
			soTrang = count /10+1;
			if (Trang > soTrang) Trang = soTrang ;
	  	  }
	 	else 
		{
			soTrang = count/10;
			if (Trang > soTrang) Trang = soTrang ;
		}
			return;
		}
		g = t ;
	}
}
void xoaSinhVien(DanhSach &list , int vt , int &Trang , int &soTrang , char *maLop)
{
	int x1 ,y1;
	inBangThongBao("Ban Co Dong Y","Xoa Sinh Vien Tren ?","","","");
	inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"DONG Y", 12);
	inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"HUY",12);
	while (true)
	{
		if(kbhit())
		{
			char c = getch();
		}
		if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE,x1,y1);
					{
						
						if (x1 >= xThongBao -130 && x1 <= xThongBao +130 && y1 <=yThongBao +40*6 +20 && y1>= yThongBao +40*6 - 20)
						{
							inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"DONG Y", 10);
							inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"HUY",12);
						}
						else if (x1 >= xThongBao -130 && x1 <= xThongBao +130 && y1 <=yThongBao +40*7 +20 && y1>= yThongBao +40*7 - 20)
						{
							inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"DONG Y", 12);
							inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"HUY",10);
						}
						else 
						{
							inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"DONG Y", 12);
							inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"HUY",12);
						}
					}
			}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x1,y1);
			{
				if (x1 >= xThongBao -130 && x1 <= xThongBao +130 && y1 <=yThongBao +40*6 +20 && y1 >= yThongBao +40*6 - 20)
				{
					xoaBatKi(list,vt,Trang,soTrang,maLop);
					inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"", 1);
					inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"",1);
					break;
				}
				if (x1 >= xThongBao -130 && x1 <= xThongBao +130 && y1 <=yThongBao +40*7 +20 && y1>= yThongBao +40*7 - 20)
				{
					inDamNutHCN(xThongBao,yThongBao +40*6,280 ,40 ,"", 1);
					inDamNutHCN(xThongBao,yThongBao +40*7,280 ,40 ,"",1);
					return;
				}
			}
		}
	}
}

void toDamDSSV(int x1,int &x2 ,int y1, int &y2,const char *& s, const char* s1 ){	
	if(y2==y1&& x2==x1){
		return;
	}
	if(y2!=-1 && x2 != -1){
		settextjustify(0,2);
		setbkcolor(15);
		setfillstyle(1,15);
		settextstyle(10,0,2);
		bar(x2-100,y2-20,x2+100,y2+20);
		outtextxy((x2*2-textwidth(s))/2,y2-10,s);
		inBangThongBao("","","","","");
	}
		settextjustify(0,2);
				y2=y1;
				x2=x1 ;
				setbkcolor(4);
				setfillstyle(1,4);
				settextstyle(10,0,2);
				bar(x2-100,y2-20,x2+100,y2+20);
				s=s1;
				outtextxy((x2*2-textwidth(s))/2,y2-10,s);
}

void chuyenThongTinClick( SinhVien hieuChinh , char *maSV ,char *HoSV,char *TenSV,char *SDT)
{
	chuyen(hieuChinh.MaSV ,maSV );
	chuyen(hieuChinh.Ho ,HoSV);
	chuyen(hieuChinh.Ten ,TenSV);
	chuyen(hieuChinh.SoDT ,SDT);
}

void toDamSV(SinhVien &k, DanhSach list ,int &STT ,int STTinput,int Trang,char *maLop)
{
	if(STTinput==STT)
	{
		return;
	}
	char STTstr[10];
	char STTstr2[10];
	int dem = 0 ;
	int Y1=120;
	char tempXuat[50];
	settextstyle(2,0,5);
	settextjustify(0,2);
	if(STT!=-1 )
		{
			int trangOut = (Trang-1)* 10 + STT;
				if (STT %2 != 0)
				{
				setfillstyle(1,15);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);	
				setbkcolor(15);
				itoa(trangOut, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+ STT*40 +8,STTstr);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
				}
				else 
				{
				setfillstyle(1,9);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);
				setbkcolor(9);
				itoa(trangOut, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+ STT*40 +8,STTstr);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
				}
		}
		int trangIn = (Trang-1)* 10 + STTinput ;
				STT = STTinput;
				for (Node *p = list.head ; p!=NULL;p=p->next)
				{
					chuyen(p->data.MaLop ,tempXuat);
					if(strcmp(tempXuat,maLop)==0 && p->data.MaSV != " ") {
					dem++ ;
					if (dem == trangIn) 
					{
						k = p->data;
					}
					
					}
				}
				setfillstyle(1,12);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);
				setbkcolor(12);
				itoa(trangIn, STTstr2 ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr2))/2 + A[1],Y1+ STT*40 +8,STTstr2);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
}

void toDamClickSV(SinhVien &k, DanhSach list ,int STT , int &keep , int Trang,char *maLop)
{
	if(keep==STT)
	{
		return;
	}
	char STTstr2[10];
	int dem = 0 ;
	int Y1=120;
	char tempXuat[50];
	settextstyle(2,0,5);
		int trangIn = (Trang-1)* 10 + STT ;
				keep = STT;
				for (Node *p = list.head ; p!=NULL;p=p->next)
				{
					chuyen(p->data.MaLop ,tempXuat);
					if(strcmp(tempXuat,maLop)==0&&p->data.MaSV != " ") {
					dem++ ;
					if (dem == trangIn) 
					{
						k = p->data;
					}
					}
				}
				setfillstyle(1,10);
				settextjustify(0,2);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);
				setbkcolor(10);
				itoa(trangIn, STTstr2 ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr2))/2 + A[1],Y1+ STT*40 +8,STTstr2);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
}

void xoaToDS(int &STT ,DanhSach list, SinhVien k , int Trang ,int &xoaToMau)
{
	if (xoaToMau == 0)
	{
		xoaToMau = 1 ;
		if (STT != -1 && k.MaSV!= " ")
		{
			char STTstr[10];
			int dem = 0 ;
			int Y1=120;
			char tempXuat[50];
			settextstyle(2,0,5);
			int trangOut = (Trang-1)* 10 + STT;
				if (STT %2 != 0)
				{
				setfillstyle(1,15);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);	
				setbkcolor(15);
				itoa(trangOut, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+ STT*40 +8,STTstr);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
				}
				else 
				{
				setfillstyle(1,9);
				bar (A[1] + 1,160 +(STT-1)*40 + 1 ,A[2] - 1, 160 + 40*STT- 1);
				bar (A[2] + 1,160 +(STT-1)*40 + 1 ,A[3] - 1, 160 + 40*STT- 1);
				bar (A[3] + 1,160 +(STT-1)*40 + 1 ,A[4] - 1, 160 + 40*STT- 1);
				bar (A[4] + 1,160 +(STT-1)*40 + 1 ,A[5] - 1, 160 + 40*STT- 1);
				bar (A[5] + 1,160 +(STT-1)*40 + 1 ,A[6] - 1, 160 + 40*STT- 1);
				bar (A[6] + 1,160 +(STT-1)*40 + 1 ,A[7] - 1, 160 + 40*STT- 1);
				setbkcolor(9);
				itoa(trangOut, STTstr ,10);
				outtextxy((A[2]-A[1] - textwidth(STTstr))/2 + A[1],Y1+ STT*40 +8,STTstr);
				chuyen(k.MaSV ,tempXuat);
				outtextxy((A[3]-A[2] - textwidth(tempXuat))/2 + A[2],Y1 + STT*40 +8,tempXuat);
				chuyen(k.Ho ,tempXuat);
				outtextxy(20 + A[3],Y1+ STT*40+8,tempXuat);
				chuyen(k.Ten ,tempXuat);
				outtextxy((A[5]-A[4] - textwidth(tempXuat))/2 + A[4],Y1+ STT*40+8,tempXuat);
				chuyen(k.Phai ,tempXuat);
				outtextxy((A[6]-A[5] - textwidth(tempXuat))/2 + A[5],Y1+ STT*40+8,tempXuat);
				chuyen(k.SoDT ,tempXuat);
				outtextxy((A[7]-A[6] - textwidth(tempXuat))/2 + A[6],Y1+ STT*40+8,tempXuat);
				}
				STT = -1;
		}
	}
}
void inDamGioiTinh(int xtemp  ,int xtemp2,int STT , const char *gioiTinh , int mau)
{
	int STTx;
	if(STT %10!= 0) STTx = STT%10;
	else STTx = 10;
	if (xtemp != 0)
	{
		setfillstyle(1,mau);
		setbkcolor(mau);
		settextstyle(2,0,5);
		bar (A[5] + 1,160 +(STTx - 1)*40 + 1 ,xtemp, 160 + 40*(STTx)- 1);
		outtextxy((xtemp-A[5] - textwidth(gioiTinh))/2 + A[5],120 + 40*(STTx)+8,gioiTinh);
	}
	else if (xtemp2 != 0)
	{
		setfillstyle(1,mau);
		setbkcolor(mau);
		settextstyle(2,0,5);
		bar (xtemp2,160 +(STTx - 1)*40 + 1 ,A[6]-1, 160 + 40*(STTx)- 1);
		outtextxy((A[6]- xtemp2 - textwidth(gioiTinh))/2 + xtemp2,120 + 40*STTx+8,gioiTinh);
	}
	else 
	{
		setfillstyle(1,mau);
		setbkcolor(mau);
		settextstyle(2,0,5);
		bar (A[5] + 1,160 +(STTx - 1)*40 + 1 ,A[6] -1, 160 + 40*(STTx)- 1);
		outtextxy((A[6]-A[5] - textwidth(gioiTinh))/2 + A[5],120 + 40*(STTx)+8,gioiTinh);
	}
}
void setGioiTinh(int &sex , int STTx , int &slot)
{
	int xtemp = (A[6]-A[5])/2 + A[5];
	int xtemp2 = (A[6]-A[5])/2 + A[5];
	if (sex == 1)
	{
			inDamGioiTinh(xtemp,0 , STTx ,"NAM" ,4);
			inDamGioiTinh(0,xtemp2 , STTx , "NU" , 10);			
	}	
	else 
	{
			inDamGioiTinh(xtemp ,0, STTx ,"NAM" ,10);
			inDamGioiTinh(0,xtemp2 , STTx , "NU" , 4);
	}
		while(true)
		{
			if(kbhit())
			{
				char c = getch();
				if (!c) 
				{
					c = getch();
				}
				if (c == 27)
				{
					slot=8;
					break;
				}
				if ( c == 77 || c == 75  )
				{
					if (sex == 1)
					{
							inDamGioiTinh(xtemp ,0, STTx ,"NAM" ,10);
							inDamGioiTinh(0,xtemp2 , STTx , "NU" , 4);
							sex = 2;
					}
					else
					{
								inDamGioiTinh(xtemp,0 , STTx ,"NAM" ,4);
								inDamGioiTinh(0,xtemp2 , STTx , "NU" , 10);
								sex =1 ;
					}	
				}
				if (c == 13)
				{
					if (sex == 1)
						{
									inDamGioiTinh(0,0, STTx ,"NAM" ,12);	
						}
					else 
						{
									inDamGioiTinh(0,0, STTx ,"NU" ,12);	
						}	
						break;
				}
			}
		}
}

void endsex(int sex, int STTx , int &slot)
{
	while (true)
	{
		if(kbhit())
		{
			char c = getch();
				if (!c) 
				{
					c = getch();
				}
				if (c == 27)
				{
					slot=8;
					break;
				}
				if	(c == 75 || c == 77 || c== 13)
				{
					if (c == 77 )
					{
						slot++ ;
					}
					else if (c == 13) slot = 6 ;
					else slot--;
					
					if (sex == 1)
						{
									inDamGioiTinh(0,0, STTx ,"NAM" ,10);		
						}
					else 
						{
									inDamGioiTinh(0,0, STTx ,"NU" ,10);
						}	
						return;
				}
		}
	}
}
void inHangTieuDe(int ytemp1)
{
	settextjustify(0,2);
	setfillstyle(1,9);
	setbkcolor(9);
	bar (A[1] + 1,ytemp1 + 1 ,A[2] - 1, ytemp1 + 40- 1);
	bar (A[2] + 1,ytemp1 + 1 ,A[3] - 1, ytemp1 + 40- 1);
	bar (A[3] + 1,ytemp1 + 1 ,A[4] - 1, ytemp1 + 40- 1);
	bar (A[4] + 1,ytemp1 + 1 ,A[5] - 1, ytemp1 + 40- 1);
	bar (A[5] + 1,ytemp1 + 1 ,A[6] - 1, ytemp1 + 40- 1);
	bar (A[6] + 1,ytemp1 + 1 ,A[7] - 1, ytemp1 + 40- 1);
	settextstyle(10,0,2);
	setbkcolor(9);
	outtextxy((350*2 + - textwidth("STT") + 60)/2 , 120 + 8 , "STT");
	outtextxy((410*2 + - textwidth("MA SO SINH VIEN") + 190)/2 , 120 + 8 , "MA SO SINH VIEN");
	outtextxy((600*2 + - textwidth("HO SINH VIEN") + 260)/2 , 120 + 8 , "HO SINH VIEN");
	outtextxy((860*2 + - textwidth("TEN SV") + 140)/2 , 120 + 8 , "TEN SV");
	outtextxy((1000*2 + - textwidth("GIOI TINH") + 150)/2 , 120 + 8 , "GIOI TINH");
	outtextxy((A[7]-A[6] - textwidth("SDT"))/2 + A[6],120 + 8,"SDT");
}
void giaoDienDSSV( int xTrangT , int xTrangS,int yTrang, int x1 ,int y1, int kc )
{
	settextstyle(4,0,4);
    setbkcolor(1);
    outtextxy((getmaxx()-textwidth("DANH SACH SINH VIEN")-A[1])/2+A[1],16," DANH SACH SINH VIEN");	
  
  	settextstyle(10,0,2);
    setfillstyle(1,15);
    setbkcolor(15);

	bar(xTrangT-100,yTrang-20,xTrangT +100, yTrang +20);
	outtextxy(((xTrangT)*2-textwidth("TRANG TRUOC"))/2,yTrang-10,"TRANG TRUOC");
	bar(xTrangS-100,yTrang-20,xTrangS +100, yTrang +20);
	outtextxy(((xTrangS)*2-textwidth("TRANG SAU"))/2,yTrang-10,"TRANG SAU");
    bar(x1-100,y1-kc*2-20,x1+100,y1-kc*2 +20);
	outtextxy(((x1)*2-textwidth("NHAP MA LOP"))/2,y1-kc*2-10,"NHAP MA LOP");
	bar(x1-100,y1-kc-20,x1+100,y1-kc +20);
	outtextxy(((x1)*2-textwidth("THEM"))/2,y1-kc-10,"THEM");
    bar(x1-100,y1-20,x1+100,y1+20);
    outtextxy((x1*2-textwidth("HIEU CHINH"))/2,y1-10,"HIEU CHINH");
	y1+=kc;
	bar(x1-100,y1-20,x1+100,y1+20);
	outtextxy((x1*2-textwidth("XOA"))/2,y1-10,"XOA");
	y1+=kc;
	bar(x1-100,y1-20,x1+100,y1+20);
	outtextxy((x1*2-textwidth("THOAT"))/2,y1-10,"THOAT");
}
void viTriChuot (int &STT , int x , int y , int y1 , int kcSV)
{
	if (x >= A[1] && x <= A[7] && y >= y1 && y <= y1 + kcSV ) 
		{
			STT = 1 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV  && y <= y1 + 2*kcSV ) 
		{
			STT = 2 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 + kcSV *2 && y <= y1 + 3*kcSV ) 
		{
			STT = 3 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV *3 && y <= y1 + 4*kcSV ) 
		{
			STT = 4 ; 
		}
	if (x >= A[1] && x <= A[7] && y >= y1 + kcSV*4 && y <= y1 + 5*kcSV ) 
		{
			STT = 5 ; 
		}
	if (x >= A[1] && x <= A[7] && y >= y1 + kcSV*5 && y <= y1 + 6*kcSV ) 
		{
			STT = 6 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV*6&& y <= y1 + 7*kcSV ) 
		{
			STT = 7 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV*7&& y <= y1 + 8*kcSV ) 
		{
			STT = 8 ;  
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV*8&& y <= y1 + 9*kcSV) 
		{
			STT = 9 ; 
		}
	if (x >= A[1] && x <= A[7] && y >= y1 +kcSV*9&& y <= y1 + 10*kcSV) 
		{
			STT = 10 ; 
		}
}
void toMauHangThem(int STT , int mau , int y , int kc)
{
	int STTx;
	if (STT % 10 != 0) STTx = STT%10 ;
	else STTx = 10;
	char STTstrx[10];
	itoa(STT, STTstrx ,10);
	setfillstyle(1,mau);
	settextstyle(2,0,5);
	setbkcolor(mau);
	bar (A[1] + 1,y +(STTx - 1)*kc + 1 ,A[2] - 1, y + kc*(STTx)- 1);
	outtextxy((A[2]-A[1] - textwidth(STTstrx))/2 + A[1],120 + kc*(STTx)+8,STTstrx);
	bar (A[2] + 1,y +(STTx - 1)*kc + 1 ,A[3] - 1, y + kc*(STTx)- 1);
	bar (A[3] + 1,y +(STTx - 1)*kc + 1 ,A[4] - 1, y + kc*(STTx)- 1);
	bar (A[4] + 1,y +(STTx - 1)*kc + 1 ,A[5] - 1, y + kc*(STTx)- 1);
	bar (A[5] + 1,y +(STTx - 1)*kc + 1 ,A[6] - 1, y + kc*(STTx)- 1);
	bar (A[6] + 1,y +(STTx - 1)*kc + 1 ,A[7] - 1, y + kc*(STTx)- 1);
}

void ThemSV(DanhSach &list  ,char maLOPtemp[] , char maSV[] ,char hoSV[] ,char tenSV[] , char SDTSV[] , int sex)
{
	if (maSV[0] == '\0') return ;
	SinhVien them ; 
	string temp;
	chuyensangString(temp ,maLOPtemp);
	them.MaLop = temp;
	chuyensangString(temp,maSV);
	them.MaSV = temp;
	chuyensangString(temp,hoSV);
	them.Ho = temp;
	chuyensangString(temp,tenSV);
	them.Ten = temp;
	chuyensangString(temp,SDTSV);
	them.SoDT = temp;
	if(sex == 1) 
	{them.Phai = "NAM";}
	else {them.Phai = "NU";}
	them.slDK = 0 ;
	Node*k = KhoiTaoNode(them);
	themVaoCuoi(list,k);
}
void keBangDSSV()
{
	setbkcolor(1);	setfillstyle(1,1);
	bar(300 - 2,100 -2,1351,100*13);
	setcolor(0);
	setlinestyle(0,0,2);
	for(int i=1;i<8;i++){
		line(A[i],B[1],A[i],B[2]-127);
	}
	int B1=B[1];
	while(B1<=B[2]-100+1){
		line(A[1],B1,A[7],B1);
		B1+=40;
	}
	settextjustify(0,2);
	int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ;
	settextstyle(10,0,2);
   setfillstyle(1,15);
   setbkcolor(15);
	bar(xTrangT-100,yTrang-20,xTrangT +100, yTrang +20);
	outtextxy(((xTrangT)*2-textwidth("TRANG TRUOC"))/2,yTrang-10,"TRANG TRUOC");
	bar(xTrangS-100,yTrang-20,xTrangS +100, yTrang +20);
	outtextxy(((xTrangS)*2-textwidth("TRANG SAU"))/2,yTrang-10,"TRANG SAU");
}
void manHinhDSSV(DanhSach &list)
{
	int x,y; 
	int x1=150,y1=160;// toa do BUTTON
	int kc=60; // khoang cach BUTTON
	setbkcolor(1);
	cleardevice();
	setcolor(0);
	setlinestyle(0,0,2);
	for(int i=1;i<8;i++){
		line(A[i],B[1],A[i],B[2]-127);
	}
	int B1=B[1];
	while(B1<=B[2]-100+1){
		line(A[1],B1,A[7],B1);
		B1+=40;
	}
	int ytemp1 = 120;
	inHangTieuDe(ytemp1);
	xoaBang(160);	// xoaBangDSSV
	 int yTrang = 590 , xTrangT = 450 , xTrangS = getmaxx() - 120 ; ///TOA DO button chuyen trang////
	giaoDienDSSV(xTrangT,xTrangS,yTrang,x1,y1,kc);
	y1=160;
	inBangThongBao("","","","","");
	int yLight =-1 ;
	int xLight = -1 ; const char *sButton ;
	setbkcolor(15);
//	settextstyle(3,0,2);
	char maLOP[16]; maLOP[0] = '\0';
	char maLOPtemp[17];maLOPtemp[0] = '\0';
    int i = 0;
    int Trang , soTrang ;
	int tempkc = 0;  int demTemp1 = 0;
	int kcSV = 40 ; // khoang cach DSSV
//	int xNhap = x1 + 220 -95; // toa do NHAP MA SV
	SinhVien k;
	int STTchange= -1; int STTmove ;
	int tempNote = 0;
//	bool check = false;
	int chuyen = 0; int xoaToMau = 0;
    while (true)
	{
		settextjustify(0,2);
		 	if (kbhit())
		 	{
		 		char c = getch();
			 }
			if(ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				if(x<=x1+100&&x>=x1-100&&y<=y1-kc+20&&y>=y1-kc-20) // MOVEMOUSE THEM
				{
						xoaToDS(STTchange,list,k,Trang,xoaToMau);
						toDamDSSV(x1,xLight,y1-kc,yLight,sButton,"THEM");
						chuyen = 0; tempNote = 0;
				}	
			else if(x<=x1+100&&x>=x1-100&&y<=y1+kc+20&&y>=y1+kc-20)//MOVEMOUSE XOA
				{
					xoaToDS(STTchange,list,k,Trang,xoaToMau);
					toDamDSSV(x1,xLight,y1+kc,yLight,sButton,"XOA");
					chuyen = 0;tempNote = 0;
				}
			else if(x<=x1+100&&x>=x1-100&&y<=y1+kc*2+20&&y>=y1+kc*2-20)//MOVEMOUSE THOAT
				{
					xoaToDS(STTchange,list,k,Trang,xoaToMau);
					toDamDSSV(x1,xLight,y1+kc*2,yLight,sButton,"THOAT");
					chuyen = 0; tempNote = 0;
				}
    		else if(x<=x1+100&&x>=x1-100&&y<=y1+20&&y>=y1-20)	//MOVEMOUSE HIEU CHINH 
	    		{
	    			xoaToDS(STTchange,list,k,Trang,xoaToMau);
					toDamDSSV(x1,xLight,y1,yLight,sButton,"HIEU CHINH");
					chuyen = 0;
					tempNote = 0;
				}					
			else if(x <= x1+100 && x >= x1-100 && y <= y1-kc*2+20 && y >= y1-kc*2-20)//MOVEMOUSE NHAP MA LOP
				{	
					xoaToDS(STTchange,list,k,Trang,xoaToMau);
				
					
					toDamDSSV(x1,xLight,y1-kc*2,yLight,sButton,"NHAP MA LOP");
					chuyen = 0; 
					if( tempNote == 0)
					{
						inBangThongBao("Click vao day","de nhap ma mon hoc","","","");
						tempNote = 1;
					}
				}
			else if(x<=xTrangT+100&&x>=xTrangT-100&&y<=yTrang+20&&y>=yTrang-20)//TRANG_TRUOC_BUTTON MOVE
					{	
						xoaToDS(STTchange,list,k,Trang,xoaToMau);
						
						
						toDamDSSV(xTrangT,xLight,yTrang,yLight,sButton ,"TRANG TRUOC");
						chuyen = 0;
						if (maLOPtemp[0] == '\0' && tempNote == 0)
			            {
			            	inBangThongBao("Ban Chua Nhap","Ma Lop !","Danh Sach","Hien Rong !","");
			            	tempNote=1;
						}
					}
			else if(x<=xTrangS+100&&x>=xTrangS-100&&y<=yTrang+20&&y>=yTrang-20) // //TRANG_TRUOC_BUTTON MOVE
					{
						xoaToDS(STTchange,list,k,Trang,xoaToMau);
		
						toDamDSSV(xTrangS,xLight,yTrang,yLight,sButton,"TRANG SAU"); 
						chuyen = 0;
						if (maLOPtemp[0] == '\0' && tempNote == 0)
			            {
			            	
			            	inBangThongBao("Ban Chua Nhap","Ma Lop !","Danh Sach","Hien Rong !","");
			            	tempNote=1;
			            }
					}
			
				else if (x>= A[1] && x <= A[7] && y >= y1 && y <= y1 + kcSV *10 && maLOPtemp[0] != '\0')
					{
						tempNote = 0;
						demTemp1 = 0;
						checkNode(list ,demTemp1 ,maLOPtemp);
						if(demTemp1 == 0) continue ;
						viTriChuot(STTmove , x , y , y1 ,kcSV);
							xoaToDamButton(xLight,yLight,sButton,chuyen); 
								xoaToMau = 0;
								int dem = 0; checkNode(list,dem,maLOPtemp);
								if ((Trang -1)*10 + STTmove <= dem)
								{
									
									toDamSV(k,list,STTchange,STTmove,Trang,maLOPtemp);
								}
								else
								{
									xoaToDS(STTchange ,list,k,Trang,xoaToMau);
									xoaToMau=0;
								}
					}
					else
					{
						xoaToDS(STTchange,list,k,Trang,xoaToMau);
						xoaToDamButton(xLight,yLight,sButton,chuyen);
						tempNote = 0;
						//inBangThongBao("","","","","");
					}	
				}// END MOVE MOUSE		
				
	//=======================================CLICKMOUSE=====================================================		
	if (ismouseclick(WM_LBUTTONDOWN) == true)
		{
			settextjustify(0,2);
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(x<=x1+100 && x>=x1-100 && y<=y1-kc*2+20 && y>=y1-kc*2-20)
    		{
    			setfillstyle(1,15);
   				setbkcolor(15);
    			bar (x1 + 220 - 100 , y1 - kc*2-20 , x1 + 220+110 , y1-kc*2+20);// BANG NHAP MA LOP
    			thaoTacNhapMaLop( maLOP ,  x1 + 220 -95, y1 -kc*2 -8 ,  i );
    			if (i == 0)
					{
						setfillstyle(1,1);
						setbkcolor(1);
	    				bar (x1 +220- 100 , y1 - kc*2-20 , x1 +220+110 , y1-kc*2+20);
	    				continue;
					}
					else 
					{
						setfillstyle(1,1);
						setbkcolor(1);
	    				bar (x1+220 - 100 , y1 - kc*2-20 , x1 + 220+110 , y1-kc*2+20);
		                maLOP[i] = '\0';
		                char temp[17];
		                int dem = 0 ;
		                int ytemp = 160;
		                if (checkNode(list, dem, maLOP) == true && maLOP[0] != '\0')
		                	{	
								Trang = 1;
								if (dem % 10 != 0)
								{
									soTrang = dem/10 + 1 ;
								}
								else 
								{
									soTrang = dem/10 ;
								}
								if (dem == 0)
								{
									Trang = 1 ; soTrang = 1;
								}
								xoaBang(ytemp);
		                		settextstyle(4,0,3);
		                		setbkcolor(1);
		                		outtextxy((getmaxx() - i *23 -A[1])/2+A[1] ,55, maLOP);
		                		sapXepAlphaB(list);
								XuatDS(list,maLOP,Trang,soTrang);	
							}
			            else
							{
								inBangThongBao("Khong co ma lop tren !","Vui Long Click ","NHAP MA LOP","de nhap lai !!","");
								settextjustify(0,2);
								delay(2000);
								clearmouseclick(WM_LBUTTONDOWN);
							}	
						}
					chuyenMaLop(maLOP , maLOPtemp);
	                tempkc = 0;
					i= 0 ;
					
    		}
	    if(x<=x1+100&&x>=x1-100&&y<=y1+kc*2+20&&y>=y1+kc*2-20) // CLICK THOAT
			{
				GHI_FILE_DSSV(list);
				break ;
			}
		if(x<=xTrangT+100&&x>=xTrangT-100&&y<=yTrang+20&&y>=yTrang-20) // CLICK TRANG TRUOC
			{
			if(maLOPtemp[0]=='\0') continue;
			xoaToDamButton(xLight,yLight,sButton,chuyen);
			int dem = 0 ;
			sapXepAlphaB(list);

			if (checkNode(list  , dem ,maLOPtemp) == true )
			    {
			        if (Trang == 1)
			        {
			        	inBangThongBao("Ban Dang O","Trang Dau Tien !","","","");
					}
					else 
					{
						Trang--;
						int ytemp = 160;
						xoaBang(ytemp);
						XuatDS(list , maLOPtemp ,Trang,soTrang);
						inBangThongBao("","","","","");
					}
				}
				if(dem==0)
				{
					inBangThongBao("Danh Sach Rong !","","","","");
				}
			}
		if (x<=xTrangS+100&&x>=xTrangS-100&&y<=yTrang+20&&y>=yTrang-20)// CLICK TRANG SAU
			{
			if(maLOPtemp[0]=='\0') continue;
			int dem = 0 ;
			sapXepAlphaB(list);	
			if (checkNode(list ,  dem ,maLOPtemp) == true )
			    {
			        if (Trang == soTrang)
			        {
			        	inBangThongBao("Ban Dang O","Trang Cuoi Cung !","","","");
					}
					else 
					{
						Trang++;
						int ytemp = 160;
						xoaBang(ytemp);
						XuatDS(list , maLOPtemp ,Trang,soTrang);
						inBangThongBao("","","","","");
					}
				}
				if(dem==0)
				{
					inBangThongBao("Danh Sach Rong !","","","","");
				}
			}
			
			if (x >= x1 - 100 && x <= x1 + 100 && y >= y1-kc - 20 && y <= y1-kc + 20) //===========THEM SINH VIEN=========
			{
				if(maLOPtemp[0]=='\0') continue;
				int dem = 0 ;
				if (checkNode(list ,  dem ,maLOPtemp) == true || dem == 0)
				{
					Trang = soTrang ;
					int ytemp = 160;
					xoaBang(ytemp);
					int STTx = dem + 1 ;
					if (dem%10 == 0)
					{
						soTrang = (STTx-1)/10 +1;
						Trang ++;
					}
					settextstyle(2,0,5);
					char maSV[16]; 
					char hoSV[51];
					char tenSV[10];
					char SDTSV[11];
					int sex = 1;
					int slot = 1 ;
					bool checkSex ;
						bool STOPADD = false ;
						while (STOPADD != true)
						{
							settextjustify(0,2);	
							inBangThongBao("Nhan ESC de huy","qua trinh!","Nhan ENTER","de luu!","");
							settextjustify(0,2);
							xoaBang(ytemp);
							XuatDS(list , maLOPtemp , Trang,soTrang);
							maSV[0] ='\0';
							hoSV[0] = '\0';
							tenSV[0] = '\0';
							SDTSV[0] = '\0' ;
							slot = 1 ;
							checkSex = false ;
							toMauHangThem(STTx , 10 , ytemp ,kcSV);
						 while (slot!=0)
						 {
						 	inBangThongBao("Nhan ESC de huy","qua trinh!","Nhan ENTER","de luu!","");
							settextjustify(0,2);
							setfillstyle(1,10);
							setbkcolor(10);
						 	switch(slot)
						 	{
						 		case 1 : 
						 		{
						 			if (STTx %10 != 0)
						 			{
						 					thaoTacNhapMSSV(A[2] + 5 , 120+ 40*(STTx%10) + 8 , 17 ,maSV  , slot);
									 }
						 			else thaoTacNhapMSSV(A[2] + 5 , 120+ 40*(10) + 8 , 15 ,maSV  , slot);
						 			break;
								 }
								 case 2 :
								 	{
								 		if(STTx %10 != 0) thaoTacNhapBoChuSoXoaCach(A[3] + 5 , 120+ 40*(STTx%10) + 8 , 51 ,hoSV ,slot );
								 		else thaoTacNhapBoChuSoXoaCach(A[3] + 5 , 120+ 40*(10) + 8 , 50,hoSV ,slot );
								 		break;
									 }
								case 3 :
									{
										if(STTx %10 != 0) thaoTacNhapKoSoKoCach(A[4] + 5 , 120+ 40*(STTx%10) + 8 , 10 ,tenSV ,slot);
										else thaoTacNhapKoSoKoCach(A[4] + 5 , 120+ 40*(10) + 8 , 10 ,tenSV ,slot);
										break;
									}
								case 4 : 
									{
										setGioiTinh(sex , STTx,slot);
										endsex(sex,STTx,slot);
										checkSex =true;
										break;
									}
								case 5 : 
								{
				
									if (STTx %10 != 0) thaoTacNhapChiSo(A[6] + 5 , 120+ 40*(STTx%10) + 8 , 10 ,SDTSV,slot);
									else  thaoTacNhapChiSo(A[6] + 5 , 120+ 40*(10) + 8 , 10 ,SDTSV,slot);
									break;
								}
								case 6 :
									{
										if (maSV[0] == '\0' && hoSV[0]=='\0' && tenSV[0]=='\0' && SDTSV[0] == '\0') 
										{
										STOPADD = true ;
										 if(STTx%10==1) 
										 {
										 	soTrang-=1;
										 	Trang-=1;
										 }
										 slot = 0;
											break;
											}
										 if (checkMaSV(maSV,list) == false && maSV[0] != '\0')
										{
											inBangThongBao("Ma Sinh Vien Ban", "Vua Nhap Da","Ton Tai !","Vui Long Kiem","Tra Lai Ma!!");
											delay(2000);
											slot=1;
											break;
										}
										if  (maSV[0] == '\0')
										{
											inBangThongBao("Ma Sinh Vien","Dang Rong !!","","","");
											delay(2000);
											slot = 1;
											break ;
										}
										 if (hoSV[0] == '\0')
										{
											inBangThongBao("Ho Sinh Vien","Dang Rong !!","","","");
											delay(2000);
											slot = 2 ;
											break;
										}
										if (tenSV[0] == '\0')
										{
											inBangThongBao("Ten Sinh Vien","Dang Rong !!","","","");
												delay(2000);
											slot = 3;
											break;
										}
										if (checkSex != true)
										{
											inBangThongBao("Chon","Gioi Tinh","","","");
												delay(2000);
											slot = 4;
											break;
										}
										if (SDTSV[0] == '\0' )
										{
											inBangThongBao("So Dien Thoai","Sinh Vien","Dang Rong !!","","");
												delay(2000);
											slot =5;
											break;
										}
										  inBangThongBao("","","","","");
											slot = 7 ;
											break;	
									}
								case 7 :
									{	
										ThemSV(list, maLOPtemp ,maSV , hoSV,tenSV,SDTSV,sex);
										slot = 0;
										break;
									}
								case 8 :
									{
										STOPADD = true ;
										if(STTx%10==1&&STTx!=1) 
										 {
										 	soTrang-=1;
										 	Trang-=1;
										 }
										slot = 0;
										inBangThongBao("","","","","");
										settextjustify(0,2);
										break;
									}
							}
						 }
						 STTx++;
						 
						if (STTx > soTrang*10 && STOPADD != true && STTx !=2 ) 
						{
							soTrang+=1;
							Trang+=1;
							 
							xoaBang(ytemp);
						}
						}
					xoaBang(ytemp);
					sapXepAlphaB(list);
					XuatDS(list , maLOPtemp , Trang,soTrang);	
				}
				clearmouseclick(WM_LBUTTONDOWN);
			}	
	int STTclick ;
	int keep=0 ;
	SinhVien click ;
	int demXoa =0;
	int STTafter;
	bool checkClick = false ;
		if (x >=A[1] && x <= A[7] && y >= 160 && y <= 160 + 40*10 && maLOPtemp[0] != '\0'  && checkNode(list,demXoa,maLOPtemp) == true) // CLICK SV
				{
					int tempNote = 0; int note = 0;
					settextjustify(0,2);
					viTriChuot(STTclick , x,y,y1 ,kcSV);	
						if ((Trang -1)*10 + STTclick <= demXoa) 
						{
							xoaToDS(STTchange,list,k,Trang,xoaToMau);
							toDamClickSV(click,list,STTclick,keep,Trang,maLOPtemp);
							inBangThongBao("Click THOAT de bo chon","Click HIEU CHINH de","thay doi thong tin","Click XOA de xoa sinh"," vien");
							checkClick=true ;
						}
						else continue ;
						char maSVhc[16] ;
						char Hohc[50] ;
						char Tenhc[10];
						char SDThc[11];
						int Sexhc = 1;
						int select =1;
						
						while (checkClick == true)
						{	
						settextjustify(0,2);
							if (kbhit())
							{
								char c1 = getch();
							}
							if (ismouseclick(WM_LBUTTONDOWN))
							{
								getmouseclick(WM_LBUTTONDOWN, x, y);
								{
									if(x<=x1+100&&x>=x1-100&&y<=y1+kc*2+20&&y>=y1+kc*2-20)
									{
										xoaToMau = 0;
										xoaToDS(STTclick,list,click,Trang,xoaToMau);
										inBangThongBao("","","","","");
										break;
									}
									if(x<=x1+100&&x>=x1-100&&y<=y1+kc+20&&y>=y1+60-20)
									{
										xoaSinhVien(list,STTclick,Trang,soTrang,maLOPtemp);
										sapXepAlphaB(list);
										xoaBang(160);
										XuatDS(list,maLOPtemp,Trang,soTrang);
										break;
									}
									if (x<=x1+100&&x>=x1-100&&y<=y1+20&&y>=y1-20)	
									{
										
										setfillstyle(1,10);
										setbkcolor(10);
										settextstyle(2,0,5);
										xoaBatKi(list,STTclick,Trang,soTrang,maLOPtemp);
										chuyenThongTinClick(click,maSVhc,Hohc,Tenhc,SDThc);
										int trangtemp = Trang ;
									while (select != 0)
									{
										inBangThongBao("Nhan ESC de huy","qua trinh!","Nhan ENTER","de luu!","");
										setfillstyle(1,10);
										setbkcolor(10);
										settextjustify(0,2);
										settextstyle(2,0,5);
										switch (select)
										{
											case 1 : 
											{
												
												if (STTclick%10 != 0)
												{
													bar (A[2] + 1,160 +(STTclick-1)*40 + 1 ,A[3] - 1, 160 + 40*STTclick- 1);
													outtextxy(A[2] + 5 , 120+ 40*(STTclick%10) + 8 ,maSVhc);
													thaoTacNhapMSSV(A[2] + 5 , 120+ 40*(STTclick%10) + 8 , 15 ,maSVhc  , select);
													
													setbkcolor(10);
													break;
												}
												else 
												{
													bar (A[2] + 1,160 +(10-1)*40 + 1 ,A[3] - 1, 160 + 40*10- 1);
													outtextxy(A[2] + 5 , 120+ 40*(10) + 8 ,maSVhc);
													thaoTacNhapMSSV(A[2] + 5 , 120+ 40*(10) + 8 , 15 ,maSVhc  , select);
													
													break;
												}
											case 2 :
												{
													if (STTclick%10 != 0)
													{
														bar (A[3] + 1,160 +(STTclick-1)*40 + 1 ,A[4] - 1, 160 + 40*STTclick- 1);
														outtextxy(A[3] + 5 , 120+ 40*(STTclick%10) + 8 ,Hohc);
														thaoTacNhapBoChuSoXoaCach(A[3] + 5 , 120+ 40*(STTclick%10) + 8 , 49 ,Hohc  , select);
														break;
													}
													else 
													{
														bar (A[3] + 1,160 +(10-1)*40 + 1 ,A[4] - 1, 160 + 40*10- 1);
														outtextxy(A[3] + 5 , 120+ 40*(10) + 8 ,Hohc);
														thaoTacNhapBoChuSoXoaCach(A[3] + 5 , 120+ 40*(10) + 8 , 49 ,Hohc , select);
														break;
													}	
												}
											case 3 :
												{
													if (STTclick%10 != 0)
													{
														bar (A[4] + 1,160 +(STTclick-1)*40 + 1 ,A[5] - 1, 160 + 40*STTclick- 1);
														outtextxy(A[4] + 5 , 120+ 40*(STTclick%10) + 8 ,Tenhc);
														thaoTacNhapKoSoKoCach(A[4] + 5 , 120+ 40*(STTclick%10) + 8 , 9 ,Tenhc  , select);
														break;
													}
													else 
													{
														bar (A[4] + 1,160 +(10-1)*40 + 1 ,A[5] - 1, 160 + 40*10- 1);
														outtextxy(A[4] + 5 , 120+ 40*(10) + 8 ,Tenhc);
														thaoTacNhapKoSoKoCach(A[4] + 5 , 120+ 40*(10) + 8 , 9 ,Tenhc , select);
														break;
													}	
												}
											case 4 :
												{
													setGioiTinh(Sexhc , STTclick,select);
													endsex(Sexhc,STTclick,select);
													break;
												}	
											case 5 :
												{
													if (STTclick%10 != 0)
													{
														bar (A[6] + 1,160 +(STTclick-1)*40 + 1 ,A[7] - 1, 160 + 40*STTclick- 1);
														outtextxy(A[6] + 5 , 120+ 40*(STTclick%10) + 8 ,SDThc);
														thaoTacNhapChiSo(A[6] + 5 , 120+ 40*(STTclick%10) + 8 , 10 ,SDThc  , select);
														break;
													}
													else 
													{
														bar (A[6] + 1,160 +(10-1)*40 + 1 ,A[7] - 1, 160 + 40*10- 1);
														outtextxy(A[6] + 5 , 120+ 40*(10) + 8 ,SDThc);
														thaoTacNhapChiSo(A[6] + 5 , 120+ 40*(10) + 8 , 10 ,SDThc , select);
														break;
													}
												}
											case 6 :
												{
												 if (checkMaSV(maSVhc,list) == false && maSVhc[0] != '\0')
													{
														inBangThongBao("Ma Sinh Vien Ban", "Vua Nhap Da","Ton Tai !","Vui Long Kiem","Tra Lai Ma!!");
														delay(2000);
														select=1;
														break;
													}
													else if  (maSVhc[0] == '\0')
													{
														inBangThongBao("Ma Sinh Vien","Dang Rong !!","","","");
														delay(2000);
														select = 1;
														break ;
													}
													else if (Hohc[0] == '\0')
													{
														inBangThongBao("Ho Sinh Vien","Dang Rong !!","","","");
														delay(2000);
														select = 2 ;
														break;
													}
													else if (Tenhc[0] == '\0')
													{
														inBangThongBao("Ten Sinh Vien","Dang Rong !!","","","");
														delay(2000);
														select = 3;
														break;
													}
													else if (SDThc[0] == '\0')
													{
														inBangThongBao("So Dien Thoai","Sinh Vien","Dang Rong !!","","");
														delay(2000);
														select =5;
														break;
													}
													 else 
													{
														inBangThongBao("","","","","");
														select = 7 ;
														break;
													}
												}
											case 7 :
												{
													ThemSV(list,maLOPtemp ,maSVhc,Hohc,Tenhc,SDThc,Sexhc);
													select = 0;
													break;
												}
											case 8 :
												{
													select = 0 ;
													Node*k = KhoiTaoNode(click);
													themVaoCuoi(list,k);
													break;
												}	
											}
										}
									}
									xoaBang(160);
									sapXepAlphaB(list);
									XuatDS(list,maLOPtemp,Trang,soTrang);
									checkClick=false ;
									xoaToDamButton(xLight,yLight,sButton,chuyen);
									break;
									}
								}
							}
							if (ismouseclick(WM_MOUSEMOVE))
								{
									getmouseclick(WM_MOUSEMOVE, x, y);
									if(x<=x1+100&&x>=x1-100&&y<=y1+kc+20&&y>=y1+60-20)
									{
										toDamDSSV(x1,xLight,y1+kc,yLight,sButton,"XOA");
										if (tempNote == 0)
										{
											inBangThongBao("Click Vao Day De","Thuc Hien Thao Tac" ,"XOA","","");
											tempNote = 1;
										}
										note = 0;
										chuyen = 0;
									}
									else if(x<=x1+100&&x>=x1-100&&y<=y1+20&&y>=y1-20)
									{
										toDamDSSV(x1,xLight,y1,yLight,sButton,"HIEU CHINH");
										if (tempNote == 0)
										{
											inBangThongBao("Click Vao Day De","HIEU CHINH","Thong Tin Sinh Vien","","");
											tempNote = 1;
										}
										note = 0;
										chuyen = 0;
										
									}
									else if(x<=x1+100&&x>=x1-100&&y<=y1+kc*2+20&&y>=y1+kc*2-20)
									{
										toDamDSSV(x1,xLight,y1+kc*2,yLight,sButton,"THOAT");
										if (tempNote == 0)
										{
											inBangThongBao("Click De Bo Chon","Sinh Vien","","","");
											tempNote = 1;
										}
										note = 0;
										chuyen = 0;	
									}
									else 
									{
										tempNote = 0;
										chuyen = 0;
										xoaToDamButton(xLight,yLight,sButton,chuyen);
										if (note == 0)
										{
											inBangThongBao("Click THOAT de bo chon","Click HIEU CHINH de","thay doi thong tin","Click XOA de xoa sinh"," vien");
											note = 1;
										}
											
										
										
										
									}
								}
						}
						demXoa=0;	
					} 		
			}//END CLICK MOUSE	
		}
	}
