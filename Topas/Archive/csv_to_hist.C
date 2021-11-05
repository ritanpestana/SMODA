vector<string> vector_split(string s, char delimiter);

vector<string> vector_split(string s, char delimiter)
	{
   		vector<string> tokens;
   		string token;
   		istringstream tokenStream(s);
   		while (getline(tokenStream, token, delimiter))
   		{
      			tokens.push_back(token);
   		}
   	return tokens;
	}

int nbins = 1000;

void csv_to_hist(){
  TString name = "counts_water.csv";
  TH1F* hist_maker(TString name);
	ifstream in;

	

	string counts;
	
	TH1F *h1 = new TH1F("h1","Energy Counts on the Water Sphere",nbins,10/nbins,10.);
  	string del = ", ";
	in.open(name, ios::in);
	int i = 0;
	vector<string> y;
	while(!in.eof()){
		i++;
		cout << i << endl;
		getline(in,counts);
		if(i == 8){
			//cout << "Hi";
			y = vector_split(counts,',');
			cout << y[0] << endl;
		}
		


  	} //end while

	/*TCanvas *c1 = new TCanvas("c1","1 RPC",200,10,700,500);
 	c1->SetGrid();
	c1->GetFrame()->SetBorderSize(12);*/
	int n = 1;
	//cout << y.size()<< endl;
	for(n=1;n < y.size();n++){
		cout << n << "\t" << stoi(y[n]) << endl;
		h1->Fill(n*10./nbins, stoi(y[n]));
	}

	//TFile *out_file = new TFile("counts_water.root", "recreate");
	h1->SetXTitle ("E [MeV]");
	h1->SetYTitle ("Counts");	
	h1->Draw("hist");
	//out_file->Close();
 
	return 0;
} //end csv_to_hist

