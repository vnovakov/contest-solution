/* @JUDGE_ID:  3207EZ  117 C++  */
#include <iostream.h>
#include<stdio.h>
#include<string.h>
int adj[26][26];
int degree[26];
const int inf=10000;
int main() {
  char s[100];
  long x=0,low,odd,a,b,i;
  if (!(cin >> s)) return 0;
  while (strcmp(s,"")!=0) {
	 memset(adj,inf,sizeof adj);
	 memset(degree,0,sizeof degree);
	 x=0;
	 while (strcmp(s,"deadend")!=0) {
		adj[s[0]-'a'][s[strlen(s)-1]-'a'] = strlen(s);
		adj[s[strlen(s)-1] -'a'][s[0]-'a'] = strlen(s);
		degree[s[0]-'a']++;
		degree[s[strlen(s)-1]-'a']++;
		x+=strlen(s);
		if (!(cin >> s)) return 0;
	 }
	 odd=0;  a=-1; b=-1;
	 for (i=0;i<26;i++) if (degree[i]&1) {
		odd++;
		if (a==-1) a=i; else b=i;
	 }
	 if (odd==0) {
		cout << x << endl;
	 } else {
		int i,j,k;
		for (k=0;k<26;k++)
		  for(i=0;i<26;i++)
			 for(j=0;j<26;j++)
				if (adj[i][k]+adj[k][j]<adj[i][j]) {
				  adj[i][j]=adj[i][k]+adj[k][j];
			  }
		 cout <<  x+adj[a][b] << endl;
	 }
	 if (!(cin >> s)) return 0;
  }
  return 0;
}







