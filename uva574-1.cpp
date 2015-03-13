#include<iostream>
#include<cstdio>
using namespace std;

//int sump( int, int, int, int*, int, int*, int );
int t, n;
int x[20], ans[20];
int sump( int i, int sum, int ansp ,int ans[]){
  if( i == n ) return 0;
  sum += x[i];
  if( sum > t ){
    sum -= x[i];
    for( i++ ; i < n ; i++ )
      if( x[i-1] != x[i] ) break;
    return sump( i, sum, ansp, ans);
  }
  else if( sum < t ){
    ans[ansp++] = x[i];
    int result = sump( i+1, sum, ansp, ans);
    sum -= x[i];
    for( i++ ; i < n ; i++ )
      if( x[i-1] != x[i] ) break;
    return result + sump( i, sum, ansp-1, ans);
  }
  else{		//sumµ¥©ót®É
    bool flag = false;
    for( int j = 0 ; j < ansp ; j++ ){
		if( flag ) 
			printf( "+" );
		printf( "%d", ans[j] );
		flag = true;
    }
    if( flag ) printf( "+" );
    printf( "%d", x[i] );
    printf( "\n" );
    sum -= x[i];
    for( i++ ; i < n ; i++ )
      if( x[i-1] != x[i] ) break;
    return 1 + sump( i, sum, ansp, ans);
  }
}
int main(){
  while( scanf( "%d %d", &t, &n ) != EOF && ( t || n ) ){
    for( int i = 0 ; i < n ; i++ )
      scanf( "%d", &x[i] );
    printf( "Sums of %d:\n", t );
    if( !sump( 0, 0, 0, ans) )
      printf( "NONE\n" );
  }
  return 0;
}