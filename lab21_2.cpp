#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *m, Rect *n){
	Rect a;
	if((m->x+m->w)-n->x>0){
		a.x = n->x;
		a.w = ((m->x+m->w)-n->x);
		if((m->x+m->w)>(n->x+n->w)){
			a.x = n->x;
			a.w = n->w;
		}else if((m->x+m->w)-n->x <= 0){
			a.x = 0;
			a.w = 0;
		}
		if(n->y-(m->y-m->h)>0){
			a.y = m->y;
			a.h = m->y-(n->y-n->h);
			if((m->y-m->h)<(n->y-n->h) and m->y>n->y){
				a.y = n->y;
				a.h = n->h;
			}
		}else if (m->x+m->w-n->x <= 0){
			a.y = 0;
			a.h = 0;
		}
	}

	return a.w*a.h;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};	
	cout << overlap(&R1,&R2) << " ";

	Rect R3 = {1,1,5,5};
	Rect R4 = {7,2,3,3};	
	cout << overlap(&R3,&R4) << " ";

	Rect R5 = {-1,2,6.9,9.6};
	Rect R6 = {0,0,1.2,2.5};	
	cout << overlap(&R5,&R6) << " ";

	return 0;
}

