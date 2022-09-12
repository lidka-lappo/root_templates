void IoExample() {

   TH1F* histo = new TH1F("histo","title;X;Count rate",100,-5.,5.);
   histo->FillRandom("pol2");

   TFile* out_file = new TFile("outfile.root","RECREATE"); 
   histo->Write(); 
   out_file->Close(); 
}
