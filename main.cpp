/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/

#include"tongHop.h"






int main()
{
	DSMH_AVL root;
	DSLTC dsLop;
	DanhSach list;
	KhoiTao(list);
	Initialize(root);
	docFile1(root);
	docFileLTC(dsLop);
	Doc_FILE_DSSV(list);
	initwindow(1360, 700);
	manHinhChinh(root,dsLop,list);
	closegraph();
	return 0;
}


