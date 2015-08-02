#include <stdio.h>
#include <stdlib.h>


#define INFILE  "CONTACT.IN"
#define OUTFILE "CONTACT.OUT"
#define SIZE   2*4096
#define MAXPAT 16

typedef struct
{
  int  index;
  long val;
}
Pair;


static Pair table[SIZE];
static int MSK[MAXPAT];

void InitPatternTable()
{
  int i,p;
  p = 0;
  for(i=0;i<MAXPAT;i++)
    {
      p <<= 1;
      p |= 1;
      MSK[i]=p;
    }
  for(i=0;i<SIZE;i++)
  {
    table[i].index=i;
    table[i].val=0;
  }
}


void PrintPattern(FILE *of,int i)
{
  char s[MAXPAT], *p;
  int j,l;
  for(j=1;j<MAXPAT;j++)
    {
      l = MAXPAT-(j+1);
      if((i&1)!=0) s[l]='1';
      else s[l]='0';
      i >>= 1;
    }
  s[MAXPAT-1]=0;
  p = s;
  while(*p!='1')
      p++;
  fprintf(of,p+1);
}


int LT(Pair a, Pair b)
{
  if(a.val == b.val)
    return b.index > a.index;
  else
  return b.val > a.val;
}

void Sort(int lo, int up)
{
int flag, i, j;
Pair tempr;

i=up-1;
while(i>=lo)
{
  tempr = table[i];
  j = i+1;
  flag = 1;
  while((j<=up) && flag)
  {
    if(LT(tempr,table[j]))
    {
      table[j-1] = table[j];
      j++;
    }
    else flag = 0;
    table[j-1] = tempr;
  }
  i--;
}
}

int LT0(Pair *a, Pair *b)
{
  if((a->val) == (b->val))
      return b->index - a->index;
  else {
      if(a->val > b-> val) return -1;
	else if(a -> val < b->val) return 1; else return 0;
  }
}

typedef int (*ff)(const void *, const void*);


void MakeListing(int M, int L,int N)
{
  int i,l;
  long c;
  int T = MSK[L]+1;
  FILE *of;

  qsort(table+MSK[M-1]+1, MSK[L]-MSK[M-1],sizeof(Pair),(ff)LT0);

  /*
  Sort(MSK[M-1]+1,MSK[L]);
  */

  of = fopen(OUTFILE,"w+");
  i=MSK[M-1]+1;
  while(table[i].val==0) i++;
  for(l=0;(l<N) && (table[i].val);l++)
    {
      fprintf(of,"%ld ",c=table[i].val);
      while(table[i].val == c)
	{
	  PrintPattern(of,table[i].index);
	  i++;
	  if(table[i].val == c)
	    fprintf(of," ");
	  else fprintf(of,"\n");
	  if(i==T) goto done1;
	}
    }
 done1:;
 fclose(of);
}

void ProcessFile(FILE *f, int M, int L)
{
  int i;
  int mask;
  unsigned int p = 0;
  long b = 0;
  int mu;
  int ch;
  int pp;
  int li;

  printf("Scanning file ...");

  /* Set the bitmask for pattern length */

  mask = MSK[L+1];

  /* Init with first M bits */

  while(b<M)
    {
      ch = getc(f);
      b++;
      p <<= 1;
      if(ch=='1') p |= 1;
    }

  /* update "first" table position */

  mu = MSK[M-1];
  pp = mu+1+(p&mu);
  table[pp].val=1;

  for(;;)
    {

      /* read next bit */

      ch = getc(f);
      if(ch=='2') break;

      b++;

      /* update current pattern */

      p <<= 1;
      if(ch=='1')
	p |= 1;
      p &= mask;

      li = (b<=L)?(b+1):L+1;

      /* update all preceeding table positions */

      for(i=M-1;i<li;i++)
	{
	  mu = MSK[i-1];
	  pp = mu+1+(p&mu);
	  table[pp].val++;
	}
    }

  printf(" done.\n");
}

void Stub(char *infile)
{
  FILE *f ;
  int M,L,T;

  InitPatternTable();
  f = fopen(infile,"r");
  if(f)
    {
      fscanf(f,"%d\n",&M);
      fscanf(f,"%d\n",&L);
      fscanf(f,"%d\n",&T);
      printf("Initial data read.\n");
      ProcessFile(f,M,L);
      MakeListing(M,L,T);
      fclose(f);
    }
}

void main(void)
{
  Stub(INFILE);
  exit(0);
}
