#include "DanhSachDangKi.h"
void KhoiTaoDK(DSDK &listDK)
{
	listDK.head = NULL;
	listDK.tail = NULL;
}
NodeDK *KhoiTaoNodeDK()
{
	NodeDK *p = new NodeDK; // cap phat vung nho cho Node p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!!\n";
		return NULL;
	}
	p->data.maSVdk[0] = '\0'; //truyen gia tri sv vao cho data
	p->next = NULL;//chua co lien ket => tro den NULL
	return p; //Tra ve Node p vua khoi tao
}

void themSVDK(DSDK &listDK,NodeDK *p){
	NodeDK *q=listDK.head;
	if (listDK.head == NULL) // danh sach rong~
		{
			listDK.head = listDK.tail = p;
			return;
		}
	if(soSanh2Chuoi(p->data.maSVdk,listDK.head->data.maSVdk)<=0){
		p->next=listDK.head;
		listDK.head=p;
		return;
	}
	if(soSanh2Chuoi(p->data.maSVdk,listDK.tail->data.maSVdk)>=0){
		listDK.tail->next = p ;
		listDK.tail = p ;
		return;
	}	
	while(q->next!=NULL){
		if(soSanh2Chuoi(p->data.maSVdk,q->next->data.maSVdk)>0){
			q=q->next;
			continue;
		}else{
			p->next=q->next;
			q->next=p;
			return;
		}
	}
}
void themVaoCuoiDK (DSDK &listDK , NodeDK *p)
{
		if (listDK.head == NULL) // danh sach rong~
		{
			listDK.head = listDK.tail = p;// node dau trung` node cuoi = p
		}	
		else 
		{
			listDK.tail->next = p ;// cho con tro cua tail lien ket voi p
			listDK.tail = p ;// cap nhat lai tail la p moi them  vao
		}
}
void themVaoDauDK (DSDK &listDK , NodeDK *p)
{
		if (listDK.head == NULL) // danh sach rong~
		{
			listDK.head = listDK.tail = p;// node dau trung` node cuoi = p
		}	
		else 
		{
			p->next = listDK.head;// cho con tro cua Node can them la p lien ket den head
			listDK.head = p ;// cap nhat lai head la p moi them  vao
		}
}
void XoaDauDK(DSDK &listDK){
    //tao node p
    NodeDK *p = new NodeDK;
    //gan p bang node pHead dau tien cua danh sach 
    p = listDK.head;
    //thay doi lai pHead cua danh sach
    listDK.head = listDK.head->next;
    //gan node p ban dau tro den NULL
    p->next = NULL;
    //xoa node p
    delete p;
}
void XoaCuoiDK(DSDK &listDK)
{
    //duyet cac phan tu co trong danh sach
    for(NodeDK *k = listDK.head; k != NULL; k = k ->next)
    {
        //neu duyet den phan tu pTail cuoi trong danh sach
        if(k->next == listDK.tail )
        {
            //xoa phan tu cuoi
            delete listDK.tail;
            //tro phan tu truoc phan tu cuoi ve NULL
            k->next = NULL;
            //thay doi lai phan tu cuoi pTail cua danh sach
            listDK.tail = k;
        }
    }
}
void XoaKhoaK(DSDK &listDK, char MaSVdk[])
{
    //tao node p de luu tru phan tu truoc node k can xoa
    NodeDK *p = new NodeDK;
    //neu data dau vao bang voi pHead->data thi xoa dau
    if(strcmp(listDK.head->data.maSVdk,MaSVdk) == 0)
    {
        //goi ham xoa dau
        XoaDauDK(listDK);
        //ket thuc ham
        return;
    }
    //neu data bang voi pTail->data thi xoa cuoi
    if(strcmp(listDK.tail->data.maSVdk,MaSVdk)==0)
	{
        //goi ham xoa cuoi
        XoaCuoiDK(listDK);
        //ket thuc ham
        return;
    }
    //duyet qua cac phan tu co trong danh sach
    for(NodeDK *k = listDK.head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(strcmp(k->data.maSVdk,MaSVdk)==0)
		{
            //gan con tro next cua node p bang con tro next cua node k
            p->next = k->next;
            //xoa di node k
            delete k;
            //ket thuc ham
            return;
        }
        //gan node p bang node k de node p luon la node dung truoc node k
        p = k;
    }
}
void giaiPhongVungNhoDK(DSDK &listDK)
{
	NodeDK *k;
	while(listDK.head!=NULL){
		k=listDK.head;
		listDK.head=listDK.head->next;
		delete k;
	}
}

Node* timThongTin1SV (char maSVdk[] , DanhSach list )//theo MaSV
{
	Node*p=NULL;
	char temp[50]; 
	Node*t = list.head;
		while(t!=NULL)
		{
			chuyen(t->data.MaSV , temp);
			if (strcmp(maSVdk ,temp) == 0)
			{
				p = t ;
				break;
			}
			t=t->next;
		}
	return p;
}


