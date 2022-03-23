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

	// Create a frame for x random variable a plot
	auto frame = x.frame(Title("Crystal Ball PDF"));
	cb.plotOn(frame, LineColor(kRed));

	// Change the value of sigma to 3
	sigma.setVal(0.3);

	// Generate a dataset of 1000 events in x from gauss
	// int const nentries{ 10000 };
	auto data = cb.generate(x, entries);

	// Make a second plot frame in x and draw both the
	// data and the pdf in the frame
	auto frame2 = x.frame(Title("Crystal Ball PDF with data"));
	data->plotOn(frame2);
	cb.plotOn(frame2);

	// Fit pdf to data
	cb.fitTo(*data);

	// Print values of mean and sigma (that now reflect fitted values and errors)
	mean.Print();
	sigma.Print();

	// Draw all frames on a canvas
	TCanvas* c = new TCanvas("ex_2020_1", "ex_2020_1", 800, 400);
	c->Divide(2);

	c->cd(1);
	gPad->SetLeftMargin(0.15);
	frame->GetYaxis()->SetTitleOffset(1.6);
	frame->Draw();

	c->cd(2);
	gPad->SetLeftMargin(0.15);
	frame2->GetYaxis()->SetTitleOffset(1.6);
	frame2->Draw();

	c->Print("ex_2020_1.png");
}