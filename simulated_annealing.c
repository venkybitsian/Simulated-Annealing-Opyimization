#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>

double Vsig, Fsig, Asig, Rsig;
double V1, F1, A1, R1, V2, F2, A2, R2, Y1, Y2, delE;

double StepThree() {
	printf("random number for step 3\n");
	 
	srand ( time(NULL) );
	double r;
	r = (rand()%100) / 100.0;
	
	return r;
}

double RandomNumbs() {
	
	int c=0;            
  	double n;   
 	double RandNumbs[12];
 	double sum;
 	sum = 0.0;
	  
  	srand ( time(NULL) );
	  
  	for (c = 0; c < 12; c++) {
	    n = (rand()%100) / 100.0;
	    RandNumbs[c] = n;
	    sum = sum + RandNumbs[c];
    }
  	 
  	return sum;
}

double * ConstraintsCheck() {
	
	static double p[6];
	double *val;
	double sum;
	Y1 = 0.202924-(0.0574*((V1 + 0.793536)*(V1 + 0.793536)))+(0.0215*((F1 + 3.5907)*(F1 + 3.5907)))+(0.3506*((A1 + 0.4066)*(A1 + 0.4066)))+(0.2746*((R1 + 0.394756)*(R1 + 0.394756)));
	
	sum =	RandomNumbs();	

	V2 = V1 + (Vsig*(sum - 6));
	F2 = F1 + (Fsig*(sum - 6));
	A2 = A1 + (Asig*(sum - 6));
	R2 = R1 + (Rsig*(sum - 6));
	
	//printf("%lf,%lf,%lf,%lf\n",V2,F2,A2,R2);
	
	if ( V2>=-1 && V2<=0.7756 && F2>=-1 && F2<=0.7095 && A2>=-1 && A2<=0.5129 && R2>=-1 && R2<=0.5849 ){
		Y2 = 0.202924-(0.0574*((V2 + 0.793536)*(V2 + 0.793536)))+(0.0215*((F2 + 3.5907)*(F2 + 3.5907)))+(0.3506*((A2 + 0.4066)*(A2 + 0.4066)))+(0.2746*((R2 + 0.394756)*(R2 + 0.394756)));
		delE = Y2 - Y1;
	 	p[0] = V2;
	 	p[1] = F2;
	 	p[2] = A2;
	 	p[3] = R2;
	 	p[4] = delE;




	 	p[5] = Y2;
	 	printf("constraints satisfied\n");
	} else {
	    sum = RandomNumbs();
		V2 = V1 + (Vsig*(sum - 6));
		F2 = F1 + (Fsig*(sum - 6));
		A2 = A1 + (Asig*(sum - 6));
		R2 = R1 + (Rsig*(sum - 6));
		Y2 = 0.202924-(0.0574*((V2 + 0.793536)*(V2 + 0.793536)))+(0.0215*((F2 + 3.5907)*(F2 + 3.5907)))+(0.3506*((A2 + 0.4066)*(A2 + 0.4066)))+(0.2746*((R2 + 0.394756)*(R2 + 0.394756)));
	 	delE = Y2 - Y1;
		printf("%lf",delE);
	 	printf("constraints not satisfied\n");
	 	val = ConstraintsCheck();
	}
		 
	return p;
}

