// Solutions of 3X4 Matrix

#include<stdio.h>
#include<iostream>
using namespace std;
float a[3][5];
int i,j,p,q,r;

// TO PRINT THE MATRIX IN A BEAUTIFUL FORMAT ;)
void printMatrix() {
	printf("\n");
	for(i=0;i<3;++i) {
		printf(" | ");
		for(j=0;j<4;++j) printf("%8.2f  ",a[i][j]);
		printf(" |  | %c |  %c  |%8.2f  |\n",(char)(i+119),i==1?'=':' ',a[i][4]);
	}
	printf(" \t\t\t\t\t\t\b| %c |\n\n",'z');
}

// TO SWAP THE ROWS x and y
void rowSwap(int x,int y) {
	for(i=0;i<5;++i) 
		swap(a[x][i],a[y][i]);
}

// TO SUBTRACT ROW NO. y FROM x
void rowOpr(int x,int y,int s) {
	for(i=s+1;i<5;++i) 
		a[x][i] -= a[y][i]*a[x][s]/a[y][s];
	if(s<4) a[x][s]=0;
}

/*
  TO UPDATE THE VALUES OF p, q, r where
  p STORES THE INDEX OF FIRST NON-ZERO ELEMENT IN 1st ROW
  q STORES THE INDEX OF FIRST NON-ZERO ELEMENT IN 2nd ROW
  r STORES THE INDEX OF FIRST NON-ZERO ELEMENT IN 3rd ROW
*/
void update() {
	for(p=0;p<4;++p) if(a[0][p]) break;
	for(q=0;q<4;++q) if(a[1][q]) break;
	for(r=0;r<4;++r) if(a[2][r]) break;
	if(p>q) swap(p,q), rowSwap(0,1);
	if(q>r) swap(q,r), rowSwap(1,2);
	if(p>q) swap(p,q), rowSwap(0,1);
}

