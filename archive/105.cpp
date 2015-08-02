/* @JUDGE_ID: 3207EZ 105 C++ */

#include <stdio.h>
#include <iostream.h>

int x,y,z,t,i,j,k,l,m,n;
int skyline[10000];  /* s[i] tells the
		  max height at i+0.5 */

int main() {

  t=10000;m=0;
  while (cin >> x >> y >> z) {
	 if (x==0) break;
	 if (x<t) t=x;
	 if (z>m) m=z;
	 for (i=x;i<z;i++)
		if (y>skyline[i]) skyline[i]=y;
  }
  while (t<=10001) {
	 printf("%d %d ",t,skyline[t]);
	 y=t;
	 do { t++; if (t>m) break;
	 } while (skyline[t]==skyline[y]);
	 if (t>m) break;
  }
  printf("\n");
  return 0;
}



