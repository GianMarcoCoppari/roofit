# TUTORIAL 1

## EXERCISE 1 - FIT OF AN UNBINNED DATASET

### Part 1
Edit the macro *roofit_empty.cpp* and, following the comments inside, create a Crystal Ball PDF with 
* $$\mu = 0$$,
* $$\sigma = 1$$,
* $$\alpha = 1.5$$,
* $$n = 1.5$$.

Change $$\sigma$$ to $$0.3$$ and visualize the PDF.


### Part 2

Generate an unbinned dataset of $$10000$$ events. Make a Fit with Maximum Likelihood and visualize the results.
_Tips_:
* Use information from the slides shown during the lecture or from RooFit Manual at par 2
* Refer to the tutorial _rf101_basics.cxx_
* Find the definition of _RooCBshape_ in the _ROOT Class reference_

Submit the macro as _ex_2020_1.cpp_ and the image of the canvas in png format.

## EXERCISE 2 - FIT OF A BINNED DATASET

Edit the macro *roofit_empty.cpp* and, following the comments inside, create an Exponential PDF with rate $$\lambda = - 1 / \tau$$ where $$\tau = 3$$ is the *mean lifetime*. Visualize the PDF. 
Generate a binned dataset of $$1000$$ events (bin width equal to $$0.5$$). Make a Fit with Maximum Likelihood. Visualize the results.
Tips:
* Define the mean life as a *RooRealVar* and express the exponential rate using *RooFormulaVar*
* The binning of the returned *RooDataHist* is controlled by the default binning associated with the observables generated. To set the number of bins in *x* to $$200$$, do e.g. *x.setBins(200)* prior to the call to *generateBinned()*

Submit the macro as *ex_2020_1.cpp* and the image of the canvas in png format.age of the canvas in png format)