void histogram(Int_t iterations=1, Int_t numDies=3) {

  TString caption = "Throw with ";
  caption += numDies;
  caption += " dices;Pips;Count rate";

  Int_t numBins=6*numDies + 2;
  Float_t upperBound = numBins + 0.5;

  TH1S* dices = new TH1S("dices",caption, numBins,0.5,upperBound);

  TRandom* die = new TRandom();
  die->SetSeed(0);

  Float_t* value = new Float_t[numDies];

  for (Int_t i=0; i<iterations;++i) {
    die->RndmArray(numDies,value);
    Int_t sum = 0;
    for (Int_t j=0; j<numDies;++j) {
      sum += static_cast<Int_t>((value[j]*6) + 1);
    }
    dices->Fill(sum);
  }

  dices->Draw();

}
