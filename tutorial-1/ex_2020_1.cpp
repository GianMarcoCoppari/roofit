// Coppari Gian Marco
// University of Bologna - LM in Physics, Nuclear & Subnuclear Physics Student

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooCBShape.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

using namespace RooFit;


void crystalball(double xmin, double xmax, int entries) {
	// Set the domain
	// double const xmin{ -10 };
	// double const xmax{ 10 };

	// Parameters of the CrystalBall PDF
	RooRealVar mean{ "mean", "mean", 0, xmin, xmax};	// mean value
	RooRealVar sigma{ "sigma", "sigma", 1, xmin, xmax };	// std. dev. of the gaussian part
	RooRealVar alpha{ "alpha", "alpha", 1.5, xmin, xmax };
	RooRealVar n{ "n", "n", 1.5, xmin, xmax };

	// Create CrystalBall PDF, of a random variable x
	RooRealVar x{"x", "x", xmin, xmax};
	RooCBShape cb{"cb", "cb", x, mean, sigma, alpha, n};

	
}