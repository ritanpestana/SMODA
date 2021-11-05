using namespace std;	

	
	const char *file_name = "counts_water.csv";
	int nbins = 1000;

	
	int y1[nbins];
	
	TH1* h = new TH1D("h1", "Energy Deposition on the Sphere",nbins, 0.0, 10.0);

	infile.open(file_name);// file containing numbers in 3 columns 
        if(infile.fail()) // checks to see if file opended 
    	{ 
        	cout << "error" << endl; 
      		return 1; // no point continuing if the file didn't open...
   	 } 
       	while(num<=n) // reads file to end of *file*, not line
      	{ 
         infile >> x1[num]; // read first column number
         infile >> y1[num]; // read second column number
         infile >> ey1[num]; // read third column number

         ++num; // go to the next number

         // you can also do it on the same line like this:
         // infile >> exam1[num] >> exam2[num] >> exam3[num]; ++num;
      } 
  	infile.close(); 
