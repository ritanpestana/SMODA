void BeamProfile()
{
	//TCanvas *c1 = new TCanvas();
	gStyle->SetPalette(kRainBow);
	TFile *input = new TFile("topas.root", "read");

	TTree *tree = (TTree*)input->Get("OutputCube");

	float x, y, z;

	tree->SetBranchAddress("Position_X__cm_", &x);
	tree->SetBranchAddress("Position_Y__cm_", &y);
	tree->SetBranchAddress("Energy__MeV_", &z);

	int entries = tree->GetEntries();

	//cout << entries << endl;
	TH2F *hist = new TH2F("hist", "Energy in Water", 1000, -0.2, 0.2, 1000, -0.2, 0.2);
	//hist->SetStats(0);
	TH1F *hist1 = new TH1F("hist", "Energy in Water", 100, -2, 2);

	for(int i = 0; i < entries; i++)
	{
		tree->GetEntry(i);
		//cout << x << " " << y << " " << z << endl;
		hist->Fill(x, y, z);
	}

	hist->SetContour(1000);

	hist->GetXaxis()->SetTitle("x [cm]");
	hist->GetYaxis()->SetTitle("y [cm]");
	hist->GetZaxis()->SetTitle("Energy [MeV]");


	hist->Draw("colz");

	input->Close();
}