#include <stdio.h>
#include <math.h>


//Program that turns binary into hexadecimal, decimal and unsigned decimal  

//Function that turns binary array into an unsigned integer 
unsigned long long bintoUnsigned(long long b[], int size){
	unsigned long long result=0;
	unsigned long long one = 1; //Both these variables have to be unsigned long long to avoid casting 
	for(int i=0; i<size; i++){
		if(b[i]==1){ 
			result+=one<<i; //Adding together powers of 2  
		}
	}
	return result;
}

//Function that turns binary array into a signed integer 
long long bintoSigned(long long b[], int size){
	long long result=0;
	long long one = 1; //Both these variables have to be long long to avoid casting
	long long negOne = -1;
	if(b[size-1]==0){ //If the binary number starts 0 it can be treated as a unsigned int
		return bintoUnsigned(b, size);
	}
	else{
		long long result= b[size-1]*(one<<(size-1))*(negOne); //Take the msb times 2 to the correct power as a negative
		for(int i=0; i<size-1; i++){
			result+=b[i]*(one<<i); //Then add the other bits times 2 to the correct power as positives
			printf("%lld\n", result);
		}
		return result;
	}
	return result;
}

//Main - gets inputs, calls other functions, prints outputs 
int main(void){
	//Setting up scanner
	printf("Enter number between 1 and 64: \n");
	int num;
	scanf("%d", &num);
	long long b[num]; //This is a long long to avoid casting 
	//Filling in bit array
	for(int i=0; i<num;i++){ 
		int bit;
		printf("Enter bit %d: \n", i);
		scanf("%d", &bit);
		b[i]= bit;
	}

	//Printing out the binary 
	printf("binary: ");
	for(int i=num-1; i>=0; i--){ //loop starts from MSB
		printf("%lld", b[i]);
	}

	//Calling conversion functions 
	unsigned long long u = bintoUnsigned(b, num);
	long long s = bintoSigned(b, num);

	//Printing results. 
	printf("\n");
	printf("hexadecimal: 0x");
	printf("%llX", u); //Using the unsigned number and the hex format 
	printf("\n");
	printf("decimal (signed): %lld",s);
	printf("\n");
	printf("decimal (unsigned): %lld", u);
	return 0;
}