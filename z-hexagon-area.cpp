
/*hexagon'un kenarlarý ve açýlarý (kenar1, açý1, ... , kenar6, açý6) kuralýna uygun girilir.
alan 4'e bölünmüþ gibi iþlem yapýlýr (aslýnda bölmüyoruz)
k1,a1,k2 kullanýlarak alan1; ... ; k5,a5,k6 kullanýlarak alan3 bulunur
k1,a1,k2 kullanýlarak ortakenar1; ... k5,a5,k6 kullanýlarak ortakenar3 bulunur
ortakenar1,2,3 kullanýlarak ortaüçgenin alaný bulunur
//a1,a3,a5'ten herhangi biri 180 dereceden büyükse bulunan üçgenin alaný negatif alýnýr
///üst satýra düzeltme: sinüsle iþlem yapýldýðý için 180 dereceden büyük deðerler zaten negatif
ayný iþlemleri kenar ve açýlarýn bir yüksek numaralýlarý için de tekrarlanýr
iki sonuç birbirine eþitse saðlama yapýlmýþtýr
daha sonra sonuç gösterilir
*/
#include <iostream>
#include <math.h>
#define PI 3.1415926535897932384626
using namespace std;

float conv(float d);
float heron_formula(float x, float y, float z);
float size1(float l1,float d1,float l2,float l3,float d3,float l4,float l5,float d5,float l6);
float size2(float l6,float d6,float l1,float l2,float d2,float l3,float l4,float d4,float l5);
float check(float value1,float value2);


int main() {
	float value1,value2;
	float l1,d1,l2,d2,l3,d3,l4,d4,l5,d5,l6,d6;
	cout << "Please, put 12 values in order" << endl;
	cin >> l1 >> d1 >> l2 >> d2 >> l3 >> d3 >> l4 >> d4 >> l5 >> d5 >> l6 >> d6;
	d1=conv(d1);
	d2=conv(d2);
	d3=conv(d3);
	d4=conv(d4);
	d5=conv(d5);
	d6=conv(d6);
	value1=size1(l1,d1,l2,l3,d3,l4,l5,d5,l6);
	value2=size2(l6,d6,l1,l2,d2,l3,l4,d4,l5);
	if(check(value1,value2)==-1){
		cout << "There are somethings wrong!" << endl;
	}
	else{
		cout << check(value1,value2);
	}
	return 0;
}

float conv(float d){
	d=PI*d/180;
	return d;
}

float heron_formula(float x, float y, float z) {
	float u, temporary, value;
	u=(x+y+z)/2;
	temporary=(u-x)*(u-y)*(u-z)*u;
	value=pow(temporary, 0.5);
	return value;
}

float size1(float l1,float d1,float l2,float l3,float d3,float l4,float l5,float d5,float l6){
	float lc1,lc2,lc3;
	float area1,area2,area3,area4;
	lc1=sqrt(pow(l1,2)+pow(l2,2)-2*cos(d1)*l1*l2); //cos teoremi
	lc2=sqrt(pow(l3,2)+pow(l4,2)-2*cos(d3)*l3*l4);
	lc3=sqrt(pow(l5,2)+pow(l6,2)-2*cos(d5)*l5*l6);
	area1=0.5*l1*l2*sin(d1);
	area2=0.5*l3*l4*sin(d3);
	area3=0.5*l5*l6*sin(d5);
	area4=heron_formula(lc1,lc2,lc3);
	float value1=area1+area2+area3+area4;
	return value1;
}

float size2(float l6,float d6,float l1,float l2,float d2,float l3,float l4,float d4,float l5){
	float lc1,lc2,lc3;
	float area1,area2,area3,area4;
	lc1=sqrt(pow(l6,2)+pow(l1,2)-2*cos(d6)*l6*l1); //cos teoremi
	lc2=sqrt(pow(l2,2)+pow(l3,2)-2*cos(d2)*l2*l3);
	lc3=sqrt(pow(l4,2)+pow(l5,2)-2*cos(d4)*l4*l5);
	area1=0.5*l6*l1*sin(d6);
	area2=0.5*l2*l3*sin(d2);
	area3=l4*l5*sin(d4)*0.5;
	area4=heron_formula(lc1,lc2,lc3);
	float value2=area1+area2+area3+area4;
	return value2;
}

float check(float value1,float value2){
	if(value1==value2){
		return value1;
	}
	else{
		return -1;
	}
}