int main() {
	int z=0;

	// TAKE THE INPUT
	printf("Let the equations be of the form:\n\nAw + Bx + Cy + Dz = E\n\nwhere A, B, C, D, E are constants and\nw, x, y, z are the variables\n\nEnter the coefficients of the first equation:\n");
	for(i=0;i<5;++i) {
		printf("%c = ",(char)(i+65));
		cin >> a[0][i];
	}
	printf("\nEnter the coefficients of the second equation:\n");
	for(i=0;i<5;++i) {
		printf("%c = ",(char)(i+65));
		cin >> a[1][i];
	}
	printf("\nEnter the coefficients of the third equation:\n");
	for(i=0;i<5;++i) {
		printf("%c = ",(char)(i+65));
		cin >> a[2][i];
	}
	
	printMatrix();

	// GAUSS JORDAN ELIMINATION
	update();rowOpr(1,0,p);rowOpr(2,0,p);
	update();rowOpr(2,1,q);
	update();rowOpr(1,2,r);rowOpr(0,2,r);
	update();rowOpr(0,1,q);
	update();
	for(i=p+1;i<5;++i) a[0][i]/=a[0][p];
	for(i=q+1;i<5;++i) a[1][i]/=a[1][q];
	for(i=r+1;i<5;++i) a[2][i]/=a[2][r];
	if(p<4) a[0][p] = 1;
	if(q<4) a[1][q] = 1;
	if(r<4) a[2][r] = 1;

	// CALCULATE THE DIMENSION
	if(p==4) z=4;
	else if(q==4) z=3;
	else if(r==4) z=2;
	else z=1;

	// CHECK FOR EXISTENCE OF SOLUTION
	if((z==2 && a[2][4]!=0) || (z==3 && (a[1][4]!=0 || a[2][4]!=0)) || (z==4 && (a[1][4]!=0 || a[2][4]!=0 || a[0][4]!=0))) {
		printf("Sadly no solution exists for the above set of equations.\nw,x,y,z ∈ ∅");
		return 0;
	}

	printf("after Gauss Jordan Elimination becomes...\n\n");
	printMatrix();
	printf("Dimension of solution space = %d\n\n",z);	

	// SOLUTION FOR 1 DIMENSION
	if(z==1) {
		if(p+q+r==3) printf("\tw\t= %8.2f - (%.2f)p\n\tx\t= %8.2f - (%.2f)p\n\ty\t= %8.2f - (%.2f)p\n\tz\t=\tp",a[0][4],a[0][3],a[1][4],a[1][3],a[2][4],a[2][3]);
		if(p+q+r==4) printf("\tw\t= %8.2f - (%.2f)p\n\tx\t= %8.2f - (%.2f)p\n\ty\t=\tp\n\tz\t= %8.2f",a[0][4],a[0][2],a[1][4],a[1][2],a[2][4]);
		if(p+q+r==5) printf("\tw\t= %8.2f - (%.2f)p\n\tx\t=\tp\n\ty\t= %8.2f\n\tz\t= %8.2f",a[0][4],a[0][1],a[1][4],a[2][4]);
		if(p+q+r==6) printf("\tw\t=\tp\n\tx\t= %8.2f\n\ty\t= %8.2f\n\tz\t= %8.2f",a[0][4],a[1][4],a[2][4]);
		printf("\n\nwhere p belongs to the Field\n");
	}

	// SOLUTION FOR 2 DIMENSIONS
	if(z==2) {
		if(p==0 && q==1) printf("\tw\t= %8.2f - (%.2f)p - (%.2f)q\n\tx\t= %8.2f - (%.2f)p - (%.2f)q\n\ty\t=\tp\n\tz\t=\tq",a[0][4],a[0][2],a[0][3],a[1][4],a[1][2],a[1][3]);
		if(p==0 && q==2) printf("\tw\t= %8.2f - (%.2f)p - (%.2f)q\n\tx\t=\tp\n\ty\t= %8.2f - (%.2f)q\n\tz\t=\tq",a[0][4],a[0][1],a[0][3],a[1][4],a[1][3]);
		if(p==0 && q==3) printf("\tw\t= %8.2f - (%.2f)p - (%.2f)q\n\tx\t=\tp\n\ty\t=\tq\n\tz\t= %8.2f",a[0][4],a[0][1],a[0][2],a[1][4]);
		if(p==1 && q==2) printf("\tw\t=\tp\n\tx\t= %8.2f - (%.2f)q\n\ty\t= %8.2f - (%.2f)q\n\tz\t=\tq",a[0][4],a[0][3],a[1][4],a[1][3]);
		if(p==1 && q==3) printf("\tw\t=\tp\n\tx\t= %8.2f - (%.2f)q\n\ty\t=\tq\n\tz\t= %8.2f",a[0][4],a[0][2],a[1][4]);
		if(p==2 && q==3) printf("\tw\t=\tp\n\tx\t=\tq\n\ty\t= %8.2f\n\tz\t= %8.2f",a[0][4],a[1][4]);
		printf("\n\nwhere p and q belong to the Field\n");
	}

	// SOLUTION FOR 3 DIMENSIONS
	if(z==3) {
		if(p==0) printf("\tw\t= %8.2f - (%.2f)p - (%.2f)q - (%.2f)r\n\tx\t=\tp\n\ty\t=\tq\n\tz\t=\tr",a[0][4],a[0][1],a[0][2],a[0][3]);
		if(p==1) printf("\tw\t=\tp\n\tx\t= %8.2f - (%.2f)q - (%.2f)r\n\ty\t=\tq\n\tz\t=\tr",a[0][4],a[0][2],a[0][3]);
		if(p==2) printf("\tw\t=\tp\n\tx\t=\tq\n\ty\t= %8.2f - (%.2f)r\n\tz\t=\tr",a[0][4],a[0][3]);
		if(p==3) printf("\tw\t=\tp\n\tx\t=\tq\n\ty\t=\tr\n\tz\t= %8.2f",a[0][4]);
		printf("\n\nwhere p, q and r belong to the Field\n");
	}

	// SOLUTION FOR 4 DIMENSIONS
	if(z==4) {
		printf("w, x, y and z belong to the Field\n");
	}
	return 0;
}
