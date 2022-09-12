void withFit() 
{
  TGraphErrors* graph = new TGraphErrors("ExampleInput.txt", "%lg %lg %lg %lg");

  graph->SetTitle("Fake Measurement;distance [cm];count rate [1/s]");
  graph->SetMarkerStyle(kOpenCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);

  TCanvas* mycanvas = new TCanvas();
  graph->Draw("APE");

  TF1* linear_function = new TF1("Linear function", "[0]+x*[1]", .5, 10.5);
//  TF1* linear_function = new TF1("Linear function", "pol1", .5, 10.5);

  linear_function->SetLineColor(kRed);
  linear_function->SetLineStyle(2);

  graph->Fit(linear_function);
  linear_function->Draw("Same");

  gStyle->SetOptFit();
  mycanvas->Update();
}
