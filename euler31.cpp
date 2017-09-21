#include <iostream> 
int Coins[8] ={200,100,50,20,10,5,2,1}; 

#define VALUE 200

int combinations = 0;
int ways = 0;

void recurse(int sum, int ind){
	  
		if(sum<Coins[ind]){
			return;
		}
		//std::cout<<"Used coin : "<<Coins[ind]<<std::endl;
		int val = sum - Coins[ind];
		//std::cout<<"Remained value: "<<val<<std::endl;
		if(val==0){
			combinations++;
		//	std::cout<<"Found!"<<std::endl;
			//std::cin.get();
			return;
		}
		else{
			if(val>=Coins[ind]){
				recurse(val,ind);
				if(ind!=7)
					recurse(val,ind+1);
			}
			else if(val<=Coins[ind])
				recurse(val,ind+1);//For current iteration
				for(int j=ind+2;j<8;j++)
					recurse(val,j);
		}
}

int main(){
	for(int i=0;i<8;i++){
		if(VALUE<Coins[i])
			continue;
		recurse(VALUE,i);
	}
	std::cout<<"combs: "<<combinations<<std::endl;
	return 0;
}
