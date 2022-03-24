# TUTORIAL 1

## EXERCISE 1 - FIT OF AN UNBINNED DATASET

### Part 1
Edit the macro `roofit_empty.cpp` and, following the comments inside, create a Crystal Ball PDF with 
* ![formula](https://render.githubusercontent.com/render/math?math=\color{white}\mu=0),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{white}\sigma=1),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{white}\alpah=1.5),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{white}n=1.5).

Change $$\sigma$$ to $$0.3$$ and visualize the PDF.


### Part 2

Generate an unbinned dataset of $$10000$$ events. Make a Fit with Maximum Likelihood and visualize the results.
_Tips_:
* Use information from the slides shown during the lecture or from RooFit Manual at par 2
* Refer to the tutorial `rf101_basics.cxx`
* Find the definition of `RooCBshape` in the `ROOT Class reference`

Submit the macro as `ex_2020_1.cpp` and the image of the canvas in png format.

## EXERCISE 2 - FIT OF A BINNED DATASET

Edit the macro `roofit_empty.cpp` and, following the comments inside, create an Exponential PDF with rate $$\lambda = - 1 / \tau$$ where $$\tau = 3$$ is the _mean lifetime_. Visualize the PDF. 
Generate a binned dataset of $$1000$$ events (bin width equal to $$0.5$$). Make a Fit with Maximum Likelihood. Visualize the results.
Tips:
* Define the mean life as a `RooRealVar` and express the exponential rate using `RooFormulaVar`
* The binning of the returned `RooDataHist` is controlled by the default binning associated with the observables generated. To set the number of bins in `x` to `200`, do e.g. `x.setBins(200)` prior to the call to `generateBinned()`

Submit the macro as `ex_2020_1.cpp` and the image of the canvas in png format.

## Exercise 12.2 – Import a binned dataset, create a model using the factory, fit the model (LHC-b)
One of the main objectives of the LHC--b experiment is the study of the CP violation through the decay of different particles, like, for example, the $$b$$--flavored mesons.
Due to the short half-life, these particles can be observed by reconstructing their decay products and analyzing the so-called *invariant mass spectrum*.
The mass of the mesons is estimated by fitting a Breit-Wigner distribution.
In `B0sInvariantMass.root` an example of invariant mass spectrum for a $$B^{0}_{s}$$ meson is stored.
Create a macro to open the `B0sInvariantMass.root` file and import the corresponding binned dataset. Using `RooFactory` and `RooWorkspace`, create a Breit-Wigner model. Fit the model to the binned dataset. Create a Gaussian function and fit to the data. Finally plot the data, and the BW and Gaussian distribution to the same canvas.
_Tips_:
* define the `RooRealVar` out of the factory, read and import the data from the file and import in the workspace using `RooWorkspace::import()`. 
* Compare the fitted value with the particle mass reported in the Particle Data Group. You can see how to import data here: https://root.cern.ch/doc/master/rf102__dataimport_8C.html

Submit the macro as `ex_2020_1.cpp` and the image of the canvas in png format.age of the canvas in png format)