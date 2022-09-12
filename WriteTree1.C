void WriteTree1()
{
   //create a Tree file tree1.root


   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   Bool_t boolVal;

   //create the Tree and a few branches
   TTree t1("t1","a simple Tree with simple variables");

   // Add a branches to the Tree, one branch per variable
   // First parameter is a the branch name
   // Second parameter connect the branch with the variable
   // Third parameter defines the variable type 
   t1.Branch("px",&px,"px/F"); 
   t1.Branch("py",&py,"py/F");
   t1.Branch("pz",&pz,"pz/F");
   t1.Branch("random",&random,"random/D");
   t1.Branch("ev",&ev,"ev/I");
   t1.Branch("bool",&boolVal,"bool/O");

   //fill the tree
   for (Int_t i=0;i<10000;i++) {
     gRandom->Rannor(px,py);
     pz = px*px + py*py;
     random = gRandom->Rndm();
     if (random < 0.5) {
       boolVal = false;
     } else {
       boolVal = true;
     }
     ev = i;
     t1.Fill();
  }

   TFile f("tree1.root","recreate");
  //save the Tree header. The file will be automatically closed
  //when going out of the function scope
  t1.Write();
}
