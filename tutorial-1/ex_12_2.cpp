// Coppari Gian Marco
// University of Bologna - LM in Physics, Nuclear & Subnuclear Physics Student

#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooBreitWigner.h"

#include "TCanvas.h"
#include "TAxis.h"
#include "TFile.h"

using namespace RooFit;

void make_model(RooWorkspace&);
void use_model(RooWorkspace&);


void b0s_invariant(double xmin, double xmax) {
	

	RooWorkspace WS{ "WS" };
	make_model(WS);
	use_model(WS);

}

void make_model(RooWorkspace& W) {
	// Define observable
	RooRealVar x{ "x", "x", 0, 10};

	// Define parameters: mean for both distributions, sigma for gaussian data, gamma for breit-wigner
	RooRealVar mean{ "mean", "mean", 5.5, 5, 6, "GeV" };
	RooRealVar sigma{ "sigma", "sigma", 0.2, 0, 1, "GeV" };
	RooRealVar width{ "gamma", "gamma", 0, 1, "GeV" };

	// Define models: breit-wigner and gaussian models
	RooGauusian gaus{ "gauss", "gaus", x, mean, sigma };
	RooBreitWigner breit{ "breitwigner", "breitwigner", x, mean, width };

	// Create a histogram and import it inside a RooDataHist object
	auto file = TFile::Open("B0sInvariantMass.root");
	auto h = static_cast<TH1F*>(file->Get("massaB0")); // h is pointer to a TH1F object.

	RooDataHist dh{ "dh", "dh", x, RooFit::Import(*h) };

	W.import(gaus);
	W.import(breit);
	W.import(dh);
}
// void use_model(RooWorkspace&);