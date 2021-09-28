/*
** hw8_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/

#include <stdio.h>
#include "hw8_lib.h"

#define WORDSIZE 2 
#define MAX 200 /* MAX SIZE OF THE ANY LINE */


long int findPower(int base,int exponent){
long int result = 1;
	for (exponent; exponent>0; exponent--)
	{
	result = result * base;
	}
return result;
}
long int transformtoInt(int arr[7]){
	int i,k;
	long int ret=0;
	for(i=6;i>-1;i--){
		if(arr[i]!=0){
			ret+= (long int) arr[i]*(long int) findPower(10,6-i);
		}
	}
return ret;
}
void printVertically(long int x){
	printf("  ");
	int i;
	long int q;
	int nr=0;
	long int p=1;
	int par;
    q=x;
    while (x!=0)
    {
        nr=nr+1;
        x=x/10;
    }
    for (i=1;i<nr;i++)
    {
        p=p*10;
    }
    while (q!=0)
    {
        par=q/p;
        q=q%p;
        p=p/10;
        printf("%d\n",par);
    }
}

/*source: source cell target: tower element goes to this cell */
int findtheUpper(int array[7],int n){ /* returns the first nonzero element in the given array */
	int i,ret;
	for(i=0;i<7;i++){
		if(array[i]==0){
			ret= i;
			return ret;
		}
	}
	return 0;
}
void initialise(int s[7],int a[7],int e[7],int n){
int k,i;
	for(i=n;i>-1;i--){
		s[k]=i;
		k++;
		}
	for(i=0;i<7;i++){
		a[i]=0;
		e[i]=0;
		}
	}
void printBuffer1(int arr[7]){
	long int x= transformtoInt(arr); 
	printVertically(x);
	printf(" ");
}
	

void print(char source,char target,int count,int s[7],int a[7],int e[7],int n){
	printf("=============================  STEP %d =============================\n",count);
	int ret1,ret2,i;
	printBuffer1(s);
	printf(" ");
	printBuffer1(a);
	printf(" ");
	printBuffer1(e);
	
	count++;	
	if(source== 'S'&& target== 'A'){
		ret1=findtheUpper(s,n);
		ret2=findtheUpper(a,n);
		a[ret2]= s[ret1-1];
		s[ret1-1]=0;
	}
	else if(source== 'S'&& target== 'E'){
		ret1=findtheUpper(s,n);
		ret2=findtheUpper(e,n);
			e[ret2]= s[ret1-1];
			s[ret1-1]=0;

	}
	
	else if(source== 'A'&& target== 'E'){
		ret1=findtheUpper(a,n);
		ret2=findtheUpper(e,n);
			e[ret2]= a[ret1-1];
			a[ret1-1]=0;
		
	}
	else if(source== 'A'&& target== 'S'){
		ret1=findtheUpper(a,n);
		ret2=findtheUpper(s,n);
			a[ret2]= s[ret1-1];
			s[ret1-1]=0;
	}
		else if(source== 'E'&& target== 'A'){
		ret1=findtheUpper(e,n);
		ret2=findtheUpper(a,n);
		a[ret2]= e[ret1-1];
		e[ret1-1]=0;
	}
	else if(source== 'E'&& target== 'S'){
		ret1=findtheUpper(e,n);
		ret2=findtheUpper(s,n);
		s[ret2]= e[ret1-1];
		e[ret1-1]=0;
	}

}

static int count1=0;
static int start[7]={0};
static int aux[7]={0};
static int end[7]={0};
int a=0;
void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n){
	if(a==0){
		int i;
		int k=0;
	for(i=n;i>0;i--){
		start[k]=i;
		k++;
	}
		a++;
	}
 if (n == 1)
    {	 
		count1++;
		print(start_peg,end_peg,count1,start,aux,end,n);  
        return;
    }
    towers_of_hanoi(start_peg, aux_peg, end_peg,n-1);
    count1++;
    print(start_peg,end_peg,count1,start,aux,end,n);
    towers_of_hanoi(aux_peg, end_peg, start_peg,n-1);
}


