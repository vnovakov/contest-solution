//### Program


/*

Problem: 3
Name: Vladimir Novakovski
Email: vnovakov@lan.tjhsst.edu
School: Thomas Jefferson High School for Science and Technology
Grade: 9
Age: 13
CityState: Springfield, VA
Country: USA

*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TFACTR 0.9
#define MBIG 1000000000
#define MSEED 161803398
#define MZ 0
#define FAC (1.0/MBIG)
#define IB1 1
#define IB2 2
#define IB5 16
#define IB18 131072

int matrix[101][101];

time_t time0, time1;

int irbit1(iseed)
unsigned long *iseed;
{
	unsigned long newbit;

	newbit = (*iseed & IB18) >> 17
		^ (*iseed & IB5) >> 4
		^ (*iseed & IB2) >> 1
		^ (*iseed & IB1);
	*iseed=(*iseed << 1) | newbit;
	return (int) newbit;
}

float ran3(idum)
long *idum;
{
	static int inext,inextp;
	static long ma[56];
	static int iff=0;
	long mj,mk;
	int i,ii,k;

	if (*idum < 0 || iff == 0) {
		iff=1;
		mj=MSEED-(*idum < 0 ? -*idum : *idum);
		mj %= MBIG;
		ma[55]=mj;
		mk=1;
		for (i=1;i<=54;i++) {
			ii=(21*i) % 55;
			ma[ii]=mk;
			mk=mj-mk;
			if (mk < MZ) mk += MBIG;
			mj=ma[ii];
		}
		for (k=1;k<=4;k++)
			for (i=1;i<=55;i++) {
				ma[i] -= ma[1+(i+30) % 55];
				if (ma[i] < MZ) ma[i] += MBIG;
			}
		inext=0;
		inextp=31;
		*idum=1;
	}
	if (++inext == 56) inext=1;
	if (++inextp == 56) inextp=1;
	mj=ma[inext]-ma[inextp];
	if (mj < MZ) mj += MBIG;
	ma[inext]=mj;
	return mj*FAC;
}

int metrop(de,t)
long de; float t;
{
	static long gljdum=1;
	if (de < 0) return 1;
	if ((rand() % 10000)/10000.0 < exp(-(float)de/t))
		return 1;
	return 0;
}

void trnspt(iorder,ncity,n)
int iorder[],n[],ncity;
{
	int m1,m2,m3,nn,j,jj;

	int jorder[100];
	m1=1 + ((n[2]-n[1]+ncity) % ncity);
	m2=1 + ((n[5]-n[4]+ncity) % ncity);
	m3=1 + ((n[3]-n[6]+ncity) % ncity);
	nn=1;
	for (j=1;j<=m1;j++) {
		jj=1 + ((j+n[1]-2) % ncity);
		jorder[nn++]=iorder[jj];
	}
	if (m2>0) {
		for (j=1;j<=m2;j++) {
			jj=1+((j+n[4]-2) % ncity);
			jorder[nn++]=iorder[jj];
		}
	}
	if (m3>0) {
		for (j=1;j<=m3;j++) {
			jj=1 + ((j+n[6]-2) % ncity);
			jorder[nn++]=iorder[jj];
		}
	}
	for (j=1;j<=ncity;j++)
		iorder[j]=jorder[j];
}

long trncst(iorder,ncity,n)
int iorder[],n[],ncity;
{
	long de;
	int j,ii;

	n[4]=1 + (n[3] % ncity);
	n[5]=1 + ((n[1]+ncity-2) % ncity);
	n[6]=1 + (n[2] % ncity);

	de = -matrix[iorder[n[2]]][iorder[n[6]]];
	de -= matrix[iorder[n[1]]][iorder[n[5]]];
	de -= matrix[iorder[n[3]]][iorder[n[4]]];
	de += matrix[iorder[n[1]]][iorder[n[3]]];
	de += matrix[iorder[n[2]]][iorder[n[4]]];
	de += matrix[iorder[n[5]]][iorder[n[6]]];
	return de;
}


void reverse(iorder,ncity,n)
int iorder[],n[],ncity;
{
	int nn,j,k,l,itmp;

	nn=(1+((n[2]-n[1]+ncity) % ncity))/2;
	for (j=1;j<=nn;j++) {
		k=1 + ((n[1]+j-2) % ncity);
		l=1 + ((n[2]-j+ncity) % ncity);
		itmp=iorder[k];
		iorder[k]=iorder[l];
		iorder[l]=itmp;
	}
}

long revcst(iorder,ncity,n)
int iorder[],n[],ncity;
{
	long de;
	int j,ii;

	n[3]=1 + ((n[1]+ncity-2) % ncity);
	n[4]=1 + (n[2] % ncity);

	de = -matrix[iorder[n[1]]][iorder[n[3]]];
	de -= matrix[iorder[n[2]]][iorder[n[4]]];
	de += matrix[iorder[n[1]]][iorder[n[4]]];
	de += matrix[iorder[n[2]]][iorder[n[3]]];
	return de;
}


long anneal(int ncity)
{
	int iorder[101];
	int ans,nover,nlimit,i1,i2;
	int i,j,k,nsucc,nn,idec;
	static int n[7];
	long idum;
	long iseed;
	long path, de; float t;

	nover=100*ncity;
	nlimit=10*ncity;
	path=0;
	t=0.5;
	for (i=1;i<ncity;i++) {
		iorder[i] = i;
      iorder[i+1] = i + 1;
		i1=iorder[i];
		i2=iorder[i+1];
		path += matrix[i1][i2];;
	}
	i1=iorder[ncity];
	i2=iorder[1];
	path += matrix[i1][i2];
	idum = -1;
	iseed=111;
	for (j=1;j<=100;j++) {
		nsucc=0;
		for (k=1;k<=nover;k++) {
			do {
				time1 = time(NULL);

				if (abs(difftime(time1, time0)) > 4)
				return path;
				n[1]=1+(int) (ncity*ran3(&idum));
				n[2]=1+(int) ((ncity-1)*ran3(&idum));
				if (n[2] >= n[1]) ++n[2];
				nn=1+((n[1]-n[2]+ncity-1) % ncity);
			} while (nn<3);
			idec=irbit1(&iseed);
			if (idec == 0) {
				n[3]=n[2]+(int) (abs(nn-2)*ran3(&idum))+1;
				n[3]=1+((n[3]-1) % ncity);
				de=trncst(iorder,ncity,n);
				ans=metrop(de,t);
				if (ans) {
					++nsucc;
					path += de;
					trnspt(iorder,ncity,n);
				}
			} else {
				de=revcst(iorder,ncity,n);
				ans=metrop(de,t);
				if (ans) {
					++nsucc;
					path += de;
					reverse(iorder,ncity,n);
				}
			}
			if (nsucc >= nlimit)
				break;
		}

		t *= TFACTR;
		if (nsucc == 0) return path;
	}
}

void main()
{
	int ncity, i, j;
	FILE *infile, *f;
	infile = fopen("INPUT.TXT", "r");
	time0 = time(NULL);
	randomize();
	f = fopen("OUTPUT.TXT", "w");
	fscanf(infile, "%d", &ncity);
	for (i = 1; i <= ncity; i++)
		for (j = 1; j <= ncity; j++)
			fscanf(infile, "%d", &matrix[i][j]);
	ncity++;
	for (i = 1; i <= ncity; i++)
		matrix[ncity][i] = 100;
	for (i = 1; i <= ncity; i++)
		matrix[i][ncity] = 100;
	matrix[ncity][ncity] = 0;

	fprintf(f, "%d", anneal(ncity) - 200);
	fprintf(f, "%c", '\n');

	fclose(infile);
	fclose(f);
}

#undef IB1
#undef IB2
#undef IB5
#undef IB18
#undef MBIG
#undef MSEED
#undef MZ
#undef FAC
#undef TFACTR

//### End