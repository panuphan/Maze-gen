#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define ROW 11
#define COL 11
int main(int argc, char const *argv[])
{
	int map[ROW][COL][3]={0},way[4],hway;
	int i,j,r=0,c=0,ra;
	time_t t;
    srand((unsigned) time(&t));
    map[r][c][1]=1;
    map[r][c][2]=2;
    while(1){
    	for(i=0;i<4;i++)way[i]=0;
    	if(map[r][c-1][1]==0&&c!=0)way[0]=1;
    	if(map[r-1][c][1]==0&&r!=0)way[1]=1;
    	if(map[r+1][c][1]==0&&c!=ROW-1)way[2]=1;
   		if(map[r][c+1][1]==0&&c!=COL-1)way[3]=1;
   		hway=0;
   		for(i=0;i<4;i++)if(way[i]==1)hway++;
   		ra=rand()%(hway);
   		for(i=0;ra>=0;){
   			if(way[i]==1){
   				ra--;
   				i++;
   			}else if(way[i]==0)i++;
   		}
   		ra=i-1;
   
   		break;
	}
	return 0;
}