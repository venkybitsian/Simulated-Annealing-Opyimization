# Simulated-Annealing-Optimization

I attach the sample code that I use to optimize the roughness in machining process with simulated annealing technique on 4 params

Algorithm 
Step 1: Choose an initial point xk(v,f,r,α) , a termination criterion Є(T=1). Set T a sufficiently high value(500), number of iterations to be performed at a particular temperature n and set t = 0.

Step 2: Calculate a neighboring point Xk+1.Usually a random point in the neighborhood is selected by Gaussian Distribution for speed and feed as
                      Xk+1=Xk + σ (Ʃi=1 to nri-n/2)
where σ  is standard deviation, ri the random number and n is the number of random number.

Step 3:  ∆E=E(Xk+1)-E(Xk)≤0 and Set k=k+1;

Else create a random number r in the range (0, 1) if r≤exp(-∆E/kT)set k=k+1.Else go to Step 2.
Step 4: If T is small, terminate. Else lower T according to a cooling schedule. Else go to Step 2.

v,f,r,α= velocity, feed, rake angle, nose radius

Here we have objective function defined, plugged inside code
 The data:
 https://drive.google.com/drive/folders/0B9NoVwqhH5DbUFNBM0hPb1h2T3M
 
 Inputs provided: We provide range of input params, and Simulated annealing provides the optimized results in that range
 as Output
 
 Example:(changed range as required)
 Input:  Speed range: 200,250
         Feed range: 200, 300
         rake: 4,10
         nose radius: 0.2,0.8
         Initialize with random values
 
 Output:
optimum values are speed = 245.675129, feed = 267.260789, rake angle = 9.627136,nose radius = 
0.820742,                                                                                     
 min. roughness = 0.405158 
 
 Reference:
 N. Suresh Kumar Reddy, P. Venkateswara Rao, A genetic algorithmic approach for optimization of surface roughness prediction model in dry milling, Machining Science and Technology – An International Journal 9(1) (2005) pages 63-84.