int main() {
	
	double Vmin, Vmax, Fmin, Fmax, Amin, Amax, Rmin, Rmax;
	double *val;
	double T;
	T = 500.0;
	double r,k;
	int iter = 0;
	
	printf("Please enter desired range for speed\n");
	scanf("%lf, %lf", &Vmin, &Vmax);
	if ( Vmin == 150.0 && Vmax == 200.0 ) {
			Vmin = (log(Vmin) - log(200.0))/(log(200.0) - log(150.0));
			Vmax = (log(Vmax) - log(200.0))/(log(200) - log(150.0)); 
			Vsig = (Vmax - Vmin)/6;
			printf("%lf, %lf, %lf\n", Vmin, Vmax, Vsig);
	} else if ( Vmin == 200.0 && Vmax == 250.0 ) {
			Vmin = (log(Vmin) - log(200.0))/(log(200.0) - log(150.0));
			Vmax = (log(Vmax) - log(200.0))/(log(200.0) - log(150.0));
			Vsig = (Vmax - Vmin)/6;
			printf("%lf, %lf, %lf\n", Vmin, Vmax, Vsig);
	}
	
	printf("Please enter desired range for feed\n");
	scanf("%lf, %lf", &Fmin, &Fmax);
	if ( Fmin == 200.0 && Fmax == 300.0 ) {
			Fmin = (log(Fmin) - log(300))/(log(300) - log(200));
			Fmax = (log(Fmax) - log(300))/(log(300) - log(200));
			Fsig = (Fmax - Fmin)/6;
			printf("%lf, %lf, %lf\n", Fmin, Fmax, Fsig);
	} else if ( Fmin == 300.0 && Fmax == 400.0 ) {
			Fmin = (log(Fmin) - log(300))/(log(300) - log(200));
			Fmax = (log(Fmax) - log(300))/(log(300) - log(200));
			Fsig = (Fmax - Fmin)/6;
			printf("%lf, %lf, %lf\n", Fmin, Fmax, Fsig);
	}
	
	printf("Please enter desired range for rake angle\n");
	scanf("%lf, %lf", &Amin, &Amax);
	if ( Amin == 4.0 && Amax == 10.0 ) {
			Amin = (log(Amin) - log(10))/(log(10) - log(4));
			Amax = (log(Amax) - log(10))/(log(10) - log(4));
			Asig = (Amax - Amin)/6;
			printf("%lf, %lf, %lf\n", Amin, Amax, Asig);
	} else if ( Amin == 10.0 && Amax == 16.0 ) {
			Amin = (log(Amin) - log(10))/(log(10) - log(4));
			Amax = (log(Amax) - log(10))/(log(10) - log(4));
			Asig = (Amax - Amin)/6;
			printf("%lf, %lf, %lf\n", Amin, Amax, Asig);
	}
	
	printf("Please enter desired range for nose radius\n");
	scanf("%lf, %lf", &Rmin, &Rmax);
	if ( Rmin == 0.4 && Rmax == 0.8 ) {
			Rmin = (log(Rmin) - log(0.8))/(log(0.8) - log(0.4));
			Rmax = (log(Rmax) - log(0.8))/(log(0.8) - log(0.4));
			Rsig = (Rmax - Rmin)/6;
			printf("%lf, %lf, %lf\n", Rmin, Rmax, Rsig);
	} else if ( Rmin == 0.8 && Rmax == 1.2 ) {
			Rmin = (log(Rmin) - log(0.8))/(log(0.8) - log(0.4));
			Rmax = (log(Rmax) - log(0.8))/(log(0.8) - log(0.4));
			Rsig = (Rmax - Rmin)/6;
			printf("%lf, %lf, %lf\n", Rmin, Rmax, Rsig);
	}
	
	printf("Please enter initial V1,F1,A1,R1\n");
	scanf("%lf,%lf,%lf,%lf", &V1, &F1, &A1, &R1);
	V1 = (log(V1) - log(200))/(log(200) - log(150));
	F1 = (log(F1) - log(300))/(log(300) - log(200));
	A1 = (log(A1) - log(10))/(log(10) - log(4));
	R1 = (log(R1) - log(0.8))/(log(0.8) - log(0.4));
	
	

	do {
		val = ConstraintsCheck();
		if ( val[4]<0 && iter<50 ) {
			V1 = val[0];
			F1 = val[1];
			A1 = val[2];
			R1 = val[3];
			iter = iter +1;
			//val = ConstraintsCheck();
			printf("in loop 1 iter = %d,%lf\n",iter,val[4]);
			printf("%lf\n",T);
		} else if ( val[4]<0 && iter>50 ) {
			if (T>1) {
				T = 0.9*T;
				V1 = val[0];
				F1 = val[1];
				A1 = val[2];
				R1 = val[3];
				iter = iter +1;
				//val = ConstraintsCheck();
				printf("iter greater than 50,delE less than 0,T greater than 1 = %lf\n",T);
			} else {
				continue;
			}
			printf("iter is greater than 50 and delE is less than 0\n");
		} else if ( val[4]>0 ) {
			r = StepThree();
			k = exp(-val[4]/T);
			if (r<=k){
				if ( iter<50 ) {
					V1 = val[0];
					F1 = val[1];
					A1 = val[2];
					R1 = val[3];
					iter = iter +1;
					//val = ConstraintsCheck();
					printf("r is less than k and iter is less than 50\n");
				} else {
					if (T>1) {
						T = 0.9*T;
						V1 = val[0];
						F1 = val[1];
						A1 = val[2];
						R1 = val[3];
						iter = iter +1;
						//val = ConstraintsCheck();
						printf("r is less than k, iter greater than 50, T greater than 1\n");
					} else {
						continue;				
					}
				}
			} else {
				continue;
				//val = ConstraintsCheck();
			}
			printf("delE is greater than 0\n k = %lf\n T = %lf\n",k,T);
		} 
	} while(T>1);	
	
	val[0] = exp(((val[0])*(log(200)-log(150))) + log(200));
	val[1] = exp(((val[1])*(log(300)-log(200))) + log(300));
	val[2] = exp(((val[2])*(log(10)-log(4))) + log(10));
	val[3] = exp(((val[3])*(log(0.8)-log(0.4))) + log(0.8));
	
	printf("optimum values are speed = %lf, feed = %lf, rake angle = %lf,nose radius = %lf,\n min. roughness = %lf\n",val[0],val[1],val[2],val[3],val[5]);

}
