// Coppari Gian Marco
// University of Bologna - LM in Physics, Nuclear & Subnuclear Physics Student

#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooBreitWigner.h"

#include "TCanvas.h"
#include "TAxis.h"
#include "TFile.h"

using namespace RooFit;


void b0s_invariant(double xmin, double xmax) {
	// Define our observable
	RooRealVar x{ "x", "x", xmin, xmax };

	// Create a histogram and import it inside a RooDataHist object
	auto file = TFile::Open("B0sInvariantMass.root");
	auto h = static_cast<TH1F*>(file->Get("massaB0")); // h is pointer to a TH1F object.

	RooDataHist dh{ "dh", "dh", x, RooFit::Import(*h) }; 
}
