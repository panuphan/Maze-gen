#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define ROW 10
#define COL 10
int main(int argc, char const *argv[])
{
	int map[ROW][COL][3]={0},show[ROW*2+1][COL*2+1]={0},way[4],hway;
	int i,j,r=0,c=0,ra,w=0,sr=1,sc=1;
	//map for show
	for(i=0;i<=COL*2;i+=2){
		for(j=0;j<=COL*2;j++){
			show[i][j]=1;
		}
	}
	for(i=0;i<=ROW*2;i++){
		for(j=0;j<=COL*2;j+=2){
			show[i][j]=1;
		}
	}
	time_t t;
    srand((unsigned) time(&t));
    map[r][c][1]=1;
    map[r][c][2]=1;
    while(w<ROW*COL+1){
    	for(i=0;i<4;i++)way[i]=0;
    	if(map[r-1][c][1]==0&&r>0)way[0]=1;
    	if(map[r][c-1][1]==0&&c>0)way[1]=1;
    	if(map[r][c+1][1]==0&&c<COL-1)way[2]=1;
   		if(map[r+1][c][1]==0&&r<ROW-1)way[3]=1;
   		hway=0;
   		for(i=0;i<4;i++)if(way[i]==1)hway++;
   		printf("Move %d: p %d %d hway %d ",w+1,r,c,hway);
   		if(hway!=0)ra=rand()%(hway);
   		printf("rand %d have ", ra);
   		for(i=0;i<4;i++)printf("%d", way[i]);
   		printf("\n");
   		if(hway!=0){
   			for(i=0;ra>=0;){
   		   			if(way[i]==1){
   		   				ra--;
   		   				i++;
   		   			}else if(way[i]==0)i++;
   		   		}
   		   		ra=i-1;
   		   		printf(" move %d \n", ra);
   		   		switch(ra){
   		   			case 0:{
   		   				map[r][c][0]=85;
   		   				map[r][c][1]=1;
   		   				show[r*2][c*2+1]=0;
   		   				r--;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 1:{
   		   				map[r][c][0]=76;
   		   				map[r][c][1]=1;
   		   				show[r*2+1][c*2]=0;
   		   				c--;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 2:{
   		   				map[r][c][0]=82;
   		   				map[r][c][1]=1;
   		   				show[r*2+1][c*2+2]=0;
   		   				c++;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 3:{
   		   				map[r][c][0]=68;
   		   				map[r][c][1]=1;
   		   				show[r*2+2][c*2+1]=0;
   		   				r++;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   		}
   		}else{
   			//break;
   			w++;
   			map[r][c][2]=1;
   			for(i=0;i<ROW;i++){
   				for(j=0;j<COL;j++){
   				if(map[i][j][1]==1&map[i][j][2]==0){
   					r=i;
   					c=j;
   					break;
   					break;
   				}
   				}
   			}	
   			printf(" address %d %d\n",r,c);
   			
   		}
   		for(i=0;i<ROW;i++){
   			for(j=0;j<COL;j++){
   				printf("%c ",map[i][j][0]);
   			}
   			printf("\n");
   		}
	}
	printf("\n" );
	for(i=0;i<ROW;i++){
   		for(j=0;j<COL;j++){
   			printf("%d",map[i][j][1]);
   		}
   		printf("\n");
   	}
   	printf("\n" );
   	for(i=0;i<ROW;i++){
   		for(j=0;j<COL;j++){
   			printf("%d",map[i][j][2]);
   		}
   		printf("\n");
   	}
	printf("\n MAP \n");
	for(i=0;i<=ROW*2;i++){
   		for(j=0;j<=COL*2;j++){
   			//printf("%d",show[i][j]);
   			if (show[i][j]==1)printf("#");
   			if (show[i][j]==0)printf(" ");
   		}
   		printf("\n");
   	}
	return 0;
}