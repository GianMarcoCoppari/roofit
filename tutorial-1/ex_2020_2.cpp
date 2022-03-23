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

	// Create a frame for x random variable a plot
	RooPlot* frame = x.frame(Title("Exponential PDF"));
	expo.plotOn(frame, LineColor(kRed));

	// Generate a binned dataset of 1000 events in x from gauss
	x.setBins(nbins);
	RooDataHist* data = expo.generateBinned(x, entries);

	// Make a second plot frame in x and draw both the
	// data and the pdf in the frame
	auto frame2 = x.frame(Title("Exponential PDF with data"));
	data->plotOn(frame2);
	expo.plotOn(frame2);

	// Fit pdf to data
	expo.fitTo(*data);

	// Print values of lambda (that now reflect fitted values and errors)
	lambda.Print();

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

	// c->Print("ex_2020_1.png");
}
