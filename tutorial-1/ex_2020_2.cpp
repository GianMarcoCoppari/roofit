// Coppari Gian Marco
// University of Bologna - LM in Physics, Nuclear & Subnuclear Physics Student

#include "RooRealVar.h"
#include "RooFormulaVar.h"
#include "RooExponential.h"
#include "RooPlot.h"

#include "TCanvas.h"
#include "TAxis.h"

using namespace RooFit;


void exponential(double xmin, double xmax, int entries, int nbins) {
	// Creation of parameters. tau is the mean lifetime, lambda intensity
	RooRealVar tau{ "tau", "tau", 3, xmin, xmax };
	RooFormulaVar lambda{ "lambda", "lambda", "- 1 / tau", tau };

	RooRealVar x{ "x", "x", xmin, xmax };
	RooExponential expo{ "expo", "expo", x, lambda };

	
}
